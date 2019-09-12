 
#include "math.h"
#include "stm32f10x.h" 


typedef struct
{ 
u16     TxFlag;       //发送使能
u16     TxType;       //发送类型，由接收的帧类型0的反馈指向决定
u16     TxData[2];    // 发送的两个数据字节
s16      TxTemp;       //待发送暂存
u16     TxTemp1;       //待发送暂存
u16     TxCnt;        // 已经发送的数据长度
u16     TxSum;        //已发送的数据的加和；
u16     TID;
}Uart_REG;
extern Uart_REG Uart;
