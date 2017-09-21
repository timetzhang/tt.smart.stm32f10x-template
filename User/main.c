#include "public.h"
#include "led.h"

int main()
{
	u8 i;
	LED_Config();
	while(1)
	{
		for(i=0; i<8; i++){
			GPIO_Write(GPIOC, (u16)~(0x01<<i));
			delay_ms(100);
		}
	}
}
