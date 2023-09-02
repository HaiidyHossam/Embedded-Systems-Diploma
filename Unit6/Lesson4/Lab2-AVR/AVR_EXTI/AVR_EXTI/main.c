/*
 * AVR_EXTI.c
 *
 * Created: 9/2/2023 1:38:57 AM
 * Author : Haiidy Hossam
 */ #define F_CPU 8000000
#include <util/delay.h>
#include "STDTYPE.h"


#define PORTD *((volatile u8 *) 0x32)
#define DDRD *((volatile u8 *) 0x31)
#define GICR  *((volatile u8*)0x5B) //bi6 enable

#define MCUCR *((volatile u8 *)0x55) //sense control set 2 bits
#define SREG *((volatile u8 *)0x5F)
#define SREG_I_BIT 7
void funct(){
	PORTD |=1<<5;
	_delay_ms(1000);
	PORTD &=~(1<<5);

	}
int main(void)
{
	DDRD |=1<<5; //set as output
	DDRD &=~(1<<2);
	PORTD |=1<<2;
	SREG |=1<<7;
	GICR |=1<<6;

	MCUCR |=1<<0;
	MCUCR |=1<<1;
	Func_PTR(funct);
    /* Replace with your application code */
    while (1) 
    {
    }
}
void (*ptr) (void)=0;
void Func_PTR (void (*ptr1) (void)){
	if (ptr1!=0){
		ptr=ptr1;
	}
}
void __vector_1 (void)__attribute__ ((signal));

void __vector_1 (void){
	ptr();
	MCUCR ^=1<<0;
	MCUCR |=1<<1;
	
}