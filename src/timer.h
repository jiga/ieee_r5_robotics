
void isr_timer0(void);
void init_timer0(void);	

int flag_07=0;


	/* init_timer0 */
void init_timer0(void)			// timer initialization module SETS timer to 250ms
{
	T0CTL &= 0x7F;		// disable timer
  	T0CTL &= 0xF8;		// one shot mode set don't change

	T0CTL |= 0x38;		// prescalar set to 111 (divide by 128)
	T0CTL |= 0x40;      // set the TPOL bit  
		
	T0H = 0x00;		// Start value = 01 don't change
	T0L = 0x01;	

	T0RH = 0x8C;		
	T0RL = 0xA0;
	
	
	SET_VECTOR(TIMER0, isr_timer0);	// initialization of TIMER1 vector
	IRQ0ENH |= 0x20;		// T0 has highest priority
	IRQ0ENL |= 0x20;

	T0CTL |= 0x80;		// enable timer
}



 
int period=4;
#pragma interrupt			// interupt service routine
void isr_timer0(void)

{
static int i=0;

if (i<period)
	{
	T0CTL |= 0x80;		// enable timer
	i++;
	}
else
{
flag_07=1;
T0CTL &= 0x7F;		// disable timer
i=0;
}

}


 
