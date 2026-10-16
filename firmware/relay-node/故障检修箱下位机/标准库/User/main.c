#include "stm32f10x.h"                  // Device header
#include "Delay.h"
//#include "OLED.h"
#include "UART_BOARD.h"
#include "stdio.h"
#include "string.h"
#include "TIMER.h"
#include "system.h"

int main(void)
{
	char Instruct[32];
	
	USART1_Init();
	Delay_ms(50);
	UnderBoard_Init();
	Delay_ms(50);
	
	while(1)
	{
		USART1_ReceiveString(Instruct, 16);
		if (strcmp(Instruct, "FFFF00000000EEEE") == 0)
		{
			Delay_ms(100);
			Reset_Instruct_C();
		}
//		Recognition_Instruct_A(Instruct);
		Recognition_Instruct_C(Instruct);
//		Recognition_Instruct_C(Instruct);
//		
//		Delay_ms(300);
//		memset(Instruct, 0, sizeof(Instruct));
	}

return 0;
}
