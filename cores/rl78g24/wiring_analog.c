#include "wiring_private.h"
#include "wiring_variant.h"
#include "pins_variant.h"
#include "pintable.h"
#include "r_smc_entry.h"
#if defined(G23_FPB)
#include "Config_Through.h"
#endif // G23_FPB

extern const PinTableType * pinTablelist[NUM_DIGITAL_PINS];
extern uint8_t g_adc_int_flg;
static uint8_t g_u8AnalogReference = DEFAULT;
boolean g_bAdcInterruptFlag = false;
uint16_t g_u16ADUL;
uint16_t g_u16ADLL;
extern uint32_t R_BSP_GetFclkFreqHz(void);
uint8_t g_pwm_create_flg=0;
uint8_t g_pwm_create_trd_flg=0;
uint8_t g_pwm_create_tkb_flg = 0;

uint8_t g_analogWrite_enable_interrupt_flag=0;

/* Match to the value of PWM_PIN */
extern volatile unsigned short *g_timer_period_reg[PWM_CH_NUM];
extern volatile unsigned short *g_timer_duty_reg[PWM_CH_NUM];
#if defined(G22_FPB) || defined(G23_FPB)
extern volatile unsigned short *g_timer_analog_mode_reg[PWM_CH_NUM];
extern volatile unsigned short *g_timer_analog_clock_select_reg;
#elif defined(G24_FPB)
extern volatile unsigned char *g_timer_analog_mode_reg[PWM_CH_NUM];

#endif
extern const uint8_t  pwm_channel_table[PWM_CH_NUM];
extern Pwm_func pwm_ch[PWM_CH_NUM];
extern const uint8_t g_au8AnalogPinTable[NUM_ANALOG_INPUTS];
extern const uint8_t g_analog_pin_input[NUM_ANALOG_INPUTS];

static void _analogPinRead(uint8_t pin);
static int _analogRead(uint8_t u8ADS);
#if defined(G22_FPB) || defined(G23_FPB)
static uint16_t _analogDuty(int val, uint16_t frequency);
static uint16_t _analogFrequency (uint8_t pin, uint32_t u32Hz);
#elif defined(G24_FPB)
static uint16_t _analogDutyTRD(int val, uint16_t frequency);
static uint16_t _analogDutyTKB(int val, uint32_t frequency);
static uint16_t _analogFrequencyTRD (uint8_t pin, uint32_t u32Hz);
static uint16_t _analogFrequencyTKB (uint8_t pin, uint32_t u32Hz);

#endif // G24_FPB

volatile uint16_t global_val1;

bool g_u8AnalogReadAvailableTable[NUM_ANALOG_INPUTS] = { 0 };
bool g_u8AnalogWriteAvailableTable[NUM_DIGITAL_PINS] = { 0 };

int8_t get_pwm_channel(uint8_t pwm_num)
{
    int8_t pwm_cnt;
    for(pwm_cnt=0;pwm_cnt<PWM_CH_NUM;pwm_cnt++)
    {
        if (pwm_num == pwm_channel_table[pwm_cnt])
        {
            return pwm_cnt;
        }
    }
    return -1;
}

/***********************************************************************************************************************
* Function Name: analogReference
* Description  : The reference voltage used for analog input.
* Arguments    : mode -
*                    DEFAULT: use VDD as VREF(+)
*                    INTERNAL: use internal voltage as VREF(+)
*                    EXTERNAL: use AVREFP as VREF(+)
* Return Value : None
***********************************************************************************************************************/
void analogReference(uint8_t mode) 
{
    // can't actually set the register here because the default setting
    // will connect AVCC and the AREF pin, which would cause a short if
    // there's something connected to AREF.
    R_Config_ADC_Create();

    R_Config_ADC_Set_Reference(mode);

    if ((DEFAULT == mode) || (INTERNAL == mode))
    {
        g_u8AnalogReference = mode;
    }
    else
    {
        g_u8AnalogReference = DEFAULT;
    }
}

int8_t get_analog_channel(uint8_t analog_num)
{
    int8_t analog_cnt;

    for(analog_cnt=0;analog_cnt<NUM_ANALOG_INPUTS;analog_cnt++)
    {
        if (analog_num == g_analog_pin_input[analog_cnt])
        {
            return analog_cnt;
        }
    }
    return -1;
}

/***********************************************************************************************************************
* Function Name: analogRead
* Description  : Reads the value from the specified analog pin.
* Arguments    : analog_pin - the name of the analog input pin to read from A0 to A7
* Return Value : The analog reading on the pin.
*                Although it is limited to the resolution of the analog to digital converter
*                (0-255 for 8 bits or 0-1023 for 10 bits).
***********************************************************************************************************************/
int analogRead(uint8_t analog_pin) {
    int s16Result = 0;
    uint8_t analog_read_flg = 0;
    uint8_t cnt;

    //アナログ入力端子の設定
    _analogPinRead(analog_pin);
    //アナログ入力端子ではない場合、何もしない終了する
    for(cnt = 0; cnt < NUM_ANALOG_INPUTS; cnt ++)
    {
        if(analog_pin == g_analog_pin_input[cnt])
        {
            analog_read_flg = 1;
            cnt = NUM_ANALOG_INPUTS;
        }
        else
        {
        analog_read_flg = 0;
        }
    }

    if(analog_read_flg == 1)
    {
        // アナログ値の読み込み
        s16Result = _analogRead(g_au8AnalogPinTable[get_analog_channel(analog_pin)]);
    }
    return s16Result;
}


// Right now, PWM output only works on the pins with
// hardware support.  These are defined in the appropriate
// pins_*.c file.  For the rest of the pins, we default
// to digital output.
/***********************************************************************************************************************
* Function Name: analogWrite
* Description  : Writes an analog value (PWM wave) to a pin.
* Arguments    : pin - the name of output pin (5,6,10,32)
*                value - Output PWM duty 0 ~ 255
* Return Value : None
***********************************************************************************************************************/
#if defined(G22_FPB) || defined(G23_FPB)
void analogWrite(uint8_t pin, int value) {
    uint16_t pwm_frequency = 0;

    if (pin < NUM_DIGITAL_PINS)
    {
        {
            value = max(value, PWM_MIN);
            value = min(value, PWM_MAX);
            uint8_t cnt;
            uint8_t analog_write_flg = 0;
            int8_t pwm_channel = get_pwm_channel(pin);

            /* If it is not a PWM output terminal, do nothing and exit */
            for(cnt = 0; cnt < PWM_CH_NUM; cnt ++)
            {
                if(pin == pwm_channel_table[cnt])
                {
                    analog_write_flg = 1;
                    cnt = PWM_CH_NUM;
                }
                else
                {
                    analog_write_flg = 0;
                }
            }
            if(analog_write_flg == 1)
            {
                if(g_pwm_create_flg == 0)
                {
                    /* Master & Slave Initialize */
                    pwm_ch[pwm_channel].open();
                    /* Master Channel Frequency Set */
                    if(pwm_ch[pwm_channel].cycle == CYCLE_VALUE)
                    {
                        pwm_frequency = _analogFrequency(pwm_channel_table[0],FREQUENCY_PWM_MIN_VAL);
                        for(int i = 0;i<PWM_CH_NUM;i++)
                        {
                            pwm_ch[i].cycle = pwm_frequency;
                        }
                    }
                    *(g_timer_period_reg[pwm_channel]) = pwm_ch[pwm_channel].cycle;
                }
                /* Slave Channel Duty set */
                *(g_timer_duty_reg[pwm_channel])   = _analogDuty(value, pwm_ch[pwm_channel].cycle);
                if(g_u8AnalogWriteAvailableTable[pin] == 0)
                {
                    pwm_ch[pwm_channel].open_slave();
                    pwm_ch[pwm_channel].start_slave();
                    g_analogWrite_enable_interrupt_flag = 1;
                    g_u8AnalogWriteAvailableTable[pin] = 1;
                    pwm_ch[pwm_channel].enable_interrupt();
                }
                if(g_pwm_create_flg == 0)
                {
                    pwm_ch[pwm_channel].start();
                    g_pwm_create_flg = 1;
                }
            }
        }
    }
}


#elif defined(G24_FPB)

void analogWriteTRDsub(uint8_t pin,int8_t pwm_channel, int value)
{
    if(g_pwm_create_trd_flg == 0)
    {
        pwm_ch[pwm_channel].open();
        g_pwm_create_trd_flg = 1;
    }

    /* Frequency Set */
    if(pwm_ch[pwm_channel].cycle == CYCLE_VALUE)
    {
        pwm_ch[pwm_channel].cycle = _analogFrequencyTRD(pin,FREQUENCY_PWM_MIN_VAL);
        *(g_timer_period_reg[pwm_channel]) = pwm_ch[pwm_channel].cycle;
        if(1 < pwm_channel)
        {
            /* TRDGRA0 <= TADGRA1 */
            *(g_timer_period_reg[0]) = *(g_timer_period_reg[pwm_channel]);
        }
        else
        {
            /* TRDGRA1 <= TADGRA0 */
            *(g_timer_period_reg[3]) = *(g_timer_period_reg[pwm_channel]);
        }
    }
    else
    {
        *(g_timer_period_reg[pwm_channel]) = pwm_ch[pwm_channel].cycle;
    }
        if(*(g_timer_period_reg[pwm_channel]) != pwm_ch[pwm_channel].cycle)
        {
            *(g_timer_period_reg[pwm_channel]) = pwm_ch[pwm_channel].cycle;
            if(pwm_ch[pwm_channel].timer_type == TIMER_TYPE_TRD)
            {
                if(1 < pwm_channel)
                {
                    /* TRDGRA0 ⇐　TADGRA1 */
                    *(g_timer_period_reg[0]) = *(g_timer_period_reg[pwm_channel]);
                }
                else
                {
                    /* TRDGRA1 ⇐　TADGRA0 */
                    *(g_timer_period_reg[3]) = *(g_timer_period_reg[pwm_channel]);
                }
            }
        }
    /* Duty set */
    *(g_timer_duty_reg[pwm_channel]) = _analogDutyTRD(value, pwm_ch[pwm_channel].cycle);
    pwm_ch[pwm_channel].duty_update_req();
    pwm_ch[pwm_channel].start();
    if(g_u8AnalogWriteAvailableTable[pin] == 0)
    {
        g_u8AnalogWriteAvailableTable[pin] = 1;
        pwm_ch[pwm_channel].start_port();
    }

}

void analogWriteTKBsub(uint8_t pin,int8_t pwm_channel, int value)
{
    if(g_pwm_create_tkb_flg == 0)
    {
        pwm_ch[pwm_channel].open();
        g_pwm_create_tkb_flg = 1;
    }

    /* Frequency Set */
    if(pwm_ch[pwm_channel].cycle == CYCLE_VALUE)
    {
        pwm_ch[pwm_channel].cycle = _analogFrequencyTKB(pin,FREQUENCY_PWM_MIN_VAL);
    }
    else
    {
        *(g_timer_period_reg[pwm_channel]) = pwm_ch[pwm_channel].cycle;
    }
    /* Duty set */
    *(g_timer_duty_reg[pwm_channel]) = _analogDutyTKB(value, *(g_timer_period_reg[pwm_channel]));
    pwm_ch[pwm_channel].duty_update_req();
    pwm_ch[pwm_channel].start();

    if(g_u8AnalogWriteAvailableTable[pin] == 0)
    {
        g_u8AnalogWriteAvailableTable[pin] = 1;
        pwm_ch[pwm_channel].start_port();
    }
}

void analogWrite(uint8_t pin, int value) {
    if (pin < NUM_DIGITAL_PINS)
    {
        value = max(value, PWM_MIN);
        value = min(value, PWM_MAX);
        uint8_t cnt;
        uint8_t analog_write_flg = 0;
        /* If it is not a PWM output terminal, do nothing and exit */
        for(cnt = 0; cnt < PWM_CH_NUM; cnt ++)
        {
            if(pin == pwm_channel_table[cnt])
            {
                analog_write_flg = 1;
                cnt = PWM_CH_NUM;
            }
            else
            {
                analog_write_flg = 0;
            }
        }
        if(analog_write_flg == 1)
        {
            int8_t pwm_channel = get_pwm_channel(pin);

            if(pwm_ch[pwm_channel].timer_type == TIMER_TYPE_TRD)
            {
                analogWriteTRDsub(pin,pwm_channel,value);
            }
            else if(pwm_ch[pwm_channel].timer_type == TIMER_TYPE_TKB)
            {
                analogWriteTKBsub(pin,pwm_channel,value);
            }
        }
    }
}


#endif // G24_FPB
/***********************************************************************************************************************
* Function Name: analogWriteFrequency
* Description  : Sets the cycle. The default is 490Hz.
* Arguments    : Hz: cycle
* Return Value : None
***********************************************************************************************************************/
#if defined(G22_FPB) || defined(G23_FPB)
void analogWriteFrequency(uint32_t Hz) {
    if(g_pwm_create_flg == 0)
    {
        for(int i = 0;i<PWM_CH_NUM;i++)
        {
            pwm_ch[i].cycle = _analogFrequency(pwm_channel_table[i],Hz);
        }
    }
}

#elif defined(G24_FPB)

void analogWriteFrequency(uint32_t Hz) {
    uint8_t check_pin_status =0;
    for(int i=0;i<NUM_DIGITAL_PINS;i++)
    {
        if(g_u8AnalogWriteAvailableTable[i] != false)
        {
            check_pin_status =1;
        }
    }
    if(check_pin_status == 0)
    {
        for(int i = 0;i<PWM_CH_NUM;i++)
        {
            if(pwm_ch[i].timer_type == TIMER_TYPE_TRD)
            {
                pwm_ch[i].cycle = _analogFrequencyTRD(pwm_channel_table[i],Hz);
            }
            else if(pwm_ch[i].timer_type == TIMER_TYPE_TKB)
            {
                pwm_ch[i].cycle = _analogFrequencyTKB(pwm_channel_table[i],Hz);
            }
        }
    }
}

#endif // G24_FPB
/***********************************************************************************************************************
* Function Name: analogWritePinFrequency
* Description  : Sets the cycle. The default is 490Hz.
* Arguments    : pin - the name of analog value (PWM wave) output pin (5,6,10,32)
*                Hz - cycle
* Return Value : None
***********************************************************************************************************************/
void analogWritePinFrequency(uint8_t pin, uint32_t Hz) {
    /* PWM output pulse cycle setting
    Pulse period = (TDR00 setting value + 1) x count clock period
    Example) When the pulse period is 2 [ms]
    2 [ms] = 1/32 [MHz] x (TDR00 setting + 1)
    TDR00 setting value = 63999 */
    int8_t pwm_channel = get_pwm_channel(pin);
    if(-1 != pwm_channel)
    {
#if defined(G22_FPB) || defined(G23_FPB)
        pwm_ch[pwm_channel].cycle = _analogFrequency(pin,Hz);
#elif defined(G24_FPB)
        if(pwm_ch[pwm_channel].timer_type == TIMER_TYPE_TRD)
        {
            pwm_ch[pwm_channel].cycle = _analogFrequencyTRD(pin,Hz);
        }
        else if(pwm_ch[pwm_channel].timer_type == TIMER_TYPE_TKB)
        {
            pwm_ch[pwm_channel].cycle = _analogFrequencyTKB(pin,Hz);
        }
#endif
    }
}

#if defined(G22_FPB) || defined(G23_FPB)
static uint16_t _analogFrequency (uint8_t pin, uint32_t u32Hz)
{
    uint16_t Result;
    uint32_t fclk_frequency = 0;
    uint32_t timer_frequency = 0;
    uint16_t timer_clock_mode = 0;
    uint16_t operating_clock_select = 0;
    int8_t pwm_channel = get_pwm_channel(pin);

    fclk_frequency = R_BSP_GetFclkFreqHz();
    /* Get timer frequency */
    timer_clock_mode = *g_timer_analog_mode_reg[pwm_channel] & TAU_OPERATION_CLOCK;
    if (timer_clock_mode == _4000_TAU_CLOCK_SELECT_CKM2) /* CK02 Clock Selected */
    {
        operating_clock_select = *g_timer_analog_clock_select_reg & CK02_OPERATION;
        if(operating_clock_select == _0000_TAU_CKM2_FCLK_1)
        {
            timer_frequency = fclk_frequency/2;    /*  fclk/2 */
        }
        else
        {
            operating_clock_select = operating_clock_select >> 8;
            timer_frequency = fclk_frequency / (1 << (operating_clock_select * 2)) ;     /*  fclk/2^2 ~ 2^6 */
        }
    }
    else if  (timer_clock_mode == _C000_TAU_CLOCK_SELECT_CKM3) /* CK03 Clock Selected */
    {
        operating_clock_select = *g_timer_analog_clock_select_reg & CK03_OPERATION;

        operating_clock_select = operating_clock_select >> 12;
        timer_frequency = fclk_frequency / (1 << (operating_clock_select * 2 + 8));    /* fclk/2^8 ~ 2^14 */
    }
    else /* CK00, CK01 Clock Selected */
    {
        operating_clock_select = *g_timer_analog_clock_select_reg & CK00_CK01_OPERATION;
        timer_frequency = fclk_frequency / (1 << operating_clock_select) ;    /* ckm00, ckm01 - fclk/2^0 ~ 2^15 */
    }

    /* 490 Hz <= frequency <= 8MHz */
    u32Hz = max(u32Hz, (uint32_t)FREQUENCY_PWM_MIN_VAL);
    u32Hz = min(u32Hz, (uint32_t)FREQUENCY_PWM_MAX_VAL);

    /* Pulse period = {Set value of TDRmn (master) + 1} × Count clock period
       Set value of TDRmn (master) = (Pulse period / Count clock period) - 1 */
    Result = (uint16_t)((timer_frequency / u32Hz) - 1);
    return Result;
}


#elif defined(G24_FPB)

static uint16_t _analogFrequencyTRD(uint8_t pin, uint32_t u32Hz)
{
    uint16_t Result;
    uint32_t fclk_frequency = 0;
    uint32_t timer_frequency = 0;
    uint8_t timer_clock_mode = 0;
    int8_t pwm_channel = get_pwm_channel(pin);

    fclk_frequency = R_BSP_GetFclkFreqHz();
    /* Get timer frequency */
    timer_clock_mode = *g_timer_analog_mode_reg[pwm_channel] & 0b0111;
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

    /* 490 Hz <= frequency <= 8MHz */
    u32Hz = max(u32Hz, (uint32_t)FREQUENCY_PWM_MIN_VAL);
    u32Hz = min(u32Hz, (uint32_t)FREQUENCY_PWM_MAX_VAL);

    /* Pulse period = {Set value of TRDGRA0 (master) + 1} × Count clock period
       Set value of TDRmn (master) = (Pulse period / Count clock period) - 1 */
    Result = (uint16_t)((timer_frequency / u32Hz) - 1);

    /* 490 Hz <= frequency <= 8MHz */
    u32Hz = max(u32Hz, (uint32_t)FREQUENCY_PWM_MIN_VAL);
    u32Hz = min(u32Hz, (uint32_t)FREQUENCY_PWM_MAX_VAL);

    /* Pulse period = {Set value of TRDGRA0 (master) + 1} × Count clock period
       Set value of TDRmn (master) = (Pulse period / Count clock period) - 1 */
    Result = (uint16_t)((timer_frequency / u32Hz) - 1);
    return Result;
}

static uint16_t _analogFrequencyTKB(uint8_t pin, uint32_t u32Hz)
{
    uint16_t Result;
    uint32_t fclk_frequency = 0;
    uint32_t timer_frequency = 0;
    uint8_t timer_clock_mode = 0;
    int8_t pwm_channel = get_pwm_channel(pin);

    fclk_frequency = R_BSP_GetFclkFreqHz();
    /* Get timer frequency */

    timer_clock_mode = *(g_timer_analog_mode_reg[pwm_channel]) & 0b1111;

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

    /* 490 Hz <= frequency <= 8MHz */
    u32Hz = max(u32Hz, (uint32_t)FREQUENCY_PWM_MIN_VAL);
    u32Hz = min(u32Hz, (uint32_t)FREQUENCY_PWM_MAX_VAL);

    /* Pulse period = {Set value of TRDGRA0 (master) + 1} × Count clock period
       Set value of TDRmn (master) = (Pulse period / Count clock period) - 1 */
    Result = (uint16_t)((timer_frequency / u32Hz) - 1);

    return Result;
}


#endif // (G24_FPB)

#if defined(G22_FPB) || defined(G23_FPB)
static int _analogDuty(int val, uint16_t frequency)
{
/*    Duty factor [0 ~ 255] = {Set value of TDRmp (slave)}/{Set value of TDRmn (master) + 1} × 255
    {Set value of TDRmp (slave)} = Duty factor * {Set value of TDRmn (master) + 1} / 255 */
    int u16Duty = 0;
    /* Duty set */
    if(val> PWM_MAX)
    {
        val = PWM_MAX;
    }
    else
    {
        u16Duty = (int) (((unsigned long) val
                * (frequency + 1)) / PWM_MAX);
    }
    return u16Duty;
}
#elif defined(G24_FPB)
static uint16_t _analogDutyTRD(int val, uint16_t frequency)
{
    uint16_t u16Duty = 0;

    if(val == 0)
    {
        u16Duty = 0xFFFE;
    }
    else if(val == 255)
    {
        u16Duty = frequency;
    }
    else{
        u16Duty = frequency - (uint16_t) ((unsigned long)(((unsigned long)(frequency +1)) * (unsigned long)val)  / (unsigned long)(PWM_MAX+1));
    }
    return u16Duty;
}

// frequency : set value of TKBCR
static uint16_t _analogDutyTKB(int val, uint32_t frequency)
{
    uint16_t u16Duty = 0;

    if(val == 0)
    {
        u16Duty = 0;
    }
    else if(val == 255)
    {
        u16Duty = (uint16_t)frequency + 1;
    }
    else{
        u16Duty = (uint16_t) ((unsigned long)((unsigned long)val * (unsigned long)(frequency+1))  / (unsigned long)(PWM_MAX+1));
    }

    return u16Duty;
}

#endif

static void _analogPinRead (uint8_t pin)
{
    int8_t pin_index;
    pin_index = pin - ANALOG_PIN_START_NUMBER;
    if ((pin_index < 0) || (pin_index >= NUM_ANALOG_INPUTS))
    {
        return;
    }

    if (g_u8AnalogReadAvailableTable[pin_index] == false)
    {
        const PinTableType ** pp;
        PinTableType * p;
        pp = &pinTablelist[pin];
        p = (PinTableType *)*pp;
        if (0!=p->pmca)
        {
            pinMode(pin, INPUT);
            /* アナログピンの場合PMCAをセットする */
            *p->portModeControlARegisterAddr |= (unsigned long)(p->pmca);
            g_u8AnalogReadAvailableTable[pin_index] = true;
        }
    }
}

static int _analogRead(uint8_t u8ADS) {
    int s16Result = 0;

    uint8_t adc_end_flg = 0;
    // 1. AD reference setting
    R_Config_ADC_Set_Reference (g_u8AnalogReference);
// 3. Snooze mode return upper / lower limit setting
    R_Config_ADC_Set_ComparisonLimit((uint8_t)(g_u16ADUL >> 2), (uint8_t)(g_u16ADLL >> 2));
// 4. AD channel setting
    R_Config_ADC_ADS0_Set_ADChannel(u8ADS);
    while(0 == adc_end_flg)
    {
        g_adc_int_flg=0;
        // 2. Trigger mode setting
        if (PM_SNOOZE_MODE == g_u8PowerManagementMode)
        {
            R_Config_ITL000_Stop();
            // Hardware trigger wait mode(RTC), one-shot conversion
//            R_Config_ADC_Set_ModeTrigger(PM_SNOOZE_MODE);
            // 6. Snooze mode ON (interrupt enabled)
            R_Config_ADC_Set_SnoozeOn();    //AWC =1
            // 5. AD comparator ON
            R_Config_ADC_Snooze_Start();    //enable interrupt & ADCS=1
        }
        else
        {
            R_Config_ADC_Set_OperationOn();  //ADCE=1 & wait
            // Software trigger mode, one-shot conversion
//            R_Config_ADC_Set_ModeTrigger(PM_NORMAL_MODE);
            R_Config_ADC_Set_SoftwareTriggerOn();
            // 5. AD comparator ON

            R_Config_ADC_Start();            //ADCS=1 & enable interrupt
        }
        // 7. After STOP mode until AD interrupt occurs (loop processing)
        while (0 == g_adc_int_flg)
        {
            if (PM_SNOOZE_MODE == g_u8PowerManagementMode)
            {
                enterPowerManagementMode (0xFFFFFFFF);
            }
            else
            {
                NOP();
            }
        }
        // 8. Snooze mode Off (interrupt stop)
        if (PM_SNOOZE_MODE == g_u8PowerManagementMode)
        {
            R_Config_ADC_Set_SnoozeOff();
            R_Config_ADC_Snooze_Stop();
            R_Config_ITL000_Start();
        }
        else
        {
            R_Config_ADC_Stop();
        }
        // 9. Get AD conversion result
        if (DEFAULT == g_u8AnalogReference)
        {
            R_Config_ADC_ADS0_Get_Result_10bit((uint16_t*) &s16Result);
        }
        else if (INTERNAL == g_u8AnalogReference)
        {
            R_Config_ADC_ADS0_Get_Result_8bit ((uint8_t*) &s16Result);
        }
        if (PM_SNOOZE_MODE == g_u8PowerManagementMode)
        {
            if((g_u16ADLL <= (uint16_t)s16Result) && ((uint16_t)s16Result <= g_u16ADUL))
            {
                adc_end_flg = 1;
            }
        }
        else
        {
            adc_end_flg = 1;
        }
    }
    // 10.AD Comparator Off
    R_Config_ADC_Set_OperationOff();
    return s16Result;
}
