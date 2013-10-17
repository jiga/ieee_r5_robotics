
void isr_timer0(void);
void init_timer0(void);	

void isr_outer_LS_L(void);
void isr_upper_outer_LS_L(void);

void isr_lower_outer_LS_R(void); 
void isr_lower_outer_LS_L(void); 
void init_outer_LS_L(int);
void disable_outer_LS_L(void);

void isr_outer_LS_R(void);
void init_upper_outer_LS_L(int);
void isr_upper_outer_LS_R(void);
void init_outer_LS_R(int);
void disable_outer_LS_R(void);
void disable_upper_outer_LS_L(void);
void init_upper_outer_LS_R(int);
void disable_upper_outer_LS_R(void);

void disable_ALL_LS(void);


int upper_outer=0,outer=0;
int upper_outer_L=0,upper_outer_R=0;
int outer_R=0, 	outer_L=0;
int count_LS_L, count_LS_R, count_upper_LS_R, count_upper_LS_L;
int new_count_LS_L, new_count_LS_R, new_count_upper_LS_L, new_count_upper_LS_R;
volatile unsigned int isInterruptOccurred;
/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// INITIALIZE INTERRUPTS ///////////////////////////////////////
/////////////////////////init all interrupts here//////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

	
/////////////////// Init Routine for C0 => Outer Line Sensor-Left//////////////////
void init_outer_LS_L(int cc)
{
	outer=0;
	outer_L=0;
	count_LS_L=0;
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
	outer=0;
	outer_R=0;
	count_LS_R=0;
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
	upper_outer=0;
	upper_outer_L=0;
	count_upper_LS_L=0;
	new_count_upper_LS_L=cc;
	SET_VECTOR(C2, isr_upper_outer_LS_L); 	// Interrupt Service Routine Function Spec
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
	upper_outer=0;
	upper_outer_R=0;
	count_upper_LS_R=0;
	new_count_upper_LS_R=cc;
	SET_VECTOR(C3, isr_upper_outer_LS_R); 	// Interrupt Service Routine Function Spec
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


/////////////// Disable ALL Interrupt for C0-C3 => Outer Line Sensor-Right//////////////////
void disable_ALL_LS(void)
{
	IRQ2ENH &= 0xF0;					// Disable Interrupt C0-C3
	IRQ2ENL &= 0xF0;					

	IRQ1ENH &= 0xFC;					
	IRQ1ENL &= 0xFC;

	upper_outer=0;
	upper_outer_L=0;
	upper_outer_R=0;
	outer=0;
	outer_R=0;
	outer_L=0;

}
//////////////////////////////////////////////////////////////////////////////////



/////////////////// Init Routine for D0 => Lower Outer Line Sensor-Left//////////////////
void init_lower_outer_LS_L()
{	

	SET_VECTOR(P0AD, isr_lower_outer_LS_L);
	IRQES &= 0x00;								// edge select is negative edge	
	IRQPS &= 0xFF;								// Port Select D
 	// Interrupt Service Routine Function Spec
	IRQ1ENH |= 0x01;					// Set Interrupt Priority High
	IRQ1ENL |= 0x01;					// Set Interrupt Priority High
}
////////////////////////////////////////////////////////////////////////////////////

/////////////// Disable Interrupt for D0 => Outer Line Sensor-Left//////////////////
void disable_lower_outer_LS_L(void)
{
	IRQ1ENH &= 0xFE;					
	IRQ1ENL &= 0xFE;					
}
//////////////////////////////////////////////////////////////////////////////////



/////////////////// Init Routine for D1 => Lower Outer Line Sensor-right//////////////////
void init_lower_outer_LS_R()
{
	SET_VECTOR(P1AD, isr_lower_outer_LS_R); 
	IRQES &= 0x00;								// edge select is negative edge	
	IRQPS &= 0xFF;								// Port Select D
	// Interrupt Service Routine Function Spec
	IRQ1ENH |= 0x02;					// Set Interrupt Priority High
	IRQ1ENL |= 0x02;					// Set Interrupt Priority High
}
////////////////////////////////////////////////////////////////////////////////////

/////////////// Disable Interrupt for D1 => Outer Line Sensor-right//////////////////
void disable_lower_outer_LS_R(void)
{
	IRQ1ENH &= 0xFD;					
	IRQ1ENL &= 0xFD;					
}
//////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////////
///////////////////////// END INITIALIZE INTERRUPTS ////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////// 






////////////////////////////////////////////////////////////////////////////////////////
////////////////////////// INTERRUPT SERVICE ROUTINES /////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////



#pragma interrupt
void isr_outer_LS_L(void) 
{
//static int count_LS_L=0;	
	DI();
	outer=1;
	outer_L=1;
	count_LS_L++;
	if (count_LS_L == new_count_LS_L)
		{
			m_stop();
			outer_L=2;
			count_LS_L=0;	
			isInterruptOccurred = TRUE;
		//	IRQ2ENH &= 0xFE;					// Disable Interrupt C0
		//	IRQ2ENL &= 0xFE;
			
		}
	EI();
}


#pragma interrupt
void isr_outer_LS_R(void) 
{
//static int count_LS_R=0;
	DI();
	outer=2;
	outer_R=1;
	count_LS_R++;
	if (count_LS_R == new_count_LS_R)
		{
			m_stop();
			outer_R=2;
			count_LS_R=0;	
			isInterruptOccurred = TRUE;
		//	IRQ2ENH &= 0xFD;					// Disable Interrupt C0
		//	IRQ2ENL &= 0xFD;
		}
	EI();
}

#pragma interrupt
void isr_upper_outer_LS_L(void) 
{
	DI();
	upper_outer=1;
	upper_outer_L=1;
	count_upper_LS_L++;
	if (count_upper_LS_L == new_count_upper_LS_L)
		{
			m_stop();
			upper_outer_L=2;
			count_upper_LS_L=0;	
			isInterruptOccurred = TRUE;
		//	IRQ2ENH &= 0xFB;					// Disable Interrupt C0
		//	IRQ2ENL &= 0xFB;
			
		}
	EI();
}




#pragma interrupt
void isr_upper_outer_LS_R(void) 
{
	DI();
	upper_outer=2;
	upper_outer_R=1;
	count_upper_LS_R++;
	if (count_upper_LS_R == new_count_upper_LS_R)
		{
			m_stop();
			upper_outer_R=2;
			count_upper_LS_R=0;	
			isInterruptOccurred = TRUE;
		//	IRQ2ENH &= 0xF7;					// Disable Interrupt C0
		//	IRQ2ENL &= 0xF7;
		}
	EI();

}



#pragma interrupt
void isr_lower_outer_LS_L(void) 
{
	DI();
	
		m_stop();
	PAOUT =(~0x02);
	isInterruptOccurred = TRUE;
	//IRQ1ENH &= 0xFE;					
	//IRQ1ENL &= 0xFE;
	EI();
}


#pragma interrupt
void isr_lower_outer_LS_R(void) 
{
	DI();
	
		m_stop();
	PAOUT=(~0x01);
	isInterruptOccurred = TRUE;
	//IRQ1ENH &= 0xFD;					
	//IRQ1ENL &= 0xFD;
	EI();
}


/////////////////////////////////////////////////////////////////////////////////////////
///////////////////////// END INTERRUPT SERVICE ROUTINES ///////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////// 








