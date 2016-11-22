//*****************************************************************************
//
// Copyright (C) 2012 - 2015 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//  Redistributions of source code must retain the above copyright
//  notice, this list of conditions and the following disclaimer.
//
//  Redistributions in binary form must reproduce the above copyright
//  notice, this list of conditions and the following disclaimer in the
//  documentation and/or other materials provided with the
//  distribution.
//
//  Neither the name of Texas Instruments Incorporated nor the names of
//  its contributors may be used to endorse or promote products derived
//  from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//****************************************************************************


/************************************************************
* ADC
************************************************************/

#ifdef __MSP430_HAS_ADC__

#define ADCIV_ADCHIIFG          ADCIV__ADCHIIFG
#define ADCIV_ADCIFG            ADCIV__ADCIFG0
#define ADCIV_ADCINIFG          ADCIV__ADCINIFG
#define ADCIV_ADCLOIFG          ADCIV__ADCLOIFG
#define ADCIV_ADCOVIFG          ADCIV__ADCOVIFG
#define ADCIV_ADCTOVIFG         ADCIV__ADCTOVIFG
#define ADCIV_NONE              ADCIV__NONE

#endif

/************************************************************
* ADC12_B
************************************************************/
#ifdef __MSP430_HAS_ADC12_B__

#define ADC12_VECTOR         ADC12_B_VECTOR

#define ADC12IV_NONE         ADC12IV__NONE
#define ADC12IV_ADC12HIIFG   ADC12IV__ADC12HIIFG
#define ADC12IV_ADC12IFG0    ADC12IV__ADC12IFG0
#define ADC12IV_ADC12IFG1    ADC12IV__ADC12IFG1
#define ADC12IV_ADC12IFG2    ADC12IV__ADC12IFG2
#define ADC12IV_ADC12IFG3    ADC12IV__ADC12IFG3
#define ADC12IV_ADC12IFG4    ADC12IV__ADC12IFG4
#define ADC12IV_ADC12IFG5    ADC12IV__ADC12IFG5
#define ADC12IV_ADC12IFG6    ADC12IV__ADC12IFG6
#define ADC12IV_ADC12IFG7    ADC12IV__ADC12IFG7
#define ADC12IV_ADC12IFG8    ADC12IV__ADC12IFG8
#define ADC12IV_ADC12IFG9    ADC12IV__ADC12IFG9
#define ADC12IV_ADC12IFG10   ADC12IV__ADC12IFG10
#define ADC12IV_ADC12IFG11   ADC12IV__ADC12IFG11
#define ADC12IV_ADC12IFG12   ADC12IV__ADC12IFG12
#define ADC12IV_ADC12IFG13   ADC12IV__ADC12IFG13
#define ADC12IV_ADC12IFG14   ADC12IV__ADC12IFG14
#define ADC12IV_ADC12IFG15   ADC12IV__ADC12IFG15
#define ADC12IV_ADC12IFG16   ADC12IV__ADC12IFG16
#define ADC12IV_ADC12IFG17   ADC12IV__ADC12IFG17
#define ADC12IV_ADC12IFG18   ADC12IV__ADC12IFG18
#define ADC12IV_ADC12IFG19   ADC12IV__ADC12IFG19
#define ADC12IV_ADC12IFG20   ADC12IV__ADC12IFG20
#define ADC12IV_ADC12IFG21   ADC12IV__ADC12IFG21
#define ADC12IV_ADC12IFG22   ADC12IV__ADC12IFG22
#define ADC12IV_ADC12IFG23   ADC12IV__ADC12IFG23
#define ADC12IV_ADC12IFG24   ADC12IV__ADC12IFG24
#define ADC12IV_ADC12IFG25   ADC12IV__ADC12IFG25
#define ADC12IV_ADC12IFG26   ADC12IV__ADC12IFG26
#define ADC12IV_ADC12IFG27   ADC12IV__ADC12IFG27
#define ADC12IV_ADC12IFG28   ADC12IV__ADC12IFG28
#define ADC12IV_ADC12IFG29   ADC12IV__ADC12IFG29
#define ADC12IV_ADC12IFG30   ADC12IV__ADC12IFG30
#define ADC12IV_ADC12IFG31   ADC12IV__ADC12IFG31
#define ADC12IV_ADC12INIFG   ADC12IV__ADC12INIFG
#define ADC12IV_ADC12LOIFG   ADC12IV__ADC12LOIFG
#define ADC12IV_ADC12OVIFG   ADC12IV__ADC12OVIFG
#define ADC12IV_ADC12RDYIFG  ADC12IV__ADC12RDYIFG
#define ADC12IV_ADC12TOVIFG  ADC12IV__ADC12TOVIFG

#endif

/************************************************************
* CAP TOUCH
************************************************************/

#ifdef __MSP430_HAS_CAPTIO0__
#define __MSP430_HAS_CAP_TOUCH_IO_0__
#define CAP_TOUCH_0_BASE    CAPTIO0_BASE
#define __MSP430_BASEADDRESS_CAP_TOUCH_IO_0__ CAPTIO0_BASE
#define CAPSIO0CTL          CAPTIO0CTL
#endif
#ifdef __MSP430_HAS_CAPTIO1__
#define __MSP430_HAS_CAP_TOUCH_IO_1__
#define __MSP430_BASEADDRESS_CAP_TOUCH_IO_1__ CAPTIO1_BASE
#define CAP_TOUCH_1_BASE    CAPTIO1_BASE
#define CAPSIO1CTL          CAPTIO1CTL
#endif

#ifdef __MSP430_HAS_CAPTIOx__

#define CAPSIOPISEL0            CAPTIOPISEL0
#define CAPSIOPISEL1            CAPTIOPISEL1
#define CAPSIOPISEL2            CAPTIOPISEL2
#define CAPSIOPOSEL0            CAPTIOPOSEL0
#define CAPSIOPOSEL1            CAPTIOPOSEL1
#define CAPSIOPOSEL2            CAPTIOPOSEL2
#define CAPSIOPOSEL3            CAPTIOPOSEL3
#define CAPSIOEN                CAPTIOEN
#define CAPSIO                  CAPTIO

#endif

/************************************************************
* CLOCK SYSTEM
************************************************************/

#ifdef __MSP430_HAS_CS__

#ifdef __MSP430FR2XX_FR4XX_FAMILY__

#define DCOFTRIM_0              (0x0000)    /* DCO frequency trim: 0 */
#define DCOFTRIM_1              (0x0010)    /* DCO frequency trim: 1 */
#define DCOFTRIM_2              (0x0020)    /* DCO frequency trim: 2 */
#define DCOFTRIM_3              (0x0030)    /* DCO frequency trim: 3 */
#define DCOFTRIM_4              (0x0040)    /* DCO frequency trim: 4 */
#define DCOFTRIM_5              (0x0050)    /* DCO frequency trim: 5 */
#define DCOFTRIM_6              (0x0060)    /* DCO frequency trim: 6 */
#define DCOFTRIM_7              (0x0070)    /* DCO frequency trim: 7 */

#endif

#define SELM__LFMODOSC          SELM__LFMODCLK
#define SELM__MODOSC            SELM__MODCLK
#define SELS__LFMODOSC          SELS__LFMODCLK
#define SELS__MODOSC            SELS__MODCLK
#define SELA__LFMODOSC          SELA__LFMODCLK

#define SELA_7                  SELA
#define SELM_7                  SELM
#define SELS_7                  SELS

#ifndef MODCLKREQEN
#define MODCLKREQEN             MODOSCREQEN
#define MODCLKREQEN_L           MODOSCREQEN_L
#endif

#endif

/************************************************************
* COMP_E
************************************************************/

#ifdef __MSP430_HAS_COMP_E__

#define CEIV_CEIFG              CEIV__CEIFG
#define CEIV_CEIIFG             CEIV__CEIIFG
#define CEIV_CERDYIFG           CEIV__CERDYIFG
#define CEIV_NONE               CEIV__NONE

#define CEPWRMD_3               CEPWRMD

#define CEREF0_0                (0x0000)       /* Comp. E Int. Ref.0 Select 0 : 1/32 */
#define CEREF0_1                (0x0001)       /* Comp. E Int. Ref.0 Select 1 : 2/32 */
#define CEREF0_2                (0x0002)       /* Comp. E Int. Ref.0 Select 2 : 3/32 */
#define CEREF0_3                (0x0003)       /* Comp. E Int. Ref.0 Select 3 : 4/32 */
#define CEREF0_4                (0x0004)       /* Comp. E Int. Ref.0 Select 4 : 5/32 */
#define CEREF0_5                (0x0005)       /* Comp. E Int. Ref.0 Select 5 : 6/32 */
#define CEREF0_6                (0x0006)       /* Comp. E Int. Ref.0 Select 6 : 7/32 */
#define CEREF0_7                (0x0007)       /* Comp. E Int. Ref.0 Select 7 : 8/32 */
#define CEREF0_8                (0x0008)       /* Comp. E Int. Ref.0 Select 0 : 9/32 */
#define CEREF0_9                (0x0009)       /* Comp. E Int. Ref.0 Select 1 : 10/32 */
#define CEREF0_10               (0x000A)       /* Comp. E Int. Ref.0 Select 2 : 11/32 */
#define CEREF0_11               (0x000B)       /* Comp. E Int. Ref.0 Select 3 : 12/32 */
#define CEREF0_12               (0x000C)       /* Comp. E Int. Ref.0 Select 4 : 13/32 */
#define CEREF0_13               (0x000D)       /* Comp. E Int. Ref.0 Select 5 : 14/32 */
#define CEREF0_14               (0x000E)       /* Comp. E Int. Ref.0 Select 6 : 15/32 */
#define CEREF0_15               (0x000F)       /* Comp. E Int. Ref.0 Select 7 : 16/32 */
#define CEREF0_16               (0x0010)       /* Comp. E Int. Ref.0 Select 0 : 17/32 */
#define CEREF0_17               (0x0011)       /* Comp. E Int. Ref.0 Select 1 : 18/32 */
#define CEREF0_18               (0x0012)       /* Comp. E Int. Ref.0 Select 2 : 19/32 */
#define CEREF0_19               (0x0013)       /* Comp. E Int. Ref.0 Select 3 : 20/32 */
#define CEREF0_20               (0x0014)       /* Comp. E Int. Ref.0 Select 4 : 21/32 */
#define CEREF0_21               (0x0015)       /* Comp. E Int. Ref.0 Select 5 : 22/32 */
#define CEREF0_22               (0x0016)       /* Comp. E Int. Ref.0 Select 6 : 23/32 */
#define CEREF0_23               (0x0017)       /* Comp. E Int. Ref.0 Select 7 : 24/32 */
#define CEREF0_24               (0x0018)       /* Comp. E Int. Ref.0 Select 0 : 25/32 */
#define CEREF0_25               (0x0019)       /* Comp. E Int. Ref.0 Select 1 : 26/32 */
#define CEREF0_26               (0x001A)       /* Comp. E Int. Ref.0 Select 2 : 27/32 */
#define CEREF0_27               (0x001B)       /* Comp. E Int. Ref.0 Select 3 : 28/32 */
#define CEREF0_28               (0x001C)       /* Comp. E Int. Ref.0 Select 4 : 29/32 */
#define CEREF0_29               (0x001D)       /* Comp. E Int. Ref.0 Select 5 : 30/32 */
#define CEREF0_30               (0x001E)       /* Comp. E Int. Ref.0 Select 6 : 31/32 */
#define CEREF0_31               (0x001F)       /* Comp. E Int. Ref.0 Select 7 : 32/32 */
#define CEREF1_0                (0x0000)       /* Comp. E Int. Ref.1 Select 0 : 1/32 */

#define CEREF1_1                (0x0100)       /* Comp. E Int. Ref.1 Select 1 : 2/32 */
#define CEREF1_2                (0x0200)       /* Comp. E Int. Ref.1 Select 2 : 3/32 */
#define CEREF1_3                (0x0300)       /* Comp. E Int. Ref.1 Select 3 : 4/32 */
#define CEREF1_4                (0x0400)       /* Comp. E Int. Ref.1 Select 4 : 5/32 */
#define CEREF1_5                (0x0500)       /* Comp. E Int. Ref.1 Select 5 : 6/32 */
#define CEREF1_6                (0x0600)       /* Comp. E Int. Ref.1 Select 6 : 7/32 */
#define CEREF1_7                (0x0700)       /* Comp. E Int. Ref.1 Select 7 : 8/32 */
#define CEREF1_8                (0x0800)       /* Comp. E Int. Ref.1 Select 0 : 9/32 */
#define CEREF1_9                (0x0900)       /* Comp. E Int. Ref.1 Select 1 : 10/32 */
#define CEREF1_10               (0x0A00)       /* Comp. E Int. Ref.1 Select 2 : 11/32 */
#define CEREF1_11               (0x0B00)       /* Comp. E Int. Ref.1 Select 3 : 12/32 */
#define CEREF1_12               (0x0C00)       /* Comp. E Int. Ref.1 Select 4 : 13/32 */
#define CEREF1_13               (0x0D00)       /* Comp. E Int. Ref.1 Select 5 : 14/32 */
#define CEREF1_14               (0x0E00)       /* Comp. E Int. Ref.1 Select 6 : 15/32 */
#define CEREF1_15               (0x0F00)       /* Comp. E Int. Ref.1 Select 7 : 16/32 */
#define CEREF1_16               (0x1000)       /* Comp. E Int. Ref.1 Select 0 : 17/32 */
#define CEREF1_17               (0x1100)       /* Comp. E Int. Ref.1 Select 1 : 18/32 */
#define CEREF1_18               (0x1200)       /* Comp. E Int. Ref.1 Select 2 : 19/32 */
#define CEREF1_19               (0x1300)       /* Comp. E Int. Ref.1 Select 3 : 20/32 */
#define CEREF1_20               (0x1400)       /* Comp. E Int. Ref.1 Select 4 : 21/32 */
#define CEREF1_21               (0x1500)       /* Comp. E Int. Ref.1 Select 5 : 22/32 */
#define CEREF1_22               (0x1600)       /* Comp. E Int. Ref.1 Select 6 : 23/32 */
#define CEREF1_23               (0x1700)       /* Comp. E Int. Ref.1 Select 7 : 24/32 */
#define CEREF1_24               (0x1800)       /* Comp. E Int. Ref.1 Select 0 : 25/32 */
#define CEREF1_25               (0x1900)       /* Comp. E Int. Ref.1 Select 1 : 26/32 */
#define CEREF1_26               (0x1A00)       /* Comp. E Int. Ref.1 Select 2 : 27/32 */
#define CEREF1_27               (0x1B00)       /* Comp. E Int. Ref.1 Select 3 : 28/32 */
#define CEREF1_28               (0x1C00)       /* Comp. E Int. Ref.1 Select 4 : 29/32 */
#define CEREF1_29               (0x1D00)       /* Comp. E Int. Ref.1 Select 5 : 30/32 */
#define CEREF1_30               (0x1E00)       /* Comp. E Int. Ref.1 Select 6 : 31/32 */
#define CEREF1_31               (0x1F00)       /* Comp. E Int. Ref.1 Select 7 : 32/32 */

#endif

/************************************************************
* CRC32
************************************************************/

#ifdef __MSP430_HAS_CRC32__

#define CRC32DIB0               CRC32DIW0_L
#define CRC32DIRBB0             CRC32DIRBW0_H
#define CRC32RESB0              CRC32INIRESW0_L
#define CRC32RESB1              CRC32INIRESW0_H
#define CRC32RESB2              CRC32INIRESW1_L
#define CRC32RESB3              CRC32INIRESW1_H
#define CRC32RESRB3             CRC32RESRW1_L
#define CRC32RESRB2             CRC32RESRW1_H
#define CRC32RESRB1             CRC32RESRW0_L
#define CRC32RESRB0             CRC32RESRW0_H
#define CRC16DIB0               CRC16DIW0_L
#define CRC16DIRBB0             CRC16DIRBW0_L
#define CRC16INIRESB1           CRC16INIRESW0_H
#define CRC16INIRESB0           CRC16INIRESW0_L
#define CRC16RESRB1             CRC16RESRW0_L
#define CRC16RESRB0             CRC16RESRW0_H

#endif

/************************************************************
* DIO
************************************************************/

#ifdef __MSP430_HAS_DIO__

#ifdef __MSP430_HAS_PORT1_R__
#define P1IV_NONE       P1IV__NONE
#define P1IV_P1IFG0     P1IV__P1IFG0
#define P1IV_P1IFG1     P1IV__P1IFG1
#define P1IV_P1IFG2     P1IV__P1IFG2
#define P1IV_P1IFG3     P1IV__P1IFG3
#define P1IV_P1IFG4     P1IV__P1IFG4
#define P1IV_P1IFG5     P1IV__P1IFG5
#define P1IV_P1IFG6     P1IV__P1IFG6
#define P1IV_P1IFG7     P1IV__P1IFG7
#endif
#ifdef __MSP430_HAS_PORT2_R__
#define P2IV_NONE       P2IV__NONE
#define P2IV_P2IFG0     P2IV__P2IFG0
#define P2IV_P2IFG1     P2IV__P2IFG1
#define P2IV_P2IFG2     P2IV__P2IFG2
#define P2IV_P2IFG3     P2IV__P2IFG3
#define P2IV_P2IFG4     P2IV__P2IFG4
#define P2IV_P2IFG5     P2IV__P2IFG5
#define P2IV_P2IFG6     P2IV__P2IFG6
#define P2IV_P2IFG7     P2IV__P2IFG7
#endif
#ifdef __MSP430_HAS_PORT3_R__
#define P3IV_NONE       P3IV__NONE
#define P3IV_P3IFG0     P3IV__P3IFG0
#define P3IV_P3IFG1     P3IV__P3IFG1
#define P3IV_P3IFG2     P3IV__P3IFG2
#define P3IV_P3IFG3     P3IV__P3IFG3
#define P3IV_P3IFG4     P3IV__P3IFG4
#define P3IV_P3IFG5     P3IV__P3IFG5
#define P3IV_P3IFG6     P3IV__P3IFG6
#define P3IV_P3IFG7     P3IV__P3IFG7
#endif
#ifdef __MSP430_HAS_PORT4_R__
#define P4IV_NONE       P4IV__NONE
#define P4IV_P4IFG0     P4IV__P4IFG0
#define P4IV_P4IFG1     P4IV__P4IFG1
#define P4IV_P4IFG2     P4IV__P4IFG2
#define P4IV_P4IFG3     P4IV__P4IFG3
#define P4IV_P4IFG4     P4IV__P4IFG4
#define P4IV_P4IFG5     P4IV__P4IFG5
#define P4IV_P4IFG6     P4IV__P4IFG6
#define P4IV_P4IFG7     P4IV__P4IFG7
#endif
#ifdef __MSP430_HAS_PORT5_R__
#define P5IV_NONE       P5IV__NONE
#define P5IV_P5IFG0     P5IV__P5IFG0
#define P5IV_P5IFG1     P5IV__P5IFG1
#define P5IV_P5IFG2     P5IV__P5IFG2
#define P5IV_P5IFG3     P5IV__P5IFG3
#define P5IV_P5IFG4     P5IV__P5IFG4
#define P5IV_P5IFG5     P5IV__P5IFG5
#define P5IV_P5IFG6     P5IV__P5IFG6
#define P5IV_P5IFG7     P5IV__P5IFG7
#endif
#ifdef __MSP430_HAS_PORT6_R__
#define P6IV_NONE       P6IV__NONE
#define P6IV_P6IFG0     P6IV__P6IFG0
#define P6IV_P6IFG1     P6IV__P6IFG1
#define P6IV_P6IFG2     P6IV__P6IFG2
#define P6IV_P6IFG3     P6IV__P6IFG3
#define P6IV_P6IFG4     P6IV__P6IFG4
#define P6IV_P6IFG5     P6IV__P6IFG5
#define P6IV_P6IFG6     P6IV__P6IFG6
#define P6IV_P6IFG7     P6IV__P6IFG7
#endif
#ifdef __MSP430_HAS_PORT7_R__
#define P7IV_NONE       P7IV__NONE
#define P7IV_P7IFG0     P7IV__P7IFG0
#define P7IV_P7IFG1     P7IV__P7IFG1
#define P7IV_P7IFG2     P7IV__P7IFG2
#define P7IV_P7IFG3     P7IV__P7IFG3
#define P7IV_P7IFG4     P7IV__P7IFG4
#define P7IV_P7IFG5     P7IV__P7IFG5
#define P7IV_P7IFG6     P7IV__P7IFG6
#define P7IV_P7IFG7     P7IV__P7IFG7
#endif
#ifdef __MSP430_HAS_PORT8_R__
#define P8IV_NONE       P8IV__NONE
#define P8IV_P8IFG0     P8IV__P8IFG0
#define P8IV_P8IFG1     P8IV__P8IFG1
#define P8IV_P8IFG2     P8IV__P8IFG2
#define P8IV_P8IFG3     P8IV__P8IFG3
#define P8IV_P8IFG4     P8IV__P8IFG4
#define P8IV_P8IFG5     P8IV__P8IFG5
#define P8IV_P8IFG6     P8IV__P8IFG6
#define P8IV_P8IFG7     P8IV__P8IFG7
#endif
#endif

/************************************************************
* DMA
************************************************************/

#ifdef __MSP430_HAS_DMA__

#define __MSP430_HAS_DMAX_6__
#define __MSP430_BASEADDRESS_DMAX_6__ DMA_BASE
    
#define DMAIV_NONE              DMAIV__NONE
#define DMAIV_DMA0IFG           DMAIV__DMA0IFG
#define DMAIV_DMA1IFG           DMAIV__DMA1IFG
#define DMAIV_DMA2IFG           DMAIV__DMA2IFG
#define DMAIV_DMA3IFG           DMAIV__DMA3IFG
#define DMAIV_DMA4IFG           DMAIV__DMA4IFG
#define DMAIV_DMA5IFG           DMAIV__DMA5IFG

#define DMASBDB                 DMASRCBYTE | DMADSTBYTE
#define DMASBDW                 DMASRCBYTE
#define DMASWDB                 DMADSTBYTE
#define DMASWDW                 (0x0000)

#ifdef DMA0CTL
#define DMA0SAL                 DMA0SA_L
#define DMA0SAH                 DMA0SA_H
#define DMA0DAL                 DMA0DA_L
#define DMA0DAH                 DMA0DA_H
#endif
#ifdef DMA1CTL
#define DMA1SAL                 DMA1SA_L
#define DMA1SAH                 DMA1SA_H
#define DMA1DAL                 DMA1DA_L
#define DMA1DAH                 DMA1DA_H
#endif
#ifdef DMA2CTL
#define DMA2SAL                 DMA2SA_L
#define DMA2SAH                 DMA2SA_H
#define DMA2DAL                 DMA2DA_L
#define DMA2DAH                 DMA2DA_H
#endif

#endif

/************************************************************
* ECOMP0
************************************************************/

#ifdef __MSP430_HAS_ECOMP0__
#define ECOMP_BASE              ECOMP0_BASE
#endif

/************************************************************
* FRCTL
************************************************************/

#ifdef __MSP430_HAS_FRCTL__

#define __MSP430_HAS_FRAM__
#define __MSP430_HAS_GC__
#define __MSP430_BASEADDRESS_FRAM__ FRCTL_BASE
#define FRAM_BASE               FRCTL_BASE
    
#define FWPW                    FRCTLPW
#define FRPW                    (0x9600)       /* FRAM password returned by read */
#define FXPW                    (0x3300)       /* for use with XOR instruction */

#endif

/************************************************************
* MPY32
************************************************************/

#ifdef __MSP430_HAS_MPY32__

#define OP1_32                  MPYOP1_32
#define OP1_32_L                MPYOP1_32_L
#define OP2_32                  MPYOP2_32
#define OP2_32_L                MPYOP1_32_L

#define MPY_B                   MPY_L
#define MPYS_B                  MPYS_L
#define MAC_B                   MAC_L
#define MACS_B                  MACS_L
#define OP2_B                   OP2_L
#define MPY32L_B                MPY32L_L
#define MPY32H_B                MPY32H_L
#define MPYS32L_B               MPYS32L_L
#define MPYS32H_B               MPYS32H_L
#define MAC32L_B                MAC32L_L
#define MAC32H_B                MAC32H_L
#define MACS32L_B               MACS32L_L
#define MACS32H_B               MACS32H_L
#define OP2L_B                  OP2L_L
#define OP2H_B                  OP2H_L

#endif
/************************************************************
* PMM
************************************************************/

#ifdef __MSP430_HAS_PMM__
#define __MSP430_HAS_PMM_FRAM__
#endif

/************************************************************
* RAMCTL
************************************************************/

#ifdef __MSP430_HAS_RAMCTL__
#define RAM_BASE                RAMCTL_BASE
#define __MSP430_BASEADDRESS_RC_FRAM__ RAMCTL_BASE
#define __MSP430_HAS_RC_FRAM__
#endif

/************************************************************
* RTC
************************************************************/

#ifdef __MSP430_HAS_RTC__

#define RTCIV_NONE              RTCIV__NONE
#define RTCIV_RTCIF             RTCIV__RTCIFG

#define RTCIF                   RTCIFG
#define RTCIF_L                 RTCIFG_L

#endif

/************************************************************
* RTC_C
************************************************************/

#ifdef __MSP430_HAS_RTC_C__

#define RTCPWD                  RTCCTL0_H
#define RTCCTL1                 RTCCTL13_L
#define RTCCTL3                 RTCCTL13_H

#define RTC_VECTOR              RTC_C_VECTOR

#define RTC_NONE                RTCIV__NONE
#define RTC_RTCOFIFG            RTCIV__RTCOFIFG
#define RTC_RTCRDYIFG           RTCIV__RTCRDYIFG
#define RTC_RTCTEVIFG           RTCIV__RTCTEVIFG
#define RTC_RTCAIFG             RTCIV__RTCAIFG
#define RTC_RT0PSIFG            RTCIV__RT0PSIFG
#define RTC_RT1PSIFG            RTCIV__RT1PSIFG

#define RTCIV_NONE              RTCIV__NONE
#define RTCIV_RTCOFIFG          RTCIV__RTCOFIFG
#define RTCIV_RTCRDYIFG         RTCIV__RTCRDYIFG
#define RTCIV_RTCTEVIFG         RTCIV__RTCTEVIFG
#define RTCIV_RTCIF             RTCIV__RTCIFG
#define RTCIV_RTCAIFG           RTCIV__RTCAIFG
#define RTCIV_RT0PSIFG          RTCIV__RT0PSIFG
#define RTCIV_RT1PSIFG          RTCIV__RT1PSIFG

#define RTCCLKSEL               RTCCKSEL
#define RTCCLKSEL_H             RTCCKSEL_H

#define RTCAE                   (0x0080)

#define RTCSEC                  RTCTIM0_L
#define RTCMIN                  RTCTIM0_H
#define RTCHOUR                 RTCTIM1_L
#define RTCDOW                  RTCTIM1_H
#define RTCDAY                  RTCDATE_L
#define RTCMON                  RTCDATE_H
#define RTCYEARL                RTCYEAR_L
#define RT0PS                   RTCPS_L
#define RT1PS                   RTCPS_H
#define RTCAMIN                 RTCAMINHR_L
#define RTCAHOUR                RTCAMINHR_H
#define RTCADOW                 RTCADOWDAY_L
#define RTCADAY                 RTCADOWDAY_H

#endif

/************************************************************
* SYS
************************************************************/

#ifdef __MSP430_HAS_SYS__

#define SYSRSTIV_NONE           SYSRSTIV__NONE
#define SYSRSTIV_BOR            SYSRSTIV__BOR
#define SYSRSTIV_CSPW           SYSRSTIV__CSPW
#define SYSRSTIV_DOBOR          SYSRSTIV__PMMSWBOR
#define SYSRSTIV_DOPOR          SYSRSTIV__PMMSWPOR
#define SYSRSTIV_FLLUL          SYSRSTIV__FLLUL
#define SYSRSTIV_FRCTLPW        SYSRSTIV__FRCTLPW
#define SYSRSTIV_LPM5WU         SYSRSTIV__LPM5WU
#define SYSRSTIV_MPUPW          SYSRSTIV__MPUPW
#define SYSRSTIV_MPUSEG1IFG     SYSRSTIV__MPUSEG1IFG
#define SYSRSTIV_MPUSEG2IFG     SYSRSTIV__MPUSEG2IFG
#define SYSRSTIV_MPUSEG3IFG     SYSRSTIV__MPUSEG3IFG
#define SYSRSTIV_MPUSEGIIFG     SYSRSTIV__MPUSEGIIFG
#define SYSRSTIV_MPUSEGPIFG     SYSRSTIV__MPUSEGPIFG
#define SYSRSTIV_PERF           SYSRSTIV__PERF
#define SYSRSTIV_PMMPW          SYSRSTIV__PMMPW
#define SYSRSTIV_RSTNMI         SYSRSTIV__RSTNMI
#define SYSRSTIV_SECYV          SYSRSTIV__SECYV
#define SYSRSTIV_SVSHIFG        SYSRSTIV__SVSHIFG
#define SYSRSTIV_UBDIFG         SYSRSTIV__UBDIFG
#define SYSRSTIV_WDTKEY         SYSRSTIV__WDTPW
#define SYSRSTIV_WDTPW          SYSRSTIV__WDTPW
#define SYSRSTIV_WDTTO          SYSRSTIV__WDTIFG

#define SYSSNIV_NONE            SYSSNIV__NONE
#define SYSSNIV_ACCTEIFG        SYSSNIV__ACCTEIFG
#define SYSSNIV_CBDIFG          SYSSNIV__CBDIFG
#define SYSSNIV_JMBINIFG        SYSSNIV__JMBINIFG
#define SYSSNIV_JMBOUTIFG       SYSSNIV__JMBOUTIFG
#define SYSSNIV_LEASCCMD        SYSSNIV__LEASCCMD
#define SYSSNIV_LEASCTO         SYSSNIV__LEASCTO
#define SYSSNIV_MPUSEG1IFG      SYSSNIV__MPUSEG1IFG
#define SYSSNIV_MPUSEG2IFG      SYSSNIV__MPUSEG2IFG
#define SYSSNIV_MPUSEG3IFG      SYSSNIV__MPUSEG3IFG
#define SYSSNIV_MPUSEGIIFG      SYSSNIV__MPUSEGIIFG
#define SYSSNIV_MPUSEGPIFG      SYSSNIV__MPUSEGPIFG
#define SYSSNIV_SVSLIFG         SYSSNIV__SVSLIFG
#define SYSSNIV_UBDIFG          SYSSNIV__UBDIFG
#define SYSSNIV_VMAIFG          SYSSNIV__VMAIFG
#define SYSSNIV_WPROT           SYSSNIV__WPROT

#define SYSUNIV_NONE            SYSUNIV__NONE
#define SYSUNIV_NMIIFG          SYSUNIV__NMIIFG
#define SYSUNIV_OFIFG           SYSUNIV__OFIFG

#endif

/************************************************************
* Timer A
************************************************************/

#ifdef  __MSP430_HAS_TAx__            /* Definition to show that Module is available */
#define __MSP430_HAS_TxA7__

#define OFS_TAxCTL             OFS_TA0CTL
#define OFS_TAxCCTL0           OFS_TA0CCTL0
#define OFS_TAxCCTL1           OFS_TA0CCTL1
#define OFS_TAxCCTL2           OFS_TA0CCTL2
#define OFS_TAxCCTL3           OFS_TA0CCTL3
#define OFS_TAxCCTL4           OFS_TA0CCTL4
#define OFS_TAxCCTL5           OFS_TA0CCTL5
#define OFS_TAxCCTL6           OFS_TA0CCTL6
#define OFS_TAxR               OFS_TA0R
#define OFS_TAxCCR0            OFS_TA0CCR0
#define OFS_TAxCCR1            OFS_TA0CCR1
#define OFS_TAxCCR2            OFS_TA0CCR2
#define OFS_TAxCCR3            OFS_TA0CCR3
#define OFS_TAxCCR4            OFS_TA0CCR4
#define OFS_TAxCCR5            OFS_TA0CCR5
#define OFS_TAxCCR6            OFS_TA0CCR6
#define OFS_TAxIV              OFS_TA0IV
#define OFS_TAxEX0             OFS_TA0EX0

/* TAxIV Definitions */
#define TAxIV_NONE             (0x0000)       /* No Interrupt pending */
#define TAxIV_TACCR1           (0x0002)       /* TAxCCR1_CCIFG */
#define TAxIV_TACCR2           (0x0004)       /* TAxCCR2_CCIFG */
#define TAxIV_TACCR3           (0x0006)       /* TAxCCR3_CCIFG */
#define TAxIV_TACCR4           (0x0008)       /* TAxCCR4_CCIFG */
#define TAxIV_TACCR5           (0x000A)       /* TAxCCR5_CCIFG */
#define TAxIV_TACCR6           (0x000C)       /* TAxCCR6_CCIFG */
#define TAxIV_TAIFG            (0x000E)       /* TAxIFG */

/* Legacy Defines */
#define TAxIV_TAxCCR1          (0x0002)       /* TAxCCR1_CCIFG */
#define TAxIV_TAxCCR2          (0x0004)       /* TAxCCR2_CCIFG */
#define TAxIV_TAxCCR3          (0x0006)       /* TAxCCR3_CCIFG */
#define TAxIV_TAxCCR4          (0x0008)       /* TAxCCR4_CCIFG */
#define TAxIV_TAxCCR5          (0x000A)       /* TAxCCR5_CCIFG */
#define TAxIV_TAxCCR6          (0x000C)       /* TAxCCR6_CCIFG */
#define TAxIV_TAxIFG           (0x000E)       /* TAxIFG */

#ifndef MC__CONTINOUS
#define MC__CONTINOUS      MC__CONTINUOUS
#endif

#endif

#ifdef __MSP430_HAS_TA0__
#if (__MSP430_HAS_TA0__ == 3)
	#define __MSP430_BASEADDRESS_T0A3__ TA0_BASE
	#define __MSP430_HAS_T0A3__
#endif
#define TIMER_A0_BASE       TA0_BASE

#define TA0IV_TA0CCR1       TAIV__TACCR1
#define TA0IV_TA0CCR2       TAIV__TACCR2
#define TA0IV_TA0IFG        TAIV__TAIFG
#define TA0IV_NONE          TAIV__NONE
#define TA0IV_TACCR1        TAIV__TACCR1
#define TA0IV_TACCR2        TAIV__TACCR2
#define TA0IV_3             TAIV__TACCR3
#define TA0IV_4             TAIV__TACCR4
#define TA0IV_5             TAIV__TACCR5
#define TA0IV_6             TAIV__TACCR6
#define TA0IV_TAIFG         TAIV__TAIFG
#endif

#ifdef __MSP430_HAS_TA1__
#if (__MSP430_HAS_TA1__ == 3)
	#define __MSP430_BASEADDRESS_T1A3__ TA1_BASE
	#define __MSP430_HAS_T1A3__
#endif
#define TIMER_A1_BASE       TA1_BASE

#define TA1IV_TA1CCR1       TAIV__TACCR1
#define TA1IV_TA1CCR2       TAIV__TACCR2
#define TA1IV_TA1IFG        TAIV__TAIFG
#define TA1IV_NONE          TAIV__NONE
#define TA1IV_TACCR1        TAIV__TACCR1
#define TA1IV_TACCR2        TAIV__TACCR2
#define TA1IV_3             TAIV__TACCR3
#define TA1IV_4             TAIV__TACCR4
#define TA1IV_5             TAIV__TACCR5
#define TA1IV_6             TAIV__TACCR6
#define TA1IV_TAIFG         TAIV__TAIFG
#endif

#ifdef __MSP430_HAS_TA2__
#if (__MSP430_HAS_TA2__ == 2)
	#define __MSP430_BASEADDRESS_T2A2__ TA2_BASE
	#define __MSP430_HAS_T2A2__
#endif
#define TIMER_A2_BASE       TA2_BASE

#define TA2IV_TA2CCR1       TAIV__TACCR1
#define TA2IV_TA2IFG        TAIV__TAIFG
#define TA2IV_NONE          TAIV__NONE
#define TA2IV_TACCR1        TAIV__TACCR1
#define TA2IV_TACCR2        TAIV__TACCR2
#define TA2IV_3             TAIV__TACCR3
#define TA2IV_4             TAIV__TACCR4
#define TA2IV_5             TAIV__TACCR5
#define TA2IV_6             TAIV__TACCR6
#define TA2IV_TAIFG         TAIV__TAIFG
#endif

#ifdef __MSP430_HAS_TA3__
#if (__MSP430_HAS_TA3__ == 2)
	#define __MSP430_BASEADDRESS_T3A2__ TA3_BASE
	#define __MSP430_HAS_T3A2__
#endif
#define TIMER_A3_BASE       TA3_BASE

#define TA3IV_TA3CCR1       TAIV__TACCR1
#define TA3IV_TA3IFG        TAIV__TAIFG
#define TA3IV_NONE          TAIV__NONE
#define TA3IV_TACCR1        TAIV__TACCR1
#define TA3IV_TACCR2        TAIV__TACCR2
#define TA3IV_3             TAIV__TACCR3
#define TA3IV_4             TAIV__TACCR4
#define TA3IV_5             TAIV__TACCR5
#define TA3IV_6             TAIV__TACCR6
#define TA3IV_TAIFG         TAIV__TAIFG
#endif

#ifdef __MSP430_HAS_TA4__
#if (__MSP430_HAS_TA4__ == 3)
	#define __MSP430_BASEADDRESS_T4A3__ TA4_BASE
	#define __MSP430_HAS_T4A3__
#endif
#define TIMER_A4_BASE       TA4_BASE

#define TA4IV_TA4CCR1       TAIV__TACCR1
#define TA4IV_TA4IFG        TAIV__TAIFG
#define TA4IV_NONE          TAIV__NONE
#define TA4IV_TACCR1        TAIV__TACCR1
#define TA4IV_TACCR2        TAIV__TACCR2
#define TA4IV_3             TAIV__TACCR3
#define TA4IV_4             TAIV__TACCR4
#define TA4IV_5             TAIV__TACCR5
#define TA4IV_6             TAIV__TACCR6
#define TA4IV_TAIFG         TAIV__TAIFG
#endif

/************************************************************
* Timer B
************************************************************/

#ifdef __MSP430_HAS_TBx__
#define __MSP430_HAS_TxB7__

#define OFS_TBxCTL             OFS_TB0CTL
#define OFS_TBxCCTL0           OFS_TB0CCTL0
#define OFS_TBxCCTL1           OFS_TB0CCTL1
#define OFS_TBxCCTL2           OFS_TB0CCTL2
#define OFS_TBxCCTL3           OFS_TB0CCTL3
#define OFS_TBxCCTL4           OFS_TB0CCTL4
#define OFS_TBxCCTL5           OFS_TB0CCTL5
#define OFS_TBxCCTL6           OFS_TB0CCTL6
#define OFS_TBxR               OFS_TB0R
#define OFS_TBxCCR0            OFS_TB0CCR0
#define OFS_TBxCCR1            OFS_TB0CCR1
#define OFS_TBxCCR2            OFS_TB0CCR2
#define OFS_TBxCCR3            OFS_TB0CCR3
#define OFS_TBxCCR4            OFS_TB0CCR4
#define OFS_TBxCCR5            OFS_TB0CCR5
#define OFS_TBxCCR6            OFS_TB0CCR6
#define OFS_TBxIV              OFS_TB0IV
#define OFS_TBxEX0             OFS_TB0EX0

/* TBxIV Definitions */
#define TBxIV_NONE             (0x0000)       /* No Interrupt pending */
#define TBxIV_TBCCR1           (0x0002)       /* TBxCCR1_CCIFG */
#define TBxIV_TBCCR2           (0x0004)       /* TBxCCR2_CCIFG */
#define TBxIV_TBCCR3           (0x0006)       /* TBxCCR3_CCIFG */
#define TBxIV_TBCCR4           (0x0008)       /* TBxCCR4_CCIFG */
#define TBxIV_TBCCR5           (0x000A)       /* TBxCCR5_CCIFG */
#define TBxIV_TBCCR6           (0x000C)       /* TBxCCR6_CCIFG */
#define TBxIV_TBIFG            (0x000E)       /* TBxIFG */

/* Legacy Defines */
#define TBxIV_TBxCCR1          (0x0002)       /* TBxCCR1_CCIFG */
#define TBxIV_TBxCCR2          (0x0004)       /* TBxCCR2_CCIFG */
#define TBxIV_TBxCCR3          (0x0006)       /* TBxCCR3_CCIFG */
#define TBxIV_TBxCCR4          (0x0008)       /* TBxCCR4_CCIFG */
#define TBxIV_TBxCCR5          (0x000A)       /* TBxCCR5_CCIFG */
#define TBxIV_TBxCCR6          (0x000C)       /* TBxCCR6_CCIFG */
#define TBxIV_TBxIFG           (0x000E)       /* TBxIFG */

#ifndef MC__CONTINOUS
#define MC__CONTINOUS          MC__CONTINUOUS
#endif

#define SHR0                    TBCLGRP0
#define SHR1                    TBCLGRP1
#define SHR_0                   TBCLGRP_0
#define SHR_1                   TBCLGRP_1
#define SHR_2                   TBCLGRP_2
#define SHR_3                   TBCLGRP_3

#define SLSHR0                  CLLD0
#define SLSHR1                  CLLD1
#define SLSHR_0                 CLLD_0
#define SLSHR_1                 CLLD_1
#define SLSHR_2                 CLLD_2
#define SLSHR_3                 CLLD_3

#endif

#ifdef __MSP430_HAS_TB0__
#if (__MSP430_HAS_TB0__ == 3)
    #define __MSP430_BASEADDRESS_T0B3__ TB0_BASE
    #define __MSP430_HAS_T0B3__
#endif
#if (__MSP430_HAS_TB0__ == 7)
    #define __MSP430_BASEADDRESS_T0B7__ TB0_BASE
    #define __MSP430_HAS_T0B7__
#endif
#define TIMER_B0_BASE           TB0_BASE
#define TIMERB0_VECTOR          TIMER0_B0_VECTOR

#define TBCTL                   TB0CTL    /* Control Register */
#define TBCCTL0                 TB0CCTL0  /* Capture/Compare Control 0 */
#define TBCCTL1                 TB0CCTL1  /* Capture/Compare Control 1 */
#define TBCCTL2                 TB0CCTL2  /* Capture/Compare Control 2 */
#define TBCCTL3                 TB0CCTL3  /* Capture/Compare Control 3 */
#define TBCCTL4                 TB0CCTL4  /* Capture/Compare Control 4 */
#define TBCCTL5                 TB0CCTL5  /* Capture/Compare Control 5 */
#define TBCCTL6                 TB0CCTL6  /* Capture/Compare Control 6 */
#define TBR                     TB0R
#define TBCCR0                  TB0CCR0   /* Capture/Compare 0 */
#define TBCCR1                  TB0CCR1   /* Capture/Compare 1 */
#define TBCCR2                  TB0CCR2   /* Capture/Compare 2 */
#define TBCCR3                  TB0CCR3   /* Capture/Compare 3 */
#define TBCCR4                  TB0CCR4   /* Capture/Compare 4 */
#define TBCCR5                  TB0CCR5   /* Capture/Compare 5 */
#define TBCCR6                  TB0CCR6   /* Capture/Compare 6 */
#define TBEX0                   TB0EX0    /* Expansion Register 0 */

#define TBSSEL__TACLK           TBSSEL__TBCLK
    
#define TB0IV_NONE              TBIV__NONE
#define TB0IV_TB0CCR1           TBIV__TBCCR1
#define TB0IV_TB0CCR2           TBIV__TBCCR2
#define TB0IV_TB0CCR3           TBIV__TBCCR3
#define TB0IV_TB0CCR4           TBIV__TBCCR4
#define TB0IV_TB0CCR5           TBIV__TBCCR5
#define TB0IV_TB0CCR6           TBIV__TBCCR6
#define TB0IV_TB0IFG            TBIV__TBIFG

#define TB0IV_TBCCR1            TBIV__TBCCR1
#define TB0IV_TBCCR2            TBIV__TBCCR2
#define TB0IV_TBCCR3            TBIV__TBCCR3
#define TB0IV_TBCCR4            TBIV__TBCCR4
#define TB0IV_TBCCR5            TBIV__TBCCR5
#define TB0IV_TBCCR6            TBIV__TBCCR6
#define TB0IV_TBIFG             TBIV__TBIFG

#endif

#ifdef __MSP430_HAS_TB1__
#if (__MSP430_HAS_TB1__ == 3)
    #define __MSP430_HAS_T1B3__
    #define __MSP430_BASEADDRESS_T1B3__ TB1_BASE
#endif
#define TIMER_B1_BASE           TB1_BASE
#define TIMERB1_VECTOR          TIMER0_B1_VECTOR

#define TB1IV_NONE              TBIV__NONE
#define TB1IV_TB1CCR1           TBIV__TBCCR1
#define TB1IV_TB1CCR2           TBIV__TBCCR2
#define TB1IV_TB1IFG            TBIV__TBIFG
#define TB1IV_TBCCR1            TBIV__TBCCR1
#define TB1IV_TBCCR2            TBIV__TBCCR1
#define TB1IV_TBIFG             TBIV__TBIFG

#endif

/************************************************************
* USCI
************************************************************/

#if defined(__MSP430_HAS_EUSCI_Ax__) || defined(__MSP430_HAS_EUSCI_Bx__)

#define UCADDMASK0              ADDMASK0
#define UCADDMASK0_L            ADDMASK0_L
#define UCADDMASK1              ADDMASK1
#define UCADDMASK1_L            ADDMASK1_L
#define UCADDMASK2              ADDMASK2
#define UCADDMASK2_L            ADDMASK2_L
#define UCADDMASK3              ADDMASK3
#define UCADDMASK3_L            ADDMASK3_L
#define UCADDMASK4              ADDMASK4
#define UCADDMASK4_L            ADDMASK4_L
#define UCADDMASK5              ADDMASK5
#define UCADDMASK5_L            ADDMASK5_L
#define UCADDMASK6              ADDMASK6
#define UCADDMASK6_L            ADDMASK6_L
#define UCADDMASK7              ADDMASK7
#define UCADDMASK7_L            ADDMASK7_L
#define UCADDMASK8              ADDMASK8
#define UCADDMASK8_H            ADDMASK8_H
#define UCADDMASK9              ADDMASK9
#define UCADDMASK9_H            ADDMASK9_H
 
#define UCADDR                  UCADDR_UCIDLE
#define UCIDLE                  UCADDR_UCIDLE
 
#define UCADDRX0                ADDRX0
#define UCADDRX0_L              ADDRX0_L
#define UCADDRX1                ADDRX1
#define UCADDRX1_L              ADDRX1_L
#define UCADDRX2                ADDRX2
#define UCADDRX2_L              ADDRX2_L
#define UCADDRX3                ADDRX3
#define UCADDRX3_L              ADDRX3_L
#define UCADDRX4                ADDRX4
#define UCADDRX4_L              ADDRX4_L
#define UCADDRX5                ADDRX5
#define UCADDRX5_L              ADDRX5_L
#define UCADDRX6                ADDRX6
#define UCADDRX6_L              ADDRX6_L
#define UCADDRX7                ADDRX7
#define UCADDRX7_L              ADDRX7_L
#define UCADDRX8                ADDRX8
#define UCADDRX8_H              ADDRX8_H
#define UCADDRX9                ADDRX9
#define UCADDRX9_H              ADDRX9_H

#define UCBRF_0                 (0x00)         /* USCI First Stage Modulation: 0 */
#define UCBRF_1                 (0x10)         /* USCI First Stage Modulation: 1 */
#define UCBRF_2                 (0x20)         /* USCI First Stage Modulation: 2 */
#define UCBRF_3                 (0x30)         /* USCI First Stage Modulation: 3 */
#define UCBRF_4                 (0x40)         /* USCI First Stage Modulation: 4 */
#define UCBRF_5                 (0x50)         /* USCI First Stage Modulation: 5 */
#define UCBRF_6                 (0x60)         /* USCI First Stage Modulation: 6 */
#define UCBRF_7                 (0x70)         /* USCI First Stage Modulation: 7 */
#define UCBRF_8                 (0x80)         /* USCI First Stage Modulation: 8 */
#define UCBRF_9                 (0x90)         /* USCI First Stage Modulation: 9 */
#define UCBRF_10                (0xA0)         /* USCI First Stage Modulation: A */
#define UCBRF_11                (0xB0)         /* USCI First Stage Modulation: B */
#define UCBRF_12                (0xC0)         /* USCI First Stage Modulation: C */
#define UCBRF_13                (0xD0)         /* USCI First Stage Modulation: D */
#define UCBRF_14                (0xE0)         /* USCI First Stage Modulation: E */
#define UCBRF_15                (0xF0)         /* USCI First Stage Modulation: F */

#define UCOA0                   I2COA00
#define UCOA0_L                 I2COA00_L
#define UCOA1                   I2COA01
#define UCOA1_L                 I2COA01_L
#define UCOA2                   I2COA02
#define UCOA2_L                 I2COA02_L
#define UCOA3                   I2COA03
#define UCOA3_L                 I2COA03_L
#define UCOA4                   I2COA04
#define UCOA4_L                 I2COA04_L
#define UCOA5                   I2COA05
#define UCOA5_L                 I2COA05_L
#define UCOA6                   I2COA06
#define UCOA6_L                 I2COA06_L
#define UCOA7                   I2COA07
#define UCOA7_L                 I2COA07_L
#define UCOA8                   I2COA08
#define UCOA8_H                 I2COA08_H
#define UCOA9                   I2COA09
#define UCOA9_H                 I2COA09_H

#define UCSA0                   I2CSA0
#define UCSA0_L                 I2CSA0_L
#define UCSA1                   I2CSA1
#define UCSA1_L                 I2CSA1_L
#define UCSA2                   I2CSA2
#define UCSA2_L                 I2CSA2_L
#define UCSA3                   I2CSA3
#define UCSA3_L                 I2CSA3_L
#define UCSA4                   I2CSA4
#define UCSA4_L                 I2CSA4_L
#define UCSA5                   I2CSA5
#define UCSA5_L                 I2CSA5_L
#define UCSA6                   I2CSA6
#define UCSA6_L                 I2CSA6_L
#define UCSA7                   I2CSA7
#define UCSA7_L                 I2CSA7_L
#define UCSA8                   I2CSA8
#define UCSA8_H                 I2CSA8_H
#define UCSA9                   I2CSA9
#define UCSA9_H                 I2CSA9_H

#define USCI_NONE               UCIV__NONE
#define USCI_I2C_UCALIFG        UCIV__UCALIFG
#define USCI_I2C_UCBCNTIFG      UCIV__UCBCNTIFG
#define USCI_I2C_UCBIT9IFG      UCIV__UCBIT9IFG
#define USCI_I2C_UCCLTOIFG      UCIV__UCCLTOIFG
#define USCI_I2C_UCNACKIFG      UCIV__UCNACKIFG
#define USCI_I2C_UCRXIFG0       UCIV__UCRXIFG0
#define USCI_I2C_UCRXIFG1       UCIV__UCRXIFG1
#define USCI_I2C_UCRXIFG2       UCIV__UCRXIFG2
#define USCI_I2C_UCRXIFG3       UCIV__UCRXIFG3
#define USCI_I2C_UCSTPIFG       UCIV__UCSTPIFG
#define USCI_I2C_UCSTTIFG       UCIV__UCSTTIFG
#define USCI_I2C_UCTXIFG0       UCIV__UCTXIFG0
#define USCI_I2C_UCTXIFG1       UCIV__UCTXIFG1
#define USCI_I2C_UCTXIFG2       UCIV__UCTXIFG2
#define USCI_I2C_UCTXIFG3       UCIV__UCTXIFG3
#define USCI_SPI_UCRXIFG        UCIV__UCRXIFG
#define USCI_SPI_UCTXIFG        UCIV__UCTXIFG
#define USCI_UART_UCRXIFG       UCIV__UCRXIFG
#define USCI_UART_UCSTTIFG      UCIV__UCSTTIFG
#define USCI_UART_UCTXCPTIFG    UCIV__UCTXCPTIFG
#define USCI_UART_UCTXIFG       UCIV__UCTXIFG

#endif

/************************************************************
* USCI Ax
************************************************************/

#ifdef  __MSP430_HAS_EUSCI_Ax__      /* Definition to show that Module is available */
#define __MSP430_HAS_USCI_Ax__

#define UCAxCTL1               UCA0CTLW0_L
#define UCAxCTL0               UCA0CTLW0_H
#define UCAxBR0                UCA0BRW_L
#define UCAxBR1                UCA0BRW_H
#define UCAxIRTCTL             UCA0IRCTL_L
#define UCAxIRRCTL             UCA0IRCTL_H

#define OFS_UCAxCTLW0          (0x0000)       /* USCI Ax Control Word Register 0 */
#define OFS_UCAxCTLW0_L        OFS_UCAxCTLW0
#define OFS_UCAxCTLW0_H        OFS_UCAxCTLW0+1
#define OFS_UCAxCTL0           (0x0001)
#define OFS_UCAxCTL1           (0x0000)
#define OFS_UCAxCTLW1          (0x0002)       /* USCI Ax Control Word Register 1 */
#define OFS_UCAxCTLW1_L        OFS_UCAxCTLW1
#define OFS_UCAxCTLW1_H        OFS_UCAxCTLW1+1
#define OFS_UCAxBRW            (0x0006)       /* USCI Ax Baud Word Rate 0 */
#define OFS_UCAxBRW_L          OFS_UCAxBRW
#define OFS_UCAxBRW_H          OFS_UCAxBRW+1
#define OFS_UCAxBR0            (0x0006)
#define OFS_UCAxBR1            (0x0007)
#define OFS_UCAxMCTLW          (0x0008)       /* USCI Ax Modulation Control */
#define OFS_UCAxMCTLW_L        OFS_UCAxMCTLW
#define OFS_UCAxMCTLW_H        OFS_UCAxMCTLW+1
#define OFS_UCAxSTATW          (0x000A)       /* USCI Ax Status Register */
#define OFS_UCAxRXBUF          (0x000C)       /* USCI Ax Receive Buffer */
#define OFS_UCAxRXBUF_L        OFS_UCAxRXBUF
#define OFS_UCAxRXBUF_H        OFS_UCAxRXBUF+1
#define OFS_UCAxTXBUF          (0x000E)       /* USCI Ax Transmit Buffer */
#define OFS_UCAxTXBUF_L        OFS_UCAxTXBUF
#define OFS_UCAxTXBUF_H        OFS_UCAxTXBUF+1
#define OFS_UCAxABCTL          (0x0010)       /* USCI Ax LIN Control */
#define OFS_UCAxIRCTL          (0x0012)       /* USCI Ax IrDA Transmit Control */
#define OFS_UCAxIRCTL_L        OFS_UCAxIRCTL
#define OFS_UCAxIRCTL_H        OFS_UCAxIRCTL+1
#define OFS_UCAxIRTCTL         (0x0012)
#define OFS_UCAxIRRCTL         (0x0013)
#define OFS_UCAxIE             (0x001A)       /* USCI Ax Interrupt Enable Register */
#define OFS_UCAxIE_L           OFS_UCAxIE
#define OFS_UCAxIE_H           OFS_UCAxIE+1
#define OFS_UCAxIFG            (0x001C)       /* USCI Ax Interrupt Flags Register */
#define OFS_UCAxIFG_L          OFS_UCAxIFG
#define OFS_UCAxIFG_H          OFS_UCAxIFG+1
#define OFS_UCAxIE__UART       (0x001A)
#define OFS_UCAxIE__UART_L     OFS_UCAxIE__UART
#define OFS_UCAxIE__UART_H     OFS_UCAxIE__UART+1
#define OFS_UCAxIFG__UART      (0x001C)
#define OFS_UCAxIFG__UART_L    OFS_UCAxIFG__UART
#define OFS_UCAxIFG__UART_H    OFS_UCAxIFG__UART+1
#define OFS_UCAxIV             (0x001E)       /* USCI Ax Interrupt Vector Register */

#define OFS_UCAxCTLW0__SPI     (0x0000)
#define OFS_UCAxCTLW0__SPI_L   OFS_UCAxCTLW0__SPI
#define OFS_UCAxCTLW0__SPI_H   OFS_UCAxCTLW0__SPI+1
#define OFS_UCAxCTL0__SPI      (0x0001)
#define OFS_UCAxCTL1__SPI      (0x0000)
#define OFS_UCAxBRW__SPI       (0x0006)
#define OFS_UCAxBRW__SPI_L     OFS_UCAxBRW__SPI
#define OFS_UCAxBRW__SPI_H     OFS_UCAxBRW__SPI+1
#define OFS_UCAxBR0__SPI       (0x0006)
#define OFS_UCAxBR1__SPI       (0x0007)
#define OFS_UCAxSTATW__SPI     (0x000A)
#define OFS_UCAxRXBUF__SPI     (0x000C)
#define OFS_UCAxRXBUF__SPI_L   OFS_UCAxRXBUF__SPI
#define OFS_UCAxRXBUF__SPI_H   OFS_UCAxRXBUF__SPI+1
#define OFS_UCAxTXBUF__SPI     (0x000E)
#define OFS_UCAxTXBUF__SPI_L   OFS_UCAxTXBUF__SPI
#define OFS_UCAxTXBUF__SPI_H   OFS_UCAxTXBUF__SPI+1
#define OFS_UCAxIE__SPI        (0x001A)
#define OFS_UCAxIFG__SPI       (0x001C)
#define OFS_UCAxIV__SPI        (0x001E)

#ifdef __MSP430_HAS_EUSCI_A0__
#define USCI_A0_VECTOR          EUSCI_A0_VECTOR

#define UCA0CTL1                UCA0CTLW0_L    /* USCI A0 Control Register 1 */
#define UCA0CTL0                UCA0CTLW0_H    /* USCI A0 Control Register 0 */
#define UCA0BR0                 UCA0BRW_L      /* USCI A0 Baud Rate 0 */
#define UCA0BR1                 UCA0BRW_H      /* USCI A0 Baud Rate 1 */
#define UCA0IRTCTL              UCA0IRCTL_L    /* USCI A0 IrDA Transmit Control */
#define UCA0IRRCTL              UCA0IRCTL_H    /* USCI A0 IrDA Receive Control */

#endif

#ifdef __MSP430_HAS_EUSCI_A1__
#define USCI_A1_VECTOR          EUSCI_A1_VECTOR

#define UCA1CTL1                UCA1CTLW0_L    /* USCI A1 Control Register 1 */
#define UCA1CTL0                UCA1CTLW0_H    /* USCI A1 Control Register 0 */
#define UCA1BR0                 UCA1BRW_L      /* USCI A1 Baud Rate 0 */
#define UCA1BR1                 UCA1BRW_H      /* USCI A1 Baud Rate 1 */
#define UCA1IRTCTL              UCA1IRCTL_L    /* USCI A1 IrDA Transmit Control */
#define UCA1IRRCTL              UCA1IRCTL_H    /* USCI A1 IrDA Receive Control */

#endif

#ifdef __MSP430_HAS_EUSCI_A2__
#define USCI_A2_VECTOR          EUSCI_A2_VECTOR

#define UCA2CTL1                UCA2CTLW0_L    /* USCI A2 Control Register 1 */
#define UCA2CTL0                UCA2CTLW0_H    /* USCI A2 Control Register 0 */
#define UCA2BR0                 UCA2BRW_L      /* USCI A2 Baud Rate 0 */
#define UCA2BR1                 UCA2BRW_H      /* USCI A2 Baud Rate 1 */
#define UCA2IRTCTL              UCA2IRCTL_L    /* USCI A2 IrDA Transmit Control */
#define UCA2IRRCTL              UCA2IRCTL_H    /* USCI A2 IrDA Receive Control */

#endif

#ifdef __MSP430_HAS_EUSCI_A3__
#define USCI_A3_VECTOR          EUSCI_A3_VECTOR

#define UCA3CTL1                UCA3CTLW0_L    /* USCI A3 Control Register 1 */
#define UCA3CTL0                UCA3CTLW0_H    /* USCI A3 Control Register 0 */
#define UCA3BR0                 UCA3BRW_L      /* USCI A3 Baud Rate 0 */
#define UCA3BR1                 UCA3BRW_H      /* USCI A3 Baud Rate 1 */
#define UCA3IRTCTL              UCA3IRCTL_L    /* USCI A3 IrDA Transmit Control */
#define UCA3IRRCTL              UCA3IRCTL_H    /* USCI A3 IrDA Receive Control */

#endif

#endif

/************************************************************
* USCI Bx
************************************************************/

#ifdef  __MSP430_HAS_EUSCI_Bx__       /* Definition to show that Module is available */
#define __MSP430_HAS_USCI_Bx__

#define UCBxCTL1               UCB0CTLW0_L
#define UCBxCTL0               UCB0CTLW0_H
#define UCBxBR0                UCB0BRW_L
#define UCBxBR1                UCB0BRW_H
#define UCBxSTAT               UCB0STATW_L
#define UCBxBCNT               UCB0STATW_H

#define OFS_UCBxCTLW0__SPI     (0x0000)
#define OFS_UCBxCTLW0__SPI_L   OFS_UCBxCTLW0__SPI
#define OFS_UCBxCTLW0__SPI_H   OFS_UCBxCTLW0__SPI+1
#define OFS_UCBxCTL0__SPI      (0x0001)
#define OFS_UCBxCTL1__SPI      (0x0000)
#define OFS_UCBxBRW__SPI       (0x0006)
#define OFS_UCBxBRW__SPI_L     OFS_UCBxBRW__SPI
#define OFS_UCBxBRW__SPI_H     OFS_UCBxBRW__SPI+1
#define OFS_UCBxBR0__SPI       (0x0006)
#define OFS_UCBxBR1__SPI       (0x0007)
#define OFS_UCBxSTATW__SPI     (0x0008)
#define OFS_UCBxSTATW__SPI_L   OFS_UCBxSTATW__SPI
#define OFS_UCBxSTATW__SPI_H   OFS_UCBxSTATW__SPI+1
#define OFS_UCBxRXBUF__SPI     (0x000C)
#define OFS_UCBxRXBUF__SPI_L   OFS_UCBxRXBUF__SPI
#define OFS_UCBxRXBUF__SPI_H   OFS_UCBxRXBUF__SPI+1
#define OFS_UCBxTXBUF__SPI     (0x000E)
#define OFS_UCBxTXBUF__SPI_L   OFS_UCBxTXBUF__SPI
#define OFS_UCBxTXBUF__SPI_H   OFS_UCBxTXBUF__SPI+1
#define OFS_UCBxIE__SPI        (0x002A)
#define OFS_UCBxIE__SPI_L      OFS_UCBxIE__SPI
#define OFS_UCBxIE__SPI_H      OFS_UCBxIE__SPI+1
#define OFS_UCBxIFG__SPI       (0x002C)
#define OFS_UCBxIFG__SPI_L     OFS_UCBxIFG__SPI
#define OFS_UCBxIFG__SPI_H     OFS_UCBxIFG__SPI+1
#define OFS_UCBxIV__SPI        (0x002E)

#define OFS_UCBxCTLW0          (0x0000)       /* USCI Bx Control Word Register 0 */
#define OFS_UCBxCTLW0_L        OFS_UCBxCTLW0
#define OFS_UCBxCTLW0_H        OFS_UCBxCTLW0+1
#define OFS_UCBxCTL0           (0x0001)
#define OFS_UCBxCTL1           (0x0000)
#define OFS_UCBxCTLW1          (0x0002)       /* USCI Bx Control Word Register 1 */
#define OFS_UCBxCTLW1_L        OFS_UCBxCTLW1
#define OFS_UCBxCTLW1_H        OFS_UCBxCTLW1+1
#define OFS_UCBxBRW            (0x0006)       /* USCI Bx Baud Word Rate 0 */
#define OFS_UCBxBRW_L          OFS_UCBxBRW
#define OFS_UCBxBRW_H          OFS_UCBxBRW+1
#define OFS_UCBxBR0            (0x0006)
#define OFS_UCBxBR1            (0x0007)
#define OFS_UCBxSTATW          (0x0008)       /* USCI Bx Status Word Register */
#define OFS_UCBxSTATW_L        OFS_UCBxSTATW
#define OFS_UCBxSTATW_H        OFS_UCBxSTATW+1
#define OFS_UCBxSTATW__I2C     (0x0008)
#define OFS_UCBxSTAT__I2C      (0x0008)
#define OFS_UCBxBCNT__I2C      (0x0009)
#define OFS_UCBxTBCNT          (0x000A)       /* USCI Bx Byte Counter Threshold Register */
#define OFS_UCBxTBCNT_L        OFS_UCBxTBCNT
#define OFS_UCBxTBCNT_H        OFS_UCBxTBCNT+1
#define OFS_UCBxRXBUF          (0x000C)       /* USCI Bx Receive Buffer */
#define OFS_UCBxRXBUF_L        OFS_UCBxRXBUF
#define OFS_UCBxRXBUF_H        OFS_UCBxRXBUF+1
#define OFS_UCBxTXBUF          (0x000E)       /* USCI Bx Transmit Buffer */
#define OFS_UCBxTXBUF_L        OFS_UCBxTXBUF
#define OFS_UCBxTXBUF_H        OFS_UCBxTXBUF+1
#define OFS_UCBxI2COA0         (0x0014)       /* USCI Bx I2C Own Address 0 */
#define OFS_UCBxI2COA0_L       OFS_UCBxI2COA0
#define OFS_UCBxI2COA0_H       OFS_UCBxI2COA0+1
#define OFS_UCBxI2COA1         (0x0016)       /* USCI Bx I2C Own Address 1 */
#define OFS_UCBxI2COA1_L       OFS_UCBxI2COA1
#define OFS_UCBxI2COA1_H       OFS_UCBxI2COA1+1
#define OFS_UCBxI2COA2         (0x0018)       /* USCI Bx I2C Own Address 2 */
#define OFS_UCBxI2COA2_L       OFS_UCBxI2COA2
#define OFS_UCBxI2COA2_H       OFS_UCBxI2COA2+1
#define OFS_UCBxI2COA3         (0x001A)       /* USCI Bx I2C Own Address 3 */
#define OFS_UCBxI2COA3_L       OFS_UCBxI2COA3
#define OFS_UCBxI2COA3_H       OFS_UCBxI2COA3+1
#define OFS_UCBxADDRX          (0x001C)       /* USCI Bx Received Address Register */
#define OFS_UCBxADDRX_L        OFS_UCBxADDRX
#define OFS_UCBxADDRX_H        OFS_UCBxADDRX+1
#define OFS_UCBxADDMASK        (0x001E)       /* USCI Bx Address Mask Register */
#define OFS_UCBxADDMASK_L      OFS_UCBxADDMASK
#define OFS_UCBxADDMASK_H      OFS_UCBxADDMASK+1
#define OFS_UCBxI2CSA          (0x0020)       /* USCI Bx I2C Slave Address */
#define OFS_UCBxI2CSA_L        OFS_UCBxI2CSA
#define OFS_UCBxI2CSA_H        OFS_UCBxI2CSA+1
#define OFS_UCBxIE             (0x002A)       /* USCI Bx Interrupt Enable Register */
#define OFS_UCBxIE_L           OFS_UCBxIE
#define OFS_UCBxIE_H           OFS_UCBxIE+1
#define OFS_UCBxIFG            (0x002C)       /* USCI Bx Interrupt Flags Register */
#define OFS_UCBxIFG_L          OFS_UCBxIFG
#define OFS_UCBxIFG_H          OFS_UCBxIFG+1
#define OFS_UCBxIE__I2C        (0x002A)
#define OFS_UCBxIE__I2C_L      OFS_UCBxIE__I2C
#define OFS_UCBxIE__I2C_H      OFS_UCBxIE__I2C+1
#define OFS_UCBxIFG__I2C       (0x002C)
#define OFS_UCBxIFG__I2C_L     OFS_UCBxIFG__I2C
#define OFS_UCBxIFG__I2C_H     OFS_UCBxIFG__I2C+1
#define OFS_UCBxIV             (0x002E)       /* USCI Bx Interrupt Vector Register */

#ifndef UCASTP_3
#define UCASTP_3                UCASTP
#endif

#ifdef __MSP430_HAS_EUSCI_B0__
#define USCI_B0_VECTOR          EUSCI_B0_VECTOR

#define UCB0CTL1                UCB0CTLW0_L    /* USCI B0 Control Register 1 */
#define UCB0CTL0                UCB0CTLW0_H    /* USCI B0 Control Register 0 */
#define UCB0BR0                 UCB0BRW_L      /* USCI B0 Baud Rate 0 */
#define UCB0BR1                 UCB0BRW_H      /* USCI B0 Baud Rate 1 */
#define UCB0STAT                UCB0STATW_L    /* USCI B0 Status Register */
#define UCB0BCNT                UCB0STATW_H    /* USCI B0 Byte Counter Register */

#endif

#ifdef __MSP430_HAS_EUSCI_B1__
#define USCI_B1_VECTOR          EUSCI_B1_VECTOR

#define UCB1CTL1                UCB1CTLW0_L    /* USCI B1 Control Register 1 */
#define UCB1CTL0                UCB1CTLW0_H    /* USCI B1 Control Register 0 */
#define UCB1BR0                 UCB1BRW_L      /* USCI B1 Baud Rate 0 */
#define UCB1BR1                 UCB1BRW_H      /* USCI B1 Baud Rate 1 */
#define UCB1STAT                UCB1STATW_L    /* USCI B1 Status Register */
#define UCB1BCNT                UCB1STATW_H    /* USCI B1 Byte Counter Register */

#endif

#ifdef __MSP430_HAS_EUSCI_B2__
#define USCI_B2_VECTOR          EUSCI_B2_VECTOR

#define UCB2CTL1                UCB2CTLW0_L    /* USCI B2 Control Register 1 */
#define UCB2CTL0                UCB2CTLW0_H    /* USCI B2 Control Register 0 */
#define UCB2BR0                 UCB2BRW_L      /* USCI B2 Baud Rate 0 */
#define UCB2BR1                 UCB2BRW_H      /* USCI B2 Baud Rate 1 */
#define UCB2STAT                UCB2STATW_L    /* USCI B2 Status Register */
#define UCB2BCNT                UCB2STATW_H    /* USCI B2 Byte Counter Register */

#endif

#ifdef __MSP430_HAS_EUSCI_B3__
#define USCI_B3_VECTOR          EUSCI_B3_VECTOR

#define UCB3CTL1                UCB3CTLW0_L    /* USCI B3 Control Register 1 */
#define UCB3CTL0                UCB3CTLW0_H    /* USCI B3 Control Register 0 */
#define UCB3BR0                 UCB3BRW_L      /* USCI B3 Baud Rate 0 */
#define UCB3BR1                 UCB3BRW_H      /* USCI B3 Baud Rate 1 */
#define UCB3STAT                UCB3STATW_L    /* USCI B3 Status Register */
#define UCB3BCNT                UCB3STATW_H    /* USCI B3 Byte Counter Register */

#endif

#endif

/************************************************************
* WDT
************************************************************/

#ifdef __MSP430_HAS_WDT_A__       /* Definition to show that Module is available */

/* WDT-interval times [1ms] coded with Bits 0-2 */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MDLY_32             (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2)                         /* 32ms interval (default) */
#define WDT_MDLY_8              (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTIS0)                  /* 8ms     " */
#define WDT_MDLY_0_5            (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTIS1)                  /* 0.5ms   " */
#define WDT_MDLY_0_064          (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTIS1+WDTIS0)           /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ADLY_1000           (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0)                /* 1000ms  " */
#define WDT_ADLY_250            (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0+WDTIS0)         /* 250ms   " */
#define WDT_ADLY_16             (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0+WDTIS1)         /* 16ms    " */
#define WDT_ADLY_1_9            (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS2+WDTSSEL0+WDTIS1+WDTIS0)  /* 1.9ms   " */
/* Watchdog mode -> reset after expired time */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MRST_32             (WDTPW+WDTCNTCL+WDTIS2)                                  /* 32ms interval (default) */
#define WDT_MRST_8              (WDTPW+WDTCNTCL+WDTIS2+WDTIS0)                           /* 8ms     " */
#define WDT_MRST_0_5            (WDTPW+WDTCNTCL+WDTIS2+WDTIS1)                           /* 0.5ms   " */
#define WDT_MRST_0_064          (WDTPW+WDTCNTCL+WDTIS2+WDTIS1+WDTIS0)                    /* 0.064ms " */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ARST_1000           (WDTPW+WDTCNTCL+WDTSSEL0+WDTIS2)                         /* 1000ms  " */
#define WDT_ARST_250            (WDTPW+WDTCNTCL+WDTSSEL0+WDTIS2+WDTIS0)                  /* 250ms   " */
#define WDT_ARST_16             (WDTPW+WDTCNTCL+WDTSSEL0+WDTIS2+WDTIS1)                  /* 16ms    " */
#define WDT_ARST_1_9            (WDTPW+WDTCNTCL+WDTSSEL0+WDTIS2+WDTIS1+WDTIS0)           /* 1.9ms   " */

#define WDTSSEL__VLO            WDTSSEL__VLOCLK

#endif
