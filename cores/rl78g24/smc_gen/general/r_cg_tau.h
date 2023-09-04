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
* File Name        : r_cg_tau.h
* Version          : 1.0.20
* Device(s)        : R7F101GLGxFB
* Description      : General header file for TAU peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef TAU_H
#define TAU_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control of timer array unit 0 input clock (TAU0EN) */
#define _00_TAU0_CLOCK_STOP               (0x00U)    /* stops supply of input clock */
#define _01_TAU0_CLOCK_SUPPLY             (0x01U)    /* supplies input clock */

/*
   Peripheral Reset Control Register 0 (PRR0)
*/
/* Reset control of timer array unit 0 (TAU0RES) */
#define _00_TAU0_RESET_RELEASE            (0x00U)    /* unreset */
#define _01_TAU0_RESET_SET                (0x01U)    /* reset */

/*
    Timer Clock Select Register m (TPSm)
*/
/* Operating mode and clear mode selection (PRSm31 - PRSm30) */
#define _0000_TAU_CKM3_FCLK_8             (0x0000U)    /* ckm3 - fCLK/2^8 */
#define _1000_TAU_CKM3_FCLK_10            (0x1000U)    /* ckm3 - fCLK/2^10 */
#define _2000_TAU_CKM3_FCLK_12            (0x2000U)    /* ckm3 - fCLK/2^12 */
#define _3000_TAU_CKM3_FCLK_14            (0x3000U)    /* ckm3 - fCLK/2^14 */
#define _CFFF_TAU_CKM3_CLEAR              (0xCFFFU)    /* ckm3 - clear */
/* Operating mode and clear mode selection (PRSm21 - PRSm20) */
#define _0000_TAU_CKM2_FCLK_1             (0x0000U)    /* ckm2 - fCLK/2^1 */
#define _0100_TAU_CKM2_FCLK_2             (0x0100U)    /* ckm2 - fCLK/2^2 */
#define _0200_TAU_CKM2_FCLK_4             (0x0200U)    /* ckm2 - fCLK/2^4 */
#define _0300_TAU_CKM2_FCLK_6             (0x0300U)    /* ckm2 - fCLK/2^6 */
#define _FCFF_TAU_CKM2_CLEAR              (0xFCFFU)    /* ckm2 - clear */
/* Operating mode and clear mode selection (PRSm13 - PRSm10) */
#define _0000_TAU_CKM1_FCLK_0             (0x0000U)    /* ckm1 - fCLK */
#define _0010_TAU_CKM1_FCLK_1             (0x0010U)    /* ckm1 - fCLK/2^1 */
#define _0020_TAU_CKM1_FCLK_2             (0x0020U)    /* ckm1 - fCLK/2^2 */
#define _0030_TAU_CKM1_FCLK_3             (0x0030U)    /* ckm1 - fCLK/2^3 */
#define _0040_TAU_CKM1_FCLK_4             (0x0040U)    /* ckm1 - fCLK/2^4 */
#define _0050_TAU_CKM1_FCLK_5             (0x0050U)    /* ckm1 - fCLK/2^5 */
#define _0060_TAU_CKM1_FCLK_6             (0x0060U)    /* ckm1 - fCLK/2^6 */
#define _0070_TAU_CKM1_FCLK_7             (0x0070U)    /* ckm1 - fCLK/2^7 */
#define _0080_TAU_CKM1_FCLK_8             (0x0080U)    /* ckm1 - fCLK/2^8 */
#define _0090_TAU_CKM1_FCLK_9             (0x0090U)    /* ckm1 - fCLK/2^9 */
#define _00A0_TAU_CKM1_FCLK_10            (0x00A0U)    /* ckm1 - fCLK/2^10 */
#define _00B0_TAU_CKM1_FCLK_11            (0x00B0U)    /* ckm1 - fCLK/2^11 */
#define _00C0_TAU_CKM1_FCLK_12            (0x00C0U)    /* ckm1 - fCLK/2^12 */
#define _00D0_TAU_CKM1_FCLK_13            (0x00D0U)    /* ckm1 - fCLK/2^13 */
#define _00E0_TAU_CKM1_FCLK_14            (0x00E0U)    /* ckm1 - fCLK/2^14 */
#define _00F0_TAU_CKM1_FCLK_15            (0x00F0U)    /* ckm1 - fCLK/2^15 */
#define _FF0F_TAU_CKM1_CLEAR              (0xFF0FU)    /* ckm1 - clear */
/* Operating mode and clear mode selection (PRSm03 - PRSm00) */
#define _0000_TAU_CKM0_FCLK_0             (0x0000U)    /* ckm0 - fCLK */
#define _0001_TAU_CKM0_FCLK_1             (0x0001U)    /* ckm0 - fCLK/2^1 */
#define _0002_TAU_CKM0_FCLK_2             (0x0002U)    /* ckm0 - fCLK/2^2 */
#define _0003_TAU_CKM0_FCLK_3             (0x0003U)    /* ckm0 - fCLK/2^3 */
#define _0004_TAU_CKM0_FCLK_4             (0x0004U)    /* ckm0 - fCLK/2^4 */
#define _0005_TAU_CKM0_FCLK_5             (0x0005U)    /* ckm0 - fCLK/2^5 */
#define _0006_TAU_CKM0_FCLK_6             (0x0006U)    /* ckm0 - fCLK/2^6 */
#define _0007_TAU_CKM0_FCLK_7             (0x0007U)    /* ckm0 - fCLK/2^7 */
#define _0008_TAU_CKM0_FCLK_8             (0x0008U)    /* ckm0 - fCLK/2^8 */
#define _0009_TAU_CKM0_FCLK_9             (0x0009U)    /* ckm0 - fCLK/2^9 */
#define _000A_TAU_CKM0_FCLK_10            (0x000AU)    /* ckm0 - fCLK/2^10 */
#define _000B_TAU_CKM0_FCLK_11            (0x000BU)    /* ckm0 - fCLK/2^11 */
#define _000C_TAU_CKM0_FCLK_12            (0x000CU)    /* ckm0 - fCLK/2^12 */
#define _000D_TAU_CKM0_FCLK_13            (0x000DU)    /* ckm0 - fCLK/2^13 */
#define _000E_TAU_CKM0_FCLK_14            (0x000EU)    /* ckm0 - fCLK/2^14 */
#define _000F_TAU_CKM0_FCLK_15            (0x000FU)    /* ckm0 - fCLK/2^15 */
#define _FFF0_TAU_CKM0_CLEAR              (0xFFF0U)    /* ckm0 - clear */

/*
    Timer Mode Register mn (TMRmn)
*/
/* Selection of macro clock (MCK) of channel n (CKSmn1 - CKSmn0) */
#define _0000_TAU_CLOCK_SELECT_CKM0       (0x0000U)    /* operation clock CK0 set by PRS register */
#define _8000_TAU_CLOCK_SELECT_CKM1       (0x8000U)    /* operation clock CK1 set by PRS register */
#define _4000_TAU_CLOCK_SELECT_CKM2       (0x4000U)    /* operation clock CK2 set by PRS register */
#define _C000_TAU_CLOCK_SELECT_CKM3       (0xC000U)    /* operation clock CK3 set by PRS register */
/* Selection of count clock (CCK) of channel n (CCSmn) */
#define _0000_TAU_CLOCK_MODE_CKS          (0x0000U)    /* macro clock MCK specified by CKSmn bit */
#define _1000_TAU_CLOCK_MODE_TIMN         (0x1000U)    /* valid edge of input signal input from TImn pin */
/* Selection of slave/master of channel n (MASTERmn) */
#define _0000_TAU_COMBINATION_SLAVE       (0x0000U)    /* operates as slave channel */
#define _0800_TAU_COMBINATION_MASTER      (0x0800U)    /* channel2, 4, 6 operates as master channel */
/* Operation explanation of channel 1 or 3 (SPLIT) */
#define _0000_TAU_16BITS_MODE             (0x0000U)    /* operates as 16 bits timer */
#define _0800_TAU_8BITS_MODE              (0x0800U)    /* operates as 8 bits timer */
/* Setting of start trigger or capture trigger of channel n (STSmn2 - STSmn0) */
#define _0000_TAU_TRIGGER_SOFTWARE        (0x0000U)    /* only software trigger start is valid */
#define _0100_TAU_TRIGGER_TIMN_VALID      (0x0100U)    /* TImn input edge is used as a start/capture trigger */
#define _0200_TAU_TRIGGER_TIMN_BOTH       (0x0200U)    /* TImn input edges are used as a start/capture trigger */
#define _0400_TAU_TRIGGER_MASTER_INT      (0x0400U)    /* interrupt signal of the master channel is used */
/* Selection of TImn pin input valid edge (CISmn1 - CISmn0) */
#define _0000_TAU_TIMN_EDGE_FALLING       (0x0000U)    /* falling edge */
#define _0040_TAU_TIMN_EDGE_RISING        (0x0040U)    /* rising edge */
#define _0080_TAU_TIMN_EDGE_BOTH_LOW      (0x0080U)    /* both edges (when low-level width is measured) */
#define _00C0_TAU_TIMN_EDGE_BOTH_HIGH     (0x00C0U)    /* both edges (when high-level width is measured) */
/* Operation mode of channel n (MDmn3 - MDmn0) */
#define _0000_TAU_MODE_INTERVAL_TIMER     (0x0000U)    /* interval timer mode */
#define _0004_TAU_MODE_CAPTURE            (0x0004U)    /* capture mode */
#define _0006_TAU_MODE_EVENT_COUNT        (0x0006U)    /* event counter mode */
#define _0008_TAU_MODE_ONE_COUNT          (0x0008U)    /* one count mode */
#define _000C_TAU_MODE_HIGHLOW_MEASURE    (0x000CU)    /* high-/low-level width measurement mode */
#define _0001_TAU_MODE_PWM_MASTER         (0x0001U)    /* PWM Function (Master Channel) mode */
#define _0009_TAU_MODE_PWM_SLAVE          (0x0009U)    /* PWM Function (Slave Channel) mode */
#define _0008_TAU_MODE_ONESHOT            (0x0008U)    /* one-shot pulse output mode */
/* Setting of starting counting and interrupt (MDmn0) */
#define _0000_TAU_START_INT_UNUSED        (0x0000U)    /* interrupt is not generated when counting is started */
#define _0001_TAU_START_INT_USED          (0x0001U)    /* interrupt is generated when counting is started */

/*
    Timer Status Register mn (TSRmn)
*/
/* Counter overflow status of channel n (OVF) */
#define _0000_TAU_OVERFLOW_NOT_OCCURS     (0x0000U)    /* overflow does not occur */
#define _0001_TAU_OVERFLOW_OCCURS         (0x0001U)    /* overflow occurs */

/*
    Timer Channel Enable Status Register m (TEm)
*/
/* Indication of operation enable/stop status of channel 3 higher 8 bits (TEHm3) */
#define _0000_TAU_CH3_H8_OPERATION_STOP   (0x0000U)    /* operation is stopped */
#define _0800_TAU_CH3_H8_OPERATION_ENABLE (0x0800U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 1 higher 8 bits (TEHm1) */
#define _0000_TAU_CH1_H8_OPERATION_STOP   (0x0000U)    /* operation is stopped */
#define _0200_TAU_CH1_H8_OPERATION_ENABLE (0x0200U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 3 (TEm3) */
#define _0000_TAU_CH3_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0008_TAU_CH3_OPERATION_ENABLE    (0x0008U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 2 (TEm2) */
#define _0000_TAU_CH2_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0004_TAU_CH2_OPERATION_ENABLE    (0x0004U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 1 (TEm1) */
#define _0000_TAU_CH1_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0002_TAU_CH1_OPERATION_ENABLE    (0x0002U)    /* operation is enabled */
/* Indication of operation enable/stop status of channel 0 (TEm0) */
#define _0000_TAU_CH0_OPERATION_STOP      (0x0000U)    /* operation is stopped */
#define _0001_TAU_CH0_OPERATION_ENABLE    (0x0001U)    /* operation is enabled */

/*
    Timer Channel Start Register m (TSm)
*/
/* Operation enable (start) trigger of channel 3 higher 8 bits (TSHm3) */
#define _0000_TAU_CH3_H8_START_TRG_OFF    (0x0000U)    /* no trigger operation */
#define _0800_TAU_CH3_H8_START_TRG_ON     (0x0800U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 1 higher 8 bits (TSHm1) */
#define _0000_TAU_CH1_H8_START_TRG_OFF    (0x0000U)    /* no trigger operation */
#define _0200_TAU_CH1_H8_START_TRG_ON     (0x0200U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 3 (TSm3) */
#define _0000_TAU_CH3_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0008_TAU_CH3_START_TRG_ON        (0x0008U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 2 (TSm2) */
#define _0000_TAU_CH2_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0004_TAU_CH2_START_TRG_ON        (0x0004U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 1 (TSm1) */
#define _0000_TAU_CH1_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0002_TAU_CH1_START_TRG_ON        (0x0002U)    /* operation is enabled (start trigger is generated) */
/* Operation enable (start) trigger of channel 0 (TSm0) */
#define _0000_TAU_CH0_START_TRG_OFF       (0x0000U)    /* no trigger operation */
#define _0001_TAU_CH0_START_TRG_ON        (0x0001U)    /* operation is enabled (start trigger is generated) */

/*
    Timer Channel Stop Register m (TTm)
*/
/* Operation stop trigger of channel 3 higher 8 bits (TTHm3) */
#define _0000_TAU_CH3_H8_STOP_TRG_OFF     (0x0000U)    /* no trigger operation */
#define _0800_TAU_CH3_H8_STOP_TRG_ON      (0x0800U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 higher 8 bits (TTHm1) */
#define _0000_TAU_CH1_H8_STOP_TRG_OFF     (0x0000U)    /* no trigger operation */
#define _0200_TAU_CH1_H8_STOP_TRG_ON      (0x0200U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 3 (TTm3) */
#define _0000_TAU_CH3_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0008_TAU_CH3_STOP_TRG_ON         (0x0008U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 2 (TTm2) */
#define _0000_TAU_CH2_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0004_TAU_CH2_STOP_TRG_ON         (0x0004U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 1 (TTm1) */
#define _0000_TAU_CH1_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0002_TAU_CH1_STOP_TRG_ON         (0x0002U)    /* operation is stopped (stop trigger is generated) */
/* Operation stop trigger of channel 0 (TTm0) */
#define _0000_TAU_CH0_STOP_TRG_OFF        (0x0000U)    /* no trigger operation */
#define _0001_TAU_CH0_STOP_TRG_ON         (0x0001U)    /* operation is stopped (stop trigger is generated) */

/*
    Timer I/O Selection Register 0 (TIOS0)
*/
/* Signal switching of timer inputs used in channel 0 (TIS07 - TIS05) */
#define _00_TAU_CH0_INPUT_TI00            (0x00U)    /* input signal of timer input terminal (TI00) */
#define _20_TAU_CH0_INPUT_TRDIOB0         (0x20U)    /* timer RD2 output signal (TRDIOB0) not via PWMOPA */
#define _40_TAU_CH0_INPUT_TRDIOD0         (0x40U)    /* timer RD2 output signal (TRDIOD0) not via PWMOPA */
#define _60_TAU_CH0_INPUT_TRDIOA1         (0x60U)    /* timer RD2 output signal (TRDIOA1) not via PWMOPA */
#define _80_TAU_CH0_INPUT_TRDIOC1         (0x80U)    /* timer RD2 output signal (TRDIOC1) not via PWMOPA */
#define _A0_TAU_CH0_INPUT_TRDIOB1         (0xA0U)    /* timer RD2 output signal (TRDIOB1) not via PWMOPA */
#define _C0_TAU_CH0_INPUT_TRDIOD1         (0xC0U)    /* timer RD2 output signal (TRDIOD1) not via PWMOPA */
#define _E0_TAU_CH0_INPUT_TRDIOC0         (0xE0U)    /* timer RD2 output signal (TRDIOC0) not via PWMOPA */
#define _0F_TAU_CH0_INPUT_CLEAR           (0x0FU)    /* TI00 clear */
/* Select timer input to use on channel 0 (TIS04) */
#define _EF_TAU_CH0_INPUT_TIS             (0xEFU)    /* input signal specified at TIS07-TIS05 bit */
#define _10_TAU_CH0_INPUT_ELC             (0x10U)    /* event input signal from ELC */
/* TAU channel 2 output permission/prohibition to P17 terminal (TOS03) */
#define _F7_TAU_CH2_OUTPUT_ENABLE         (0xF7U)    /* output permission */
#define _08_TAU_CH2_OUTPUT_DISABLE        (0x08U)    /* no output (fixed to L) */
/* Select timer input to use in channel 1 (TIS02 - TIS00) */
#define _00_TAU_CH1_INPUT_TI01            (0x00U)    /* input signal of timer input terminal (TI01) */
#define _01_TAU_CH1_INPUT_ELC             (0x01U)    /* event input signal from ELC */
#define _02_TAU_CH1_INPUT_TI01            (0x02U)    /* input signal of timer input terminal (TI01) */
#define _03_TAU_CH1_INPUT_FIMP            (0x03U)    /* medium speed on-chip oscillator clock (fIMP) */
#define _04_TAU_CH1_INPUT_FIL             (0x04U)    /* slow on-chip oscillator clock (fIL) */
#define _05_TAU_CH1_INPUT_FSUB            (0x05U)    /* subsystem clock (fSUB) */
#define _F8_TAU_CH1_INPUT_CLEAR           (0xF8U)    /* TI01 clear */

/*
    Timer Output Enable Register m (TOEm)
*/
/* Timer output enable/disable of channel 3 (TOEm3) */
#define _0008_TAU_CH3_OUTPUT_ENABLE       (0x0008U)    /* the TOm3 operation enabled by count operation */
#define _0000_TAU_CH3_OUTPUT_DISABLE      (0x0000U)    /* the TOm3 operation stopped by count operation */
/* Timer output enable/disable of channel 2 (TOEm2) */
#define _0004_TAU_CH2_OUTPUT_ENABLE       (0x0004U)    /* the TOm2 operation enabled by count operation */
#define _0000_TAU_CH2_OUTPUT_DISABLE      (0x0000U)    /* the TOm2 operation stopped by count operation */
/* Timer output enable/disable of channel 1 (TOEm1) */
#define _0002_TAU_CH1_OUTPUT_ENABLE       (0x0002U)    /* the TOm1 operation enabled by count operation */
#define _0000_TAU_CH1_OUTPUT_DISABLE      (0x0000U)    /* the TOm1 operation stopped by count operation */
/* Timer output enable/disable of channel 0 (TOEm0) */
#define _0001_TAU_CH0_OUTPUT_ENABLE       (0x0001U)    /* the TOm0 operation enabled by count operation */
#define _0000_TAU_CH0_OUTPUT_DISABLE      (0x0000U)    /* the TOm0 operation stopped by count operation */

/*
    Timer Output Register m (TOm)
*/
/* Timer output of channel 3 (TOm3) */
#define _0000_TAU_CH3_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0008_TAU_CH3_OUTPUT_VALUE_1      (0x0008U)    /* timer output value is "1" */
/* Timer output of channel 2 (TOm2) */
#define _0000_TAU_CH2_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0004_TAU_CH2_OUTPUT_VALUE_1      (0x0004U)    /* timer output value is "1" */
/* Timer output of channel 1 (TOm1) */
#define _0000_TAU_CH1_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0002_TAU_CH1_OUTPUT_VALUE_1      (0x0002U)    /* timer output value is "1" */
/* Timer output of channel 0 (TOm0) */
#define _0000_TAU_CH0_OUTPUT_VALUE_0      (0x0000U)    /* timer output value is "0" */
#define _0001_TAU_CH0_OUTPUT_VALUE_1      (0x0001U)    /* timer output value is "1" */

/*
    Timer Output Level Register 0 (TOLm)
*/
/* Control of timer output level of channel 3 (TOLm3) */
#define _0000_TAU_CH3_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0008_TAU_CH3_OUTPUT_LEVEL_L      (0x0008U)    /* inverted output (active-low) */
/* Control of timer output level of channel 2 (TOLm2) */
#define _0000_TAU_CH2_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0004_TAU_CH2_OUTPUT_LEVEL_L      (0x0004U)    /* inverted output (active-low) */
/* Control of timer output level of channel 1 (TOLm1) */
#define _0000_TAU_CH1_OUTPUT_LEVEL_H      (0x0000U)    /* positive logic output (active-high) */
#define _0002_TAU_CH1_OUTPUT_LEVEL_L      (0x0002U)    /* inverted output (active-low) */

/*
    Timer Output Mode Register m (TOMm)
*/
/* Control of timer output mode of channel 3 (TOMm3) */
#define _0000_TAU_CH3_MASTER_OUTPUT       (0x0000U)    /* master channel output mode  */
#define _0008_TAU_CH3_SLAVE_OUTPUT        (0x0008U)    /* slave channel output mode */
/* Control of timer output mode of channel 2 (TOMm2) */
#define _0000_TAU_CH2_MASTER_OUTPUT       (0x0000U)    /* master channel output mode  */
#define _0004_TAU_CH2_SLAVE_OUTPUT        (0x0004U)    /* slave channel output mode */
/* Control of timer output mode of channel 1 (TOMm1) */
#define _0000_TAU_CH1_MASTER_OUTPUT       (0x0000U)    /* master channel output mode  */
#define _0002_TAU_CH1_SLAVE_OUTPUT        (0x0002U)    /* slave channel output mode */

/*
    Input Switch Control Register (ISC)
*/
/* Set the SSI00 input for channel 0 in CSI00 communication and slave mode (SSIE00) */
#define _00_TAU_CH0_SSI00_DISABLE         (0x00U)    /* invalid SSI00 terminal input */
#define _80_TAU_CH0_SSI00_ENABLE          (0x80U)    /* enable SSI00 terminal input */
/* Switching inputs for channel 0 in the timer array unit (ISC1) */
#define _00_TAU_CH3_INPUT_TI03            (0x00U)    /* the input signal of the TI03 terminal is the timer input
                                                        (normal operation) */
#define _02_TAU_CH3_INPUT_RXD0            (0x02U)    /* the input signal of the RxD0 terminal is the timer input
                                                        (wake-up signal detection and break field) */
#define _FD_TAU_CH3_INPUT_CLEAR           (0xFDU)    /* channel3 input clear */
/* Input switching of external interrupts (INTP0) (ISC0) */
#define _00_TAU_CH0_INPUT_INTP0           (0x00U)    /* the input signal of the INTP0 terminal is an external
                                                        interrupt input (normal operation) */
#define _01_TAU_CH0_INPUT_RXD0            (0x01U)    /* the input signal of the RxD0 terminal is an external
                                                        interrupt input (wake-up signal detection) */

/*
    Noise Filter Enable Register 1 (NFENm)
*/
/* Enable/disable using noise filter of TIm3 pin input signal (TNFENm3) */
#define _00_TAU_CH3_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _08_TAU_CH3_NOISE_ON              (0x08U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm2 pin input signal (TNFENm2) */
#define _00_TAU_CH2_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _04_TAU_CH2_NOISE_ON              (0x04U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm1 pin input signal (TNFENm1) */
#define _00_TAU_CH1_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _02_TAU_CH1_NOISE_ON              (0x02U)    /* noise filter ON */
/* Enable/disable using noise filter of TIm0 pin input signal (TNFENm0) */
#define _00_TAU_CH0_NOISE_OFF             (0x00U)    /* noise filter OFF */
#define _01_TAU_CH0_NOISE_ON              (0x01U)    /* noise filter ON */

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
