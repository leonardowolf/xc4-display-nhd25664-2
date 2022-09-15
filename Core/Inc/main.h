/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f3xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define KEYPAD_BL_Pin GPIO_PIN_1
#define KEYPAD_BL_GPIO_Port GPIOA
#define BATLV_Pin GPIO_PIN_2
#define BATLV_GPIO_Port GPIOA
#define SPI1_RES_Pin GPIO_PIN_3
#define SPI1_RES_GPIO_Port GPIOA
#define SPI1_CS_Pin GPIO_PIN_4
#define SPI1_CS_GPIO_Port GPIOA
#define SCK_Pin GPIO_PIN_5
#define SCK_GPIO_Port GPIOA
#define MOSI_Pin GPIO_PIN_7
#define MOSI_GPIO_Port GPIOA
#define LED_BC8_Pin GPIO_PIN_0
#define LED_BC8_GPIO_Port GPIOB
#define LED_BC7_Pin GPIO_PIN_1
#define LED_BC7_GPIO_Port GPIOB
#define LED_BC6_Pin GPIO_PIN_2
#define LED_BC6_GPIO_Port GPIOB
#define LED_BC5_Pin GPIO_PIN_10
#define LED_BC5_GPIO_Port GPIOB
#define LED_BC4_Pin GPIO_PIN_11
#define LED_BC4_GPIO_Port GPIOB
#define LED_BC3_Pin GPIO_PIN_12
#define LED_BC3_GPIO_Port GPIOB
#define LED_BC2_Pin GPIO_PIN_13
#define LED_BC2_GPIO_Port GPIOB
#define LED_BC1_Pin GPIO_PIN_14
#define LED_BC1_GPIO_Port GPIOB
#define EN_BATLV_Pin GPIO_PIN_15
#define EN_BATLV_GPIO_Port GPIOB
#define SPI1_DC_Pin GPIO_PIN_8
#define SPI1_DC_GPIO_Port GPIOA
#define KP_RT_Pin GPIO_PIN_15
#define KP_RT_GPIO_Port GPIOA
#define KP_RT_EXTI_IRQn EXTI15_10_IRQn
#define KP_DN_Pin GPIO_PIN_3
#define KP_DN_GPIO_Port GPIOB
#define KP_DN_EXTI_IRQn EXTI3_IRQn
#define KP_OK_Pin GPIO_PIN_4
#define KP_OK_GPIO_Port GPIOB
#define KP_OK_EXTI_IRQn EXTI4_IRQn
#define KP_CN_Pin GPIO_PIN_5
#define KP_CN_GPIO_Port GPIOB
#define KP_CN_EXTI_IRQn EXTI9_5_IRQn
#define KP_LF_Pin GPIO_PIN_6
#define KP_LF_GPIO_Port GPIOB
#define KP_LF_EXTI_IRQn EXTI9_5_IRQn
#define KP_UP_Pin GPIO_PIN_7
#define KP_UP_GPIO_Port GPIOB
#define KP_UP_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
