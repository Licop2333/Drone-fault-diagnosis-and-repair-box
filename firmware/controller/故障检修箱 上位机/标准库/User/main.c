#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "UART_BOARD.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "TIMER.h"

int main(void)
{
	USART1_Init();
	USART2_Init();
	SysTick_Init();
	UnderBoard_A_Init();
	//配置定时器
	SysTick_Config(SystemCoreClock / 1000);

	char NumOfSub[100];
	char StateOfSub[100];	
	char For_i;

	//GPIO_WriteBit(GPIOC, GPIO_Pin_13, Bit_SET);

	while(1)
	{
		USART2_ReceiveString(StateOfSub, 3);
		if(strcmp(StateOfSub, "GET") != 0){
			for(For_i=0; For_i<5; For_i++)
			{
				USART1_SendString("011");
				Delay_ms(10);
			}
		}
	}

return 0;
}
