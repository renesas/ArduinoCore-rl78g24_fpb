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
* Copyright (C) 2021, 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_CSI10.c
* Component Version: 1.5.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_CSI10.
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
#include "Config_CSI10.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t * gp_csi10_tx_address;    /* csi10 send buffer address */
volatile uint16_t g_csi10_tx_count;        /* csi10 send data count */
volatile uint8_t * gp_csi10_rx_address;    /* csi10 receive buffer address */
/* Start user code for global. Do not edit comment generated here */
volatile uint16_t g_csi10_status_flag;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CSI10_Create
* Description  : This function initializes the CSI10 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSI10_Create(void)
{
    SPS0 &= _000F_SAU_CK01_CLEAR;
    SPS0 |= _0010_SAU_CK01_FCLK_1;
    /* Stop channel 2 */
    ST0 |= _0004_SAU_CH2_STOP_TRG_ON;
    /* Mask channel 2 interrupt */
    CSIMK10 = 1U;    /* disable INTCSI10 interrupt */
    CSIIF10 = 0U;    /* clear INTCSI10 interrupt flag */
    /* Set INTCSI10 low priority */
    CSIPR110 = 1U;
    CSIPR010 = 1U;
    SIR02 = _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR02 = _0020_SAU_SMRMN_INITIALVALUE | _8000_SAU_CLOCK_SELECT_CK01 | _0000_SAU_CLOCK_MODE_CKS | 
            _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_MODE_CSI | _0000_SAU_TRANSFER_END;
    SCR02 = _0004_SAU_SCRMN_INITIALVALUE | _C000_SAU_RECEPTION_TRANSMISSION | _3000_SAU_TIMING_4 | _0000_SAU_MSB |
            _0003_SAU_LENGTH_8;
    SDR02 = _0400_SAU0_CH2_BAUDRATE_DIVISOR;
    SO0 &= (uint16_t)~_0400_SAU_CH2_CLOCK_OUTPUT_1;    /* CSI10 clock initial level */
    SO0 &= (uint16_t)~_0004_SAU_CH2_DATA_OUTPUT_1;    /* CSI10 SO initial level */
    SOE0 |= _0004_SAU_CH2_OUTPUT_ENABLE;    /* enable CSI10 output */
    /* Set SI10 pin */
    PMCA0 &= 0xF7U;
    PM0 |= 0x08U;
    /* Set SO10 pin */
    PMCA0 &= 0xFBU;
    P0 |= 0x04U;
    PM0 &= 0xFBU;
    /* Set SCK10 pin */
    P0 |= 0x10U;
    PM0 &= 0xEFU;

    R_Config_CSI10_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_CSI10_Start
* Description  : This function starts the CSI10 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSI10_Start(void)
{
//    SO0 &= (uint16_t)~_0400_SAU_CH2_CLOCK_OUTPUT_1;    /* CSI10 clock initial level */
//    SO0 &= (uint16_t)~_0004_SAU_CH2_DATA_OUTPUT_1;    /* CSI10 SO initial level */
    SOE0 |= _0004_SAU_CH2_OUTPUT_ENABLE;    /* enable CSI10 output */
    SS0 |= _0004_SAU_CH2_START_TRG_ON;    /* enable CSI10 */
    CSIIF10 = 0U;    /* clear INTCSI10 interrupt flag */
    CSIMK10 = 0U;    /* enable INTCSI10 interrupt */
}

/***********************************************************************************************************************
* Function Name: R_Config_CSI10_Stop
* Description  : This function stops the CSI10 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_CSI10_Stop(void)
{
    CSIMK10 = 1U;    /* disable INTCSI10 interrupt */
    ST0 |= _0004_SAU_CH2_STOP_TRG_ON;    /* disable CSI10 */
    SOE0 &= (uint16_t)~_0004_SAU_CH2_OUTPUT_ENABLE;    /* disable CSI10 output */
    CSIIF10 = 0U;    /* clear INTCSI10 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_Config_CSI10_Send_Receive
* Description  : This function sends and receives CSI10 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
*                rx_buf -
*                    receive buffer pointer
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_CSI10_Send_Receive(uint8_t * const tx_buf, uint16_t tx_num, uint8_t * const rx_buf)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_csi10_tx_count = tx_num;    /* send data count */
        gp_csi10_tx_address = tx_buf;    /* send buffer pointer */
        gp_csi10_rx_address = rx_buf;    /* receive buffer pointer */
        CSIMK10 = 1U;    /* disable INTCSI10 interrupt */

        if (0U != gp_csi10_tx_address)
        {
            SIO10 = *gp_csi10_tx_address;    /* started by writing data to SDR02[7:0] */
            gp_csi10_tx_address++;
        }
        else
        {
            SIO10 = 0xFFU;
        }

        g_csi10_tx_count--;
        CSIMK10 = 0U;    /* enable INTCSI10 interrupt */
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/**********************************************************************************************************************
 * Function Name: R_Config_CSI10_GetBitOrder
 * Description  : Get the order of the bits shifted out of and into the SPI bus.
 * Arguments    : -
 * Return Value : Current bit order setting
 *              :   LSBFIRST
 *              :   MSBFIRST
 *********************************************************************************************************************/
uint8_t R_Config_CSI10_GetBitOrder(void) {
    return (SCR02 & (uint16_t)_0080_SAU_LSB) == _0080_SAU_LSB
                ? LSBFIRST : MSBFIRST;
}

/**********************************************************************************************************************
 * Function Name: R_Config_CSI10_SetBitOrder
 * Description  : Set the order of the bits shifted out of and into the SPI bus.
 * Arguments    : bitOrder - Bit order setting
 *              :   LSBFIRST
 *              :   MSBFIRST
 * Return Value : -
 *********************************************************************************************************************/
void R_Config_CSI10_SetBitOrder(uint8_t bitOrder) {
    ST0     |= _0004_SAU_CH2_STOP_TRG_ON;                       /* Stop channel 2 */
    SOE0    &= (uint16_t)~_0004_SAU_CH2_OUTPUT_ENABLE;          /* disable CSI10 output */

    SCR02    = (SCR02 & (uint16_t)~_0080_SAU_LSB)
             | (bitOrder == LSBFIRST ? _0080_SAU_LSB : _0000_SAU_MSB);

    CSIIF10  = 0U;                                              /* clear INTCSI10 interrupt flag */

//    SO0     |= _0800_SAU_CH3_CLOCK_OUTPUT_1;                    /* CSI10 clock initial level */
//    SO0     &= (uint16_t)~_0008_SAU_CH3_DATA_OUTPUT_1;          /* CSI10 SO initial level */
    SOE0    |= _0004_SAU_CH2_OUTPUT_ENABLE;                     /* enable CSI10 output */
    SS0     |= _0004_SAU_CH2_START_TRG_ON;                      /* enable CSI10 */
}

/**********************************************************************************************************************
 * Function Name: R_Config_CSI10_SetDataMode
 * Description  : Set the SPI data mode (clock polarity and phase).
 * Arguments    : dataMode - SPI data mode
 *              :   SPI_MODE0
 *              :   SPI_MODE1
 *              :   SPI_MODE2
 *              :   SPI_MODE3
 * Return Value : -
 *********************************************************************************************************************/
void R_Config_CSI10_SetDataMode(uint8_t dataMode) {

    ST0     |= _0004_SAU_CH2_STOP_TRG_ON;                       /* Stop channel 2 */
    SOE0    &= (uint16_t)~_0004_SAU_CH2_OUTPUT_ENABLE;          /* disable CSI10 output */

    /*
     * This mapping is obeying the base code.
     * Fix the `SPI_MODEx` macros together.
     */
    switch (dataMode) {
    case SPI_MODE3:
        SCR02 = (SCR02 & (uint16_t)~SPI_MODE_MASK) | _0000_SAU_TIMING_1;
        SO0     |= _0400_SAU_CH2_CLOCK_OUTPUT_1;                    /* CSI10 clock initial level */
        break;
    case SPI_MODE2:
        SCR02 = (SCR02 & (uint16_t)~SPI_MODE_MASK) | _2000_SAU_TIMING_3;
        SO0     |= _0400_SAU_CH2_CLOCK_OUTPUT_1;                    /* CSI10 clock initial level */
        break;
    case SPI_MODE1:
        SCR02 = (SCR02 & (uint16_t)~SPI_MODE_MASK) | _1000_SAU_TIMING_2;
        SO0     &= (uint16_t)~_0400_SAU_CH2_CLOCK_OUTPUT_1;                    /* CSI10 clock initial level */
        break;
    case SPI_MODE0:
    default:
        SCR02 = (SCR02 & (uint16_t)~SPI_MODE_MASK) | _3000_SAU_TIMING_4;
        SO0     &= (uint16_t)~_0400_SAU_CH2_CLOCK_OUTPUT_1;                    /* CSI10 clock initial level */
        break;
    }

    CSIIF10  = 0U;                                              /* clear INTCSI10 interrupt flag */

//    SO0     |= _0800_SAU_CH3_CLOCK_OUTPUT_1;                    /* CSI10 clock initial level */
//    SO0     &= (uint16_t)~_0008_SAU_CH3_DATA_OUTPUT_1;          /* CSI10 SO initial level */
    SOE0    |= _0004_SAU_CH2_OUTPUT_ENABLE;                     /* enable CSI10 output */
    SS0     |= _0004_SAU_CH2_START_TRG_ON;                      /* enable CSI10 */
}

/**********************************************************************************************************************
 * Function Name: R_Config_CSI10_SetClockDivider
 * Description  : Set the SPI clock divider relative to the system clock.
 * Arguments    : clockDiv - SPI clock divider
 *              :   SPI_CLOCK_DIV2
 *              :   SPI_CLOCK_DIV4
 *              :   SPI_CLOCK_DIV8
 *              :   SPI_CLOCK_DIV16
 *              :   SPI_CLOCK_DIV32
 *              :   SPI_CLOCK_DIV64
 *              :   SPI_CLOCK_DIV128
 *              :   or an immediate { 2, 4, 6, 8, ..., 256 }
 * Return Value : -
 *********************************************************************************************************************/
void R_Config_CSI10_SetClockDivider(uint16_t clockDiv) {
    ST0     |= _0004_SAU_CH2_STOP_TRG_ON;                       /* Stop channel 2 */
    SOE0    &= (uint16_t)~_0004_SAU_CH2_OUTPUT_ENABLE;          /* disable CSI10 output */

    clockDiv = clockDiv <   4 ?   4U
             : clockDiv > 256 ? 256U
             :                  clockDiv + (clockDiv & 1U);

    SDR02    = ((clockDiv >> 2) - 1) << 9;

    CSIIF10  = 0U;                                              /* clear INTCSI10 interrupt flag */

//    SO0     |= _0800_SAU_CH3_CLOCK_OUTPUT_1;                    /* CSI10 clock initial level */
//    SO0     &= (uint16_t)~_0008_SAU_CH3_DATA_OUTPUT_1;          /* CSI10 SO initial level */
    SOE0    |= _0004_SAU_CH2_OUTPUT_ENABLE;                     /* enable CSI10 output */
    SS0     |= _0004_SAU_CH2_START_TRG_ON;                      /* enable CSI10 */
}

/**********************************************************************************************************************
 * Function Name: R_Config_CSI10_SetClock
 * Description  : Set the SPI maximum speed of communication.
 * Arguments    : clock - SPI clock speed
 * Return Value : -
 *********************************************************************************************************************/
void R_Config_CSI10_SetClock(uint32_t clock) {
    uint16_t clockDiv;
    uint32_t spi_frequency = R_BSP_GetFclkFreqHz();

    for (clockDiv = 4; clockDiv < 256; clockDiv += 2)
    {
        if (clock >= spi_frequency / clockDiv)
        {
            break;
        }
    }

    R_Config_CSI10_SetClockDivider(clockDiv);
}
/* End user code. Do not edit comment generated here */
