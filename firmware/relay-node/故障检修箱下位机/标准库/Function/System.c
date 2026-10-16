#include "stm32f10x.h"
#include <stdio.h>
#include <string.h>
#include "stdlib.h"

int Relay_ID;
int Relay_STATE;
char Relay_ID_S[16];
char Relay_STATE_S[8];

void UnderBoard_Init(void)
{
	//GPIOA
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure_A;
	GPIO_InitStructure_A.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure_A.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_15;
	GPIO_InitStructure_A.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure_A);
	
	//GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure_B;
	GPIO_InitStructure_B.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure_B.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure_B.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure_B);
	
	//GPIOC
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure_C;
	GPIO_InitStructure_C.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure_C.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	GPIO_InitStructure_C.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure_C);
}

void Recognition_Instruct_A(char Instruct[32])
{
	strncpy(Relay_ID_S, Instruct + 5, 3); //获取继电器编号
	strncpy(Relay_STATE_S, Instruct + 9, 1); //获取继电器状态
	Relay_ID = atoi(Relay_ID_S);
	Relay_STATE = atoi(Relay_STATE_S);

	//A
	if(Relay_ID == 4)  {GPIO_WriteBit(GPIOC, GPIO_Pin_14, Relay_STATE);}
	if(Relay_ID == 8)  {GPIO_WriteBit(GPIOA, GPIO_Pin_12, Relay_STATE);}//11
	if(Relay_ID == 12) {GPIO_WriteBit(GPIOC, GPIO_Pin_13, Relay_STATE);}//c13
	if(Relay_ID == 16) {GPIO_WriteBit(GPIOC, GPIO_Pin_15, Relay_STATE);}//c15
	if(Relay_ID == 33) {GPIO_WriteBit(GPIOA, GPIO_Pin_5, Relay_STATE);}//a05
	if(Relay_ID == 34) {GPIO_WriteBit(GPIOB, GPIO_Pin_14, Relay_STATE);}//b14
	if(Relay_ID == 35) {GPIO_WriteBit(GPIOA, GPIO_Pin_4, Relay_STATE);}//a04
	if(Relay_ID == 40) {GPIO_WriteBit(GPIOA, GPIO_Pin_0, Relay_STATE);}//a00
	if(Relay_ID == 41) {GPIO_WriteBit(GPIOA, GPIO_Pin_3, Relay_STATE);}//a03
	if(Relay_ID == 42) {GPIO_WriteBit(GPIOA, GPIO_Pin_1, Relay_STATE);}//a01
	if(Relay_ID == 43) {GPIO_WriteBit(GPIOA, GPIO_Pin_2, Relay_STATE);}//a02
	if(Relay_ID == 50) {GPIO_WriteBit(GPIOB, GPIO_Pin_13, Relay_STATE);}//b13
	if(Relay_ID == 53) {GPIO_WriteBit(GPIOB, GPIO_Pin_12, Relay_STATE);}//b12
}

void Reset_Instruct_A(void)
{
	GPIO_WriteBit(GPIOC, GPIO_Pin_14, 0);
	GPIO_WriteBit(GPIOA, GPIO_Pin_12, 0);//11
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, 0);//c13
	GPIO_WriteBit(GPIOC, GPIO_Pin_15, 0);//c15
	GPIO_WriteBit(GPIOA, GPIO_Pin_5, 0);//a05
	GPIO_WriteBit(GPIOB, GPIO_Pin_14, 0);//b14
	GPIO_WriteBit(GPIOA, GPIO_Pin_4, 0);//a04
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);//a00
	GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);//a03
	GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);//a01
	GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);//a02
	GPIO_WriteBit(GPIOB, GPIO_Pin_13, 0);//b13
	GPIO_WriteBit(GPIOB, GPIO_Pin_12, 0);//b12
}

void Recognition_Instruct_B(char Instruct[32])
{
	strncpy(Relay_ID_S, Instruct + 5, 3); //获取继电器编号
	strncpy(Relay_STATE_S, Instruct + 9, 1); //获取继电器状态
	Relay_ID = atoi(Relay_ID_S);
	Relay_STATE = atoi(Relay_STATE_S);
	
	//B
	if(Relay_ID == 1)  {GPIO_WriteBit(GPIOC, GPIO_Pin_15, Relay_STATE);}//c15
	if(Relay_ID == 2)  {GPIO_WriteBit(GPIOB, GPIO_Pin_10, Relay_STATE);}//b10
	if(Relay_ID == 3)  {GPIO_WriteBit(GPIOA, GPIO_Pin_1, Relay_STATE);}//a01
	if(Relay_ID == 5)  {GPIO_WriteBit(GPIOB, GPIO_Pin_14, Relay_STATE);}//b14
	if(Relay_ID == 6)  {GPIO_WriteBit(GPIOB, GPIO_Pin_13, Relay_STATE);}//b13
	if(Relay_ID == 7)  {GPIO_WriteBit(GPIOB, GPIO_Pin_12, Relay_STATE);}//b12
	if(Relay_ID == 9)  {GPIO_WriteBit(GPIOB, GPIO_Pin_1, Relay_STATE);}//b01
	if(Relay_ID == 10)  {GPIO_WriteBit(GPIOA, GPIO_Pin_2, Relay_STATE);}//a02
	if(Relay_ID == 11)  {GPIO_WriteBit(GPIOA, GPIO_Pin_0, Relay_STATE);}//a00
	if(Relay_ID == 13)  {GPIO_WriteBit(GPIOB, GPIO_Pin_7, Relay_STATE);}//b07
	if(Relay_ID == 14)  {GPIO_WriteBit(GPIOB, GPIO_Pin_8, Relay_STATE);}//b08
	if(Relay_ID == 15)  {GPIO_WriteBit(GPIOB, GPIO_Pin_6, Relay_STATE);}//b06
	if(Relay_ID == 17)  {GPIO_WriteBit(GPIOA, GPIO_Pin_3, Relay_STATE);}//a03
	if(Relay_ID == 19)  {GPIO_WriteBit(GPIOA, GPIO_Pin_4, Relay_STATE);}//a04
	if(Relay_ID == 21)  {GPIO_WriteBit(GPIOA, GPIO_Pin_6, Relay_STATE);}//a06
	if(Relay_ID == 23)  {GPIO_WriteBit(GPIOA, GPIO_Pin_7, Relay_STATE);}//a07
	if(Relay_ID == 25)  {GPIO_WriteBit(GPIOC, GPIO_Pin_13, Relay_STATE);}//c13
	if(Relay_ID == 26)  {GPIO_WriteBit(GPIOB, GPIO_Pin_15, Relay_STATE);}//b15
	if(Relay_ID == 27)  {GPIO_WriteBit(GPIOC, GPIO_Pin_14, Relay_STATE);}//c14
	if(Relay_ID == 29)  {GPIO_WriteBit(GPIOA, GPIO_Pin_5, Relay_STATE);}//a05
	if(Relay_ID == 30)  {GPIO_WriteBit(GPIOB, GPIO_Pin_5, Relay_STATE);}//b05
	if(Relay_ID == 31)  {GPIO_WriteBit(GPIOB, GPIO_Pin_0, Relay_STATE);}//b00
	if(Relay_ID == 39)  {GPIO_WriteBit(GPIOB, GPIO_Pin_11, Relay_STATE);}//b11
}

void Reset_Instruct_B(void)
{
	GPIO_WriteBit(GPIOC, GPIO_Pin_15, 0);//c15
	GPIO_WriteBit(GPIOB, GPIO_Pin_10, 0);//b10
	GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);//a01
	GPIO_WriteBit(GPIOB, GPIO_Pin_14, 0);//b14
	GPIO_WriteBit(GPIOB, GPIO_Pin_13, 0);//b13
	GPIO_WriteBit(GPIOB, GPIO_Pin_12, 0);//b12
	GPIO_WriteBit(GPIOB, GPIO_Pin_1, 0);//b01
  GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);//a02
  GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);//a00
  GPIO_WriteBit(GPIOB, GPIO_Pin_7, 0);//b07
  GPIO_WriteBit(GPIOB, GPIO_Pin_8, 0);//b08
  GPIO_WriteBit(GPIOB, GPIO_Pin_6, 0);//b06
  GPIO_WriteBit(GPIOA, GPIO_Pin_3, 0);//a03
  GPIO_WriteBit(GPIOA, GPIO_Pin_4, 0);//a04
  GPIO_WriteBit(GPIOA, GPIO_Pin_6, 0);//a06
  GPIO_WriteBit(GPIOA, GPIO_Pin_7, 0);//a07
  GPIO_WriteBit(GPIOC, GPIO_Pin_13, 0);//c13
  GPIO_WriteBit(GPIOB, GPIO_Pin_15, 0);//b15
  GPIO_WriteBit(GPIOC, GPIO_Pin_14, 0);//c14
  GPIO_WriteBit(GPIOA, GPIO_Pin_5, 0);//a05
  GPIO_WriteBit(GPIOB, GPIO_Pin_5, 0);//b05
  GPIO_WriteBit(GPIOB, GPIO_Pin_0, 0);//b00
  GPIO_WriteBit(GPIOB, GPIO_Pin_11, 0);//b11

}

void Recognition_Instruct_C(char Instruct[32])
{
	strncpy(Relay_ID_S, Instruct + 5, 3); //获取继电器编号
	strncpy(Relay_STATE_S, Instruct + 9, 1); //获取继电器状态
	Relay_ID = atoi(Relay_ID_S);
	Relay_STATE = atoi(Relay_STATE_S);
	
	//C
	if(Relay_ID == 18)  {GPIO_WriteBit(GPIOB, GPIO_Pin_8, Relay_STATE);}//b08
	if(Relay_ID == 22)  {GPIO_WriteBit(GPIOB, GPIO_Pin_6, Relay_STATE);}//b06
	if(Relay_ID == 36)  {GPIO_WriteBit(GPIOB, GPIO_Pin_12, Relay_STATE);}//b12
	if(Relay_ID == 37)  {GPIO_WriteBit(GPIOB, GPIO_Pin_11, Relay_STATE);}//b11
	if(Relay_ID == 38)  {GPIO_WriteBit(GPIOB, GPIO_Pin_7, Relay_STATE);}//b07
	if(Relay_ID == 44)  {GPIO_WriteBit(GPIOB, GPIO_Pin_14, Relay_STATE);}//b14
	if(Relay_ID == 45)  {GPIO_WriteBit(GPIOC, GPIO_Pin_14, Relay_STATE);}//c14
	if(Relay_ID == 46)  {GPIO_WriteBit(GPIOA, GPIO_Pin_0, Relay_STATE);}//a00
	if(Relay_ID == 47)  {GPIO_WriteBit(GPIOB, GPIO_Pin_13, Relay_STATE);}//b13
	if(Relay_ID == 48)  {GPIO_WriteBit(GPIOA, GPIO_Pin_2, Relay_STATE);}//a02
	if(Relay_ID == 49)  {GPIO_WriteBit(GPIOB, GPIO_Pin_1, Relay_STATE);}//b01
	if(Relay_ID == 51)  {GPIO_WriteBit(GPIOB, GPIO_Pin_10, Relay_STATE);}//b10
	if(Relay_ID == 52)  {GPIO_WriteBit(GPIOA, GPIO_Pin_1, Relay_STATE);}//a01
	if(Relay_ID == 54)  {GPIO_WriteBit(GPIOC, GPIO_Pin_13, Relay_STATE);}//c13
	if(Relay_ID == 55)  {GPIO_WriteBit(GPIOC, GPIO_Pin_15, Relay_STATE);}//c15
}

void Reset_Instruct_C(void)
{
	GPIO_WriteBit(GPIOB, GPIO_Pin_8, 0);//b08
	GPIO_WriteBit(GPIOB, GPIO_Pin_6, 0);//b06
	GPIO_WriteBit(GPIOB, GPIO_Pin_12, 0);//b12
	GPIO_WriteBit(GPIOB, GPIO_Pin_11, 0);//b11
	GPIO_WriteBit(GPIOB, GPIO_Pin_7, 0);//b07
	GPIO_WriteBit(GPIOB, GPIO_Pin_14, 0);//b14
	GPIO_WriteBit(GPIOC, GPIO_Pin_14, 0);//c14
	GPIO_WriteBit(GPIOA, GPIO_Pin_0, 0);//a00
	GPIO_WriteBit(GPIOB, GPIO_Pin_13, 0);//b13
	GPIO_WriteBit(GPIOA, GPIO_Pin_2, 0);//a02
	GPIO_WriteBit(GPIOB, GPIO_Pin_1, 0);//b01
	GPIO_WriteBit(GPIOB, GPIO_Pin_10, 0);//b10
	GPIO_WriteBit(GPIOA, GPIO_Pin_1, 0);//a01
	GPIO_WriteBit(GPIOC, GPIO_Pin_13, 0);//c13
	GPIO_WriteBit(GPIOC, GPIO_Pin_15, 0);//c15
}
