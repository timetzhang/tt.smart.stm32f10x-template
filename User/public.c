#include "public.h"
#include "stm32f10x.h"

void delay_us(u32 time)
{
	u32 temp;
	SysTick->LOAD=9*time;
	SysTick->CTRL=0X01;
	SysTick->VAL=0;
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&(!(temp&(1<<16))));
	SysTick->CTRL=0;
	SysTick->VAL=0;
}

void delay_ms(u32 time)
{
	u32 temp;
	SysTick->LOAD=9000*time;
	SysTick->CTRL=0X01;
	SysTick->VAL=0;
	do
	{
		temp=SysTick->CTRL;
	}
	while((temp&0x01)&&(!(temp&(1<<16))));
	SysTick->CTRL=0;
	SysTick->VAL=0;
}

