#ifndef __DHT22_H
#define __DHT22_H 
#include "sys.h"   
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK战舰STM32开发板
//DHT22数字温湿度传感器驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/9/12
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////
 
//IO方向设置
#define DHT22_IO_IN()  {GPIOC->CRL&=0XFFFF0FFF;GPIOC->CRL|=8<<12;}
#define DHT22_IO_OUT() {GPIOC->CRL&=0XFFFF0FFF;GPIOC->CRL|=3<<12;}
////IO操作函数											   
#define	DHT22_DQ_OUT PCout(3) //数据端口	PC3 
#define	DHT22_DQ_IN  PCin(3)  //数据端口	PC3 


uint8_t DHT22_Init(void);//初始化DHT22
uint8_t DHT22_Read_Data(u16 *temp,u16 *humi);//读取温湿度
uint8_t DHT22_Read_Byte(void);//读出一个字节
uint8_t DHT22_Read_Bit(void);//读出一个位
uint8_t DHT22_Check(void);//检测是否存在DHT22
void DHT22_Rst(void);//复位DHT22    
#endif















