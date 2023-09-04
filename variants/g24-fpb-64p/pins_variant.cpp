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
#include "wiring_private_tone.h"
#include "r_smc_entry.h"

/*
 * Pins descriptions
 */

const uint8_t SS   = PIN_SPI_SS;
const uint8_t MOSI = PIN_SPI_MOSI;
const uint8_t MISO = PIN_SPI_MISO;
const uint8_t SCK  = PIN_SPI_SCK;

const uint8_t SDA0 = PIN_WIRE_SDA0;
const uint8_t SCL0 = PIN_WIRE_SCL0;
const uint8_t SDA1 = PIN_WIRE_SDA1;
const uint8_t SCL1 = PIN_WIRE_SCL1;

const uint8_t A0 = PIN_A0;
const uint8_t A1 = PIN_A1;
const uint8_t A2 = PIN_A2;
const uint8_t A3 = PIN_A3;
const uint8_t A4 = PIN_A4;
const uint8_t A5 = PIN_A5;

/* tone pin set */
// register itself
// volatile unsigned short *g_tone_period_reg[TONE_CH_NUM] = {&TRDGRA0,&TRDGRA0,&TRDGRA1,&TRDGRA1,&TRDGRA1,&TRDGRA1,&TKBCR20,&TKBCR20};
// volatile unsigned short *g_tone_duty_reg[TONE_CH_NUM]   = {&TRDGRB0,&TRDCMPB0,&TRDCMPA1,&TRDGRB1,&TRDCMPE1,&TRDCMPB1,&TKBCR21,&TKBCR23};

// buffer
volatile unsigned short *g_tone_period_reg[TONE_CH_NUM] = {&TRDGRC0,&TRDGRC0,&TRDGRC1,&TRDGRC1,&TRDGRC1,&TRDGRC1,&TKBCR20,&TKBCR20};
volatile unsigned short *g_tone_duty_reg[TONE_CH_NUM]   = {&TRDGRD0,&TRDCMPD0,&TRDCMPC1,&TRDGRD1,&TRDCMPF1,&TRDCMPD1,&TKBCR21,&TKBCR23};


volatile unsigned char *g_timer_tone_mode_reg[TONE_CH_NUM] = {&TRDCR0,&TRDCR0,&TRDCR1,&TRDCR1,&TRDCR1,&TRDCR1,&TPS2,&TPS2};
volatile unsigned short *g_timer_tone_clock_select_reg = &TPS0;
const uint8_t  tone_channel_table[TONE_CH_NUM]  = {PWM_PIN_6,PWM_PIN_9,PWM_PIN_10,PWM_PIN_11,PWM_PIN_12,PWM_PIN_13,PWM_PIN_5,PWM_PIN_3};

tone_func tone_ch[TONE_CH_NUM] =
{
    {
        .open  = R_Config_TRD0_TRD1_0B_Create,
        .start = R_Config_TRD0_TRD1_0B_Start,
        .start_port = R_Config_TRD0_TRD1_0B_StartPort,
        .duty_update_req = R_Config_TRD0_TRD1_CopyBufferData,
        .stop = R_Config_TRD0_TRD1_0B_Stop,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = R_Config_TRD0_TRD1_0B_Create,
        .start = R_Config_TRD0_TRD1_0D_Start,
        .start_port = R_Config_TRD0_TRD1_0D_StartPort,
        .duty_update_req = R_Config_TRD0_TRD1_CopyBufferData,
        .stop = R_Config_TRD0_TRD1_0D_Stop,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = R_Config_TRD0_TRD1_0B_Create,
        .start = R_Config_TRD0_TRD1_1A_Start,
        .start_port = R_Config_TRD0_TRD1_1A_StartPort,
        .duty_update_req = R_Config_TRD0_TRD1_CopyBufferData,
        .stop = R_Config_TRD0_TRD1_1A_Stop,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = R_Config_TRD0_TRD1_0B_Create,
        .start = R_Config_TRD0_TRD1_1B_Start,
        .start_port = R_Config_TRD0_TRD1_1B_StartPort,
        .duty_update_req = R_Config_TRD0_TRD1_CopyBufferData,
        .stop = R_Config_TRD0_TRD1_1B_Stop,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = R_Config_TRD0_TRD1_0B_Create,
        .start = R_Config_TRD0_TRD1_1C_Start,
        .start_port = R_Config_TRD0_TRD1_1C_StartPort,
        .duty_update_req = R_Config_TRD0_TRD1_CopyBufferData,
        .stop = R_Config_TRD0_TRD1_1C_Stop,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = R_Config_TRD0_TRD1_0B_Create,
        .start = R_Config_TRD0_TRD1_1D_Start,
        .start_port = R_Config_TRD0_TRD1_1D_StartPort,
        .duty_update_req = R_Config_TRD0_TRD1_CopyBufferData,
        .stop = R_Config_TRD0_TRD1_1D_Stop,
        .timer_type = TIMER_TYPE_TRD
    },
    {
        .open  = R_Config_TKB2_0_Create,
        .start = R_Config_TKB2_0_Start,
        .start_port = R_Config_TKB2_0_StartPort,
        .duty_update_req = R_Config_TKB2_Set_BatchOverwriteRequestOn,
        .stop  = R_Config_TKB2_0_Stop,
        .timer_type = TIMER_TYPE_TKB
    },
    {
        .open  = R_Config_TKB2_0_Create,
        .start = R_Config_TKB2_1_Start,
        .start_port = R_Config_TKB2_1_StartPort,
        .duty_update_req = R_Config_TKB2_Set_BatchOverwriteRequestOn,
        .stop = R_Config_TKB2_1_Stop,
        .timer_type = TIMER_TYPE_TKB
    }
};
