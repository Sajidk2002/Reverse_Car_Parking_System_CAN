/* can2_receiver_interrupt_nodeB.c */
#include <LPC21XX.H>
#include "headerB.h"

extern can2 r1;
extern u32 flag, flag1, flag2;
void can2_rx_handlerB(void)__irq
{
    flag=1;
    r1.id=C2RID;
    r1.dlc=(C2RFS>>16)&0x0f;
    r1.rtr=(C2RFS>>30)&1;
    C2CMR=(1<<2);
    VICVectAddr=0;
}

void en_can2_interruptB(void){
    VICVectAddr4=(u32)can2_rx_handlerB;
    VICVectCntl4=27|(1<<5);
    VICIntEnable=(1<<27);
    C2IER=1;  //Enable CAN2 RX interrupt
}
