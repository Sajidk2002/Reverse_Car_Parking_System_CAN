/* main_nodeA.c */
#include <LPC21XX.H>
#include "headerA.h"

#define buzz (1<<21)
u8 flag=0;
u32 count1;
can2 v1, v2, r1;

int main(){
    IODIR0|=led|buzz;
    IOSET0=led;
    IOCLR0=buzz;
    PINSEL1|=1;
    can2_init();
    uart0_init(9600);
    en_eint();
    en_can2_interruptA();
    uart0_tx_string("WELCOME\r\n");

    v1.id=0x100;
    v2.id=0x200;
    v1.rtr=v2.rtr=1;
    v1.dlc=v2.dlc=4;

    while(1){
        if(count1==1){
            IOCLR0=led;
            count1=0;
            can2_tx(v1);
            uart0_tx_string("\r\nRemote frame 1 transmitted\r\n");
        }
        else if(count1==2){
            IOSET0=led;
            count1=0;
            can2_tx(v2);
            uart0_tx_string("\r\nRemote frame 2 transmitted\r\n");
        }

        if(flag==1){
            flag=0;
            if(r1.id==0x123){
                int distance;
                distance=r1.byteA;
                uart0_tx_string("\r\n Distance:");
                uart0_integer(distance);
                if(distance>300 && distance<=400){
                    IOSET0=buzz;
                    delay_sec(2);
                    IOCLR0=buzz;
                    delay_sec(2);
                }
                else if(distance>200 && distance<=300){
                    IOSET0=buzz;
                    delay_sec(1);
                    IOCLR0=buzz;
                    delay_sec(1);
                }
                else if(distance>100 && distance<=200){
                    IOSET0=buzz;
                    delay_ms(250);
                    IOCLR0=buzz;
                    delay_ms(250);
                }
                else if(distance>=50 && distance<=100){
                    IOSET0=buzz;
                    delay_ms(100);
                    IOCLR0=buzz;
                    delay_ms(100);
                }
                else if(distance<50){
                    IOSET0=buzz;
                    while(distance<50);
                    IOCLR0=buzz;
                }
            }
        }
    }
}
