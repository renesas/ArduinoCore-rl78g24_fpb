#include "pins_variant.h"
#include "iodefine.h"
#include "iodefine_ext.h"
#include "api/Common.h"
#include "wiring_private.h"
#include "wiring_private_tone.h"
#include "r_smc_entry.h"

extern "C"
{
#if defined(G23_FPB)
#include "Config_Through.h"
#endif // G23_FPB

uint8_t g_tone_create_trd_flg=0;
extern bool g_u8AnalogWriteAvailableTable[NUM_DIGITAL_PINS];
extern uint32_t R_BSP_GetFclkFreqHz(void);
}

int8_t get_tone_channel(uint8_t tone_num)
{
    int8_t tone_cnt;

    for(tone_cnt=0;tone_cnt<TONE_CH_NUM;tone_cnt++)
    {
        if (tone_num == tone_channel_table[tone_cnt])
        {
            return tone_cnt;
        }
    }
    return -1;
}

void noTone(uint8_t pin)
{
    int8_t tone_channel = get_tone_channel(pin);
    if (-1 == tone_channel)
    {
        ;
    }
    else
    {
        tone_ch[tone_channel].stop();
    }
}

// frequency (in hertz) and duration (in milliseconds).
void tone(uint8_t pin, unsigned int frequency, unsigned long duration)
{
    uint8_t i;
    uint8_t tone_pin_flg = 0;
    int8_t tone_channel = get_tone_channel(pin);
    uint32_t fclk_frequency = 0;
    uint32_t timer_frequency = 0;
    uint16_t timer_clock_mode = 0;
    uint16_t operating_clock_select = 0;
    volatile uint32_t temp_int32;

    /* If it is not a tone output pin, do nothing and exit */
    for(i = 0; i < TONE_CH_NUM; i ++)
    {
        if(pin == tone_channel_table[i])
        {
            tone_pin_flg = 1;
            i = TONE_CH_NUM;
        }
        else
        {
            tone_pin_flg = 0;
        }
    }

    if(tone_pin_flg == 1)
    {

        /* Initializes the tone channel */
#if defined(G23_FPB)
        if(pin == 11)
        {
            R_Config_Through_Create();
            R_Config_Through_Start();
        }
#endif // G23_FPB
        if(tone_ch[tone_channel].timer_type == TIMER_TYPE_TAU)
        {
            tone_ch[tone_channel].open();
            fclk_frequency = R_BSP_GetFclkFreqHz();

            /* Get timer frequency */
            timer_clock_mode = *g_timer_tone_mode_reg[tone_channel] & TAU_OPERATION_CLOCK;

            if (timer_clock_mode == _4000_TAU_CLOCK_SELECT_CKM2)
            {
                operating_clock_select = *g_timer_tone_clock_select_reg & CK02_OPERATION;
                if(operating_clock_select == _0000_TAU_CKM2_FCLK_1)
                {
                    timer_frequency = fclk_frequency/2;
                }
                else
                {
                    operating_clock_select = operating_clock_select >> 8;
                    timer_frequency = fclk_frequency / (1 << (operating_clock_select * 2)) ;     /*  fclk/2^2 ~ 2^6 */
                }
            }
            else if  (timer_clock_mode == _C000_TAU_CLOCK_SELECT_CKM3)
            {
                operating_clock_select = *g_timer_tone_clock_select_reg & CK03_OPERATION;

                operating_clock_select = operating_clock_select >> 12;
                timer_frequency = fclk_frequency / (1 << (operating_clock_select * 2 + 8));    /* fclk/2^8 ~ 2^14 */
            }
            else /* CK00, CK01 Clock Select */
            {
                operating_clock_select = *g_timer_tone_clock_select_reg & CK00_CK01_OPERATION;
                timer_frequency = fclk_frequency / (1 << operating_clock_select) ;    /* ckm00, ckm01 - fclk/2^0 ~ 2^15 */
            }

            /* 500 Hz <= frequency <= 65535Hz */
            frequency = max(frequency, (unsigned int)FREQUENCY_TONE_MIN_VAL);
            frequency = min(frequency, (unsigned int)65535);

            *g_tone_period_reg[tone_channel] = (uint16_t)((timer_frequency / 2 / frequency) - 1);
        }

        else if(tone_ch[tone_channel].timer_type == TIMER_TYPE_TKB)
        {
            tone_ch[tone_channel].open();
            fclk_frequency = R_BSP_GetFclkFreqHz();

            /* Get timer frequency */
            timer_clock_mode = *g_timer_tone_mode_reg[tone_channel] & 0b1111;

            if (timer_clock_mode == 0b000) /* fCLK */
            {
                timer_frequency = fclk_frequency;
            }
            else if (timer_clock_mode == 0b001) /* fCLK/2 */
            {
                timer_frequency = fclk_frequency/2;
            }
            else /* fCLK/4 */
            {
                timer_frequency = fclk_frequency/4;
            }

            /* 500 Hz <= frequency <= 65535Hz */
            frequency = max(frequency, (unsigned int)FREQUENCY_TONE_MIN_VAL);
            frequency = min(frequency, (unsigned int)65535);

            *g_tone_period_reg[tone_channel] = (uint16_t)((timer_frequency / frequency) - 1);
            *g_tone_duty_reg[tone_channel] = *g_tone_period_reg[tone_channel] / 2;
            tone_ch[tone_channel].duty_update_req();
        }

        else if(tone_ch[tone_channel].timer_type == TIMER_TYPE_TRD)
        {
            if(g_tone_create_trd_flg == 0)
            {
                tone_ch[tone_channel].open();
                g_tone_create_trd_flg = 1;
            }

            fclk_frequency = R_BSP_GetFclkFreqHz();

            /* Get timer frequency */
            timer_clock_mode = *g_timer_tone_mode_reg[tone_channel] & 0b0111;

            if (timer_clock_mode == 0b0000)
            {
                timer_frequency = fclk_frequency;
            }
            else if  (timer_clock_mode == 0b0001)
            {
                timer_frequency = fclk_frequency / 2;
            }
            else
            {
                timer_frequency = fclk_frequency;
            }

            /* 500 Hz <= frequency <= 65535Hz */
            frequency = max(frequency, (unsigned int)FREQUENCY_TONE_MIN_VAL);
            frequency = min(frequency, (unsigned int)65535);
            temp_int32 = (timer_frequency / frequency) - 1;
            *g_tone_period_reg[tone_channel] = (uint16_t)temp_int32;
            *g_tone_duty_reg[tone_channel] = *g_tone_period_reg[tone_channel] / 2;
            tone_ch[tone_channel].duty_update_req();
        }
        tone_ch[tone_channel].start();

//        if(g_u8AnalogWriteAvailableTable[pin] == 0)
//        {
//            g_u8AnalogWriteAvailableTable[pin] = 1;
            tone_ch[tone_channel].start_port();
//        }
        if(duration != 0)
        {
            delay(duration);
            noTone(pin);
        }
    }
}

// XXX: this function only works properly for timer 2 (the only one we use
// currently).  for the others, it should end the tone, but won't restore
// proper PWM functionality for the timer.
/*
void disableTimer(uint8_t _timer)
{
;
}
*/


