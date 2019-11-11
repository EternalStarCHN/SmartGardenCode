#ifndef __MYADC_H
#define __MYADC_H	 
#include "sys.h"
#include "delay.h"


extern uint32_t ADC_ConvertedValue;

void MYadc_Init(void);
float MYgetadc(uint8_t ADC_Channel);
u16 Get_Adc(u8 ch); 
void  Adc_Init(void);


#endif

