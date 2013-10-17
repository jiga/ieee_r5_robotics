//Created March 24th, 1:00 AM
//Author  Jonathan Rodgers
//Simple program to control the opening and closing of the 
//robot's arm or can holding device.

//Note, code adapted from motor.h & linesensor.h by Jignesh and Dhaval
// Configure hyperterminal for 57600 baud, 8 data bits, 1 stop bit, parity none  and hardware flow control none. 
#include <eZ8.h >
#include<stdio.h>


void open(void);
void close(void);
void init_servo(void);

#define FREQ 18432000                        // 18.432MHz
#define BAUD0 57600                                // 57.6K baud for UART0
#define BAUD1 2400								//2400 baud for UART1

#define BRG0 FREQ/(BAUD0*16L) 

#define BRG1 FREQ/(BAUD1*16L)

#define UART0
#define PORTA_UART_RXD				0x10
#define PORTA_UART_TXD              0x20
#define UART_TXD_EN                 0x80 
#define UART_RXD_EN                 0x40

#define UART1
#define PORTD_UART_RXD              0x10
#define PORTD_UART_TXD              0x20
#define UART1_TXD_EN                0x80 
#define UART1_RXD_EN                0x40

#define DATA_DIR 					0x01              // Data Direction
#define ALT_FUN  					0x02              // Alternate Function
#define OUT_CTL  					0x03                                 

void inituart0(void);
void inituart1(void);
void putch0(char Data);
void putch1(char Data1);
int getch0(void);
int getch1(void);


init_servo()
{ 
      inituart1();
}






 void open(void)
 {
	 putch1('A');
	 putch1('0');
	 putch1('5');
	 putch1('0');
	 printf("OPENED\n");
 }

 void close(void)
 {
	 putch1('A');
	 putch1('1');
	 putch1('1');
	 putch1('0');
	 printf("CLOSED\n");
 }

void inituart0(void)
{

     PAADDR = ALT_FUN;                // Configure for alternate function 
     PACTL |= 0x30;    // Enable UART0 TxD0/RxD0 pins and the driver enable
     U0BRH = (char)(BRG0 >> 8);                // Baud Rate High
     U0BRL = (char)(BRG0 & 0xff);                // Baud Rate Low 
     U0CTL0 = UART_RXD_EN | UART_TXD_EN;       // Transmit enable, Receive Enable, No Parity, 1 Stop
         
}

void inituart1(void)
{

 	 PDADDR = ALT_FUN;                                // Configure for alternate function 
 	 PDCTL |= PORTD_UART_TXD | PORTD_UART_RXD;        // Enable UART0 TxD0/RxD0 pins
     U1BRH = (char)(BRG1 >> 8);                                // Baud Rate High
     U1BRL = (char)(BRG1 & 0xff);
     U1CTL0 = UART_RXD_EN | UART_TXD_EN;       // Transmit enable, Receive Enable, No Parity, 1 Stop 

}



void putch0(char Data)
{
       while(!(U0STAT0 & 0x04))        // check for transmitter empty
               ;
       U0TXD=Data;                     // if empty print the character to serial port 

}
       

void putch1(char Data1)
{
       while(!(U1STAT0 & 0x04))        // check for transmitter empty
               ;
       U1TXD=Data1;                    // if empty print the character to serial port 
                  
}

int getch0(void)
{
   char ch;
    
   while (!(U0STAT0 & 0x80));     // Wait for receive data available
   ch = U0D;
    
   if (ch == '\r' || ch == ('\r'|0x80)) 
       return '\n';

   return(ch);
}

int getch1(void)
{
   char ch;

   while (!(U1STAT0 & 0x80));     // Wait for receive data available
   ch = U1D;
    
    if (ch == '\r' || ch == ('\r'|0x80))
       return '\n';

   return(ch);
}                

