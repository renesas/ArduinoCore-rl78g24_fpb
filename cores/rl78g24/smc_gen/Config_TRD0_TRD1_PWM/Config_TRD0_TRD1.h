/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_TRD0_TRD1.h
* Component Version: 1.5.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TRD0_TRD1.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef CFG_Config_TRD0_TRD1_H
#define CFG_Config_TRD0_TRD1_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_trd.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _F9EF_TRD_KB3_TRDGRA0_VALUE                  (0xF9EFU)
#define _7CF7_TRD_KB3_TRDGRB0_VALUE                  (0x7CF7U)
#define _7CF7_TRD_KB3_TRDCMPB0_VALUE                 (0x7CF7U)
#define _7CF7_TRD_KB3_TRDGRB1_VALUE                  (0x7CF7U)
#define _7CF7_TRD_KB3_TRDCMPE1_VALUE                 (0x7CF7U)
#define _7CF7_TRD_KB3_TRDCMPB1_VALUE                 (0x7CF7U)
#define _7CF7_TRD_KB3_TRDCMPA1_VALUE                 (0x7CF7U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef struct {
    uint16_t trdgra0;
    uint16_t trdgrb0;
    uint16_t trdcmpb0;
} st_kb3pwm_ch0_buffer_registers_t;

typedef struct {
    uint16_t trdgra1;
    uint16_t trdgrb1;
    uint16_t trdcmpa1;
    uint16_t trdcmpb1;
    uint16_t trdcmpe1;
} st_kb3pwm_ch1_buffer_registers_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_TRD0_TRD1_Create (void);
void R_Config_TRD0_TRD1_Start (void);
void R_Config_TRD0_TRD1_Stop (void);
MD_STATUS R_Config_TRD0_TRD1_Set_TRD0_ReloadTrigger (st_kb3pwm_ch0_buffer_registers_t * buffer);
MD_STATUS R_Config_TRD0_TRD1_Set_TRD1_ReloadTrigger (st_kb3pwm_ch1_buffer_registers_t * buffer);
void R_Config_TRD0_TRD1_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
void R_Config_TRD0_TRD1_0B_Create(void);
/*
void R_Config_TRD0_TRD1_0D_Create(void);
void R_Config_TRD0_TRD1_1A_Create(void);
void R_Config_TRD0_TRD1_1B_Create(void);
void R_Config_TRD0_TRD1_1C_Create(void);
void R_Config_TRD0_TRD1_1D_Create(void);
*/
void R_Config_TRD0_TRD1_0B_Start(void);
void R_Config_TRD0_TRD1_0D_Start(void);
void R_Config_TRD0_TRD1_1A_Start(void);
void R_Config_TRD0_TRD1_1B_Start(void);
void R_Config_TRD0_TRD1_1C_Start(void);
void R_Config_TRD0_TRD1_1D_Start(void);

void R_Config_TRD0_TRD1_0B_StartPort(void);
void R_Config_TRD0_TRD1_0D_StartPort(void);
void R_Config_TRD0_TRD1_1A_StartPort(void);
void R_Config_TRD0_TRD1_1B_StartPort(void);
void R_Config_TRD0_TRD1_1C_StartPort(void);
void R_Config_TRD0_TRD1_1D_StartPort(void);

void R_Config_TRD0_TRD1_0B_Stop(void);
void R_Config_TRD0_TRD1_0D_Stop(void);
void R_Config_TRD0_TRD1_1A_Stop(void);
void R_Config_TRD0_TRD1_1B_Stop(void);
void R_Config_TRD0_TRD1_1C_Stop(void);
void R_Config_TRD0_TRD1_1D_Stop(void);

void R_Config_TRD0_TRD1_CopyBufferData(void);

/* End user code. Do not edit comment generated here */
#endif
