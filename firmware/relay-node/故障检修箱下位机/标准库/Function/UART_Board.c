#include "stm32f10x.h"
#include <stdio.h>
#include <string.h>
#include "OLED.h"
#include "stdlib.h"
#include "UART_BOARD.h"
#include "Delay.h"
#include "TIMER.h"

// 初始化USART1
void USART1_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    // 使能GPIOA和USART1的时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1, ENABLE);

    // 配置USART1的TX（PA9）为复用推挽输出
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 配置USART1的RX（PA10）为浮空输入
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 配置USART1
    USART_InitStructure.USART_BaudRate = 9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);

    // 使能USART1
    USART_Cmd(USART1, ENABLE);
}

// 初始化USART2
void USART2_Init(void) {
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    // 使能GPIOA和USART2的时钟
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    // 配置USART2的TX（PA2）为复用推挽输出
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 配置USART2的RX（PA3）为浮空输入
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    // 配置USART2
    USART_InitStructure.USART_BaudRate = 9600;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART2, &USART_InitStructure);

    // 使能USART2
    USART_Cmd(USART2, ENABLE);
}

// UART1 接收一个字符，带超时机制
uint8_t USART1_ReceiveChar(void) {
    SysTick_Reset();  // 重置 SysTick 计数器
    while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET) {
        if (SysTick_Get() >= 20) {
            return 0;  // 超时返回 0
        }
    }
    return USART_ReceiveData(USART1);
}

// UART1 接收一个字符串
void USART1_ReceiveString(char *buffer, uint16_t maxLength) {
    uint16_t i = 0;
    char ch;
    do {
        ch = USART1_ReceiveChar();
        if (ch == 0) {
            break;  // 如果接收到 0，表示超时，停止接收
        }
        buffer[i++] = ch;
    } while (ch != '\0' && i < maxLength);
    buffer[i] = '\0';  // 确保字符串以空字符结尾
}

// UART1 发送一个字符，带超时机制
uint8_t USART1_SendChar(uint8_t data) {
    SysTick_Reset();  // 重置 SysTick 计数器
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET) {
        if (SysTick_Get() >= 20) {
            return 0;  // 超时返回 0
        }
    }
    USART_SendData(USART1, data);
    return 1;  // 发送成功返回 1
}

// UART2 发送一个字符串
uint8_t USART1_SendString(const char *str){
    while (*str) {
        if (USART1_SendChar(*str) == 0) {
            break;  // 如果发送超时，停止发送
        }
        str++;
    }
}

// UART2 接收一个字符，带超时机制
uint8_t USART2_ReceiveChar(void) {
    SysTick_Reset();  // 重置 SysTick 计数器
    while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET) {
        if (SysTick_Get() >= 20) {
            return 0;  // 超时返回 0
        }
    }
    return USART_ReceiveData(USART1);
}

// UART2 接收一个字符串
void USART2_ReceiveString(char *buffer, uint16_t maxLength) {
    uint16_t i = 0;
    char ch;
    do {
        ch = USART1_ReceiveChar();
        if (ch == 0) {
            break;  // 如果接收到 0，表示超时，停止接收
        }
        buffer[i++] = ch;
    } while (ch != '\0' && i < maxLength);
    buffer[i] = '\0';  // 确保字符串以空字符结尾
}

// UART2 发送一个字符，带超时机制
uint8_t USART2_SendChar(uint8_t data) {
    SysTick_Reset();  // 重置 SysTick 计数器
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET) {
        if (SysTick_Get() >= 20) {
            return 0;  // 超时返回 0
        }
    }
    USART_SendData(USART1, data);
    return 1;  // 发送成功返回 1
}

// UART2 发送一个字符串
uint8_t USART2_SendString(const char *str){
    while (*str) {
        if (USART1_SendChar(*str) == 0) {
            break;  // 如果发送超时，停止发送
        }
        str++;
    }
}
