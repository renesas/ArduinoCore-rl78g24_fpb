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
* Copyright (C) 2021, 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_trg.h
* Version          : 1.0.12
* Device(s)        : R7F101GLGxFB
* Description      : General header file for TRG peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef TRG_H
#define TRG_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 2 (PER2)
*/
/* Control of timer RG input clock supply (TRGEN) */
#define _00_TRG_CLOCK_STOP                       (0x00U)    /* stop input clock supply */
#define _10_TRG_CLOCK_SUPPLY                     (0x10U)    /* enable input clock supply */

/*
    Peripheral Reset Control Register 0 (PRR2)
*/
/* Peripheral reset control of timer RG (TRGRES) */
#define _00_TRG_RESET_RELEASE                    (0x00U)    /* released from the reset state */
#define _10_TRG_RESET_SET                        (0x10U)    /* reset */

/*
    Timer RG Mode Register 0 (TRGMR0)
*/
/* TRG count start (TRGSTART) */
#define _00_TRG_STOP_COUNT                       (0x00U)    /* stop counting, initialize PWM output signal */
#define _80_TRG_START_COUNT                      (0x80U)    /* start counting */
/* ELC input capture request selection (TRGELCICE) */
#define _00_TRG_INPUT_SIGNAL_B                   (0x00U)    /* select external input signal B/digital filter signal B */
#define _40_TRG_EVENT_INPUT_ELC                  (0x40U)    /* select event input (input capture) from ELC */
/* Clock selection used in the digital filter function (TRGDFCK1,TRGDFCK0) */
#define _00_TRG_FILTER_CLOCK_FCLK_32             (0x00U)    /* fCLK/32 */
#define _10_TRG_FILTER_CLOCK_FCLK_8              (0x10U)    /* fCLK/8 */
#define _20_TRG_FILTER_CLOCK_FCLK                (0x20U)    /* fCLK */
#define _30_TRG_FILTER_CLOCK_TRGTCK              (0x30U)    /* clock selected by TRGTCK [2:0] bits of TRGCR register */
/* Digital filter function selection of TRGIOB terminal (TRGDFB) */
#define _00_TRG_TRGIOB_NO_DIGITAL_FILTER         (0x00U)    /* no digital filter function */
#define _08_TRG_TRGIOB_WITH_DIGITAL_FILTER       (0x08U)    /* with digital filter function */
/* Digital filter function selection of TRGIOA terminal (TRGDFA) */
#define _00_TRG_TRGIOA_NO_DIGITAL_FILTER         (0x00U)    /* no digital filter function */
#define _04_TRG_TRGIOA_WITH_DIGITAL_FILTER       (0x04U)    /* with digital filter function */
/* Phase counting mode selection (TRGMDF) */
#define _00_TRG_COUNT_TRGTCK_VALUE               (0x00U)    /* count the count source set by the TRGTCK [2:0] */
#define _02_TRG_COUNT_TRGCLK_PHASE               (0x02U)    /* count the phase of the input signal TRGCLKj (j=A,B) */
/* PWM mode selection (TRGPWM) */
#define _00_TRG_TIMER_MODE                       (0x00U)    /* timer mode */
#define _01_TRG_PWM_MODE                         (0x01U)    /* PWM mode */

/*
    Timer RG Mode Register 1 (TRGMR1)
*/
/* TRGIOB terminal pulse output forced cutoff control (TRGPENB) */
#define _00_TRG_TRGIOB_CUTOFF_DISABLE            (0x00U)    /* forced cutoff is disabled */
#define _80_TRG_TRGIOB_CUTOFF_HIZ_OUTPUT         (0x80U)    /* Hi-Z output */
/* TRGIOA terminal pulse output forced cutoff control (TRGPENA) */
#define _00_TRG_TRGIOA_CUTOFF_DISABLE            (0x00U)    /* forced cutoff is disabled */
#define _40_TRG_TRGIOA_CUTOFF_HIZ_OUTPUT         (0x40U)    /* Hi-Z output */
/* TRGTRG input edge selection (TRGTCEG1,TRGTCEG0) */
#define _00_TRG_TRGTRG_INPUT_PROHIBITED          (0x00U)    /* TRGTRG input prohibited */
#define _04_TRG_TRGTRG_INPUT_RISING              (0x04U)    /* rising edge */
#define _08_TRG_TRGTRG_INPUT_FALLING             (0x08U)    /* falling edge */
#define _0C_TRG_TRGTRG_INPUT_BOTH                (0x0CU)    /* rising / falling edges */
/* TRGTRG digital filter function selection (TRGDFCLR) */
#define _00_TRG_TRGTRG_NO_DIGITAL_FILTER         (0x00U)    /* no digital filter function */
#define _02_TRG_TRGTRG_WITH_DIGITAL_FILTER       (0x02U)    /* with digital filter function */
/* PWM2 mode selection (TRGPWM2) */
#define _00_TRG_TIMER_OR_PWM_MODE                (0x00U)    /* timer mode or PWM mode */
#define _01_TRG_PWM2_MODE                        (0x01U)    /* PWM2 mode */

/*
    Timer RG Count Control Register (TRGCNTC)
*/
/* Count permission 7 (CNTEN7) */
#define _00_TRG_COUNT_7_DISABLE                  (0x00U)    /* disabled */
#define _80_TRG_COUNT_7_ENABLE                   (0x80U)    /* up count */
/* Count permission 6 (CNTEN6) */
#define _00_TRG_COUNT_6_DISABLE                  (0x00U)    /* disabled */
#define _40_TRG_COUNT_6_ENABLE                   (0x40U)    /* up count */
/* Count permission 5 (CNTEN5) */
#define _00_TRG_COUNT_5_DISABLE                  (0x00U)    /* disabled */
#define _20_TRG_COUNT_5_ENABLE                   (0x20U)    /* up count */
/* Count permission 4 (CNTEN4) */
#define _00_TRG_COUNT_4_DISABLE                  (0x00U)    /* disabled */
#define _10_TRG_COUNT_4_ENABLE                   (0x10U)    /* up count */
/* Count permission 3 (CNTEN3) */
#define _00_TRG_COUNT_3_DISABLE                  (0x00U)    /* disabled */
#define _08_TRG_COUNT_3_ENABLE                   (0x08U)    /* up count */
/* Count permission 2 (CNTEN2) */
#define _00_TRG_COUNT_2_DISABLE                  (0x00U)    /* disabled */
#define _04_TRG_COUNT_2_ENABLE                   (0x04U)    /* up count */
/* Count permission 1 (CNTEN1) */
#define _00_TRG_COUNT_1_DISABLE                  (0x00U)    /* disabled */
#define _02_TRG_COUNT_1_ENABLE                   (0x02U)    /* up count */
/* Count permission 0 (CNTEN0) */
#define _00_TRG_COUNT_0_DISABLE                  (0x00U)    /* disabled */
#define _01_TRG_COUNT_0_ENABLE                   (0x01U)    /* up count */

/*
    Timer RG Control Register (TRGCR)
*/
/* TRG counter clear factor selection (TRGCCLR1,TRGCCLR0) */
#define _00_TRG_COUNTER_CLEAR_PROHIBITED         (0x00U)    /* clear prohibited */
#define _20_TRG_COUNTER_CLEAR_TRGGRA             (0x20U)    /* clear with TRGGRA input capture / compare match */
#define _40_TRG_COUNTER_CLEAR_TRGGRB             (0x40U)    /* clear with TRGGRB input capture / compare match */
/* External clock valid edge selection (TRGCKEG1,TRGCKEG0) */
#define _00_TRG_COUNT_AT_RISING_EDGE             (0x00U)    /* count at the rising edge */
#define _08_TRG_COUNT_AT_FALLING_EDGE            (0x08U)    /* count at the falling edge */
#define _10_TRG_COUNT_AT_BOTH_EDGE               (0x10U)    /* count at both rising and falling edges */
/* Count source selection (TRGTCK2,TRGTCK1,TRGTCK0) */
#define _00_TRG_COUNT_SOURCE_FCLK                (0x00U)    /* count source fCLK */
#define _01_TRG_COUNT_SOURCE_FCLK_2              (0x01U)    /* count source fCLK/2 */
#define _02_TRG_COUNT_SOURCE_FCLK_4              (0x02U)    /* count source fCLK/4 */
#define _03_TRG_COUNT_SOURCE_FCLK_8              (0x03U)    /* count source fCLK/8 */
#define _04_TRG_COUNT_SOURCE_FCLK_32             (0x04U)    /* count source fCLK/32 */
#define _05_TRG_COUNT_SOURCE_TRGCLKA             (0x05U)    /* count source TRGCLKA */
#define _07_TRG_COUNT_SOURCE_TRGCLKB             (0x07U)    /* count source TRGCLKB */

/*
    Timer RG Start Register (TRGSTR)
*/
/* TRG count operation selection (TRGCSEL) */
#define _00_TRG_COUNT_STOP_ON_MATCH              (0x00U)    /* counting stops after matching */
#define _02_TRG_COUNT_CONTINUE_ON_MATCH          (0x02U)    /* counting continues after matching */
/* TRG count start flag (TRGTSTART) */
#define _00_TRG_FLAG_COUNT_STOP                  (0x00U)    /* stop counting */
#define _01_TRG_FLAG_COUNT_CONTINUE              (0x01U)    /* start counting */

/*
    Timer RG Interrupt Enable Register 0 (TRGIER0)
*/
/* Compare match interrupt enabled D (TRGIMIED) */
#define _00_TRG_COMPARE_MATCH_D_INT_DISABLE      (0x00U)    /* disable interrupts with the TRGIMFD flag */
#define _80_TRG_COMPARE_MATCH_D_INT_ENABLE       (0x80U)    /* enable interrupts with the TRGIMFD flag */
/* Compare match interrupt enabled C (TRGIMIEC) */
#define _00_TRG_COMPARE_MATCH_C_INT_DISABLE      (0x00U)    /* disable interrupts with the TRGIMFC flag */
#define _40_TRG_COMPARE_MATCH_C_INT_ENABLE       (0x40U)    /* enable interrupts with the TRGIMFC flag */
/* Overflow interrupt enabled (TRGOVIE) */
#define _00_TRG_OVERFLOW_INT_DISABLE             (0x00U)    /* disable interrupts with the TRGOVF flag */
#define _08_TRG_OVERFLOW_INT_ENABLE              (0x08U)    /* enable interrupts with the TRGOVF flag  */
/* Underflow interrupt enabled (TRGUDIE) */
#define _00_TRG_UNDERFLOW_INT_DISABLE            (0x00U)    /* disable interrupts with the TRGUDF flag */
#define _04_TRG_UNDERFLOW_INT_ENABLE             (0x04U)    /* enable interrupts with the TRGUDF flag */
/* Input capture / compare match interrupt enable B (TRGIMIEB) */
#define _00_TRG_CAPTURE_COMPARE_B_INT_DISABLE    (0x00U)    /* disable interrupts with the TRGIMFB flag */
#define _02_TRG_CAPTURE_COMPARE_B_INT_ENABLE     (0x02U)    /* enable interrupts with the TRGIMFB flag */
/* Input capture / compare match interrupt enable A (TRGIMIEA) */
#define _00_TRG_CAPTURE_COMPARE_A_INT_DISABLE    (0x00U)    /* disable interrupts with the TRGIMFA flag */
#define _01_TRG_CAPTURE_COMPARE_A_INT_ENABLE     (0x01U)    /* enable interrupts with the TRGIMFA flag */

/*
    Timer RG Interrupt Enable Register 1 (TRGIER1)
*/
/* Counter clear interrupt enabled by phase period compare match (TRGPCIE) */
#define _00_TRG_CLEAR_INT_PHASE_DISABLE          (0x00U)    /* disable interrupts with the TRGPCLF flag */
#define _02_TRG_CLEAR_INT_PHASE_ENABLE           (0x02U)    /* enable interrupts with the TRGPCLF flag */
/* Counter clear interrupt enabled by Z phase detection (TRGZCIE) */
#define _00_TRG_CLEAR_INT_Z_PHASE_DISABLE        (0x00U)    /* disable interrupts with the TRGZCLF flag */
#define _01_TRG_CLEAR_INT_Z_PHASE_ENABLE         (0x01U)    /* enable interrupts with the TRGZCLF flag */

/*
    Timer RG Status Register 0 (TRGSR0)
*/
/* Compare match flag D (TRGIMFD) */
#define _00_TRG_FLAG_COMPARE_D_CLEAR             (0x00U)    /* compare D match flag clear */
#define _80_TRG_FLAG_COMPARE_D_SET               (0x80U)    /* compare D match flag set */
/* Compare match flag C (TRGIMFC) */
#define _00_TRG_FLAG_COMPARE_C_CLEAR             (0x00U)    /* compare C match flag clear */
#define _40_TRG_FLAG_COMPARE_C_SET               (0x40U)    /* compare C match flag set */
/* Count direction flag (TRGDIRF) */
#define _00_TRG_FLAG_COUNT_DOWN                  (0x00U)    /* TRG counter counts down flag */
#define _10_TRG_FLAG_COUNT_UP                    (0x10U)    /* TRG counter counts up flag */
/* Overflow flag (TRGOVF) */
#define _00_TRG_FLAG_OVERFLOW_CLEAR              (0x00U)    /* overflow flag clear */
#define _08_TRG_FLAG_OVERFLOW_SET                (0x08U)    /* overflow flag set  */
/* Underflow flag (TRGUDF) */
#define _00_TRG_FLAG_UNDERFLOW_CLEAR             (0x00U)    /* underflow flag clear */
#define _04_TRG_FLAG_UNDERFLOW_SET               (0x04U)    /* underflow flag set */
/* Input capture / compare match flag B (TRGIMFB) */
#define _00_TRG_FLAG_CAPTURE_COMPARE_B_CLEAR     (0x00U)    /* capture / compare match flag clear */
#define _02_TRG_FLAG_CAPTURE_COMPARE_B_SET       (0x02U)    /* capture / compare match flag set */
/* Input capture / compare match flag A (TRGIMFA) */
#define _00_TRG_FLAG_CAPTURE_COMPARE_A_CLEAR     (0x00U)    /* capture / compare match flag clear */
#define _01_TRG_FLAG_CAPTURE_COMPARE_A_SET       (0x01U)    /* capture / compare match flag set */

/*
    Timer RG Status Register 1 (TRGSR1)
*/
/* Counter clear flag by phase period compare match (TRGPCLF) */
#define _00_TRG_FLAG_CLEAR_INT_PHASE_CLEAR       (0x00U)    /* counter clear by phase period match flag clear */
#define _02_TRG_FLAG_CLEAR_INT_PHASE_SET         (0x02U)    /* counter clear by phase period match flag set */
/* Counter clear flag by Z phase detection (TRGPCLF) */
#define _00_TRG_FLAG_CLEAR_INT_Z_PHASE_CLEAR     (0x00U)    /* counter clear by Z phase period match flag clear */
#define _01_TRG_FLAG_CLEAR_INT_Z_PHASE_SET       (0x01U)    /* counter clear by Z phase period match flag set */

/*
    Timer RG I/O Control Register (TRGIOR)
*/
/* TRGGRD register function selection (TRGBUFB) */
#define _00_TRG_TRGGRD_GENERAL                   (0x00U)    /* not used as a buffer register for the TRGGRB register */
#define _80_TRG_TRGGRD_BUFFER                    (0x80U)    /* used as a buffer register for the TRGGRB register */
/* TRGGRB mode selection (TRGIOB2) */
#define _00_TRG_TRGGRB_OUTPUT_COMPARE            (0x00U)    /* output compare function */
#define _40_TRG_TRGGRB_INPUT_CAPTURE             (0x40U)    /* input capture function */
/* TRGGRB control (TRGIOB1, TRGIOB0) */
#define _00_TRG_TRGIOB_OUTPUT_PROHIBITED         (0x00U)    /* output prohibited due to compare match */
#define _10_TRG_TRGIOB_OUTPUT_LOW                (0x10U)    /* low level output */
#define _20_TRG_TRGIOB_OUTPUT_HIGH               (0x20U)    /* high level output */
#define _30_TRG_TRGIOB_OUTPUT_TOGGLE             (0x30U)    /* toggle output  */
#define _00_TRG_TRGIOB_RISING_EDGE               (0x00U)    /* rising edge */
#define _10_TRG_TRGIOB_FALLING_EDGE              (0x10U)    /* falling edge */
#define _20_TRG_TRGIOB_BOTH_EDGES                (0x20U)    /* both edges */
/* TRGGRC register function selection (TRGBUFA) */
#define _00_TRG_TRGGRC_GENERAL                   (0x00U)    /* not used as a buffer register for the TRGGRA register */
#define _08_TRG_TRGGRC_BUFFER                    (0x08U)    /* used as a buffer register for the TRGGRA register */
/* TRGGRA mode selection (TRGIOA2) */
#define _00_TRG_TRGGRA_OUTPUT_COMPARE            (0x00U)    /* output compare function */
#define _04_TRG_TRGGRA_INPUT_CAPTURE             (0x04U)    /* input capture function */
/* TRGGRA control (TRGIOA1, TRGIOA0) */
#define _00_TRG_TRGIOA_OUTPUT_PROHIBITED         (0x00U)    /* output prohibited due to compare match */
#define _01_TRG_TRGIOA_OUTPUT_LOW                (0x01U)    /* low level output */
#define _02_TRG_TRGIOA_OUTPUT_HIGH               (0x02U)    /* high level output */
#define _03_TRG_TRGIOA_OUTPUT_TOGGLE             (0x03U)    /* toggle output  */
#define _00_TRG_TRGIOA_RISING_EDGE               (0x00U)    /* rising edge */
#define _01_TRG_TRGIOA_FALLING_EDGE              (0x01U)    /* falling edge */
#define _02_TRG_TRGIOA_BOTH_EDGES                (0x02U)    /* both edges */

/*
    Timer RG Output Permission Register (TRGOER)
*/
/* Timer output forced cutoff input INTP0 signal valid (TRGPTO) */
#define _00_TRG_INTP0_OUTPUT_CUTOFF_DISABLE      (0x00U)    /* output forced cutoff input disabled */
#define _80_TRG_INTP0_OUTPUT_CUTOFF_ENABLE       (0x80U)    /* output forced cutoff input enabled */
/* Forced shutoff state (TRGSHUTS) */
#define _00_TRG_NO_FORCED_CUTOFF                 (0x00U)    /* no forced cutoff */
#define _01_TRG_FORCED_CUTOFF                    (0x01U)    /* forced cutoff */

/*
    Timer RG Output Control Register (TRGOCR)
*/
/* Timer output level selection B (TRGTOB) */
#define _00_TRG_TRGTOB_INITIAL_LOW               (0x00U)    /* initial low level */
#define _02_TRG_TRGTOB_INITIAL_HIGH              (0x02U)    /* initial high level */
/* Timer output level selection A (TRGTOA) */
#define _00_TRG_TRGTOA_INITIAL_LOW               (0x00U)    /* initial low level */
#define _01_TRG_TRGTOA_INITIAL_HIGH              (0x01U)    /* initial high level */

/*
    Timer RG Phase Counting Mode Control Register 0 (TRGCTL0)
*/
/* Phase counting mode TRG counter clear method selection (TRGSCE) */
#define _00_TRG_COUNT_CLEAR_ON_EFFECTIVE_EDGE    (0x00U)    /* clear counter on the effective edge of the TRGIDZ */
#define _80_TRG_COUNT_CLEAR_ON_CONDITION_LEVEL   (0x80U)    /* clear counter on the clear condition level */
/* TRGIDZ (Z phase) clear condition setting (TRGZCL) */
#define _00_TRG_TRGIDZ_CLEAR_ON_LOW              (0x00U)    /* set the clear condition to low level */
#define _40_TRG_TRGIDZ_CLEAR_ON_HIGH             (0x40U)    /* set the clear condition to high level */
/* TRGCLKB (B phase) clear condition setting (TRGBCL) */
#define _00_TRG_TRGCLKB_CLEAR_ON_LOW             (0x00U)    /* set the clear condition to low level */
#define _20_TRG_TRGCLKB_CLEAR_ON_HIGH            (0x20U)    /* set the clear condition to high level */
/* TRGCLKA (A phase) clear condition setting (TRGACL) */
#define _00_TRG_TRGCLKA_CLEAR_ON_LOW             (0x00U)    /* set the clear condition to low level */
#define _10_TRG_TRGCLKA_CLEAR_ON_HIGH            (0x10U)    /* set the clear condition to high level */
/* TRGIDZ input edge selection (TRGIDZ1, TRGIDZ0) */
#define _00_TRG_TRGIDZ_INPUT_PROHIBITED          (0x00U)    /* trigger input prohibited */
#define _01_TRG_TRGIDZ_INPUT_RISING_EDGE         (0x01U)    /* select rising edge */
#define _02_TRG_TRGIDZ_INPUT_FALLING_EDGE        (0x02U)    /* select falling edge */
#define _03_TRG_TRGIDZ_INPUT_BOTH_EDGES          (0x03U)    /* select both edges */

/*
    Timer RG Phase Counting Mode Control Register 1 (TRGCTL1)
*/
/* TRGPMC count operation permission (TRGPMCE) */
#define _00_TRG_TRGPMC_COUNT_STOP                (0x00U)    /* TRGPMC count operation stopped */
#define _80_TRG_TRGPMC_COUNT_PERMISSION          (0x80U)    /* TRGPMC count operation permission */
/* TRGGRC register value counter load control during underflow (TRGLDE) */
#define _00_TRG_TRGGRC_RELOAD_PROHIBITED         (0x00U)    /* reloading is prohibited */
#define _08_TRG_TRGGRC_RELOAD_ALLOWED            (0x08U)    /* reloading is allowed */
/* TRGGRD match TRG counter clear selection (TRGECM1) */
#define _00_TRG_NOT_CLEAR_ON_TRGGRD_MATCH        (0x00U)    /* do not clear the counter to 0000H */
#define _02_TRG_CLEAR_ON_TRGGRD_MATCH            (0x02U)    /* clear the counter to 0000H */
/* TRGGRC match TRG counter clear selection (TRGECM0) */
#define _00_TRG_NOT_CLEAR_ON_TRGGRC_MATCH        (0x00U)    /* do not clear the counter to 0000H */
#define _01_TRG_CLEAR_ON_TRGGRC_MATCH            (0x01U)    /* clear the counter to 0000H */

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
