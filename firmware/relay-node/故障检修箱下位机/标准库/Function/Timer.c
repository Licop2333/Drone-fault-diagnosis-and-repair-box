#include "stm32f10x.h"                  // Device header
#include "TIMER.h"

volatile uint32_t systick_counter = 0;

//// SysTick 中断服务例程
//void SysTick_Handler(void) {
//    systick_counter++;
//}

// 初始化 SysTick 定时器
void SysTick_Init(void) {
    if (SysTick_Config(SystemCoreClock / 1000)) {
        while (1);  // 配置失败时进入死循环
    }
}

// 重置 SysTick 计数器
void SysTick_Reset(void) {
    systick_counter = 0;
}

// 获取 SysTick 计数器值
uint32_t SysTick_Get(void) {
    return systick_counter;
}
