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
* File Name        : r_cg_trd_common.c
* Version          : 1.0.20
* Device(s)        : R7F101GLGxFB
* Description      : None
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
#include "r_cg_trd_common.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_TRD_Create
* Description  : This function enables TRD input clock supply and initializes TRD module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TRD_Create(void)
{
    TRD0EN = 1U;    /* start TRD clock */
    /* Set TRD settings */
    R_Config_TRD0_TRD1_Create();

}

/***********************************************************************************************************************
* Function Name: R_TRD_Set_PowerOn
* Description  : This function starts the clock supply for TRD.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TRD_Set_PowerOn(void)
{
    TRD0EN = 1U;    /* start TRD clock */
}

/***********************************************************************************************************************
* Function Name: R_TRD_Set_PowerOff
* Description  : This function stops the clock supply for TRD.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TRD_Set_PowerOff(void)
{
    TRD0EN = 0U;    /* stop TRD clock */
}

/***********************************************************************************************************************
* Function Name: R_TRD_Set_Reset
* Description  : This function sets TRD module in reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TRD_Set_Reset(void)
{
    TRD0RES = 1U;    /* reset TRD */
}

/***********************************************************************************************************************
* Function Name: R_TRD_Release_Reset
* Description  : This function releases TRD module from reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TRD_Release_Reset(void)
{
    TRD0RES = 0U;    /* release TRD */
}

/***********************************************************************************************************************
* Function Name: R_TRD_ForcedOutput_Enable
* Description  : This function enables TRD force output.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TRD_ForcedOutput_Enable(void)
{
    TRDSHUTS = 0U;    /* suspend the forced cutoff of the pulse output */
    TRDPTO = 1U;    /* pulse output forced cutoff signal input INTP0 enabled */
}

/***********************************************************************************************************************
* Function Name: R_TRD_ForcedOutput_Disable
* Description  : This function disables TRD force output.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TRD_ForcedOutput_Disable(void)
{
    TRDSHUTS = 0U;    /* suspend the forced cutoff of the pulse output */
    TRDPTO = 0U;    /* pulse output forced cutoff signal input INTP0 disabled */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
