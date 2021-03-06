/*INTERFACING 16x2 LCD screen with PIC16F877A Microcontroller in 4 Bit mode
 ANOKHAUTOMATION
 https://microcontrollerslab.com/lcd-interfacing-pic16f877a-microcontroller/*/

#include <xc.h>
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & WRT_OFF & CP_OFF);
#define _XTAL_FREQ 10000000
void display(int a,int b);
char name[]={"ANOKH-AUTOMATION"};//char array
void main(void) {
    TRISB0=TRISB1=TRISB4=TRISB5=TRISB6=TRISB7=TRISC0=0;// Set PORTB0,1,2,3,4,5,6,7 and PORTC0 as OUTPUT
    TRISB2=1;// set PORTB2 (PIN35) as INPUT(connect Push Button)
    RC0 =0; // set PORTC0 (PIN15) as OUTPUT(connect LED)
    
    display (0x02,0);//Command for change LCD to 4 Bit Mode
    display (0x01,0);//Command for clear screen
    display (0x0c,0);//command for display ON,Cursor OFF,Blink OFF                 
    display (0x28,0);//Command for4 bit interface, 2 lines, 5x8 font
    
    while(1)
    {display (0x80,0);//Command for Begin Print at 1st Row,1st column
for(int i=0;name[i]!='\0';i++) 
{display(name[i],1);
}
    if (RB2 ==1)//If Push Button is Pressed 
    {while(RB2 ==1);
    RC0 = RC0^1;// TOGGLE LED
    }
    }
}
    void display(int a,int b)
    {PORTB=a;
    RB0=b;
    RB1=1;
    __delay_ms(10);
    RB1=0;
    __delay_ms(10);
    PORTB=a<<4;
    RB0=b;
    RB1=1;
    __delay_ms(10);
    RB1=0;
    __delay_ms(10);
    return;
}
