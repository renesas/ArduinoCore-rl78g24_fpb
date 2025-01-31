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
* File Name        : Config_IIC20.c
* Component Version: 1.6.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_IIC20.
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
#include "Config_IIC20.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint8_t   g_iic20_master_status_flag;    /* iic20 start flag for send address check */
volatile uint8_t   g_iica20_master_status_flag;   /* iic20 master flag */
volatile uint8_t * gp_iic20_tx_address;           /* iic20 send data pointer by master mode */
volatile uint16_t  g_iic20_tx_cnt;              /* iic20 send data size by master mode */
volatile uint8_t * gp_iic20_rx_address;           /* iic20 receive data pointer by master mode */
volatile uint16_t  g_iic20_rx_cnt;              /* iic20 receive data size by master mode */
uint16_t  g_iic20_rx_len;                      /* iic20 receive data length by master mode */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_IIC20_Create
* Description  : This function initializes the IIC20 master module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IIC20_Create(void)
{
    SPS1 &= _00F0_SAU_CK00_CLEAR;
    SPS1 |= _0001_SAU_CK00_FCLK_1;
    ST1 |= _0001_SAU_CH0_STOP_TRG_ON;
    IICMK20 = 1U;    /* disable INTIIC20 interrupt */
    IICIF20 = 0U;    /* clear INTIIC20 interrupt flag */
    /* Set INTIIC20 low priority */
    IICPR120 = 1U;
    IICPR020 = 1U;
    SIR10 = _0002_SAU_SIRMN_PECTMN | _0001_SAU_SIRMN_OVCTMN;    /* clear error flag */
    SMR10 = _0020_SAU_SMRMN_INITIALVALUE | _0000_SAU_CLOCK_SELECT_CK00 | _0000_SAU_CLOCK_MODE_CKS | 
            _0000_SAU_TRIGGER_SOFTWARE | _0000_SAU_EDGE_FALL | _0004_SAU_MODE_IIC | _0000_SAU_TRANSFER_END;
    SCR10 = _0004_SAU_SCRMN_INITIALVALUE | _0000_SAU_TIMING_1 | _0000_SAU_INTSRE_MASK | _0000_SAU_PARITY_NONE | 
            _0000_SAU_MSB | _0010_SAU_STOP_1 | _0003_SAU_LENGTH_8;
    SDR10 = _EE00_IIC20_DIVISOR;
    SO1 |= (_0100_SAU_CH0_CLOCK_OUTPUT_1 | _0001_SAU_CH0_DATA_OUTPUT_1);
    /* Set SCL20, SDA20 pin */
    POM1 |= 0x10U;
    PMCA1 &= 0xCFU;
    P1 |= 0x30U;
    PM1 &= 0xCFU;

    R_Config_IIC20_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_IIC20_Stop
* Description  : This function stops the IIC20 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IIC20_Stop(void)
{
    IICMK20 = 1U;    /* disable INTIIC20 interrupt */
    ST1 |= _0001_SAU_CH0_STOP_TRG_ON;
    IICIF20 = 0U;    /* clear INTIIC20 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_Config_IIC20_StartCondition
* Description  : This function starts the IIC20 condition.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IIC20_StartCondition(void)
{
    volatile uint8_t w_count;

    SO1 &= (uint16_t)~_0001_SAU_CH0_DATA_OUTPUT_1;    /* clear IIC20 SDA */

    /* Set delay to secure a hold time after SDA output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC20_WAITTIME; w_count++ )
    {
        NOP();
    }

    SO1 &= (uint16_t)~_0100_SAU_CH0_CLOCK_OUTPUT_1;    /* clear IIC20 SCL */
    SOE1 |= _0001_SAU_CH0_OUTPUT_ENABLE;    /* enable IIC20 output */
    SS1 |= _0001_SAU_CH0_START_TRG_ON;    /* enable IIC20 */

    /* Set delay to secure a hold time after SCL output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC20_WAITTIME; w_count++ )
    {
        NOP();
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_IIC20_StopCondition
* Description  : This function stops the IIC20 condition.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IIC20_StopCondition(void)
{
    volatile uint8_t w_count;

    ST1 |= _0001_SAU_CH0_STOP_TRG_ON;    /* disable IIC20 */
    SOE1 &= (uint16_t)~_0001_SAU_CH0_OUTPUT_ENABLE;    /* disable IIC20 output */
    SO1 &= (uint16_t)~_0001_SAU_CH0_DATA_OUTPUT_1;    /* clear IIC20 SDA */

    /* Set delay to secure a hold time after SDA output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC20_WAITTIME; w_count++ )
    {
        NOP();
    }

    SO1 |= _0100_SAU_CH0_CLOCK_OUTPUT_1;    /* set IIC20 SCL */

    /* Set delay to secure a hold time after SCL output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC20_WAITTIME; w_count++ )
    {
        NOP();
    }

    SO1 |= _0001_SAU_CH0_DATA_OUTPUT_1;    /* set IIC20 SDA */

    /* Set delay to secure a hold time after SDA output low. The delay time depend on slave device.
       Here set 5us as default base on current clock */
    for (w_count = 0U; w_count <= IIC20_WAITTIME; w_count++ )
    {
        NOP();
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_IIC20_Master_Send
* Description  : This function starts transferring data for IIC20 in master mode.
* Arguments    : adr -
*                    set address for select slave
*                tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : None
***********************************************************************************************************************/
MD_STATUS R_Config_IIC20_Master_Send(uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num, uint8_t wait)
{
    MD_STATUS status = MD_OK;

    g_iic20_master_status_flag = _00_SAU_IIC_MASTER_FLAG_CLEAR;    /* clear IIC20 master status flag */
    adr &= 0xFEU;    /* send mode */
    g_iic20_master_status_flag = _01_SAU_IIC_SEND_FLAG;    /* set master status flag */
    SCR10 &= (uint16_t)~_C000_SAU_RECEPTION_TRANSMISSION;
    SCR10 |= _8000_SAU_TRANSMISSION;
    /* Set paramater */
    g_iic20_tx_cnt = tx_num;
    gp_iic20_tx_address = tx_buf;
    /* Start condition */
    R_Config_IIC20_StartCondition();
    IICIF20 = 0U;    /* clear INTIIC20 interrupt flag */
    IICMK20 = 0U;    /* enable INTIIC20 */
    SIO20 = adr;
    g_iica20_master_status_flag = _00_IICA_MASTER_FLAG_CLEAR;
    return (status);
}

/***********************************************************************************************************************
* Function Name: R_Config_IIC20_Master_Receive
* Description  : This function starts receiving data for IIC20 in master mode.
* Arguments    : adr -
*                    set address for select slave
*                rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : None
***********************************************************************************************************************/
MD_STATUS R_Config_IIC20_Master_Receive(uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num, uint8_t wait)
{
    MD_STATUS status = MD_OK;

    g_iic20_master_status_flag = _00_SAU_IIC_MASTER_FLAG_CLEAR;    /* clear master status flag */
    adr |= 0x01U;    /* receive mode */
    g_iic20_master_status_flag = _02_SAU_IIC_RECEIVE_FLAG;    /* set master status flag */
    SCR10 &= (uint16_t)~_C000_SAU_RECEPTION_TRANSMISSION;
    SCR10 |= _8000_SAU_TRANSMISSION;
    /* Set parameter */
    g_iic20_rx_len = rx_num;
    g_iic20_rx_cnt = 0U;
    gp_iic20_rx_address = rx_buf;
    /* Start condition */
    R_Config_IIC20_StartCondition();
    IICIF20 = 0U;    /* clear INTIIC20 interrupt flag */
    IICMK20 = 0U;    /* enable INTIIC20 */
    SIO20 = adr;
    g_iica20_master_status_flag = _00_IICA_MASTER_FLAG_CLEAR;
    return (status);
}

/* Start user code for adding. Do not edit comment generated here */

/**********************************************************************************************************************
 * Function Name: R_Config_IICA0_Master_SetClock
 * Description  : This function sets I2C clock frequency
 * Arguments    : clock - clock frequency to set
 *              :   The given frequency is normalized
 *              :   cutting off to the either one of the frequencies below:
 *              :     I2C_CLOCK_FAST_PLUS = 1,000,000 Hz (fast     mode plus)
 *              :     I2C_CLOCK_FAST      =   400,000 Hz (fast     mode     )
 *              :     I2C_CLOCK_STANDARD  =   100,000 Hz (standard mode     )
 *              :   If the given frequency is lower than above all,
 *              :   considers it as the lowest clock or standard mode 100,000 Hz.
 * Return Value : None
 *********************************************************************************************************************/
void R_Config_IIC20_Master_SetClock(uint32_t clock) {
    uint32_t fclk_frequency;
    uint32_t  peri_clk    ;
    uint16_t tmp_sdr ;
    fclk_frequency = R_BSP_GetFclkFreqHz();
    peri_clk    = fclk_frequency / 2;
    tmp_sdr = (uint16_t)(( peri_clk/clock - 1) << 8) ;
    if(tmp_sdr>0)
    {
        SDR10 = tmp_sdr & 0xFE00;
    }
    else
    {
        SDR10 = 0x0200;
    }
}
/* End user code. Do not edit comment generated here */

