/**
 * @file con_init.c
 *
 * @date 2015-02-25
 * @author Pascal Gollor (http://www.pgollor.de)
 * 
 *
 * Copyright (c) 2015 Pascal Gollor <pascal@pgollor.de>
 * Dieses Material steht unter der Creative-Commons-Lizenz Namensnennung 4.0 International.
 * Um eine Kopie dieser Lizenz zu sehen, besuchen Sie http://creativecommons.org/licenses/by/4.0/.
 */

#include "con_init.h"
#include "user_config.h"

#include <espmissingincludes.h> // needs for missing includes like ets_...
#include <user_interface.h>
#include <osapi.h> // os_...


void ICACHE_FLASH_ATTR wifi_init(void)
{
	struct softap_config config;
	//struct dhcps_lease lease;
#if defined(SOFTAP_SSID) || defined(SOFTAP_ENCRYPT)
	char buff[33];
#endif

	wifi_softap_get_config(&config);

#ifdef SOFTAP_SSID
	/**
	 * @brief ssid
	 * @{
	 */
	// clear ssid
	os_memset(config.ssid, 0, sizeof(config.ssid));

	// store ssid from definition info buffer variable
	os_sprintf(buff, "%s", SOFTAP_SSID);

	// copy ssid to memory
	os_memcpy(config.ssid, buff, os_strlen(buff));
	/// @}
#endif

#ifdef SOFTAP_ENCRYPT
	/**
	 * @brief password
	 * @{
	 */
	// clear passwort
	os_memset(config.password, 0, sizeof(config.password));

	// store password from const into buffer variable
	os_sprintf(buff, "%s", SOFTAP_PASSWORD);

	// copy password to memory
	os_memcpy(config.password, buff, os_strlen(buff));

	// set auth mode
	config.authmode = AUTH_WPA_WPA2_PSK;
	/// @}
#else
	config.authmode = AUTH_OPEN;
#endif

	/// set config
	wifi_softap_set_config(&config);

	/**
	 * @brief dhcp server
	 * @{
	 */
	// set ip range
	//lease.start_ip = 100;
	//lease.end_ip = 110;
	//wifi_softap_set_dhcps_lease(&lease);

	// start server
	//wifi_softap_dhcps_start();
	/// @}

	// print config
#ifdef DEBUG_SOFTAP
	os_printf(PRINTF_LINEENDING "---------- softAP info ----------" PRINTF_LINEENDING);
	os_printf("ssid: %s" PRINTF_LINEENDING, config.ssid);
	os_printf("channel: %d" PRINTF_LINEENDING, config.channel);

	os_printf("authmode: ");
	switch (config.authmode)
	{
	case AUTH_OPEN:
		os_printf("open" PRINTF_LINEENDING);
		break;
	case AUTH_WEP:
		os_printf("WEP" PRINTF_LINEENDING);
		break;
	case AUTH_WPA_PSK:
		os_printf("WPA PSK" PRINTF_LINEENDING);
		break;
	case AUTH_WPA2_PSK:
		os_printf("WPA2 PSK" PRINTF_LINEENDING);
		break;
	case AUTH_WPA_WPA2_PSK:
		os_printf("WPA WPA2 PSK" PRINTF_LINEENDING);
		break;
	case AUTH_MAX:
		os_printf("MAX" PRINTF_LINEENDING);
		break;
	default:
		os_printf("unknown" PRINTF_LINEENDING);
		break;
	}

	os_printf("---------- softAP info ----------" PRINTF_LINEENDING);
#endif
}

