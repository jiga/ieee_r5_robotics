
void isr_timer0(void);
void init_timer0(void);	

void isr_outer_LS_L(void);
void isr_upper_outer_LS_L(void);
void init_outer_LS_L(int);
void disable_outer_LS_L(void);

void isr_outer_LS_R(void);
void isr_upper_outer_LS_L(void);
void init_outer_LS_R(int);
void disable_outer_LS_R(void);

int count_LS_L=0, count_LS_R=0, count_upper_LS_L =0, count_upper_LS_R =0;
int new_count_LS_L=2, new_count_LS_R=2;
int interruptcount;
volatile unsigned int isInterruptOccurred = FALSE;
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// INITIALIZE INTERRUPTS ///////////////////////////////////////
/////////////////////////init all interrupts here//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

//////////////////////// Init Routine for TIMER0 ////////////////////////////////////
void init_timer0(void)					// timer initialization module SETS timer to 250ms
{
	T0CTL &= 0x7F;						// disable timer
  	T0CTL |= 0x01;						// continuous mode set don't change

	T0CTL |= 0x00;						// prescalar set to 001(divide by s2)
	T0CTL |= 0x40;      				// set the TPOL bit  
		
	T0H = 0x00;							// Start value = 01 don't change
	T0L = 0x00;	
	T0PWMH = 0x00;						// change these 4 values for different duty cycle
	T0PWML = 0x00;		
	T0RH = 0x01;
	T0RL = 0x00;
	
	SET_VECTOR(TIMER0, isr_timer0);		// initialization of TIMER1 vector
	IRQ0ENH |= 0x20;					// T0 has highest priority
	IRQ0ENL |= 0x20;

	T0CTL |= 0x80;						// enable timer
}
////////////////////////////////////////////////////////////////////////////////////

	
/////////////////// Init Routine for C0 => Outer Line Sensor-Left//////////////////
void init_outer_LS_L(int cc)
{
	new_count_LS_L=cc;
	SET_VECTOR(C0, isr_outer_LS_L); 	// Interrupt Service Routine Function Spec
	IRQ2ENH |= 0x01;					// Set Interrupt Priority High
	IRQ2ENL |= 0x01;					// Set Interrupt Priority High
}
////////////////////////////////////////////////////////////////////////////////////

/////////////// Disable Interrupt for C0 => Outer Line Sensor-Left//////////////////
void disable_outer_LS_L(void)
{
	IRQ2ENH &= 0xFE;					// Disable Interrupt C0
	IRQ2ENL &= 0xFE;					
}
//////////////////////////////////////////////////////////////////////////////////




/////////////////// Init Routine for C1 => Outer Line Sensor-Right//////////////////
void init_outer_LS_R(int cc)
{
	new_count_LS_R=cc;
	SET_VECTOR(C1, isr_outer_LS_R); 	// Interrupt Service Routine Function Spec
	IRQ2ENH |= 0x02;					// Set Interrupt Priority High
	IRQ2ENL |= 0x02;					// Set Interrupt Priority High
}
//////////////////////////////////////////////////////////////////////////////////////

/////////////// Disable Interrupt for C1 => Outer Line Sensor-Right//////////////////
void disable_outer_LS_R(void)
{
	IRQ2ENH &= 0xFD;					// Disable Interrupt C1
	IRQ2ENL &= 0xFD;					
}
//////////////////////////////////////////////////////////////////////////////////




/////////////////// Init Routine for C2 => Outer Line Sensor-Left//////////////////
void init_upper_outer_LS_L(int cc)
{
	new_count_LS_L=cc;
	SET_VECTOR(C2, isr_outer_LS_L); 	// Interrupt Service Routine Function Spec
	IRQ2ENH |= 0x04;					// Set Interrupt Priority High
	IRQ2ENL |= 0x04;					// Set Interrupt Priority High
}
////////////////////////////////////////////////////////////////////////////////////

/////////////// Disable Interrupt for C2 => Outer Line Sensor-Left//////////////////
void disable_upper_outer_LS_L(void)
{
	IRQ2ENH &= 0xFB;					// Disable Interrupt C2
	IRQ2ENL &= 0xFB;					
}
//////////////////////////////////////////////////////////////////////////////////




/////////////////// Init Routine for C3 => Outer Line Sensor-Right//////////////////
void init_upper_outer_LS_R(int cc)
{
	new_count_LS_R=cc;
	interruptcount = 0;
	SET_VECTOR(C3, isr_outer_LS_R); 	// Interrupt Service Routine Function Spec
	IRQ2ENH |= 0x08;					// Set Interrupt Priority High
	IRQ2ENL |= 0x08;					// Set Interrupt Priority High
}
//////////////////////////////////////////////////////////////////////////////////////

/////////////// Disable Interrupt for C3 => Outer Line Sensor-Right//////////////////
void disable_upper_outer_LS_R(void)
{
	IRQ2ENH &= 0xF7;					// Disable Interrupt C3
	IRQ2ENL &= 0xF7;					
}
//////////////////////////////////////////////////////////////////////////////////















/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// END INITIALIZE INTERRUPTS ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////// 




////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// INTERRUPT SERVICE ROUTINES /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

#pragma interrupt		
void isr_timer0(void)
{
	/*extern char ls_status;
	ls_status = PEIN;
	ls_status = ~ls_status;
	*/
}


#pragma interrupt
void isr_outer_LS_L(void) 
{
//static int count_LS_L=0;	
	count_LS_L++;
	if (count_LS_L == new_count_LS_L)
		{
			m_stop();
			count_LS_L=0;	
			isInterruptOccurred = TRUE;
			
		}

}


#pragma interrupt
void isr_outer_LS_R(void) 
{
//static int count_LS_R=0;
	count_upper_LS_R++;
	if (count_LS_R == new_count_LS_R)
		{
			m_stop();
			count_LS_R=0;	
			isInterruptOccurred = TRUE;
		}

}

/*
#pragma interrupt
void isr_upper_outer_LS_L(void) 
{
//static int count_LS_L=0;	
	interruptcount++;
	count_upper_LS_L++;
	if (count_LS_L == new_count_LS_L)
		{
			m_stop();
			count_upper_LS_L=0;	
			isInterruptOccurred = TRUE;
			
		}

}


#pragma interrupt
void isr_upper_outer_LS_R(void) 
{
//static int count_LS_R=0;
	interruptcount++;
	count_upper_LS_R++;
	if (count_upper_LS_R == new_count_LS_R)
		{
			m_stop();
			count_upper_LS_R=0;	
			isInterruptOccurred = TRUE;
		}

}*/
/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// END INTERRUPT SERVICE ROUTINES ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////// 








