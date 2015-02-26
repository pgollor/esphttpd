/**
 * @file con_init.h
 *
 * @date 2015-02-25
 * @author Pascal Gollor (http://www.pgollor.de)
 * 
 *
 * Copyright (c) 2015 Pascal Gollor <pascal@pgollor.de>
 * Dieses Material steht unter der Creative-Commons-Lizenz Namensnennung 4.0 International.
 * Um eine Kopie dieser Lizenz zu sehen, besuchen Sie http://creativecommons.org/licenses/by/4.0/.
 */

#ifndef __CON_INIT_H__
#define __CON_INIT_H__

#include "user_config.h"

//functions
void wifi_init(void);
#ifdef DEBUG_SOFTAP
	void print_wifi_softap_info(void);
#endif



#endif // __CON_INIT_H__
