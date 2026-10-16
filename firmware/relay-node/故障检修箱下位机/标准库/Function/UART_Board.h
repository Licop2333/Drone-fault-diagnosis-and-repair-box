#ifndef _UART_BOARD_H
#define _UART_BOARD_H

extern void USART1_Init(void);
extern void USART2_Init(void);
//USART1
uint8_t USART1_ReceiveChar(void);
void USART1_ReceiveString(char *buffer, uint16_t maxLength);
uint8_t USART1_SendChar(uint8_t data);
uint8_t USART1_SendString(const char *str);
//USART2
uint8_t USART2_ReceiveChar(void);
void USART2_ReceiveString(char *buffer, uint16_t maxLength);
uint8_t USART2_SendChar(uint8_t data);
uint8_t USART2_SendString(const char *str);
extern void UnderBoard_WaitState(char* NumOfSub);
extern void UnderBoard_A_Init(void);

#endif
