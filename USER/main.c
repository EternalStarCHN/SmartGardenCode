#include "main.h"

short temperature=0; 
uint16_t temperature1;  	    
uint16_t humidity;
float wV;
float eng;
float chong;
float dirH;
float bri;
int a;
	
 int main(void)
 {	
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();
	LED_Init();
	ctrl_Init();
	USART_Config(115200);
	DS18B20_Init();
	MYadc_Init();
	while(DS18B20_Init())	
	{
		printf("water_tmp Init err");
		break;
	}
	delay_ms(1000);	
	while(DHT22_Init())
	{
		printf("tmp&hum Init err");
		break;
	}
	ESP8266_Init();
	okflag = 0;
	memset(temp,0,sizeof(temp));
  while(1)
	{
		analys1();
		temperature=DS18B20_Get_Temp();	
		a=(int)(temperature);

		DHT22_Read_Data(&temperature1,&humidity); 

		bri = MYgetadc(ADC_Channel_5);
		delay_ms(10);
		
		eng = MYgetadc(ADC_Channel_3);
		delay_ms(10);

		chong = MYgetadc(ADC_Channel_2);
		delay_ms(10);

		wV = MYgetadc(ADC_Channel_1);
		delay_ms(10);
		
		dirH = MYgetadc(ADC_Channel_0);
		delay_ms(1000);
		delay_ms(1000);
		
		if(wV>2.2){
			PCout(1)=1;
		}
		else{
			PCout(1)=0;
		}

		if(bri>2.2){
			PCout(0)=1;		
		}
		else{
			PCout(0)=0;
		}
		
		delay_ms(1000);
		ESP_Jason(wV,temperature1,a,humidity,dirH,eng,chong);
	}
 }
