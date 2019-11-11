#ifndef __TEST_H
#define __TEST_H	 
#include "sys.h"
#include "My_Usart.h"
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//LED驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/2
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define LED1 PDout(2)	// PD2
#define ESP_EN PAout(11) 

extern uint8_t temp[255];
extern uint8_t okflag;


void LED_Init(void);//初始化
void ctrl_Init(void);
void ESP8266_Init(void);
void ESP_CWMODEset(void);
void ESP_RST(void);
void ESP_TCP(void);
void ESP_Send(u16 longth);
void ESP_Test(void);
void ESP_Jason(float wV,uint16_t tmp,uint16_t wT,uint16_t hum,float dirH,float eng,float chong);
void analys(const char* xx,uint8_t ch,uint8_t K);
void analys1();

#endif

