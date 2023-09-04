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
* File Name        : Config_TRD0_TRD1.c
* Component Version: 1.5.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TRD0_TRD1.
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
#include "Config_TRD0_TRD1.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_TRD1_Create
* Description  : This function initializes the TRD0 and TRD1 modules.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_TRD1_Create(void)
{
    TRDSTR |= (_04_TRD_TRD0_COUNT_CONTINUES | _08_TRD_TRD1_COUNT_CONTINUES);
    TRDSTR &= (uint8_t)~_03_TRD_COUNT_START_INITIAL_VALUE;
    TRDMK0 = 1U;    /* disable TRD0 interrupt */
    TRDIF0 = 0U;    /* clear TRD0 interrupt flag */
    TRDMK1 = 1U;    /* disable TRD1 interrupt */
    TRDIF1 = 0U;    /* clear TRD1 interrupt flag */
    /* Set INTTRD0 low priority */
    TRDPR10 = 1U;
    TRDPR00 = 1U;
    /* Set INTTRD1 low priority */
    TRDPR11 = 1U;
    TRDPR01 = 1U;
    TPS2 &= _70_TRD_KB3_COUNT_SOURCE_CLEAR;
    TPS2 |= _00_TRD_KB3_CK0_SELECT_FKB;
    TRDMR = _01_TRD_SYNCHRONOUSLY;
    TRDBCR = _00_TRD_KB3_STANDALONE_MODE | _00_TRD_KB3_COUNT_SOURCE_TKBTCK0;
    TRDPMR = _00_TRD_KB3_TRDTKBOUT4_OUTPUT_DISABLE | _00_TRD_KB3_TRDTKBOUT5_OUTPUT_DISABLE | 
             _00_TRD_KB3_TRDTKBOUT0_OUTPUT_DISABLE | _00_TRD_KB3_TRDTKBOUT1_OUTPUT_DISABLE | 
             _00_TRD_KB3_TRDTKBOUT2_OUTPUT_DISABLE | _00_TRD_KB3_TRDTKBOUT3_OUTPUT_DISABLE;
    TRDFCR = _00_TRD_TIMER_PWM_MODE | _80_TRD_TRDFCR_DEFAULT_VALUE;
    TRDOER1 = _01_TRD_TRDIOA0_OUTPUT_DISABLE | _02_TRD_TRDIOB0_OUTPUT_DISABLE | _04_TRD_TRDIOC0_OUTPUT_DISABLE |
            _08_TRD_TRDIOD0_OUTPUT_DISABLE | _10_TRD_TRDIOA1_OUTPUT_DISABLE | _20_TRD_TRDIOB1_OUTPUT_DISABLE |
            _40_TRD_TRDIOC1_OUTPUT_DISABLE | _80_TRD_TRDIOD1_OUTPUT_DISABLE;
    TRDOER2 = _00_TRD_INTP0_CUTOFF_DISABLE;
    TRDPOCR0 = _01_TRD_TRDIOB_OUTPUT_ACTIVE_H | _04_TRD_TRDIOD_OUTPUT_ACTIVE_H;
    TRDPOCR1 = _01_TRD_TRDIOB_OUTPUT_ACTIVE_H | _02_TRD_TRDIOC_OUTPUT_ACTIVE_H | _04_TRD_TRDIOD_OUTPUT_ACTIVE_H | 
               _08_TRD_TRDIOA_OUTPUT_ACTIVE_H;
    TRDELC = _00_TRD_ELC0_CUTOFF_DISABLE | _00_TRD_ELC1_CUTOFF_DISABLE;
    TRDIER0 = _01_TRD_IMIA_ENABLE;
    TRDIER1 = _01_TRD_IMIA_ENABLE;
    TRDGRA0 = _F9EF_TRD_KB3_TRDGRA0_VALUE;
    TRDGRB0 = _7CF7_TRD_KB3_TRDGRB0_VALUE;
    TRDGRC0 = _F9EF_TRD_KB3_TRDGRA0_VALUE;
    TRDGRD0 = _7CF7_TRD_KB3_TRDGRB0_VALUE;
    TRDCMPB0 = _7CF7_TRD_KB3_TRDCMPB0_VALUE;
    TRDCMPD0 = _7CF7_TRD_KB3_TRDCMPB0_VALUE;
    TRDGRA1 = _F9EF_TRD_KB3_TRDGRA0_VALUE;
    TRDGRC1 = _F9EF_TRD_KB3_TRDGRA0_VALUE;
    TRDGRB1 = _7CF7_TRD_KB3_TRDGRB1_VALUE;
    TRDGRD1 = _7CF7_TRD_KB3_TRDGRB1_VALUE;
    TRDCMPE1 = _7CF7_TRD_KB3_TRDCMPE1_VALUE;
    TRDCMPF1 = _7CF7_TRD_KB3_TRDCMPE1_VALUE;
    TRDCMPB1 = _7CF7_TRD_KB3_TRDCMPB1_VALUE;
    TRDCMPD1 = _7CF7_TRD_KB3_TRDCMPB1_VALUE;
    TRDCMPA1 = _7CF7_TRD_KB3_TRDCMPA1_VALUE;
    TRDCMPC1 = _7CF7_TRD_KB3_TRDCMPA1_VALUE;

    R_Config_TRD0_TRD1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_TRD1_Start
* Description  : This function starts TRD0 and TRD1 counters.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_TRD1_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF0 = 0U;    /* clear TRD0 interrupt flag */
    TRDIF1 = 0U;    /* clear TRD1 interrupt flag */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDMK0 = 0U;    /* enable TRD0 interrupt */
    TRDMK1 = 0U;    /* enable TRD1 interrupt */
    TRDBCR |= _80_TRD_KB3_GATE_FUNCTION_ENABLE;
    TRDSTR |= _04_TRD_TRD0_COUNT_CONTINUES;
    TRDSTR |= _08_TRD_TRD1_COUNT_CONTINUES;
    TRDSTR |= _03_TRD_COUNT_START_INITIAL_VALUE;    /* start TRD counter */
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_TRD1_Stop
* Description  : This function stops TRD0 and TRD1 counters.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_TRD1_Stop(void)
{
    volatile uint8_t trdsr_dummy;

    TRDSTR |= (_04_TRD_TRD0_COUNT_CONTINUES | _08_TRD_TRD1_COUNT_CONTINUES);
    TRDSTR &= (uint8_t)~_03_TRD_COUNT_START_INITIAL_VALUE;
    TRDBCR &= _11_TRD_KB3_GATE_FUNCTION_DISABLE;
    TRDMK0 = 1U;    /* disable TRD0 interrupt */
    TRDIF0 = 0U;    /* clear TRD0 interrupt flag */
    TRDMK1 = 1U;    /* disable TRD1 interrupt */
    TRDIF1 = 0U;    /* clear TRD1 interrupt flag */
    trdsr_dummy = TRDSR0;    /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U;    /* clear TRD0 each interrupt request */
    trdsr_dummy = TRDSR1;    /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U;    /* clear TRD1 each interrupt request */
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_TRD1_Set_TRD0_ReloadTrigger
* Description  : This function generates TRD0 buffer registers reload trigger.
* Arguments    : buffer -
*                    buffer registers value
* Return Value : status -
*                    MD_OK or MD_ERROR
***********************************************************************************************************************/
MD_STATUS R_Config_TRD0_TRD1_Set_TRD0_ReloadTrigger(st_kb3pwm_ch0_buffer_registers_t * buffer)
{
    MD_STATUS status = MD_OK;

    if (_01_TRD_TRDRSF_RELOAD_WAITING_STATUS == (TRDRSF0 & _01_TRD_TRDRSF_RELOAD_WAITING_STATUS))
    {
        status = MD_ERROR;
    }
    else
    {
        TRDGRA0 = buffer->trdgra0;
        TRDGRB0 = buffer->trdgrb0;
        TRDCMPB0 = buffer->trdcmpb0;
        TRDRDT0 |= _01_TRD_TRDRDT0_RELOAD_REGISTER;
    }

    return status;
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_TRD1_Set_TRD1_ReloadTrigger
* Description  : This function generates TRD1 buffer registers reload trigger.
* Arguments    : buffer -
*                    buffer registers value
* Return Value : status -
*                    MD_OK or MD_ERROR
***********************************************************************************************************************/
MD_STATUS R_Config_TRD0_TRD1_Set_TRD1_ReloadTrigger(st_kb3pwm_ch1_buffer_registers_t * buffer)
{
    MD_STATUS status = MD_OK;

    if (_01_TRD_TRDRSF_RELOAD_WAITING_STATUS == (TRDRSF1 & _01_TRD_TRDRSF_RELOAD_WAITING_STATUS))
    {
        status = MD_ERROR;
    }
    else
    {
        TRDGRA1 = buffer->trdgra1;
        TRDGRB1 = buffer->trdgrb1;
        TRDCMPA1 = buffer->trdcmpa1;
        TRDCMPB1 = buffer->trdcmpb1;
        TRDCMPE1 = buffer->trdcmpe1;
        TRDRDT1 |= _01_TRD_TRDRDT1_RELOAD_REGISTER;
    }

    return status;
}

/* Start user code for adding. Do not edit comment generated here */
void R_Config_TRD0_TRD1_CopyBufferData(void)
{
    while(TRDRSF != 0)
    {
        ;
    }
    TRDRDT = 0x0101;
    while(TRDRSF != 0)
    {
        ;
    }

}

void R_Config_TRD0_TRD1_0B_Create(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF0 = 0U;    /* clear TRD0 interrupt flag */
    TRDIF1 = 0U;    /* clear TRD1 interrupt flag */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDMK0 = 0U;    /* enable TRD0 interrupt */
    TRDMK1 = 0U;    /* enable TRD1 interrupt */
    TRDBCR |= _80_TRD_KB3_GATE_FUNCTION_ENABLE;
    TRDSTR |= _04_TRD_TRD0_COUNT_CONTINUES;
    TRDSTR |= _08_TRD_TRD1_COUNT_CONTINUES;
    TRDSTR |= _03_TRD_COUNT_START_INITIAL_VALUE;    /* start TRD counter */
}

void R_Config_TRD0_TRD1_0B_StartPort(void)
{
    /* Set TRDIOB0 pin */
    POM1 &= 0xDFU;
    PMCA1 &= 0xDFU;
    P1 &= 0xDFU;
    PM1 &= 0xDFU;
}

void R_Config_TRD0_TRD1_0D_StartPort(void)
{
    /* Set TRDIOD0 pin */
    POM1 &= 0xEFU;
    PMCA1 &= 0xEFU;
    P1 &= 0xEFU;
    PM1 &= 0xEFU;
}

void R_Config_TRD0_TRD1_1A_StartPort(void)
{
    /* Set TRDIOA1 pin */
    POM1 &= 0xF7U;
    PMCA1 &= 0xF7U;
    P1 &= 0xF7U;
    PM1 &= 0xF7U;
}

void R_Config_TRD0_TRD1_1B_StartPort(void)
{
    /* Set TRDIOB1 pin */
    POM1 &= 0xFBU;
    PMCA1 &= 0xFBU;
    P1 &= 0xFBU;
    PM1 &= 0xFBU;
}

void R_Config_TRD0_TRD1_1C_StartPort(void)
{
    /* Set TRDIOC1 pin */
    POM1 &= 0xFDU;
    PMCA1 &= 0xFDU;
    CCDE &= 0x7FU;
    P1 &= 0xFDU;
    PM1 &= 0xFDU;
}

void R_Config_TRD0_TRD1_1D_StartPort(void)
{
    /* Set TRDIOD1 pin */
    POM1 &= 0xFEU;
    PMCA1 &= 0xFEU;
    CCDE &= 0xBFU;
    P1 &= 0xFEU;
    PM1 &= 0xFEU;
}

void R_Config_TRD0_TRD1_0B_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF0 = 0U;    /* clear TMRD0 interrupt flag */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    TRDMK0 = 0U;    /* enable TMRD0 interrupt */

    TRDOER1 &= ~_02_TRD_TRDIOB0_OUTPUT_DISABLE;
}

void R_Config_TRD0_TRD1_0D_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF0 = 0U;    /* clear TMRD0 interrupt flag */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    TRDMK0 = 0U;    /* enable TMRD0 interrupt */

    TRDOER1 &= ~_08_TRD_TRDIOD0_OUTPUT_DISABLE;
}

void R_Config_TRD0_TRD1_1A_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF1 = 0U;    /* clear TRD1 interrupt flag */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDMK1 = 0U;    /* enable TRD1 interrupt */

    TRDOER1 &= ~_10_TRD_TRDIOA1_OUTPUT_DISABLE;
}

void R_Config_TRD0_TRD1_1B_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF1 = 0U;    /* clear TRD1 interrupt flag */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDMK1 = 0U;    /* enable TRD1 interrupt */

    TRDOER1 &= ~_20_TRD_TRDIOB1_OUTPUT_DISABLE;
}

void R_Config_TRD0_TRD1_1C_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF1 = 0U;    /* clear TRD1 interrupt flag */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDMK1 = 0U;    /* enable TRD1 interrupt */

    TRDOER1 &= ~_40_TRD_TRDIOC1_OUTPUT_DISABLE;
}

void R_Config_TRD0_TRD1_1D_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF1 = 0U;    /* clear TRD1 interrupt flag */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDMK1 = 0U;    /* enable TRD1 interrupt */

    TRDOER1 &= ~_80_TRD_TRDIOD1_OUTPUT_DISABLE;
}

void R_Config_TRD0_TRD1_0B_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    TRDMK0 = 1U;    /* disable TMRD0 interrupt */
    TRDIF0 = 0U;    /* clear TMRD0 interrupt flag */
    trdsr_dummy = TRDSR0;
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    TRDOER1 |= _02_TRD_TRDIOB0_OUTPUT_DISABLE; /* output disabled */
}

void R_Config_TRD0_TRD1_0D_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    TRDMK0 = 1U;    /* disable TMRD0 interrupt */
    TRDIF0 = 0U;    /* clear TMRD0 interrupt flag */
    trdsr_dummy = TRDSR0;
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    TRDOER1 |= _08_TRD_TRDIOD0_OUTPUT_DISABLE; /* output disabled */
}

void R_Config_TRD0_TRD1_1A_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    TRDMK1 = 1U;    /* disable TMRD1 interrupt */
    TRDIF1 = 0U;    /* clear TMRD1 interrupt flag */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDOER1 |= _10_TRD_TRDIOA1_OUTPUT_DISABLE; /* output disabled */
}

void R_Config_TRD0_TRD1_1B_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    TRDMK1 = 1U;    /* disable TMRD1 interrupt */
    TRDIF1 = 0U;    /* clear TMRD1 interrupt flag */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDOER1 |= _20_TRD_TRDIOB1_OUTPUT_DISABLE; /* output disabled */
}

void R_Config_TRD0_TRD1_1C_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    TRDMK1 = 1U;    /* disable TMRD1 interrupt */
    TRDIF1 = 0U;    /* clear TMRD1 interrupt flag */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDOER1 |= _40_TRD_TRDIOC1_OUTPUT_DISABLE; /* output disabled */
}

void R_Config_TRD0_TRD1_1D_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    TRDMK1 = 1U;    /* disable TMRD1 interrupt */
    TRDIF1 = 0U;    /* clear TMRD1 interrupt flag */
    trdsr_dummy = TRDSR1; /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U; /* clear TRD1 each interrupt request */
    TRDOER1 |= _80_TRD_TRDIOD1_OUTPUT_DISABLE; /* output disabled */
}

/* End user code. Do not edit comment generated here */

