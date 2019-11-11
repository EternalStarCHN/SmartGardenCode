#ifndef MY_USART_H
#define MY_USART_H
/****************
	作者：debug406
	日期：2018-9-17
	
*****************/
#include "stm32f10x.h"
#include "stdio.h"

static void NVIC_Configuration(void);
void USART_Config(int Baud);

void Usart_SendByte(USART_TypeDef * pUSARTx, uint8_t ch);
void Usart_SendString(USART_TypeDef * pUSARTx,char *str);


#endif
