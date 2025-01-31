#ifndef WiringVariante_h
#define WiringVariante_h

#include <stdio.h>
#include <stdarg.h>
#include "Arduino.h"
#include "utilities.h"

#ifdef __cplusplus
extern "C"{
#endif

#define ANALOG_PIN_START_NUMBER	(52)
// 20241010
#define MAX_CYCLIC_HANDLER 		(8)
#define EXTERNAL_NUM_INTERRUPTS (14)

/* PWM defines. */
#define PWM_MIN			0
#define PWM_MAX			255

/* External interrupt define. */

#define EXTERNAL_INTERRUPT_0	2
#define EXTERNAL_INTERRUPT_1	4
#define EXTERNAL_INTERRUPT_2	5
#define EXTERNAL_INTERRUPT_3    7
#define EXTERNAL_INTERRUPT_4    14
#define EXTERNAL_INTERRUPT_5    15
#define EXTERNAL_INTERRUPT_6    20
#define EXTERNAL_INTERRUPT_7    24
#define EXTERNAL_INTERRUPT_8    25
#define EXTERNAL_INTERRUPT_9    36
#define EXTERNAL_INTERRUPT_10	37
#define EXTERNAL_INTERRUPT_11	38
#define EXTERNAL_INTERRUPT_12	39
#define EXTERNAL_INTERRUPT_13	48

// 6 (TRD) +  1 (TKB30) +  1 (TKB31)
#define	PWM_CH_NUM	(8)

#define TIMER_TYPE_TAU 0
#define TIMER_TYPE_TKB 1
#define TIMER_TYPE_TRD 2

#define FREQUENCY_PWM_MIN_VAL	(750)
#define FREQUENCY_PWM_MAX_VAL	(12000000)

/* pulseIn define. */
#define PULSEIN_CLOCK_CYCLE 33

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* WiringVariante_h */

