#include "key.h"
#include "main.h"

void key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	
}

uint8_t ReadKey(void){
	if(!GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_1)){
		return 1;
	}
	return 0;
}

/*  按键消抖
		if(ReadKeyDown()== 1){
			delay_ms(5);
				if(ReadKeyDown()== 1){
						}
*/
