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
* File Name        : Config_INTC.h
* Component Version: 1.4.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_INTC.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef CFG_Config_INTC_H
#define CFG_Config_INTC_H

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_intc.h"

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_INTC_Create (void);
void R_Config_INTC_INTP0_Start (void);
void R_Config_INTC_INTP0_Stop (void);
void R_Config_INTC_INTP1_Start (void);
void R_Config_INTC_INTP1_Stop (void);
void R_Config_INTC_INTP2_Start (void);
void R_Config_INTC_INTP2_Stop (void);
void R_Config_INTC_INTP3_Start (void);
void R_Config_INTC_INTP3_Stop (void);
void R_Config_INTC_INTP4_Start (void);
void R_Config_INTC_INTP4_Stop (void);
void R_Config_INTC_INTP5_Start (void);
void R_Config_INTC_INTP5_Stop (void);
void R_Config_INTC_INTP6_Start (void);
void R_Config_INTC_INTP6_Stop (void);
void R_Config_INTC_INTP7_Start (void);
void R_Config_INTC_INTP7_Stop (void);
void R_Config_INTC_INTP8_Start (void);
void R_Config_INTC_INTP8_Stop (void);
void R_Config_INTC_INTP9_Start (void);
void R_Config_INTC_INTP9_Stop (void);
void R_Config_INTC_INTP10_Start (void);
void R_Config_INTC_INTP10_Stop (void);
void R_Config_INTC_INTP11_Start (void);
void R_Config_INTC_INTP11_Stop (void);
void R_Config_INTC_INTP20_Start (void);
void R_Config_INTC_INTP20_Stop (void);
void R_Config_INTC_INTP21_Start (void);
void R_Config_INTC_INTP21_Stop (void);
void R_Config_INTC_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
void R_Config_INTC_Create_Mode(uint8_t interruptNum, int mode);
void R_Config_INTC_INTP_Start(void);
void R_Config_INTC_INTP_Stop(uint8_t interruptNum);
/* End user code. Do not edit comment generated here */
#endif
