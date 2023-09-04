/* Generated configuration header file - do not edit */
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_bsp_config_reference.h
* H/W Platform : GENERIC_RL78_G24
* Description  :
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 29.07.2022 1.60     First Release

***********************************************************************************************************************/

#ifndef R_BSP_CONFIG_REF_HEADER_FILE
#define R_BSP_CONFIG_REF_HEADER_FILE
/*************************************************
 * MCU information
 *************************************************/
/*
 R 7 F 101G L G 3 xxx C FB #AA0
 | | |  |   | | |  |  |  |  |__not used                   Packaging specification
 | | |  |   | | |  |  |  |_____not used                   Package type
 | | |  |   | | |  |  |________not used                   Fields of application
 | | |  |   | | |  |___________not used                   ROM number(Omitted for blank products)
 | | |  |   | | |______________not used                   Ambient operating temperature range
 | | |  |   | |________________BSP_CFG_MCU_PART_ROM_SIZE  ROM capacity
 | | |  |   |__________________BSP_CFG_MCU_PART_PIN_NUM   Pin count
 | | |  |______________________not used                   RL78/G24
 | | |_________________________BSP_CFG_MCU_PART_ROM_TYPE  Device type
 | |___________________________not used                   Renesas MCU
 |_____________________________not used                   Renesas semiconductor product
*/

/* ROM capacity
 E = 64(KB) : 0x0
 G = 128    : 0x1
*/
#define BSP_CFG_MCU_PART_ROM_SIZE (0x1) /* Generated value. Do not edit this manually */

/* Pin count
 6 = 20-pin  : 0x0
 7 = 24-pin  : 0x1
 8 = 25-pin  : 0x2
 A = 30-pin  : 0x3
 B = 32-pin  : 0x4
 E = 40-pin  : 0x5
 F = 44-pin  : 0x6
 G = 48-pin  : 0x7
 J = 52-pin  : 0x8
 L = 64-pin  : 0x9
*/
#define BSP_CFG_MCU_PART_PIN_NUM (0x9) /* Generated value. Do not edit this manually */

/* group
 101G = RL78/G24 : (true)
*/
#define BSP_CFG_MCU_PART_HAS_DATA_FLASH (true)

/* Device type
 F = Flash memory : 0
*/
#define BSP_CFG_MCU_PART_ROM_TYPE (0)

#if defined(__ICCRL78__)
/* Option byte setting(When using IAR) */
#define BSP_CFG_OPTBYTE0_VALUE (0xEFU) /* Generated value. Do not edit this manually */
#define BSP_CFG_OPTBYTE1_VALUE (0x3AU) /* Generated value. Do not edit this manually */
#define BSP_CFG_OPTBYTE2_VALUE (0xF0U) /* Generated value. Do not edit this manually */
#define BSP_CFG_OPTBYTE3_VALUE (0x85U) /* Generated value. Do not edit this manually */
/* Security ID Codes for On-Chip Debugging setting(When using IAR) */
#define BSP_CFG_SECUID0_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID1_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID2_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID3_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID4_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID5_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID6_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID7_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID8_VALUE (0x00U) /* Generated value. Do not edit this manually */
#define BSP_CFG_SECUID9_VALUE (0x00U) /* Generated value. Do not edit this manually */
#endif

/*************************************************
 * Pin assignment setting
 *************************************************/
/* Peripheral I/O redirection register 0(PIOR0-PIOR00)
     52/48/44/40/32/30/25/24/20-pin
0 : INTP1 - These functions are not available for use. Set this bit to 0(default value).
    INTP2 - These functions are not available for use. Set this bit to 0(default value).
    INTP3 - These functions are not available for use. Set this bit to 0(default value).
    INTP4 - These functions are not available for use. Set this bit to 0(default value).
    INTP8 - These functions are not available for use. Set this bit to 0(default value).
    INTP9 - These functions are not available for use. Set this bit to 0(default value).
1 : INTP1 - These functions are not available for use. Set this bit to 0(default value).
    INTP2 - These functions are not available for use. Set this bit to 0(default value).
    INTP3 - These functions are not available for use. Set this bit to 0(default value).
    INTP4 - These functions are not available for use. Set this bit to 0(default value).
    INTP8 - These functions are not available for use. Set this bit to 0(default value).
    INTP9 - These functions are not available for use. Set this bit to 0(default value).

     64-pin
0 : INTP1 - P50
    INTP2 - P51
    INTP3 - P30
    INTP4 - P31
    INTP8 - P74
    INTP9 - P75
1 : INTP1 - P52
    INTP2 - P53
    INTP3 - P54
    INTP4 - P55
    INTP8 - P42
    INTP9 - P43
*/
#define BSP_CFG_PIOR00 (1) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR0-PIOR01)
     20-pin
0 : INTP10 - -
    INTP11 - -
    TxD0   - -
    RxD0   - -
    SCL00  - -
    SDA00  - -
    SI00   - -
    SO00   - -
    SCK00  - -
1 : INTP10 - -
    INTP11 - -
    TxD0   - -
    RxD0   - -
    SCL00  - -
    SDA00  - -
    SI00   - -
    SO00   - -
    SCK00  - -

     25/24-pin
0 : INTP10 - -
    INTP11 - -
    TxD0   - -
    RxD0   - -
    SCL00  - -
    SDA00  - -
    SI00   - -
    SO00   - -
    SCK00  - -
1 : INTP10 - -
    INTP11 - -
    TxD0   - P17
    RxD0   - P16
    SCL00  - -
    SDA00  - -
    SI00   - -
    SO00   - -
    SCK00  - -

     48/44/40/32/30-pin
0 : INTP10 - -
    INTP11 - -
    TxD0   - P51
    RxD0   - P50
    SCL00  - P30
    SDA00  - P50
    SI00   - P50
    SO00   - P51
    SCK00  - P30
1 : INTP10 - -
    INTP11 - -
    TxD0   - P17
    RxD0   - P16
    SCL00  - -
    SDA00  - -
    SI00   - -
    SO00   - -
    SCK00  - -

     52-pin
0 : INTP10 - P76
    INTP11 - P77
    TxD0   - P51
    RxD0   - P50
    SCL00  - P30
    SDA00  - P50
    SI00   - P50
    SO00   - P51
    SCK00  - P30
1 : INTP10 - -
    INTP11 - -
    TxD0   - P17
    RxD0   - P16
    SCL00  - -
    SDA00  - -
    SI00   - -
    SO00   - -
    SCK00  - -

     64-pin
0 : INTP10 - P76
    INTP11 - P77
    TxD0   - P51
    RxD0   - P50
    SCL00  - P30
    SDA00  - P50
    SI00   - P50
    SO00   - P51
    SCK00  - P30
1 : INTP10 - P05
    INTP11 -  P06
    TxD0   - P17
    RxD0   - P16
    SCL00  - -
    SDA00  - -
    SI00   - P16
    SO00   - P17
    SCK00  - P55
*/
#define BSP_CFG_PIOR01 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR0-PIOR02)
     25/24/20-pin
0 : SCLA0 - -
    SDAA0 - -
1 : SCLA0 - P14
    SDAA0 - P15

     64/52/48/44/40/32/30-pin
0 : SCLA0 - P60
    SDAA0 - P61
1 : SCLA0 - P14
    SDAA0 - P15
*/
#define BSP_CFG_PIOR02 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR0-PIOR03)
     44/40/32/30/25/24/20-pin
0 : PCLBUZ0 - These functions are not available for use. Set this bit to 0(default value).
1 : PCLBUZ0 - These functions are not available for use. Set this bit to 0(default value).

     64/52/48-pin
0 : PCLBUZ0 - P140
1 : PCLBUZ0 - P31
*/
#define BSP_CFG_PIOR03 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR0-PIOR04)
     52/48/44/40/32/30/25/24/20-pin
0 : PCLBUZ1 - These functions are not available for use. Set this bit to 0(default value).
    INTP5   - These functions are not available for use. Set this bit to 0(default value).
1 : PCLBUZ1 - These functions are not available for use. Set this bit to 0(default value).
    INTP5   - These functions are not available for use. Set this bit to 0(default value).

     64-pin
0 : PCLBUZ1 - P141
    INTP5   - P16
1 : PCLBUZ1 - P55
    INTP5   - P12
*/
#define BSP_CFG_PIOR04 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR0-PIOR05)
    25/24/20-pin
0 : TxD1 - These functions are not available for use. Set this bit to 0(default value).
    RxD1 - These functions are not available for use. Set this bit to 0(default value).
1 : TxD1 - These functions are not available for use. Set this bit to 0(default value).
    RxD1 - These functions are not available for use. Set this bit to 0(default value).

     32/30-pin
 0 : TxD1 - P00
     RxD1 - P01
 1 : TxD1 - P30
     RxD1 - P31

     48/44/40-pin
 0 : TxD1 - P00
     RxD1 - P01
 1 : TxD1 - P72
     RxD1 - P73

     64/52-pin
 0 : TxD1 - P02
     RxD1 - P03
 1 : TxD1 - P72
     RxD1 - P73
*/
#define BSP_CFG_PIOR05 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR0-PIOR06)
    44/40/32/30/25/24/20-pin
0 : INTP6  - -
    INTP7  - -
    TxD0_1 - These functions are not available for use. Set this bit to 0(default value).
    RxD0_1 - These functions are not available for use. Set this bit to 0(default value).
1 : INTP6  - P20
    INTP7  - P21
    TxD0_1 - These functions are not available for use. Set this bit to 0(default value).
    RxD0_1 - These functions are not available for use. Set this bit to 0(default value).

     52/48-pin
0 : INTP6  - P140
    INTP7  - -
    TxD0_1 - -
    RxD0_1 - -
1 : INTP6  - P20
    INTP7  - P21
    TxD0_1 - P12
    RxD0_1 - P11

     64-pin
0 : INTP6  - P140
    INTP7  - P141
    TxD0_1 - -
    RxD0_1 - -
1 : INTP6  - P20
    INTP7  - P21
    TxD0_1 - P12
    RxD0_1 - P11
*/
#define BSP_CFG_PIOR06 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR0-PIOR07)
    48/44/40/32/30/25/24/20-pin
0 : TxD2  - P13
    RxD2  - P14
    SCL20 - P15
    SDA20 - P14
    SI20  - P14
    SO20  - P13
    SCK20 - P15
1 : TxD2  - P10
    RxD2  - P11
    SCL20 - -
    SDA20 - -
    SI20  - -
    SO20  - -
    SCK20 - -

    64/52-pin
0 : TxD2  - P13
    RxD2  - P14
    SCL20 - P15
    SDA20 - P14
    SI20  - P14
    SO20  - P13
    SCK20 - P15
0 : TxD2  - P77
    RxD2  - P76
    SCL20 - -
    SDA20 - -
    SI20  - -
    SO20  - -
    SCK20 - -
*/
#define BSP_CFG_PIOR07 (1) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register 0(PIOR1-PIOR11/PIOR10)
    25/24/20-pin
 00 : TRJIO0 - P01
 01 : -
 10 : -
 11 : -

    40/32/30-pin
 00 : TRJIO0 - P01
 01 : TRJIO0 - P31
 10 : -
 11 : -

    52/48/44/-pin
 00 : TRJIO0 - P01
 01 : TRJIO0 - P31
 10 : TRJIO0 - P41
 11 : -

    64-pin
 00 : TRJIO0 - P01
 01 : TRJIO0 - P31
 10 : TRJIO0 - P41
 11 : TRJIO0 - P06
*/
#define BSP_CFG_PIOR11 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR10 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR1-PIOR13/PIOR12)
    25/24/20-pin
 00 : TRJO0 - -
 01 : TRJO0 - -
 10 : TRJO0 - P00
 11 : setting prohibit

    64/52/48/44/40/32/30-pin
 00 : TRJO0 - P30
 01 : TRJO0 - P50
 10 : TRJO0 - P00
 11 : setting prohibit
*/
#define BSP_CFG_PIOR13 (0) /* Generated value. Do not edit this manually */
#define BSP_CFG_PIOR12 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register 0(PIOR2-PIOR20)
    20-pin
 0 : TRGIOA - These functions are not available for use. Set this bit to 0(default value).
     TRGIOB - These functions are not available for use. Set this bit to 0(default value).
 1 : TRGIOA - These functions are not available for use. Set this bit to 0(default value).
     TRGIOB - These functions are not available for use. Set this bit to 0(default value).

    25/24-pin
 0 : TRGIOA - -
     TRGIOB - -
 1 : TRGIOA - P17
     TRGIOB - P16

    64/52/48/44/40/32/30-pin
 0 : TRGIOA - P50
     TRGIOB - P51
 1 : TRGIOA - P17
     TRGIOB - P16
*/
#define BSP_CFG_PIOR20 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR2-PIOR21)
    30/25/24/20-pin
 0 : TRDIOB0 - These functions are not available for use. Set this bit to 0(default value).
 1 : TRDIOB0 - These functions are not available for use. Set this bit to 0(default value).

    64/52/48/44/40/32-pin
 0 : TRDIOB0 - P15
 1 : TRDIOB0 - P70
*/
#define BSP_CFG_PIOR21 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR2-PIOR22)
    20-pin
 0 : TRDIOA1 - These functions are not available for use. Set this bit to 0(default value).
 1 : TRDIOA1 - These functions are not available for use. Set this bit to 0(default value).

    32/30/25/24-pin
 0 : TRDIOA1 - P13
 1 : TRDIOA1 - P16

    64/52/48/44/40-pin
 0 : TRDIOA1 - P13
 1 : TRDIOA1 - P72
*/
#define BSP_CFG_PIOR22 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR2-PIOR23)
    25/24/20-pin
 0 : TRDIOB1 - These functions are not available for use. Set this bit to 0(default value).
 1 : TRDIOB1 - These functions are not available for use. Set this bit to 0(default value).

    44/40/32/30-pin
 0 : TRDIOB1 - P12
 1 : TRDIOB1 - P30

    64/52/48-pin
 0 : TRDIOB1 - P12
 1 : TRDIOB1 - P74
*/
#define BSP_CFG_PIOR23 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR2-PIOR24)
    25/24/20-pin
 0 : TRDIOC1 - These functions are not available for use. Set this bit to 0(default value).
 1 : TRDIOC1 - These functions are not available for use. Set this bit to 0(default value).

    32/30-pin
 0 : TRDIOC1 - P11
 1 : TRDIOC1 - P50

    64/52/48/44/40-pin
 0 : TRDIOC1 - P11
 1 : TRDIOC1 - P73
*/
#define BSP_CFG_PIOR24 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR2-PIOR25)
    25/24/20-pin
 0 : TRDIOD1 - These functions are not available for use. Set this bit to 0(default value).
 1 : TRDIOD1 - These functions are not available for use. Set this bit to 0(default value).

    44/40/32/30-pin
 0 : TRDIOD1 - P10
 1 : TRDIOD1 - P51

    64/52/48-pin
 0 : TRDIOD1 - P10
 1 : TRDIOD1 - P75
*/
#define BSP_CFG_PIOR25 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR2-PIOR26)
    20-pin
 0 : TRDIOD0 - These functions are not available for use. Set this bit to 0(default value).
 1 : TRDIOD0 - These functions are not available for use. Set this bit to 0(default value).

    32/30/25/24-pin
 0 : TRDIOD0 - P14
 1 : TRDIOD0 - P17

    64/52/48/44/40-pin
 0 : TRDIOD0 - P14
 1 : TRDIOD0 - P71
*/
#define BSP_CFG_PIOR26 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR2-PIOR27)
    20-pin
 0 : TRDIOC0 - -
 1 : TRDIOC0 - P13

    64/52/48/44/40/32/30/25/24-pin
 0 : TRDIOC0 - P16
 1 : TRDIOC0 - P13
*/
#define BSP_CFG_PIOR27 (0) /* Generated value. Do not edit this manually */

/* Peripheral I/O redirection register 0(PIOR3-PIOR30)
    25/24/20-pin
 0 : VCOUT0 - These functions are not available for use. Set this bit to 0(default value).
 1 : VCOUT0 - These functions are not available for use. Set this bit to 0(default value).

    64/52/48/44/40/32/30-pin
 0 : VCOUT0 - P14
 1 : VCOUT0 - P31
*/
#define BSP_CFG_PIOR30 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR3-PIOR31)
    25/24/20-pin
 0 : VCOUT1 - These functions are not available for use. Set this bit to 0(default value).
 1 : VCOUT1 - These functions are not available for use. Set this bit to 0(default value).

    64/52/48/44/40/32/30-pin
 0 : VCOUT1 - P15
 1 : VCOUT1 - P30
*/
#define BSP_CFG_PIOR31 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR3-PIOR32)
    25/24/20-pin
 0 : VCOUT2 - These functions are not available for use. Set this bit to 0(default value).
 1 : VCOUT2 - These functions are not available for use. Set this bit to 0(default value).

    64/52/48/44/40/32/30-pin
 0 : VCOUT2 - P10
 1 : VCOUT2 - P51
*/
#define BSP_CFG_PIOR32 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR3-PIOR33)
    25/24/20-pin
 0 : VCOUT3 - These functions are not available for use. Set this bit to 0(default value).
 1 : VCOUT3 - These functions are not available for use. Set this bit to 0(default value).

    64/52/48/44/40/32/30-pin
 0 : VCOUT3 - P11
 1 : VCOUT3 - P50
*/
#define BSP_CFG_PIOR33 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR3-PIOR34)
    25/24/20-pin
 0 : TI03 - -
     TO03 - -
 1 : TI03 - P11
     TO03 - P11

    64/52/48/44/40/32/30-pin
 0 : TI03 - P31
     TO03 - P31
 1 : TI03 - P50
     TO03 - P11
*/
#define BSP_CFG_PIOR34 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR3-PIOR35)
    20-pin
 0 : TI01/TO01 - -
 1 : TI01/TO01 - P15

    32/30/25/24-pin
 0 : TI01/TO01 - P16
 1 : TI01/TO01 - P15

    64/52/48/44/40-pin
 0 : TI01/TO01 - P16
 1 : TI01/TO01 - P71
*/
#define BSP_CFG_PIOR35 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR3-PIOR36)
    20-pin
 0 : TI00      - P00
     TO00      - P01
     TI02/TO02 - -
 1 : TI00      - P01
     TO00      - P122
     TI02/TO02 - P120

    32/30/25/24-pin
 0 : TI00      - P00
     TO00      - P01
     TI02/TO02 - P17
 1 : TI00      - P01
     TO00      - P122
     TI02/TO02 - P120

    48/44/40-pin
 0 : TI00      - P00
     TO00      - P01
     TI02/TO02 - P17
 1 : TI00      - P01
     TO00      - P122
     TI02/TO02 - P121

    64/52-pin
 0 : TI00      - P00
     TO00      - P01
     TI02/TO02 - P17
 1 : TI00      - P03
     TO00      - P122
     TI02/TO02 - P121
*/
#define BSP_CFG_PIOR36 (0) /* Generated value. Do not edit this manually */
/* Peripheral I/O redirection register 0(PIOR3-PIOR37)
    25/24/20-pin
 0 :  DALITxD0 - -
      DALIRxD0 - -
 1 :  DALITxD0 - P00
      DALIRxD0 - P01

    48/44/40/32/30-pin
 0 :  DALITxD0 - P51
      DALIRxD0 - P50
 1 :  DALITxD0 - P00
      DALIRxD0 - P01

    64/52-pin
 0 :  DALITxD0 - P51
      DALIRxD0 - P50
 1 :  DALITxD0 - P02
      DALIRxD0 - P03
*/
#define BSP_CFG_PIOR37 (0) /* Generated value. Do not edit this manually */

/***********************************************************
 * Invalid memory access detection control register (IAWCTL)
 ***********************************************************/
/* Control of invalid memory access detection(IAWEN)
 0 : Disable the detection of invalid memory accesses.
 1 : Enable the detection of invalid memory accesses.
*/
#define BSP_CFG_INVALID_MEMORY_ACCESS_DETECTION_ENABLE (0)

/* RAM guard space(GRAM0-1)
 0 : Disabled. RAM can be written to.
 1 : The 128 bytes of space starting at the start address in the RAM.
 2 : The 256 bytes of space starting at the start address in the RAM.
 3 : The 512 bytes of space starting at the start address in the RAM.
*/
#define BSP_CFG_RAM_GUARD_FUNC (0)

/* Guard of control registers of port function(GPORT)
 0 : Disabled. Control registers of the port function can be read from or written to.
 1 : Enabled. Writing to control registers of the port function is disabled. Reading is enabled.
 [Guarded SFRs] PMxx, PUxx, PIMxx, POMxx, PMCAxx, PDIDISxx, CCDE, CCSx
 Note:Pxx(Port register) is not guarded.
*/
#define BSP_CFG_PORT_FUNCTION_GUARD (0)

/* Guard of registers of interrupt function(GINT)
 0 : Disabled. Registers of the interrupt function can be read from or written to.
 1 : Enabled. Writing to registers of the interrupt function is disabled. Reading is enabled.
 [Guarded SFRs] IFxx, MKxx, PRxx, EGPx, EGNx
*/
#define BSP_CFG_INT_FUNCTION_GUARD (0)

/* Guard of control registers of clock control function, voltage detector,
   and RAM parity error detection function(GCSC)
 0 : Disabled. Control registers of the clock control function, voltage detector
     and RAM parity error detection function can be read from or written to.
 1 : Enabled. Writing to control registers of the clock control function, voltage detector
     and RAM parity error detection function is disabled. Reading is enabled.
 [Guarded SFRs] CMC, CSC, OSTS, CKC, PERx, OSMC, LVIM, LVIS, RPECTL,
 CKSEL, PRRx, MOCODIV, WKUPMD, DSCCTL, MCKC, HSCLKSEL, PFBER
*/
#define BSP_CFG_CHIP_STATE_CTRL_GUARD (0)

/*************************************************
 * Data flash
 *************************************************/
/* Data flash access control(DFLEN)
 0 : Access to the data flash memory area and extra area is disabled.
 1 : Access to the data flash memory area and extra area is enabled.
*/
#define BSP_CFG_DATA_FLASH_ACCESS_ENABLE (0)

/*************************************************
 * Definition for switching functions
 *************************************************/

/* Start up select
 0 : Enable BSP startup program.
 1 : Disable BSP startup program.(e.g. Using user startup program.)
*/
#define BSP_CFG_STARTUP_DISABLE (0)

/* Initialization of peripheral functions by Code Generator/Smart Configurator
 0 : Disable initialization of peripheral functions by Code Generator/Smart Configurator.
 1 : Enable initialization of peripheral functions by Code Generator/Smart Configurator.
*/
#define BSP_CFG_CONFIGURATOR_SELECT (1)

/* Version number of Smart Configurator.
   This macro definitions is updated by Smart Configurator.
   If you are using e2studio, set the following values.
   2021-04  : 1001
   2021-07  : 1010
   2021-10  : 1010
   2022-01  : 1030
   If you are using Smart the standalone version of Smart Configurator,
   set the following values.
   v1.0.1   : 1001
   v1.1.0   : 1010
   v1.3.0   : 1030
 */
#define BSP_CFG_CONFIGURATOR_VERSION (1070) /* Generated value. Do not edit this manually */

/* API function disable(R_BSP_StartClock, R_BSP_StopClock)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_CLOCK_OPERATION_API_FUNCTIONS_DISABLE (0)

/* API function disable(R_BSP_GetFclkFreqHz)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_GET_FREQ_API_FUNCTIONS_DISABLE (0)

/* API function disable(R_BSP_SetClockSource)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_SET_CLOCK_SOURCE_API_FUNCTIONS_DISABLE (0)

/* API function disable(R_BSP_ChangeClockSetting)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_CHANGE_CLOCK_SETTING_API_FUNCTIONS_DISABLE (0)

/* API function disable(R_BSP_SoftwareDelay)
 0 : Enable API functions
 1 : Disable API functions
*/
#define BSP_CFG_SOFTWARE_DELAY_API_FUNCTIONS_DISABLE (0)

/* Parameter check enable
 0 : Disable parameter check.
 1 : Enable parameter check.
*/
#define BSP_CFG_PARAM_CHECKING_ENABLE (1)

/*************************************************
 * Clock settings
 *************************************************/
/* High-speed system clock frequency(fMX)
   Clock operation mode control register(CMC)
   (Products with 20 to 32 pins)
    XTSEL,EXCLK,OSCSEL
   (Products with 40 to 64 pins)
    EXCLK/OSCSEL
 0 : Port
 1 : fX(Crystal/ceramic resonator connection)
 2 : fEX(External clock input)
*/
#define BSP_CFG_HISYSCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* High-speed system clock frequency(fMX)
   Clock operation status control register(CSC)
   MSTOP
 (X1 oscillation mode)
  0 : X1 oscillator operating
  1 : X1 oscillator stopped
 (External clock input mode)
  0 : External clock from EXCLK pin is valid
  1 : External clock from EXCLK pin is invalid
 (Port mode)
  0 : I/O Port
  1 : I/O Port
*/
#define BSP_CFG_HISYSCLK_OPERATION (1) /* Generated value. Do not edit this manually */

/* Subsystem clock oscillator clock frequency(fSX)
   Clock operation mode control register(CMC)
   (Products with 20 to 32 pins)
    XTSEL,EXCLKS,OSCSELS
   (Products with 40 to 64 pins)
    EXCLKS/OSCSELS
 0 : Input Port
 1 : fXT(Crystal resonator connection)
 2 : fEXS(External clock input)
*/
#define BSP_CFG_SUBCLK_SOURCE (1) /* Generated value. Do not edit this manually */

/* Subsystem clock oscillator clock frequency(fSX)
   Clock operation status control register(CSC)
   XTSTOP
 (XT1 oscillation mode)
  0 : XT1 oscillator operating
  1 : XT1 oscillator stopped
 (External clock input mode)
  0 : External clock from EXCLKS pin is valid
  1 : External clock from EXCLKS pin is invalid
 (Port mode)
  0 : Input port
  1 : Input port
*/
#define BSP_CFG_SUBCLK_OPERATION (0) /* Generated value. Do not edit this manually */

/* Middle-speed on-chip oscillator clock frequency(fIM)
   Clock operation status control register(CSC)
   MIOEN
 0 : Middle-speed on-chip oscillator stopped
 1 : Middle-speed on-chip oscillator operating
*/
#define BSP_CFG_MOCO_OPERATION (0) /* Generated value. Do not edit this manually */

/* Main on-chip oscillator clock(fOCO) operation control
   System clock control register(CKC)
   MCM1
 0 : High-speed on-chip oscillator clock
 1 : Middle-speed on-chip oscillator clock
*/
#define BSP_CFG_OCOCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Main system clock(fMAIN) operation control
   System clock control register(CKC)
   MCM0
 0 : Selects the main on-chip oscillator clock(fOCO) as the main system clock(fMAIN)
 1 : Selects the high-speed system clock(fMX) as the main system clock(fMAIN)
*/
#define BSP_CFG_MAINCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Selection of the subsystem clock X or low-speed on-chip oscillator clock
   Subsystem clock select register(CKSEL)
   SELLOSC
 0 : Subsystem clock X
 1 : Low-speed on-chip oscillator clock
*/
#define BSP_CFG_SUBSYSCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Selection of CPU/peripheral hardware clock(fCLK)
   System clock control register(CKC)
   CSS
 0 : Main system clock(fMAIN)
 1 : Subsystem clock(fSUB)
*/
#define BSP_CFG_FCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* XT1 oscillator oscillation mode selection
   Clock operation mode control register(CMC)
   AMPHS1,AMPHS0
 0 : Low power consumption oscillation 1(default)
 1 : Normal oscillation
 2 : Low power consumption oscillation 2
 3 : Low power consumption oscillation 3
*/
#define BSP_CFG_XT1_OSCMODE (0) /* Generated value. Do not edit this manually */

/* Input clock frequency in Hz(High-speed system clock(X1))
*/
#define BSP_CFG_FMX_HZ (20000000)
/* Control of X1 clock oscillation frequency
   Clock operation mode control register(CMC)
   AMPH
 0 : 1 MHz <= fX <= 10 MHz
 1 : 10 MHz < fX <= 20 MHz
 Set the value corresponding to the setting of BSP_CFG_FMX_HZ
*/

/* X1 clock oscillation stabilization time selection
   Oscillation stabilization time select register(OSTS)
   OSTS2,OSTS1,OSTS0
  0 : (2^8)/fX  (fX = 10MHz : 25.6us, fX = 20MHz : 12.8us)
  1 : (2^9)/fX  (fX = 10MHz : 51.2us, fX = 20MHz : 25.6us)
  2 : (2^10)/fX (fX = 10MHz : 102us,  fX = 20MHz : 51.2us)
  3 : (2^11)/fX (fX = 10MHz : 204us,  fX = 20MHz : 102us)
  4 : (2^13)/fX (fX = 10MHz : 819us,  fX = 20MHz : 409us)
  5 : (2^15)/fX (fX = 10MHz : 3.27ms, fX = 20MHz : 1.63ms)
  6 : (2^17)/fX (fX = 10MHz : 13.1ms, fX = 20MHz : 6.55ms)
  7 : (2^18)/fX (fX = 10MHz : 26.2ms, fX = 20MHz : 13.1ms)
*/
#define BSP_CFG_X1_WAIT_TIME_SEL (0)

/* Setting in STOP mode or in HALT mode while the CPU is operating with the subsystem clock
   Subsystem clock supply mode control register(OSMC)
   RTCLPC
  0 : Enables supply of the subsystem clock to peripheral functions.
  1 : Stops supply of the subsystem clock to peripheral functions other than the realtime clock.
*/
#define BSP_CFG_ALLOW_FSUB_IN_STOPHALT (0) /* Generated value. Do not edit this manually */

/* Selection of operation clock for the realtime clock, 32-bit interval timer and
   clock output/buzzer output controller
   Subsystem clock supply mode control register(OSMC)
   WUTMMCK0
 0 : Subsystem clock X
 1 : Low-speed on-chip oscillator clock
*/
#define BSP_CFG_RTC_OUT_CLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Selection of high-speed on-chip oscillator clock frequency
   High-Speed On-Chip Oscillator Frequency Select Register(HOCODIV)
   HOCODIV2,HOCODIV1,HOCODIV0

(FIHSEL=0)
 (FRQSEL4 = 0, FRQSEL3 = 0)
  0 : fIH = 24 MHz
  1 : fIH = 12 MHz
  2 : fIH =  6 MHz
  3 : fIH =  3 MHz
  Other than above : Setting prohibited
 (FRQSEL4 = 0, FRQSEL3 = 1)
  0 : fIH = 32 MHz
  1 : fIH = 16 MHz
  2 : fIH = 8 MHz
  3 : fIH = 4 MHz
  4 : fIH = 2 MHz
  5 : fIH = 1 MHz
  Other than above : Setting prohibited
 (FRQSEL4 = 1, FRQSEL3 = 0)
  0 : fIH = 24 MHz, fHOCO = 48MHz
  1 : fIH = 12 MHz, fHOCO = 24MHz
  2 : fIH = 6 MHz,  fHOCO = 12MHz
  3 : fIH = 3 MHz,  fHOCO = 6MHz
  Other than above : Setting prohibited
 (FRQSEL4 = 1, FRQSEL3 = 1)
  0 : fIH = 32 MHz, fHOCO = 64MHz
  1 : fIH = 16 MHz, fHOCO = 32MHz
  2 : fIH = 8 MHz,  fHOCO = 16MHz
  3 : fIH = 4 MHz,  fHOCO = 8MHz
  4 : fIH =  2 MHz, fHOCO = 4MHz
  5 : fIH =  1 MHz, fHOCO = 2MHz
  Other than above : Setting prohibited

(FIHSEL=1)
 (FRQSEL4 = 1, FRQSEL3 = 0)
  0 : fIH = 48 MHz, fHOCO = 48MHz
  Other than above : Setting prohibited
*/
#define BSP_CFG_HOCO_DIVIDE (0) /* Generated value. Do not edit this manually */

/* Setting for starting the high-speed on-chip oscillator at the times of release from STOP mode
   and of transitions to SNOOZE mode
   Standby mode release setting register(WKUPMD)
   FWKUP
 0 : Starting of the high-speed on-chip oscillator is at normal speed.
 1 : Starting of the high-speed on-chip oscillator is at high speed.
*/
#define BSP_CFG_WAKEUP_MODE (0) /* Generated value. Do not edit this manually */

/* Selection of fIH
   High-speed clock select register(HSCLKSEL)
   FIHSEL
 (FRQSEL4 = 0, FRQSEL3 = x)
   0 : fIH = fHOCO
   Other than above : Setting prohibited
 (FRQSEL4 = 1, FRQSEL3 = 0)
   0 : fIH = fHOCO/2
   1 : fIH = fHOCO
 (FRQSEL4 = 1, FRQSEL3 = 1)
   0 : fIH = fHOCO
   Other than above : Setting prohibited
*/
#define BSP_CFG_FIH_SEL (1) /* Generated value. Do not edit this manually */

/* Control by the prefetch buffer enable register(PFBER)
   Prefetch buffer enable register(PFBER)
   PFBE
 0 : Disables the prefetch buffer.
 1 : Enables the prefetch buffer.
*/
#define BSP_CFG_PFB_ENABLE (1) /* Generated value. Do not edit this manually */

/* Selection of flash operation mode
   Flash operating mode select register(FLMODE)
   MODE1, MODE0
 0 : LP(low-power main) mode
     (Selectable from LS(low-speed main) mode with 1 MHz <= fCLK <= 2 MHz)
 1 : LS(low-speed main) mode
     (Selectable from HS(high-speed main) mode with 1 MHz <= fCLK <= 24 MHz or
      from LP(low-power main) mode)
 2 : HS(high-speed main) mode
     (Selectable from LS(low-speed main) mode)
*/
#define BSP_CFG_FLASH_MODE (2) /* Generated value. Do not edit this manually */

/* High-speed system clock division selection
   High-speed system clock division register(MOSCDIV)
   MOSCDIV2,MOSCDIV1,MOSCDIV0
  0 : fMX   (fMX = 20MHz : 20MHz)
  1 : fMX/2 (fMX = 20MHz : 10MHz)
  2 : fMX/4 (fMX = 20MHz : 5MHz)
  3 : fMX/8 (fMX = 20MHz : 2.5MHz)
  4 : fMX/16(fMX = 20MHz : 1.25MHz)
  Other than above : Setting prohibited
*/
#define BSP_CFG_MOSC_DIVIDE (0) /* Generated value. Do not edit this manually */

/* Selection of middle-speed on-chip oscillator clock frequency
   Middle-speed on-chip oscillator frequency select register(MOCODIV)
   MOCODIV1,MOCODIV0
  0 : 4MHz
  1 : 2MHz
  2 : 1MHz
  Other than above : Setting prohibited
*/
#define BSP_CFG_MOCO_DIVIDE (0) /* Generated value. Do not edit this manually */

/* Control of PLL multiplication selection
   PLL Control Register(DSCCTL)
   DSCM4,DSCM3,DSCM2,DSCM1,PLLDIV0
 0 : Multiples the clock frequency by 16/2(8).  fPLL = 64MHz
 1 : Multiples the clock frequency by 24/2(12). fPLL = 96MHz
 Other than above : Setting prohibited
*/
#define BSP_CFG_PLL_MULTI (1) /* Generated value. Do not edit this manually */

/* Selection of the main system clock(fMAIN)
   Main clock control register(MCKC)
   CKSELR
 0 : On-chip oscillator clock(fOCO)/high-speed system clock(fMX)
 1 : PLL clock(fPLL)
*/
#define BSP_CFG_PLL_MODE (0) /* Generated value. Do not edit this manually */

/* Control of PLL oscillation and output
   PLL control register(DSCCTL)
   DSCON
 0 : The PLL is stopped.
 1 : The PLL is oscillating and producing a clock signal.
*/
#define BSP_CFG_PLLCLK_OPERATION (0) /* Generated value. Do not edit this manually */

/* Control of the PLL operating clock supply
   Peripheral clock control register(PCKC)
   PLLCK
 0 : Stops supply of the on-chip oscillator clock(fOCO)/high-speed system clock(fMX).
 1 : Enables supply of the on-chip oscillator clock(fOCO)/high-speed system clock(fMX)
*/
#define BSP_CFG_PLLCLK_SOURCE (0) /* Generated value. Do not edit this manually */

/* Division ratio selection bits of the main system clock(fMAIN)
   Main clock control register(MCKC)
   RDIV1, RDIV0
 0 : Frequency division by two (fMAIN = 48/32 MHz, fPLL = 96/64 MHz)
 1 : Frequency division by four (fMAIN = 24/16 MHz, fPLL = 96/64 MHz)
 Other than above : Setting prohibited
*/
#define BSP_CFG_FMAIN_DIVIDE (0)

/* Operation setting at initial setting */
/* Starts the high-speed on-chip oscillator at initialization
 0 : Stops the high-speed on-chip oscillator at initialization
 1 : Starts the high-speed on-chip oscillator at initialization
*/
#define BSP_CFG_FIH_START_ON_STARTUP (1) /* Generated value. Do not edit this manually */

/* This macro lets other modules no if a RTOS is being used.
   0 = RTOS is not used.
   1 = FreeRTOS is used.(This is not available.)
   2 = embOS is used.(This is not available.)
   3 = MicroC_OS is used.(This is not available.)
   4 = Renesas ITRON is used.
*/
#define BSP_CFG_RTOS_USED               (0)

/* Loop count using the main system clock. */
/* The loop count refers to a loop consisting of a "for" statement that executes a single NOP instruction. */
/* Subsystem clock oscillation stabilization wait time */
/* If the main system clock 48 MHz, 1050000 means 306 ms. */
#define BSP_CFG_SUBWAITTIME              (1050000U)

/* High-speed on-chip oscillator  clock oscillation stabilization wait time */
/* If the main system clock 48 MHz, 30 means 5.12 us. */
#define BSP_CFG_FIHWAITTIME              (30U)

/* Middle-speed on-chip oscillator clock oscillation stabilization wait time. */
/* If the main system clock 48 MHz, 6 means 1.14 us. */
#define BSP_CFG_FIMWAITTIME              (6U)

/*  Low-speed on-chip oscillator clock oscillation stabilization wait time */
/* If the main system clock 48 MHz, 500 means 83.5 us. */
#define BSP_CFG_FILWAITTIME              (500U)

/* PLL effective wait time */
/* If the main system clock 48 MHz, 6 means 1.14 us. */
#define BSP_CFG_PLLWAITTIME              (6U)

/* PLL lock-up wait time */
/* If the main system clock 48 MHz, 100 means 16.8 us. */
#define BSP_CFG_LOCKUP_WAIT_COUNT_SEL    (100U)

/* If the user would like to determine if a warm start reset has occurred, then they may enable one or more of the
   following callback definitions AND provide a call back function name for the respective callback
   function (to be defined by the user). Setting BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED = 1 will result
   in a callback to the user defined my_sw_warmstart_prec_function just prior to the initialization of the C
   runtime environment by bsp_init_system.
   Setting BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED = 1 will result in a callback to the user defined
   my_sw_warmstart_postc_function just after the initialization of the C runtime environment by bsp_init_hardware.
*/
#define BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED    (0)
#define BSP_CFG_USER_WARM_START_PRE_C_FUNCTION     my_sw_warmstart_prec_function

#define BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED    (0)
#define BSP_CFG_USER_WARM_START_POST_C_FUNCTION    my_sw_warmstart_postc_function

/* If the user sets the window open period of watchdog timer to 50%,
   set the following macro definition(BSP_CFG_WDT_REFRESH_ENABLE) to 2
   and specify the callback function name for each callback function(to be defined by the user).
   Setting BSP_CFG_WDT_REFRESH_ENABLE == 2 will result in a callback to the user defined
   my_sw_wdt_refresh_init_function just prior to the clock is set by bsp_init_system.
   In addition, a callback to the user defined my_sw_wdt_refresh_setting_function occurs
   during the oscillation stabilization wait time od the subsystem clock.
*/
#define BSP_CFG_WDT_REFRESH_ENABLE                   (0)
#define BSP_CFG_USER_WDT_REFRESH_INIT_FUNCTION       my_sw_wdt_refresh_init_function
#define BSP_CFG_USER_WDT_REFRESH_SETTING_FUNCTION    my_sw_wdt_refresh_setting_function

#endif /* R_BSP_CONFIG_REF_HEADER_FILE */
