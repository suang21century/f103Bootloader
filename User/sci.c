 
#include "my.h"

//ÑÓÊ±º¯Êý
void delay_us(u32 time)  
{  
  u32 i=8*time;  
  while(i--);  
} 
void delay_ms(u32 time)  
{  
  u32 i=8000*time;  
  while(i--);  
}
 
uint16_t tet=0;

void UartSend(void)
{ 
	USART_SendData(USART3, 0x0055);
	delay_us(200);
	
  Uart.TxTemp= tet++;//(int16_t)(mpu_value.g_Roll*100);// mpu_value.Gyro[1];//
  Uart.TxData[0] = Uart.TxTemp>>8;
  Uart.TxData[1] = Uart.TxTemp;
  USART_SendData(USART3, Uart.TxData[0]); 
	delay_us(200);
  USART_SendData(USART3, Uart.TxData[1]);
	delay_us(200);
	
  Uart.TxTemp=  2;//mpu_value.Accel[0];//(int16_t)(roll*100);//(int16_t)Fil.p_Tyf;//
  Uart.TxData[0] = Uart.TxTemp>>8;
  Uart.TxData[1] = Uart.TxTemp;
  USART_SendData(USART3, Uart.TxData[0]); 
	delay_us(200);
  USART_SendData(USART3, Uart.TxData[1]);
	delay_us(200);
	
	Uart.TxTemp= 3;//(int16_t)(pitch*1); //mpu_value.Accel[1];//(int16_t)(mpu_value.g_Pitch*100);//mpu_value.Gyro[0];//
  Uart.TxData[0] = Uart.TxTemp>>8;
  Uart.TxData[1] = Uart.TxTemp;
  USART_SendData(USART3, Uart.TxData[0]); 
	delay_us(200);
  USART_SendData(USART3, Uart.TxData[1]);
	delay_us(200);
	
	Uart.TxTemp= 4;//(int16_t)(roll*100); //mpu_value.Accel[2];//(int16_t)Fil.p_Txf;//
  Uart.TxData[0] = Uart.TxTemp>>8;
  Uart.TxData[1] = Uart.TxTemp;
  USART_SendData(USART3, Uart.TxData[0]); 
//	delay_us(20);
//  USART_SendData(USART3, Uart.TxData[1]);
//	delay_us(20);
//	
//	USART_SendData(USART3, 0x00AA);
}
