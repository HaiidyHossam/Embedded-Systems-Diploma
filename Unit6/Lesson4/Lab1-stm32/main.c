/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include <stdio.h>

//Registers Adresses
typedef  unsigned int uint32_t
//RCC
#define RCC_BASE 	0x40021000
#define RCC_APB2ENR		*(volatile uint32_t *)(RCC_BASE + 0x18)

//GPIOA
#define GPIO_BASE 	0x40010800
#define GPIO_CRH		*(volatile uint32_t *)(GPIO_BASE + 0x04)
#define GPIO_ODR		*(volatile uint32_t *)(GPIO_BASE + 0x0C)
#define GPIOA_CRL		*(volatile uint32_t *)(GPIO_BASE + 0x00)

//AFIO
#define AFIO_BASE 	0x40010000
#define AFIO_EXTICR1	*(volatile uint32_t *)(AFIO_BASE + 0x08)

//EXTI
#define EXTI_BASE 	0x40010400
#define EXTI_IMR		*(volatile uint32_t *)(EXTI_BASE + 0x00)
#define EXTI_RTSR		*(volatile uint32_t *)(EXTI_BASE + 0x08)
#define EXTI_PR			*(volatile uint32_t *)(EXTI_BASE + 0x14)

//NVIC
#define NVIC_EXTI0		 (*(volatile uint32_t *)(0xE000E100))

#define SET_BIT(REG,NO_PIN)		(REG |= (1<<NO_PIN))
#define TOGGLE_BIT(REG,NO_PIN)	(REG ^= (1<<NO_PIN))

void Clock_init()
{
	// Make GPIO Enable Clocks (by set pin2)
	SET_BIT(RCC_APB2ENR,2);
	// AFIORST: Alternate function I/O reset
	SET_BIT(RCC_APB2ENR,0);
}
void GPIOA_init()
{
	//ENABLE GPIOA as OUTPUT
	GPIO_CRH &= 0xff0fffff;
	GPIO_CRH |= 0x00200000;	

	//01: Floating input (reset state)
	SET_BIT(GPIOA_CRL,2);
}
int main(void)
{
	Clock_init();
	GPIOA_init();

	//Enable EXTI0 
	AFIO_EXTICR1 = 0x0;

	//Enable Interrupt mask register In EXTI0 >> Pin0 in PortA
	SET_BIT(EXTI_IMR,0);

	//Enable Rising trigger event 
	SET_BIT(EXTI_RTSR,0);

	//Enable NVIC Irq6 >> EXTI0
	SET_BIT(NVIC_EXTI0,6);

	while(1);
}

//EXT0 FOR PORTA Pin0
void EXTI0_IRQHandler()
{
	//Toggle LED in PORTA Pin13
	TOGGLE_BIT(GPIO_ODR,13);

	// Clear Pending Interrupt Request for Line 0
	SET_BIT(EXTI_PR,0);
}