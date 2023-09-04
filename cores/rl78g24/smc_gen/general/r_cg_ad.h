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
* File Name        : r_cg_ad.h
* Version          : 1.0.20
* Device(s)        : R7F101GLGxFB
* Description      : General header file for ADC peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef ADC_H
#define ADC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control of supply of an input clock to the A/D converter (ADCEN) */
#define _00_AD_CLOCK_STOP                      (0x00U)    /* stop supply of input clock */
#define _20_AD_CLOCK_SUPPLY                    (0x20U)    /* supply input clock */

/*
    Peripheral Reset Register 0 (PRR0)
*/
/* Control resetting of the A/D converter (ADCRES) */
#define _00_AD_RESET_RELEASE                   (0x00U)    /* the A/D converter is released from the reset state */
#define _20_AD_RESET_SET                       (0x20U)    /* the A/D converter is in the reset state */

/*
    AD Converter Mode Register 0 (ADM0)
*/
/* A/D conversion operation control (ADCS) */
#define _00_AD_CONVERSION_DISABLE              (0x00U)    /* disable conversion operation */
#define _80_AD_CONVERSION_ENABLE               (0x80U)    /* enable conversion operation */
/* Specification of the A/D conversion channel selection mode (ADMD) */
#define _00_AD_OPERMODE_SELECT                 (0x00U)    /* select operation mode */
#define _40_AD_OPERMODE_SCAN                   (0x40U)    /* scan operation mode */
/* A/D conversion clock selection (FR2-FR0) */
#define _00_AD_CONVERSION_CLOCK_32             (0x00U)    /* fCLK/32 */
#define _08_AD_CONVERSION_CLOCK_16             (0x08U)    /* fCLK/16 */
#define _10_AD_CONVERSION_CLOCK_8              (0x10U)    /* fCLK/8 */
#define _18_AD_CONVERSION_CLOCK_4              (0x18U)    /* fCLK/4 */
#define _20_AD_CONVERSION_CLOCK_2              (0x20U)    /* fCLK/2 */
#define _28_AD_CONVERSION_CLOCK_1              (0x28U)    /* fCLK/1 */
/* Specification A/D conversion time mode (LV1,LV0) */
#define _00_AD_TIME_MODE_NORMAL_1              (0x00U)    /* normal 1 mode */
#define _02_AD_TIME_MODE_NORMAL_2              (0x02U)    /* normal 2 mode */
#define _04_AD_TIME_MODE_LOWVOLTAGE_1          (0x04U)    /* low-voltage 1 mode */
#define _06_AD_TIME_MODE_LOWVOLTAGE_2          (0x06U)    /* low-voltage 2 mode */
/* A/D voltage comparator operation control (ADCE) */
#define _00_AD_COMPARATOR_DISABLE              (0x00U)    /* disable A/D voltage comparator operation */
#define _01_AD_COMPARATOR_ENABLE               (0x01U)    /* enable A/D voltage comparator operation */

/*
    AD Converter Mode Register 1 (ADM1)
*/
/* Selection of the A/D conversion trigger mode (ADTMD1,ADTMD0) */
#define _00_AD_TRIGGER_SOFTWARE                (0x00U)    /* software trigger no-wait or wait mode */
#define _80_AD_TRIGGER_HARDWARE_NOWAIT         (0x80U)    /* hardware trigger no-wait mode */
#define _C0_AD_TRIGGER_HARDWARE_WAIT           (0xC0U)    /* hardware trigger wait mode */
/* Specification of the A/D conversion mode (ADSCM) */
#define _00_AD_CONVMODE_CONSELECT              (0x00U)    /* sequential conversion mode */
#define _20_AD_CONVMODE_ONESELECT              (0x20U)    /* one-shot conversion mode */
/* fCLK input frequency setting (ADLSP) */
#define _00_AD_FCLK_BETWEEN_4_48               (0x00U)    /* 4 MHz < fCLK <= 48 MHz */
#define _08_AD_FCLK_BETWEEN_1_4                (0x08U)    /* 1 MHz <= fCLK <= 4 MHz */
/* Trigger signal selection (ADTRS2-ADTRS0) */
#define _00_AD_TRIGGER_INTTM01                 (0x00U)    /* channel 01 timer array unit counting or
                                                             capture end interrupt signal (INTTM01) */
#define _02_AD_TRIGGER_INTRTC                  (0x02U)    /* realtime clock interrupt signal (INTRTC) */
#define _03_AD_TRIGGER_ELCITL0                 (0x03U)    /* 32-bit interval timer channel 0 interrupt signal 
                                                             (ELCITL0) */
#define _04_AD_TRIGGER_ELC                     (0x04U)    /* event input from the ELC */

/*
    AD Converter Mode Register 2 (ADM2)
*/
/* Selection of the + side reference voltage source of the A/D converter (ADREFP1,ADREFP0) */
#define _00_AD_POSITIVE_VDD                    (0x00U)    /* supplied from VDD */
#define _40_AD_POSITIVE_AVREFP                 (0x40U)    /* supplied from P20/AVREFP/ANI0 */
#define _80_AD_POSITIVE_INTERVOLT              (0x80U)    /* supplied from the internal reference voltage */
#define _C0_AD_POSITIVE_DISCHARGE              (0xC0U)    /* discharged */
#define _3F_AD_POSITIVE_CLEAR                  (0x3FU)    /* clear ADREFP1 and ADREFP0 */
/* Selection of the - side reference voltage source of the A/D converter (ADREFM) */
#define _00_AD_NEGATIVE_VSS                    (0x00U)    /* supplied from VSS */
#define _20_AD_NEGATIVE_AVREFM                 (0x20U)    /* supplied from P21/AVREFM/ANI1 */
/* Checking the upper limit and lower limit conversion result values (ADRCK) */
#define _00_AD_AREA_MODE_1                     (0x00U)    /* generates INTADn when ADLL <= ADCRn <= ADUL */
#define _08_AD_AREA_MODE_2_3                   (0x08U)    /* generates INTADn when ADCRH < ADUL or ADUL < ADCRn */
/* Specification of the SNOOZE mode (AWC) */
#define _00_AD_WAKEUP_OFF                      (0x00U)    /* does not use the SNOOZE mode function */
#define _04_AD_WAKEUP_ON                       (0x04U)    /* uses the SNOOZE mode function */
/* Selection of the A/D conversion resolution (ADTYP1,ADTYP0) */
#define _00_AD_RESOLUTION_10BIT                (0x00U)    /* 10-bit resolution */
#define _01_AD_RESOLUTION_8BIT                 (0x01U)    /* 8-bit resolution */
#define _02_AD_RESOLUTION_12BIT                (0x02U)    /* 12-bit resolution */

/*
    AD Converter Mode Register 3 (ADM3)
*/
/* Software trigger (ADTRSWT) */
#define _00_AD_ADV_SW_NOT_GENERATE             (0x00U)    /* a software trigger is not generated */
#define _80_AD_ADV_SW_GENERATE                 (0x80U)    /* a software trigger is generated */
/* Setting of the advanced mode (ADVMOD) */
#define _00_AD_ADV_MODE_DISABLE                (0x00U)    /* the advanced mode is disabled */
#define _01_AD_ADV_MODE_ENABLE                 (0x01U)    /* the advanced mode is enabled */

/*
    Analog Input Channel Specification Register (ADS)
*/
/* Specification of analog input channel (ADISS,ADS4-ADS0) */
/* Select mode */
#define _00_AD_INPUT_CHANNEL_0                 (0x00U)    /* ANI0 */
#define _01_AD_INPUT_CHANNEL_1                 (0x01U)    /* ANI1 */
#define _02_AD_INPUT_CHANNEL_2                 (0x02U)    /* ANI2 */
#define _03_AD_INPUT_CHANNEL_3                 (0x03U)    /* ANI3 */
#define _04_AD_INPUT_CHANNEL_4                 (0x04U)    /* ANI4 */
#define _05_AD_INPUT_CHANNEL_5                 (0x05U)    /* ANI5 */
#define _06_AD_INPUT_CHANNEL_6                 (0x06U)    /* ANI6 */
#define _07_AD_INPUT_CHANNEL_7                 (0x07U)    /* ANI7 */
#define _10_AD_INPUT_CHANNEL_16                (0x10U)    /* ANI16 */
#define _11_AD_INPUT_CHANNEL_17                (0x11U)    /* ANI17 */
#define _12_AD_INPUT_CHANNEL_18                (0x12U)    /* ANI18 */
#define _13_AD_INPUT_CHANNEL_19                (0x13U)    /* ANI19 */
#define _14_AD_INPUT_CHANNEL_20                (0x14U)    /* ANI20 */
#define _15_AD_INPUT_CHANNEL_21                (0x15U)    /* ANI21 */
#define _16_AD_INPUT_CHANNEL_22                (0x16U)    /* ANI22 */
#define _17_AD_INPUT_CHANNEL_23                (0x17U)    /* ANI23 */
#define _18_AD_INPUT_CHANNEL_24                (0x18U)    /* ANI24 */
#define _19_AD_INPUT_CHANNEL_25                (0x19U)    /* ANI25 */
#define _1A_AD_INPUT_CHANNEL_26                (0x1AU)    /* ANI26 */
#define _1B_AD_INPUT_CHANNEL_27                (0x1BU)    /* ANI27 */
#define _1C_AD_INPUT_CHANNEL_28                (0x1CU)    /* ANI28 */
#define _1D_AD_INPUT_CHANNEL_29                (0x1DU)    /* ANI29 */
#define _1E_AD_INPUT_CHANNEL_30                (0x1EU)    /* ANI30 */
#define _80_AD_INPUT_TEMPERSENSOR_0            (0x80U)    /* temperature sensor output voltage */
#define _81_AD_INPUT_INTERREFVOLT              (0x81U)    /* internal reference voltage */
/* Scan mode */
#define _00_AD_INPUT_CHANNEL_0_3               (0x00U)    /* ANI0 - ANI3 */
#define _01_AD_INPUT_CHANNEL_1_4               (0x01U)    /* ANI1 - ANI4 */
#define _02_AD_INPUT_CHANNEL_2_5               (0x02U)    /* ANI2 - ANI5 */
#define _03_AD_INPUT_CHANNEL_3_6               (0x03U)    /* ANI3 - ANI6 */
#define _04_AD_INPUT_CHANNEL_4_7               (0x04U)    /* ANI4 - ANI7 */

/*
    Analog Input Channel Specification Registers For Advanced Mode 0 To 3 (ADS0 To ADS3)
*/
/* Channel specification for simultaneous sampling (ADSPSCn1,ADSPSCn0) */
#define _00_AD_ADV_SIMUTANEOUS_UNUSE           (0x00U)    /* simultaneous sampling does not proceed */
#define _40_AD_ADV_USE_1ST_SH_CIRCUIT          (0x40U)    /* the first S&H circuit is used */
#define _80_AD_ADV_USE_2ND_SH_CIRCUIT          (0x80U)    /* the second S&H circuit is used
                                                             (for simultaneous sampling: ANI2) */
#define _C0_AD_ADV_USE_3RD_SH_CIRCUIT          (0xC0U)    /* the third S&H circuit is used
                                                             (for simultaneous sampling: ANI3) */
/* Specification of analog input channel (ADISSn,ADSn4-ADSn0) */
#define _00_AD_ADV_INPUT_ANI0                  (0x00U)    /* ANI0 */
#define _01_AD_ADV_INPUT_ANI1                  (0x01U)    /* ANI1 */
#define _02_AD_ADV_INPUT_ANI2                  (0x02U)    /* ANI2 */
#define _03_AD_ADV_INPUT_ANI3                  (0x03U)    /* ANI3 */
#define _04_AD_ADV_INPUT_ANI4                  (0x04U)    /* ANI4 */
#define _05_AD_ADV_INPUT_ANI5                  (0x05U)    /* ANI5 */
#define _06_AD_ADV_INPUT_ANI6                  (0x06U)    /* ANI6 */
#define _07_AD_ADV_INPUT_ANI7                  (0x07U)    /* ANI7 */
#define _10_AD_ADV_INPUT_ANI16                 (0x10U)    /* ANI16 */
#define _11_AD_ADV_INPUT_ANI17                 (0x11U)    /* ANI17 */
#define _12_AD_ADV_INPUT_ANI18                 (0x12U)    /* ANI18 */
#define _13_AD_ADV_INPUT_ANI19                 (0x13U)    /* ANI19 */
#define _14_AD_ADV_INPUT_ANI20                 (0x14U)    /* ANI20 */
#define _15_AD_ADV_INPUT_ANI21                 (0x15U)    /* ANI21 */
#define _16_AD_ADV_INPUT_ANI22                 (0x16U)    /* ANI22 */
#define _17_AD_ADV_INPUT_ANI23                 (0x17U)    /* ANI23 */
#define _18_AD_ADV_INPUT_ANI24                 (0x18U)    /* ANI24 */
#define _19_AD_ADV_INPUT_ANI25                 (0x19U)    /* ANI25 */
#define _1A_AD_ADV_INPUT_ANI26                 (0x1AU)    /* ANI26 */
#define _1B_AD_ADV_INPUT_ANI27                 (0x1BU)    /* ANI27 */
#define _1C_AD_ADV_INPUT_ANI28                 (0x1CU)    /* ANI28 */
#define _1D_AD_ADV_INPUT_ANI29                 (0x1DU)    /* ANI29 */
#define _1E_AD_ADV_INPUT_ANI30                 (0x1EU)    /* ANI30 */
#define _1F_AD_ADV_INPUT_PGA                   (0x1FU)    /* PGA input */
#define _20_AD_ADV_INPUT_TEMPERATURE           (0x20U)    /* temperature sensor output voltage */
#define _21_AD_ADV_INPUT_INREFVOLT             (0x21U)    /* internal reference voltage */
#define _C0_AD_ADV_INPUT_CLEAR                 (0xC0U)    /* clear ADISSn, ADSn4-ADSn0 */

/*
    Conversion Setting Register (ADSCTL)
*/
/* Enabling the ADS3 register (ADSEN3) */
#define _00_AD_ADV_ADS3_DISABLE                (0x00U)    /* disables the ADS3 register */
#define _80_AD_ADV_ADS3_ENABLE                 (0x80U)    /* enables the ADS3 register */
/* Enabling the ADS2 register (ADSEN2) */
#define _00_AD_ADV_ADS2_DISABLE                (0x00U)    /* disables the ADS2 register */
#define _40_AD_ADV_ADS2_ENABLE                 (0x40U)    /* enables the ADS2 register */
/* Enabling the ADS1 register (ADSEN1) */
#define _00_AD_ADV_ADS1_DISABLE                (0x00U)    /* disables the ADS1 register */
#define _20_AD_ADV_ADS1_ENABLE                 (0x20U)    /* enables the ADS1 register */
/* Enabling the ADS0 register (ADSEN0) */
#define _00_AD_ADV_ADS0_DISABLE                (0x00U)    /* disables the ADS0 register */
#define _10_AD_ADV_ADS0_ENABLE                 (0x10U)    /* enables the ADS0 register */
/* Priority of conversion for the channel specified by the ADS3 register (ADPRIOR3) */
#define _00_AD_ADV_ADS3_PRIOR_LOW              (0x00U)    /* channel specified by ADS3 register has low priority */
#define _08_AD_ADV_ADS3_PRIOR_HIGH             (0x08U)    /* channel specified by ADS3 register has high priority */
/* Priority of conversion for the channel specified by the ADS2 register (ADPRIOR2) */
#define _00_AD_ADV_ADS2_PRIOR_LOW              (0x00U)    /* channel specified by ADS2 register has low priority */
#define _04_AD_ADV_ADS2_PRIOR_HIGH             (0x04U)    /* channel specified by ADS2 register has high priority */
/* Priority of conversion for the channel specified by the ADS1 register (ADPRIOR1) */
#define _00_AD_ADV_ADS1_PRIOR_LOW              (0x00U)    /* channel specified by ADS1 register has low priority */
#define _02_AD_ADV_ADS1_PRIOR_HIGH             (0x02U)    /* channel specified by ADS1 register has high priority */
/* Priority of conversion for the channel specified by the ADS0 register (ADPRIOR0) */
#define _00_AD_ADV_ADS0_PRIOR_LOW              (0x00U)    /* channel specified by ADS0 register has low priority */
#define _01_AD_ADV_ADS0_PRIOR_HIGH             (0x01U)    /* channel specified by ADS0 register has high priority */

/*
    Conversion Trigger Specification Registers 0 To 3 (ADTR0 To ADTR3)
*/
/* Trigger source (ADTRSn3-ADTRSn0) */
#define _00_AD_ADV_TRIGGER_INTTM01             (0x00U)    /* TAU01 counting or capture end interrupt signal */
#define _02_AD_ADV_TRIGGER_INTRTC              (0x02U)    /* realtime clock interrupt signal */
#define _03_AD_ADV_TRIGGER_ELCITL0             (0x03U)    /* 32-bit interval timer channel 0 interrupt signal */
#define _04_AD_ADV_TRIGGER_ELC                 (0x04U)    /* event input from the ELC */
#define _08_AD_ADV_TRIGGER_16TKB30             (0x08U)    /* 16-bit timer KB30 A/D trigger signal */
#define _09_AD_ADV_TRIGGER_16TKB31             (0x09U)    /* 16-bit timer KB31 A/D trigger signal */
#define _0A_AD_ADV_TRIGGER_16TKB32             (0x0AU)    /* 16-bit timer KB32 A/D trigger signal */
#define _0B_AD_ADV_TRIGGER_TRD2_AD0            (0x0BU)    /* timer RD2 A/D conversion trigger 0 */
#define _0C_AD_ADV_TRIGGER_TRD2_AD1            (0x0CU)    /* timer RD2 A/D conversion trigger 1 */
#define _0F_AD_ADV_TRIGGER_SW                  (0x0FU)    /* software trigger */

/*
    Conversion Interrupt Control Register (ADINTCTL)
*/
/* Control when conversion was successful (ADINTCTL3S) */
#define _00_AD_ADV_INTAD3_DISABLE              (0x00U)    /* output of the INTAD3 signal and storage of the conversion
                                                             state information in the ADINTST are disabled */
#define _80_AD_ADV_INTAD3_ENABLE               (0x80U)    /* output of the INTAD3 signal and storage of the conversion
                                                             state information in the ADINTST are enabled */
/* Control when conversion failed (ADINTCTL3F) */
#define _00_AD_ADV_ADS3_FAIL_STORE_DISABLE     (0x00U)    /* storage of the state information in the ADINTST
                                                             when failure conversion are disabled */
#define _40_AD_ADV_ADS3_FAIL_STORE_ENABLE      (0x40U)    /* storage of the state information in the ADINTST
                                                             when failure conversion are enabled */
/* Control when conversion was successful (ADINTCTL2S) */
#define _00_AD_ADV_INTAD2_DISABLE              (0x00U)    /* output of the INTAD2 signal and storage of the conversion
                                                             state information in the ADINTST are disabled */
#define _20_AD_ADV_INTAD2_ENABLE               (0x20U)    /* output of the INTAD2 signal and storage of the conversion
                                                             state information in the ADINTST are enabled */
/* Control when conversion failed (ADINTCTL2F) */
#define _00_AD_ADV_ADS2_FAIL_STORE_DISABLE     (0x00U)    /* storage of the state information in the ADINTST
                                                             when failure conversion are disabled */
#define _10_AD_ADV_ADS2_FAIL_STORE_ENABLE      (0x10U)    /* storage of the state information in the ADINTST
                                                             when failure conversion are enabled */
/* Control when conversion was successful (ADINTCTL1S) */
#define _00_AD_ADV_INTAD1_DISABLE              (0x00U)    /* output of the INTAD1 signal and storage of the conversion
                                                             state information in the ADINTST are disabled */
#define _08_AD_ADV_INTAD1_ENABLE               (0x08U)    /* output of the INTAD1 signal and storage of the conversion
                                                             state information in the ADINTST are enabled */
/* Control when conversion failed (ADINTCTL1F) */
#define _00_AD_ADV_ADS1_FAIL_STORE_DISABLE     (0x00U)    /* storage of the state information in the ADINTST
                                                             when failure conversion are disabled */
#define _04_AD_ADV_ADS1_FAIL_STORE_ENABLE      (0x04U)    /* storage of the state information in the ADINTST
                                                             when failure conversion are enabled */
/* Control when conversion was successful (ADINTCTL0S) */
#define _00_AD_ADV_INTAD0_DISABLE              (0x00U)    /* output of the INTAD0 signal and storage of the conversion
                                                             state information in the ADINTST are disabled */
#define _02_AD_ADV_INTAD0_ENABLE               (0x02U)    /* output of the INTAD0 signal and storage of the conversion
                                                             state information in the ADINTST are enabled */
/* Control when conversion failed (ADINTCTL0F) */
#define _00_AD_ADV_ADS0_FAIL_STORE_DISABLE     (0x00U)    /* storage of the state information in the ADINTST
                                                             when failure conversion are disabled */
#define _01_AD_ADV_ADS0_FAIL_STORE_ENABLE      (0x01U)    /* storage of the state information in the ADINTST
                                                             when failure conversion are enabled */

/*
    Conversion Interrupt Status Register (ADINTST)
*/
/* State when conversion was successful (ADINTST3S) */
#define _00_AD_ADV_ADS3_CONV_INPROGRESS        (0x00U)    /* conversion for the analog input channel
                                                             specified by ADS3 has not been completed */
#define _80_AD_ADV_ADS3_CONV_COMPLETE          (0x80U)    /* conversion for the analog input channel
                                                             specified by ADS3 has been completed */
/* State when conversion was successful (ADINTST3F) */
#define _00_AD_ADV_ADS3_CONV_NOT_FAIL          (0x00U)    /* conversion for the analog input channel
                                                             specified by ADS3 did not fail */
#define _40_AD_ADV_ADS3_CONV_FAIL              (0x40U)    /* conversion for the analog input channel
                                                             specified by ADS3 failed */
/* State when conversion was successful (ADINTST2S) */
#define _00_AD_ADV_ADS2_CONV_INPROGRESS        (0x00U)    /* conversion for the analog input channel
                                                             specified by ADS2 has not been completed */
#define _20_AD_ADV_ADS2_CONV_COMPLETE          (0x20U)    /* conversion for the analog input channel
                                                             specified by ADS2 has been completed */
/* State when conversion was successful (ADINTST2F) */
#define _00_AD_ADV_ADS2_CONV_NOT_FAIL          (0x00U)    /* conversion for the analog input channel
                                                             specified by ADS2 did not fail */
#define _10_AD_ADV_ADS2_CONV_FAIL              (0x10U)    /* conversion for the analog input channel
                                                             specified by ADS2 failed */
/* State when conversion was successful (ADINTST1S) */
#define _00_AD_ADV_ADS1_CONV_INPROGRESS        (0x00U)    /* conversion for the analog input channel
                                                             specified by ADS1 has not been completed */
#define _08_AD_ADV_ADS1_CONV_COMPLETE          (0x08U)    /* conversion for the analog input channel
                                                             specified by ADS1 has been completed */
/* State when conversion was successful (ADINTST1F) */
#define _00_AD_ADV_ADS1_CONV_NOT_FAIL          (0x00U)    /* conversion for the analog input channel
                                                             specified by ADS1 did not fail */
#define _04_AD_ADV_ADS1_CONV_FAIL              (0x04U)    /* conversion for the analog input channel
                                                             specified by ADS1 failed */
/* State when conversion was successful (ADINTST0S) */
#define _00_AD_ADV_ADS0_CONV_INPROGRESS        (0x00U)    /* conversion for the analog input channel
                                                             specified by ADS0 has not been completed */
#define _02_AD_ADV_ADS0_CONV_COMPLETE          (0x02U)    /* conversion for the analog input channel
                                                             specified by ADS0 has been completed */
/* State when conversion was successful (ADINTST0F) */
#define _00_AD_ADV_ADS0_CONV_NOT_FAIL          (0x00U)    /* conversion for the analog input channel
                                                             specified by ADS0 did not fail */
#define _01_AD_ADV_ADS0_CONV_FAIL              (0x01U)    /* conversion for the analog input channel
                                                             specified by ADS0 failed */

/*
    Sampling Delay Clock Cycle Number Specification Register (ADPS)
*/
/* Number of clock cycles for sampling delay (PSCS1,PSCS0) */
#define _00_AD_ADV_SAMPLING_DELAY_0            (0x00U)    /* 0 cycles of the fAD clock */
#define _03_AD_ADV_SAMPLING_DELAY_3            (0x03U)    /* 3 cycles of the fAD clock */

/*
    A/D Conversion Sampling Mode Specification Register (ADSPMOD)
*/
/* A/D conversion sampling mode specification (ADSPMOD1,ADSPMOD0) */
#define _00_AD_ADV_SAMPLING_MODE_27            (0x00U)    /* 27 cycles of the fAD clock */
#define _01_AD_ADV_SAMPLING_MODE_20            (0x01U)    /* 20 cycles of the fAD clock */

/*
    AD Test Register (ADTES)
*/
/* A/D conversion target (ADTES1,ADTES0) */
#define _00_AD_NORMAL_INPUT                    (0x00U)    /* ANIxx or temperature sensor output voltage
                                                             or internal reference voltage */
#define _02_AD_TEST_AVREFM                     (0x02U)    /* the - side reference voltage */
#define _03_AD_TEST_AVREFP                     (0x03U)    /* the + side reference voltage */

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

