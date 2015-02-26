/**
 * @file con_init.h
 *
 * @date 2015-02-25
 * @author Pascal Gollor (http://www.pgollor.de)
 * 
 * @copyright Dieses Material steht unter der Creative-Commons-Lizenz Namensnennung 4.0 International. Um eine Kopie dieser Lizenz zu sehen, besuchen Sie http://creativecommons.org/licenses/by/4.0/.
 */

#include "con_init.h"

#include "espmissingincludes.h" // needs for missing includes like ets_...
#include <user_interface.h>
#include <osapi.h> // os_...


void wifi_init(void)
{
	struct softap_config config;
	//struct dhcps_lease lease;
#if defined(SOFTAP_SSID) || defined(SOFTAP_ENCRYPT)
	char buff[33];
#endif
	//uint8 macaddr[6];
 
	wifi_softap_get_config(&config);
	//wifi_get_macaddr(SOFTAP_IF, macaddr);

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
#endif

	/// set config
	wifi_softap_set_config(&config);

	/**
	 * @brief dhcp server
	 * @{
	 */
	// set ip range
	//lease.start_ip = 100;
	//lease.stop_ip = 110;
	//wifi_softap_set_dhcps_lease(&lease);

	// start server
	//wifi_softap_dhcps_start();
	/// @}
}
