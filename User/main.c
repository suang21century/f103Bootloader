/***************************************************************/
//Funcation: MPU-9250 SPI device
//chip£ºstm32f103c8t6 
//development environment£ºkeil5.27
//edit time:2019Äê5ÔÂ8ÈÕ16:42:44
/***************************************************************/
 
#include "my.h"

Uart_REG Uart;                //uart data
 

extern void InitCpu(void);
extern void InitData(void);
extern void UartSend(void);
extern void delay_us(u32 time)  ;
extern void delay_ms(u32 time)  ;

void jmp(void)
{  
  void (*pfn)(void);  
  pfn = (void (*)(void))(0x08003000 | 0x1);  
  pfn(); 
}

u16 test=0;
u16 cnt=0;
u16 en=1;
int main()
{
	delay_us(50000);
	InitCpu(); 
	InitData();
	
	while(en)
	{
    delay_ms(50);
		GPIO_SetBits(GPIOC,GPIO_Pin_13); 
		delay_ms(50);
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	  if(cnt++>50)//5s
		{
      en=0;
		}
	}
	 __disable_irq(); 
	jmp();
}
