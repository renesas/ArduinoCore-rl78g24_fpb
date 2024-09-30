#ifndef WiringPrivateTone_h
#define WiringPrivateTone_h

#include "Arduino.h"
#include "utilities.h"

#ifdef __cplusplus
extern "C"{
#endif

#define FREQUENCY_TONE_MIN_VAL	(750)
#define FREQUENCY_TONE_MAX_VAL	(12000000)

#define TONE_CH_NUM				(8)

typedef struct {
    void (*open)();
	void (*start)();
    void (*start_port)();
    void (*duty_update_req)();
	void (*stop)();
	uint8_t timer_type;
} tone_func;

#ifdef __cplusplus
} // extern "C"
#endif

/* tone pin set */
extern volatile unsigned short *g_tone_period_reg[TONE_CH_NUM];
extern volatile unsigned short *g_tone_duty_reg[TONE_CH_NUM];
extern volatile unsigned char *g_timer_tone_mode_reg[TONE_CH_NUM];
extern volatile unsigned short *g_timer_tone_clock_select_reg;
extern const uint8_t  tone_channel_table[TONE_CH_NUM];

extern "C"{
#include "Config_TKB2.h"
#include "Config_TRD0_TRD1.h"
}

extern tone_func tone_ch[TONE_CH_NUM];

#endif
