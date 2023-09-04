/*
  wiring_variant.h - Internal header file.
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 239 2007-01-12 17:58:39Z mellis $
*/
/*
  Modified 13 July 2014 by Nozomu Fujita for GR-SAKURA
  Modified 1  Mar  2017 by Yuuki Okamiya for RL78/G13
*/

#ifndef WiringVariante_h
#define WiringVariante_h

#include <stdio.h>
#include <stdarg.h>
#include "Arduino.h"
#include "utilities.h"

#ifdef __cplusplus
extern "C"{
#endif

#define ANALOG_ADPC_OFFSET	4
#define ANALOG_PIN_START_NUMBER	(52)
#define MAX_CYCLIC_HANDLER 		(8)
#define EXTERNAL_NUM_INTERRUPTS (13)

/* PWM defines. */
#define PWM_MIN			0
#define PWM_MAX			255

/* External interrupt define. */

#define EXTERNAL_INTERRUPT_0	6
#define EXTERNAL_INTERRUPT_1	20
#define EXTERNAL_INTERRUPT_2	5
#define EXTERNAL_INTERRUPT_3    21
#define EXTERNAL_INTERRUPT_4    9
#define EXTERNAL_INTERRUPT_5    8
#define EXTERNAL_INTERRUPT_6    0
#define EXTERNAL_INTERRUPT_7    11
#define EXTERNAL_INTERRUPT_8    10
#define EXTERNAL_INTERRUPT_9    1
#define EXTERNAL_INTERRUPT_10	2
#define EXTERNAL_INTERRUPT_11	3
#define EXTERNAL_INTERRUPT_12	4

// 6 (TRD) +  1 (TKB30) +  1 (TKB31)
#define	PWM_CH_NUM	(8)

#define TIMER_TYPE_TAU 0
#define TIMER_TYPE_TKB 1
#define TIMER_TYPE_TRD 2

#define FREQUENCY_PWM_MIN_VAL	(750)
#define FREQUENCY_PWM_MAX_VAL	(12000000)

#ifdef __cplusplus
} // extern "C"
#endif

extern volatile unsigned char *g_timer_pulse_mode_reg[PULSE_IN_CH_NUM];
extern volatile unsigned short *g_timer_pulse_clock_select_reg;
extern volatile unsigned short *g_timer_timeout_data_reg;
extern volatile unsigned short *g_timer_timeout_mode_reg;
extern const uint8_t  pulse_in_channel_table[PULSE_IN_CH_NUM];
extern pulse_in_func pulse_in_ch[PULSE_IN_CH_NUM];


#endif /* WiringVariante_h */

