#include <Arduino.h>
#include "utilities.h"
extern "C" {
    #include "r_smc_entry.h"
}

extern "C" {
}

/* This declaration is used to force the constant in
 * r_cg_vect_table.c to be linked to the static library (*.a). */
extern const unsigned char Option_Bytes[];
void * p_force_link = (void * )Option_Bytes;

int main(void)
{
/******************************************************/
    interrupts();                /* Enable Interrupt */
    _readResetFlag();           /* Read causes of reset */

/* Start Interval Timer */
    R_Config_ITL000_Create();    /* Create 1ms Interval Timer */
    R_Config_ITL000_Start();    /* Start 1ms Interval Timer */
    R_ITL_Start_Interrupt();    /* Start ITL Interrupt */

    R_Config_TAU0_1_Micros_Create();
    R_Config_TAU0_1_Micros_Start();

    /* Start RTC Timer */
//    R_Config_RTC_Start();
#if defined(G22_FPB) || defined(G23_FPB) || defined(G24_FPB)
    R_Config_ITL013_SetCompareMatch(0x20, 0x0);
    R_Config_ITL013_Start();
#endif // defined(G24_FPB)

/* Power Off unused Peripheral */
/* SERIAL ARRAY UNIT (SAU) */
#if !defined(UART_CHANNEL) && (UART1_CHANNEL == 0) && !defined(CSI_CHANNEL)
    R_SAU0_Set_Reset();
    R_SAU0_Set_PowerOff();
#endif
#if !defined(UART1_CHANNEL) || UART1_CHANNEL == 0
    R_Config_UART1_Stop();
#endif
#if !defined(UART2_CHANNEL) || (UART2_CHANNEL == 0)
    R_SAU1_Set_Reset();
    R_SAU1_Set_PowerOff();
#endif

/* IICA UNIT(IICA*) */
#if !defined(IIC_CHANNEL0) | (IIC_CHANNEL0!=0)
    R_IICA0_Set_Reset();
    R_IICA0_Set_PowerOff();
#endif
#if (IIC_CHANNEL1!=1)
//    R_IICA1_Set_Reset();
//    R_IICA1_Set_PowerOff();
#endif

/* RTC */
#if defined(G22_FPB) || defined(G23_FPB) || defined(G24_FPB)
    #if !defined(RTC_ON) | (RTC_ON!=0)
        R_RTC_Set_PowerOff();
    #endif
#endif // defined(G24_FPB)

#if WDT_EN==1
    R_Config_WDT_Start();
#endif
//    R_Config_TRD0_TRD1_Start();

    setPowerManagementMode(PM_NORMAL_MODE);

    SOE0 &= 0xf3;
    SO0 |= 0x08;
#if defined(G22_FPB)
    /* P26,P25,P24,P23,P22 */
    PMCA2 &= 0x83;  /* 0 : Use Digital IO */
    PMCT2 &= 0x83;  /* 0 : Use Digital IO */
    PM2 &= 0x83;    /* 0 : Use Output Mode */
    P2 &= 0x83;     /* 0 : Use Output Low  */
    /* P30 */
    PMCT3 &= 0xFE;  /* 0 : Use Digital IO */
    PM3 &= 0xFE;    /* 0 : Use Output Mode */
    P3 &= 0xFE;     /* 0 : Use Output Low  */
#endif

/******************************************************/
    
    setup();
    
    for (;;) {
        loop();
    }
    return 0;
}

/**
 * Finish Function
 *
 * RLduino78 Framework finish
 *  *
 * @return None
 *
 * @attention No return
 ***************************************************************************/
#include <stdlib.h>

void abort(void)
{
    for(;;);
}

void exit(int) __attribute__ ((weak, alias ("abort")));

#include <exception>

