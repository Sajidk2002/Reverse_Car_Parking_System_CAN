/* CAN2_interrupt_nodeA.c */
#include <LPC21XX.H>
#include "headerA.h"

extern can2 r1;
extern u8 flag;
void can2_rx_handlerA(void)__irq
{
    flag=1;
    r1.id=C2RID;
    r1.dlc=(C2RFS>>16)&0x0f;
    r1.rtr=(C2RFS>>30)&1;
    if(r1.rtr==0){
        r1.byteA=C2RDA;
        r1.byteB=C2RDB;
    }
    C2CMR=(1<<2);  //release receiver buffer
    VICVectAddr=0;
}

void en_can2_interruptA(void){
    VICIntSelect=0;
    VICVectCntl2=27|(1<<5);
    VICVectAddr2=(u32)can2_rx_handlerA;
    VICIntEnable|=(1<<27);
    C2IER=1;  //enable rx interrupt
}
