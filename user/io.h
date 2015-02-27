/**
 * @file io.h
 *
 * @date unknown
 * @author Jeroen Domburg <jeroen@spritesmods.com>
 *
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Jeroen Domburg <jeroen@spritesmods.com> wrote this file. As long as you retain
 * this notice you can do whatever you want with this stuff. If we meet some day,
 * and you think this stuff is worth it, you can buy me a beer in return.
 * ----------------------------------------------------------------------------
 */

#ifndef __IO_H__
#define __IO_H__


#include "c_types.h"
#include "eagle_soc.h"


// definitions
/**
 * @defgroup LED pin
 * @{
 */
#define LED_GPIO            2
#define LED_FUNC_GPIO       FUNC_GPIO2
#define LED_PERIPHS_IO_MUX  PERIPHS_IO_MUX_GPIO2_U
/// @}

/**
 * @defgroup Button pin
 * @{
 */
#define BTN_GPIO            0
#define BTN_FUNC_GPIO       FUNC_GPIO0
#define BTN_PERIPHS_IO_MUX  PERIPHS_IO_MUX_GPIO0_U
/// @}

// functions
void ICACHE_FLASH_ATTR ioLed(int ena);
void ioInit(void);


#endif // __IO_H__
