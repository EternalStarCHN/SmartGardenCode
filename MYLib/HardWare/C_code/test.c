#include "test.h"
#include "main.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK miniSTM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	   

//初始化PD2为输出口.并使能这两个口的时钟		    
//LED IO初始化

void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);	 //使能PB,PE端口时钟
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;				 //LED0-->PD.2 端口配置
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
 GPIO_Init(GPIOD, &GPIO_InitStructure);					 //根据设定参数初始化GPIOD.2
}

void ctrl_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOB, ENABLE);	 //使能PB,PE端口时钟
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1;				 //LED0-->PD.2 端口配置
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 //根据设定参数初始化GPIOD.2
	PCout(0)=0;PCout(1)=0;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4
																	|GPIO_Pin_5
																	|GPIO_Pin_6;				 //LED0-->PD.2 端口配置
	GPIO_Init(GPIOB, &GPIO_InitStructure);			
	PBout(4)=0;PBout(5)=0;PBout(6)=0;
}



 

void ESP_RST(void)
{
		printf("AT+RST\r");
	printf("\n");
}
void ESP_TCP()
{
	printf("AT+CIPSTART=\"TCP\",\"192.168.43.168\",8088\r\n");
}
void ESP_Send(u16 longth)
{
	printf("AT+CIPSEND=%d\r",longth);
	//printf("AT+CIPSEND");
	printf("\r\n");
	delay_ms(1000);

}
void ESP8266_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	 //使能PB,PE端口时钟	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 //根据设定参数初始化GPIOD.2
	PAout(11) = 0;
	PAout(11) = 1;
	delay_ms(30);
	memset(temp,0,sizeof(temp));
	ESP_RST();
	delay_ms(1000);delay_ms(1000);delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	ESP_TCP();
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
	delay_ms(1000);
		if(temp[0]!='O'){
		PDout(2) = 1;
		ESP_TCP();
		delay_ms(1000);
		delay_ms(1000);
		delay_ms(1000);
		delay_ms(1000);
		PDout(2) = 0;
	}
	delay_ms(1000);
	delay_ms(1000);

	printf("AT+CIPMODE=1\r\n");
	delay_ms(500);
	delay_ms(500);
	printf("AT+CIPSEND\r\n");
	delay_ms(500);
	delay_ms(500);
	if(temp[0]=='>'){
			PDout(2) = 1;
		delay_ms(1000);
		delay_ms(1000);
		PDout(2) = 0;
		}
}
void ESP_Test(void){
	ESP_Send(10);
	printf("test_ESP1\n\r");
	printf("\n");
}

void ESP_Jason(float wV,uint16_t tmp,uint16_t wT,uint16_t hum,float dirH,float eng,float chong){
//	ESP_Send(89);
	printf("{\"wv\":\"%.2f\",\"tmp\":\"%02d.%d\",\"wT\":\"%02d\",\"hum\":\"%d\",\"dirH\":\"%.2f\",\"eng\":\"%.2f\",\"chong\":\"%.1f\"}\r\n",wV,(tmp/10),(tmp%10),(wT/10),(hum/10),dirH,eng,chong);	
}


void analys(const char* xx,uint8_t ch,uint8_t K)
{ 	
	while(okflag!=0)
	{
		if(okflag==1)
		{
			if(strcmp((const char*)temp,xx)==0){
				PBout(ch)=K;
				printf("ok\r\n");
			}
			else{
				printf("unkown com\r\n");
			}
		}

		if(okflag ==2)
		{
			printf("com too long\r\n");
		}
		delay_ms(5);
		okflag = 0;
		memset(temp,0,sizeof(temp));
	}
}

void analys1()
{ 	
	while(okflag!=0)
	{
		if(okflag==1)
		{
			if(strcmp((const char*)temp,"41\r\n")==0){
				PBout(4)=1;
				printf("ok\r\n");
			}
			else if(strcmp((const char*)temp,"40\r\n")==0){
				PBout(4)=0;
				printf("ok\r\n");
			}
			else if(strcmp((const char*)temp,"51\r\n")==0){
				PBout(5)=1;
				printf("ok\r\n");
			}
			else if(strcmp((const char*)temp,"50\r\n")==0){
				PBout(5)=0;
				printf("ok\r\n");
			}
			else if(strcmp((const char*)temp,"60\r\n")==0){
				PBout(6)=0;
				printf("ok\r\n");
			}
			else if(strcmp((const char*)temp,"61\r\n")==0){
				PBout(6)=1;
				printf("ok\r\n");
			}
			else{
				printf("unkown com\r\n");
			}
		}

		if(okflag ==2)
		{
			printf("com too long\r\n");
		}
		delay_ms(5);
		okflag = 0;
		memset(temp,0,sizeof(temp));
	}
}

