/* CAN2_NodeB_Driver.c */
#include <LPC21XX.H>
#include "headerB.h"

void can2_init(void){
    PINSEL1|=0x00014000;   // CAN2 p0.24-->Tx, p0.23-->Rx
    VPBDIV=1;   //pclk=60MHz
    C2MOD=1;  //Select RESET mode
    AFMR=0x02;  //AccBP=1-->Accepting all incoming messages
    C2BTR=0x001C001D;  //Select 125kbps baudrate
    C2MOD=0;   //Cancel reset mode
}

#define TCS ((C2GSR>>3)&1)
void can2_tx(can2 v){
    C2TID1=v.id;
    C2TFI1=(v.dlc)<<16;
    if(v.rtr==0){
        C2TDA1=v.byteA;
        C2TDB1=v.byteB;
    }
    else
        C2TFI1|=(1<<30);
    C2CMR=0x21;
    while(TCS==0);
}

#define RBS (C2GSR&1)
void can2_rx(can2 *ptr){
    while(RBS==0);
    ptr->id=C2RID;
    ptr->dlc=((C2RFS>>16)&0x0f);
    ptr->rtr=((C2RFS>>30)&1);
    if(ptr->rtr==0){
        ptr->byteA=C2RDA;
        ptr->byteB=C2RDB;
    }
    C2CMR=(1<<2);
}
