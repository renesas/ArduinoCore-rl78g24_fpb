/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "pins_variant.h"
#include "wiring_private.h"
#include "wiring_variant.h"
#include "r_smc_entry.h"

/* Match to the value of PWM_PIN */
// register itself
// volatile unsigned short *g_timer_period_reg[PWM_CH_NUM] = {&TRDGRA0,&TRDGRA0,&TRDGRA1,&TRDGRA1,&TRDGRA1,&TRDGRA1,&TKBCR20,&TKBCR20};
// volatile unsigned short *g_timer_duty_reg[PWM_CH_NUM]   = {&TRDGRB0,&TRDCMPB0,&TRDCMPA1,&TRDGRB1,&TRDCMPE1,&TRDCMPB1,&TKBCR21,&TKBCR23};
// register buffer
volatile unsigned short *g_timer_period_reg[PWM_CH_NUM] = {&TRDGRC0,&TRDGRC0,&TRDGRC1,&TRDGRC1,&TRDGRC1,&TRDGRC1,&TKBCR20,&TKBCR20};
volatile unsigned short *g_timer_duty_reg[PWM_CH_NUM]   = {&TRDGRD0,&TRDCMPD0,&TRDCMPC1,&TRDGRD1,&TRDCMPF1,&TRDCMPD1,&TKBCR21,&TKBCR23};

// changed from unsigned short to unsigned char
volatile unsigned char *g_timer_analog_mode_reg[PWM_CH_NUM] = {&TRDCR0,&TRDCR0,&TRDCR1,&TRDCR1,&TRDCR1,&TRDCR1,&TPS2,&TPS2};
volatile unsigned short *g_timer_analog_clock_select_reg = &TPS0;
const uint8_t  pwm_channel_table[PWM_CH_NUM]  = {PWM_PIN_6,PWM_PIN_9,PWM_PIN_10,PWM_PIN_11,PWM_PIN_12,PWM_PIN_13,PWM_PIN_5,PWM_PIN_3};
const uint8_t g_au8AnalogPinTable[NUM_ANALOG_INPUTS] = {
        ANALOG_PIN_0, ANALOG_PIN_1, ANALOG_PIN_2, ANALOG_PIN_3,ANALOG_PIN_4, ANALOG_PIN_5
    };

const uint8_t g_analog_pin_input[NUM_ANALOG_INPUTS] = {PIN_A0, PIN_A1, PIN_A2, PIN_A3, PIN_A4, PIN_A5
};

Pwm_func pwm_ch[PWM_CH_NUM] =
{
    {
        .open  = (void*)R_Config_TRD0_TRD1_0B_Create,
        .start = (void*)R_Config_TRD0_TRD1_0B_Start,
        .start_port = (void*)R_Config_TRD0_TRD1_0B_StartPort,
        .duty_update_req = (void*)R_Config_TRD0_TRD1_CopyBufferData,
        .stop_slave = (void*)R_Config_TRD0_TRD1_0B_Stop,
        .cycle = CYCLE_VALUE,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = (void*)R_Config_TRD0_TRD1_0B_Create,
        .start = (void*)R_Config_TRD0_TRD1_0D_Start,
        .start_port = (void*)R_Config_TRD0_TRD1_0D_StartPort,
        .duty_update_req = (void*)R_Config_TRD0_TRD1_CopyBufferData,
        .stop_slave = (void*)R_Config_TRD0_TRD1_0D_Stop,
        .cycle = CYCLE_VALUE,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = (void*)R_Config_TRD0_TRD1_0B_Create,
        .start = (void*)R_Config_TRD0_TRD1_1A_Start,
        .start_port = (void*)R_Config_TRD0_TRD1_1A_StartPort,
        .duty_update_req = (void*)R_Config_TRD0_TRD1_CopyBufferData,
        .stop_slave = (void*)R_Config_TRD0_TRD1_1A_Stop,
        .cycle = CYCLE_VALUE,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = (void*)R_Config_TRD0_TRD1_0B_Create,
        .start = (void*)R_Config_TRD0_TRD1_1B_Start,
        .start_port = (void*)R_Config_TRD0_TRD1_1B_StartPort,
        .duty_update_req = (void*)R_Config_TRD0_TRD1_CopyBufferData,
        .stop_slave = (void*)R_Config_TRD0_TRD1_1B_Stop,
        .cycle = CYCLE_VALUE,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = (void*)R_Config_TRD0_TRD1_0B_Create,
        .start = (void*)R_Config_TRD0_TRD1_1C_Start,
        .start_port = (void*)R_Config_TRD0_TRD1_1C_StartPort,
        .duty_update_req = (void*)R_Config_TRD0_TRD1_CopyBufferData,
        .stop_slave = (void*)R_Config_TRD0_TRD1_1C_Stop,
        .cycle = CYCLE_VALUE,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = (void*)R_Config_TRD0_TRD1_0B_Create,
        .start = (void*)R_Config_TRD0_TRD1_1D_Start,
        .start_port = (void*)R_Config_TRD0_TRD1_1D_StartPort,
        .duty_update_req = (void*)R_Config_TRD0_TRD1_CopyBufferData,
        .stop_slave = (void*)R_Config_TRD0_TRD1_1D_Stop,
        .cycle = CYCLE_VALUE,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = (void*)R_Config_TKB2_0_Create,
        .start = (void*)R_Config_TKB2_0_Start,
        .start_port = (void*)R_Config_TKB2_0_StartPort,
        .duty_update_req = (void*)R_Config_TKB2_Set_BatchOverwriteRequestOn,
        .stop_slave = (void*)R_Config_TKB2_0_Stop,
        .cycle = CYCLE_VALUE,
        .timer_type = TIMER_TYPE_TKB
    },
    {
        .open  = (void*)R_Config_TKB2_0_Create,
        .start = (void*)R_Config_TKB2_1_Start,
        .start_port = (void*)R_Config_TKB2_1_StartPort,
        .duty_update_req = (void*)R_Config_TKB2_Set_BatchOverwriteRequestOn,
        .stop_slave = (void*)R_Config_TKB2_1_Stop,
        .cycle = CYCLE_VALUE,
        .timer_type = TIMER_TYPE_TKB
    }
};


