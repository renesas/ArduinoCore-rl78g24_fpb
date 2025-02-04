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
* File Name        : Config_ADC.h
* Component Version: 1.4.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_ADC.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef CFG_Config_ADC_H
#define CFG_Config_ADC_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_ad.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Upper bound (ADUL) value */
#define _FF_AD_ADUL_VALUE               (0xFFU)
/* Lower bound (ADLL) value */
#define _00_AD_ADLL_VALUE               (0x00U)
#define AD_WAITTIME_B                   (4U)    /* wait for 1us + 2fAD as default,
                                                   please change the waiting time value according to the system */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef enum
{
    ADCHANNEL0, ADCHANNEL1, ADCHANNEL2, ADCHANNEL3, ADCHANNEL4, ADCHANNEL5,
    ADCHANNEL6, ADCHANNEL7, ADCHANNEL16 = 16U, ADCHANNEL17, ADCHANNEL18,
    ADCHANNEL19, ADCHANNEL20, ADCHANNEL21, ADCHANNEL22, ADCHANNEL23,
    ADCHANNEL24, ADCHANNEL25, ADCHANNEL26, ADCHANNEL27, ADCHANNEL28,
    ADCHANNEL29, ADCHANNEL30, ADPGA, ADTEMPERSENSOR0, ADINTERREFVOLT
} e_ad_channel_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_ADC_Create (void);
void R_Config_ADC_Start (void);
void R_Config_ADC_Stop (void);
void R_Config_ADC_Set_OperationOn (void);
void R_Config_ADC_Set_OperationOff (void);
void R_Config_ADC_Set_SoftwareTriggerOn (void);
void R_Config_ADC_ADS0_Get_Result_10bit (uint16_t * const buffer);
MD_STATUS R_Config_ADC_ADS0_Set_ADChannel (e_ad_channel_t channel);
void R_Config_ADC_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
#define AD_WAITTIME_DISCHARGE           (2U)
#define AD_WAITTIME_A                   (13U)
void R_Config_ADC_ADS0_Get_Result_8bit(uint8_t * const buffer);
MD_STATUS R_Config_ADC_Set_Reference(uint8_t mode);

void R_Config_ADC_Set_ComparisonLimit(uint8_t upper, uint8_t lower);

void R_Config_ADC_Set_TemperatureSensor(void);
void R_Config_ADC_Set_InternalReferenceVoltage(void);
/* End user code. Do not edit comment generated here */
#endif

