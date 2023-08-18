/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : FMC.h
  * Description        : This file provides code for the configuration
  *                      of the FMC peripheral.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FMC_H
#define __FMC_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
 /* Exported types ------------------------------------------------------------*/
// typedef enum {PASSED = 0, FAILED = !PASSED} TestStatus_t;
 /* Exported constants --------------------------------------------------------*/
 #define SDRAM_BANK_ADDR                 ((uint32_t)0xC0000000)

 /* #define SDRAM_MEMORY_WIDTH            FMC_SDRAM_MEM_BUS_WIDTH_8  */
 #define SDRAM_MEMORY_WIDTH               FMC_SDRAM_MEM_BUS_WIDTH_16

 #define SDCLOCK_PERIOD                   FMC_SDRAM_CLOCK_PERIOD_2
 /* #define SDCLOCK_PERIOD                FMC_SDRAM_CLOCK_PERIOD_3 */

 #define SDRAM_TIMEOUT     ((uint32_t)0xFFFF)

 #define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
 #define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
 #define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
 #define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
 #define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
 #define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
 #define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
 #define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
 #define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
 #define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
 #define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)
/* USER CODE END Includes */

extern SDRAM_HandleTypeDef hsdram1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_FMC_Init(void);
void HAL_SDRAM_MspInit(SDRAM_HandleTypeDef* hsdram);
void HAL_SDRAM_MspDeInit(SDRAM_HandleTypeDef* hsdram);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__FMC_H */

/**
  * @}
  */

/**
  * @}
  */
