/**
 * @file uart_rx_handle.c
 *
 * @date 27.02.2015
 * @author Pascal Gollor
 */

#include "uart_rx_handle.h"
#include "user_config.h"
#include "osapi.h"


// variables
char _uart_rx_buffer[RX_BUFF_SIZE];


void uart_rx_handle(RcvMsgBuff *rxBuff)
{
	// debugging code
	for (; rxBuff->pReadPos < rxBuff->pWritePos; rxBuff->pReadPos++)
	{
		os_printf("%c", *(rxBuff->pReadPos));
	}
	os_printf(PRINTF_LINEENDING);
}
