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
* File Name        : Config_TKB2.c
* Component Version: 1.5.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TKB2.
* Creation Date    : 
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_TKB2.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TKB2_Create
* Description  : This function initializes the TKB2 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TKB2_Create(void)
{
    TKBCTL21 &= _1B_KB3_STOP_TIMER_OPTERATION;

    TMKBSTPMK20 = 1U;    /* disable KB32 termination interrupt 0 */
    TMKBSTPIF20 = 0U;    /* clear KB32 termination interrupt 0 flag */
    TMKBSTRMK20 = 1U;    /* disable KB32 activation interrupt 0 */
    TMKBSTRIF20 = 0U;    /* clear KB32 activation interrupt 0 flag */
    TMKBSTPMK21 = 1U;    /* disable KB32 termination interrupt 1 */
    TMKBSTPIF21 = 0U;    /* clear KB32 termination interrupt 1 flag */
    TMKBSTRMK21 = 1U;    /* disable KB32 activation interrupt 1 */
    TMKBSTRIF21 = 0U;    /* clear KB32 activation interrupt 1 flag */
    TMKBMK2 = 1U;    /* disable KB32 count end interrupt */
    TMKBIF2 = 0U;    /* clear KB32 count end flag */
    /* Set INTTMKB2 low priority */
    TMKBPR12 = 1U;
    TMKBPR02 = 1U;
    TPS2 &= _70_KB3_CK0_COUNT_SOURCE_CLEAR;
    TPS2 |= _00_KB3_CK0_SELECT_FKBKC;
    TKBCTL20 = _0000_KB3_TKBO0_PWM_OUTPUT_DITHERING_DISABLE | _0000_KB3_TKBO0_PWM_OUTPUT_SMOOTH_DISABLE | 
               _0000_KB3_TKBO0_PWM_OUTPUT_GATE_DISABLE | _0000_KB3_TKBO1_PWM_OUTPUT_DITHERING_DISABLE | 
               _0000_KB3_TKBO1_PWM_OUTPUT_SMOOTH_DISABLE | _0000_KB3_TKBO1_PWM_OUTPUT_GATE_DISABLE;
    TKBCTL21 = _00_KB3_STANDALONE_MODE | _00_KB3_CLOCK_SELECTED_CK20;
    TKBIOC20 = _00_KB3_TKBO0_OUTPUT_DEFAULT_LOW | _00_KB3_TKBO1_OUTPUT_DEFAULT_LOW | 
               _00_KB3_TKBO0_OUTPUT_ACTIVE_HIGH | _00_KB3_TKBO1_OUTPUT_ACTIVE_HIGH;

    TKBCR20 = _F9EF_KB3_TKBCR20_VALUE;
    TKBCR21 = _7CF8_KB3_TKBCR21_VALUE;
    TKBCR22 = 0;
    TKBCR23 = _7CF8_KB3_TKBCR21_VALUE;

    TKBTGCR2 = _0064_KB3_TKBTGCR2_VALUE;
    TKBTCTL2 = _00_KB3_SKIPPING_INTERRUPT_DISABLE | _00_KB3_SKIPPING_AD_DISABLE | _00_KB3_FIRST_CYCLE_DISABLE | 
               _00_KB3_INTERLOCK_WITH_TIMER_RD_DISABLE;
    TKBPACTL22 = _00_KB3_TKBO0_FORCED_STOP_FUNCTION_DISABLE | _00_KB3_TKBO1_FORCED_STOP_FUNCTION_DISABLE;
    TKBPACTL23 = _00_KB3_TKBO0_FIXED_OFF_FUNCTION_DISABLE | _00_KB3_TKBO0_ACTIVE_FORCED_STOP_NO_INTERRUPT | 
                 _00_KB3_TKBO0_TERMIN_FORCED_STOP_NO_INTERRUPT | _00_KB3_TKBO1_FIXED_OFF_FUNCTION_DISABLE | 
                 _00_KB3_TKBO1_ACTIVE_FORCED_STOP_NO_INTERRUPT | _00_KB3_TKBO1_TERMIN_FORCED_STOP_NO_INTERRUPT;

    R_Config_TKB2_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TKB2_Start
* Description  : This function starts TKB2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TKB2_Start(void)
{
    TKBIOC21 = _01_KB3_TKBO0_TIMER_OUTPUT_ENABLE | _02_KB3_TKBO1_TIMER_OUTPUT_ENABLE;
    TMKBIF2 = 0U;    /* clear INTTMKB2 interrupt flag */
    TMKBMK2 = 0U;    /* enable INTTMKB2 interrupt */
    TKBCTL21 |= _80_KB3_TIMER_OPTERATION_ENABLE;    /* start KB32 operation */
}

/***********************************************************************************************************************
* Function Name: R_Config_TKB2_Stop
* Description  : This function stops TKB2 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TKB2_Stop(void)
{
    TKBCTL21 &= _1B_KB3_STOP_TIMER_OPTERATION;    /* stop KB32 operation */
    TMKBMK2 = 1U;    /* disable KB32 count end interrupt */
    TMKBIF2 = 0U;    /* clear KB32 count end flag */
}

/***********************************************************************************************************************
* Function Name: R_Config_TKB2_Set_BatchOverwriteRequestOn
* Description  : This function sets TKB2 batch overwrite request function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TKB2_Set_BatchOverwriteRequestOn(void)
{
    TKBRDT2 = 1U;
}

/* Start user code for adding. Do not edit comment generated here */
void R_Config_TKB2_0_Create(void)
{
    TMKBIF2 = 0U;    /* clear INTTMKB2 interrupt flag */
    TMKBMK2 = 0U;    /* enable INTTMKB2 interrupt */
    TKBCTL21 |= _80_KB3_TIMER_OPTERATION_ENABLE;    /* start KB32 operation */
}

void R_Config_TKB2_0_Start(void)
{
    TKBIOC21 |= _01_KB3_TKBO0_TIMER_OUTPUT_ENABLE;
    TMKBIF2 = 0U;    /* clear INTTMKB2 interrupt flag */
}

void R_Config_TKB2_0_StartPort(void)
{
    /* Set TKBO20 pin */
    PMCA1 &= 0xBFU;
    CCDE &= 0xFEU;
    P1 &= 0xBFU;
    PM1 &= 0xBFU;
}

void R_Config_TKB2_0_Stop(void)
{
    TKBIOC21 &= ~_01_KB3_TKBO0_TIMER_OUTPUT_ENABLE;
}

void R_Config_TKB2_1_Start(void)
{
    TKBIOC21 |= _02_KB3_TKBO1_TIMER_OUTPUT_ENABLE;
    TMKBIF2 = 0U;    /* clear INTTMKB2 interrupt flag */
}

void R_Config_TKB2_1_StartPort(void)
{
    /* Set TKBO21 pin (P17) */
    PMCA1 &= 0x7FU;
    CCDE &= 0xFDU;
    P1 &= 0x7FU;
    PM1 &= 0x7FU;
}

void R_Config_TKB2_1_Stop(void)
{
    TKBIOC21 &= ~_02_KB3_TKBO1_TIMER_OUTPUT_ENABLE;
}

/* End user code. Do not edit comment generated here */

