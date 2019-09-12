
/*************************************
//CPU�����ã�����ģ�飬
//
**************************************/
 
#include "my.h"

TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
TIM_OCInitTypeDef   TIM_OCInitStructure;
TIM_BDTRInitTypeDef TIM_BDTRInitStructure;
NVIC_InitTypeDef    NVIC_InitStructure;  
ADC_InitTypeDef     ADC_InitStructure;
GPIO_InitTypeDef    GPIO_InitStructure;
DMA_InitTypeDef     DMA_InitStructure;
TIM_ICInitTypeDef TIM_ICInitStructure; 
SPI_InitTypeDef  SPI_InitStructure;  
USART_InitTypeDef USART_InitStructure;  
EXTI_InitTypeDef EXTI_InitStructure; //�����ʼ���ṹ��

#define ADC1_DR_Address    ((uint32_t)0x4001244C)

void Cpu_Confi(void)
{

//����ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
/*************************************
//GPIO����
**************************************/
	//LED -> PC13
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;                           //ѡ����Ƶ�����
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;                    //��������
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;                     //ͨ�����ģʽ
  GPIO_Init(GPIOC, &GPIO_InitStructure);                               //��ʼ��GPIOC
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);                                  //��ʼ״̬Ϊ��
	  
	//uart3 PB10��11
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;  //Tx
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  
  GPIO_Init(GPIOB, &GPIO_InitStructure);  
  
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11; //USART3 Rx
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
  GPIO_Init(GPIOB, &GPIO_InitStructure);  

	/*************************************
//UART3���� 
**************************************/
	USART_InitStructure.USART_BaudRate = 115200;  
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;  
  USART_InitStructure.USART_StopBits = USART_StopBits_1;  
  USART_InitStructure.USART_Parity = USART_Parity_No ;  
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;  
   
  USART_Init(USART3, &USART_InitStructure);   
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
  USART_Cmd(USART3, ENABLE);
/*************************************
//�ж�����
**************************************/

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//�ж���0����Ϊ�����ȼ�
	 
	//���ڽ����ж�
  NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);  
		
}
void InitCpu(void)
{
	SystemInit();          //ϵͳʱ�ӳ�ʼ����Ĭ���ⲿ����8MHz��9��Ƶ��72MHz
	Cpu_Confi();    //gpio��ʼ��
}
