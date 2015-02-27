/**
 * @file user_config.h
 *
 * @date 2015-02-25
 * @author Pascal Gollor (http://www.pgollor.de)
 *
 * Copyright (c) 2015 Pascal Gollor <pascal@pgollor.de>
 * Dieses Material steht unter der Creative-Commons-Lizenz Namensnennung 4.0 International.
 * Um eine Kopie dieser Lizenz zu sehen, besuchen Sie http://creativecommons.org/licenses/by/4.0/.
 */

#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__


/**
 * @defgroup softAP definitions
 * @{
 */
/// name of esp8266 access point
#define SOFTAP_SSID "microWifi"


/// this enables encryption for esp8266 as access point
//#define SOFTAP_ENCRYPT


#ifdef SOFTAP_ENCRYPT
	/// SoftAP password
	#define SOFTAP_PASSWORD "foofoofoo123"
#endif
/// @}

/// use IO functions (actually GPIO0 and GPIO2)
//#define USE_IO


/**
 * @defgroup debug definitions
 *
 * @{
 */
#define DEBUG_SOFTAP

/**
 * @brief select UART for debugging
 *
 * 0: TX and RX PIN
 * 1: GPIO2 as TX Pin
 *
 * If you use GPIO2 as debugging UART then you are not able to use this as GPIO pin.
 * You have do disable all GPIO usage for GPIO2.
 */
#define DEBUG_UART 1

/**
 * @}
 */


/// os_printf line ending
#define PRINTF_LINEENDING "\n"



#endif // __USER_CONFIG_H__
