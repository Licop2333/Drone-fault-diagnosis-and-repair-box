#ifndef __TIMER_H
#define __TIMER_H

#define TIMEOUT_MS 100
void SysTick_Handler(void);
void SysTick_Init(void);
void SysTick_Reset(void);
uint32_t SysTick_Get(void);

#endif
