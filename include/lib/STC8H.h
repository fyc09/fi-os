#ifndef __STC8H_H_
#define __STC8H_H_

#ifdef __SDCC
#define SFR(reg, addr) __sfr __at(addr) reg
#define SBIT(reg, addr) __sbit __at(addr) reg
#else
#define SFR(reg, addr) sfr reg = addr
#define SBIT(reg, addr) sbit reg = addr
#endif // End of __SDCC

SFR(P0, 0x80);
SBIT(P00, P0 ^ 0);
SBIT(P01, P0 ^ 1);
SBIT(P02, P0 ^ 2);
SBIT(P03, P0 ^ 3);
SBIT(P04, P0 ^ 4);
SBIT(P05, P0 ^ 5);
SBIT(P06, P0 ^ 6);
SBIT(P07, P0 ^ 7);
SFR(SP, 0x81);
SFR(DPL, 0x82);
SFR(DPH, 0x83);
SFR(S4CON, 0x84);
SFR(S4BUF, 0x85);
SFR(PCON, 0x87);
SFR(TCON, 0x88);
SBIT(TF1, TCON ^ 7);
SBIT(TR1, TCON ^ 6);
SBIT(TF0, TCON ^ 5);
SBIT(TR0, TCON ^ 4);
SBIT(IE1, TCON ^ 3);
SBIT(IT1, TCON ^ 2);
SBIT(IE0, TCON ^ 1);
SBIT(IT0, TCON ^ 0);
SFR(TMOD, 0x89);
SFR(TL0, 0x8a);
SFR(TL1, 0x8b);
SFR(TH0, 0x8c);
SFR(TH1, 0x8d);
SFR(AUXR, 0x8e);
SFR(INTCLKO, 0x8f);
SFR(P1, 0x90);
SBIT(P10, P1 ^ 0);
SBIT(P11, P1 ^ 1);
SBIT(P12, P1 ^ 2);
SBIT(P13, P1 ^ 3);
SBIT(P14, P1 ^ 4);
SBIT(P15, P1 ^ 5);
SBIT(P16, P1 ^ 6);
SBIT(P17, P1 ^ 7);
SFR(P1M1, 0x91);
SFR(P1M0, 0x92);
SFR(P0M1, 0x93);
SFR(P0M0, 0x94);
SFR(P2M1, 0x95);
SFR(P2M0, 0x96);
SFR(SCON, 0x98);
SBIT(SM0, SCON ^ 7);
SBIT(SM1, SCON ^ 6);
SBIT(SM2, SCON ^ 5);
SBIT(REN, SCON ^ 4);
SBIT(TB8, SCON ^ 3);
SBIT(RB8, SCON ^ 2);
SBIT(TI, SCON ^ 1);
SBIT(RI, SCON ^ 0);
SFR(SBUF, 0x99);
SFR(S2CON, 0x9a);
SFR(S2BUF, 0x9b);
SFR(IRCBAND, 0x9d);
SFR(LIRTRIM, 0x9e);
SFR(IRTRIM, 0x9f);
SFR(P2, 0xa0);
SBIT(P20, P2 ^ 0);
SBIT(P21, P2 ^ 1);
SBIT(P22, P2 ^ 2);
SBIT(P23, P2 ^ 3);
SBIT(P24, P2 ^ 4);
SBIT(P25, P2 ^ 5);
SBIT(P26, P2 ^ 6);
SBIT(P27, P2 ^ 7);
SFR(P_SW1, 0xa2);
SFR(IE, 0xa8);
SBIT(EA, IE ^ 7);
SBIT(ELVD, IE ^ 6);
SBIT(EADC, IE ^ 5);
SBIT(ES, IE ^ 4);
SBIT(ET1, IE ^ 3);
SBIT(EX1, IE ^ 2);
SBIT(ET0, IE ^ 1);
SBIT(EX0, IE ^ 0);
SFR(SADDR, 0xa9);
SFR(WKTCL, 0xaa);
SFR(WKTCH, 0xab);
SFR(S3CON, 0xac);
SFR(S3BUF, 0xad);
SFR(TA, 0xae);
SFR(IE2, 0xaf);
SFR(P3, 0xb0);
SBIT(P30, P3 ^ 0);
SBIT(P31, P3 ^ 1);
SBIT(P32, P3 ^ 2);
SBIT(P33, P3 ^ 3);
SBIT(P34, P3 ^ 4);
SBIT(P35, P3 ^ 5);
SBIT(P36, P3 ^ 6);
SBIT(P37, P3 ^ 7);
SFR(P3M1, 0xb1);
SFR(P3M0, 0xb2);
SFR(P4M1, 0xb3);
SFR(P4M0, 0xb4);
SFR(IP2, 0xb5);
SFR(IP2H, 0xb6);
SFR(IPH, 0xb7);
SFR(IP, 0xb8);
SBIT(PPCA, IP ^ 7);
SBIT(PLVD, IP ^ 6);
SBIT(PADC, IP ^ 5);
SBIT(PS, IP ^ 4);
SBIT(PT1, IP ^ 3);
SBIT(PX1, IP ^ 2);
SBIT(PT0, IP ^ 1);
SBIT(PX0, IP ^ 0);
SFR(SADEN, 0xb9);
SFR(P_SW2, 0xba);
SFR(ADC_CONTR, 0xbc);
SFR(ADC_RES, 0xbd);
SFR(ADC_RESL, 0xbe);
SFR(P4, 0xc0);
SBIT(P40, P4 ^ 0);
SBIT(P41, P4 ^ 1);
SBIT(P42, P4 ^ 2);
SBIT(P43, P4 ^ 3);
SBIT(P44, P4 ^ 4);
SBIT(P45, P4 ^ 5);
SBIT(P46, P4 ^ 6);
SBIT(P47, P4 ^ 7);
SFR(WDT_CONTR, 0xc1);
SFR(IAP_DATA, 0xc2);
SFR(IAP_ADDRH, 0xc3);
SFR(IAP_ADDRL, 0xc4);
SFR(IAP_CMD, 0xc5);
SFR(IAP_TRIG, 0xc6);
SFR(IAP_CONTR, 0xc7);
SFR(P5, 0xc8);
SBIT(P50, P5 ^ 0);
SBIT(P51, P5 ^ 1);
SBIT(P52, P5 ^ 2);
SBIT(P53, P5 ^ 3);
SBIT(P54, P5 ^ 4);
SBIT(P55, P5 ^ 5);
SBIT(P56, P5 ^ 6);
SBIT(P57, P5 ^ 7);
SFR(P5M1, 0xc9);
SFR(P5M0, 0xca);
SFR(P6M1, 0xcb);
SFR(P6M0, 0xcc);
SFR(SPSTAT, 0xcd);
SFR(SPCTL, 0xce);
SFR(SPDAT, 0xcf);
SFR(PSW, 0xd0);
SBIT(CY, PSW ^ 7);
SBIT(AC, PSW ^ 6);
SBIT(F0, PSW ^ 5);
SBIT(RS1, PSW ^ 4);
SBIT(RS0, PSW ^ 3);
SBIT(OV, PSW ^ 2);
SBIT(F1, PSW ^ 1);
SBIT(P, PSW ^ 0);
SFR(T4T3M, 0xd1);
SFR(T4H, 0xd2);
SFR(T4L, 0xd3);
SFR(T3H, 0xd4);
SFR(T3L, 0xd5);
SFR(T2H, 0xd6);
SFR(T2L, 0xd7);
SFR(USBCLK, 0xdc);
SFR(ADCCFG, 0xde);
SFR(IP3, 0xdf);
SFR(ACC, 0xe0);
SFR(P7M1, 0xe1);
SFR(P7M0, 0xe2);
SFR(DPS, 0xe3);
SFR(DPL1, 0xe4);
SFR(DPH1, 0xe5);
SFR(CMPCR1, 0xe6);
SFR(CMPCR2, 0xe7);
SFR(P6, 0xe8);
SFR(USBDAT, 0xec);
SFR(IP3H, 0xee);
SFR(AUXINTIF, 0xef);
SFR(B, 0xf0);
SFR(USBCON, 0xf4);
SFR(IAP_TPS, 0xf5);
SFR(P7, 0xf8);
SFR(USBADR, 0xfc);
SFR(RSTCFG, 0xff);

// 如下特殊功能寄存器位于扩展RAM区域
// 访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写

/////////////////////////////////////////////////
// FF00H-FFFFH
/////////////////////////////////////////////////

/////////////////////////////////////////////////
// FE00H-FEFFH
/////////////////////////////////////////////////

#define CKSEL (*(unsigned char volatile xdata *)0xfe00)
#define CLKDIV (*(unsigned char volatile xdata *)0xfe01)
#define HIRCCR (*(unsigned char volatile xdata *)0xfe02)
#define XOSCCR (*(unsigned char volatile xdata *)0xfe03)
#define IRC32KCR (*(unsigned char volatile xdata *)0xfe04)
#define MCLKOCR (*(unsigned char volatile xdata *)0xfe05)
#define IRCDB (*(unsigned char volatile xdata *)0xfe06)
#define X32KCR (*(unsigned char volatile xdata *)0xfe08)

#define P0PU (*(unsigned char volatile xdata *)0xfe10)
#define P1PU (*(unsigned char volatile xdata *)0xfe11)
#define P2PU (*(unsigned char volatile xdata *)0xfe12)
#define P3PU (*(unsigned char volatile xdata *)0xfe13)
#define P4PU (*(unsigned char volatile xdata *)0xfe14)
#define P5PU (*(unsigned char volatile xdata *)0xfe15)
#define P6PU (*(unsigned char volatile xdata *)0xfe16)
#define P7PU (*(unsigned char volatile xdata *)0xfe17)
#define P0NCS (*(unsigned char volatile xdata *)0xfe18)
#define P1NCS (*(unsigned char volatile xdata *)0xfe19)
#define P2NCS (*(unsigned char volatile xdata *)0xfe1a)
#define P3NCS (*(unsigned char volatile xdata *)0xfe1b)
#define P4NCS (*(unsigned char volatile xdata *)0xfe1c)
#define P5NCS (*(unsigned char volatile xdata *)0xfe1d)
#define P6NCS (*(unsigned char volatile xdata *)0xfe1e)
#define P7NCS (*(unsigned char volatile xdata *)0xfe1f)
#define P0SR (*(unsigned char volatile xdata *)0xfe20)
#define P1SR (*(unsigned char volatile xdata *)0xfe21)
#define P2SR (*(unsigned char volatile xdata *)0xfe22)
#define P3SR (*(unsigned char volatile xdata *)0xfe23)
#define P4SR (*(unsigned char volatile xdata *)0xfe24)
#define P5SR (*(unsigned char volatile xdata *)0xfe25)
#define P6SR (*(unsigned char volatile xdata *)0xfe26)
#define P7SR (*(unsigned char volatile xdata *)0xfe27)
#define P0DR (*(unsigned char volatile xdata *)0xfe28)
#define P1DR (*(unsigned char volatile xdata *)0xfe29)
#define P2DR (*(unsigned char volatile xdata *)0xfe2a)
#define P3DR (*(unsigned char volatile xdata *)0xfe2b)
#define P4DR (*(unsigned char volatile xdata *)0xfe2c)
#define P5DR (*(unsigned char volatile xdata *)0xfe2d)
#define P6DR (*(unsigned char volatile xdata *)0xfe2e)
#define P7DR (*(unsigned char volatile xdata *)0xfe2f)
#define P0IE (*(unsigned char volatile xdata *)0xfe30)
#define P1IE (*(unsigned char volatile xdata *)0xfe31)
#define P2IE (*(unsigned char volatile xdata *)0xfe32)
#define P3IE (*(unsigned char volatile xdata *)0xfe33)
#define P4IE (*(unsigned char volatile xdata *)0xfe34)
#define P5IE (*(unsigned char volatile xdata *)0xfe35)
#define P6IE (*(unsigned char volatile xdata *)0xfe36)
#define P7IE (*(unsigned char volatile xdata *)0xfe37)

#define RTCCR (*(unsigned char volatile xdata *)0xfe60)
#define RTCCFG (*(unsigned char volatile xdata *)0xfe61)
#define RTCIEN (*(unsigned char volatile xdata *)0xfe62)
#define RTCIF (*(unsigned char volatile xdata *)0xfe63)
#define ALAHOUR (*(unsigned char volatile xdata *)0xfe64)
#define ALAMIN (*(unsigned char volatile xdata *)0xfe65)
#define ALASEC (*(unsigned char volatile xdata *)0xfe66)
#define ALASSEC (*(unsigned char volatile xdata *)0xfe67)
#define INIYEAR (*(unsigned char volatile xdata *)0xfe68)
#define INIMONTH (*(unsigned char volatile xdata *)0xfe69)
#define INIDAY (*(unsigned char volatile xdata *)0xfe6a)
#define INIHOUR (*(unsigned char volatile xdata *)0xfe6b)
#define INIMIN (*(unsigned char volatile xdata *)0xfe6c)
#define INISEC (*(unsigned char volatile xdata *)0xfe6d)
#define INISSEC (*(unsigned char volatile xdata *)0xfe6e)
#define YEAR (*(unsigned char volatile xdata *)0xfe70)
#define MONTH (*(unsigned char volatile xdata *)0xfe71)
#define DAY (*(unsigned char volatile xdata *)0xfe72)
#define HOUR (*(unsigned char volatile xdata *)0xfe73)
#define MIN (*(unsigned char volatile xdata *)0xfe74)
#define SEC (*(unsigned char volatile xdata *)0xfe75)
#define SSEC (*(unsigned char volatile xdata *)0xfe76)

#define I2CCFG (*(unsigned char volatile xdata *)0xfe80)
#define I2CMSCR (*(unsigned char volatile xdata *)0xfe81)
#define I2CMSST (*(unsigned char volatile xdata *)0xfe82)
#define I2CSLCR (*(unsigned char volatile xdata *)0xfe83)
#define I2CSLST (*(unsigned char volatile xdata *)0xfe84)
#define I2CSLADR (*(unsigned char volatile xdata *)0xfe85)
#define I2CTXD (*(unsigned char volatile xdata *)0xfe86)
#define I2CRXD (*(unsigned char volatile xdata *)0xfe87)
#define I2CMSAUX (*(unsigned char volatile xdata *)0xfe88)
#define TM2PS (*(unsigned char volatile xdata *)0xfea2)
#define TM3PS (*(unsigned char volatile xdata *)0xfea3)
#define TM4PS (*(unsigned char volatile xdata *)0xfea4)
#define ADCTIM (*(unsigned char volatile xdata *)0xfea8)

#define PWM1_ETRPS (*(unsigned char volatile xdata *)0xfeb0)
#define PWM1_ENO (*(unsigned char volatile xdata *)0xfeb1)
#define PWM1_PS (*(unsigned char volatile xdata *)0xfeb2)
#define PWM1_IOAUX (*(unsigned char volatile xdata *)0xfeb3)
#define PWM2_ETRPS (*(unsigned char volatile xdata *)0xfeb4)
#define PWM2_ENO (*(unsigned char volatile xdata *)0xfeb5)
#define PWM2_PS (*(unsigned char volatile xdata *)0xfeb6)
#define PWM2_IOAUX (*(unsigned char volatile xdata *)0xfeb7)
#define PWM1_CR1 (*(unsigned char volatile xdata *)0xfec0)
#define PWM1_CR2 (*(unsigned char volatile xdata *)0xfec1)
#define PWM1_SMCR (*(unsigned char volatile xdata *)0xfec2)
#define PWM1_ETR (*(unsigned char volatile xdata *)0xfec3)
#define PWM1_IER (*(unsigned char volatile xdata *)0xfec4)
#define PWM1_SR1 (*(unsigned char volatile xdata *)0xfec5)
#define PWM1_SR2 (*(unsigned char volatile xdata *)0xfec6)
#define PWM1_EGR (*(unsigned char volatile xdata *)0xfec7)
#define PWM1_CCMR1 (*(unsigned char volatile xdata *)0xfec8)
#define PWM1_CCMR2 (*(unsigned char volatile xdata *)0xfec9)
#define PWM1_CCMR3 (*(unsigned char volatile xdata *)0xfeca)
#define PWM1_CCMR4 (*(unsigned char volatile xdata *)0xfecb)
#define PWM1_CCER1 (*(unsigned char volatile xdata *)0xfecc)
#define PWM1_CCER2 (*(unsigned char volatile xdata *)0xfecd)
#define PWM1_CNTR (*(unsigned int volatile xdata *)0xfece)
#define PWM1_CNTRH (*(unsigned char volatile xdata *)0xfece)
#define PWM1_CNTRL (*(unsigned char volatile xdata *)0xfecf)
#define PWM1_PSCR (*(unsigned int volatile xdata *)0xfed0)
#define PWM1_PSCRH (*(unsigned char volatile xdata *)0xfed0)
#define PWM1_PSCRL (*(unsigned char volatile xdata *)0xfed1)
#define PWM1_ARR (*(unsigned int volatile xdata *)0xfed2)
#define PWM1_ARRH (*(unsigned char volatile xdata *)0xfed2)
#define PWM1_ARRL (*(unsigned char volatile xdata *)0xfed3)
#define PWM1_RCR (*(unsigned char volatile xdata *)0xfed4)
#define PWM1_CCR1 (*(unsigned int volatile xdata *)0xfed5)
#define PWM1_CCR1H (*(unsigned char volatile xdata *)0xfed5)
#define PWM1_CCR1L (*(unsigned char volatile xdata *)0xfed6)
#define PWM1_CCR2 (*(unsigned int volatile xdata *)0xfed7)
#define PWM1_CCR2H (*(unsigned char volatile xdata *)0xfed7)
#define PWM1_CCR2L (*(unsigned char volatile xdata *)0xfed8)
#define PWM1_CCR3 (*(unsigned int volatile xdata *)0xfed9)
#define PWM1_CCR3H (*(unsigned char volatile xdata *)0xfed9)
#define PWM1_CCR3L (*(unsigned char volatile xdata *)0xfeda)
#define PWM1_CCR4 (*(unsigned int volatile xdata *)0xfedb)
#define PWM1_CCR4H (*(unsigned char volatile xdata *)0xfedb)
#define PWM1_CCR4L (*(unsigned char volatile xdata *)0xfedc)
#define PWM1_BKR (*(unsigned char volatile xdata *)0xfedd)
#define PWM1_DTR (*(unsigned char volatile xdata *)0xfede)
#define PWM1_OISR (*(unsigned char volatile xdata *)0xfedf)
#define PWM2_CR1 (*(unsigned char volatile xdata *)0xfee0)
#define PWM2_CR2 (*(unsigned char volatile xdata *)0xfee1)
#define PWM2_SMCR (*(unsigned char volatile xdata *)0xfee2)
#define PWM2_ETR (*(unsigned char volatile xdata *)0xfee3)
#define PWM2_IER (*(unsigned char volatile xdata *)0xfee4)
#define PWM2_SR1 (*(unsigned char volatile xdata *)0xfee5)
#define PWM2_SR2 (*(unsigned char volatile xdata *)0xfee6)
#define PWM2_EGR (*(unsigned char volatile xdata *)0xfee7)
#define PWM2_CCMR1 (*(unsigned char volatile xdata *)0xfee8)
#define PWM2_CCMR2 (*(unsigned char volatile xdata *)0xfee9)
#define PWM2_CCMR3 (*(unsigned char volatile xdata *)0xfeea)
#define PWM2_CCMR4 (*(unsigned char volatile xdata *)0xfeeb)
#define PWM2_CCER1 (*(unsigned char volatile xdata *)0xfeec)
#define PWM2_CCER2 (*(unsigned char volatile xdata *)0xfeed)
#define PWM2_CNTR (*(unsigned int volatile xdata *)0xfeee)
#define PWM2_CNTRH (*(unsigned char volatile xdata *)0xfeee)
#define PWM2_CNTRL (*(unsigned char volatile xdata *)0xfeef)
#define PWM2_PSCR (*(unsigned int volatile xdata *)0xfef0)
#define PWM2_PSCRH (*(unsigned char volatile xdata *)0xfef0)
#define PWM2_PSCRL (*(unsigned char volatile xdata *)0xfef1)
#define PWM2_ARR (*(unsigned int volatile xdata *)0xfef2)
#define PWM2_ARRH (*(unsigned char volatile xdata *)0xfef2)
#define PWM2_ARRL (*(unsigned char volatile xdata *)0xfef3)
#define PWM2_RCR (*(unsigned char volatile xdata *)0xfef4)
#define PWM2_CCR1 (*(unsigned int volatile xdata *)0xfef5)
#define PWM2_CCR1H (*(unsigned char volatile xdata *)0xfef5)
#define PWM2_CCR1L (*(unsigned char volatile xdata *)0xfef6)
#define PWM2_CCR2 (*(unsigned int volatile xdata *)0xfef7)
#define PWM2_CCR2H (*(unsigned char volatile xdata *)0xfef7)
#define PWM2_CCR2L (*(unsigned char volatile xdata *)0xfef8)
#define PWM2_CCR3 (*(unsigned int volatile xdata *)0xfef9)
#define PWM2_CCR3H (*(unsigned char volatile xdata *)0xfef9)
#define PWM2_CCR3L (*(unsigned char volatile xdata *)0xfefa)
#define PWM2_CCR4 (*(unsigned int volatile xdata *)0xfefb)
#define PWM2_CCR4H (*(unsigned char volatile xdata *)0xfefb)
#define PWM2_CCR4L (*(unsigned char volatile xdata *)0xfefc)
#define PWM2_BKR (*(unsigned char volatile xdata *)0xfefd)
#define PWM2_DTR (*(unsigned char volatile xdata *)0xfefe)
#define PWM2_OISR (*(unsigned char volatile xdata *)0xfeff)

#define PWMA_ETRPS (*(unsigned char volatile xdata *)0xfeb0)
#define PWMA_ENO (*(unsigned char volatile xdata *)0xfeb1)
#define PWMA_PS (*(unsigned char volatile xdata *)0xfeb2)
#define PWMA_IOAUX (*(unsigned char volatile xdata *)0xfeb3)
#define PWMB_ETRPS (*(unsigned char volatile xdata *)0xfeb4)
#define PWMB_ENO (*(unsigned char volatile xdata *)0xfeb5)
#define PWMB_PS (*(unsigned char volatile xdata *)0xfeb6)
#define PWMB_IOAUX (*(unsigned char volatile xdata *)0xfeb7)
#define PWMA_CR1 (*(unsigned char volatile xdata *)0xfec0)
#define PWMA_CR2 (*(unsigned char volatile xdata *)0xfec1)
#define PWMA_SMCR (*(unsigned char volatile xdata *)0xfec2)
#define PWMA_ETR (*(unsigned char volatile xdata *)0xfec3)
#define PWMA_IER (*(unsigned char volatile xdata *)0xfec4)
#define PWMA_SR1 (*(unsigned char volatile xdata *)0xfec5)
#define PWMA_SR2 (*(unsigned char volatile xdata *)0xfec6)
#define PWMA_EGR (*(unsigned char volatile xdata *)0xfec7)
#define PWMA_CCMR1 (*(unsigned char volatile xdata *)0xfec8)
#define PWMA_CCMR2 (*(unsigned char volatile xdata *)0xfec9)
#define PWMA_CCMR3 (*(unsigned char volatile xdata *)0xfeca)
#define PWMA_CCMR4 (*(unsigned char volatile xdata *)0xfecb)
#define PWMA_CCER1 (*(unsigned char volatile xdata *)0xfecc)
#define PWMA_CCER2 (*(unsigned char volatile xdata *)0xfecd)
#define PWMA_CNTR (*(unsigned int volatile xdata *)0xfece)
#define PWMA_CNTRH (*(unsigned char volatile xdata *)0xfece)
#define PWMA_CNTRL (*(unsigned char volatile xdata *)0xfecf)
#define PWMA_PSCR (*(unsigned int volatile xdata *)0xfed0)
#define PWMA_PSCRH (*(unsigned char volatile xdata *)0xfed0)
#define PWMA_PSCRL (*(unsigned char volatile xdata *)0xfed1)
#define PWMA_ARR (*(unsigned int volatile xdata *)0xfed2)
#define PWMA_ARRH (*(unsigned char volatile xdata *)0xfed2)
#define PWMA_ARRL (*(unsigned char volatile xdata *)0xfed3)
#define PWMA_RCR (*(unsigned char volatile xdata *)0xfed4)
#define PWMA_CCR1 (*(unsigned int volatile xdata *)0xfed5)
#define PWMA_CCR1H (*(unsigned char volatile xdata *)0xfed5)
#define PWMA_CCR1L (*(unsigned char volatile xdata *)0xfed6)
#define PWMA_CCR2 (*(unsigned int volatile xdata *)0xfed7)
#define PWMA_CCR2H (*(unsigned char volatile xdata *)0xfed7)
#define PWMA_CCR2L (*(unsigned char volatile xdata *)0xfed8)
#define PWMA_CCR3 (*(unsigned int volatile xdata *)0xfed9)
#define PWMA_CCR3H (*(unsigned char volatile xdata *)0xfed9)
#define PWMA_CCR3L (*(unsigned char volatile xdata *)0xfeda)
#define PWMA_CCR4 (*(unsigned int volatile xdata *)0xfedb)
#define PWMA_CCR4H (*(unsigned char volatile xdata *)0xfedb)
#define PWMA_CCR4L (*(unsigned char volatile xdata *)0xfedc)
#define PWMA_BKR (*(unsigned char volatile xdata *)0xfedd)
#define PWMA_DTR (*(unsigned char volatile xdata *)0xfede)
#define PWMA_OISR (*(unsigned char volatile xdata *)0xfedf)
#define PWMB_CR1 (*(unsigned char volatile xdata *)0xfee0)
#define PWMB_CR2 (*(unsigned char volatile xdata *)0xfee1)
#define PWMB_SMCR (*(unsigned char volatile xdata *)0xfee2)
#define PWMB_ETR (*(unsigned char volatile xdata *)0xfee3)
#define PWMB_IER (*(unsigned char volatile xdata *)0xfee4)
#define PWMB_SR1 (*(unsigned char volatile xdata *)0xfee5)
#define PWMB_SR2 (*(unsigned char volatile xdata *)0xfee6)
#define PWMB_EGR (*(unsigned char volatile xdata *)0xfee7)
#define PWMB_CCMR1 (*(unsigned char volatile xdata *)0xfee8)
#define PWMB_CCMR2 (*(unsigned char volatile xdata *)0xfee9)
#define PWMB_CCMR3 (*(unsigned char volatile xdata *)0xfeea)
#define PWMB_CCMR4 (*(unsigned char volatile xdata *)0xfeeb)
#define PWMB_CCER1 (*(unsigned char volatile xdata *)0xfeec)
#define PWMB_CCER2 (*(unsigned char volatile xdata *)0xfeed)
#define PWMB_CNTR (*(unsigned int volatile xdata *)0xfeee)
#define PWMB_CNTRH (*(unsigned char volatile xdata *)0xfeee)
#define PWMB_CNTRL (*(unsigned char volatile xdata *)0xfeef)
#define PWMB_PSCR (*(unsigned int volatile xdata *)0xfef0)
#define PWMB_PSCRH (*(unsigned char volatile xdata *)0xfef0)
#define PWMB_PSCRL (*(unsigned char volatile xdata *)0xfef1)
#define PWMB_ARR (*(unsigned int volatile xdata *)0xfef2)
#define PWMB_ARRH (*(unsigned char volatile xdata *)0xfef2)
#define PWMB_ARRL (*(unsigned char volatile xdata *)0xfef3)
#define PWMB_RCR (*(unsigned char volatile xdata *)0xfef4)
#define PWMB_CCR5 (*(unsigned int volatile xdata *)0xfef5)
#define PWMB_CCR5H (*(unsigned char volatile xdata *)0xfef5)
#define PWMB_CCR5L (*(unsigned char volatile xdata *)0xfef6)
#define PWMB_CCR6 (*(unsigned int volatile xdata *)0xfef7)
#define PWMB_CCR6H (*(unsigned char volatile xdata *)0xfef7)
#define PWMB_CCR6L (*(unsigned char volatile xdata *)0xfef8)
#define PWMB_CCR7 (*(unsigned int volatile xdata *)0xfef9)
#define PWMB_CCR7H (*(unsigned char volatile xdata *)0xfef9)
#define PWMB_CCR7L (*(unsigned char volatile xdata *)0xfefa)
#define PWMB_CCR8 (*(unsigned int volatile xdata *)0xfefb)
#define PWMB_CCR8H (*(unsigned char volatile xdata *)0xfefb)
#define PWMB_CCR8L (*(unsigned char volatile xdata *)0xfefc)
#define PWMB_BKR (*(unsigned char volatile xdata *)0xfefd)
#define PWMB_DTR (*(unsigned char volatile xdata *)0xfefe)
#define PWMB_OISR (*(unsigned char volatile xdata *)0xfeff)

/////////////////////////////////////////////////
// FD00H-FDFFH
/////////////////////////////////////////////////

#define P0INTE (*(unsigned char volatile xdata *)0xfd00)
#define P1INTE (*(unsigned char volatile xdata *)0xfd01)
#define P2INTE (*(unsigned char volatile xdata *)0xfd02)
#define P3INTE (*(unsigned char volatile xdata *)0xfd03)
#define P4INTE (*(unsigned char volatile xdata *)0xfd04)
#define P5INTE (*(unsigned char volatile xdata *)0xfd05)
#define P6INTE (*(unsigned char volatile xdata *)0xfd06)
#define P7INTE (*(unsigned char volatile xdata *)0xfd07)
#define P0INTF (*(unsigned char volatile xdata *)0xfd10)
#define P1INTF (*(unsigned char volatile xdata *)0xfd11)
#define P2INTF (*(unsigned char volatile xdata *)0xfd12)
#define P3INTF (*(unsigned char volatile xdata *)0xfd13)
#define P4INTF (*(unsigned char volatile xdata *)0xfd14)
#define P5INTF (*(unsigned char volatile xdata *)0xfd15)
#define P6INTF (*(unsigned char volatile xdata *)0xfd16)
#define P7INTF (*(unsigned char volatile xdata *)0xfd17)
#define P0IM0 (*(unsigned char volatile xdata *)0xfd20)
#define P1IM0 (*(unsigned char volatile xdata *)0xfd21)
#define P2IM0 (*(unsigned char volatile xdata *)0xfd22)
#define P3IM0 (*(unsigned char volatile xdata *)0xfd23)
#define P4IM0 (*(unsigned char volatile xdata *)0xfd24)
#define P5IM0 (*(unsigned char volatile xdata *)0xfd25)
#define P6IM0 (*(unsigned char volatile xdata *)0xfd26)
#define P7IM0 (*(unsigned char volatile xdata *)0xfd27)
#define P0IM1 (*(unsigned char volatile xdata *)0xfd30)
#define P1IM1 (*(unsigned char volatile xdata *)0xfd31)
#define P2IM1 (*(unsigned char volatile xdata *)0xfd32)
#define P3IM1 (*(unsigned char volatile xdata *)0xfd33)
#define P4IM1 (*(unsigned char volatile xdata *)0xfd34)
#define P5IM1 (*(unsigned char volatile xdata *)0xfd35)
#define P6IM1 (*(unsigned char volatile xdata *)0xfd36)
#define P7IM1 (*(unsigned char volatile xdata *)0xfd37)
#define P0WKUE (*(unsigned char volatile xdata *)0xfd40)
#define P1WKUE (*(unsigned char volatile xdata *)0xfd41)
#define P2WKUE (*(unsigned char volatile xdata *)0xfd42)
#define P3WKUE (*(unsigned char volatile xdata *)0xfd43)
#define P4WKUE (*(unsigned char volatile xdata *)0xfd44)
#define P5WKUE (*(unsigned char volatile xdata *)0xfd45)
#define P6WKUE (*(unsigned char volatile xdata *)0xfd46)
#define P7WKUE (*(unsigned char volatile xdata *)0xfd47)
#define PIN_IP (*(unsigned char volatile xdata *)0xfd60)
#define PIN_IPH (*(unsigned char volatile xdata *)0xfd61)

/////////////////////////////////////////////////
// FC00H-FCFFH
/////////////////////////////////////////////////

#define MD3 (*(unsigned char volatile xdata *)0xfcf0)
#define MD2 (*(unsigned char volatile xdata *)0xfcf1)
#define MD1 (*(unsigned char volatile xdata *)0xfcf2)
#define MD0 (*(unsigned char volatile xdata *)0xfcf3)
#define MD5 (*(unsigned char volatile xdata *)0xfcf4)
#define MD4 (*(unsigned char volatile xdata *)0xfcf5)
#define ARCON (*(unsigned char volatile xdata *)0xfcf6)
#define OPCON (*(unsigned char volatile xdata *)0xfcf7)

/////////////////////////////////////////////////
// FB00H-FBFFH
/////////////////////////////////////////////////

#define COMEN (*(unsigned char volatile xdata *)0xfb00)
#define SEGENL (*(unsigned char volatile xdata *)0xfb01)
#define SEGENH (*(unsigned char volatile xdata *)0xfb02)
#define LEDCTRL (*(unsigned char volatile xdata *)0xfb03)
#define LEDCKS (*(unsigned char volatile xdata *)0xfb04)
#define COM0_DA_L (*(unsigned char volatile xdata *)0xfb10)
#define COM1_DA_L (*(unsigned char volatile xdata *)0xfb11)
#define COM2_DA_L (*(unsigned char volatile xdata *)0xfb12)
#define COM3_DA_L (*(unsigned char volatile xdata *)0xfb13)
#define COM4_DA_L (*(unsigned char volatile xdata *)0xfb14)
#define COM5_DA_L (*(unsigned char volatile xdata *)0xfb15)
#define COM6_DA_L (*(unsigned char volatile xdata *)0xfb16)
#define COM7_DA_L (*(unsigned char volatile xdata *)0xfb17)
#define COM0_DA_H (*(unsigned char volatile xdata *)0xfb18)
#define COM1_DA_H (*(unsigned char volatile xdata *)0xfb19)
#define COM2_DA_H (*(unsigned char volatile xdata *)0xfb1a)
#define COM3_DA_H (*(unsigned char volatile xdata *)0xfb1b)
#define COM4_DA_H (*(unsigned char volatile xdata *)0xfb1c)
#define COM5_DA_H (*(unsigned char volatile xdata *)0xfb1d)
#define COM6_DA_H (*(unsigned char volatile xdata *)0xfb1e)
#define COM7_DA_H (*(unsigned char volatile xdata *)0xfb1f)
#define COM0_DC_L (*(unsigned char volatile xdata *)0xfb20)
#define COM1_DC_L (*(unsigned char volatile xdata *)0xfb21)
#define COM2_DC_L (*(unsigned char volatile xdata *)0xfb22)
#define COM3_DC_L (*(unsigned char volatile xdata *)0xfb23)
#define COM4_DC_L (*(unsigned char volatile xdata *)0xfb24)
#define COM5_DC_L (*(unsigned char volatile xdata *)0xfb25)
#define COM6_DC_L (*(unsigned char volatile xdata *)0xfb26)
#define COM7_DC_L (*(unsigned char volatile xdata *)0xfb27)
#define COM0_DC_H (*(unsigned char volatile xdata *)0xfb28)
#define COM1_DC_H (*(unsigned char volatile xdata *)0xfb29)
#define COM2_DC_H (*(unsigned char volatile xdata *)0xfb2a)
#define COM3_DC_H (*(unsigned char volatile xdata *)0xfb2b)
#define COM4_DC_H (*(unsigned char volatile xdata *)0xfb2c)
#define COM5_DC_H (*(unsigned char volatile xdata *)0xfb2d)
#define COM6_DC_H (*(unsigned char volatile xdata *)0xfb2e)
#define COM7_DC_H (*(unsigned char volatile xdata *)0xfb2f)

#define TSCHEN1 (*(unsigned char volatile xdata *)0xfb40)
#define TSCHEN2 (*(unsigned char volatile xdata *)0xfb41)
#define TSCFG1 (*(unsigned char volatile xdata *)0xfb42)
#define TSCFG2 (*(unsigned char volatile xdata *)0xfb43)
#define TSWUTC (*(unsigned char volatile xdata *)0xfb44)
#define TSCTRL (*(unsigned char volatile xdata *)0xfb45)
#define TSSTA1 (*(unsigned char volatile xdata *)0xfb46)
#define TSSTA2 (*(unsigned char volatile xdata *)0xfb47)
#define TSRT (*(unsigned char volatile xdata *)0xfb48)
#define TSDAT (*(unsigned int volatile xdata *)0xfb49)
#define TSDATH (*(unsigned char volatile xdata *)0xfb49)
#define TSDATL (*(unsigned char volatile xdata *)0xfb4A)
#define TSTH00 (*(unsigned int volatile xdata *)0xfb50)
#define TSTH00H (*(unsigned char volatile xdata *)0xfb50)
#define TSTH00L (*(unsigned char volatile xdata *)0xfb51)
#define TSTH01 (*(unsigned int volatile xdata *)0xfb52)
#define TSTH01H (*(unsigned char volatile xdata *)0xfb52)
#define TSTH01L (*(unsigned char volatile xdata *)0xfb53)
#define TSTH02 (*(unsigned int volatile xdata *)0xfb54)
#define TSTH02H (*(unsigned char volatile xdata *)0xfb54)
#define TSTH02L (*(unsigned char volatile xdata *)0xfb55)
#define TSTH03 (*(unsigned int volatile xdata *)0xfb56)
#define TSTH03H (*(unsigned char volatile xdata *)0xfb56)
#define TSTH03L (*(unsigned char volatile xdata *)0xfb57)
#define TSTH04 (*(unsigned int volatile xdata *)0xfb58)
#define TSTH04H (*(unsigned char volatile xdata *)0xfb58)
#define TSTH04L (*(unsigned char volatile xdata *)0xfb59)
#define TSTH05 (*(unsigned int volatile xdata *)0xfb5a)
#define TSTH05H (*(unsigned char volatile xdata *)0xfb5a)
#define TSTH05L (*(unsigned char volatile xdata *)0xfb5b)
#define TSTH06 (*(unsigned int volatile xdata *)0xfb5c)
#define TSTH06H (*(unsigned char volatile xdata *)0xfb5c)
#define TSTH06L (*(unsigned char volatile xdata *)0xfb5d)
#define TSTH07 (*(unsigned int volatile xdata *)0xfb5e)
#define TSTH07H (*(unsigned char volatile xdata *)0xfb5e)
#define TSTH07L (*(unsigned char volatile xdata *)0xfb5f)
#define TSTH08 (*(unsigned int volatile xdata *)0xfb60)
#define TSTH08H (*(unsigned char volatile xdata *)0xfb60)
#define TSTH08L (*(unsigned char volatile xdata *)0xfb61)
#define TSTH09 (*(unsigned int volatile xdata *)0xfb62)
#define TSTH09H (*(unsigned char volatile xdata *)0xfb62)
#define TSTH09L (*(unsigned char volatile xdata *)0xfb63)
#define TSTH10 (*(unsigned int volatile xdata *)0xfb64)
#define TSTH10H (*(unsigned char volatile xdata *)0xfb64)
#define TSTH10L (*(unsigned char volatile xdata *)0xfb65)
#define TSTH11 (*(unsigned int volatile xdata *)0xfb66)
#define TSTH11H (*(unsigned char volatile xdata *)0xfb66)
#define TSTH11L (*(unsigned char volatile xdata *)0xfb67)
#define TSTH12 (*(unsigned int volatile xdata *)0xfb68)
#define TSTH12H (*(unsigned char volatile xdata *)0xfb68)
#define TSTH12L (*(unsigned char volatile xdata *)0xfb69)
#define TSTH13 (*(unsigned int volatile xdata *)0xfb6a)
#define TSTH13H (*(unsigned char volatile xdata *)0xfb6a)
#define TSTH13L (*(unsigned char volatile xdata *)0xfb6b)
#define TSTH14 (*(unsigned int volatile xdata *)0xfb6c)
#define TSTH14H (*(unsigned char volatile xdata *)0xfb6c)
#define TSTH14L (*(unsigned char volatile xdata *)0xfb6d)
#define TSTH15 (*(unsigned int volatile xdata *)0xfb6e)
#define TSTH15H (*(unsigned char volatile xdata *)0xfb6e)
#define TSTH15L (*(unsigned char volatile xdata *)0xfb6f)

/////////////////////////////////////////////////
// FA00H-FAFFH
/////////////////////////////////////////////////

/////////////////////////////////////////////////

#endif
