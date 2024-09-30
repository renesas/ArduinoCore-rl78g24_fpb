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
* File Name        : r_cg_tkb.h
* Version          : 1.0.20
* Device(s)        : R7F101GLGxFB
* Description      : General header file for 16-bit Timers KB3 peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef KB3_H
#define KB3_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 2 (PER2)
*/
/* Control of supply of an input clock to the 16-bit timer KB3n (TKBEN) */
#define _00_KB3_CLOCK_STOP                               (0x00U)    /* stops input clock supply */
#define _20_KB3_CLOCK_SUPPLY                             (0x20U)    /* enables input clock supply */

/*
    Peripheral Reset Control Register 0 (PRR2)
*/
/* Control resetting of the 16-bit timer KB3n (TKBRES) */
#define _00_KB3_RESET_RELEASE                            (0x00U)    /* released from the reset state */
#define _20_KB3_RESET_SET                                (0x20U)    /* the 16-bit timer KB3n is in the reset state */

/*
    Timer Clock Select Register 2 (TPS2)
*/
/* Selection of operating clock (CK21) (TPS212 - TPS210) */
#define _00_KB3_CK1_SELECT_FKBKC                         (0x00U)    /* fCLK, fPLL, fHOCO */
#define _10_KB3_CK1_SELECT_FKBKC2                        (0x10U)    /* fCLK/2, fPLL/2 */
#define _20_KB3_CK1_SELECT_FKBKC4                        (0x20U)    /* fCLK/2^2, fPLL/2^2 */
#define _30_KB3_CK1_SELECT_FKBKC8                        (0x30U)    /* fCLK/2^3, fPLL/2^3 */
#define _40_KB3_CK1_SELECT_FKBKC16                       (0x40U)    /* fCLK/2^4, fPLL/2^4 */
#define _50_KB3_CK1_SELECT_FKBKC32                       (0x50U)    /* fCLK/2^5, fPLL/2^5 */
#define _07_KB3_CK1_COUNT_SOURCE_CLEAR                   (0x07U)    /* clear macro */
/* Selection of operating clock (CK20) (TPS202 - TPS200) */
#define _00_KB3_CK0_SELECT_FKBKC                         (0x00U)    /* fCLK, fPLL, fHOCO */
#define _01_KB3_CK0_SELECT_FKBKC2                        (0x01U)    /* fCLK/2, fPLL/2 */
#define _02_KB3_CK0_SELECT_FKBKC4                        (0x02U)    /* fCLK/2^2, fPLL/2^2 */
#define _03_KB3_CK0_SELECT_FKBKC8                        (0x03U)    /* fCLK/2^3, fPLL/2^3 */
#define _04_KB3_CK0_SELECT_FKBKC16                       (0x04U)    /* fCLK/2^4, fPLL/2^4 */
#define _05_KB3_CK0_SELECT_FKBKC32                       (0x05U)    /* fCLK/2^5, fPLL/2^5 */
#define _70_KB3_CK0_COUNT_SOURCE_CLEAR                   (0x70U)    /* clear macro */

/*
    16-bit Timer KB Operation Control Registers 00 to 20 (TKBCTL00 to TKBCTL20)
*/
/* Control of TKBOn1 of PWM output gate function by timer RD2 output (TKBGTEn1) */
#define _0000_KB3_TKBO1_PWM_OUTPUT_GATE_DISABLE          (0x0000U)    /* not use PWM output gate function */
#define _4000_KB3_TKBO1_PWM_OUTPUT_GATE_ENABLE           (0x4000U)    /* use PWM output gate function */
/* Control of TKBOn1 PWM output smooth start function (TKBSSEn1) */
#define _0000_KB3_TKBO1_PWM_OUTPUT_SMOOTH_DISABLE        (0x0000U)    /* not use PWM output smooth start function */
#define _2000_KB3_TKBO1_PWM_OUTPUT_SMOOTH_ENABLE         (0x2000U)    /* use PWM output smooth start function */
/* Control of TKBOn1 PWM output dithering function (TKBDIEn1) */
#define _0000_KB3_TKBO1_PWM_OUTPUT_DITHERING_DISABLE     (0x0000U)    /* not use PWM output dithering function */
#define _1000_KB3_TKBO1_PWM_OUTPUT_DITHERING_ENABLE      (0x1000U)    /* use PWM output dithering function */
/* Control of TKBOn0 of PWM output gating function by timer RD2 output (TKBGTEn0) */
#define _0000_KB3_TKBO0_PWM_OUTPUT_GATE_DISABLE          (0x0000U)    /* not use PWM output gating function */
#define _0400_KB3_TKBO0_PWM_OUTPUT_GATE_ENABLE           (0x0400U)    /* use PWM output gating function */
/* Control of TKBOn0 PWM output smooth start function (TKBSSEn0) */
#define _0000_KB3_TKBO0_PWM_OUTPUT_SMOOTH_DISABLE        (0x0000U)    /* not use PWM output smooth start function */
#define _0200_KB3_TKBO0_PWM_OUTPUT_SMOOTH_ENABLE         (0x0200U)    /* use PWM output smooth start function */
/* Control of TKBOn0 PWM output dithering function (TKBDIEn0) */
#define _0000_KB3_TKBO0_PWM_OUTPUT_DITHERING_DISABLE     (0x0000U)    /* not use PWM output dithering function */
#define _0100_KB3_TKBO0_PWM_OUTPUT_DITHERING_ENABLE      (0x0100U)    /* use PWM output dithering function */
/* Control of TKBOn0 and TKBOn1 maximum frequency limit function (TKBMFEn) */
#define _0000_KB3_MAXIMUM_FREQUENCY_DISABLE              (0x0000U)    /* not use the maximum frequency limit function
                                                                         */
#define _0080_KB3_MAXIMUM_FREQUENCY_ENABLE               (0x0080U)    /* use the maximum frequency limit function */
/* Range of INTP21 input that immediately outputs TKBOn1 in interleaved PFC output mode (TKBIRSn1, TKBIRSn0) */
#define _0000_KB3_INTP21_INPUT_RANGE_T64                 (0x0000U)    /* T/2 to T/2 + T/64 */
#define _0010_KB3_INTP21_INPUT_RANGE_T32                 (0x0010U)    /* T/2 to T/2 + T/32 */
#define _0020_KB3_INTP21_INPUT_RANGE_T16                 (0x0020U)    /* T/2 to T/2 + T/16 */
#define _0030_KB3_INTP21_INPUT_RANGE_T8                  (0x0030U)    /* T/2 to T/2 + T/8 */
/* Control of compare register batch overwrite function set by external trigger (TKBTSEn) */
#define _0000_KB3_BATCH_OVERWRITE_DISABLE                (0x0000U)    /* not use compare register batch overwrite
                                                                         function set by external trigger */
#define _0004_KB3_BATCH_OVERWRITE_ENABLE                 (0x0004U)    /* use compare register batch overwrite function
                                                                         set by external trigger */
/* Selection of the restart trigger for the 16-bit timer KB3n (TKBSTSn1, TKBSTSn0) */
#define _0000_KB3_TRIGGER_INPUT_DISABLE                  (0x0000U)    /* not use trigger input */
#define _0001_KB3_TRIGGER_INPUT_INTP20                   (0x0001U)    /* external interrupt signal (INTP20) */
#define _0002_KB3_TRIGGER_INPUT_INTP21                   (0x0002U)    /* external interrupt signal (INTP21) */
#define _0003_KB3_TRIGGER_INPUT_INTP0                    (0x0003U)    /* external interrupt signal (INTP0) */

/*
    16-bit Timer KB Operation Control Registers 01 to 21 (TKBCTL01 to TKBCTL21)
*/
/* Operation control of the 16-bit timer KB3n (TKBCEn) */
#define _00_KB3_TIMER_OPTERATION_STOP                    (0x00U)    /* stops timer operation */
#define _1B_KB3_STOP_TIMER_OPTERATION                    (0x1BU)    /* stops timer operation */
#define _80_KB3_TIMER_OPTERATION_ENABLE                  (0x80U)    /* enables timer count operation */
/* Clock selection for 16-bit timer KB3m (TKBCKSm) */
#define _00_KB3_CLOCK_SELECTED_CK20                      (0x00U)    /* CK20 clock selected by TPS20[2:0] bits */
#define _10_KB3_CLOCK_SELECTED_CK21                      (0x10U)    /* CK20 clock selected by TPS21[2:0] bits */
/* Start operation control of 16-bit timer KB30 (TKBSCMn) */
#define _00_KB3_START_OPER_TKBCKS                        (0x00U)    /* operates using clock selected by TKBCKSn bit */
#define _08_KB3_START_OPER_SIMULTANESOUS                 (0x08U)    /* the count start timing per se is to start when
                                                                       the CK20 and CK21 clock are matched. After the
                                                                       operation is started, the clock selected by the
                                                                       TKBCKSn bit is used for operation */
/* operation mode selection of the 16-bit timer KB3n(TKBMDn1, TKBMDn0) */
#define _00_KB3_STANDALONE_MODE                          (0x00U)    /* standalone mode */
#define _01_KB3_SIMULTANESOUS_STARTSTOP_MODE             (0x01U)    /* simultaneous start/stop mode */
#define _02_KB3_SYNCHRONOUS_STARTCLEAR_MODE              (0x02U)    /* synchronous start/clear mode */
#define _03_KB3_INTERLEAVE_PFC_MODE                      (0x03U)    /* interleave PFC output mode */
#define _1B_KB3_STOP_TIMER_OPTERATION                    (0x1BU)    /* stops timer operation */

/*
    16-bit Timer KB Operation Control Registers 02 to 22 (TKBCTL02 to TKBCTL22)
*/
/* Control of a mask for the external trigger when the maximum frequency limit function is used (TKBKCMSKn) */
#define _0000_KB3_EXT_TRIGGER_NOT_AS_ADDITIONAL_SOURCE   (0x0000U)    /* while either TKBOn0 or TKBOn1 is active, the
                                                                         external trigger selected by setting the
                                                                         TKBKCIn0 to TKBKCIn2 bits is not selected
                                                                         as an additional source for the masking */
#define _1000_KB3_EXT_TRIGGER_AS_ADDITIONAL_SOURCE       (0x1000U)    /* while either TKBOn0 or TKBOn1 is active, the
                                                                         external trigger selected by setting the
                                                                         TKBKCIn0 to TKBKCIn2 bits is selected as an
                                                                         additional source for the masking */
/* Control of the source when the maximum frequency limit function is used (TKBMFMn1) */
#define _0000_KB3_TKBO1_NOT_AS_SOURCE                    (0x0000U)    /* active TKBOn0 is not used as a source for
                                                                         masking */
#define _0200_KB3_TKBO1_AS_SOURCE                        (0x0200U)    /* active TKBOn0 is used as a source for
                                                                         masking */
/* Control of the source when the maximum frequency limit function is used (TKBMFMn0) */
#define _0000_KB3_TKBO0_NOT_AS_SOURCE                    (0x0000U)    /* active TKBOn0 is not used as a source for
                                                                         masking */
#define _0100_KB3_TKBO0_AS_SOURCE                        (0x0100U)    /* active TKBOn0 is used as a source for
                                                                         masking */
/* selection of the restart trigger for the 16-bit timer KB3n (TKBINSn2 to TKBINSn0) */
#define _0000_KB3_RESTART_NOT_USE_TRIGGER_INPUT          (0x0000U)    /* does not use trigger input */
#define _0020_KB3_RESTART_COMPARATOR0_OUTPUT_SIGNAL      (0x0020U)    /* output signal of comparator 0 */
#define _0030_KB3_RESTART_COMPARATOR1_OUTPUT_SIGNAL      (0x0030U)    /* output signal of comparator 1 */
#define _0040_KB3_RESTART_COMPARATOR2_OUTPUT_SIGNAL      (0x0040U)    /* output signal of comparator 2 */
#define _0050_KB3_RESTART_COMPARATOR3_OUTPUT_SIGNAL      (0x0050U)    /* output signal of comparator 3 */
/* selection of the restart trigger for the 16-bit timer KB30 (TKBKCI02 to TKBKCI00) */
#define _0001_KB3_RESTART_USE_COMPARE_MATCH1             (0x0001U)    /* Compare match 1 signal in timer-KB PWM
                                                                         output gating mode */
#define _0002_KB3_RESTART_USE_TRDIOB1_RISING_EDGE        (0x0002U)    /* TRDIOB1 rising edge */
#define _0003_KB3_RESTART_USE_TRDIOB1_FALLING_EDGE       (0x0003U)    /* TRDIOB1 falling edge */
#define _0004_KB3_RESTART_USE_TRDIOC1_RISING_EDGE        (0x0004U)    /* TRDIOC1 rising edge */
#define _0005_KB3_RESTART_USE_TRDIOC1_FALLING_EDGE       (0x0005U)    /* TRDIOC1 falling edge */
/* selection of the restart trigger for the 16-bit timer KB31 (TKBKCI12 to TKBKCI10) */
#define _0002_KB3_RESTART_USE_TRDIOD1_RISING_EDGE        (0x0002U)    /* TRDIOD1 rising edge */
#define _0003_KB3_RESTART_USE_TRDIOD1_FALLING_EDGE       (0x0003U)    /* TRDIOD1 falling edge */
#define _0004_KB3_RESTART_USE_TRDIOA1_RISING_EDGE        (0x0004U)    /* TRDIOA1 rising edge */
#define _0005_KB3_RESTART_USE_TRDIOA1_FALLING_EDGE       (0x0005U)    /* TRDIOA1 falling edge */
/* selection of the restart trigger for the 16-bit timer KB32 (TKBKCI22 to TKBKCI20) */
#define _0001_KB3_RESTART_USE_COMPARE_MATCH0             (0x0001U)    /* Compare match 0 signal in timer-KB PWM
                                                                         output gating mode */
#define _0002_KB3_RESTART_USE_TRDIOB0_RISING_EDGE        (0x0002U)    /* TRDIOB0 rising edge */
#define _0003_KB3_RESTART_USE_TRDIOB0_FALLING_EDGE       (0x0003U)    /* TRDIOB0 falling edge */
#define _0004_KB3_RESTART_USE_TRDIOD0_RISING_EDGE        (0x0004U)    /* TRDIOD0 rising edge */
#define _0005_KB3_RESTART_USE_TRDIOD0_FALLING_EDGE       (0x0005U)    /* TRDIOD0 falling edge */

/*
    16-bit Timer KB Output Control Registers 00 to 20 (TKBIOC00 to TKBIOC20)
*/
/* Active level setting of timer output TKBOn1 (TKBTOLn1) */
#define _00_KB3_TKBO1_OUTPUT_ACTIVE_HIGH                 (0x00U)    /* high level */
#define _08_KB3_TKBO1_OUTPUT_ACTIVE_LOW                  (0x08U)    /* low level */
/* Active level setting of timer output TKBOn0 (TKBTOLn0) */
#define _00_KB3_TKBO0_OUTPUT_ACTIVE_HIGH                 (0x00U)    /* high level */
#define _04_KB3_TKBO0_OUTPUT_ACTIVE_LOW                  (0x04U)    /* low level */
/* Default level setting of timer output TKBOn1 (TKBTODn1) */
#define _00_KB3_TKBO1_OUTPUT_DEFAULT_LOW                 (0x00U)    /* low level */
#define _02_KB3_TKBO1_OUTPUT_DEFAULT_HIGH                (0x02U)    /* high level */
/* Default level setting of timer output TKBOn0 (TKBTODn0) */
#define _00_KB3_TKBO0_OUTPUT_DEFAULT_LOW                 (0x00U)    /* low level */
#define _01_KB3_TKBO0_OUTPUT_DEFAULT_HIGH                (0x01U)    /* high level */

/*
    16-bit Timer KB Output Control Registers 01 to 21 (TKBIOC01 to TKBIOC21)
*/
/* timer output TKBOn1 output enable/disable (TKBTOEn1) */
#define _00_KB3_TKBO1_TIMER_OUTPUT_DISABLE               (0x00U)    /* disables timer output */
#define _02_KB3_TKBO1_TIMER_OUTPUT_ENABLE                (0x02U)    /* enables timer output */
/* timer output TKBOn0 output enable/disable (TKBTOEn0) */
#define _00_KB3_TKBO0_TIMER_OUTPUT_DISABLE               (0x00U)    /* disables timer output */
#define _01_KB3_TKBO0_TIMER_OUTPUT_ENABLE                (0x01U)    /* enables timer output */

/*
    16-bit Timer KB Flag Registers 0 to 2 (TKBFLG0 to TKBFLG2)
*/
/* Status flag for PWM output smooth start function of TKBOn1 pin (TKBSSFn1) */
#define _00_KB3_TKBOn1_SMOOTH_STOP                       (0x00U)    /* during stop in PWM output smooth start function
                                                                       */
#define _80_KB3_TKBOn1_SMOOTH_EXECUTE                    (0x80U)    /* executing in PWM output smooth start function */
/* Status flag for PWM output smooth start function of TKBOn0 pins (TKBSSFn0) */
#define _00_KB3_TKBOn0_SMOOTH_STOP                       (0x00U)    /* during stop in PWM output smooth start function
                                                                       */
#define _40_KB3_TKBOn0_SMOOTH_EXECUTE                    (0x40U)    /* executing in PWM output smooth start function */
/* Error flag for PWM output smooth start function of TKBOn1 pin (TKBSEFn1) */
#define _00_KB3_TKBOn1_SMOOTH_NOERR                      (0x00U)    /* no error or completion of clearing by TKBCLSE */
#define _20_KB3_TKBOn1_SMOOTH_ERR                        (0x20U)    /* error */
/* Error flag for PWM output smooth start function of TKBOn0 pin (TKBSEFn0) */
#define _00_KB3_TKBOn0_SMOOTH_NOERR                      (0x00U)    /* no error or completion of clearing by TKBCLSE */
#define _10_KB3_TKBOn0_SMOOTH_ERR                        (0x10U)    /* error */
/* Undetected restart trigger source 1 trigger error flag for interleave PFC mode (TKBIRFn) */
#define _00_KB3_PFC_RESTART_SRC1_NOERR                   (0x00U)    /* no error or completion of clearing by TKBCLIR */
#define _08_KB3_PFC_RESTART_SRC1_ERR                     (0x08U)    /* error */
/* Restart trigger source 1 trigger multiplex detection error flag for interleave PFC mode (TKBIEFn) */
#define _00_KB3_PFC_MULTIRESTART_SRC1_NOERR              (0x00U)    /* no error or completion of clearing by TKBCLIE */
#define _04_KB3_PFC_MULTIRESTART_SRC1_ERR                (0x04U)    /* error */
/* Status flag for maximum frequency limit function (TKBMFFn) */
#define _00_KB3_MAXFRQ_NOT_OCCURRE                       (0x00U)    /* maximum frequency limit function is not
                                                                       occurred, or completion of clearing by the
                                                                       TKBCLRn.TKBCLMFn bit */
#define _02_KB3_MAXFRQ_OCCURRE                           (0x02U)    /* maximum frequency limit function is occurred */
/* Batch overwrite trigger pending status flag (TKBRSFn) */
#define _00_KB3_BATCH_OVERWRITE_EN_STS                   (0x00U)    /* batch overwrite enabled status or completion of
                                                                       batch overwrite caused by to batch overwrite
                                                                       trigger */
#define _01_KB3_BATCH_OVERWRITE_HOLD_STS                 (0x01U)    /* on hold (waiting for completion) status */

/*
    16-bit Timer KB Trigger Registers 0 to 2 (TKBTRG0 to TKBTRG2)
*/
/* trigger for batch overwrite request of compare register (TKBRDTn) */
#define _01_KB3_BATCH_OVERWRITE_REQUEST                  (0x01U)    /* batch overwrite request of compare register */

/*
    16-bit Timer KB Flag Clear Trigger Registers 0 to 2 (TKBCLR0 to TKBCLR2)
*/
/* trigger for clearing error flag for PWM output smooth start function of TKBOn1 pin (TKBCLSEn1) */
#define _20_KB3_SMOOTH_CLEAR_TKBSEF1_FLAG                (0x20U)    /* clear the TKBSEFn1 flag to “0” */
/* trigger for clearing error flag for PWM output smooth start function of TKBOn0 pin (TKBCLSEn0) */
#define _10_KB3_SMOOTH_CLEAR_TKBSEF0_FLAG                (0x10U)    /* clear the TKBSEFn0 flag to “0” */
/* trigger for clearing undetected INTP21 trigger error flag for interleave PFC mode (TKBCLIRn) */
#define _08_KB3_TRIGGER_CLEAR_TKBIRF_FLAG                (0x08U)    /* clear the TKBIRFn flag to “0” */
/* trigger for clearing undetected INTP21 trigger error flag for interleave PFC mode (TKBCLIEn) */
#define _04_KB3_TRIGGER_CLEAR_TKBIEF_FLAG                (0x04U)    /* clear the TKBIRFn flag to “0” */
/* trigger for clearing undetected INTP21 trigger error flag for interleave PFC mode (TKBCLMFn) */
#define _02_KB3_TRIGGER_CLEAR_TKBMFF_FLAG                (0x02U)    /* clear the TKBIRFn flag to “0” */

/*
    16-bit Timer KB LEB Control Registers 02 to 22, 03 to 23 (TKBLEB02 to TKBLEB22, TKBLEB03 to TKBLEB23)
*/
/* Enabling or disabling leading edge blanking (TKBLEBEnp) */
#define _00_KB3_LEB_FUNCTION_DISABLE                     (0x00U)    /* the LEB function is disabled */
#define _01_KB3_LEB_FUNCTION_ENABLE                      (0x01U)    /* the LEB function is enabled */
/*
    16-bit Timer KB Skipping Control Registers 0 to 2 (TKBTCTL0 to TKBTCTL2)
*/
/* Enabling the skipping of interrupt requests from timer RD21 (TKBTKBGENn) */
#define _00_KB3_INTERLOCK_WITH_TIMER_RD_DISABLE          (0x00U)    /* interlocking is disabled */
#define _80_KB3_INTERLOCK_WITH_TIMER_RD_ENABLE           (0x80U)    /* interlocking is enabled */
/* Enabling or disabling skipping of the output in the first cycle after the KB3n starts to operate (TKBTMDn) */
#define _00_KB3_FIRST_CYCLE_DISABLE                      (0x00U)    /* output is disabled */
#define _10_KB3_FIRST_CYCLE_ENABLE                       (0x10U)    /* output is enabled */
/* Enabling or disabling skipping of the A/D trigger signal from the 16-bit timer KB3n (TKBTADTENn) */
#define _00_KB3_SKIPPING_AD_DISABLE                      (0x00U)    /* skipping is disabled */
#define _04_KB3_SKIPPING_AD_ENABLE                       (0x04U)    /* skipping is enabled */
/* Enabling or disabling skipping of the count end interrupt signal from the 16-bit timer KB3n (TKBTINTENn) */
#define _00_KB3_SKIPPING_INTERRUPT_DISABLE               (0x00U)    /* skipping is disabled */
#define _01_KB3_SKIPPING_INTERRUPT_ENABLE                (0x01U)    /* skipping is enabled */

/*
    16-bit Timer KB Dithering Count Registers 00 to 20, 01 to 21 (TKBDNR00 to TKBDNR20, TKBDNR01 to TKBDNR21)
*/
/* 16-bit timer KB dithering count (TKBDNRnp) */
#define _00_KB3_OUTPUT_DITHERING_COUNT_0                 (0x00U)    /* PWM output dithering count */
#define _10_KB3_OUTPUT_DITHERING_COUNT_1                 (0x10U)    /* PWM output dithering count */
#define _20_KB3_OUTPUT_DITHERING_COUNT_2                 (0x20U)    /* PWM output dithering count */
#define _30_KB3_OUTPUT_DITHERING_COUNT_3                 (0x30U)    /* PWM output dithering count */
#define _40_KB3_OUTPUT_DITHERING_COUNT_4                 (0x40U)    /* PWM output dithering count */
#define _50_KB3_OUTPUT_DITHERING_COUNT_5                 (0x50U)    /* PWM output dithering count */
#define _60_KB3_OUTPUT_DITHERING_COUNT_6                 (0x60U)    /* PWM output dithering count */
#define _70_KB3_OUTPUT_DITHERING_COUNT_7                 (0x70U)    /* PWM output dithering count */
#define _80_KB3_OUTPUT_DITHERING_COUNT_8                 (0x80U)    /* PWM output dithering count */
#define _90_KB3_OUTPUT_DITHERING_COUNT_9                 (0x90U)    /* PWM output dithering count */
#define _A0_KB3_OUTPUT_DITHERING_COUNT_A                 (0xA0U)    /* PWM output dithering count */
#define _B0_KB3_OUTPUT_DITHERING_COUNT_B                 (0xB0U)    /* PWM output dithering count */
#define _C0_KB3_OUTPUT_DITHERING_COUNT_C                 (0xC0U)    /* PWM output dithering count */
#define _D0_KB3_OUTPUT_DITHERING_COUNT_D                 (0xD0U)    /* PWM output dithering count */
#define _E0_KB3_OUTPUT_DITHERING_COUNT_E                 (0xE0U)    /* PWM output dithering count */
#define _F0_KB3_OUTPUT_DITHERING_COUNT_F                 (0xF0U)    /* PWM output dithering count */

/*
    16-bit Timer KB Smooth Start Step Width Registers 00 to 20, 01 to 21 (TKBSSR00 to TKBSSR20, TKBSSR01 to TKBSSR21)
*/
/* 16-bit timer KB smooth start step width (TKBSSRnp) */
#define _00_KB3_SMOOTH_START_STEP_WIDTH_1                (0x00U)    /* PWM output smooth start step width */
#define _01_KB3_SMOOTH_START_STEP_WIDTH_2                (0x01U)    /* PWM output smooth start step width */
#define _02_KB3_SMOOTH_START_STEP_WIDTH_3                (0x02U)    /* PWM output smooth start step width */
#define _03_KB3_SMOOTH_START_STEP_WIDTH_4                (0x03U)    /* PWM output smooth start step width */
#define _04_KB3_SMOOTH_START_STEP_WIDTH_5                (0x04U)    /* PWM output smooth start step width */
#define _05_KB3_SMOOTH_START_STEP_WIDTH_6                (0x05U)    /* PWM output smooth start step width */
#define _06_KB3_SMOOTH_START_STEP_WIDTH_7                (0x06U)    /* PWM output smooth start step width */
#define _07_KB3_SMOOTH_START_STEP_WIDTH_8                (0x07U)    /* PWM output smooth start step width */
#define _08_KB3_SMOOTH_START_STEP_WIDTH_9                (0x08U)    /* PWM output smooth start step width */
#define _09_KB3_SMOOTH_START_STEP_WIDTH_10               (0x09U)    /* PWM output smooth start step width */
#define _0A_KB3_SMOOTH_START_STEP_WIDTH_11               (0x0AU)    /* PWM output smooth start step width */
#define _0B_KB3_SMOOTH_START_STEP_WIDTH_12               (0x0BU)    /* PWM output smooth start step width */
#define _0C_KB3_SMOOTH_START_STEP_WIDTH_13               (0x0CU)    /* PWM output smooth start step width */
#define _0D_KB3_SMOOTH_START_STEP_WIDTH_14               (0x0DU)    /* PWM output smooth start step width */
#define _0E_KB3_SMOOTH_START_STEP_WIDTH_15               (0x0EU)    /* PWM output smooth start step width */
#define _0F_KB3_SMOOTH_START_STEP_WIDTH_16               (0x0FU)    /* PWM output smooth start step width */

/*
    Forced Output Stop Function Control Registers 00 to 31 (TKBPACTL00 to TKBPACTL31)
*/
/* External interruption trigger selection for forced output stop function 2 (TKBPAFXS0p4) */
#define _0000_KB3_FUNCTION2_INTP0_DISABLE                (0x0000U)    /* INTP0 can not be used as a trigger */
#define _8000_KB3_FUNCTION2_INTP0_ENABLE                 (0x8000U)    /* INTP0 can not be used as a trigger */
/* External interruption trigger selection for forced output stop function 2 (TKBPAFXS0p3) */
#define _0000_KB3_FUNCTION2_INTP21_DISABLE               (0x0000U)    /* INTP21 can not be used as a trigger */
#define _4000_KB3_FUNCTION2_INTP21_ENABLE                (0x4000U)    /* INTP21 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 2 (TKBPAFXS0p2) */
#define _0000_KB3_FUNCTION2_COMP2_DISABLE                (0x0000U)    /* comparator 2 can not be used as a trigger */
#define _2000_KB3_FUNCTION2_COMP2_ENABLE                 (0x2000U)    /* comparator 2 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 2 (TKBPAFXS0p1) */
#define _0000_KB3_FUNCTION2_COMP1_DISABLE                (0x0000U)    /* comparator 1 can not be used as a trigger */
#define _1000_KB3_FUNCTION2_COMP1_ENABLE                 (0x1000U)    /* comparator 1 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 2 (TKBPAFXS0p0) */
#define _0000_KB3_FUNCTION2_COMP0_DISABLE                (0x0000U)    /* comparator 0 can not be used as a trigger */
#define _0800_KB3_FUNCTION2_COMP0_ENABLE                 (0x0800U)    /* comparator 0 can be used as a trigger */
/* Operation mode selection for forced output stop function 2 (TKBPAFCM0p) */
#define _0000_KB3_FORCED_FUNCTION2_TYPE1                 (0x0000U)    /* forced output stop function 2 starts with
                                                                         trigger input, and forced output stop function
                                                                         2 is cleared at the next counter period */
#define _0100_KB3_FORCED_FUNCTION2_TYPE2                 (0x0100U)    /* forced output stop function 2 starts with
                                                                         trigger input, and forced output stop function
                                                                         2 is cleared at the next counter period
                                                                         following detection of the reverse edge of the
                                                                         trigger */
/* External interruption trigger selection for forced output stop function 1 (TKBPAHZS0p4) */
#define _0000_KB3_FUNCTION1_INTP0_DISABLE                (0x0000U)    /* INTP0 can not be used as a trigger */
#define _0400_KB3_FUNCTION1_INTP0_ENABLE                 (0x0400U)    /* INTP0 can not be used as a trigger */
/* External interruption trigger selection for forced output stop function 1 (TKBPAHZS0p3) */
#define _0000_KB3_FUNCTION1_INTP21_DISABLE               (0x0000U)    /* INTP21 can not be used as a trigger */
#define _0200_KB3_FUNCTION1_INTP21_ENABLE                (0x0200U)    /* INTP21 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 1 (TKBPAHZS0p2) */
#define _0000_KB3_FUNCTION1_COMP2_DISABLE                (0x0000U)    /* comparator 2 can not be used as a trigger */
#define _0040_KB3_FUNCTION1_COMP2_ENABLE                 (0x0040U)    /* comparator 2 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 1 (TKBPAHZS0p1) */
#define _0000_KB3_FUNCTION1_COMP1_DISABLE                (0x0000U)    /* comparator 1 can not be used as a trigger */
#define _0020_KB3_FUNCTION1_COMP1_ENABLE                 (0x0020U)    /* comparator 1 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 1 (TKBPAHZS0p0) */
#define _0000_KB3_FUNCTION1_COMP0_DISABLE                (0x0000U)    /* comparator 0 can not be used as a trigger */
#define _0010_KB3_FUNCTION1_COMP0_ENABLE                 (0x0010U)    /* comparator 0 can be used as a trigger */
/* Clear condition selection for forced output stop function 1 (TKBPAHCM0p1,TKBPAHCM0p0) */
#define _0000_KB3_FORCED_FUNCTION1_TYPE1                 (0x0000U)    /* forced output stop function 1 starts with
                                                                         trigger input, and forced output stop function
                                                                         1 is cleared when forced output stop function
                                                                         release trigger(TKBPAHTT0p) = 1 is written,
                                                                         regardless of the trigger signal level */
#define _0004_KB3_FORCED_FUNCTION1_TYPE2                 (0x0004U)    /* forced output stop function 1 starts with
                                                                         trigger input, and when the trigger signal is
                                                                         in its high-level period, writing “forced
                                                                         output stop function release trigger
                                                                         (TKBPAHTT0p) = 1” is invalid. Forced output
                                                                         stop function 1 is cleared when forced output
                                                                         stop function release trigger (TKBPAHTT0p) = 1
                                                                         is written while the trigger signal is in its
                                                                         low-level period */
#define _0008_KB3_FORCED_FUNCTION1_TYPE3                 (0x0008U)    /* forced output stop function 1 starts with
                                                                         trigger input, and forced output stop function
                                                                         1 is cleared at the next counter period after
                                                                         forced output stop function release trigger
                                                                         (TKBPAHTT0p) = 1 is written, regardless of
                                                                         the trigger signal level */
#define _000C_KB3_FORCED_FUNCTION1_TYPE4                 (0x000CU)    /* forced output stop function 1 starts with
                                                                         trigger input, and when the trigger signal is
                                                                         in its high-level period, writing “forced
                                                                         output stop function release trigger
                                                                         (TKBPAHTT0p) = 1” is invalid. Forced output
                                                                         stop function 1 is cleared at the next counter
                                                                         period after forced output stop function
                                                                         release trigger (TKBPAHTT0p) = 1 is written
                                                                         when the trigger signal is in its low-level
                                                                         period */
/* Output status selection when executing forced output stop function (TKBPAMD0p1,TKBPAMD0p0) */
#define _0000_KB3_FORCED_HIZ_LOW                         (0x0000U)    /* Hi-Z Output / fixed at low level */
#define _0001_KB3_FORCED_HIZ_HIGH                        (0x0001U)    /* Hi-Z Output / fixed at high level */
#define _0002_KB3_FORCED_LOW_LOW                         (0x0002U)    /* function 1/2 : output fixed at low level */
#define _0003_KB3_FORCED_HIGH_HIGH                       (0x0003U)    /* function 1/2 : output fixed at high level */
/* External interruption trigger selection for forced output stop function 2 (TKBPAFXS1p3) */
#define _0000_KB3_FUNCTION2_INTP20_DISABLE               (0x0000U)    /* INTP20 can not be used as a trigger */
#define _4000_KB3_FUNCTION2_INTP20_ENABLE                (0x4000U)    /* INTP20 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 2 (TKBPAFXS1p2) */
#define _0000_KB3_FUNCTION2_COMP3_DISABLE                (0x0000U)    /* comparator 3 can not be used as a trigger */
#define _2000_KB3_FUNCTION2_COMP3_ENABLE                 (0x2000U)    /* comparator 3 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 2 (TKBPAFXS1p1) */
#define _1000_KB3_FUNCTION2_COMP2_ENABLE                 (0x1000U)    /* comparator 2 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 2 (TKBPAFXS1p0) */
#define _0800_KB3_FUNCTION2_COMP1_ENABLE                 (0x0800U)    /* comparator 1 can be used as a trigger */
/* External interruption trigger selection for forced output stop function 1 (TKBPAHZS1p3) */
#define _0000_KB3_FUNCTION1_INTP20_DISABLE               (0x0000U)    /* INTP20 can not be used as a trigger */
#define _0200_KB3_FUNCTION1_INTP20_ENABLE                (0x0200U)    /* INTP20 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 1 (TKBPAHZS1p2) */
#define _0000_KB3_FUNCTION1_COMP3_DISABLE                (0x0000U)    /* comparator 2 can not be used as a trigger */
#define _0040_KB3_FUNCTION1_COMP3_ENABLE                 (0x0040U)    /* comparator 2 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 1 (TKBPAHZS1p1) */
#define _0020_KB3_FUNCTION1_COMP2_ENABLE                 (0x0020U)    /* comparator 1 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 1 (TKBPAHZS1p0) */
#define _0010_KB3_FUNCTION1_COMP1_ENABLE                 (0x0010U)    /* comparator 0 can be used as a trigger */

/*
    Forced Output Stop Function Control Registers 02 to 22 (TKBPACTL02 to TKBPACTL22)
*/
/* Input control of trigger signal used for forced output stop function of the TKBOn1 pin (TKBPACEn1) */
#define _00_KB3_TKBO1_FORCED_STOP_FUNCTION_DISABLE       (0x00U)    /* disable operation of forced output stop */
#define _02_KB3_TKBO1_FORCED_STOP_FUNCTION_ENABLE        (0x02U)    /* enable operation of forced output stop */
/* Input control of trigger signal used for forced output stop function of the TKBOn0 pin (TKBPACEn0) */
#define _00_KB3_TKBO0_FORCED_STOP_FUNCTION_DISABLE       (0x00U)    /* disable operation of forced output stop */
#define _01_KB3_TKBO0_FORCED_STOP_FUNCTION_ENABLE        (0x01U)    /* enable operation of forced output stop */

/*
    Forced Output Stop Function Control Registers 03 to 23 (TKBPACTL03 to TKBPACTL23)
*/
/* Control of the mask for forced stopping of the output when leading edge blanking is in use (TKBPALEBENn1) */
#define _00_KB3_TKBO1_FORCED_STOP_MASKED_DISABLE         (0x00U)    /* the forced output stop function is not masked */
#define _80_KB3_TKBO1_FORCED_STOP_MASKED_ENABLE          (0x80U)    /* the forced output stop function is masked */
/* Control of the interrupt when forced stopping of the output from the TKBOn1 pin is terminated (TKBPASTPIn1) */
#define _00_KB3_TKBO1_TERMIN_FORCED_STOP_NO_INTERRUPT    (0x00U)    /* an interrupt is not generated when forced
                                                                       stopping of the output is terminated */
#define _40_KB3_TKBO1_TERMIN_FORCED_STOP_AN_INTERRUPT    (0x40U)    /* an interrupt is generated when forced stopping
                                                                       of the output is terminated */
/* Control of the interrupt when forced stopping of the output from the TKBOn1 pin is activated (TKBPASTAIn1) */
#define _00_KB3_TKBO1_ACTIVE_FORCED_STOP_NO_INTERRUPT    (0x00U)    /* an interrupt is not generated when forced
                                                                       stopping of the output is activated */
#define _20_KB3_TKBO1_ACTIVE_FORCED_STOP_AN_INTERRUPT    (0x20U)    /* an interrupt is generated when forced stopping
                                                                       of the output is activated */
/* Control of the fixed off function for forced output stop function 2 for the TKBOn1 pin (TKBPAFIXn1) */
#define _00_KB3_TKBO1_FIXED_OFF_FUNCTION_DISABLE         (0x00U)    /* the fixed off function is not used */
#define _10_KB3_TKBO1_FIXED_OFF_FUNCTION_ENABLE          (0x10U)    /* the fixed off function is used */
/* Control of the mask for forced stopping of the output when leading edge blanking is in use (TKBPALEBENn0) */
#define _00_KB3_TKBO0_FORCED_STOP_MASKED_DISABLE         (0x00U)    /* the forced output stop function is not masked */
#define _08_KB3_TKBO0_FORCED_STOP_MASKED_ENABLE          (0x08U)    /* the forced output stop function is masked */
/* Control of the interrupt when forced stopping of the output from the TKBOn0 pin is terminated (TKBPASTPIn0) */
#define _00_KB3_TKBO0_TERMIN_FORCED_STOP_NO_INTERRUPT    (0x00U)    /* an interrupt is not generated when forced
                                                                       stopping of the output is terminated */
#define _04_KB3_TKBO0_TERMIN_FORCED_STOP_AN_INTERRUPT    (0x04U)    /* an interrupt is generated when forced stopping
                                                                       of the output is terminated */
/* Control of the interrupt when forced stopping of the output from the TKBOn0 pin is activated (TKBPASTAIn0) */
#define _00_KB3_TKBO0_ACTIVE_FORCED_STOP_NO_INTERRUPT    (0x00U)    /* an interrupt is not generated when forced
                                                                       stopping of the output is activated */
#define _02_KB3_TKBO0_ACTIVE_FORCED_STOP_AN_INTERRUPT    (0x02U)    /* an interrupt is generated when forced stopping
                                                                       of the output is activated */
/* Control of the fixed off function for forced output stop function 2 for the TKBOn0 pin (TKBPAFIXn0) */
#define _00_KB3_TKBO0_FIXED_OFF_FUNCTION_DISABLE         (0x00U)    /* the fixed off function is not used */
#define _01_KB3_TKBO0_FIXED_OFF_FUNCTION_ENABLE          (0x01U)    /* the fixed off function is used */

/*
    Forced Output Stop Function Control Registers 04 to 24 (TKBPACTL04 to TKBPACTL24)
*/
/* Control of the operation of the forced output stop function pulse count register n1 (TKBPACTENn11, TKBPACTENn10) */
#define _00_KB3_PULSE_CHARACTERISTICS_REG1_DISABLE       (0x00U)    /* the pulse characteristics measurement function
                                                                       is disabled. */
#define _40_KB3_PULSE_CHARACTERISTICS_REG1_TKBO0         (0x40U)    /* the pulse characteristics measurement function
                                                                       for the TKBOn0 pin is enabled */
#define _80_KB3_PULSE_CHARACTERISTICS_REG1_TKBO1         (0x80U)    /* the pulse characteristics measurement function
                                                                       for the TKBOn1 pin is enabled */
/* Setting of the function of the forced output stop function pulse count register n1 (TKBPACTLVn11, TKBPACTLVn10) */
#define _00_KB3_PULSE_COUNT_HIGH_LEVEL_TO_TKBPAPLS1      (0x00U)    /* counting proceeds while the pulse is at the high
                                                                       level to measure the width and the result is
                                                                     stored in the corresponding TKBPAPLSn1 register */
#define _10_KB3_PULSE_COUNT_LOW_LEVEL_TO_TKBPAPLS1       (0x10U)    /* counting proceeds while the pulse is at the low
                                                                       level to measure the width and the result is
                                                                     stored in the corresponding TKBPAPLSn1 register */
#define _20_KB3_PULSE_COUNT_BETWEEN_RISING_TO_TKBPAPLS1  (0x20U)    /* counting proceeds between two consecutive rising
                                                                       edges to measure the pulse interval and the
                                                                       result is stored in the corresponding TKBPAPLSn1
                                                                       register */
#define _30_KB3_PULSE_COUNT_BETWEEN_FALLING_TO_TKBPAPLS1 (0x30U)    /* counting proceeds between two consecutive
                                                                       falling edges to measure the pulse interval and
                                                                       the result is stored in the corresponding
                                                                       TKBPAPLSn1 register */
/* Control of the operation of the forced output stop function pulse count register n0 (TKBPACTENn01, TKBPACTENn00) */
#define _00_KB3_PULSE_CHARACTERISTICS_REG0_DISABLE       (0x00U)    /* the pulse characteristics measurement function
                                                                       is disabled. */
#define _04_KB3_PULSE_CHARACTERISTICS_REG0_TKBO0         (0x04U)    /* the pulse characteristics measurement function
                                                                       for the TKBOn0 pin is enabled */
#define _08_KB3_PULSE_CHARACTERISTICS_REG0_TKBO1         (0x08U)    /* the pulse characteristics measurement function
                                                                       for the TKBOn1 pin is enabled */
/* Setting of the function of the forced output stop function pulse count register n0 (TKBPACTLVn01, TKBPACTLVn00) */
#define _00_KB3_PULSE_COUNT_HIGH_LEVEL_TO_TKBPAPLS0      (0x00U)    /* counting proceeds while the pulse is at the high
                                                                       level to measure the width and the result is
                                                                     stored in the corresponding TKBPAPLSn1 register */
#define _01_KB3_PULSE_COUNT_LOW_LEVEL_TO_TKBPAPLS0       (0x01U)    /* counting proceeds while the pulse is at the low
                                                                       level to measure the width and the result is
                                                                     stored in the corresponding TKBPAPLSn1 register */
#define _02_KB3_PULSE_COUNT_BETWEEN_RISING_TO_TKBPAPLS0  (0x02U)    /* counting proceeds between two consecutive rising
                                                                       edges to measure the pulse interval and the
                                                                       result is stored in the corresponding TKBPAPLSn1
                                                                       register */
#define _03_KB3_PULSE_COUNT_BETWEEN_FALLING_TO_TKBPAPLS0 (0x03U)    /* counting proceeds between two consecutive
                                                                       falling edges to measure the pulse interval and
                                                                       the result is stored in the corresponding
                                                                       TKBPAPLSn1 register */

/*
    Forced Output Stop Function Flag Registers 0 to 2 (TKBPAFLG0 to TKBPAFLG2)
*/
/* Status flag of forced output stop function 2 for TKBOn1 pin (TKBPAFSFn1) */
#define _00_KB3_TKBO1_FORCED_STOP_FUNC2_CLEAR_STATUS     (0x00U)    /* forced output stop function clear status */
#define _80_KB3_TKBO1_FORCED_STOP_FUNC2_STATUS           (0x80U)    /* forced output stop function status */
/* Status flag of forced output stop function 1 for TKBOn1 pin (TKBPAHSFn1) */
#define _00_KB3_TKBO1_FORCED_STOP_FUNC1_CLEAR_STATUS     (0x00U)    /* forced output stop function clear status */
#define _40_KB3_TKBO1_FORCED_STOP_FUNC1_STATUS           (0x40U)    /* forced output stop function status */
/* Status flag of forced output stop function 2 for TKBOn0 pin (TKBPAFSFn0) */
#define _00_KB3_TKBO0_FORCED_STOP_FUNC2_CLEAR_STATUS     (0x00U)    /* forced output stop function clear status */
#define _20_KB3_TKBO0_FORCED_STOP_FUNC2_STATUS           (0x20U)    /* forced output stop function status */
/* Status flag of forced output stop function 1 for TKBOn0 pin (TKBPAHSFn0) */
#define _00_KB3_TKBO0_FORCED_STOP_FUNC1_CLEAR_STATUS     (0x00U)    /* forced output stop function clear status */
#define _10_KB3_TKBO0_FORCED_STOP_FUNC1_STATUS           (0x10U)    /* forced output stop function status */
/* Input monitor bit of forced output stop function 2 for TKBOn1 pin (TKBPAFIFn1) */
#define _00_KB3_TKBO1_FORCED_STOP_FUNC2_AT_LOW           (0x00U)    /* forced output stop function 2 trigger signal is
                                                                       at low level */
#define _08_KB3_TKBO1_FORCED_STOP_FUNC2_AT_HIGH          (0x08U)    /* forced output stop function 2 trigger signal is
                                                                       at high level */
/* Input monitor bit of forced output stop function 1 for TKBOn1 pin (TKBPAHIFn1) */
#define _00_KB3_TKBO1_FORCED_STOP_FUNC1_AT_LOW           (0x00U)    /* forced output stop function 1 trigger signal is
                                                                       at low level */
#define _04_KB3_TKBO1_FORCED_STOP_FUNC1_AT_HIGH          (0x04U)    /* forced output stop function 1 trigger signal is
                                                                       at high level */
/* Input monitor bit of forced output stop function 2 for TKBOn0 pin (TKBPAFIFn0) */
#define _00_KB3_TKBO0_FORCED_STOP_FUNC2_AT_LOW           (0x00U)    /* forced output stop function 2 trigger signal is
                                                                       at low level */
#define _02_KB3_TKBO0_FORCED_STOP_FUNC2_AT_HIGH          (0x02U)    /* forced output stop function 2 trigger signal is
                                                                       at high level */
/* Input monitor bit of forced output stop function 1 for TKBOn0 pin (TKBPAHIFn0) */
#define _00_KB3_TKBO0_FORCED_STOP_FUNC1_AT_LOW           (0x00U)    /* forced output stop function 1 trigger signal is
                                                                       at low level */
#define _01_KB3_TKBO0_FORCED_STOP_FUNC1_AT_HIGH          (0x01U)    /* forced output stop function 1 trigger signal is
                                                                       at high level */

/*
    Forced Output Stop Function 1 Start Trigger Registers 0 to 2 (TKBPAHFS0 to TKBPAHFS2)
*/
/* Start trigger of forced output stop function 1 for TKBOn1 output (TKBPAHTSn1) */
#define _02_KB3_TKBO1_FORCED_STOP_FUNC1_START            (0x02U)    /* starts forced output stop function 1 for TKBOn1
                                                                       output */
/* Start trigger of forced output stop function 1 for TKBOn0 output (TKBPAHTSn0) */
#define _01_KB3_TKBO0_FORCED_STOP_FUNC1_START            (0x01U)    /* starts forced output stop function 1 for TKBOn0
                                                                       output */

/*
    Forced Output Stop Function Cancel 1 Trigger Registers 0 to 2 (TKBPAHFT0 to TKBPAHFT2)
*/
/* Cancel trigger of forced output stop function for TKBOn1 output (TKBPAHTTn1) */
#define _02_KB3_TKBO1_FORCED_STOP_FUNC1_CLEAR            (0x02U)    /* clears forced output stop function 1 for TKBOn1
                                                                       output */
/* Cancel trigger of forced output stop function for TKBOn0 output (TKBPAHTTn0) */
#define _01_KB3_TKBO0_FORCED_STOP_FUNC1_CLEAR            (0x01U)    /* clears forced output stop function 1 for TKBOn0
                                                                       output */

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

