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
* File Name    : iodefine_ext.h
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 29.07.2022 1.60     First Release.

***********************************************************************************************************************/

#ifndef __INTRINSIC_FUNCTIONS
#define __INTRINSIC_FUNCTIONS

#define DI() asm("di")
#define EI() asm("ei")
#define HALT() asm("halt")
#define NOP() asm("nop")
#define STOP() asm("stop")

#endif

#ifndef __IOREG_BIT_STRUCTURES
#define __IOREG_BIT_STRUCTURES
typedef struct {
	unsigned char no0 :1;
	unsigned char no1 :1;
	unsigned char no2 :1;
	unsigned char no3 :1;
	unsigned char no4 :1;
	unsigned char no5 :1;
	unsigned char no6 :1;
	unsigned char no7 :1;
} __BITS8;

typedef struct {
	unsigned short no0 :1;
	unsigned short no1 :1;
	unsigned short no2 :1;
	unsigned short no3 :1;
	unsigned short no4 :1;
	unsigned short no5 :1;
	unsigned short no6 :1;
	unsigned short no7 :1;
	unsigned short no8 :1;
	unsigned short no9 :1;
	unsigned short no10 :1;
	unsigned short no11 :1;
	unsigned short no12 :1;
	unsigned short no13 :1;
	unsigned short no14 :1;
	unsigned short no15 :1;
} __BITS16;

#endif

#ifndef IODEFINE_EXT_H
#define IODEFINE_EXT_H

/*
 IO Registers
 */
union un_adm2 {
	unsigned char adm2;
	__BITS8 BIT;
};
union un_adm3 {
	unsigned char adm3;
	__BITS8 BIT;
};
union un_adsctl {
	unsigned char adsctl;
	__BITS8 BIT;
};
union un_adintctl {
	unsigned char adintctl;
	__BITS8 BIT;
};
union un_adintst {
	unsigned char adintst;
	__BITS8 BIT;
};
union un_pu0 {
	unsigned char pu0;
	__BITS8 BIT;
};
union un_pu1 {
	unsigned char pu1;
	__BITS8 BIT;
};
union un_pu3 {
	unsigned char pu3;
	__BITS8 BIT;
};
union un_pu4 {
	unsigned char pu4;
	__BITS8 BIT;
};
union un_pu5 {
	unsigned char pu5;
	__BITS8 BIT;
};
union un_pu6 {
	unsigned char pu6;
	__BITS8 BIT;
};
union un_pu7 {
	unsigned char pu7;
	__BITS8 BIT;
};
union un_pu12 {
	unsigned char pu12;
	__BITS8 BIT;
};
union un_pu14 {
	unsigned char pu14;
	__BITS8 BIT;
};
union un_pim0 {
	unsigned char pim0;
	__BITS8 BIT;
};
union un_pim1 {
	unsigned char pim1;
	__BITS8 BIT;
};
union un_pim3 {
	unsigned char pim3;
	__BITS8 BIT;
};
union un_pim5 {
	unsigned char pim5;
	__BITS8 BIT;
};
union un_pim7 {
	unsigned char pim7;
	__BITS8 BIT;
};
union un_pom0 {
	unsigned char pom0;
	__BITS8 BIT;
};
union un_pom1 {
	unsigned char pom1;
	__BITS8 BIT;
};
union un_pom3 {
	unsigned char pom3;
	__BITS8 BIT;
};
union un_pom5 {
	unsigned char pom5;
	__BITS8 BIT;
};
union un_pom7 {
	unsigned char pom7;
	__BITS8 BIT;
};
union un_pmca0 {
	unsigned char pmca0;
	__BITS8 BIT;
};
union un_pmca1 {
	unsigned char pmca1;
	__BITS8 BIT;
};
union un_pmca2 {
	unsigned char pmca2;
	__BITS8 BIT;
};
union un_pmca12 {
	unsigned char pmca12;
	__BITS8 BIT;
};
union un_pmca14 {
	unsigned char pmca14;
	__BITS8 BIT;
};
union un_nfen0 {
	unsigned char nfen0;
	__BITS8 BIT;
};
union un_nfen1 {
	unsigned char nfen1;
	__BITS8 BIT;
};
union un_isc {
	unsigned char isc;
	__BITS8 BIT;
};
union un_ulbs {
	unsigned char ulbs;
	__BITS8 BIT;
};
union un_pms {
	unsigned char pms;
	__BITS8 BIT;
};
union un_pfber {
	unsigned char pfber;
	__BITS8 BIT;
};
union un_gdidis {
	unsigned char gdidis;
	__BITS8 BIT;
};
union un_dflctl {
	unsigned char dflctl;
	__BITS8 BIT;
};
union un_pckc {
	unsigned char pckc;
	__BITS8 BIT;
};
union un_flmode {
	unsigned char flmode;
	__BITS8 BIT;
};
union un_flmwrp {
	unsigned char flmwrp;
	__BITS8 BIT;
};
union un_fsse {
	unsigned char fsse;
	__BITS8 BIT;
};
union un_pfs {
	unsigned char pfs;
	__BITS8 BIT;
};
union un_per0 {
	unsigned char per0;
	__BITS8 BIT;
};
union un_prr0 {
	unsigned char prr0;
	__BITS8 BIT;
};
union un_osmc {
	unsigned char osmc;
	__BITS8 BIT;
};
union un_rpectl {
	unsigned char rpectl;
	__BITS8 BIT;
};
union un_porsr {
	unsigned char porsr;
	__BITS8 BIT;
};
union un_per1 {
	unsigned char per1;
	__BITS8 BIT;
};
union un_prr1 {
	unsigned char prr1;
	__BITS8 BIT;
};
union un_per2 {
	unsigned char per2;
	__BITS8 BIT;
};
union un_prr2 {
	unsigned char prr2;
	__BITS8 BIT;
};
union un_se0l {
	unsigned char se0l;
	__BITS8 BIT;
};
union un_ss0l {
	unsigned char ss0l;
	__BITS8 BIT;
};
union un_st0l {
	unsigned char st0l;
	__BITS8 BIT;
};
union un_soe0l {
	unsigned char soe0l;
	__BITS8 BIT;
};
union un_se1l {
	unsigned char se1l;
	__BITS8 BIT;
};
union un_ss1l {
	unsigned char ss1l;
	__BITS8 BIT;
};
union un_st1l {
	unsigned char st1l;
	__BITS8 BIT;
};
union un_soe1l {
	unsigned char soe1l;
	__BITS8 BIT;
};
union un_te0l {
	unsigned char te0l;
	__BITS8 BIT;
};
union un_ts0l {
	unsigned char ts0l;
	__BITS8 BIT;
};
union un_tt0l {
	unsigned char tt0l;
	__BITS8 BIT;
};
union un_toe0l {
	unsigned char toe0l;
	__BITS8 BIT;
};
union un_wkupmd {
	unsigned char wkupmd;
	__BITS8 BIT;
};
union un_lvdfclr {
	unsigned char lvdfclr;
	__BITS8 BIT;
};
union un_hsclksel {
	unsigned char hsclksel;
	__BITS8 BIT;
};
union un_rtcc0 {
	unsigned char rtcc0;
	__BITS8 BIT;
};
union un_rtcc1 {
	unsigned char rtcc1;
	__BITS8 BIT;
};
union un_iicctl00 {
	unsigned char iicctl00;
	__BITS8 BIT;
};
union un_iicctl01 {
	unsigned char iicctl01;
	__BITS8 BIT;
};
union un_trjioc0 {
	unsigned char trjioc0;
	__BITS8 BIT;
};
union un_trjmr0 {
	unsigned char trjmr0;
	__BITS8 BIT;
};
union un_trjisr0 {
	unsigned char trjisr0;
	__BITS8 BIT;
};
union un_ccde {
	unsigned char ccde;
	__BITS8 BIT;
};
union un_pdidis0 {
	unsigned char pdidis0;
	__BITS8 BIT;
};
union un_pdidis1 {
	unsigned char pdidis1;
	__BITS8 BIT;
};
union un_pdidis3 {
	unsigned char pdidis3;
	__BITS8 BIT;
};
union un_pdidis5 {
	unsigned char pdidis5;
	__BITS8 BIT;
};
union un_pdidis7 {
	unsigned char pdidis7;
	__BITS8 BIT;
};
union un_pdidis13 {
	unsigned char pdidis13;
	__BITS8 BIT;
};
union un_flars {
	unsigned char flars;
	__BITS8 BIT;
};
union un_fssq {
	unsigned char fssq;
	__BITS8 BIT;
};
union un_flrst {
	unsigned char flrst;
	__BITS8 BIT;
};
union un_fsastl {
	unsigned char fsastl;
	__BITS8 BIT;
};
union un_fsasth {
	unsigned char fsasth;
	__BITS8 BIT;
};
union un_dscctl {
	unsigned char dscctl;
	__BITS8 BIT;
};
union un_mckc {
	unsigned char mckc;
	__BITS8 BIT;
};
union un_dtcen0 {
	unsigned char dtcen0;
	__BITS8 BIT;
};
union un_dtcen1 {
	unsigned char dtcen1;
	__BITS8 BIT;
};
union un_dtcen2 {
	unsigned char dtcen2;
	__BITS8 BIT;
};
union un_dtcen3 {
	unsigned char dtcen3;
	__BITS8 BIT;
};
union un_dtcen4 {
	unsigned char dtcen4;
	__BITS8 BIT;
};
union un_dtcen5 {
	unsigned char dtcen5;
	__BITS8 BIT;
};
union un_dtcen6 {
	unsigned char dtcen6;
	__BITS8 BIT;
};
union un_crc0ctl {
	unsigned char crc0ctl;
	__BITS8 BIT;
};
union un_dam0 {
	unsigned char dam0;
	__BITS8 BIT;
};
union un_dam1 {
	unsigned char dam1;
	__BITS8 BIT;
};
union un_compmdr0 {
	unsigned char compmdr0;
	__BITS8 BIT;
};
union un_compocr0 {
	unsigned char compocr0;
	__BITS8 BIT;
};
union un_compmdr1 {
	unsigned char compmdr1;
	__BITS8 BIT;
};
union un_compocr1 {
	unsigned char compocr1;
	__BITS8 BIT;
};
union un_pgactl {
	unsigned char pgactl;
	__BITS8 BIT;
};
union un_pgains {
	unsigned char pgains;
	__BITS8 BIT;
};
union un_trxcr1 {
	unsigned char trxcr1;
	__BITS8 BIT;
};
union un_trxcr2 {
	unsigned char trxcr2;
	__BITS8 BIT;
};
union un_trxsr {
	unsigned char trxsr;
	__BITS8 BIT;
};
union un_itlctl0 {
	unsigned char itlctl0;
	__BITS8 BIT;
};
union un_itlcc0 {
	unsigned char itlcc0;
	__BITS8 BIT;
};
union un_trdmr {
	unsigned char trdmr;
	__BITS8 BIT;
};
union un_trdpmr {
	unsigned char trdpmr;
	__BITS8 BIT;
};
union un_trdoer2 {
	unsigned char trdoer2;
	__BITS8 BIT;
};
union un_trdsr0 {
	unsigned char trdsr0;
	__BITS8 BIT;
};
union un_trdsr1 {
	unsigned char trdsr1;
	__BITS8 BIT;
};
union un_trgmr0 {
	unsigned char trgmr0;
	__BITS8 BIT;
};
union un_trgcr {
	unsigned char trgcr;
	__BITS8 BIT;
};
union un_trgier0 {
	unsigned char trgier0;
	__BITS8 BIT;
};
union un_trgsr0 {
	unsigned char trgsr0;
	__BITS8 BIT;
};
union un_trgior {
	unsigned char trgior;
	__BITS8 BIT;
};
union un_trgmr1 {
	unsigned char trgmr1;
	__BITS8 BIT;
};
union un_trgoer {
	unsigned char trgoer;
	__BITS8 BIT;
};
union un_trgocr {
	unsigned char trgocr;
	__BITS8 BIT;
};
union un_trgier1 {
	unsigned char trgier1;
	__BITS8 BIT;
};
union un_trgsr1 {
	unsigned char trgsr1;
	__BITS8 BIT;
};
union un_trgstr {
	unsigned char trgstr;
	__BITS8 BIT;
};
union un_trgctl0 {
	unsigned char trgctl0;
	__BITS8 BIT;
};
union un_trgctl1 {
	unsigned char trgctl1;
	__BITS8 BIT;
};
union un_tkbtrg2 {
	unsigned char tkbtrg2;
	__BITS8 BIT;
};
union un_tkbflg2 {
	unsigned char tkbflg2;
	__BITS8 BIT;
};
union un_tkbioc20 {
	unsigned char tkbioc20;
	__BITS8 BIT;
};
union un_tkbclr2 {
	unsigned char tkbclr2;
	__BITS8 BIT;
};
union un_tkbioc21 {
	unsigned char tkbioc21;
	__BITS8 BIT;
};
union un_tkbctl21 {
	unsigned char tkbctl21;
	__BITS8 BIT;
};
union un_tkbpahfs2 {
	unsigned char tkbpahfs2;
	__BITS8 BIT;
};
union un_tkbpahft2 {
	unsigned char tkbpahft2;
	__BITS8 BIT;
};
union un_tkbpaflg2 {
	unsigned char tkbpaflg2;
	__BITS8 BIT;
};
union un_tkbpactl22 {
	unsigned char tkbpactl22;
	__BITS8 BIT;
};
union un_rpectl2 {
	unsigned char rpectl2;
	__BITS8 BIT;
};
union un_trngscr0 {
	unsigned char trngscr0;
	__BITS8 BIT;
};
union un_tkbtrg0 {
	unsigned char tkbtrg0;
	__BITS8 BIT;
};
union un_tkbflg0 {
	unsigned char tkbflg0;
	__BITS8 BIT;
};
union un_tkbioc00 {
	unsigned char tkbioc00;
	__BITS8 BIT;
};
union un_tkbclr0 {
	unsigned char tkbclr0;
	__BITS8 BIT;
};
union un_tkbioc01 {
	unsigned char tkbioc01;
	__BITS8 BIT;
};
union un_tkbctl01 {
	unsigned char tkbctl01;
	__BITS8 BIT;
};
union un_tkbpahfs0 {
	unsigned char tkbpahfs0;
	__BITS8 BIT;
};
union un_tkbpahft0 {
	unsigned char tkbpahft0;
	__BITS8 BIT;
};
union un_tkbpaflg0 {
	unsigned char tkbpaflg0;
	__BITS8 BIT;
};
union un_tkbpactl02 {
	unsigned char tkbpactl02;
	__BITS8 BIT;
};
union un_tkbtrg1 {
	unsigned char tkbtrg1;
	__BITS8 BIT;
};
union un_tkbflg1 {
	unsigned char tkbflg1;
	__BITS8 BIT;
};
union un_tkbioc10 {
	unsigned char tkbioc10;
	__BITS8 BIT;
};
union un_tkbclr1 {
	unsigned char tkbclr1;
	__BITS8 BIT;
};
union un_tkbioc11 {
	unsigned char tkbioc11;
	__BITS8 BIT;
};
union un_tkbctl11 {
	unsigned char tkbctl11;
	__BITS8 BIT;
};
union un_tkbpahfs1 {
	unsigned char tkbpahfs1;
	__BITS8 BIT;
};
union un_tkbpahft1 {
	unsigned char tkbpahft1;
	__BITS8 BIT;
};
union un_tkbpaflg1 {
	unsigned char tkbpaflg1;
	__BITS8 BIT;
};
union un_tkbpactl12 {
	unsigned char tkbpactl12;
	__BITS8 BIT;
};

#define ADM2 (*(volatile union un_adm2 *)0xF0010).adm2
#define ADM2_bit (*(volatile union un_adm2 *)0xF0010).BIT
#define ADUL (*(volatile unsigned char *)0xF0011)
#define ADLL (*(volatile unsigned char *)0xF0012)
#define ADTES (*(volatile unsigned char *)0xF0013)
#define ADM3 (*(volatile union un_adm3 *)0xF0014).adm3
#define ADM3_bit (*(volatile union un_adm3 *)0xF0014).BIT
#define ADS0 (*(volatile unsigned char *)0xF0015)
#define ADS1 (*(volatile unsigned char *)0xF0016)
#define ADS2 (*(volatile unsigned char *)0xF0017)
#define ADS3 (*(volatile unsigned char *)0xF0018)
#define ADSCTL (*(volatile union un_adsctl *)0xF0019).adsctl
#define ADSCTL_bit (*(volatile union un_adsctl *)0xF0019).BIT
#define ADTR0 (*(volatile unsigned char *)0xF001A)
#define ADTR1 (*(volatile unsigned char *)0xF001B)
#define ADTR2 (*(volatile unsigned char *)0xF001C)
#define ADTR3 (*(volatile unsigned char *)0xF001D)
#define ADPS (*(volatile unsigned char *)0xF001E)
#define ADSPMOD (*(volatile unsigned char *)0xF001F)
#define ADCR0 (*(volatile unsigned short *)0xF0020)
#define ADCR0H (*(volatile unsigned char *)0xF0021)
#define ADCR1 (*(volatile unsigned short *)0xF0022)
#define ADCR1H (*(volatile unsigned char *)0xF0023)
#define ADCR2 (*(volatile unsigned short *)0xF0024)
#define ADCR2H (*(volatile unsigned char *)0xF0025)
#define ADCR3 (*(volatile unsigned short *)0xF0026)
#define ADCR3H (*(volatile unsigned char *)0xF0027)
#define ADINTCTL (*(volatile union un_adintctl *)0xF0028).adintctl
#define ADINTCTL_bit (*(volatile union un_adintctl *)0xF0028).BIT
#define ADINTST (*(volatile union un_adintst *)0xF0029).adintst
#define ADINTST_bit (*(volatile union un_adintst *)0xF0029).BIT
#define PU0 (*(volatile union un_pu0 *)0xF0030).pu0
#define PU0_bit (*(volatile union un_pu0 *)0xF0030).BIT
#define PU1 (*(volatile union un_pu1 *)0xF0031).pu1
#define PU1_bit (*(volatile union un_pu1 *)0xF0031).BIT
#define PU3 (*(volatile union un_pu3 *)0xF0033).pu3
#define PU3_bit (*(volatile union un_pu3 *)0xF0033).BIT
#define PU4 (*(volatile union un_pu4 *)0xF0034).pu4
#define PU4_bit (*(volatile union un_pu4 *)0xF0034).BIT
#define PU5 (*(volatile union un_pu5 *)0xF0035).pu5
#define PU5_bit (*(volatile union un_pu5 *)0xF0035).BIT
#define PU6 (*(volatile union un_pu6 *)0xF0036).pu6
#define PU6_bit (*(volatile union un_pu6 *)0xF0036).BIT
#define PU7 (*(volatile union un_pu7 *)0xF0037).pu7
#define PU7_bit (*(volatile union un_pu7 *)0xF0037).BIT
#define PU12 (*(volatile union un_pu12 *)0xF003C).pu12
#define PU12_bit (*(volatile union un_pu12 *)0xF003C).BIT
#define PU14 (*(volatile union un_pu14 *)0xF003E).pu14
#define PU14_bit (*(volatile union un_pu14 *)0xF003E).BIT
#define PIM0 (*(volatile union un_pim0 *)0xF0040).pim0
#define PIM0_bit (*(volatile union un_pim0 *)0xF0040).BIT
#define PIM1 (*(volatile union un_pim1 *)0xF0041).pim1
#define PIM1_bit (*(volatile union un_pim1 *)0xF0041).BIT
#define PIM3 (*(volatile union un_pim3 *)0xF0043).pim3
#define PIM3_bit (*(volatile union un_pim3 *)0xF0043).BIT
#define PIM5 (*(volatile union un_pim5 *)0xF0045).pim5
#define PIM5_bit (*(volatile union un_pim5 *)0xF0045).BIT
#define PIM7 (*(volatile union un_pim7 *)0xF0047).pim7
#define PIM7_bit (*(volatile union un_pim7 *)0xF0047).BIT
#define POM0 (*(volatile union un_pom0 *)0xF0050).pom0
#define POM0_bit (*(volatile union un_pom0 *)0xF0050).BIT
#define POM1 (*(volatile union un_pom1 *)0xF0051).pom1
#define POM1_bit (*(volatile union un_pom1 *)0xF0051).BIT
#define POM3 (*(volatile union un_pom3 *)0xF0053).pom3
#define POM3_bit (*(volatile union un_pom3 *)0xF0053).BIT
#define POM5 (*(volatile union un_pom5 *)0xF0055).pom5
#define POM5_bit (*(volatile union un_pom5 *)0xF0055).BIT
#define POM7 (*(volatile union un_pom7 *)0xF0057).pom7
#define POM7_bit (*(volatile union un_pom7 *)0xF0057).BIT
#define PMCA0 (*(volatile union un_pmca0 *)0xF0060).pmca0
#define PMCA0_bit (*(volatile union un_pmca0 *)0xF0060).BIT
#define PMCA1 (*(volatile union un_pmca1 *)0xF0061).pmca1
#define PMCA1_bit (*(volatile union un_pmca1 *)0xF0061).BIT
#define PMCA2 (*(volatile union un_pmca2 *)0xF0062).pmca2
#define PMCA2_bit (*(volatile union un_pmca2 *)0xF0062).BIT
#define PMCA12 (*(volatile union un_pmca12 *)0xF006C).pmca12
#define PMCA12_bit (*(volatile union un_pmca12 *)0xF006C).BIT
#define PMCA14 (*(volatile union un_pmca14 *)0xF006E).pmca14
#define PMCA14_bit (*(volatile union un_pmca14 *)0xF006E).BIT
#define NFEN0 (*(volatile union un_nfen0 *)0xF0070).nfen0
#define NFEN0_bit (*(volatile union un_nfen0 *)0xF0070).BIT
#define NFEN1 (*(volatile union un_nfen1 *)0xF0071).nfen1
#define NFEN1_bit (*(volatile union un_nfen1 *)0xF0071).BIT
#define ISC (*(volatile union un_isc *)0xF0073).isc
#define ISC_bit (*(volatile union un_isc *)0xF0073).BIT
#define TIOS0 (*(volatile unsigned char *)0xF0074)
#define PIOR0 (*(volatile unsigned char *)0xF0077)
#define IAWCTL (*(volatile unsigned char *)0xF0078)
#define ULBS (*(volatile union un_ulbs *)0xF0079).ulbs
#define ULBS_bit (*(volatile union un_ulbs *)0xF0079).BIT
#define IICM (*(volatile unsigned char *)0xF007A)
#define PMS (*(volatile union un_pms *)0xF007B).pms
#define PMS_bit (*(volatile union un_pms *)0xF007B).BIT
#define PFBER (*(volatile union un_pfber *)0xF007C).pfber
#define PFBER_bit (*(volatile union un_pfber *)0xF007C).BIT
#define GDIDIS (*(volatile union un_gdidis *)0xF007D).gdidis
#define GDIDIS_bit (*(volatile union un_gdidis *)0xF007D).BIT
#define DFLCTL (*(volatile union un_dflctl *)0xF0090).dflctl
#define DFLCTL_bit (*(volatile union un_dflctl *)0xF0090).BIT
#define PCKC (*(volatile union un_pckc *)0xF0098).pckc
#define PCKC_bit (*(volatile union un_pckc *)0xF0098).BIT
#define HIOTRM (*(volatile unsigned char *)0xF00A0)
#define HOCODIV (*(volatile unsigned char *)0xF00A8)
#define FLMODE (*(volatile union un_flmode *)0xF00AA).flmode
#define FLMODE_bit (*(volatile union un_flmode *)0xF00AA).BIT
#define FLMWRP (*(volatile union un_flmwrp *)0xF00AB).flmwrp
#define FLMWRP_bit (*(volatile union un_flmwrp *)0xF00AB).BIT
#define FLSEC (*(volatile unsigned short *)0xF00B0)
#define FLFSWS (*(volatile unsigned short *)0xF00B2)
#define FLFSWE (*(volatile unsigned short *)0xF00B4)
#define FSSET (*(volatile unsigned char *)0xF00B6)
#define FSSE (*(volatile union un_fsse *)0xF00B7).fsse
#define FSSE_bit (*(volatile union un_fsse *)0xF00B7).BIT
#define PFCMD (*(volatile unsigned char *)0xF00C0)
#define PFS (*(volatile union un_pfs *)0xF00C1).pfs
#define PFS_bit (*(volatile union un_pfs *)0xF00C1).BIT
#define PER0 (*(volatile union un_per0 *)0xF00F0).per0
#define PER0_bit (*(volatile union un_per0 *)0xF00F0).BIT
#define PRR0 (*(volatile union un_prr0 *)0xF00F1).prr0
#define PRR0_bit (*(volatile union un_prr0 *)0xF00F1).BIT
#define MOCODIV (*(volatile unsigned char *)0xF00F2)
#define OSMC (*(volatile union un_osmc *)0xF00F3).osmc
#define OSMC_bit (*(volatile union un_osmc *)0xF00F3).BIT
#define RPECTL (*(volatile union un_rpectl *)0xF00F5).rpectl
#define RPECTL_bit (*(volatile union un_rpectl *)0xF00F5).BIT
#define PORSR (*(volatile union un_porsr *)0xF00F9).porsr
#define PORSR_bit (*(volatile union un_porsr *)0xF00F9).BIT
#define PER1 (*(volatile union un_per1 *)0xF00FA).per1
#define PER1_bit (*(volatile union un_per1 *)0xF00FA).BIT
#define PRR1 (*(volatile union un_prr1 *)0xF00FB).prr1
#define PRR1_bit (*(volatile union un_prr1 *)0xF00FB).BIT
#define PER2 (*(volatile union un_per2 *)0xF00FC).per2
#define PER2_bit (*(volatile union un_per2 *)0xF00FC).BIT
#define PRR2 (*(volatile union un_prr2 *)0xF00FD).prr2
#define PRR2_bit (*(volatile union un_prr2 *)0xF00FD).BIT
#define BCDADJ (*(volatile unsigned char *)0xF00FE)
#define VECTCTRL (*(volatile unsigned char *)0xF00FF)
#define SSR00 (*(volatile unsigned short *)0xF0100)
#define SSR00L (*(volatile unsigned char *)0xF0100)
#define SSR01 (*(volatile unsigned short *)0xF0102)
#define SSR01L (*(volatile unsigned char *)0xF0102)
#define SSR02 (*(volatile unsigned short *)0xF0104)
#define SSR02L (*(volatile unsigned char *)0xF0104)
#define SSR03 (*(volatile unsigned short *)0xF0106)
#define SSR03L (*(volatile unsigned char *)0xF0106)
#define SIR00 (*(volatile unsigned short *)0xF0108)
#define SIR00L (*(volatile unsigned char *)0xF0108)
#define SIR01 (*(volatile unsigned short *)0xF010A)
#define SIR01L (*(volatile unsigned char *)0xF010A)
#define SIR02 (*(volatile unsigned short *)0xF010C)
#define SIR02L (*(volatile unsigned char *)0xF010C)
#define SIR03 (*(volatile unsigned short *)0xF010E)
#define SIR03L (*(volatile unsigned char *)0xF010E)
#define SMR00 (*(volatile unsigned short *)0xF0110)
#define SMR01 (*(volatile unsigned short *)0xF0112)
#define SMR02 (*(volatile unsigned short *)0xF0114)
#define SMR03 (*(volatile unsigned short *)0xF0116)
#define SCR00 (*(volatile unsigned short *)0xF0118)
#define SCR01 (*(volatile unsigned short *)0xF011A)
#define SCR02 (*(volatile unsigned short *)0xF011C)
#define SCR03 (*(volatile unsigned short *)0xF011E)
#define SE0 (*(volatile unsigned short *)0xF0120)
#define SE0L (*(volatile union un_se0l *)0xF0120).se0l
#define SE0L_bit (*(volatile union un_se0l *)0xF0120).BIT
#define SS0 (*(volatile unsigned short *)0xF0122)
#define SS0L (*(volatile union un_ss0l *)0xF0122).ss0l
#define SS0L_bit (*(volatile union un_ss0l *)0xF0122).BIT
#define ST0 (*(volatile unsigned short *)0xF0124)
#define ST0L (*(volatile union un_st0l *)0xF0124).st0l
#define ST0L_bit (*(volatile union un_st0l *)0xF0124).BIT
#define SPS0 (*(volatile unsigned short *)0xF0126)
#define SPS0L (*(volatile unsigned char *)0xF0126)
#define SO0 (*(volatile unsigned short *)0xF0128)
#define SOE0 (*(volatile unsigned short *)0xF012A)
#define SOE0L (*(volatile union un_soe0l *)0xF012A).soe0l
#define SOE0L_bit (*(volatile union un_soe0l *)0xF012A).BIT
#define SOL0 (*(volatile unsigned short *)0xF0134)
#define SOL0L (*(volatile unsigned char *)0xF0134)
#define SSC0 (*(volatile unsigned short *)0xF0138)
#define SSC0L (*(volatile unsigned char *)0xF0138)
#define SSR10 (*(volatile unsigned short *)0xF0140)
#define SSR10L (*(volatile unsigned char *)0xF0140)
#define SSR11 (*(volatile unsigned short *)0xF0142)
#define SSR11L (*(volatile unsigned char *)0xF0142)
#define SIR10 (*(volatile unsigned short *)0xF0148)
#define SIR10L (*(volatile unsigned char *)0xF0148)
#define SIR11 (*(volatile unsigned short *)0xF014A)
#define SIR11L (*(volatile unsigned char *)0xF014A)
#define SMR10 (*(volatile unsigned short *)0xF0150)
#define SMR11 (*(volatile unsigned short *)0xF0152)
#define SCR10 (*(volatile unsigned short *)0xF0158)
#define SCR11 (*(volatile unsigned short *)0xF015A)
#define SE1 (*(volatile unsigned short *)0xF0160)
#define SE1L (*(volatile union un_se1l *)0xF0160).se1l
#define SE1L_bit (*(volatile union un_se1l *)0xF0160).BIT
#define SS1 (*(volatile unsigned short *)0xF0162)
#define SS1L (*(volatile union un_ss1l *)0xF0162).ss1l
#define SS1L_bit (*(volatile union un_ss1l *)0xF0162).BIT
#define ST1 (*(volatile unsigned short *)0xF0164)
#define ST1L (*(volatile union un_st1l *)0xF0164).st1l
#define ST1L_bit (*(volatile union un_st1l *)0xF0164).BIT
#define SPS1 (*(volatile unsigned short *)0xF0166)
#define SPS1L (*(volatile unsigned char *)0xF0166)
#define SO1 (*(volatile unsigned short *)0xF0168)
#define SOE1 (*(volatile unsigned short *)0xF016A)
#define SOE1L (*(volatile union un_soe1l *)0xF016A).soe1l
#define SOE1L_bit (*(volatile union un_soe1l *)0xF016A).BIT
#define SOL1 (*(volatile unsigned short *)0xF0174)
#define SOL1L (*(volatile unsigned char *)0xF0174)
#define TCR00 (*(volatile unsigned short *)0xF0180)
#define TCR01 (*(volatile unsigned short *)0xF0182)
#define TCR02 (*(volatile unsigned short *)0xF0184)
#define TCR03 (*(volatile unsigned short *)0xF0186)
#define TMR00 (*(volatile unsigned short *)0xF0190)
#define TMR01 (*(volatile unsigned short *)0xF0192)
#define TMR02 (*(volatile unsigned short *)0xF0194)
#define TMR03 (*(volatile unsigned short *)0xF0196)
#define TSR00 (*(volatile unsigned short *)0xF01A0)
#define TSR00L (*(volatile unsigned char *)0xF01A0)
#define TSR01 (*(volatile unsigned short *)0xF01A2)
#define TSR01L (*(volatile unsigned char *)0xF01A2)
#define TSR02 (*(volatile unsigned short *)0xF01A4)
#define TSR02L (*(volatile unsigned char *)0xF01A4)
#define TSR03 (*(volatile unsigned short *)0xF01A6)
#define TSR03L (*(volatile unsigned char *)0xF01A6)
#define TE0 (*(volatile unsigned short *)0xF01B0)
#define TE0L (*(volatile union un_te0l *)0xF01B0).te0l
#define TE0L_bit (*(volatile union un_te0l *)0xF01B0).BIT
#define TS0 (*(volatile unsigned short *)0xF01B2)
#define TS0L (*(volatile union un_ts0l *)0xF01B2).ts0l
#define TS0L_bit (*(volatile union un_ts0l *)0xF01B2).BIT
#define TT0 (*(volatile unsigned short *)0xF01B4)
#define TT0L (*(volatile union un_tt0l *)0xF01B4).tt0l
#define TT0L_bit (*(volatile union un_tt0l *)0xF01B4).BIT
#define TPS0 (*(volatile unsigned short *)0xF01B6)
#define TO0 (*(volatile unsigned short *)0xF01B8)
#define TO0L (*(volatile unsigned char *)0xF01B8)
#define TOE0 (*(volatile unsigned short *)0xF01BA)
#define TOE0L (*(volatile union un_toe0l *)0xF01BA).toe0l
#define TOE0L_bit (*(volatile union un_toe0l *)0xF01BA).BIT
#define TOL0 (*(volatile unsigned short *)0xF01BC)
#define TOL0L (*(volatile unsigned char *)0xF01BC)
#define TOM0 (*(volatile unsigned short *)0xF01BE)
#define TOM0L (*(volatile unsigned char *)0xF01BE)
#define MIOTRM (*(volatile unsigned char *)0xF0212)
#define LIOTRM (*(volatile unsigned char *)0xF0213)
#define MOSCDIV (*(volatile unsigned char *)0xF0214)
#define WKUPMD (*(volatile union un_wkupmd *)0xF0215).wkupmd
#define WKUPMD_bit (*(volatile union un_wkupmd *)0xF0215).BIT
#define LVDFCLR (*(volatile union un_lvdfclr *)0xF0218).lvdfclr
#define LVDFCLR_bit (*(volatile union un_lvdfclr *)0xF0218).BIT
#define HSCLKSEL (*(volatile union un_hsclksel *)0xF0219).hsclksel
#define HSCLKSEL_bit (*(volatile union un_hsclksel *)0xF0219).BIT
#define SEC (*(volatile unsigned char *)0xF0220)
#define MIN (*(volatile unsigned char *)0xF0221)
#define HOUR (*(volatile unsigned char *)0xF0222)
#define WEEK (*(volatile unsigned char *)0xF0223)
#define DAY (*(volatile unsigned char *)0xF0224)
#define MONTH (*(volatile unsigned char *)0xF0225)
#define YEAR (*(volatile unsigned char *)0xF0226)
#define SUBCUD (*(volatile unsigned char *)0xF0227)
#define ALARMWM (*(volatile unsigned char *)0xF0228)
#define ALARMWH (*(volatile unsigned char *)0xF0229)
#define ALARMWW (*(volatile unsigned char *)0xF022A)
#define RTCC0 (*(volatile union un_rtcc0 *)0xF022B).rtcc0
#define RTCC0_bit (*(volatile union un_rtcc0 *)0xF022B).BIT
#define RTCC1 (*(volatile union un_rtcc1 *)0xF022C).rtcc1
#define RTCC1_bit (*(volatile union un_rtcc1 *)0xF022C).BIT
#define IICCTL00 (*(volatile union un_iicctl00 *)0xF0230).iicctl00
#define IICCTL00_bit (*(volatile union un_iicctl00 *)0xF0230).BIT
#define IICCTL01 (*(volatile union un_iicctl01 *)0xF0231).iicctl01
#define IICCTL01_bit (*(volatile union un_iicctl01 *)0xF0231).BIT
#define IICWL0 (*(volatile unsigned char *)0xF0232)
#define IICWH0 (*(volatile unsigned char *)0xF0233)
#define SVA0 (*(volatile unsigned char *)0xF0234)
#define TRJCR0 (*(volatile unsigned char *)0xF0240)
#define TRJIOC0 (*(volatile union un_trjioc0 *)0xF0241).trjioc0
#define TRJIOC0_bit (*(volatile union un_trjioc0 *)0xF0241).BIT
#define TRJMR0 (*(volatile union un_trjmr0 *)0xF0242).trjmr0
#define TRJMR0_bit (*(volatile union un_trjmr0 *)0xF0242).BIT
#define TRJISR0 (*(volatile union un_trjisr0 *)0xF0243).trjisr0
#define TRJISR0_bit (*(volatile union un_trjisr0 *)0xF0243).BIT
#define CCS0 (*(volatile unsigned char *)0xF02A0)
#define CCS4 (*(volatile unsigned char *)0xF02A4)
#define CCS5 (*(volatile unsigned char *)0xF02A5)
#define CCS6 (*(volatile unsigned char *)0xF02A6)
#define CCS7 (*(volatile unsigned char *)0xF02A7)
#define CCDE (*(volatile union un_ccde *)0xF02A8).ccde
#define CCDE_bit (*(volatile union un_ccde *)0xF02A8).BIT
#define TRDPOE (*(volatile unsigned char *)0xF02AC)
#define PIOR1 (*(volatile unsigned char *)0xF02AD)
#define PIOR2 (*(volatile unsigned char *)0xF02AE)
#define PIOR3 (*(volatile unsigned char *)0xF02AF)
#define PDIDIS0 (*(volatile union un_pdidis0 *)0xF02B0).pdidis0
#define PDIDIS0_bit (*(volatile union un_pdidis0 *)0xF02B0).BIT
#define PDIDIS1 (*(volatile union un_pdidis1 *)0xF02B1).pdidis1
#define PDIDIS1_bit (*(volatile union un_pdidis1 *)0xF02B1).BIT
#define PDIDIS3 (*(volatile union un_pdidis3 *)0xF02B3).pdidis3
#define PDIDIS3_bit (*(volatile union un_pdidis3 *)0xF02B3).BIT
#define PDIDIS5 (*(volatile union un_pdidis5 *)0xF02B5).pdidis5
#define PDIDIS5_bit (*(volatile union un_pdidis5 *)0xF02B5).BIT
#define PDIDIS7 (*(volatile union un_pdidis7 *)0xF02B7).pdidis7
#define PDIDIS7_bit (*(volatile union un_pdidis7 *)0xF02B7).BIT
#define PDIDIS13 (*(volatile union un_pdidis13 *)0xF02BD).pdidis13
#define PDIDIS13_bit (*(volatile union un_pdidis13 *)0xF02BD).BIT
#define FLPMC (*(volatile unsigned char *)0xF02C0)
#define FLARS (*(volatile union un_flars *)0xF02C1).flars
#define FLARS_bit (*(volatile union un_flars *)0xF02C1).BIT
#define FLAPL (*(volatile unsigned short *)0xF02C2)
#define FLAPH (*(volatile unsigned char *)0xF02C4)
#define FSSQ (*(volatile union un_fssq *)0xF02C5).fssq
#define FSSQ_bit (*(volatile union un_fssq *)0xF02C5).BIT
#define FLSEDL (*(volatile unsigned short *)0xF02C6)
#define FLSEDH (*(volatile unsigned char *)0xF02C8)
#define FLRST (*(volatile union un_flrst *)0xF02C9).flrst
#define FLRST_bit (*(volatile union un_flrst *)0xF02C9).BIT
#define FSASTL (*(volatile union un_fsastl *)0xF02CA).fsastl
#define FSASTL_bit (*(volatile union un_fsastl *)0xF02CA).BIT
#define FSASTH (*(volatile union un_fsasth *)0xF02CB).fsasth
#define FSASTH_bit (*(volatile union un_fsasth *)0xF02CB).BIT
#define FLWL (*(volatile unsigned short *)0xF02CC)
#define FLWH (*(volatile unsigned short *)0xF02CE)
#define DTCBAR (*(volatile unsigned char *)0xF02E0)
#define DSCCTL (*(volatile union un_dscctl *)0xF02E5).dscctl
#define DSCCTL_bit (*(volatile union un_dscctl *)0xF02E5).BIT
#define MCKC (*(volatile union un_mckc *)0xF02E6).mckc
#define MCKC_bit (*(volatile union un_mckc *)0xF02E6).BIT
#define DTCEN0 (*(volatile union un_dtcen0 *)0xF02E8).dtcen0
#define DTCEN0_bit (*(volatile union un_dtcen0 *)0xF02E8).BIT
#define DTCEN1 (*(volatile union un_dtcen1 *)0xF02E9).dtcen1
#define DTCEN1_bit (*(volatile union un_dtcen1 *)0xF02E9).BIT
#define DTCEN2 (*(volatile union un_dtcen2 *)0xF02EA).dtcen2
#define DTCEN2_bit (*(volatile union un_dtcen2 *)0xF02EA).BIT
#define DTCEN3 (*(volatile union un_dtcen3 *)0xF02EB).dtcen3
#define DTCEN3_bit (*(volatile union un_dtcen3 *)0xF02EB).BIT
#define DTCEN4 (*(volatile union un_dtcen4 *)0xF02EC).dtcen4
#define DTCEN4_bit (*(volatile union un_dtcen4 *)0xF02EC).BIT
#define DTCEN5 (*(volatile union un_dtcen5 *)0xF02ED).dtcen5
#define DTCEN5_bit (*(volatile union un_dtcen5 *)0xF02ED).BIT
#define DTCEN6 (*(volatile union un_dtcen6 *)0xF02EE).dtcen6
#define DTCEN6_bit (*(volatile union un_dtcen6 *)0xF02EE).BIT
#define CRC0CTL (*(volatile union un_crc0ctl *)0xF02F0).crc0ctl
#define CRC0CTL_bit (*(volatile union un_crc0ctl *)0xF02F0).BIT
#define PGCRCL (*(volatile unsigned short *)0xF02F2)
#define CRCD (*(volatile unsigned short *)0xF02FA)
#define ELSELR00 (*(volatile unsigned char *)0xF0300)
#define ELSELR01 (*(volatile unsigned char *)0xF0301)
#define ELSELR02 (*(volatile unsigned char *)0xF0302)
#define ELSELR03 (*(volatile unsigned char *)0xF0303)
#define ELSELR04 (*(volatile unsigned char *)0xF0304)
#define ELSELR05 (*(volatile unsigned char *)0xF0305)
#define ELSELR06 (*(volatile unsigned char *)0xF0306)
#define ELSELR07 (*(volatile unsigned char *)0xF0307)
#define ELSELR08 (*(volatile unsigned char *)0xF0308)
#define ELSELR09 (*(volatile unsigned char *)0xF0309)
#define ELSELR10 (*(volatile unsigned char *)0xF030A)
#define ELSELR11 (*(volatile unsigned char *)0xF030B)
#define ELSELR12 (*(volatile unsigned char *)0xF030C)
#define ELSELR13 (*(volatile unsigned char *)0xF030D)
#define ELSELR14 (*(volatile unsigned char *)0xF030E)
#define ELSELR15 (*(volatile unsigned char *)0xF030F)
#define ELSELR16 (*(volatile unsigned char *)0xF0310)
#define ELSELR17 (*(volatile unsigned char *)0xF0311)
#define ELSELR18 (*(volatile unsigned char *)0xF0312)
#define ELSELR19 (*(volatile unsigned char *)0xF0313)
#define ELSELR20 (*(volatile unsigned char *)0xF0314)
#define ELSELR21 (*(volatile unsigned char *)0xF0315)
#define ELSELR22 (*(volatile unsigned char *)0xF0316)
#define ELSELR23 (*(volatile unsigned char *)0xF0317)
#define ELSELR24 (*(volatile unsigned char *)0xF0318)
#define ELSELR25 (*(volatile unsigned char *)0xF0319)
#define ELSELR26 (*(volatile unsigned char *)0xF031A)
#define ELSELR27 (*(volatile unsigned char *)0xF031B)
#define ELSELR28 (*(volatile unsigned char *)0xF031C)
#define ELSELR29 (*(volatile unsigned char *)0xF031D)
#define ELSELR30 (*(volatile unsigned char *)0xF031E)
#define ELSELR31 (*(volatile unsigned char *)0xF031F)
#define ELSELR32 (*(volatile unsigned char *)0xF0320)
#define ELSELR33 (*(volatile unsigned char *)0xF0321)
#define DAM0 (*(volatile union un_dam0 *)0xF0330).dam0
#define DAM0_bit (*(volatile union un_dam0 *)0xF0330).BIT
#define DAM1 (*(volatile union un_dam1 *)0xF0331).dam1
#define DAM1_bit (*(volatile union un_dam1 *)0xF0331).BIT
#define DAM2 (*(volatile unsigned char *)0xF0332)
#define DACS2 (*(volatile unsigned char *)0xF0333)
#define DACS0 (*(volatile unsigned short *)0xF0334)
#define DACS1 (*(volatile unsigned short *)0xF0336)
#define DACS1L (*(volatile unsigned char *)0xF0336)
#define COMPMDR0 (*(volatile union un_compmdr0 *)0xF0340).compmdr0
#define COMPMDR0_bit (*(volatile union un_compmdr0 *)0xF0340).BIT
#define COMPFIR0 (*(volatile unsigned char *)0xF0341)
#define COMPOCR0 (*(volatile union un_compocr0 *)0xF0342).compocr0
#define COMPOCR0_bit (*(volatile union un_compocr0 *)0xF0342).BIT
#define COMPMDR1 (*(volatile union un_compmdr1 *)0xF0344).compmdr1
#define COMPMDR1_bit (*(volatile union un_compmdr1 *)0xF0344).BIT
#define COMPFIR1 (*(volatile unsigned char *)0xF0345)
#define COMPOCR1 (*(volatile union un_compocr1 *)0xF0346).compocr1
#define COMPOCR1_bit (*(volatile union un_compocr1 *)0xF0346).BIT
#define PGACTL (*(volatile union un_pgactl *)0xF0347).pgactl
#define PGACTL_bit (*(volatile union un_pgactl *)0xF0347).BIT
#define PGAINS (*(volatile union un_pgains *)0xF0348).pgains
#define PGAINS_bit (*(volatile union un_pgains *)0xF0348).BIT
#define CMP0SEL (*(volatile unsigned char *)0xF034A)
#define CMP1SEL (*(volatile unsigned char *)0xF034B)
#define CMP2SEL (*(volatile unsigned char *)0xF034C)
#define CMP3SEL (*(volatile unsigned char *)0xF034D)
#define COMPOCR2 (*(volatile unsigned char *)0xF034E)
#define TRX (*(volatile unsigned short *)0xF0350)
#define TRXBUF (*(volatile unsigned short *)0xF0352)
#define TRXCR1 (*(volatile union un_trxcr1 *)0xF0354).trxcr1
#define TRXCR1_bit (*(volatile union un_trxcr1 *)0xF0354).BIT
#define TRXCR2 (*(volatile union un_trxcr2 *)0xF0355).trxcr2
#define TRXCR2_bit (*(volatile union un_trxcr2 *)0xF0355).BIT
#define TRXSR (*(volatile union un_trxsr *)0xF0356).trxsr
#define TRXSR_bit (*(volatile union un_trxsr *)0xF0356).BIT
#define OPCTL0 (*(volatile unsigned char *)0xF0358)
#define OPDF0 (*(volatile unsigned char *)0xF0359)
#define OPDF1 (*(volatile unsigned char *)0xF035A)
#define OPEDGE (*(volatile unsigned char *)0xF035B)
#define OPSR (*(volatile unsigned char *)0xF035C)
#define ITLCMP00 (*(volatile unsigned short *)0xF0360)
#define ITLCMP000 (*(volatile unsigned char *)0xF0360)
#define ITLCMP001 (*(volatile unsigned char *)0xF0361)
#define ITLCMP01 (*(volatile unsigned short *)0xF0362)
#define ITLCMP012 (*(volatile unsigned char *)0xF0362)
#define ITLCMP013 (*(volatile unsigned char *)0xF0363)
#define ITLCAP00 (*(volatile unsigned short *)0xF0364)
#define ITLCTL0 (*(volatile union un_itlctl0 *)0xF0366).itlctl0
#define ITLCTL0_bit (*(volatile union un_itlctl0 *)0xF0366).BIT
#define ITLCSEL0 (*(volatile unsigned char *)0xF0367)
#define ITLFDIV00 (*(volatile unsigned char *)0xF0368)
#define ITLFDIV01 (*(volatile unsigned char *)0xF0369)
#define ITLCC0 (*(volatile union un_itlcc0 *)0xF036A).itlcc0
#define ITLCC0_bit (*(volatile union un_itlcc0 *)0xF036A).BIT
#define ITLS0 (*(volatile unsigned char *)0xF036B)
#define ITLMKF0 (*(volatile unsigned char *)0xF036C)
#define INTPCTL0 (*(volatile unsigned char *)0xF0370)
#define INTPCTL1 (*(volatile unsigned char *)0xF0371)
#define INTPCTL2 (*(volatile unsigned char *)0xF0372)
#define TPS2 (*(volatile unsigned char *)0xF0373)
#define TRDELC (*(volatile unsigned char *)0xF0390)
#define TRDBCR (*(volatile unsigned char *)0xF0391)
#define TRDBOF (*(volatile unsigned char *)0xF0392)
#define TRDSTR (*(volatile unsigned char *)0xF0393)
#define TRDMR (*(volatile union un_trdmr *)0xF0394).trdmr
#define TRDMR_bit (*(volatile union un_trdmr *)0xF0394).BIT
#define TRDPMR (*(volatile union un_trdpmr *)0xF0395).trdpmr
#define TRDPMR_bit (*(volatile union un_trdpmr *)0xF0395).BIT
#define TRDFCR (*(volatile unsigned char *)0xF0396)
#define TRDOER1 (*(volatile unsigned char *)0xF0397)
#define TRDOER2 (*(volatile union un_trdoer2 *)0xF0398).trdoer2
#define TRDOER2_bit (*(volatile union un_trdoer2 *)0xF0398).BIT
#define TRDOCR (*(volatile unsigned char *)0xF0399)
#define TRDDF0 (*(volatile unsigned char *)0xF039A)
#define TRDDF1 (*(volatile unsigned char *)0xF039B)
#define TRDCR0 (*(volatile unsigned char *)0xF03A0)
#define TRDIORA0 (*(volatile unsigned char *)0xF03A1)
#define TRDIORC0 (*(volatile unsigned char *)0xF03A2)
#define TRDSR0 (*(volatile union un_trdsr0 *)0xF03A3).trdsr0
#define TRDSR0_bit (*(volatile union un_trdsr0 *)0xF03A3).BIT
#define TRDIER0 (*(volatile unsigned char *)0xF03A4)
#define TRDPOCR0 (*(volatile unsigned char *)0xF03A5)
#define TRD0 (*(volatile unsigned short *)0xF03A6)
#define TRDGRA0 (*(volatile unsigned short *)0xF03A8)
#define TRDGRB0 (*(volatile unsigned short *)0xF03AA)
#define TRDCR1 (*(volatile unsigned char *)0xF03B0)
#define TRDIORA1 (*(volatile unsigned char *)0xF03B1)
#define TRDIORC1 (*(volatile unsigned char *)0xF03B2)
#define TRDSR1 (*(volatile union un_trdsr1 *)0xF03B3).trdsr1
#define TRDSR1_bit (*(volatile union un_trdsr1 *)0xF03B3).BIT
#define TRDIER1 (*(volatile unsigned char *)0xF03B4)
#define TRDPOCR1 (*(volatile unsigned char *)0xF03B5)
#define TRD1 (*(volatile unsigned short *)0xF03B6)
#define TRDGRA1 (*(volatile unsigned short *)0xF03B8)
#define TRDGRB1 (*(volatile unsigned short *)0xF03BA)
#define TRDCMPB0 (*(volatile unsigned short *)0xF03C0)
#define TRDCMPA1 (*(volatile unsigned short *)0xF03C4)
#define TRDCMPB1 (*(volatile unsigned short *)0xF03C8)
#define TRDCMPE1 (*(volatile unsigned short *)0xF03CC)
#define TRDADTC0 (*(volatile unsigned short *)0xF03CC)
#define TRDADTC1 (*(volatile unsigned short *)0xF03D0)
#define TRDRSF (*(volatile unsigned short *)0xF03D6)
#define TRDRSF0 (*(volatile unsigned char *)0xF03D6)
#define TRDRSF1 (*(volatile unsigned char *)0xF03D7)
#define TRDADCR (*(volatile unsigned char *)0xF03D8)
#define TRGMR0 (*(volatile union un_trgmr0 *)0xF03E0).trgmr0
#define TRGMR0_bit (*(volatile union un_trgmr0 *)0xF03E0).BIT
#define TRGCNTC (*(volatile unsigned char *)0xF03E1)
#define TRGCR (*(volatile union un_trgcr *)0xF03E2).trgcr
#define TRGCR_bit (*(volatile union un_trgcr *)0xF03E2).BIT
#define TRGIER0 (*(volatile union un_trgier0 *)0xF03E3).trgier0
#define TRGIER0_bit (*(volatile union un_trgier0 *)0xF03E3).BIT
#define TRGSR0 (*(volatile union un_trgsr0 *)0xF03E4).trgsr0
#define TRGSR0_bit (*(volatile union un_trgsr0 *)0xF03E4).BIT
#define TRGIOR (*(volatile union un_trgior *)0xF03E5).trgior
#define TRGIOR_bit (*(volatile union un_trgior *)0xF03E5).BIT
#define TRG (*(volatile unsigned short *)0xF03E6)
#define TRGGRA (*(volatile unsigned short *)0xF03E8)
#define TRGGRB (*(volatile unsigned short *)0xF03EA)
#define TRGMR1 (*(volatile union un_trgmr1 *)0xF03F0).trgmr1
#define TRGMR1_bit (*(volatile union un_trgmr1 *)0xF03F0).BIT
#define TRGOER (*(volatile union un_trgoer *)0xF03F1).trgoer
#define TRGOER_bit (*(volatile union un_trgoer *)0xF03F1).BIT
#define TRGOCR (*(volatile union un_trgocr *)0xF03F2).trgocr
#define TRGOCR_bit (*(volatile union un_trgocr *)0xF03F2).BIT
#define TRGIER1 (*(volatile union un_trgier1 *)0xF03F3).trgier1
#define TRGIER1_bit (*(volatile union un_trgier1 *)0xF03F3).BIT
#define TRGSR1 (*(volatile union un_trgsr1 *)0xF03F4).trgsr1
#define TRGSR1_bit (*(volatile union un_trgsr1 *)0xF03F4).BIT
#define TRGSTR (*(volatile union un_trgstr *)0xF03F5).trgstr
#define TRGSTR_bit (*(volatile union un_trgstr *)0xF03F5).BIT
#define TRGCTL0 (*(volatile union un_trgctl0 *)0xF03F6).trgctl0
#define TRGCTL0_bit (*(volatile union un_trgctl0 *)0xF03F6).BIT
#define TRGCTL1 (*(volatile union un_trgctl1 *)0xF03F7).trgctl1
#define TRGCTL1_bit (*(volatile union un_trgctl1 *)0xF03F7).BIT
#define TRGPMC (*(volatile unsigned short *)0xF03F8)
#define TRGCAP0 (*(volatile unsigned short *)0xF03FA)
#define TRGCAP1 (*(volatile unsigned short *)0xF03FC)
#define TKBCR20 (*(volatile unsigned short *)0xF0400)
#define TKBCR21 (*(volatile unsigned short *)0xF0402)
#define TKBCR22 (*(volatile unsigned short *)0xF0404)
#define TKBCR23 (*(volatile unsigned short *)0xF0406)
#define TKBTGCR2 (*(volatile unsigned short *)0xF0408)
#define TKBSIR20 (*(volatile unsigned short *)0xF040A)
#define TKBSIR21 (*(volatile unsigned short *)0xF040C)
#define TKBDNR20 (*(volatile unsigned char *)0xF040E)
#define TKBSSR20 (*(volatile unsigned char *)0xF040F)
#define TKBDNR21 (*(volatile unsigned char *)0xF0410)
#define TKBSSR21 (*(volatile unsigned char *)0xF0411)
#define TKBTRG2 (*(volatile union un_tkbtrg2 *)0xF0412).tkbtrg2
#define TKBTRG2_bit (*(volatile union un_tkbtrg2 *)0xF0412).BIT
#define TKBFLG2 (*(volatile union un_tkbflg2 *)0xF0413).tkbflg2
#define TKBFLG2_bit (*(volatile union un_tkbflg2 *)0xF0413).BIT
#define TKBCRLD20 (*(volatile unsigned short *)0xF0414)
#define TKBCRLD21 (*(volatile unsigned short *)0xF0416)
#define TKBLEB20 (*(volatile unsigned char *)0xF0418)
#define TKBLEB21 (*(volatile unsigned char *)0xF0419)
#define TKBCNT2 (*(volatile unsigned short *)0xF0420)
#define TKBCTL20 (*(volatile unsigned short *)0xF0422)
#define TKBMFR2 (*(volatile unsigned short *)0xF0424)
#define TKBIOC20 (*(volatile union un_tkbioc20 *)0xF0426).tkbioc20
#define TKBIOC20_bit (*(volatile union un_tkbioc20 *)0xF0426).BIT
#define TKBCLR2 (*(volatile union un_tkbclr2 *)0xF0427).tkbclr2
#define TKBCLR2_bit (*(volatile union un_tkbclr2 *)0xF0427).BIT
#define TKBIOC21 (*(volatile union un_tkbioc21 *)0xF0428).tkbioc21
#define TKBIOC21_bit (*(volatile union un_tkbioc21 *)0xF0428).BIT
#define TKBCTL21 (*(volatile union un_tkbctl21 *)0xF0429).tkbctl21
#define TKBCTL21_bit (*(volatile union un_tkbctl21 *)0xF0429).BIT
#define TKBCTL22 (*(volatile unsigned short *)0xF042A)
#define TKBLEB22 (*(volatile unsigned char *)0xF042C)
#define TKBLEB23 (*(volatile unsigned char *)0xF042D)
#define TKBPACTL20 (*(volatile unsigned short *)0xF0430)
#define TKBPACTL21 (*(volatile unsigned short *)0xF0432)
#define TKBPAHFS2 (*(volatile union un_tkbpahfs2 *)0xF0434).tkbpahfs2
#define TKBPAHFS2_bit (*(volatile union un_tkbpahfs2 *)0xF0434).BIT
#define TKBPAHFT2 (*(volatile union un_tkbpahft2 *)0xF0435).tkbpahft2
#define TKBPAHFT2_bit (*(volatile union un_tkbpahft2 *)0xF0435).BIT
#define TKBPAFLG2 (*(volatile union un_tkbpaflg2 *)0xF0436).tkbpaflg2
#define TKBPAFLG2_bit (*(volatile union un_tkbpaflg2 *)0xF0436).BIT
#define TKBPACTL22 (*(volatile union un_tkbpactl22 *)0xF0437).tkbpactl22
#define TKBPACTL22_bit (*(volatile union un_tkbpactl22 *)0xF0437).BIT
#define TKBPACTL23 (*(volatile unsigned char *)0xF0438)
#define TKBPACTL24 (*(volatile unsigned char *)0xF0439)
#define TKBPAPLS20 (*(volatile unsigned short *)0xF043A)
#define TKBPAPLS21 (*(volatile unsigned short *)0xF043C)
#define TKBPAPLS20L (*(volatile unsigned char *)0xF043E)
#define TKBPAPLS21L (*(volatile unsigned char *)0xF043F)
#define CWDW0L (*(volatile unsigned short *)0xF0440)
#define CWDW0H (*(volatile unsigned short *)0xF0442)
#define CWDW1L (*(volatile unsigned short *)0xF0444)
#define CWDW1H (*(volatile unsigned short *)0xF0446)
#define CWDW2L (*(volatile unsigned short *)0xF0448)
#define CWDW2H (*(volatile unsigned short *)0xF044A)
#define CWDW3L (*(volatile unsigned short *)0xF044C)
#define CWDW3H (*(volatile unsigned short *)0xF044E)
#define CWDW4L (*(volatile unsigned short *)0xF0450)
#define CWDW4H (*(volatile unsigned short *)0xF0452)
#define CWDW5L (*(volatile unsigned short *)0xF0454)
#define CWDW5H (*(volatile unsigned short *)0xF0456)
#define CWDW6L (*(volatile unsigned short *)0xF0458)
#define CWDW6H (*(volatile unsigned short *)0xF045A)
#define CWDW7L (*(volatile unsigned short *)0xF045C)
#define CWDW7H (*(volatile unsigned short *)0xF045E)
#define FLSIVC0 (*(volatile unsigned short *)0xF0480)
#define FLSIVC1 (*(volatile unsigned short *)0xF0482)
#define GFLASH0 (*(volatile unsigned short *)0xF0488)
#define GFLASH1 (*(volatile unsigned short *)0xF048A)
#define GFLASH2 (*(volatile unsigned short *)0xF048C)
#define GIAWCTL (*(volatile unsigned short *)0xF048E)
#define TKBTCTL0 (*(volatile unsigned char *)0xF0490)
#define TKBTCMP0 (*(volatile unsigned char *)0xF0491)
#define TKBTCTL1 (*(volatile unsigned char *)0xF0492)
#define TKBTCMP1 (*(volatile unsigned char *)0xF0493)
#define TKBTCTL2 (*(volatile unsigned char *)0xF0494)
#define TKBTCMP2 (*(volatile unsigned char *)0xF0495)
#define TRDTCTL (*(volatile unsigned char *)0xF0498)
#define TRDTCMP (*(volatile unsigned char *)0xF0499)
#define WIND (*(volatile unsigned short *)0xF04A0)
#define ADBSEL (*(volatile unsigned short *)0xF04B0)
#define RPECTL2 (*(volatile union un_rpectl2 *)0xF04B2).rpectl2
#define RPECTL2_bit (*(volatile union un_rpectl2 *)0xF04B2).BIT
#define FAADUC (*(volatile unsigned char *)0xF04B3)
#define FAADCL (*(volatile unsigned short *)0xF04B4)
#define FAADCH (*(volatile unsigned short *)0xF04B6)
#define FAADAL (*(volatile unsigned short *)0xF04B8)
#define FAADAH (*(volatile unsigned short *)0xF04BA)
#define FAADBL (*(volatile unsigned short *)0xF04BC)
#define FAADBH (*(volatile unsigned short *)0xF04BE)
#define BTVTHR1 (*(volatile unsigned short *)0xF04C0)
#define BTVTHR2 (*(volatile unsigned short *)0xF04C2)
#define BTVTHR3 (*(volatile unsigned short *)0xF04C4)
#define BTVTHR4 (*(volatile unsigned short *)0xF04C6)
#define COLTHR1 (*(volatile unsigned short *)0xF04C8)
#define COLTHR2 (*(volatile unsigned short *)0xF04CA)
#define COLTHR3 (*(volatile unsigned short *)0xF04CC)
#define COLTHR4 (*(volatile unsigned short *)0xF04CE)
#define COLTHR5 (*(volatile unsigned short *)0xF04D0)
#define CNFR1 (*(volatile unsigned short *)0xF04D2)
#define CNFR2 (*(volatile unsigned short *)0xF04D4)
#define TXWR1 (*(volatile unsigned short *)0xF04D6)
#define TDR1H (*(volatile unsigned short *)0xF04DE)
#define TDR1L (*(volatile unsigned short *)0xF04E0)
#define TRSTR1 (*(volatile unsigned short *)0xF04E2)
#define CTR1 (*(volatile unsigned short *)0xF04E6)
#define TXDCTR1 (*(volatile unsigned short *)0xF04E8)
#define RDR1H (*(volatile unsigned short *)0xF04EE)
#define RDR1L (*(volatile unsigned short *)0xF04F0)
#define STR1 (*(volatile unsigned short *)0xF04F2)
#define STR2 (*(volatile unsigned short *)0xF04F4)
#define COLR1 (*(volatile unsigned short *)0xF04F6)
#define FECR1 (*(volatile unsigned short *)0xF04FA)
#define SWRR1 (*(volatile unsigned short *)0xF04FC)
#define TRJ0 (*(volatile unsigned short *)0xF0500)
#define TRNGSDR (*(volatile unsigned char *)0xF0540)
#define TRNGSCR0 (*(volatile union un_trngscr0 *)0xF0542).trngscr0
#define TRNGSCR0_bit (*(volatile union un_trngscr0 *)0xF0542).BIT
#define A0L (*(volatile unsigned short *)0xF0600)
#define A0H (*(volatile unsigned short *)0xF0602)
#define M0L (*(volatile unsigned short *)0xF0604)
#define TMCMP0L (*(volatile unsigned short *)0xF0604)
#define TMCMP0H (*(volatile unsigned short *)0xF0606)
#define M0H (*(volatile unsigned short *)0xF0606)
#define TMCMP1L (*(volatile unsigned short *)0xF0608)
#define M1L (*(volatile unsigned short *)0xF0608)
#define TMCMP1H (*(volatile unsigned short *)0xF060A)
#define M1H (*(volatile unsigned short *)0xF060A)
#define TMCMP2L (*(volatile unsigned short *)0xF060C)
#define L0L (*(volatile unsigned short *)0xF060C)
#define TMCMP2H (*(volatile unsigned short *)0xF060E)
#define L0H (*(volatile unsigned short *)0xF060E)
#define L1L (*(volatile unsigned short *)0xF0610)
#define TMCMP3L (*(volatile unsigned short *)0xF0610)
#define TMCMP3H (*(volatile unsigned short *)0xF0612)
#define L1H (*(volatile unsigned short *)0xF0612)
#define R0L (*(volatile unsigned short *)0xF0614)
#define TMCMP4L (*(volatile unsigned short *)0xF0614)
#define TMCMP4H (*(volatile unsigned short *)0xF0616)
#define R0H (*(volatile unsigned short *)0xF0616)
#define TMCMP5L (*(volatile unsigned short *)0xF0618)
#define DP0 (*(volatile unsigned short *)0xF061A)
#define TMCMP5H (*(volatile unsigned short *)0xF061A)
#define TMMSK0L (*(volatile unsigned short *)0xF061C)
#define DP1 (*(volatile unsigned short *)0xF061E)
#define TMMSK0H (*(volatile unsigned short *)0xF061E)
#define TMMSK1L (*(volatile unsigned short *)0xF0620)
#define DRP0 (*(volatile unsigned short *)0xF0622)
#define TMMSK1H (*(volatile unsigned short *)0xF0622)
#define TMMSK2L (*(volatile unsigned short *)0xF0624)
#define TMMSK2H (*(volatile unsigned short *)0xF0626)
#define TMMSK3L (*(volatile unsigned short *)0xF0628)
#define TMMSK3H (*(volatile unsigned short *)0xF062A)
#define FAACNT (*(volatile unsigned short *)0xF062A)
#define TMMSK4L (*(volatile unsigned short *)0xF062C)
#define TMMSK4H (*(volatile unsigned short *)0xF062E)
#define PG0 (*(volatile unsigned short *)0xF062E)
#define TMMSK5L (*(volatile unsigned short *)0xF0630)
#define TMMSK5H (*(volatile unsigned short *)0xF0632)
#define FCNTL (*(volatile unsigned short *)0xF0634)
#define FCNTH (*(volatile unsigned short *)0xF0636)
#define FAAFLG (*(volatile unsigned short *)0xF0636)
#define FCCNT (*(volatile unsigned short *)0xF0638)
#define IV0L (*(volatile unsigned short *)0xF0648)
#define IV0H (*(volatile unsigned short *)0xF064A)
#define IV1L (*(volatile unsigned short *)0xF064C)
#define IV1H (*(volatile unsigned short *)0xF064E)
#define IV2L (*(volatile unsigned short *)0xF0650)
#define IV2H (*(volatile unsigned short *)0xF0652)
#define IV3L (*(volatile unsigned short *)0xF0654)
#define IV3H (*(volatile unsigned short *)0xF0656)
#define IV4L (*(volatile unsigned short *)0xF0658)
#define IV4H (*(volatile unsigned short *)0xF065A)
#define IV5L (*(volatile unsigned short *)0xF065C)
#define IV5H (*(volatile unsigned short *)0xF065E)
#define IV6L (*(volatile unsigned short *)0xF0660)
#define IV6H (*(volatile unsigned short *)0xF0662)
#define IV7L (*(volatile unsigned short *)0xF0664)
#define IV7H (*(volatile unsigned short *)0xF0666)
#define IV8L (*(volatile unsigned short *)0xF0668)
#define IV8H (*(volatile unsigned short *)0xF066A)
#define IV9L (*(volatile unsigned short *)0xF066C)
#define DSYSC (*(volatile unsigned short *)0xF066E)
#define IV9H (*(volatile unsigned short *)0xF066E)
#define IV10L (*(volatile unsigned short *)0xF0670)
#define IV10H (*(volatile unsigned short *)0xF0672)
#define IV11L (*(volatile unsigned short *)0xF0674)
#define IV11H (*(volatile unsigned short *)0xF0676)
#define IV12L (*(volatile unsigned short *)0xF0678)
#define IV12H (*(volatile unsigned short *)0xF067A)
#define IV13L (*(volatile unsigned short *)0xF067C)
#define IV13H (*(volatile unsigned short *)0xF067E)
#define IV14L (*(volatile unsigned short *)0xF0680)
#define IV14H (*(volatile unsigned short *)0xF0682)
#define SP0 (*(volatile unsigned short *)0xF0682)
#define IV15L (*(volatile unsigned short *)0xF0684)
#define IV15H (*(volatile unsigned short *)0xF0686)
#define IEVSC0L (*(volatile unsigned short *)0xF06A0)
#define IEVSC0H (*(volatile unsigned short *)0xF06A2)
#define IEVSC1 (*(volatile unsigned short *)0xF06A4)
#define TKBCR00 (*(volatile unsigned short *)0xF0740)
#define TKBCR01 (*(volatile unsigned short *)0xF0742)
#define TKBCR02 (*(volatile unsigned short *)0xF0744)
#define TKBCR03 (*(volatile unsigned short *)0xF0746)
#define TKBTGCR0 (*(volatile unsigned short *)0xF0748)
#define TKBSIR00 (*(volatile unsigned short *)0xF074A)
#define TKBSIR01 (*(volatile unsigned short *)0xF074C)
#define TKBDNR00 (*(volatile unsigned char *)0xF074E)
#define TKBSSR00 (*(volatile unsigned char *)0xF074F)
#define TKBDNR01 (*(volatile unsigned char *)0xF0750)
#define TKBSSR01 (*(volatile unsigned char *)0xF0751)
#define TKBTRG0 (*(volatile union un_tkbtrg0 *)0xF0752).tkbtrg0
#define TKBTRG0_bit (*(volatile union un_tkbtrg0 *)0xF0752).BIT
#define TKBFLG0 (*(volatile union un_tkbflg0 *)0xF0753).tkbflg0
#define TKBFLG0_bit (*(volatile union un_tkbflg0 *)0xF0753).BIT
#define TKBCRLD00 (*(volatile unsigned short *)0xF0754)
#define TKBCRLD01 (*(volatile unsigned short *)0xF0756)
#define TKBLEB00 (*(volatile unsigned char *)0xF0758)
#define TKBLEB01 (*(volatile unsigned char *)0xF0759)
#define TKBCNT0 (*(volatile unsigned short *)0xF0760)
#define TKBCTL00 (*(volatile unsigned short *)0xF0762)
#define TKBMFR0 (*(volatile unsigned short *)0xF0764)
#define TKBIOC00 (*(volatile union un_tkbioc00 *)0xF0766).tkbioc00
#define TKBIOC00_bit (*(volatile union un_tkbioc00 *)0xF0766).BIT
#define TKBCLR0 (*(volatile union un_tkbclr0 *)0xF0767).tkbclr0
#define TKBCLR0_bit (*(volatile union un_tkbclr0 *)0xF0767).BIT
#define TKBIOC01 (*(volatile union un_tkbioc01 *)0xF0768).tkbioc01
#define TKBIOC01_bit (*(volatile union un_tkbioc01 *)0xF0768).BIT
#define TKBCTL01 (*(volatile union un_tkbctl01 *)0xF0769).tkbctl01
#define TKBCTL01_bit (*(volatile union un_tkbctl01 *)0xF0769).BIT
#define TKBCTL02 (*(volatile unsigned short *)0xF076A)
#define TKBLEB02 (*(volatile unsigned char *)0xF076C)
#define TKBLEB03 (*(volatile unsigned char *)0xF076D)
#define TKBPACTL00 (*(volatile unsigned short *)0xF0770)
#define TKBPACTL01 (*(volatile unsigned short *)0xF0772)
#define TKBPAHFS0 (*(volatile union un_tkbpahfs0 *)0xF0774).tkbpahfs0
#define TKBPAHFS0_bit (*(volatile union un_tkbpahfs0 *)0xF0774).BIT
#define TKBPAHFT0 (*(volatile union un_tkbpahft0 *)0xF0775).tkbpahft0
#define TKBPAHFT0_bit (*(volatile union un_tkbpahft0 *)0xF0775).BIT
#define TKBPAFLG0 (*(volatile union un_tkbpaflg0 *)0xF0776).tkbpaflg0
#define TKBPAFLG0_bit (*(volatile union un_tkbpaflg0 *)0xF0776).BIT
#define TKBPACTL02 (*(volatile union un_tkbpactl02 *)0xF0777).tkbpactl02
#define TKBPACTL02_bit (*(volatile union un_tkbpactl02 *)0xF0777).BIT
#define TKBPACTL03 (*(volatile unsigned char *)0xF0778)
#define TKBPACTL04 (*(volatile unsigned char *)0xF0779)
#define TKBPAPLS00 (*(volatile unsigned short *)0xF077A)
#define TKBPAPLS01 (*(volatile unsigned short *)0xF077C)
#define TKBPAPLS00L (*(volatile unsigned char *)0xF077E)
#define TKBPAPLS01L (*(volatile unsigned char *)0xF077F)
#define TKBCR10 (*(volatile unsigned short *)0xF0780)
#define TKBCR11 (*(volatile unsigned short *)0xF0782)
#define TKBCR12 (*(volatile unsigned short *)0xF0784)
#define TKBCR13 (*(volatile unsigned short *)0xF0786)
#define TKBTGCR1 (*(volatile unsigned short *)0xF0788)
#define TKBSIR10 (*(volatile unsigned short *)0xF078A)
#define TKBSIR11 (*(volatile unsigned short *)0xF078C)
#define TKBDNR10 (*(volatile unsigned char *)0xF078E)
#define TKBSSR10 (*(volatile unsigned char *)0xF078F)
#define TKBDNR11 (*(volatile unsigned char *)0xF0790)
#define TKBSSR11 (*(volatile unsigned char *)0xF0791)
#define TKBTRG1 (*(volatile union un_tkbtrg1 *)0xF0792).tkbtrg1
#define TKBTRG1_bit (*(volatile union un_tkbtrg1 *)0xF0792).BIT
#define TKBFLG1 (*(volatile union un_tkbflg1 *)0xF0793).tkbflg1
#define TKBFLG1_bit (*(volatile union un_tkbflg1 *)0xF0793).BIT
#define TKBCRLD10 (*(volatile unsigned short *)0xF0794)
#define TKBCRLD11 (*(volatile unsigned short *)0xF0796)
#define TKBLEB10 (*(volatile unsigned char *)0xF0798)
#define TKBLEB11 (*(volatile unsigned char *)0xF0799)
#define TKBCNT1 (*(volatile unsigned short *)0xF07A0)
#define TKBCTL10 (*(volatile unsigned short *)0xF07A2)
#define TKBMFR1 (*(volatile unsigned short *)0xF07A4)
#define TKBIOC10 (*(volatile union un_tkbioc10 *)0xF07A6).tkbioc10
#define TKBIOC10_bit (*(volatile union un_tkbioc10 *)0xF07A6).BIT
#define TKBCLR1 (*(volatile union un_tkbclr1 *)0xF07A7).tkbclr1
#define TKBCLR1_bit (*(volatile union un_tkbclr1 *)0xF07A7).BIT
#define TKBIOC11 (*(volatile union un_tkbioc11 *)0xF07A8).tkbioc11
#define TKBIOC11_bit (*(volatile union un_tkbioc11 *)0xF07A8).BIT
#define TKBCTL11 (*(volatile union un_tkbctl11 *)0xF07A9).tkbctl11
#define TKBCTL11_bit (*(volatile union un_tkbctl11 *)0xF07A9).BIT
#define TKBCTL12 (*(volatile unsigned short *)0xF07AA)
#define TKBLEB12 (*(volatile unsigned char *)0xF07AC)
#define TKBLEB13 (*(volatile unsigned char *)0xF07AD)
#define TKBPACTL10 (*(volatile unsigned short *)0xF07B0)
#define TKBPACTL11 (*(volatile unsigned short *)0xF07B2)
#define TKBPAHFS1 (*(volatile union un_tkbpahfs1 *)0xF07B4).tkbpahfs1
#define TKBPAHFS1_bit (*(volatile union un_tkbpahfs1 *)0xF07B4).BIT
#define TKBPAHFT1 (*(volatile union un_tkbpahft1 *)0xF07B5).tkbpahft1
#define TKBPAHFT1_bit (*(volatile union un_tkbpahft1 *)0xF07B5).BIT
#define TKBPAFLG1 (*(volatile union un_tkbpaflg1 *)0xF07B6).tkbpaflg1
#define TKBPAFLG1_bit (*(volatile union un_tkbpaflg1 *)0xF07B6).BIT
#define TKBPACTL12 (*(volatile union un_tkbpactl12 *)0xF07B7).tkbpactl12
#define TKBPACTL12_bit (*(volatile union un_tkbpactl12 *)0xF07B7).BIT
#define TKBPACTL13 (*(volatile unsigned char *)0xF07B8)
#define TKBPACTL14 (*(volatile unsigned char *)0xF07B9)
#define TKBPAPLS10 (*(volatile unsigned short *)0xF07BA)
#define TKBPAPLS11 (*(volatile unsigned short *)0xF07BC)
#define TKBPAPLS10L (*(volatile unsigned char *)0xF07BE)
#define TKBPAPLS11L (*(volatile unsigned char *)0xF07BF)

/*
 Sfr bits
 */
#define ADTYP0 ADM2_bit.no0
#define ADTYP1 ADM2_bit.no1
#define AWC ADM2_bit.no2
#define ADRCK ADM2_bit.no3
#define ADVMOD ADM3_bit.no0
#define ADTRSWT ADM3_bit.no7
#define ADPRIOR0 ADSCTL_bit.no0
#define ADPRIOR1 ADSCTL_bit.no1
#define ADPRIOR2 ADSCTL_bit.no2
#define ADPRIOR3 ADSCTL_bit.no3
#define ADSEN0 ADSCTL_bit.no4
#define ADSEN1 ADSCTL_bit.no5
#define ADSEN2 ADSCTL_bit.no6
#define ADSEN3 ADSCTL_bit.no7
#define ADINTCTL0F ADINTCTL_bit.no0
#define ADINTCTL0S ADINTCTL_bit.no1
#define ADINTCTL1F ADINTCTL_bit.no2
#define ADINTCTL1S ADINTCTL_bit.no3
#define ADINTCTL2F ADINTCTL_bit.no4
#define ADINTCTL2S ADINTCTL_bit.no5
#define ADINTCTL3F ADINTCTL_bit.no6
#define ADINTCTL3S ADINTCTL_bit.no7
#define ADINTST0F ADINTST_bit.no0
#define ADINTST0S ADINTST_bit.no1
#define ADINTST1F ADINTST_bit.no2
#define ADINTST1S ADINTST_bit.no3
#define ADINTST2F ADINTST_bit.no4
#define ADINTST2S ADINTST_bit.no5
#define ADINTST3F ADINTST_bit.no6
#define ADINTST3S ADINTST_bit.no7
#define ULBS0 ULBS_bit.no0
#define ULBS1 ULBS_bit.no1
#define ULBS2 ULBS_bit.no2
#define PFBE PFBER_bit.no0
#define DFLEN DFLCTL_bit.no0
#define PLLCK PCKC_bit.no1
#define MODE0 FLMODE_bit.no6
#define MODE1 FLMODE_bit.no7
#define FLMWEN FLMWRP_bit.no0
#define ESQST FSSE_bit.no7
#define TAU0EN PER0_bit.no0
#define SAU0EN PER0_bit.no2
#define SAU1EN PER0_bit.no3
#define IICA0EN PER0_bit.no4
#define ADCEN PER0_bit.no5
#define RTCWEN PER0_bit.no7
#define TAU0RES PRR0_bit.no0
#define SAU0RES PRR0_bit.no2
#define SAU1RES PRR0_bit.no3
#define IICA0RES PRR0_bit.no4
#define ADCRES PRR0_bit.no5
#define HIPREC OSMC_bit.no0
#define WUTMMCK0 OSMC_bit.no4
#define RTCLPC OSMC_bit.no7
#define RPEF RPECTL_bit.no0
#define RPERDIS RPECTL_bit.no7
#define PORF PORSR_bit.no0
#define DALIEN PER1_bit.no0
#define DTCEN PER1_bit.no3
#define TML32EN PER1_bit.no4
#define PGACMPEN PER1_bit.no5
#define DACEN PER1_bit.no7
#define DALIRES PRR1_bit.no0
#define TML32RES PRR1_bit.no4
#define PGACMPRES PRR1_bit.no5
#define DACRES PRR1_bit.no7
#define TRJ0EN PER2_bit.no0
#define TRXEN PER2_bit.no1
#define PWMOPEN PER2_bit.no2
#define TRD0EN PER2_bit.no3
#define TRGEN PER2_bit.no4
#define TKBEN PER2_bit.no5
#define MEMEN PER2_bit.no6
#define FAAEN PER2_bit.no7
#define TRJ0RES PRR2_bit.no0
#define TRXRES PRR2_bit.no1
#define PWMOPRES PRR2_bit.no2
#define TRD0RES PRR2_bit.no3
#define TRGRES PRR2_bit.no4
#define TKBRES PRR2_bit.no5
#define MEMRES PRR2_bit.no6
#define FAARES PRR2_bit.no7
#define FWKUP WKUPMD_bit.no0
#define DLVD0FCLR LVDFCLR_bit.no2
#define DLVD1FCLR LVDFCLR_bit.no3
#define FIHSEL HSCLKSEL_bit.no0
#define FIHST HSCLKSEL_bit.no1
#define RTC128EN RTCC0_bit.no4
#define RCLOE1 RTCC0_bit.no5
#define RTCE RTCC0_bit.no7
#define RWAIT RTCC1_bit.no0
#define RWST RTCC1_bit.no1
#define RIFG RTCC1_bit.no3
#define WAFG RTCC1_bit.no4
#define WALIE RTCC1_bit.no6
#define WALE RTCC1_bit.no7
#define SPT0 IICCTL00_bit.no0
#define STT0 IICCTL00_bit.no1
#define ACKE0 IICCTL00_bit.no2
#define WTIM0 IICCTL00_bit.no3
#define SPIE0 IICCTL00_bit.no4
#define WREL0 IICCTL00_bit.no5
#define LREL0 IICCTL00_bit.no6
#define IICE0 IICCTL00_bit.no7
#define PRS0 IICCTL01_bit.no0
#define DFC0 IICCTL01_bit.no2
#define SMC0 IICCTL01_bit.no3
#define DAD0 IICCTL01_bit.no4
#define CLD0 IICCTL01_bit.no5
#define SVADIS0 IICCTL01_bit.no6
#define WUP0 IICCTL01_bit.no7
#define FSSTP FSSQ_bit.no6
#define SQST FSSQ_bit.no7
#define DSCON DSCCTL_bit.no0
#define PLLDIV0 DSCCTL_bit.no6
#define CKSELR MCKC_bit.no0
#define RDIV0 MCKC_bit.no1
#define RDIV1 MCKC_bit.no2
#define CLSTR MCKC_bit.no7
#define CRC0EN CRC0CTL_bit.no7
#define DACE0 DAM0_bit.no4
#define DACE1 DAM0_bit.no5
#define DACE2 DAM0_bit.no6
#define DAPOE0 DAM1_bit.no0
#define DAPOE1 DAM1_bit.no1
#define DAPOE2 DAM1_bit.no2
#define C0ENB COMPMDR0_bit.no0
#define C0POE COMPMDR0_bit.no1
#define C0MON COMPMDR0_bit.no3
#define C1ENB COMPMDR0_bit.no4
#define C1POE COMPMDR0_bit.no5
#define C1MON COMPMDR0_bit.no7
#define C0IE COMPOCR0_bit.no0
#define C0OE COMPOCR0_bit.no1
#define C0OP COMPOCR0_bit.no2
#define C0OTWMD COMPOCR0_bit.no3
#define C1IE COMPOCR0_bit.no4
#define C1OE COMPOCR0_bit.no5
#define C1OP COMPOCR0_bit.no6
#define C1OTWMD COMPOCR0_bit.no7
#define C2ENB COMPMDR1_bit.no0
#define C2POE COMPMDR1_bit.no1
#define C2MON COMPMDR1_bit.no3
#define C3ENB COMPMDR1_bit.no4
#define C3POE COMPMDR1_bit.no5
#define C3MON COMPMDR1_bit.no7
#define C2IE COMPOCR1_bit.no0
#define C2OE COMPOCR1_bit.no1
#define C2OP COMPOCR1_bit.no2
#define C2OTWMD COMPOCR1_bit.no3
#define C3IE COMPOCR1_bit.no4
#define C3OE COMPOCR1_bit.no5
#define C3OP COMPOCR1_bit.no6
#define PGAPOE PGACTL_bit.no6
#define PGAEN PGACTL_bit.no7
#define TRXOVF TRXSR_bit.no0
#define TRXSB TRXSR_bit.no1
#define ITLEN00 ITLCTL0_bit.no0
#define ITLEN01 ITLCTL0_bit.no1
#define ITLEN02 ITLCTL0_bit.no2
#define ITLEN03 ITLCTL0_bit.no3
#define CAPR0 ITLCC0_bit.no4
#define CAPF0CR ITLCC0_bit.no6
#define TRDSYNC TRDMR_bit.no0
#define TRDBFC0 TRDMR_bit.no4
#define TRDBFD0 TRDMR_bit.no5
#define TRDBFC1 TRDMR_bit.no6
#define TRDBFD1 TRDMR_bit.no7
#define TRDPWMB0 TRDPMR_bit.no0
#define TRDPWMC0 TRDPMR_bit.no1
#define TRDPWMD0 TRDPMR_bit.no2
#define TRDPWMB1 TRDPMR_bit.no4
#define TRDPWMC1 TRDPMR_bit.no5
#define TRDPWMD1 TRDPMR_bit.no6
#define TRDPWMA1 TRDPMR_bit.no7
#define TRDSHUTS TRDOER2_bit.no0
#define TRDPTO TRDOER2_bit.no7
#define TRGPWM TRGMR0_bit.no0
#define TRGMDF TRGMR0_bit.no1
#define TRGDFA TRGMR0_bit.no2
#define TRGDFB TRGMR0_bit.no3
#define TRGDFCK0 TRGMR0_bit.no4
#define TRGDFCK1 TRGMR0_bit.no5
#define TRGELCICE TRGMR0_bit.no6
#define TRGSTART TRGMR0_bit.no7
#define TRGTCK0 TRGCR_bit.no0
#define TRGTCK1 TRGCR_bit.no1
#define TRGTCK2 TRGCR_bit.no2
#define TRGCKEG0 TRGCR_bit.no3
#define TRGCKEG1 TRGCR_bit.no4
#define TRGCCLR0 TRGCR_bit.no5
#define TRGCCLR1 TRGCR_bit.no6
#define TRGIMIEA TRGIER0_bit.no0
#define TRGIMIEB TRGIER0_bit.no1
#define TRGUDIE TRGIER0_bit.no2
#define TRGOVIE TRGIER0_bit.no3
#define TRGIMIEC TRGIER0_bit.no6
#define TRGIMIED TRGIER0_bit.no7
#define TRGIMFA TRGSR0_bit.no0
#define TRGIMFB TRGSR0_bit.no1
#define TRGUDF TRGSR0_bit.no2
#define TRGOVF TRGSR0_bit.no3
#define TRGDIRF TRGSR0_bit.no4
#define TRGIMFC TRGSR0_bit.no6
#define TRGIMFD TRGSR0_bit.no7
#define TRGIOA0 TRGIOR_bit.no0
#define TRGIOA1 TRGIOR_bit.no1
#define TRGIOA2 TRGIOR_bit.no2
#define TRGBUFA TRGIOR_bit.no3
#define TRGIOB0 TRGIOR_bit.no4
#define TRGIOB1 TRGIOR_bit.no5
#define TRGIOB2 TRGIOR_bit.no6
#define TRGBUFB TRGIOR_bit.no7
#define TRGPWM2 TRGMR1_bit.no0
#define TRGDFCLR TRGMR1_bit.no1
#define TRGTCEG0 TRGMR1_bit.no2
#define TRGTCEG1 TRGMR1_bit.no3
#define TRGPENA TRGMR1_bit.no6
#define TRGPENB TRGMR1_bit.no7
#define TRGSHUTS TRGOER_bit.no0
#define TRGPTO TRGOER_bit.no7
#define TRGTOA TRGOCR_bit.no0
#define TRGTOB TRGOCR_bit.no1
#define TRGZCIE TRGIER1_bit.no0
#define TRGPCIE TRGIER1_bit.no1
#define TRGZCLF TRGSR1_bit.no0
#define TRGPCLF TRGSR1_bit.no1
#define TRGTSTART TRGSTR_bit.no0
#define TRGCSEL TRGSTR_bit.no1
#define TRGIDZ0 TRGCTL0_bit.no0
#define TRGIDZ1 TRGCTL0_bit.no1
#define TRGACL TRGCTL0_bit.no4
#define TRGBCL TRGCTL0_bit.no5
#define TRGZCL TRGCTL0_bit.no6
#define TRGSCE TRGCTL0_bit.no7
#define TRGECM0 TRGCTL1_bit.no0
#define TRGECM1 TRGCTL1_bit.no1
#define TRGLDE TRGCTL1_bit.no3
#define TRGPMCE TRGCTL1_bit.no7
#define TKBRDT2 TKBTRG2_bit.no0
#define TKBRSF2 TKBFLG2_bit.no0
#define TKBMFF2 TKBFLG2_bit.no1
#define TKBIEF2 TKBFLG2_bit.no2
#define TKBIRF2 TKBFLG2_bit.no3
#define TKBSEF20 TKBFLG2_bit.no4
#define TKBSEF21 TKBFLG2_bit.no5
#define TKBSSF20 TKBFLG2_bit.no6
#define TKBSSF21 TKBFLG2_bit.no7
#define TKBTOD20 TKBIOC20_bit.no0
#define TKBTOD21 TKBIOC20_bit.no1
#define TKBTOL20 TKBIOC20_bit.no2
#define TKBTOL21 TKBIOC20_bit.no3
#define TKBCLMF2 TKBCLR2_bit.no1
#define TKBCLIE2 TKBCLR2_bit.no2
#define TKBCLIR2 TKBCLR2_bit.no3
#define TKBCLSE20 TKBCLR2_bit.no4
#define TKBCLSE21 TKBCLR2_bit.no5
#define TKBTOE20 TKBIOC21_bit.no0
#define TKBTOE21 TKBIOC21_bit.no1
#define TKBCE2 TKBCTL21_bit.no7
#define TKBPAHTS20 TKBPAHFS2_bit.no0
#define TKBPAHTS21 TKBPAHFS2_bit.no1
#define TKBPAHTT20 TKBPAHFT2_bit.no0
#define TKBPAHTT21 TKBPAHFT2_bit.no1
#define TKBPAHIF20 TKBPAFLG2_bit.no0
#define TKBPAFIF20 TKBPAFLG2_bit.no1
#define TKBPAHIF21 TKBPAFLG2_bit.no2
#define TKBPAFIF21 TKBPAFLG2_bit.no3
#define TKBPAHSF20 TKBPAFLG2_bit.no4
#define TKBPAFSF20 TKBPAFLG2_bit.no5
#define TKBPAHSF21 TKBPAFLG2_bit.no6
#define TKBPAFSF21 TKBPAFLG2_bit.no7
#define TKBPACE20 TKBPACTL22_bit.no0
#define TKBPACE21 TKBPACTL22_bit.no1
#define FAARPEF RPECTL2_bit.no0
#define FAARPEREN RPECTL2_bit.no7
#define TRNGST TRNGSCR0_bit.no2
#define TRNGEN TRNGSCR0_bit.no3
#define TRNGRDY TRNGSCR0_bit.no7
#define TKBRDT0 TKBTRG0_bit.no0
#define TKBRSF0 TKBFLG0_bit.no0
#define TKBMFF0 TKBFLG0_bit.no1
#define TKBIEF0 TKBFLG0_bit.no2
#define TKBIRF0 TKBFLG0_bit.no3
#define TKBSEF00 TKBFLG0_bit.no4
#define TKBSEF01 TKBFLG0_bit.no5
#define TKBSSF00 TKBFLG0_bit.no6
#define TKBSSF01 TKBFLG0_bit.no7
#define TKBTOD00 TKBIOC00_bit.no0
#define TKBTOD01 TKBIOC00_bit.no1
#define TKBTOL00 TKBIOC00_bit.no2
#define TKBTOL01 TKBIOC00_bit.no3
#define TKBCLMF0 TKBCLR0_bit.no1
#define TKBCLIE0 TKBCLR0_bit.no2
#define TKBCLIR0 TKBCLR0_bit.no3
#define TKBCLSE00 TKBCLR0_bit.no4
#define TKBCLSE01 TKBCLR0_bit.no5
#define TKBTOE00 TKBIOC01_bit.no0
#define TKBTOE01 TKBIOC01_bit.no1
#define TKBCE0 TKBCTL01_bit.no7
#define TKBPAHTS00 TKBPAHFS0_bit.no0
#define TKBPAHTS01 TKBPAHFS0_bit.no1
#define TKBPAHTT00 TKBPAHFT0_bit.no0
#define TKBPAHTT01 TKBPAHFT0_bit.no1
#define TKBPAHIF00 TKBPAFLG0_bit.no0
#define TKBPAFIF00 TKBPAFLG0_bit.no1
#define TKBPAHIF01 TKBPAFLG0_bit.no2
#define TKBPAFIF01 TKBPAFLG0_bit.no3
#define TKBPAHSF00 TKBPAFLG0_bit.no4
#define TKBPAFSF00 TKBPAFLG0_bit.no5
#define TKBPAHSF01 TKBPAFLG0_bit.no6
#define TKBPAFSF01 TKBPAFLG0_bit.no7
#define TKBPACE00 TKBPACTL02_bit.no0
#define TKBPACE01 TKBPACTL02_bit.no1
#define TKBRDT1 TKBTRG1_bit.no0
#define TKBRSF1 TKBFLG1_bit.no0
#define TKBMFF1 TKBFLG1_bit.no1
#define TKBIEF1 TKBFLG1_bit.no2
#define TKBIRF1 TKBFLG1_bit.no3
#define TKBSEF10 TKBFLG1_bit.no4
#define TKBSEF11 TKBFLG1_bit.no5
#define TKBSSF10 TKBFLG1_bit.no6
#define TKBSSF11 TKBFLG1_bit.no7
#define TKBTOD10 TKBIOC10_bit.no0
#define TKBTOD11 TKBIOC10_bit.no1
#define TKBTOL10 TKBIOC10_bit.no2
#define TKBTOL11 TKBIOC10_bit.no3
#define TKBCLMF1 TKBCLR1_bit.no1
#define TKBCLIE1 TKBCLR1_bit.no2
#define TKBCLIR1 TKBCLR1_bit.no3
#define TKBCLSE10 TKBCLR1_bit.no4
#define TKBCLSE11 TKBCLR1_bit.no5
#define TKBTOE10 TKBIOC11_bit.no0
#define TKBTOE11 TKBIOC11_bit.no1
#define TKBCE1 TKBCTL11_bit.no7
#define TKBPAHTS10 TKBPAHFS1_bit.no0
#define TKBPAHTS11 TKBPAHFS1_bit.no1
#define TKBPAHTT10 TKBPAHFT1_bit.no0
#define TKBPAHTT11 TKBPAHFT1_bit.no1
#define TKBPAHIF10 TKBPAFLG1_bit.no0
#define TKBPAFIF10 TKBPAFLG1_bit.no1
#define TKBPAHIF11 TKBPAFLG1_bit.no2
#define TKBPAFIF11 TKBPAFLG1_bit.no3
#define TKBPAHSF10 TKBPAFLG1_bit.no4
#define TKBPAFSF10 TKBPAFLG1_bit.no5
#define TKBPAHSF11 TKBPAFLG1_bit.no6
#define TKBPAFSF11 TKBPAFLG1_bit.no7
#define TKBPACE10 TKBPACTL12_bit.no0
#define TKBPACE11 TKBPACTL12_bit.no1

/*
 Interrupt vector addresses
 */
#endif
