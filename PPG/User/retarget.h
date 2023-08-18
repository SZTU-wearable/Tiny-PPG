/*
 * retarget.h
 *
 *  Created on: Apr 12, 2023
 *      Author: Z
 */

#ifndef RETARGET_H_
#define RETARGET_H_

#include "stm32f7xx_hal.h"
#include "sys/stat.h"
#include "sys/time.h"
#include "sys/times.h"
#include "_ansi.h"
#include "_syslist.h"
#include "stdio.h"
#include "stdint.h"
#include "errno.h"

void RetargetInit(UART_HandleTypeDef *huart);

int _isatty(int fd);

int _write(int fd, char *ptr, int len);

int _close(int fd);

int _lseek(int fd, int ptr, int dir);

int _read(int fd, char *ptr, int len);

int _fstat(int fd, struct stat *st);

#endif /* RETARGET_H_ */
