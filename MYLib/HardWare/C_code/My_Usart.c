#include "My_Usart.h"

/****************
	作者：debug406
	日期：2018-9-17
	
*****************/

/**
  * @brief  NVIC
  * @param  None
  * @retval None
  */
static void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&NVIC_InitStructure);
}

/**
  * @brief  Deinitializes the GPIOx peripheral registers to their default reset values.
  * @param  UARTx: where x can be (1-5) to select the GPIO peripheral.
  * @retval None
  */
void USART_Config(int Baud)
{
	GPIO_InitTypeDef GPIO_InStructure;
	USART_InitTypeDef USART_InStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);
	
	/*配置A9*/
	GPIO_InStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InStructure);
	
	/*配置A10*/
	GPIO_InStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA, &GPIO_InStructure);
	
	USART_InStructure.USART_BaudRate = Baud;
	USART_InStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;
	USART_InStructure.USART_Parity = USART_Parity_No;
	USART_InStructure.USART_StopBits = USART_StopBits_1;
	USART_InStructure.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART1,&USART_InStructure);
	NVIC_Configuration();
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1,ENABLE);
}

/**
  * @brief  Deinitializes the GPIOx peripheral registers to their default reset values.
  * @param  pUARTx: where x can be (1-5) to select the GPIO peripheral.
						ch: 
  * @retval None
  */
void Usart_SendByte(USART_TypeDef * pUSARTx, uint8_t ch)
{
	USART_SendData(pUSARTx,ch);
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TXE)==RESET){}
}

/**
  * @brief  Deinitializes the GPIOx peripheral registers to their default reset values.
  * @param  pUARTx: where x can be (1-5) to select the GPIO peripheral.
						ch: 
  * @retval None
  */

void Usart_SendString(USART_TypeDef * pUSARTx,char *str)
{
	unsigned int k = 0;
	do{
		Usart_SendByte(pUSARTx,*(str+k));
		k++;
	} while(*(str+k)!= '\0');
	while(USART_GetFlagStatus(pUSARTx,USART_FLAG_TC)==RESET){}
}

int fputc(int ch, FILE *f)
{
	USART_SendData(USART1,(uint8_t) ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	return (ch);
}

int fgetc(FILE *f)
{
	while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==RESET);
	
	return (int)USART_ReceiveData(USART1);
}
