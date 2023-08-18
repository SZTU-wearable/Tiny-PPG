/*
 * usbd_cdc.h
 *
 *  Created on: 2023Äê4ÔÂ2ÈÕ
 *      Author: Z
 */

#ifndef USART_USART_H_
#define USART_USART_H_

#include "stm32f7xx_hal.h"
#include "string.h"
#include "usbd_cdc_if.h"

void CDC_Send(uint8_t* Buf);

#endif /* USART_USART_H_ */
