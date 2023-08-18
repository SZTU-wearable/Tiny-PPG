/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "crc.h"
#include "dma.h"
#include "dma2d.h"
#include "ltdc.h"
#include "tim.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"
#include "fmc.h"
#include "app_x-cube-ai.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "stdio.h"
#include "../../User/usbd_cdc.h"
#include "../../User/retarget.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define SDRAM_BANK_ADDR     ((uint32_t)0xC0000000)//FMC SDRAM ���ݻ���ַ
#define SDRAM_BANK_ADDR2     ((uint32_t)0xC003FC00)//LTDC Layer2 ���ݻ���ַ
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t key_flag = 0, ai_flag = 1, ma_cnt = 0, ma_cnt_plot = 0;//���ر�ǡ�AI��ǡ�αӰ������αӰ��ͼ����
uint16_t *pSDRAM = (uint16_t *)SDRAM_BANK_ADDR, *pSDRAM2 = (uint16_t *)SDRAM_BANK_ADDR2, n = 0, nn = 1728, ma_plot = 0xFFFF;//nn��ͼ�����ӳ�3��,ma_plotΪ��ͼ��ֵ����ɫֵ
__IO uint16_t adc = 0;
uint32_t ppg_plot = 0, plot1 = 0, plot2 = 0;//ppg_plotΪ��ͼ��ֵ����ֵ��1��Сֵ��2����ֵ
float ppg[1920] = {0}, ma[1920] = {0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);//GPIO�жϻص�����
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);//��ʱ���жϻص�����
//void SDRAM_Test(void);//SDRAM����
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
//  SCB->CACR|=1<<2;//ǿ��L1 Cache͸д,��ʵ��ʹ��������һ����������Կ���
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  RetargetInit(&huart1);//�����շ�
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_DMA2D_Init();
  MX_FMC_Init();
  MX_LTDC_Init();
  MX_CRC_Init();
  MX_ADC1_Init();
  MX_USB_DEVICE_Init();
  MX_USART1_UART_Init();
  MX_TIM6_Init();
  MX_X_CUBE_AI_Init();
  /* USER CODE BEGIN 2 */
  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adc, 1);//����ADC��DMA����
  memset(pSDRAM, 0xFF, 480 * 544 * 2);//��ʾȫ�׻���
  HAL_TIM_Base_Start_IT(&htim6);//������ʱ���ж�
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(ai_flag == 0)
	  {
    /* USER CODE END WHILE */

  MX_X_CUBE_AI_Process();
    /* USER CODE BEGIN 3 */
  	  	  ai_flag = 1;
	  }
	  HAL_Delay(1);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 432;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
//	if((GPIO_Pin == B1_Pin))//�ж��Ƿ��ǰ����ж�
//		{
//			HAL_GPIO_TogglePin(LCD_BL_GPIO_Port, LCD_BL_Pin);//�������
//			HAL_GPIO_TogglePin(LCD_DISP_GPIO_Port, LCD_DISP_Pin);//LCD����
	key_flag ^= 1;

//		}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	SCB_InvalidateDCache_by_Addr((uint32_t*)&adc, 1);//��Ч��adc��ַ��Ӧ��Cache Line��������ȡ�ڴ����ֵ
	ppg[n] = adc;
	ppg[n] = (ppg[n] < 3846) ? ppg[n]/3846 : 1;//��һ����3846�ɴ������ź�����ֵ����
	if(key_flag == 0)
	{
		//αӰ����,������αӰ����16������ʾΪαӰ
		plot1 = (nn > 1904) ? nn - 1905 : nn + 15;//����nn���15��
		printf("%f, %f,", ppg[plot1], ma[plot1]);
		printf("%f, %f, %d\r\n", ppg[nn], ma[nn], nn);//�Ӵ��������ͼ���õ�ԭʼ�����Է����ռ�����
		if(ma[plot1] > 0.6)
		{
			if(ma_cnt == 15)
				ma_cnt_plot = 16;
			else ma_cnt ++;
		}
		else ma_cnt = 0;
		if(ma_cnt_plot != 0)
		{
			ma_plot = 0x07E0;//αӰ��ʾ��ɫ
			ma_cnt_plot --;
		}
		else ma_plot = 0xFFFF;//αӰ��ʾ��ɫ����û��αӰ

		//��ͼ
		//��ž�ֵ
		plot1 = ppg_plot;
		//��ȡ��ֵ����ppg_plot = 130559-(uint16_t)(271*ppg)*480;
		ppg_plot = (271*ppg[nn]);//0~1>0~271(uint16_t)�ѹ�һ����ֵת��ΪLCD���ص�y��λ��
		ppg_plot = 130559 + (ppg_plot << 5) - (ppg_plot << 9);//0~271>130559~0;��LCD���ص�y��λ��ת��Ϊʵ��LCD���ص�λ��
		//ppg��ͼ��С�жϣ������ֵ��ͼ
		if(plot1 != ppg_plot)
		{
			plot2 = (plot1 > ppg_plot) ? plot1 - 480 : ppg_plot;//�Ѵ�ֵ����2
			plot1 = (plot1 > ppg_plot) ? ppg_plot : plot1 + 480;//��Сֵ����1
		}else plot2 = ppg_plot;

		//LCD�������
		HAL_DMA2D_Abort(&hdma2d);
		HAL_DMA2D_Start(&hdma2d, (uint32_t)&pSDRAM[1], (uint32_t)&pSDRAM[0], 480, 544);
		//����һ��
		for(uint32_t i = 479; i != 131039; i = i + 480)
		{
			pSDRAM[i] = (plot1 > i || i > plot2) ? 0xFFFF : 0;//Layer1
			pSDRAM2[i] = ma_plot;//Layer2
		}
	}
	ai_flag = (n & 31) ? 1 : 0;//ÿ31������0.5�룬��ai_flag��Ϊ0��ִ��һ��ai����ai_flag
	n = (n == 1919) ? 0 : n + 1;
	nn = (nn == 1919) ? 0 : nn + 1;
}

//void SDRAM_Test(void)//SDRAM����
//{
//  uint8_t ReadData = 0;   // ��ȡ��������
//  CDC_Send((uint8_t*)"SDRAM����\r\n");
//  pSDRAM[0] = 1;// д������
//  CDC_Send((uint8_t*)"д����ϣ���ȡ���ݲ��Ƚ�...\r\n");
//  ReadData = pSDRAM[0];
//  if( ReadData != 1 )      //�������
//    {
//      CDC_Send((uint8_t*)"SDRAM����ʧ�ܣ���\r\n");
//    }
//  else CDC_Send((uint8_t*)"SDRAM��д����ͨ����ϵͳ����\r\n");
//}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)



{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
	  HAL_GPIO_TogglePin(LD1_GPIO_Port, LD1_Pin);
	  for(uint32_t Delay = 2097152; Delay; Delay--);
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
