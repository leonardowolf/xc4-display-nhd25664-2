/*
 * keypad_IH.c
 *
 *  Created on: Apr 30, 2022
 *      Author: munin
 */

#include <com_monitor.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "keypad_IH.h"
#include "main.h"
#include "stm32f3xx_hal.h"
#include "cwlibx.h"
#include "usbd_cdc_if.h"

uint8_t txt[15];

//{set,reset,up,down,left,right}
key_ih IRQ_VECTOR[6];

extern TIM_HandleTypeDef htim4;

void Kpd_Irqv_Init(void) {
	//
	IRQ_VECTOR[0].IRQn_p = KP_OK_EXTI_IRQn;
	IRQ_VECTOR[0].deb_counter = 0;
	IRQ_VECTOR[0].disabled = false;
	//
	IRQ_VECTOR[1].IRQn_p = KP_CN_EXTI_IRQn;
	IRQ_VECTOR[1].deb_counter = 0;
	IRQ_VECTOR[1].disabled = false;
	//
	IRQ_VECTOR[2].IRQn_p = KP_UP_EXTI_IRQn;
	IRQ_VECTOR[2].deb_counter = 0;
	IRQ_VECTOR[2].disabled = false;
	//
	IRQ_VECTOR[3].IRQn_p = KP_DN_EXTI_IRQn;
	IRQ_VECTOR[3].deb_counter = 0;
	IRQ_VECTOR[3].disabled = false;
	//
	IRQ_VECTOR[4].IRQn_p = KP_LF_EXTI_IRQn;
	IRQ_VECTOR[4].deb_counter = 0;
	IRQ_VECTOR[4].disabled = false;
	//
	IRQ_VECTOR[5].IRQn_p = KP_RT_EXTI_IRQn;
	IRQ_VECTOR[5].deb_counter = 0;
	IRQ_VECTOR[5].disabled = false;
}
/*void SystickCallback(void) {*/

void HAL_SYSTICK_Callback(void)
{
	uint8_t i = 0;

	for (i = 0; i < 6; i++) {
		if(IRQ_VECTOR[i].disabled){
			if (IRQ_VECTOR[i].deb_counter == 0) {
				HAL_NVIC_ClearPendingIRQ(IRQ_VECTOR[i].IRQn_p);
				HAL_NVIC_EnableIRQ(IRQ_VECTOR[i].IRQn_p);
				IRQ_VECTOR[i].disabled = false;
			} else {
				IRQ_VECTOR[i].deb_counter--;
			}
			IRQ_VECTOR[i].deb_counter = IRQ_VECTOR[i].deb_counter > DEBOUNCE_TIME ? DEBOUNCE_TIME : IRQ_VECTOR[i].deb_counter;
		}
	}
//
//	if(++j > BAT_LOG_TIMER*1000){
//			battery_lvl_read();
//		j = 0;
//	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	bool post_it_state;
	if(GPIO_Pin == GPIO_PIN_15){
		post_it_state = HAL_GPIO_ReadPin(GPIOA,GPIO_Pin) == GPIO_PIN_RESET;
	}
	else{
		post_it_state = HAL_GPIO_ReadPin(GPIOB,GPIO_Pin) == GPIO_PIN_RESET;
	}
	if(post_it_state){
		if (GPIO_Pin == KP_OK_Pin) {
			//SET
            HAL_NVIC_DisableIRQ(IRQ_VECTOR[0].IRQn_p);
			HAL_NVIC_ClearPendingIRQ(IRQ_VECTOR[0].IRQn_p);
			IRQ_VECTOR[0].deb_counter = DEBOUNCE_TIME;
			IRQ_VECTOR[0].disabled = true;
			monitor_send_string("E");
	//		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

		}
		if (GPIO_Pin == KP_CN_Pin) {
			//RESET
			HAL_NVIC_DisableIRQ(IRQ_VECTOR[1].IRQn_p);
			HAL_NVIC_ClearPendingIRQ(IRQ_VECTOR[1].IRQn_p);
			IRQ_VECTOR[1].deb_counter = DEBOUNCE_TIME;
			IRQ_VECTOR[1].disabled = true;
			monitor_send_string("F");
	//		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

		}
		if (GPIO_Pin == KP_UP_Pin) {
			//UP
			HAL_NVIC_DisableIRQ(IRQ_VECTOR[2].IRQn_p);
			HAL_NVIC_ClearPendingIRQ(IRQ_VECTOR[2].IRQn_p);
			IRQ_VECTOR[2].deb_counter = DEBOUNCE_TIME;
			IRQ_VECTOR[2].disabled = true;
			monitor_send_string("A");
	//		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

		}
		if (GPIO_Pin == KP_DN_Pin) {
			//DOWN
			HAL_NVIC_DisableIRQ(IRQ_VECTOR[3].IRQn_p);
			HAL_NVIC_ClearPendingIRQ(IRQ_VECTOR[3].IRQn_p);
			IRQ_VECTOR[3].deb_counter = DEBOUNCE_TIME;
			IRQ_VECTOR[3].disabled = true;
			monitor_send_string("B");
	//		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

		}else if (GPIO_Pin == KP_LF_Pin) {
			//LEFT
			HAL_NVIC_DisableIRQ(IRQ_VECTOR[4].IRQn_p);
			HAL_NVIC_ClearPendingIRQ(IRQ_VECTOR[4].IRQn_p);
			IRQ_VECTOR[4].deb_counter = DEBOUNCE_TIME;
			IRQ_VECTOR[4].disabled = true;
			monitor_send_string("C");
	//		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

		}
		if (GPIO_Pin == KP_RT_Pin) {
			//RIGHT
			HAL_NVIC_DisableIRQ(IRQ_VECTOR[5].IRQn_p);
			HAL_NVIC_ClearPendingIRQ(IRQ_VECTOR[5].IRQn_p);
			IRQ_VECTOR[5].deb_counter = DEBOUNCE_TIME;
			IRQ_VECTOR[5].disabled = true;
			monitor_send_string("D");
	//		HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);

		}
	}

}
