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


// definitions
#define LEDGPIO 2
#define BTNGPIO 0

// functions
void ICACHE_FLASH_ATTR ioLed(int ena);
void ioInit(void);


#endif // __IO_H__
