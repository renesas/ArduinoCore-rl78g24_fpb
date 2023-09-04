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
* File Name        : Config_TKB2.h
* Component Version: 1.5.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TKB2.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef CFG_Config_TKB2_H
#define CFG_Config_TKB2_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_tkb.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _12BF_KB3_TKBCR20_VALUE                  (0x12BFU)
#define _0960_KB3_TKBCR21_VALUE                  (0x0960U)
#define _01E0_KB3_TKBCR22_VALUE                  (0x01E0U)
#define _0B40_KB3_TKBCR23_VALUE                  (0x0B40U)

#define _0C7F_KB3_TKBCR20_VALUE                  (0x0C7FU)
#define _F9FF_KB3_TKBCR20_VALUE                  (0xF9FFU)
#define _0640_KB3_TKBCR21_VALUE                  (0x0640U)
#define _0140_KB3_TKBCR22_VALUE                  (0x0140U)
#define _0780_KB3_TKBCR23_VALUE                  (0x0780U)

#define _F9EF_KB3_TKBCR20_VALUE                  (0xF9EFU)
#define _7CF8_KB3_TKBCR21_VALUE                  (0x7CF8U)
#define _18FE_KB3_TKBCR22_VALUE                  (0x18FEU)
#define _95F6_KB3_TKBCR23_VALUE                  (0x95F6U)

#define _0064_KB3_TKBTGCR2_VALUE                 (0x0064U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_TKB2_Create (void);
void R_Config_TKB2_Start (void);
void R_Config_TKB2_Stop (void);
void R_Config_TKB2_Set_BatchOverwriteRequestOn (void);
void R_Config_TKB2_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
void R_Config_TKB2_0_Create(void);
void R_Config_TKB2_0_Start(void);
void R_Config_TKB2_0_StartPort(void);
void R_Config_TKB2_0_Stop(void);

void R_Config_TKB2_1_Start(void);
void R_Config_TKB2_1_StartPort(void);
void R_Config_TKB2_1_Stop(void);
/* End user code. Do not edit comment generated here */
#endif
