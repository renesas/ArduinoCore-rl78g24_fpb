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
* File Name        : r_cg_trd.h
* Version          : 1.0.20
* Device(s)        : R7F101GLGxFB
* Description      : General header file for TRD peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef TRD_H
#define TRD_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 2 (PER2)
*/
/* Control of timer RD2 input clock supply (TRD0EN) */
#define _00_TRD_CLOCK_STOP                       (0x00U)    /* stops input clock supply */
#define _08_TRD_CLOCK_SUPPLY                     (0x08U)    /* enables input clock supply */
/* Control of PWMOPA input clock supply (PWMOPEN) */
#define _00_TRD_PWMOPA_CLOCK_STOP                (0x00U)    /* stops input clock supply */
#define _04_TRD_PWMOPA_CLOCK_SUPPLY              (0x04U)    /* enables input clock supply */

/*
    Peripheral Reset Control Register 0 (PRR2)
*/
/* Peripheral reset control of timer RD2 (TRD0RES) */
#define _00_TRD_RESET_RELEASE                    (0x00U)    /* released from the reset state */
#define _08_TRD_RESET_SET                        (0x08U)    /* reset */
/* Peripheral reset control of PWMOPA (PWMOPRES) */
#define _00_TRD_PWMOPA_RESET_RELEASE             (0x00U)    /* released from the reset state */
#define _04_TRD_PWMOPA_RESET_SET                 (0x04U)    /* reset */

/*
    Timer RD ELC Register (TRDELC)
*/
/* ELC event input 1 enable/disable for timer RD2 pulse output forced cutoff (ELCOBE1) */
#define _00_TRD_ELC1_CUTOFF_DISABLE              (0x00U)    /* forced cutoff is disabled */
#define _20_TRD_ELC1_CUTOFF_ENABLE               (0x20U)    /* forced cutoff is enabled */
/* ELC event input 1 select for timer RD2 input capture D1 (ELCICE1) */
#define _00_TRD_TRD1_INPUT_CAPTURE               (0x00U)    /* input capture D1 is selected */
#define _10_TRD_TRD1_ELC_SELECT                  (0x10U)    /* event input 1 from the ELC is selected */
/* ELC event input 0 enable/disable for timer RD2 pulse output forced cutoff (ELCOBE0) */
#define _00_TRD_ELC0_CUTOFF_DISABLE              (0x00U)    /* forced cutoff is disabled */
#define _02_TRD_ELC0_CUTOFF_ENABLE               (0x02U)    /* forced cutoff is enabled */
/* ELC event input 0 select for timer RD2 input capture D0 (ELCICE0) */
#define _00_TRD_TRD0_INPUT_CAPTURE               (0x00U)    /* input capture D0 is selected */
#define _01_TRD_TRD0_ELC_SELECT                  (0x01U)    /* event input 0 from the ELC is selected */

/*
    Timer RD KB3 PWM Output Gate Mode Control Register (TRDBCR)
*/
/* Timer KB3 PWM output gate mode effective (GCE) */
#define _00_TRD_KB3_GATE_FUNCTION_DISABLE        (0x00U)    /* KB3 gate function is disabled */
#define _80_TRD_KB3_GATE_FUNCTION_ENABLE         (0x80U)    /* KB3 gate function is enabled */
/* Timer KB3 output gate mode count source selection (GCKS) */
#define _00_TRD_KB3_COUNT_SOURCE_TKBTCK0         (0x00U)    /* count source select TKBTCK0 */
#define _10_TRD_KB3_COUNT_SOURCE_TKBTCK1         (0x10U)    /* count source select TKBTCK1 */
/* Timer KB3 PWM output gate mode operation selection (GCE) */
#define _00_TRD_KB3_STANDALONE_MODE              (0x00U)    /* standalone mode */
#define _01_TRD_KB3_INTERLOCKED_MODE             (0x01U)    /* timer KB3 interlocked mode */
#define _11_TRD_KB3_GATE_FUNCTION_DISABLE        (0x11U)    /* KB3 gate function is disabled */

/*
    Timer RD KB3 PWM Output Monitor Register (TRDBOF)
*/
/* Timer KB3 PWM output monitor flag 5 (BOF5) */
#define _00_TRD_KB3_TRDTKBOUT5_LOW_LEVEL         (0x00U)    /* low level */
#define _20_TRD_KB3_TRDTKBOUT5_HIGH_LEVEL        (0x20U)    /* high level */
/* Timer KB3 PWM output monitor flag 4 (BOF4) */
#define _00_TRD_KB3_TRDTKBOUT4_LOW_LEVEL         (0x00U)    /* low level */
#define _10_TRD_KB3_TRDTKBOUT4_HIGH_LEVEL        (0x10U)    /* high level */
/* Timer KB3 PWM output monitor flag 3 (BOF3) */
#define _00_TRD_KB3_TRDTKBOUT3_LOW_LEVEL         (0x00U)    /* low level */
#define _08_TRD_KB3_TRDTKBOUT3_HIGH_LEVEL        (0x08U)    /* high level */
/* Timer KB3 PWM output monitor flag 2 (BOF2) */
#define _00_TRD_KB3_TRDTKBOUT2_LOW_LEVEL         (0x00U)    /* low level */
#define _04_TRD_KB3_TRDTKBOUT2_HIGH_LEVEL        (0x04U)    /* high level */
/* Timer KB3 PWM output monitor flag 1 (BOF1) */
#define _00_TRD_KB3_TRDTKBOUT1_LOW_LEVEL         (0x00U)    /* low level */
#define _02_TRD_KB3_TRDTKBOUT1_HIGH_LEVEL        (0x02U)    /* high level */
/* Timer KB3 PWM output monitor flag 0 (BOF0) */
#define _00_TRD_KB3_TRDTKBOUT0_LOW_LEVEL         (0x00U)    /* low level */
#define _01_TRD_KB3_TRDTKBOUT0_HIGH_LEVEL        (0x01U)    /* high level */

/*
    Timer RD Start Register (TRDSTR)
*/
#define _01_TRD_COUNT_START_INITIAL_VALUE        (0x01U)    /* TRD0 count start */
#define _02_TRD_COUNT_START_INITIAL_VALUE        (0x02U)    /* TRD1 count start */
#define _03_TRD_COUNT_START_INITIAL_VALUE        (0x03U)    /* TRD0/TRD1 count start */
/* Selection of TRD1 count operation (CSEL1) */
#define _00_TRD_TRD1_COUNT_STOP_MATCH            (0x00U)    /* count stops at compare match with TRDGRA1 */
#define _08_TRD_TRD1_COUNT_CONTINUES             (0x08U)    /* count continues after compare match with TRDGRA1 */
/* Selection of TRD0 count operation (CSEL0) */
#define _00_TRD_TRD0_COUNT_STOP_MATCH            (0x00U)    /* count stops at compare match with TRDGRA0 */
#define _04_TRD_TRD0_COUNT_CONTINUES             (0x04U)    /* count continues after compare match with TRDGRA0 */
/* Control of TRD1 count start flag (TSTART1) */
#define _00_TRD_TRD1_COUNT_STOP                  (0x00U)    /* count stops */
#define _02_TRD_TRD1_COUNT_START                 (0x02U)    /* count starts */
/* Control of TRD0 count start flag (TSTART0) */
#define _00_TRD_TRD0_COUNT_STOP                  (0x00U)    /* count stops */
#define _01_TRD_TRD0_COUNT_START                 (0x01U)    /* count starts */

/*
    Timer RD Mode Register (TRDMR)
*/
#define _C1_TRD_TRD0_FUNCTION_CLEAR              (0xC1U)    /* TRDBFC0 - TRDBFD0 clear */
#define _31_TRD_TRD1_FUNCTION_CLEAR              (0x31U)    /* TRDBFC1 - TRDBFD1 clear */
/* Selection of TRDGRD1 register function (TRDBFD1) */
#define _00_TRD_TRDGRD1_GENERAL                  (0x00U)    /* general register */
#define _80_TRD_TRDGRD1_BUFFER                   (0x80U)    /* buffer register of TRDGRB1 register */
/* Selection of TRDGRC1 register function (TRDBFC1) */
#define _00_TRD_TRDGRC1_GENERAL                  (0x00U)    /* general register */
#define _40_TRD_TRDGRC1_BUFFER                   (0x40U)    /* buffer register of TRDGRA1 register */
/* Selection of TRDGRD0 register function (TRDBFD0) */
#define _00_TRD_TRDGRD0_GENERAL                  (0x00U)    /* general register */
#define _20_TRD_TRDGRD0_BUFFER                   (0x20U)    /* buffer register of TRDGRB0 register */
/* Selection of TRDGRC0 register function (TRDBFC0) */
#define _00_TRD_TRDGRC0_GENERAL                  (0x00U)    /* general register */
#define _10_TRD_TRDGRC0_BUFFER                   (0x10U)    /* buffer register of TRDGRA0 register */
/* Selection of timer RD2 synchronous (TRDSYNC) */
#define _00_TRD_INDEPENDENTLY                    (0x00U)    /* TRD0 and TRD1 operate independently */
#define _01_TRD_SYNCHRONOUSLY                    (0x01U)    /* TRD0 and TRD1 operate synchronously */

/*
    Timer RD PWM Function Select Register (TRDPMR)
*/
/* Selection of PWM function of TRDIOD1 (TRDPWMD1) */
#define _00_TRD_TRDIOD1_TIMER_MODE               (0x00U)    /* input capture function or output compare function */
#define _40_TRD_TRDIOD1_PWM_MODE                 (0x40U)    /* PWM function */
/* Selection of PWM function of TRDIOC1 (TRDPWMC1) */
#define _00_TRD_TRDIOC1_TIMER_MODE               (0x00U)    /* input capture function or output compare function */
#define _20_TRD_TRDIOC1_PWM_MODE                 (0x20U)    /* PWM function */
/* Selection of PWM function of TRDIOB1 (TRDPWMB1) */
#define _00_TRD_TRDIOB1_TIMER_MODE               (0x00U)    /* input capture function or output compare function */
#define _10_TRD_TRDIOB1_PWM_MODE                 (0x10U)    /* PWM function */
/* Selection of PWM function of TRDIOD0 (TRDPWMD0) */
#define _00_TRD_TRDIOD0_TIMER_MODE               (0x00U)    /* input capture function or output compare function */
#define _04_TRD_TRDIOD0_PWM_MODE                 (0x04U)    /* PWM function */
/* Selection of PWM function of TRDIOC0 (TRDPWMC0) */
#define _00_TRD_TRDIOC0_TIMER_MODE               (0x00U)    /* input capture function or output compare function */
#define _02_TRD_TRDIOC0_PWM_MODE                 (0x02U)    /* PWM function */
/* Selection of PWM function of TRDIOB0 (TRDPWMB0) */
#define _00_TRD_TRDIOB0_TIMER_MODE               (0x00U)    /* input capture function or output compare function */
#define _01_TRD_TRDIOB0_PWM_MODE                 (0x01U)    /* PWM function */
/* In timer KB3 PWM output gate mode */
/* TRDTKBOUT3 output permission (TRDPWMA1) */
#define _00_TRD_KB3_TRDTKBOUT3_OUTPUT_DISABLE    (0x00U)    /* TRDTKBOUT3 output disable */
#define _80_TRD_KB3_TRDTKBOUT3_OUTPUT_ENABLE     (0x80U)    /* TRDTKBOUT3 output enable */
/* TRDTKBOUT2 output permission (TRDPWMD1) */
#define _00_TRD_KB3_TRDTKBOUT2_OUTPUT_DISABLE    (0x00U)    /* TRDTKBOUT3 output disable */
#define _40_TRD_KB3_TRDTKBOUT2_OUTPUT_ENABLE     (0x40U)    /* TRDTKBOUT3 output enable */
/* TRDTKBOUT1 output permission (TRDPWMC1) */
#define _00_TRD_KB3_TRDTKBOUT1_OUTPUT_DISABLE    (0x00U)    /* TRDTKBOUT3 output disable */
#define _20_TRD_KB3_TRDTKBOUT1_OUTPUT_ENABLE     (0x20U)    /* TRDTKBOUT3 output enable */
/* TRDTKBOUT0 output permission (TRDPWMB1) */
#define _00_TRD_KB3_TRDTKBOUT0_OUTPUT_DISABLE    (0x00U)    /* TRDTKBOUT3 output disable */
#define _10_TRD_KB3_TRDTKBOUT0_OUTPUT_ENABLE     (0x10U)    /* TRDTKBOUT3 output enable */
/* TRDTKBOUT5 output permission (TRDPWMD0) */
#define _00_TRD_KB3_TRDTKBOUT5_OUTPUT_DISABLE    (0x00U)    /* TRDTKBOUT3 output disable */
#define _04_TRD_KB3_TRDTKBOUT5_OUTPUT_ENABLE     (0x04U)    /* TRDTKBOUT3 output enable */
/* TRDTKBOUT4 output permission (TRDPWMB0) */
#define _00_TRD_KB3_TRDTKBOUT4_OUTPUT_DISABLE    (0x00U)    /* TRDTKBOUT3 output disable */
#define _01_TRD_KB3_TRDTKBOUT4_OUTPUT_ENABLE     (0x01U)    /* TRDTKBOUT3 output enable */

/*
    Timer RD Function Control Register (TRDFCR)
*/
#define _80_TRD_TRDFCR_DEFAULT_VALUE             (0x80U)
/* Selection of PWM3 mode (PWM3) */
#define _00_TRD_PWM3_MODE                        (0x00U)    /* PWM3 mode */
#define _80_TRD_OTHER_MODE                       (0x80U)    /* timer mode and extended PWM mode */
/* Selection of external clock input (STCLK) */
#define _00_TRD_EXTERNAL_CLOCK_DISABLE           (0x00U)    /* external clock input disabled */
#define _40_TRD_EXTERNAL_CLOCK_ENABLE            (0x40U)    /* external clock input enabled */
/* Selection of extended complementary PWM mode or extended PWM mode (EPWM) */
#define _00_TRD_OTHER_PWM_MODE                   (0x00U)    /* other mode */
#define _20_TRD_EXTEND_PWM_MODE                  (0x20U)    /* extended complementary PWM mode or extended PWM mode */
/* Selection of extended complementary PWM mode action (CPSS) */
#define _00_TRD_PWM_OUTPUT_SYMMETRY              (0x00U)    /* symmetry PWM output */
#define _10_TRD_PWM_OUTPUT_ASYMMETRY             (0x10U)    /* asymmetry PWM output */
/* Selection of counter-phase output level (OLS1) */
#define _00_TRD_COUNTER_PHASE_LEVEL_HL           (0x00U)    /* high initial output and low active level */
#define _08_TRD_COUNTER_PHASE_LEVEL_LH           (0x08U)    /* low initial output and high active level */
/* Selection of phase output level (OLS0) */
#define _00_TRD_NORMAL_PHASE_LEVEL_HL            (0x00U)    /* high initial output and low active level */
#define _04_TRD_NORMAL_PHASE_LEVEL_LH            (0x04U)    /* low initial output and high active level */
/* Selection of combination mode (CMD1, CMD0) */
#define _00_TRD_TIMER_PWM_MODE                   (0x00U)    /* timer, PWM3, and extended PWM modes */
#define _01_TRD_RESET_SYNCHRONOUS_MODE           (0x01U)    /* reset synchronous PWM mode */
#define _02_TRD_EXTEND_COMPLE_PWM_MODE           (0x02U)    /* extended complementary PWM mode */
#define _02_TRD_TRANSFER_TRD1_UNDERFLOW          (0x02U)    /* complementary PWM mode (when TRD1 underflows) */
#define _03_TRD_TRANSFER_TRD0_MATCH              (0x03U)    /* complementary PWM mode (at compare match) */
#define _FC_TRD_COMBINATION_MODE_CLEAR           (0xFCU)    /* bit CMD1 - CMD0 clear */

/*
    Timer RD Output Master Enable Register 1 (TRDOER1)
*/
#define _F0_TRD_TRD0_OUTPUT_CLEAR                (0xF0U)    /* TRD0 output clear */
#define _0F_TRD_TRD1_OUTPUT_CLEAR                (0x0FU)    /* TRD1 output clear */
/* TRDIOD1 output enable/disable (ED1) */
#define _00_TRD_TRDIOD1_OUTPUT_ENABLE            (0x00U)    /* output enabled */
#define _80_TRD_TRDIOD1_OUTPUT_DISABLE           (0x80U)    /* output disabled */
/* TRDIOC1 output enable/disable (EC1) */
#define _00_TRD_TRDIOC1_OUTPUT_ENABLE            (0x00U)    /* output enabled */
#define _40_TRD_TRDIOC1_OUTPUT_DISABLE           (0x40U)    /* output disabled */
/* TRDIOB1 output enable/disable (EB1) */
#define _00_TRD_TRDIOB1_OUTPUT_ENABLE            (0x00U)    /* output enabled */
#define _20_TRD_TRDIOB1_OUTPUT_DISABLE           (0x20U)    /* output disabled */
/* TRDIOA1 output enable/disable (EA1) */
#define _00_TRD_TRDIOA1_OUTPUT_ENABLE            (0x00U)    /* output enabled */
#define _10_TRD_TRDIOA1_OUTPUT_DISABLE           (0x10U)    /* output disabled */
/* TRDIOD0 output enable/disable (ED0) */
#define _00_TRD_TRDIOD0_OUTPUT_ENABLE            (0x00U)    /* output enabled */
#define _08_TRD_TRDIOD0_OUTPUT_DISABLE           (0x08U)    /* output disabled */
/* TRDIOC0 output enable/disable (EC0) */
#define _00_TRD_TRDIOC0_OUTPUT_ENABLE            (0x00U)    /* output enabled */
#define _04_TRD_TRDIOC0_OUTPUT_DISABLE           (0x04U)    /* output disabled */
/* TRDIOB0 output enable/disable (EB0) */
#define _00_TRD_TRDIOB0_OUTPUT_ENABLE            (0x00U)    /* output enabled */
#define _02_TRD_TRDIOB0_OUTPUT_DISABLE           (0x02U)    /* output disabled */
/* TRDIOA0 output enable/disable (EA0) */
#define _00_TRD_TRDIOA0_OUTPUT_ENABLE            (0x00U)    /* output enabled */
#define _01_TRD_TRDIOA0_OUTPUT_DISABLE           (0x01U)    /* output disabled */

/*
    Timer RD Output Master Enable Register 2 (TRDOER2)
*/
/* INTP0 of pulse output forced cutoff signal input enable/disable (TRDPTO) */
#define _00_TRD_INTP0_CUTOFF_DISABLE             (0x00U)    /* pulse output forced cutoff input disabled */
#define _80_TRD_INTP0_CUTOFF_ENABLE              (0x80U)    /* pulse output forced cutoff input enabled */
/* Forced cutoff flag (TRDSHUTS) */
#define _00_TRD_NOT_FORCE_CUTOFF                 (0x00U)    /* not forcibly cut off */
#define _01_TRD_FORCE_CUTOFF                     (0x01U)    /* forcibly cut off */

/*
    Timer RD Output Control Register (TRDOCR)
*/
/* In Output compare function */
#define _F0_TRD_TRD0_INITIAL_OUTPUT_CLEAR        (0xF0U)    /* TRD0 initial output clear */
#define _0F_TRD_TRD1_INITIAL_OUTPUT_CLEAR        (0x0FU)    /* TRD1 initial output clear */
/* Selection of TRDIOD1 initial output level (TOD1) */
#define _00_TRD_TRDIOD1_INITIAL_OUTPUT_L         (0x00U)    /* low initial output */
#define _80_TRD_TRDIOD1_INITIAL_OUTPUT_H         (0x80U)    /* high initial output */
/* Selection of TRDIOC1 initial output level (TOC1) */
#define _00_TRD_TRDIOC1_INITIAL_OUTPUT_L         (0x00U)    /* low initial output */
#define _40_TRD_TRDIOC1_INITIAL_OUTPUT_H         (0x40U)    /* high initial output */
/* Selection of TRDIOB1 initial output level (TOB1) */
#define _00_TRD_TRDIOB1_INITIAL_OUTPUT_L         (0x00U)    /* low initial output */
#define _20_TRD_TRDIOB1_INITIAL_OUTPUT_H         (0x20U)    /* high initial output */
/* Selection of TRDIOA1 initial output level (TOA1) */
#define _00_TRD_TRDIOA1_INITIAL_OUTPUT_L         (0x00U)    /* low initial output */
#define _10_TRD_TRDIOA1_INITIAL_OUTPUT_H         (0x10U)    /* high initial output */
/* Selection of TRDIOD0 initial output level (TOD0) */
#define _00_TRD_TRDIOD0_INITIAL_OUTPUT_L         (0x00U)    /* low initial output */
#define _08_TRD_TRDIOD0_INITIAL_OUTPUT_H         (0x08U)    /* high initial output */
/* Selection of TRDIOC0 initial output level (TOC0) */
#define _00_TRD_TRDIOC0_INITIAL_OUTPUT_L         (0x00U)    /* low initial output */
#define _04_TRD_TRDIOC0_INITIAL_OUTPUT_H         (0x04U)    /* high initial output */
/* Selection of TRDIOB0 initial output level (TOB0) */
#define _00_TRD_TRDIOB0_INITIAL_OUTPUT_L         (0x00U)    /* low initial output */
#define _02_TRD_TRDIOB0_INITIAL_OUTPUT_H         (0x02U)    /* high initial output */
/* Selection of TRDIOA0 initial output level (TOA0) */
#define _00_TRD_TRDIOA0_INITIAL_OUTPUT_L         (0x00U)    /* low initial output */
#define _01_TRD_TRDIOA0_INITIAL_OUTPUT_H         (0x01U)    /* high initial output */
/* In PWM function, Extended PWM mode */
/* Selection of TRDIOD1 initial output level (TOD1) */
#define _00_TRD_TRDIOD1_NOT_ACTIVE_LEVEL         (0x00U)    /* initial output is not active level */
#define _80_TRD_TRDIOD1_ACTIVE_LEVEL             (0x80U)    /* initial output is active level */
/* Selection of TRDIOC1 initial output level (TOC1) */
#define _00_TRD_TRDIOC1_NOT_ACTIVE_LEVEL         (0x00U)    /* initial output is not active level */
#define _40_TRD_TRDIOC1_ACTIVE_LEVEL             (0x40U)    /* initial output is active level */
/* Selection of TRDIOB1 initial output level (TOB1) */
#define _00_TRD_TRDIOB1_NOT_ACTIVE_LEVEL         (0x00U)    /* initial output is not active level */
#define _20_TRD_TRDIOB1_ACTIVE_LEVEL             (0x20U)    /* initial output is active level */
/* Selection of TRDIOD0 initial output level (TOD0) */
#define _00_TRD_TRDIOD0_NOT_ACTIVE_LEVEL         (0x00U)    /* initial output is not active level */
#define _08_TRD_TRDIOD0_ACTIVE_LEVEL             (0x08U)    /* initial output is active level */
/* Selection of TRDIOC0 initial output level (TOC0) */
#define _00_TRD_TRDIOC0_NOT_ACTIVE_LEVEL         (0x00U)    /* initial output is not active level */
#define _04_TRD_TRDIOC0_ACTIVE_LEVEL             (0x04U)    /* initial output is active level */
/* Selection of TRDIOB0 initial output level (TOB0) */
#define _00_TRD_TRDIOB0_NOT_ACTIVE_LEVEL         (0x00U)    /* initial output is not active level */
#define _02_TRD_TRDIOB0_ACTIVE_LEVEL             (0x02U)    /* initial output is active level */
/* In PWM3 Mode */
/* Selection of TRDIOB0 initial output level (TOB0) */
#define _00_TRD_TRDIOB0_INITIAL_OUTPUT_LH        (0x00U)    /* low initial output, high active level */
#define _02_TRD_TRDIOB0_INITIAL_OUTPUT_HL        (0x02U)    /* high initial output, low active level */
/* Selection of TRDIOA0 initial output level (TOA0) */
#define _00_TRD_TRDIOA0_INITIAL_OUTPUT_LH        (0x00U)    /* low initial output, high active level */
#define _01_TRD_TRDIOA0_INITIAL_OUTPUT_HL        (0x01U)    /* high initial output, low active level */

/*
    Timer RD Digital Filter Function Select Register i (TRDDFi) (i = 0 or 1)
*/
/* In Input Capture Function */
/* Selection of clock for digital filter function (DFCK1, DFCK0) */
#define _00_TRD_DIGITAL_FILTER_CLOCK_FTRD32      (0x00U)    /* fTRD/32 */
#define _40_TRD_DIGITAL_FILTER_CLOCK_FTRD8       (0x40U)    /* fTRD/8 */
#define _80_TRD_DIGITAL_FILTER_CLOCK_FTRD1       (0x80U)    /* fTRD */
#define _C0_TRD_DIGITAL_FILTER_CLOCK_SOURCE      (0xC0U)    /* count source */
/* Selection of TRDIODi pin digital filter function (DFD) */
#define _00_TRD_TRDIOD_DIGITAL_FILTER_DISABLE    (0x00U)    /* function is not used */
#define _08_TRD_TRDIOD_DIGITAL_FILTER_ENABLE     (0x08U)    /* function is used */
/* Selection of TRDIOCi pin digital filter function (DFC) */
#define _00_TRD_TRDIOC_DIGITAL_FILTER_DISABLE    (0x00U)    /* function is not used */
#define _04_TRD_TRDIOC_DIGITAL_FILTER_ENABLE     (0x04U)    /* function is used */
/* Selection of TRDIOBi pin digital filter function (DFB) */
#define _00_TRD_TRDIOB_DIGITAL_FILTER_DISABLE    (0x00U)    /* function is not used */
#define _02_TRD_TRDIOB_DIGITAL_FILTER_ENABLE     (0x02U)    /* function is used */
/* Selection of TRDIOAi pin digital filter function (DFA) */
#define _00_TRD_TRDIOA_DIGITAL_FILTER_DISABLE    (0x00U)    /* function is not used */
#define _01_TRD_TRDIOA_DIGITAL_FILTER_ENABLE     (0x01U)    /* function is used */
/* In other mode */
/* Control of TRDIOAi pin pulse forced cutoff (DFCK1, DFCK0) */
#define _00_TRD_TRDIOA_FORCEDCUTOFF_DISABLE      (0x00U)    /* forced cutoff disabled */
#define _40_TRD_TRDIOA_HIGHIMPEDANCE_OUTPUT      (0x40U)    /* high-impedance output */
#define _80_TRD_TRDIOA_LOW_OUTPUT                (0x80U)    /* low output */
#define _C0_TRD_TRDIOA_HIGH_OUTPUT               (0xC0U)    /* high output */
/* Control of TRDIOBi pin pulse forced cutoff (PENB1, PENB0) */
#define _00_TRD_TRDIOB_FORCEDCUTOFF_DISABLE      (0x00U)    /* forced cutoff disabled */
#define _10_TRD_TRDIOB_HIGHIMPEDANCE_OUTPUT      (0x10U)    /* high-impedance output */
#define _20_TRD_TRDIOB_LOW_OUTPUT                (0x20U)    /* low output */
#define _30_TRD_TRDIOB_HIGH_OUTPUT               (0x30U)    /* high output */
/* Control of TRDIOCi pin pulse forced cutoff (DFD, DFC) */
#define _00_TRD_TRDIOC_FORCEDCUTOFF_DISABLE      (0x00U)    /* forced cutoff disabled */
#define _04_TRD_TRDIOC_HIGHIMPEDANCE_OUTPUT      (0x04U)    /* high-impedance output */
#define _08_TRD_TRDIOC_LOW_OUTPUT                (0x08U)    /* low output */
#define _0C_TRD_TRDIOC_HIGH_OUTPUT               (0x0CU)    /* high output */
/* Control of TRDIODi pin pulse forced cutoff (DFB, DFA) */
#define _00_TRD_TRDIOD_FORCEDCUTOFF_DISABLE      (0x00U)    /* forced cutoff disabled */
#define _01_TRD_TRDIOD_HIGHIMPEDANCE_OUTPUT      (0x01U)    /* high-impedance output */
#define _02_TRD_TRDIOD_LOW_OUTPUT                (0x02U)    /* low output */
#define _03_TRD_TRDIOD_HIGH_OUTPUT               (0x03U)    /* high output */

/*
    Timer RD Control Register i (TRDCRi) (i = 0 or 1)
*/
/* Selection of TRDi counter clear (CCLR2 - CCLR0) */
#define _00_TRD_COUNTER_CLEAR_DISABLE            (0x00U)    /* clear disabled (free-running operation) */
#define _20_TRD_COUNTER_CLEAR_TRDGRA             (0x20U)    /* clear by input capture/compare match with TRDGRAi */
#define _40_TRD_COUNTER_CLEAR_TRDGRB             (0x40U)    /* clear by input capture/compare match with TRDGRBi */
#define _60_TRD_COUNTER_CLEAR_SYNCHRONOUS        (0x60U)    /* synchronous clear */
#define _A0_TRD_COUNTER_CLEAR_TRDGRC             (0xA0U)    /* clear by input capture/compare match with TRDGRCi */
#define _C0_TRD_COUNTER_CLEAR_TRDGRD             (0xC0U)    /* clear by input capture/compare match with TRDGRDi */
/* Selection of external clock edge (CKEG1, CKEG0) */
#define _00_TRD_EXTERNAL_CLOCK_EDGE_RISING       (0x00U)    /* count at the rising edge */
#define _08_TRD_EXTERNAL_CLOCK_EDGE_FALLING      (0x08U)    /* count at the falling edge */
#define _10_TRD_EXTERNAL_CLOCK_EDGE_BOTH         (0x10U)    /* count at both edges */
/* Selection of count source (TCK2 - TCK0) */
#define _00_TRD_INTERNAL_CLOCK_FTRD1             (0x00U)    /* fTRD */
#define _01_TRD_INTERNAL_CLOCK_FTRD2             (0x01U)    /* fTRD/2 */
#define _02_TRD_INTERNAL_CLOCK_FTRD4             (0x02U)    /* fTRD/2^2 */
#define _03_TRD_INTERNAL_CLOCK_FTRD8             (0x03U)    /* fTRD/2^3 */
#define _04_TRD_INTERNAL_CLOCK_FTRD32            (0x04U)    /* fTRD/2^5 */
#define _05_TRD_CLOCK_TRDCLK_INPUT               (0x05U)    /* TRDCLK input */

/*
    Timer RD I/O Control Register Ai (TRDIORAi) (i = 0 or 1)
*/
/* Selection of TRDGRBi mode (IOB2) */
#define _00_TRD_TRDGRB_COMPARE                   (0x00U)    /* output compare function */
#define _40_TRD_TRDGRB_CAPTURE                   (0x40U)    /* input capture function */
/* Control of TRDGRBi (IOB1, IOB0) */
/* In Input Capture Function */
#define _00_TRD_TRDGRB_CAPTURE_EDGE_RISING       (0x00U)    /* input capture to TRDGRBi at the rising edge */
#define _10_TRD_TRDGRB_CAPTURE_EDGE_FALLING      (0x10U)    /* input capture to TRDGRBi at the falling edge */
#define _20_TRD_TRDGRB_CAPTURE_EDGE_BOTH         (0x20U)    /* input capture to TRDGRBi at both edges */
/* In Output Compare Function */
#define _00_TRD_TRDGRB_COMPARE_OUTPUT_DISABLE    (0x00U)    /* pin output by compare match is disabled */
#define _10_TRD_TRDGRB_COMPARE_OUTPUT_LOW        (0x10U)    /* low output by compare match with TRDGRBi */
#define _20_TRD_TRDGRB_COMPARE_OUTPUT_HIGH       (0x20U)    /* high output by compare match with TRDGRBi */
#define _30_TRD_TRDGRB_COMPARE_OUTPUT_TOGGLE     (0x30U)    /* toggle output by compare match with TRDGRBi */
/* Selection of TRDGRAi mode (IOA2) */
#define _00_TRD_TRDGRA_COMPARE                   (0x00U)    /* output compare function */
#define _04_TRD_TRDGRA_CAPTURE                   (0x04U)    /* input capture function */
/* Control of TRDGRAi (IOA1, IOA0) */
/* In Input Capture Function */
#define _00_TRD_TRDGRA_CAPTURE_EDGE_RISING       (0x00U)    /* input capture to TRDGRAi at the rising edge */
#define _01_TRD_TRDGRA_CAPTURE_EDGE_FALLING      (0x01U)    /* input capture to TRDGRAi at the falling edge */
#define _02_TRD_TRDGRA_CAPTURE_EDGE_BOTH         (0x02U)    /* input capture to TRDGRAi at both edges */
/* In Output Compare Function */
#define _00_TRD_TRDGRA_COMPARE_OUTPUT_DISABLE    (0x00U)    /* pin output by compare match is disabled */
#define _01_TRD_TRDGRA_COMPARE_OUTPUT_LOW        (0x01U)    /* low output by compare match with TRDGRAi */
#define _02_TRD_TRDGRA_COMPARE_OUTPUT_HIGH       (0x02U)    /* high output by compare match with TRDGRAi */
#define _03_TRD_TRDGRA_COMPARE_OUTPUT_TOGGLE     (0x03U)    /* toggle output by compare match with TRDGRAi */

/*
    Timer RD I/O Control Register Ci (TRDIORCi) (i = 0 or 1)
*/
/* Selection of TRDGRDi register function (IOD3) */
#define _00_TRD_TRDGRD_OUTPUT_REGISTER           (0x00U)    /* TRDIOBi output register */
#define _80_TRD_TRDGRD_GENERAL_BUFFER_REGISTER   (0x80U)    /* general register or buffer register */
/* Selection of TRDGRDi mode (IOD2) */
#define _00_TRD_TRDGRD_COMPARE                   (0x00U)    /* output compare function */
#define _40_TRD_TRDGRD_CAPTURE                   (0x40U)    /* input capture function */
/* Control of TRDGRDi (IOD1, IOD0) */
/* In Input Capture Function */
#define _00_TRD_TRDGRD_CAPTURE_EDGE_RISING       (0x00U)    /* input capture to TRDGRDi at the rising edge */
#define _10_TRD_TRDGRD_CAPTURE_EDGE_FALLING      (0x10U)    /* input capture to TRDGRDi at the falling edge */
#define _20_TRD_TRDGRD_CAPTURE_EDGE_BOTH         (0x20U)    /* input capture to TRDGRDi at both edges */
/* In Output Compare Function */
#define _00_TRD_TRDGRD_COMPARE_OUTPUT_DISABLE    (0x00U)    /* pin output by compare match is disabled */
#define _10_TRD_TRDGRD_COMPARE_OUTPUT_LOW        (0x10U)    /* low output by compare match with TRDGRDi */
#define _20_TRD_TRDGRD_COMPARE_OUTPUT_HIGH       (0x20U)    /* high output by compare match with TRDGRDi */
#define _30_TRD_TRDGRD_COMPARE_OUTPUT_TOGGLE     (0x30U)    /* toggle output by compare match with TRDGRDi */
/* Selection of TRDGRCi register function (IOC3) */
#define _00_TRD_TRDGRC_OUTPUT_REGISTER           (0x00U)    /* TRDIOAi output register */
#define _08_TRD_TRDGRC_GENERAL_BUFFER_REGISTER   (0x08U)    /* general register or buffer register */
/* Selection of TRDGRCi mode (IOC2) */
#define _00_TRD_TRDGRC_COMPARE                   (0x00U)    /* output compare function */
#define _04_TRD_TRDGRC_CAPTURE                   (0x04U)    /* input capture function */
/* Control of TRDGRCi (IOC1, IOC0) */
/* In Input Capture Function */
#define _00_TRD_TRDGRC_CAPTURE_EDGE_RISING       (0x00U)    /* input capture to TRDGRCi at the rising edge */
#define _01_TRD_TRDGRC_CAPTURE_EDGE_FALLING      (0x01U)    /* input capture to TRDGRCi at the falling edge */
#define _02_TRD_TRDGRC_CAPTURE_EDGE_BOTH         (0x02U)    /* input capture to TRDGRCi at both edges */
/* In Output Compare Function */
#define _00_TRD_TRDGRC_COMPARE_OUTPUT_DISABLE    (0x00U)    /* pin output by compare match is disabled */
#define _01_TRD_TRDGRC_COMPARE_OUTPUT_LOW        (0x01U)    /* low output by compare match with TRDGRCi */
#define _02_TRD_TRDGRC_COMPARE_OUTPUT_HIGH       (0x02U)    /* high output by compare match with TRDGRCi */
#define _03_TRD_TRDGRC_COMPARE_OUTPUT_TOGGLE     (0x03U)    /* toggle output by compare match with TRDGRCi */

/*
    Timer RD Status Register i (TRDSRi) (i = 0 or 1)
*/
#define _E0_TRD_TRDSR0_FLAG_CLEAR                (0xE0U)    /* bit IMFD - IMFA clear */
#define _C0_TRD_TRDSR1_FLAG_CLEAR                (0xC0U)    /* bit IMFD - IMFA clear */
/* Up / down counter status flag (UDS) */
#define _00_TRD_DECREMENT_COUNTING               (0x00U)    /* TRDi is in decrement counting */
#define _40_TRD_INCREMENT_COUNTING               (0x40U)    /* TRDi is in increment counting */
/* Underflow flag (UDF) */
#define _00_TRD_INTUD_FLAG_CLEAR                 (0x00U)    /* interrupt underflow not generate */
#define _20_TRD_INTUD_GENERATE_FLAG              (0x20U)    /* interrupt underflow generate */
/* Overflow flag (OVF) */
#define _00_TRD_INTOV_FLAG_CLEAR                 (0x00U)    /* interrupt overflow not generate */
#define _10_TRD_INTOV_GENERATE_FLAG              (0x10U)    /* interrupt overflow generate */
/* Input capture/compare match flag D (IMFD) */
#define _00_TRD_INTD_FLAG_CLEAR                  (0x00U)    /* interrupt D not generate */
#define _08_TRD_INTD_GENERATE_FLAG               (0x08U)    /* interrupt D generate */
/* Input capture/compare match flag C (IMFC) */
#define _00_TRD_INTC_FLAG_CLEAR                  (0x00U)    /* interrupt C not generate */
#define _04_TRD_INTC_GENERATE_FLAG               (0x04U)    /* interrupt C generate */
/* Input capture/compare match flag B (IMFB) */
#define _00_TRD_INTB_FLAG_CLEAR                  (0x00U)    /* interrupt B not generate */
#define _02_TRD_INTB_GENERATE_FLAG               (0x02U)    /* interrupt B generate */
/* Input capture/compare match flag A (IMFA) */
#define _00_TRD_INTA_FLAG_CLEAR                  (0x00U)    /* interrupt A not generate */
#define _01_TRD_INTA_GENERATE_FLAG               (0x01U)    /* interrupt A generate */

/*
    Timer RD Interrupt Enable Register i (TRDIERi) (i = 0 or 1)
*/
/* Overflow/underflow interrupt enable/disable (OVIE) */
#define _00_TRD_OVIE_DISABLE                     (0x00U)    /* disable interrupt (OVI) by the OVF or UDF bit */
#define _10_TRD_OVIE_ENABLE                      (0x10U)    /* enable interrupt (OVI) by the OVF or UDF bit */
/* Input capture/compare match interrupt enable/disable D (IMIED) */
#define _00_TRD_IMID_DISABLE                     (0x00U)    /* disable interrupt (IMID) by the IMFD bit */
#define _08_TRD_IMID_ENABLE                      (0x08U)    /* enable interrupt (IMID) by the IMFD bit */
/* Input capture/compare match interrupt enable/disable C (IMIEC) */
#define _00_TRD_IMIC_DISABLE                     (0x00U)    /* disable interrupt (IMIC) by the IMFC bit */
#define _04_TRD_IMIC_ENABLE                      (0x04U)    /* enable interrupt (IMIC) by the IMFC bit */
/* Input capture/compare match interrupt enable/disable B (IMIEB) */
#define _00_TRD_IMIB_DISABLE                     (0x00U)    /* disable interrupt (IMIB) by the IMFB bit */
#define _02_TRD_IMIB_ENABLE                      (0x02U)    /* enable interrupt (IMIB) by the IMFB bit */
/* Input capture/compare match interrupt enable/disable A (IMIEA) */
#define _00_TRD_IMIA_DISABLE                     (0x00U)    /* disable interrupt (IMIA) by the IMFA bit */
#define _01_TRD_IMIA_ENABLE                      (0x01U)    /* enable interrupt (IMIA) by the IMFA bit */

/*
    Timer RD PWM Function Output Level Control Register i (TRDPOCRi) (i = 0 or 1)
*/
/* Control of PWM function output level A (POLA) */
#define _00_TRD_TRDIOA_OUTPUT_ACTIVE_L           (0x00U)    /* TRDIOA1 output level is low active */
#define _08_TRD_TRDIOA_OUTPUT_ACTIVE_H           (0x08U)    /* TRDIOA1 output level is high active */
/* Control of PWM function output level D (POLD) */
#define _00_TRD_TRDIOD_OUTPUT_ACTIVE_L           (0x00U)    /* TRDIODi output level is low active */
#define _04_TRD_TRDIOD_OUTPUT_ACTIVE_H           (0x04U)    /* TRDIODi output level is high active */
/* Control of PWM function output level C (POLC) */
#define _00_TRD_TRDIOC_OUTPUT_ACTIVE_L           (0x00U)    /* TRDIOCi output level is low active */
#define _02_TRD_TRDIOC_OUTPUT_ACTIVE_H           (0x02U)    /* TRDIOCi output level is high active */
/* Control of PWM function output level B (POLB) */
#define _00_TRD_TRDIOB_OUTPUT_ACTIVE_L           (0x00U)    /* TRDIOBi output level is low active */
#define _01_TRD_TRDIOB_OUTPUT_ACTIVE_H           (0x01U)    /* TRDIOBi output level is high active */

/*
    Timer RD Reload Trigger Register (TRDRDT0)
*/
/* Rewrite trigger (RDT) */
#define _00_TRD_TRDRDT0_RELOAD_INVALID           (0x00U)    /* rewrite trigger is disable */
#define _01_TRD_TRDRDT0_RELOAD_REGISTER          (0x01U)    /* rewrite trigger is enable */

/*
    Timer RD Reload Trigger Register (TRDRDT1)
*/
/* Rewrite trigger (RDT) */
#define _00_TRD_TRDRDT1_RELOAD_INVALID           (0x00U)    /* rewrite trigger is disable */
#define _01_TRD_TRDRDT1_RELOAD_REGISTER          (0x01U)    /* rewrite trigger is enable */

/*
    Timer RD simultaneous update flag register n (TRDRSFn)
*/
/* Reload trigger status flag */
#define _00_TRD_TRDRSF_RELOAD_ENABLE_STATUS      (0x00U)    /* reload trigger enable status */
#define _01_TRD_TRDRSF_RELOAD_WAITING_STATUS     (0x01U)    /* waiting for reload trigger status */

/*
    Timer RD A/D Trigger Control Register (TRDADCR)
*/
/* Selection of A/D trigger mode 1 (ADMD1) */
#define _00_TRD_AD1_COMPARE_UP                   (0x00U)    /* A/D trigger 1 compares during up counting */
#define _20_TRD_AD1_COMPARE_DOWN                 (0x20U)    /* A/D trigger 1 compares during down counting */
/* Indication of A/D trigger enable/disable 1 (ADE1) */
#define _00_TRD_AD_TRIGGER1_DISABLE              (0x00U)    /* A/D trigger 1 is disabled */
#define _10_TRD_AD_TRIGGER1_ENABLE               (0x10U)    /* A/D trigger 1 is enabled */
/* Selection of A/D trigger mode 0 (ADMD0) */
#define _00_TRD_AD0_COMPARE_UP                   (0x00U)    /* A/D trigger 0 compares during up counting */
#define _02_TRD_AD0_COMPARE_DOWN                 (0x02U)    /* A/D trigger 0 compares during down counting */
/* Indication of A/D trigger enable/disable 0 (ADE0) */
#define _00_TRD_AD_TRIGGER0_DISABLE              (0x00U)    /* A/D trigger 0 is disabled */
#define _01_TRD_AD_TRIGGER0_ENABLE               (0x01U)    /* A/D trigger 0 is enabled */

/*
    Timer RD Skipping Control Register (TRDTCTL)
*/
/* Enabling the output in the first cycle after timer RD2 begins operation (TRDTMD) */
#define _00_TRD_FIRST_CYCLE_DISABLE              (0x00U)    /* Output is disabled */
#define _10_TRD_FIRST_CYCLE_ENABLE               (0x10U)    /* Output is enabled */
/* Enabling the skipping of A/D conversion trigger 1 (ADTEN1) */
#define _00_TRD_SKIPPING_AD1_DISABLE             (0x00U)    /* A/D trigger 1 skipping is disabled */
#define _08_TRD_SKIPPING_AD1_ENABLE              (0x08U)    /* A/D trigger 1 skipping is enabled */
/* Enabling the skipping of A/D conversion trigger 0 (ADTEN0) */
#define _00_TRD_SKIPPING_AD0_DISABLE             (0x00U)    /* A/D trigger 0 skipping is disabled */
#define _04_TRD_SKIPPING_AD0_ENABLE              (0x04U)    /* A/D trigger 0 skipping is enabled */
/* Enabling the skipping of interrupt requests from timer RD21 (INTEN1) */
#define _00_TRD_SKIPPING_INTERRUPT1_DISABLE      (0x00U)    /* RD21 skipping interrupt is disabled */
#define _02_TRD_SKIPPING_INTERRUPT1_ENABLE       (0x02U)    /* RD21 skipping interrupt is enabled */
/* Enabling the skipping of interrupt requests from timer RD20 (INTEN0) */
#define _00_TRD_SKIPPING_INTERRUPT0_DISABLE      (0x00U)    /* RD20 skipping interrupt is disabled */
#define _01_TRD_SKIPPING_INTERRUPT0_ENABLE       (0x01U)    /* RD20 skipping interrupt is enabled */

/*
    Timer RD Output Control Register i (TRDPOE)
*/
/* TRDIOC0 pin output enable/disable (EC0) */
#define _00_TRD_TRDIOC0_OUTPUT_ENABLE            (0x00U)    /* TRDIOC0 output is enabled */
#define _01_TRD_TRDIOC0_OUTPUT_DISABLE           (0x01U)    /* TRDIOC0 output is disabled */

/*
    PWMOPA Control Register 0 (OPCTL0)
*/
/* Output cutoff hazard control selection (HAZAD_SET) */
#define _00_TRD_HAZARD_MEASURE_DISABLE           (0x00U)    /* hazard measure disabled */
#define _40_TRD_HAZARD_MEASURE_ENABLE            (0x40U)    /* hazard measure enabled */
/* Output forced cutoff source edge/output forced cutoff release edge selection (IN_EG) */
#define _00_TRD_CUTOFF_RISING_RELEASE_FALLING    (0x00U)    /* output forced cutoff is rising edge,
                                                            output forced cutoff release is falling edge */
#define _20_TRD_CUTOFF_FALLING_RELEASE_RISING    (0x20U)    /* output forced cutoff is falling edge,
                                                            output forced cutoff release is rising edge */
/* Cutoff source selection (IN_SEL1, IN_SEL0) */
#define _00_TRD_CUTOFF_SOURCE_NONE               (0x00U)    /* no output cutoff source selection */
#define _08_TRD_CUTOFF_SOURCE_COMP0              (0x08U)    /* comparator 0 output */
#define _10_TRD_CUTOFF_SOURCE_INTP0              (0x10U)    /* INTP0 pin input */
#define _18_TRD_CUTOFF_SOURCE_ELC                (0x18U)    /* event input from ELC */
#define _67_TRD_CUTOFF_SOURCE_CLEAR              (0x67U)    /* bit IN_SEL1 - IN_SEL0 clear */
/* When software release is selected: software release timing selection (ACT) */
#define _00_TRD_SW_RELEASE_TIMING_DEFAULT        (0x00U)    /* forced cutoff is released and pulse output is resumed */
#define _04_TRD_SW_RELEASE_TIMING_BY_MODE        (0x04U)    /* forced cutoff is released and pulse output is resumed
                                                            by mode */
/* When software release is selected: output cutoff release control (HZ_REL) */
#define _00_TRD_SW_CUTOFF_CONTINUES              (0x00U)    /* output forced cutoff continues */
#define _02_TRD_SW_CUTOFF_RELEASE                (0x02U)    /* output forced cutoff is released and
                                                            pulse output is resumed */
/* Output forced cutoff release mode selection (HS_SEL) */
#define _00_TRD_RELEASE_MODE_HARDWARE            (0x00U)    /* released via hardware */
#define _01_TRD_RELEASE_MODE_SOFTWARE            (0x01U)    /* released via software */

/*
    PWMOPA Cutoff Control Register 0 (OPDF0)
*/
/* TRDIOD0 pin output forced cutoff control (DFD01, DFD00) */
#define _00_TRD_TRDIOD0_FORCEDCUTOFF_DISABLE     (0x00U)    /* forced cutoff disabled */
#define _40_TRD_TRDIOD0_HIGHIMPEDANCE_OUTPUT     (0x40U)    /* high-impedance output */
#define _80_TRD_TRDIOD0_LOW_OUTPUT               (0x80U)    /* low-level output */
#define _C0_TRD_TRDIOD0_HIGH_OUTPUT              (0xC0U)    /* high-level output */
/* TRDIOC0 pin output forced cutoff control (DFC01, DFC00) */
#define _00_TRD_TRDIOC0_FORCEDCUTOFF_DISABLE     (0x00U)    /* forced cutoff disabled */
#define _10_TRD_TRDIOC0_HIGHIMPEDANCE_OUTPUT     (0x10U)    /* high-impedance output */
#define _20_TRD_TRDIOC0_LOW_OUTPUT               (0x20U)    /* low-level output */
#define _30_TRD_TRDIOC0_HIGH_OUTPUT              (0x30U)    /* high-level output */
/* TRDIOB0 pin output forced cutoff control (DFB01, DFB00) */
#define _00_TRD_TRDIOB0_FORCEDCUTOFF_DISABLE     (0x00U)    /* forced cutoff disabled */
#define _04_TRD_TRDIOB0_HIGHIMPEDANCE_OUTPUT     (0x04U)    /* high-impedance output */
#define _08_TRD_TRDIOB0_LOW_OUTPUT               (0x08U)    /* low-level output */
#define _0C_TRD_TRDIOB0_HIGH_OUTPUT              (0x0CU)    /* high-level output */
/* TRDIOA0 pin output forced cutoff control (DFA01, DFA00) */
#define _00_TRD_TRDIOA0_FORCEDCUTOFF_DISABLE     (0x00U)    /* forced cutoff disabled */
#define _01_TRD_TRDIOA0_HIGHIMPEDANCE_OUTPUT     (0x01U)    /* high-impedance output */
#define _02_TRD_TRDIOA0_LOW_OUTPUT               (0x02U)    /* low-level output */
#define _03_TRD_TRDIOA0_HIGH_OUTPUT              (0x03U)    /* high-level output */

/*
    PWMOPA Cutoff Control Register 1 (OPDF1)
*/
/* TRDIOD1 pin output forced cutoff control (DFD11, DFD10) */
#define _00_TRD_TRDIOD1_FORCEDCUTOFF_DISABLE     (0x00U)    /* forced cutoff disabled */
#define _40_TRD_TRDIOD1_HIGHIMPEDANCE_OUTPUT     (0x40U)    /* high-impedance output */
#define _80_TRD_TRDIOD1_LOW_OUTPUT               (0x80U)    /* low-level output */
#define _C0_TRD_TRDIOD1_HIGH_OUTPUT              (0xC0U)    /* high-level output */
/* TRDIOC1 pin output forced cutoff control (DFC11, DFC10) */
#define _00_TRD_TRDIOC1_FORCEDCUTOFF_DISABLE     (0x00U)    /* forced cutoff disabled */
#define _10_TRD_TRDIOC1_HIGHIMPEDANCE_OUTPUT     (0x10U)    /* high-impedance output */
#define _20_TRD_TRDIOC1_LOW_OUTPUT               (0x20U)    /* low-level output */
#define _30_TRD_TRDIOC1_HIGH_OUTPUT              (0x30U)    /* high-level output */
/* TRDIOB1 pin output forced cutoff control (DFB11, DFB10) */
#define _00_TRD_TRDIOB1_FORCEDCUTOFF_DISABLE     (0x00U)    /* forced cutoff disabled */
#define _04_TRD_TRDIOB1_HIGHIMPEDANCE_OUTPUT     (0x04U)    /* high-impedance output */
#define _08_TRD_TRDIOB1_LOW_OUTPUT               (0x08U)    /* low-level output */
#define _0C_TRD_TRDIOB1_HIGH_OUTPUT              (0x0CU)    /* high-level output */
/* TRDIOA1 pin output forced cutoff control (DFA11, DFA10) */
#define _00_TRD_TRDIOA1_FORCEDCUTOFF_DISABLE     (0x00U)    /* forced cutoff disabled */
#define _01_TRD_TRDIOA1_HIGHIMPEDANCE_OUTPUT     (0x01U)    /* high-impedance output */
#define _02_TRD_TRDIOA1_LOW_OUTPUT               (0x02U)    /* low-level output */
#define _03_TRD_TRDIOA1_HIGH_OUTPUT              (0x03U)    /* high-level output */

/*
    PWMOPA Edge Selection Register (OPEDGE)
*/
/* Output forced cutoff release edge selection (EG1, EG0) */
#define _00_TRD_TRDIOC0_RELEASE_EDGE_RISING      (0x00U)    /* cutoff released at the rising edge of TRDIOC0 */
#define _01_TRD_TRDIOC0_RELEASE_EDGE_FALLING     (0x01U)    /* cutoff released at the falling edge of TRDIOC0 */
#define _02_TRD_TRDIOC0_RELEASE_EDGE_BOTH        (0x02U)    /* cutoff released at both edges of TRDIOC0 */
#define _03_TRD_TRDIOC0_RELEASE_EDGE_DISABLE     (0x03U)    /* input edge of TRDIOC0 disabled, cutoff retained */

/*
    PWMOPA Status Register (OPSR)
*/
/* Blocked state (HZOF1) */
#define _00_TRD_TRD1_OUTPUT_NORMAL               (0x00U)    /* nomal timer output */
#define _04_TRD_TRD1_OUTPUT_BLOCK                (0x04U)    /* block timer output */
/* Blocked state (HZOF0) */
#define _00_TRD_TRD0_OUTPUT_NORMAL               (0x00U)    /* nomal timer output */
#define _02_TRD_TRD0_OUTPUT_BLOCK                (0x02U)    /* block timer output */
/* Status of output cutoff factor (HZIF0) */
#define _00_TRD_NOT_EXCEED_THRESHOLD             (0x00U)    /* output cutoff factor does not exceed the threshold */
#define _01_TRD_EXCEED_THRESHOLD                 (0x01U)    /* output cutoff factor does exceed the threshold */

/*
    Timer clock select register 2 (TPS2)
*/
/* Selection of operating clock (CK21) (TPS212 - TPS210) */
#define _00_TRD_KB3_CK1_SELECT_FKB               (0x00U)    /* fCLK, fPLL, fHOCO */
#define _10_TRD_KB3_CK1_SELECT_FKB2              (0x10U)    /* fCLK/2, fPLL/2 */
#define _20_TRD_KB3_CK1_SELECT_FKB4              (0x20U)    /* fCLK/2^2, fPLL/2^2 */
#define _30_TRD_KB3_CK1_SELECT_FKB8              (0x30U)    /* fCLK/2^3, fPLL/2^3 */
#define _40_TRD_KB3_CK1_SELECT_FKB16             (0x40U)    /* fCLK/2^4, fPLL/2^4 */
#define _50_TRD_KB3_CK1_SELECT_FKB32             (0x50U)    /* fCLK/2^5, fPLL/2^5 */
#define _07_TRD_KB3_COUNT_SOURCE_CLEAR           (0x07U)    /* clear macro */
/* Selection of operating clock (CK20) (TPS202 - TPS200) */
#define _00_TRD_KB3_CK0_SELECT_FKB               (0x00U)    /* fCLK, fPLL, fHOCO */
#define _01_TRD_KB3_CK0_SELECT_FKB2              (0x01U)    /* fCLK/2, fPLL/2 */
#define _02_TRD_KB3_CK0_SELECT_FKB4              (0x02U)    /* fCLK/2^2, fPLL/2^2 */
#define _03_TRD_KB3_CK0_SELECT_FKB8              (0x03U)    /* fCLK/2^3, fPLL/2^3 */
#define _04_TRD_KB3_CK0_SELECT_FKB16             (0x04U)    /* fCLK/2^4, fPLL/2^4 */
#define _05_TRD_KB3_CK0_SELECT_FKB32             (0x05U)    /* fCLK/2^5, fPLL/2^5 */
#define _70_TRD_KB3_COUNT_SOURCE_CLEAR           (0x70U)    /* clear macro */

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

