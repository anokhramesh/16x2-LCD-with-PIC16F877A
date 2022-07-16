
#include <xc.h>
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);
#include "lcd.h"
#define _XTAL_FREQ 10000000

void display(int a,int b);
char arr[]={"ANOKHRAMESH"};
void main(void) {
 TRISB0 =TRISB1=TRISB4=TRISB5=TRISB6=TRISB7=TRISC=0;
TRISB2=TRISB3=1;
RC0 =0;
display (0x02,0);//command for Enable LCD to 4 bit mode
display (0x01,0);// command for clear screen
display (0x0c,0);
display (0x28,0); //select Raw of LCD      
while(1){
    display (0x80,0);// (0x83,0)print 1st RAW 3rd column.
    for(int i=0;arr[i]!='\0';i++)
    {display(arr[i],1);
    }
    if(RB2 ==1)
    {while(RB2==1);
    {RC0 =RC0^1;
    }
    }
}
}
void display(int a,int b)
{
    PORTB=a;
    RB0=b;
    RB1=1;
    __delay_ms(10);
    RB1 =0;
    __delay_ms(10);
    PORTB=a<<4;
    RB0=b;
    RB1=1;
    __delay_ms(10);
    RB1=0;
    __delay_ms(10);   
    
 
}
