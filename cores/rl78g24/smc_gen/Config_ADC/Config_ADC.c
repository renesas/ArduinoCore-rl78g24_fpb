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
* File Name        : Config_ADC.c
* Component Version: 1.4.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_ADC.
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
#include "Config_ADC.h"
/* Start user code for include. Do not edit comment generated here */
#include <Arduino.h>
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Create
* Description  : This function initializes the ADC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Create(void)
{
    ADCEN = 1U;    /* supply AD clock */
    ADMK0 = 1U;    /* disable INTAD0 interrupt */
    ADIF0 = 0U;    /* clear INTAD0 interrupt flag */
    ADMK1 = 1U;    /* disable INTAD1 interrupt */
    ADIF1 = 0U;    /* clear INTAD1 interrupt flag */
    ADMK2 = 1U;    /* disable INTAD2 interrupt */
    ADIF2 = 0U;    /* clear INTAD2 interrupt flag */
    ADMK3 = 1U;    /* disable INTAD3 interrupt */
    ADIF3 = 0U;    /* clear INTAD3 interrupt flag */
    /* Set INTAD0 priority */
    ADPR10 = 1U;
    ADPR00 = 1U;

    ADVMOD = 1U;
    ADM0 = _20_AD_CONVERSION_CLOCK_2 | _00_AD_TIME_MODE_NORMAL_1;
    ADM1 = _20_AD_CONVMODE_ONESELECT | _00_AD_FCLK_BETWEEN_4_48;
    ADM2 = _00_AD_AREA_MODE_1 | _00_AD_RESOLUTION_10BIT;
    ADUL = _FF_AD_ADUL_VALUE;
    ADLL = _00_AD_ADLL_VALUE;
    ADS0 = _12_AD_ADV_INPUT_ANI18;
    ADSCTL = _00_AD_ADV_ADS3_DISABLE | _00_AD_ADV_ADS2_DISABLE | _00_AD_ADV_ADS1_DISABLE | _10_AD_ADV_ADS0_ENABLE | 
             _00_AD_ADV_ADS0_PRIOR_LOW;
    ADTR0 = _0F_AD_ADV_TRIGGER_SW;
    ADINTCTL = _00_AD_ADV_INTAD3_DISABLE | _00_AD_ADV_INTAD2_DISABLE | _00_AD_ADV_INTAD1_DISABLE | 
               _02_AD_ADV_INTAD0_ENABLE | _00_AD_ADV_ADS0_FAIL_STORE_DISABLE;
    ADCE = 0U;
    ADM2 &= (uint8_t)~_20_AD_NEGATIVE_AVREFM;    /* set the (-) side reference voltage */
    ADM2 &= _3F_AD_POSITIVE_CLEAR;    /* clear ADREFP1 and ADREFP0 */
    ADM2 |= _00_AD_POSITIVE_VDD;    /* set the (+) side reference voltage */

    R_Config_ADC_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Start
* Description  : This function starts the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Start(void)
{
    ADIF0 = 0U;    /* clear INTAD0 interrupt flag */
    ADMK0 = 0U;    /* enable INTAD0 interrupt */
    ADCS = 1U;    /* enable conversion operation */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Stop
* Description  : This function stops the AD converter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Stop(void)
{
    ADCS = 0U;    /* stop conversion operation */
    ADMK0 = 1U;    /* disable INTAD0 interrupt */
    ADIF0 = 0U;    /* clear INTAD0 interrupt flag */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Set_OperationOn
* Description  : This function enables AD voltage comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Set_OperationOn(void)
{
    volatile uint16_t w_count;

    ADCE = 1U;    /* enable AD comparator */

    /* Reference voltage stability wait time (B) 1us */
    for (w_count = 0U; w_count < AD_WAITTIME_B; w_count++ )
    {
        NOP();
    }
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Set_OperationOff
* Description  : This function disables AD voltage comparator operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Set_OperationOff(void)
{
    ADCE = 0U;    /* disable AD comparator */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_Set_SoftwareTriggerOn
* Description  : This function generates software trigger.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_Set_SoftwareTriggerOn(void)
{
    ADTRSWT = 1U;    /* generate software trigger */
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_ADS0_Get_Result_10bit
* Description  : This function returns the high 10 bits conversion result in the buffer.
* Arguments    : buffer -
*                    the address where to write the conversion result
* Return Value : None
***********************************************************************************************************************/
void R_Config_ADC_ADS0_Get_Result_10bit(uint16_t * const buffer)
{
    *buffer = (uint16_t)(ADCR0 >> 6U);
}

/***********************************************************************************************************************
* Function Name: R_Config_ADC_ADS0_Set_ADChannel
* Description  : This function selects analog input channel.
* Arguments    : channel -
*                    analog input channel
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_ADC_ADS0_Set_ADChannel(e_ad_channel_t channel)
{
    MD_STATUS status = MD_OK;

    if (((channel > ADCHANNEL7) && (channel < ADCHANNEL16)) || (channel > ADINTERREFVOLT))
    {
        status = MD_ARGERROR;
    }
    else
    {
        ADS0 &= _C0_AD_ADV_INPUT_CLEAR;
        ADS0 |= (uint8_t)channel;
    }
    return (status);
}


/* Start user code for adding. Do not edit comment generated here */

void R_Config_ADC_ADS0_Get_Result_8bit(uint8_t * const buffer)
{
    *buffer = ADCR0H;
}

MD_STATUS R_Config_ADC_Set_Reference(uint8_t mode)
{
    MD_STATUS status = MD_OK;
    volatile uint16_t w_count;

    if (DEFAULT == mode)
    {
        ADM2 |= _00_AD_POSITIVE_VDD;    /* use VDD as VREF(+) */
    }
    else if (INTERNAL == mode)
    {
        ADM0 |= _04_AD_TIME_MODE_LOWVOLTAGE_1;
        ADM2 |= _01_AD_RESOLUTION_8BIT;
        ADM2 |= _C0_AD_POSITIVE_DISCHARGE;        /* Discharge */

    /* Reference voltage discharge time 1us */
        for (w_count = 0U; w_count < AD_WAITTIME_DISCHARGE; w_count++)
        {
            NOP();
        }

        ADM2 &= _3F_AD_POSITIVE_CLEAR;        /* clear ADREFP1 and ADREFP0 */
        ADM2 |= _80_AD_POSITIVE_INTERVOLT;        /* set the reference voltage */

    /* Internal reference voltage is selected, Reference voltage stability wait time(A), 5us */
        for (w_count = 0U; w_count < AD_WAITTIME_A; w_count++)
        {
            NOP();
        }

        ADM2 |= _80_AD_POSITIVE_INTERVOLT;        /* use internal voltage as VREF(+) */

    }
/*
    else if (INTERNAL == EXTERNAL)
    {
        ADM2 |= _40_AD_POSITIVE_AVREFP;        // use AVREFP as VREF(+)
    }
*/
    else // default
    {
        ADM2 |= _00_AD_POSITIVE_VDD;    /* use VDD as VREF(+) */
    }
    return status;
}




void R_Config_ADC_Set_ComparisonLimit(uint8_t upper, uint8_t lower)
{
    ADUL = upper;
    ADLL = lower;
}

void R_Config_ADC_Set_TemperatureSensor(void)
{
    ADCEN = 1U;    /* supply AD clock */
    ADMK0 = 1U;    /* disable INTAD0 interrupt */
    ADIF0 = 0U;    /* clear INTAD0 interrupt flag */
    ADMK1 = 1U;    /* disable INTAD1 interrupt */
    ADIF1 = 0U;    /* clear INTAD1 interrupt flag */
    ADMK2 = 1U;    /* disable INTAD2 interrupt */
    ADIF2 = 0U;    /* clear INTAD2 interrupt flag */
    ADMK3 = 1U;    /* disable INTAD3 interrupt */
    ADIF3 = 0U;    /* clear INTAD3 interrupt flag */
    /* Set INTAD0 priority */
    ADPR10 = 1U;
    ADPR00 = 1U;

    ADVMOD = 1U;
    ADM0 = 0x04;
    ADM1 = _20_AD_CONVMODE_ONESELECT | _00_AD_FCLK_BETWEEN_4_48;
    ADM2 = _00_AD_AREA_MODE_1 | _00_AD_RESOLUTION_10BIT;
    ADUL = _FF_AD_ADUL_VALUE;
    ADLL = _00_AD_ADLL_VALUE;
    ADS0 = _20_AD_ADV_INPUT_TEMPERATURE;
    ADSCTL = _00_AD_ADV_ADS3_DISABLE | _00_AD_ADV_ADS2_DISABLE | _00_AD_ADV_ADS1_DISABLE | _10_AD_ADV_ADS0_ENABLE |
             _00_AD_ADV_ADS0_PRIOR_LOW;
    ADTR0 = _0F_AD_ADV_TRIGGER_SW;
    ADINTCTL = _00_AD_ADV_INTAD3_DISABLE | _00_AD_ADV_INTAD2_DISABLE | _00_AD_ADV_INTAD1_DISABLE |
               _02_AD_ADV_INTAD0_ENABLE | _00_AD_ADV_ADS0_FAIL_STORE_DISABLE;
    ADCE = 0U;
    ADM2 &= (uint8_t)~_20_AD_NEGATIVE_AVREFM;    /* set the (-) side reference voltage */
    ADM2 &= _3F_AD_POSITIVE_CLEAR;    /* clear ADREFP1 and ADREFP0 */
    ADM2 |= _00_AD_POSITIVE_VDD;    /* set the (+) side reference voltage */
}

void R_Config_ADC_Set_InternalReferenceVoltage(void)
{
    ADCEN = 1U;    /* supply AD clock */
    ADMK0 = 1U;    /* disable INTAD0 interrupt */
    ADIF0 = 0U;    /* clear INTAD0 interrupt flag */
    ADMK1 = 1U;    /* disable INTAD1 interrupt */
    ADIF1 = 0U;    /* clear INTAD1 interrupt flag */
    ADMK2 = 1U;    /* disable INTAD2 interrupt */
    ADIF2 = 0U;    /* clear INTAD2 interrupt flag */
    ADMK3 = 1U;    /* disable INTAD3 interrupt */
    ADIF3 = 0U;    /* clear INTAD3 interrupt flag */
    /* Set INTAD0 priority */
    ADPR10 = 1U;
    ADPR00 = 1U;

    ADVMOD = 1U;
    ADM0 = 0x04;
    ADM1 = _20_AD_CONVMODE_ONESELECT | _00_AD_FCLK_BETWEEN_4_48;
    ADM2 = _00_AD_AREA_MODE_1 | _00_AD_RESOLUTION_10BIT;
    ADUL = _FF_AD_ADUL_VALUE;
    ADLL = _00_AD_ADLL_VALUE;
    ADS0 = _21_AD_ADV_INPUT_INREFVOLT;
    ADSCTL = _00_AD_ADV_ADS3_DISABLE | _00_AD_ADV_ADS2_DISABLE | _00_AD_ADV_ADS1_DISABLE | _10_AD_ADV_ADS0_ENABLE |
             _00_AD_ADV_ADS0_PRIOR_LOW;
    ADTR0 = _0F_AD_ADV_TRIGGER_SW;
    ADINTCTL = _00_AD_ADV_INTAD3_DISABLE | _00_AD_ADV_INTAD2_DISABLE | _00_AD_ADV_INTAD1_DISABLE |
               _02_AD_ADV_INTAD0_ENABLE | _00_AD_ADV_ADS0_FAIL_STORE_DISABLE;
    ADCE = 0U;
    ADM2 &= (uint8_t)~_20_AD_NEGATIVE_AVREFM;    /* set the (-) side reference voltage */
    ADM2 &= _3F_AD_POSITIVE_CLEAR;    /* clear ADREFP1 and ADREFP0 */
    ADM2 |= _00_AD_POSITIVE_VDD;    /* set the (+) side reference voltage */
    ADCE = 1U;

    /* Reference voltage stability wait time (B), 1us+2fAD */
    volatile uint16_t w_count;
    for (w_count = 0U; w_count < AD_WAITTIME_B; w_count++)
    {
        NOP();
    }
}
/* End user code. Do not edit comment generated here */

