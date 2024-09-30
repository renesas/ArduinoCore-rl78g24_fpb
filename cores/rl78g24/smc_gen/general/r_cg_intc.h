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
* File Name        : r_cg_intc.h
* Version          : 1.0.20
* Device(s)        : R7F101GLGxFB
* Description      : General header file for INTC peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef INTC_H
#define INTC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    External Interrupt Rising Edge Enable Register 0 (EGP0)
*/
/* INTPn pin valid edge selection (EGPn) */
#define _80_INTP7_EDGE_RISING_SEL          (0x80U)    /* rising edge selected for INTP7 pin */
#define _00_INTP7_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP7 pin */
#define _40_INTP6_EDGE_RISING_SEL          (0x40U)    /* rising edge selected for INTP6 pin */
#define _00_INTP6_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP6 pin */
#define _20_INTP5_EDGE_RISING_SEL          (0x20U)    /* rising edge selected for INTP5 pin */
#define _00_INTP5_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP5 pin */
#define _10_INTP4_EDGE_RISING_SEL          (0x10U)    /* rising edge selected for INTP4 pin */
#define _00_INTP4_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP4 pin */
#define _08_INTP3_EDGE_RISING_SEL          (0x08U)    /* rising edge selected for INTP3 pin */
#define _00_INTP3_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP3 pin */
#define _04_INTP2_EDGE_RISING_SEL          (0x04U)    /* rising edge selected for INTP2 pin */
#define _00_INTP2_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP2 pin */
#define _02_INTP1_EDGE_RISING_SEL          (0x02U)    /* rising edge selected for INTP1 pin */
#define _00_INTP1_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP1 pin*/
#define _01_INTP0_EDGE_RISING_SEL          (0x01U)    /* rising edge selected for INTP0 pin */
#define _00_INTP0_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP0 pin */

/*
    External Interrupt Falling Edge Enable Register 0 (EGN0)
*/
/* INTPn pin valid edge selection (EGNn) */
#define _80_INTP7_EDGE_FALLING_SEL         (0x80U)    /* falling edge selected for INTP7 pin */
#define _00_INTP7_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP7 pin */
#define _40_INTP6_EDGE_FALLING_SEL         (0x40U)    /* falling edge selected for INTP6 pin */
#define _00_INTP6_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP6 pin */
#define _20_INTP5_EDGE_FALLING_SEL         (0x20U)    /* falling edge selected for INTP5 pin */
#define _00_INTP5_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP5 pin */
#define _10_INTP4_EDGE_FALLING_SEL         (0x10U)    /* falling edge selected for INTP4 pin */
#define _00_INTP4_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP4 pin */
#define _08_INTP3_EDGE_FALLING_SEL         (0x08U)    /* falling edge selected for INTP3 pin */
#define _00_INTP3_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP3 pin */
#define _04_INTP2_EDGE_FALLING_SEL         (0x04U)    /* falling edge selected for INTP2 pin */
#define _00_INTP2_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP2 pin */
#define _02_INTP1_EDGE_FALLING_SEL         (0x02U)    /* falling edge selected for INTP1 pin */
#define _00_INTP1_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP1 pin */
#define _01_INTP0_EDGE_FALLING_SEL         (0x01U)    /* falling edge selected for INTP0 pin */
#define _00_INTP0_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP0 pin */

/*
    External Interrupt Rising Edge Enable Register 1 (EGP1)
*/
/* INTPn pin valid edge selection (EGPn) */
#define _80_INTP21_EDGE_RISING_SEL         (0x80U)    /* rising edge selected for INTP21 pin */
#define _00_INTP21_EDGE_RISING_UNSEL       (0x00U)    /* rising edge not selected for INTP21 pin */
#define _40_INTP20_EDGE_RISING_SEL         (0x40U)    /* rising edge selected for INTP20 pin */
#define _00_INTP20_EDGE_RISING_UNSEL       (0x00U)    /* rising edge not selected for INTP20 pin */
#define _08_INTP11_EDGE_RISING_SEL         (0x08U)    /* rising edge selected for INTP11 pin */
#define _00_INTP11_EDGE_RISING_UNSEL       (0x00U)    /* rising edge not selected for INTP11 pin */
#define _04_INTP10_EDGE_RISING_SEL         (0x04U)    /* rising edge selected for INTP10 pin */
#define _00_INTP10_EDGE_RISING_UNSEL       (0x00U)    /* rising edge not selected for INTP10 pin */
#define _02_INTP9_EDGE_RISING_SEL          (0x02U)    /* rising edge selected for INTP9 pin */
#define _00_INTP9_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP9 pin */
#define _01_INTP8_EDGE_RISING_SEL          (0x01U)    /* rising edge selected for INTP8 pin */
#define _00_INTP8_EDGE_RISING_UNSEL        (0x00U)    /* rising edge not selected for INTP8 pin */

/*
    External Interrupt Falling Edge Enable Register 1 (EGN1)
*/
/* INTPn pin valid edge selection (EGNn) */
#define _80_INTP21_EDGE_FALLING_SEL        (0x80U)    /* falling edge selected for INTP21 pin */
#define _00_INTP21_EDGE_FALLING_UNSEL      (0x00U)    /* falling edge not selected for INTP21 pin */
#define _40_INTP20_EDGE_FALLING_SEL        (0x40U)    /* falling edge selected for INTP20 pin */
#define _00_INTP20_EDGE_FALLING_UNSEL      (0x00U)    /* falling edge not selected for INTP20 pin */
#define _08_INTP11_EDGE_FALLING_SEL        (0x08U)    /* falling edge selected for INTP11 pin */
#define _00_INTP11_EDGE_FALLING_UNSEL      (0x00U)    /* falling edge not selected for INTP11 pin */
#define _04_INTP10_EDGE_FALLING_SEL        (0x04U)    /* falling edge selected for INTP10 pin */
#define _00_INTP10_EDGE_FALLING_UNSEL      (0x00U)    /* falling edge not selected for INTP10 pin */
#define _02_INTP9_EDGE_FALLING_SEL         (0x02U)    /* falling edge selected for INTP9 pin */
#define _00_INTP9_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP9 pin */
#define _01_INTP8_EDGE_FALLING_SEL         (0x01U)    /* falling edge selected for INTP8 pin */
#define _00_INTP8_EDGE_FALLING_UNSEL       (0x00U)    /* falling edge not selected for INTP8 pin */

/*
    Program Status Word (PSW)
*/
/* Priority of interrupt currently being serviced (ISP1 - ISP0) */
#define _06_INTP_PRIORITY_LEVEL_ALL        (0x06U)    /* enables all interrupts */
#define _04_INTP_PRIORITY_LEVEL_0_2        (0x04U)    /* enables interrupt of level 0 to 2 */
#define _02_INTP_PRIORITY_LEVEL_0_1        (0x02U)    /* enables interrupt of level 0 and 1 */
#define _00_INTP_PRIORITY_LEVEL_0          (0x00U)    /* enables interrupt of level 0 */
#define _F9_INTP_PRIORITY_LEVEL_CLEAR      (0xF9U)    /* bits of ISP1 - ISP0 clear */
/* Interrupt request acknowledgment enable/disable (IE) */
#define _80_INTP_REQUEST_ACK_ENABLED       (0x80U)    /* enabled */
#define _00_INTP_REQUEST_ACK_DISABLED      (0x00U)    /* disabled */

/*
    External Interrupt Control Registers 0 To 2 (INTPCTL0 to INTPCTL2)
*/
/* Enabling or disabling of the noise filter for external interrupt INTPx (PNFENn) */
#define _00_INTP_NOISE_FILTER_ENABLE       (0x00U)    /* the noise filter is enabled */
#define _80_INTP_NOISE_FILTER_DISABLE      (0x80U)    /* the noise filter is disabled */
/* Selecting the filter for external interrupt INTPx (INTFCKn1, INTFCKn0) */
#define _00_INTP_NOISE_FILTER_NONE         (0x00U)    /* the INTPx filter is disabled */
#define _20_INTP_NOISE_FILTER_FCLK         (0x20U)    /* the INTPx filter is enabled, sampling at fCLK */
#define _40_INTP_NOISE_FILTER_FCLK8        (0x40U)    /* the INTPx filter is enabled, sampling at fCLK/8 */
#define _60_INTP_NOISE_FILTER_TO01_OUTPUT  (0x60U)    /* the INTPx filter is enabled, sampling at TO01 output */
/* Inverting the output of the external interrupt INTPx signal (INTPINVn) */
#define _00_INTP_SIGNAL_NORMAL             (0x00U)    /* the INTPx signal is not inverted */
#define _10_INTP_SIGNAL_INVERTED           (0x10U)    /* the INTPx signal is inverted */
/* Selecting the valid edge of external interrupt INTPx (INTEGPn, INTEGNn) */
#define _00_INTP_EDGE_DISABLE              (0x00U)    /* edge detection is disabled */
#define _04_INTP_EDGE_FALLING              (0x04U)    /* falling edge */
#define _08_INTP_EDGE_RISING               (0x08U)    /* rising edge */
#define _0C_INTP_EDGE_BOTH                 (0x0CU)    /* both edges */
/* Selecting the route of external interrupt INTPx (INTPSTENn) */
#define _00_INTP_EXT_INT_SIGNAL_INTP       (0x00U)    /* external interrupt signal is set to INTPx */
#define _02_INTP_EXT_INT_SIGNAL_KB3        (0x02U)    /* signal for the 16-bit timers KB30, KB31,
                                                         and KB32 is set to INTPx */
/* Enabling or disabling of the 16-bit timers KB30, KB31, and KB32 with the INTPx */
#define _00_INTP_OUTPUT_SIGNAL_KB3_DISABLE (0x00U)    /* disable restart or forced output stop signal 2*/
#define _01_INTP_OUTPUT_SIGNAL_KB3_ENABLE  (0x01U)    /* enable restart or forced output stop signal 2*/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
