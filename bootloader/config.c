/*-------------------------------------------------------------------------
  config.c - PIC configuration words

             (c) 2006 Pierre Gaufillet <pierre.gaufillet@magic.fr> 

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
-------------------------------------------------------------------------*/

/* $Id: config.c,v 1.1 2006/04/17 20:36:15 gaufille Exp $ */

#include <pic18fregs.h>
#include "flash.h"

/* Set the PIC config words */

/* CONFIG1L */
#pragma config PLLDIV = 3
#pragma config CPUDIV = OSC1_PLL2
#pragma config USBDIV = 2

/* CONFIG1H */
#pragma config FOSC = HSPLL_HS
#pragma config FCMEN = OFF
#pragma config IESO = OFF

/* CONFIG2L */
#pragma config PWRT = ON
#pragma config BOR = OFF
#pragma config BORV = 2
#pragma config VREGEN = ON

/* CONFIG2H */
#pragma config WDT = OFF
#pragma config WDTPS = 1

/* CONFIG3H */
#pragma config CCP2MX = OFF
#pragma config PBADEN = OFF
#pragma config LPT1OSC = OFF
#pragma config MCLRE = ON

/* CONFIG4L */
#pragma config STVREN = ON
#pragma config LVP = ON
#pragma config XINST = OFF
#pragma config DEBUG = OFF

/* CONFIG5L */
#pragma config CP0 = OFF
#pragma config CP1 = OFF
#pragma config CP2 = OFF

/* CONFIG5H */
#pragma config CPB = OFF
#pragma config CPD = OFF

/* CONFIG6L */
#pragma config WRT0 = ON
#pragma config WRT1 = OFF
#pragma config WRT2 = OFF

/* CONFIG6H */
#pragma config WRTC = OFF
#pragma config WRTB = ON
#pragma config WRTD = OFF

/* CONFIG7L */
#pragma config EBTR0 = OFF
#pragma config EBTR1 = OFF
#pragma config EBTR2 = OFF

/* CONFIG7H */
#pragma config EBTRB = OFF

/* Memory sections for flash operations */
const uchar section_descriptor [22] = {3,
                                     FLASH_SECTION_READ,
                                     0x00, 0x00, 0x00,
                                     0xff, 0x1f, 0x00,
                                     FLASH_SECTION_READ | FLASH_SECTION_WRITE,
                                     0x00, 0x20, 0x00,
                                     0xff, 0x5f, 0x00,
                                     FLASH_SECTION_READ,
                                     0x00, 0x00, 0x30,
                                     0x0d, 0x00, 0x30};

