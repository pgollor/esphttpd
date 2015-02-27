/**
 * @file io.c
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

#include "io.h"

#include "user_interface.h"
#include "espconn.h"
#include "mem.h"
#include "osapi.h"
#include "gpio.h"
#include "espmissingincludes.h"


static ETSTimer resetBtntimer;


/**
 * @brief set or reset LED state
 * @param ena: 1: enable - 0: disable
 */
void ICACHE_FLASH_ATTR ioLed(int ena)
{
	//gpio_output_set is overkill. ToDo: use better mactos
	if (ena)
	{
		gpio_output_set((1<<LEDGPIO), 0, (1<<LEDGPIO), 0);
	}
	else
	{
		gpio_output_set(0, (1<<LEDGPIO), (1<<LEDGPIO), 0);
	}
}


/**
 * @brief timer function for reading GPIO state
 * @param arg: timer arguments
 */
static void ICACHE_FLASH_ATTR resetBtnTimerCb(void *arg)
{
	static int resetCnt = 0;

	if (!GPIO_INPUT_GET(BTNGPIO))
	{
		resetCnt++;
	}
	else
	{
		if (resetCnt >= 6)
		{ //3 sec pressed
			wifi_station_disconnect();
			wifi_set_opmode(0x3); //reset to AP+STA mode
			os_printf("Reset to AP mode. Restarting system...\n");
			system_restart();
		}

		resetCnt=0;
	}
}


/**
 * @brief initialize GPIO
 */
void ioInit()
{
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2); // enable GPIO2
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0); // enable GPIO0

	gpio_output_set(0, 0, (1 << LEDGPIO), (1 << BTNGPIO));

	// init timer for reading gpio state
	os_timer_disarm(&resetBtntimer);
	os_timer_setfn(&resetBtntimer, resetBtnTimerCb, NULL);
	os_timer_arm(&resetBtntimer, 500, 1);
}

