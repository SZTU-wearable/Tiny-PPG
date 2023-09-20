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
//#define SDRAM_BANK_ADDR     ((uint32_t)0xC0000000)//FMC SDRAM 数据基地址
#define SDRAM_BANK_ADDR2     ((uint32_t)0xC003FC00)//LTDC Layer2 数据基地址
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint8_t key_flag = 0, ai_flag = 1, ma_cnt = 0, ma_cnt_plot = 0;//开关标记、AI标记、伪影计数、伪影画图计数
uint16_t *pSDRAM = (uint16_t *)SDRAM_BANK_ADDR, *pSDRAM2 = (uint16_t *)SDRAM_BANK_ADDR2, n = 0, nn = 1728, ma_plot = 0xFFFF;//nn绘图计数延迟3秒,ma_plot为画图用值存颜色值
__IO uint16_t adc = 0;
uint32_t ppg_plot = 0, plot1 = 0, plot2 = 0;//ppg_plot为画图用值最新值。1：小值；2：大值
float ppg[1920] = {0}, ma[1920] = {0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);//GPIO中断回调函数
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);//定时器中断回调函数
//void SDRAM_Test(void);//SDRAM测试
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
//  SCB->CACR|=1<<2;//强制L1 Cache透写,如实际使用中遇到一致性问题可以开启
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  RetargetInit(&huart1);//串口收发
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
  HAL_ADC_Start_DMA(&hadc1, (uint32_t*)&adc, 1);//开启ADC的DMA传输
  memset(pSDRAM, 0xFF, 480 * 544 * 2);//显示全白画面
  HAL_TIM_Base_Start_IT(&htim6);//开启定时器中断
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
//	if((GPIO_Pin == B1_Pin))//判断是否是按键中断
//		{
//			HAL_GPIO_TogglePin(LCD_BL_GPIO_Port, LCD_BL_Pin);//背光控制
//			HAL_GPIO_TogglePin(LCD_DISP_GPIO_Port, LCD_DISP_Pin);//LCD控制
	key_flag ^= 1;

//		}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	SCB_InvalidateDCache_by_Addr((uint32_t*)&adc, 1);//无效化adc地址对应的Cache Line以正常读取内存的数值
	ppg[n] = adc;
	ppg[n] = (ppg[n] < 3846) ? ppg[n]/3846 : 1;//归一化，3846由传感器信号最大幅值决定
	if(key_flag == 0)
	{
		//伪影计数,若连续伪影少于16点则不显示为伪影
		plot1 = (nn > 1904) ? nn - 1905 : nn + 15;//计算nn后第15点
		printf("%f, %f,", ppg[plot1], ma[plot1]);
		printf("%f, %f, %d\r\n", ppg[nn], ma[nn], nn);//从串口输出绘图所用的原始数据以方便收集数据
		if(ma[plot1] > 0.6)
		{
			if(ma_cnt == 15)
				ma_cnt_plot = 16;
			else ma_cnt ++;
		}
		else ma_cnt = 0;
		if(ma_cnt_plot != 0)
		{
			ma_plot = 0x07E0;//伪影显示绿色
			ma_cnt_plot --;
		}
		else ma_plot = 0xFFFF;//伪影显示白色，即没有伪影

		//画图
		//存放旧值
		plot1 = ppg_plot;
		//获取新值，即ppg_plot = 130559-(uint16_t)(271*ppg)*480;
		ppg_plot = (271*ppg[nn]);//0~1>0~271(uint16_t)把归一化数值转换为LCD像素点y轴位置
		ppg_plot = 130559 + (ppg_plot << 5) - (ppg_plot << 9);//0~271>130559~0;把LCD像素点y轴位置转换为实际LCD像素点位置
		//ppg画图大小判断，方便插值绘图
		if(plot1 != ppg_plot)
		{
			plot2 = (plot1 > ppg_plot) ? plot1 - 480 : ppg_plot;//把大值放在2
			plot1 = (plot1 > ppg_plot) ? ppg_plot : plot1 + 480;//把小值放在1
		}else plot2 = ppg_plot;

		//LCD向左滚动
		HAL_DMA2D_Abort(&hdma2d);
		HAL_DMA2D_Start(&hdma2d, (uint32_t)&pSDRAM[1], (uint32_t)&pSDRAM[0], 480, 544);
		//最新一列
		for(uint32_t i = 479; i != 131039; i = i + 480)
		{
			pSDRAM[i] = (plot1 > i || i > plot2) ? 0xFFFF : 0;//Layer1
			pSDRAM2[i] = ma_plot;//Layer2
		}
	}
	ai_flag = (n & 31) ? 1 : 0;//每31个数，0.5秒，把ai_flag置为0，执行一次ai计算ai_flag
	n = (n == 1919) ? 0 : n + 1;
	nn = (nn == 1919) ? 0 : nn + 1;
}

//void SDRAM_Test(void)//SDRAM测试
//{
//  uint8_t ReadData = 0;   // 读取到的数据
//  CDC_Send((uint8_t*)"SDRAM测试\r\n");
//  pSDRAM[0] = 1;// 写入数据
//  CDC_Send((uint8_t*)"写入完毕，读取数据并比较...\r\n");
//  ReadData = pSDRAM[0];
//  if( ReadData != 1 )      //检测数据
//    {
//      CDC_Send((uint8_t*)"SDRAM测试失败！！\r\n");
//    }
//  else CDC_Send((uint8_t*)"SDRAM读写测试通过，系统正常\r\n");
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
