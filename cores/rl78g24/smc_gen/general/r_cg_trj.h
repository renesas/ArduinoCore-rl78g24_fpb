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
* File Name        : r_cg_trj.h
* Version          : 1.0.12
* Device(s)        : R7F101GLGxFB
* Description      : General header file for TRJ peripheral.
* Creation Date    : 
***********************************************************************************************************************/

#ifndef TRJ_H
#define TRJ_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
 Peripheral Enable Register 2 (PER2)
 */
/* Control of timer RJ input clock supply (TRJ0EN) */
#define _00_TRJ_CLOCK_STOP                       (0x00U)    /* stops input clock supply */
#define _01_TRJ_CLOCK_SUPPLY                     (0x01U)    /* enables input clock supply */

/*
 Peripheral Reset Control Register 2 (PRR2)
*/
/* Control of timer RJ input clock supply (TRJ0RES) */
#define _00_TRJ_RESET_RELEASE                    (0x00U)    /* released from the reset state */
#define _01_TRJ_RESET_SET                        (0x01U)    /* reset */

/*
 Timer RJ Control Register 0 (TRJCR0)
 */
/* Timer RJ underflow flag (TUNDF) */
#define _00_TRJ_UNDERFLOW_NOOCCUR                (0x00U)    /* no underflow */
#define _20_TRJ_UNDERFLOW_OCCUR                  (0x20U)    /* underflow */
/* Active edge judgement flag (TEDGF) */
#define _00_TRJ_ACTIVE_EDGE_UNRECEIVED           (0x00U)    /* no active edge received */
#define _10_TRJ_ACTIVE_EDGE_RECEIVED             (0x10U)    /* active edge received */
/* Timer RJ count forced stop (TSTOP) */
#define _00_TRJ_FORCIBLE_STOP_DISABLE            (0x00U)    /* count is not forcibly stopped */
#define _04_TRJ_FORCIBLE_STOP_ENABLE             (0x04U)    /* count is forcibly stopped */
/* Timer RJ count status flag (TCSTF) */
#define _00_TRJ_STATUS_STOP                      (0x00U)    /* count stops */
#define _02_TRJ_STATUS_COUNT                     (0x02U)    /* count in progress */
/* Timer RJ count start (TSTART) */
#define _00_TRJ_COUNT_STOP                       (0x00U)    /* count stops */
#define _01_TRJ_COUNT_START                      (0x01U)    /* count starts */

/*
 Timer RJ I/O Control Register 0 (TRJIOC0)
 */
#define _00_TRJ_TRJIOC_INITIAL_VALUE             (0x00U)    /* TRJIOC0 register initial value */
/* TRJIO0 count control (TIOGT1, TIOGT0) */
#define _35_TRJ_EVENT_ENABLE_CLEAR               (0x35U)    /* TIOGT1, TIOGT0 clear */
#define _00_TRJ_EVENT_ENABLE_ALWAYS              (0x00U)    /* event is always counted */
#define _40_TRJ_EVENT_ENABLE_INTP4               (0x40U)    /* event is counted during polarity period specified
                                                               for INTP4 */
#define _80_TRJ_EVENT_ENABLE_TIMER               (0x80U)    /* event is counted during polarity period specified
                                                               for timer output signal */
/* TRJIO0 input filter select (TIPF1, TIPF0) */
#define _C5_TRJ_TRJIO_FILTER_CLEAR               (0xC5U)    /* TIPF1, TIPF0 clear */
#define _00_TRJ_TRJIO_FILTER_UNUSED              (0x00U)    /* no filter */
#define _10_TRJ_TRJIO_FILTER_FCLK                (0x10U)    /* filter sampled at fCLK */
#define _20_TRJ_TRJIO_FILTER_FCLK8               (0x20U)    /* filter sampled at fCLK/8 */
#define _30_TRJ_TRJIO_FILTER_FCLK32              (0x30U)    /* filter sampled at fCLK/32 */
/* TRJO0 output enable/disable (TOENA) */
#define _00_TRJ_TRJO_OUTPUT_DISABLE              (0x00U)    /* TRJO0 output disabled (port) */
#define _04_TRJ_TRJO_OUTPUT_ENABLE               (0x04U)    /* TRJO0 output enabled */
/* TRJIO0 I/O edge and polarity switching (TEDGSEL) */
/* For Pulse output mode */
#define _00_TRJ_TRJIO_OUTPUT_START_H             (0x00U)    /* output is started at high (Initialization level: High) */
#define _01_TRJ_TRJIO_OUTPUT_START_L             (0x01U)    /* output is started at low (Initialization level: Low) */
/* For Event counter mode */
#define _00_TRJ_TRJIO_COUNT_EDGE_RISING          (0x00U)    /* count at rising edge */
#define _01_TRJ_TRJIO_COUNT_EDGE_FALLING         (0x01U)    /* count at falling edge */
/* For Pulse width measurement mode */
#define _00_TRJ_TRJIO_MEASURE_LEVEL_L            (0x00U)    /* low-level width is measured */
#define _01_TRJ_TRJIO_MEASURE_LEVEL_H            (0x01U)    /* high-level width is measured */
/* For Pulse period measurement mode */
#define _00_TRJ_TRJIO_MEASURE_EDGE_RISING        (0x00U)    /* measure from one rising edge to the next rising edge */
#define _01_TRJ_TRJIO_MEASURE_EDGE_FALLING       (0x01U)    /* measure from one falling edge to the next falling edge */
/* For all mode */
#define _00_TRJ_TRJIO_POLARITY_LOW               (0x00U)    /* output is started at low (Initialization level: Low) */
#define _01_TRJ_TRJIO_POLARITY_HIGH              (0x01U)    /* output is started at high (Initialization level: High) */

/*
 Timer RJ Mode Register 0 (TRJMR0)
 */
/* Timer RJ count source select (TCK2 - TCK0) */
#define _0F_TRJ_COUNT_SOURCE_CLEAR               (0x0FU)    /* TCK2 - TCK0 clear */
#define _00_TRJ_COUNT_SOURCE_FCLK                (0x00U)    /* fCLK */
#define _10_TRJ_COUNT_SOURCE_FCLK8               (0x10U)    /* fCLK/8 */
#define _30_TRJ_COUNT_SOURCE_FCLK2               (0x30U)    /* fCLK/2 */
#define _40_TRJ_COUNT_SOURCE_FIL                 (0x40U)    /* fIL */
#define _50_TRJ_COUNT_SOURCE_ELC                 (0x50U)    /* event input from event link controller (ELC) */
#define _60_TRJ_COUNT_SOURCE_FSX                 (0x60U)    /* fSX */
/* TRJIO0 edge polarity select (TEDGPL) */
#define _00_TRJ_TRJIO_POLARITY_ONE               (0x00U)    /* one edge */
#define _08_TRJ_TRJIO_POLARITY_BOTH              (0x08U)    /* both edges */
/* Timer RJ operating mode select (TMOD2 - TMOD0) */
#define _78_TRJ_MODE_CLEAR                       (0x78U)    /* TMOD2 - TMOD0 clear */
#define _00_TRJ_MODE_TIMER                       (0x00U)    /* timer mode */
#define _01_TRJ_MODE_PULSE_OUTPUT                (0x01U)    /* pulse output mode */
#define _02_TRJ_MODE_EVENT_COUNTER               (0x02U)    /* event counter mode */
#define _03_TRJ_MODE_PULSE_WIDTH                 (0x03U)    /* pulse width measurement mode */
#define _04_TRJ_MODE_PULSE_PERIOD                (0x04U)    /* pulse period measurement mode */

/*
 Timer RJ Event Pin Select Register 0 (TRJISR0)
 */
/* Timer output signal and INTP4 polarity selection (RCCPSEL2) */
#define _00_TRJ_OUTPUT_POLARITY_L                (0x00U)    /* an event is counted during the low-level period */
#define _04_TRJ_OUTPUT_POLARITY_H                (0x04U)    /* an event is counted during the high-level period */
/* Timer output signal selection (RCCPSEL1, RCCPSEL0) */
#define _04_TRJ_OUTPUT_CLEAR                     (0x04U)    /* RCCPSEL1, RCCPSEL0 clear */
#define _00_TRJ_OUTPUT_TRDIOD1                   (0x00U)    /* TRDIOD1 */
#define _01_TRJ_OUTPUT_TRDIOC1                   (0x01U)    /* TRDIOC1 */
#define _02_TRJ_OUTPUT_TO02                      (0x02U)    /* TO02 */
#define _03_TRJ_OUTPUT_TO03                      (0x03U)    /* TO03 */

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

