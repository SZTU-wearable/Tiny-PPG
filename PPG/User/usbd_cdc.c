/*
 * usbd_cdc.c
 *
 *  Created on: Apr 9, 2023
 *      Author: Z
 */

#include "usbd_cdc.h"

void CDC_Send(uint8_t* Buf)
{
	uint16_t Len = strlen((char *)Buf);
	while(CDC_Transmit_FS(Buf, Len) == USBD_BUSY);
}


