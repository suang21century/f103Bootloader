 
#include "math.h"
#include "stm32f10x.h" 


typedef struct
{ 
u16     TxFlag;       //����ʹ��
u16     TxType;       //�������ͣ��ɽ��յ�֡����0�ķ���ָ�����
u16     TxData[2];    // ���͵����������ֽ�
s16      TxTemp;       //�������ݴ�
u16     TxTemp1;       //�������ݴ�
u16     TxCnt;        // �Ѿ����͵����ݳ���
u16     TxSum;        //�ѷ��͵����ݵļӺͣ�
u16     TID;
}Uart_REG;
extern Uart_REG Uart;
