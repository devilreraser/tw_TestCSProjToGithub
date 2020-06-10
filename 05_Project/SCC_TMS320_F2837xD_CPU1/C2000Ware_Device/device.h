//#############################################################################
//
// FILE:   device.h
//
// TITLE:  Device setup for examples.
//
//#############################################################################
// $TI Release: F2837xD Support Library v3.06.00.00 $
// $Release Date: Mon May 27 06:48:24 CDT 2019 $
// $Copyright:
// Copyright (C) 2013-2019 Texas Instruments Incorporated - http://www.ti.com/
//
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions 
// are met:
// 
//   Redistributions of source code must retain the above copyright 
//   notice, this list of conditions and the following disclaimer.
// 
//   Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the 
//   documentation and/or other materials provided with the   
//   distribution.
// 
//   Neither the name of Texas Instruments Incorporated nor the names of
//   its contributors may be used to endorse or promote products derived
//   from this software without specific prior written permission.
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
// $
//#############################################################################

//
// Included Files
//
#include "driverlib.h"
#include "boardcfg.h"
#ifdef USE_PINMUX
#include "pinmux.h"
#endif


#if (!defined(CPU1) && !defined(CPU2) && !defined(CPU))
#error "You must define CPU1 or CPU2 or CPU for one core in your project properties.  Otherwise, the offsets in your header files will be inaccurate."
#endif

#if ((defined(CPU1) && defined(CPU2)) || (defined(CPU) && defined(CPU2)) || (defined(CPU) && defined(CPU1)))
#error "You have defined both CPU1 and CPU2 or CPU for one core in your project properties.  Only \
a single CPU should be defined."
#endif

//*****************************************************************************
//
// Defines for pin numbers and other GPIO configuration
//
//*****************************************************************************

#if 0

//
// LEDs
//
#define DEVICE_GPIO_PIN_LED1        31U  // GPIO number for LD2
#define DEVICE_GPIO_PIN_LED2        34U  // GPIO number for LD3
#define DEVICE_GPIO_CFG_LED1        GPIO_31_GPIO31  // "pinConfig" for LD2
#define DEVICE_GPIO_CFG_LED2        GPIO_34_GPIO34  // "pinConfig" for LD3

//
// SCI for USB-to-UART adapter on FTDI chip
//
#define DEVICE_GPIO_PIN_SCIRXDA     28U             // GPIO number for SCI RX
#define DEVICE_GPIO_PIN_SCITXDA     29U             // GPIO number for SCI TX
#define DEVICE_GPIO_CFG_SCIRXDA     GPIO_28_SCIRXDA // "pinConfig" for SCI RX
#define DEVICE_GPIO_CFG_SCITXDA     GPIO_29_SCITXDA // "pinConfig" for SCI TX

//
// CANA
//
#define DEVICE_GPIO_PIN_CANTXA      31U  // GPIO number for CANTXA
#define DEVICE_GPIO_PIN_CANRXA      30U  // GPIO number for CANRXA

//
// CAN External Loopback
//
#define DEVICE_GPIO_CFG_CANRXA      GPIO_30_CANRXA  // "pinConfig" for CANA RX
#define DEVICE_GPIO_CFG_CANTXA      GPIO_31_CANTXA  // "pinConfig" for CANA TX
#define DEVICE_GPIO_CFG_CANRXB      GPIO_10_CANRXB  // "pinConfig" for CANB RX
#define DEVICE_GPIO_CFG_CANTXB      GPIO_8_CANTXB   // "pinConfig" for CANB TX

#endif


//*****************************************************************************
//
// Defines related to clock configuration
//
//*****************************************************************************


//
// Clock Configuration
//


#define SYSCTL_OSCSRC_OSC2      0x00000000U
//! External oscillator (XTAL) in crystal mode
#define SYSCTL_OSCSRC_XTAL      0x00010000U
//! Internal oscillator INTOSC1
#define SYSCTL_OSCSRC_OSC1      0x00020000U



#ifdef _LAUNCHXL_F28379D

#define DEVICE_OSCSRC_XTAL          10000000U           /* 10MHz XTAL on LaunchPad */
#define DEVICE_SYSCLK_FREQ         200000000U           /* 200MHz SYSCLK frequency */
#define DEVICE_OSCSRC_USED         SYSCTL_OSCSRC_XTAL   /* SYSCTL_OSCSRC_OSC2, SYSCTL_OSCSRC_XTAL or SYSCTL_OSCSRC_OSC1 */
#define DEVICE_INTEGER_DIV         2                    /* 1,2,4,6,8...126 */

#elif BOARDCFG_BOARD == BOARDCFG_BOARD_SCC_BIG

#define DEVICE_OSCSRC_XTAL          20000000U           /* 20MHz XTAL on SCC BIG */
#define DEVICE_SYSCLK_FREQ         200000000U           /* 200MHz SYSCLK frequency */
#define DEVICE_OSCSRC_USED         SYSCTL_OSCSRC_XTAL   /* SYSCTL_OSCSRC_OSC2, SYSCTL_OSCSRC_XTAL or SYSCTL_OSCSRC_OSC1 */
#define DEVICE_INTEGER_DIV         2                    /* 1,2,4,6,8...126 */

#elif BOARDCFG_BOARD == BOARDCFG_BOARD_SCC_SMALL_TEST

#define DEVICE_OSCSRC_XTAL          25000000U           /* 25MHz XTAL on SCC SMALL with 28075 */
#define DEVICE_SYSCLK_FREQ         120000000U           /* 120MHz SYSCLK frequency */
#define DEVICE_OSCSRC_USED         SYSCTL_OSCSRC_OSC2   /* SYSCTL_OSCSRC_OSC2, SYSCTL_OSCSRC_XTAL or SYSCTL_OSCSRC_OSC1 */
#define DEVICE_INTEGER_DIV         2                    /* 1,2,4,6,8...126 */

#elif BOARDCFG_BOARD == BOARDCFG_BOARD_CS_1107_SCC

#define DEVICE_OSCSRC_XTAL          20000000U           /* 25MHz XTAL on SCC BIG */
#define DEVICE_SYSCLK_FREQ         200000000U           /* 200MHz SYSCLK frequency */
#define DEVICE_OSCSRC_USED         SYSCTL_OSCSRC_XTAL   /* SYSCTL_OSCSRC_OSC2, SYSCTL_OSCSRC_XTAL or SYSCTL_OSCSRC_OSC1 */
#define DEVICE_INTEGER_DIV         2                    /* 1,2,4,6,8...126 */

#endif

#undef FCY_HZ
#define FCY_HZ DEVICE_SYSCLK_FREQ

#if DEVICE_OSCSRC_USED == SYSCTL_OSCSRC_XTAL
#define DEVICE_OSCSRC_FREQ          DEVICE_OSCSRC_XTAL
#else
#define DEVICE_OSCSRC_FREQ          10000000U
#endif

/* for 28075:     120 MHz <= DEVICE_SYSCLK_FREQ * (DEVICE_INTEGER_MULT + DEVICE_FRACTIONAL_MULT) <= 400 MHz */

#define DEVICE_INTEGER_MULT         (uint16_t)( ( DEVICE_SYSCLK_FREQ * DEVICE_INTEGER_DIV ) / DEVICE_OSCSRC_FREQ )
#define DEVICE_FRACTIONAL_MULT      SYSCTL_FMULT_NONE /* SYSCTL_FMULT_NONE, SYSCTL_FMULT_1_4, SYSCTL_FMULT_1_2, SYSCTL_FMULT_3_4 */

//
// Define to pass to SysCtl_setClock(). Will configure the clock as follows:
// PLLSYSCLK = DEVICE_OSCSRC_FREQ (XTAL_OSC) * DEVICE_INTEGER_MULT (IMULT) * 1 (FMULT) / 2 (PLLCLK_BY_2)
//
#define DEVICE_SETCLOCK_CFG         (DEVICE_OSCSRC_USED | SYSCTL_IMULT(DEVICE_INTEGER_MULT) |  \
                                     SYSCTL_FMULT_NONE | SYSCTL_SYSDIV(DEVICE_INTEGER_DIV) |   \
                                     SYSCTL_PLL_ENABLE)


//
// 50MHz LSPCLK frequency based on the above DEVICE_SYSCLK_FREQ and a default
// low speed peripheral clock divider of 4. Update the code below if a
// different LSPCLK divider is used!
//
#define DEVICE_LSPCLK_DIVIDER       1
#define DEVICE_LSPCLK_FREQ          (DEVICE_SYSCLK_FREQ / DEVICE_LSPCLK_DIVIDER)

//*****************************************************************************
//
// Macro to call SysCtl_delay() to achieve a delay in microseconds. The macro
// will convert the desired delay in microseconds to the count value expected
// by the function. \b x is the number of microseconds to delay.
//
//*****************************************************************************
#define DEVICE_DELAY_US(x) SysCtl_delay(((((long double)(x)) / (1000000.0L /  \
                              (long double)DEVICE_SYSCLK_FREQ)) - 9.0L) / 5.0L)

//*****************************************************************************
//
// Defines, Globals, and Header Includes related to Flash Support
//
//*****************************************************************************
#ifdef _FLASH
#include <stddef.h>

extern uint16_t RamfuncsLoadStart;
extern uint16_t RamfuncsLoadEnd;
extern uint16_t RamfuncsLoadSize;
extern uint16_t RamfuncsRunStart;
extern uint16_t RamfuncsRunEnd;
extern uint16_t RamfuncsRunSize;

#define DEVICE_FLASH_WAITSTATES 3

#endif

extern uint32_t Example_PassCount;
extern uint32_t Example_Fail;

//*****************************************************************************
//
// Function Prototypes
//
//*****************************************************************************
extern void Device_init(void);
extern void Device_enableAllPeripherals(void);
extern void Device_initGPIO(void);
extern void Device_enableUnbondedGPIOPullupsFor176Pin(void);
extern void Device_enableUnbondedGPIOPullupsFor100Pin(void);
extern void Device_enableUnbondedGPIOPullups(void);
extern void __error__(char *filename, uint32_t line);
extern void Example_setResultPass(void);
extern void Example_setResultFail(void);
extern void Example_done(void);

//
// End of file
//
