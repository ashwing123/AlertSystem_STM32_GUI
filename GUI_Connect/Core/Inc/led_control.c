/*
 * LED_Control.c
 *
 *  Created on: Jul 12, 2022
 *      Author: gopala4
 */

//includes
#include "LED_Control.h"
#include "main.h"

#define PERIOD 10000
#define PERIOD_ms 1
#define RED_LED_CHANNEL TIM_CHANNEL_1
#define GREEN_LED_CHANNEL TIM_CHANNEL_1
#define BLUE_LED_CHANNEL TIM_CHANNEL_3

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim3;

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 16-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 10000;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.BreakFilter = 0;
  sBreakDeadTimeConfig.BreakAFMode = TIM_BREAK_AFMODE_INPUT;
  sBreakDeadTimeConfig.Break2State = TIM_BREAK2_DISABLE;
  sBreakDeadTimeConfig.Break2Polarity = TIM_BREAK2POLARITY_HIGH;
  sBreakDeadTimeConfig.Break2Filter = 0;
  sBreakDeadTimeConfig.Break2AFMode = TIM_BREAK_AFMODE_INPUT;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 16-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 10000;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 16-1;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 10000;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

}

/*
 * function name: LED_Init
 * purpose: initialize timer corresponding to colored piezo on STM32U5 Board
 */
void LED_Init(char color) {
    switch (color)
    {
        case 'r':
            MX_TIM1_Init();
            HAL_TIM_Base_Start(&htim1);
            HAL_TIM_PWM_Start(&htim1, RED_LED_CHANNEL);
            break;
        case 'g':
            MX_TIM4_Init();
            HAL_TIM_Base_Start(&htim4);
            HAL_TIM_PWM_Start(&htim4, GREEN_LED_CHANNEL);
            break;
        case 'b':
            MX_TIM3_Init();
            HAL_TIM_Base_Start(&htim3);
            HAL_TIM_PWM_Start(&htim3, BLUE_LED_CHANNEL);
            break;
        default:
            break;
    }
}
/*
 * function name: off_LED
 * purpose: turns the LED with specified color off by setting the duty cycle equivalent to 0
 */
void off_LED(char color) {
    TIM_HandleTypeDef htim;
    uint32_t Channel;
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }
    __HAL_TIM_SET_COMPARE(&htim, Channel, 0);
}

void pause_LED(char color, int duration) {
  TIM_HandleTypeDef htim;
    uint32_t Channel;
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }
    __HAL_TIM_SET_COMPARE(&htim, Channel, 0);
    HAL_Delay(duration);

}

/*
 * function name: breathe_LED_up
 * purpose: emulates a "breathing in" LED by increasing the duty cycle progressively
 * params: color of LED, duration of single breaths (resolution = every 100ms) and the number of breaths
 */
void breathe_LED_up(char color, int breath_duration_ms, int num_repeats) {
    TIM_HandleTypeDef htim;
    uint32_t Channel;
    uint32_t delay_amount = breath_duration_ms / (PERIOD/100);
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }

	for (int j = 0; j < num_repeats; j++) {
		int i = 0;
		while (i < PERIOD/50) {
			__HAL_TIM_SET_COMPARE(&htim, Channel, i);
			HAL_Delay(delay_amount);
			i = i + 2;
		}
	}
	off_LED(color);
}
/*
 * function name: breathe_LED_down
 * purpose: emulates a "breathing out" LED by decreasing the duty cycle progressively
 * params: color of LED, duration of single breaths (resolution = every 100ms) and the number of breaths
 */
void breathe_LED_down(char color, int breath_duration_ms, int num_repeats) {
    TIM_HandleTypeDef htim;
    uint32_t Channel;
    uint32_t delay_amount = breath_duration_ms / (PERIOD/100);
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }
	for (int j = 0; j < num_repeats; j++) {
		int i = PERIOD/50;
		while (i > 0) {
			__HAL_TIM_SET_COMPARE(&htim, Channel, i);
			HAL_Delay(delay_amount);
			i = i - 2;
		}
	}
}

/*
 * function name: breathe_LED_up_and_down
 * purpose: emulates a "breathing in and out" LED by increasing then decreasing duty cycle
 * params: color of LED, duration of single breaths (resolution = every 100ms) and the number of breaths
 */
void breathe_LED_up_and_down(char color, int breath_duration_ms, int num_repeats) {
    TIM_HandleTypeDef htim;
    uint32_t Channel;
    uint32_t delay_amount = breath_duration_ms / (PERIOD/100);
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }
	for (int j = 0; j < num_repeats; j++) {
		int i = 0;
		while (i < PERIOD/100) {
			__HAL_TIM_SET_COMPARE(&htim, Channel, i);
			HAL_Delay(delay_amount);
			i = i + 2;
		}
		while (i > 0) {
			__HAL_TIM_SET_COMPARE(&htim, Channel, i);
			HAL_Delay(delay_amount);
			i = i - 2;
		}
	}
}

/*
 * function name: blink_LED
 * purpose: flashes LED
 * params: color of LED, number of blinks and duration of flash
 */
void blink_LED(char color, int flash_duration, int num_blinks) {
    TIM_HandleTypeDef htim;
    uint32_t Channel;
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }
	for (int i = 0; i < num_blinks; i++) {
		__HAL_TIM_SET_COMPARE(&htim, Channel, PERIOD/2);
		HAL_Delay(flash_duration);
		__HAL_TIM_SET_COMPARE(&htim, Channel, 0);
		HAL_Delay(flash_duration);
	}
}
/*
 * function name: solid_LED
 * purpose: keeps LED on for specified duration, then turns off
 * params: color of LED duration of solid LED
 */
void solid_LED(char color, int duration) {
    TIM_HandleTypeDef htim;
    uint32_t Channel;
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }
	__HAL_TIM_SET_COMPARE(&htim, Channel, PERIOD/2);
	HAL_Delay(duration);
	off_LED(color);
}

void pair_LED(int blink_arr[], int blinks_per_second, int len_code) {
  int len_blink = 1000/blinks_per_second;
  for (int i = 0; i < len_code; i++){
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, 1 - blink_arr[i]);
    HAL_Delay(len_blink*9/10);
    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin,  1);
    HAL_Delay(len_blink*1/10);
  }
}

void synced_breathe_up(char color, int breath_duration_ms, float start_duty, float end_duty) {
  TIM_HandleTypeDef htim;
    uint32_t Channel;
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }
  int start_pulse = (int) (start_duty*PERIOD);
  int end_pulse = (int) (end_duty*PERIOD);
  int increment = (end_pulse - start_pulse) / (breath_duration_ms/2);
  for (int i = start_pulse; i < end_pulse; i+= increment) {
    __HAL_TIM_SET_COMPARE(&htim, Channel, i);
    HAL_Delay(1);
  }
}

void synced_breathe_up_off(char color, int breath_duration_ms, float start_duty, float end_duty) {
  synced_breathe_up(color, breath_duration_ms, start_duty, end_duty);
  off_LED(color);
}

void synced_breathe_down(char color, int breath_duration_ms, float start_duty, float end_duty) {
  TIM_HandleTypeDef htim;
    uint32_t Channel;
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }
  int start_pulse = (int) (start_duty*PERIOD);
  int end_pulse = (int) (end_duty*PERIOD);
  int stepsize = (start_pulse - end_pulse) / (breath_duration_ms/2);
  for (int i = start_pulse; i > end_pulse; i -= stepsize) {
    __HAL_TIM_SET_COMPARE(&htim, Channel, i);
    HAL_Delay(1);
  }
}

void synced_breathe_down_off(char color, int breath_duration_ms, float start_duty, float end_duty) {
  synced_breathe_down(color, breath_duration_ms, start_duty, end_duty);
  off_LED(color);
}

void on_LED(char color) {
    TIM_HandleTypeDef htim;
    uint32_t Channel;
    switch (color)
    {
        case 'r':
            htim = htim1;
            Channel = RED_LED_CHANNEL;
            break;
        case 'g':
            htim = htim4;
            Channel = GREEN_LED_CHANNEL;
            break;
        case 'b':
            htim = htim3;
            Channel = BLUE_LED_CHANNEL;
            break;
    }
	__HAL_TIM_SET_COMPARE(&htim, Channel, PERIOD/2);
}