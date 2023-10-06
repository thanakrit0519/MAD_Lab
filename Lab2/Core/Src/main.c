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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define D0 GPIOG
#define D0PIN GPIO_PIN_9
#define D1 GPIOG
#define D1PIN GPIO_PIN_14
#define D2 GPIOF
#define D2PIN GPIO_PIN_15
#define D3 GPIOE
#define D3PIN GPIO_PIN_13
#define D4 GPIOF
#define D4PIN GPIO_PIN_14
#define D5 GPIOE
#define D5PIN GPIO_PIN_11
#define D6 GPIOE
#define D6PIN GPIO_PIN_9
#define D7 GPIOF
#define D7PIN GPIO_PIN_13

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
	int nowLed = -1;
	int sw1 = 1;
	int lastsw1 = 1;
	int sw2 = 1;
	int lastsw2 = 1;
	int x=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

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

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//	  for(n=0;n<=2;n++){
//		  GPIOC -> BSRR = 0x07000000;
//		  HAL_Delay(500);
//		  GPIOC -> BSRR = 0x00000400 >> n;
//		  HAL_Delay(500);
//	  }
//	  GPIOC -> BSRR = 0x00000700;
//	  HAL_Delay(500);
//	  GPIOC -> BSRR = 0x07000000;
//	  HAL_Delay(500);
	  //Lab2_1
//	  if(HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_12) == 0){
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
//		  HAL_Delay(1000);
//		  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
//	  }

//	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == 0){
//	  		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 1);
//	  		  HAL_Delay(1000);
//	  		  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);
//	  	  }

	  sw1 = HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_12);
	  if(sw1 == 0 && lastsw1 == 1){
		  HAL_Delay(150);
		  nowLed++;
		  if(nowLed > 7){
			  nowLed = 0;
		  }
		  if(nowLed==0){
			  HAL_GPIO_WritePin(D7, D7PIN, 0);
			  HAL_GPIO_WritePin(D0, D0PIN, 1);
			  HAL_GPIO_WritePin(D1, D1PIN, 0);
		  }
		  else if(nowLed==1){
		  	HAL_GPIO_WritePin(D0, D0PIN, 0);
		  	HAL_GPIO_WritePin(D1, D1PIN, 1);
		  	HAL_GPIO_WritePin(D2, D2PIN, 0);
		  }
		  else if(nowLed==2){
		  		  	HAL_GPIO_WritePin(D1, D1PIN, 0);
		  		  	HAL_GPIO_WritePin(D2, D2PIN, 1);
		  		  HAL_GPIO_WritePin(D3, D3PIN, 0);
		  		  }
		  else if(nowLed==3){
		  		  	HAL_GPIO_WritePin(D2, D2PIN, 0);
		  		  	HAL_GPIO_WritePin(D3, D3PIN, 1);
		  		    HAL_GPIO_WritePin(D4, D4PIN, 0);
		  		  }
		  else if(nowLed==4){
		  		  	HAL_GPIO_WritePin(D3, D3PIN, 0);
		  		  	HAL_GPIO_WritePin(D4, D4PIN, 1);
		  		    HAL_GPIO_WritePin(D5, D5PIN, 0);
		  		  }
		  else if(nowLed==5){
		  		  	HAL_GPIO_WritePin(D4, D4PIN, 0);
		  		  	HAL_GPIO_WritePin(D5, D5PIN, 1);
		  		  HAL_GPIO_WritePin(D6, D6PIN, 0);
		  		  }
		  else if(nowLed==6){
		  		  	HAL_GPIO_WritePin(D5, D5PIN, 0);
		  		  	HAL_GPIO_WritePin(D6, D6PIN, 1);
		  		  HAL_GPIO_WritePin(D7, D7PIN, 0);
		  		  }
		  else if(nowLed==7){
		  		  	HAL_GPIO_WritePin(D6, D6PIN, 0);
		  		  	HAL_GPIO_WritePin(D7, D7PIN, 1);
		  		  HAL_GPIO_WritePin(D0, D0PIN, 0);
		  		  }
	  }
	  lastsw1=sw1;

	  sw2 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
	  if(sw2 == 0 && lastsw2 == 1){
		  HAL_Delay(150);
		  if(nowLed == -1){
			  x=1;
		  }
		  for (int i=0;i<8;i++){
			  nowLed--;
			  if(nowLed<0){
				  nowLed=7;
			  }

			  if(nowLed==0){
			  			  HAL_GPIO_WritePin(D7, D7PIN, 0);
			  			  HAL_GPIO_WritePin(D0, D0PIN, 1);
			  			  HAL_GPIO_WritePin(D1, D1PIN, 0);
			  		  }
			  		  else if(nowLed==1){
			  		  	HAL_GPIO_WritePin(D0, D0PIN, 0);
			  		  	HAL_GPIO_WritePin(D1, D1PIN, 1);
			  		  	HAL_GPIO_WritePin(D2, D2PIN, 0);
			  		  }
			  		  else if(nowLed==2){
			  		  		  	HAL_GPIO_WritePin(D1, D1PIN, 0);
			  		  		  	HAL_GPIO_WritePin(D2, D2PIN, 1);
			  		  		  HAL_GPIO_WritePin(D3, D3PIN, 0);
			  		  		  }
			  		  else if(nowLed==3){
			  		  		  	HAL_GPIO_WritePin(D2, D2PIN, 0);
			  		  		  	HAL_GPIO_WritePin(D3, D3PIN, 1);
			  		  		    HAL_GPIO_WritePin(D4, D4PIN, 0);
			  		  		  }
			  		  else if(nowLed==4){
			  		  		  	HAL_GPIO_WritePin(D3, D3PIN, 0);
			  		  		  	HAL_GPIO_WritePin(D4, D4PIN, 1);
			  		  		    HAL_GPIO_WritePin(D5, D5PIN, 0);
			  		  		  }
			  		  else if(nowLed==5){
			  		  		  	HAL_GPIO_WritePin(D4, D4PIN, 0);
			  		  		  	HAL_GPIO_WritePin(D5, D5PIN, 1);
			  		  		  HAL_GPIO_WritePin(D6, D6PIN, 0);
			  		  		  }
			  		  else if(nowLed==6){
			  		  		  	HAL_GPIO_WritePin(D5, D5PIN, 0);
			  		  		  	HAL_GPIO_WritePin(D6, D6PIN, 1);
			  		  		  HAL_GPIO_WritePin(D7, D7PIN, 0);
			  		  		  }
			  		  else if(nowLed==7){
			  		  		  	HAL_GPIO_WritePin(D6, D6PIN, 0);
			  		  		  	HAL_GPIO_WritePin(D7, D7PIN, 1);
			  		  		  HAL_GPIO_WritePin(D0, D0PIN, 0);
			  		  		  }
			  HAL_Delay(500);
		  }
		  if(x==1){
			  x=0;
		  		HAL_GPIO_WritePin(D0, D0PIN, 0);
		  		nowLed=-1;
		  }
	  }
	  lastsw2=sw2;


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOF, GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, GPIO_PIN_9|GPIO_PIN_11|GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9|GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pin : PA0 */
  GPIO_InitStruct.Pin = GPIO_PIN_0;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PF12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PF13 PF14 PF15 */
  GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pins : PE9 PE11 PE13 */
  GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_11|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PC8 PC9 PC10 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PG9 PG14 */
  GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_14;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

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
