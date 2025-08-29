/* ultrasonic.c */
#include <LPC21XX.H>
#include "headerB.h"
#define trig (1<<2)     //p0.2 --> trigger pin
#define echo ((IOPIN0>>3)&1)  //p0.3 --> echo pin

void ultra_init(void){
    IODIR0|=trig;
    T1PR=59;  //prescaler for ~1us tick
    T1TCR=0;  //disable timer1
}

void trigger_pulse(void){
    T1PC=0;
    T1TC=0;
    IOSET0=trig;  //SET trigger for 10us
    delay_us(10);
    IOCLR0=trig;  //CLEAR trigger
}

u32 get_distance(void){
    u32 dist=0;
    trigger_pulse();
    while(echo==0);    //wait for echo high
    T1TCR=1;   //start timer1
    while(echo==1);    //wait for echo low
    T1TCR=0;   //stop timer1
    dist=T1TC;
    dist=(0.0343*dist)/2;    //calculate distance
    return dist;
}
