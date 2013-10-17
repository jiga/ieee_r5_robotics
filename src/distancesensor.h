

void isr_adc0(void);
void init_adc(void);
void init_gpio(void);
 
volatile unsigned int valueH,valueL;
volatile unsigned int adc_valuetemp;
//int temp_F;
volatile unsigned int distance;
volatile unsigned int flagGrab=0;
 
void find_can(int delay1,int delay2)
{
	
	PAOUT = ~0x01;
	while((PHIN&0x07)!= 0x01)
	{
		m_turnright();
		for(beinchod=0;beinchod<delay1;beinchod++)
		{
			if((PHIN&0x07)==0x01) break;
		}
		m_stop();	
		for(beinchod=0;beinchod<delay2;beinchod++);
	}

	
	isInterruptOccurred = FALSE;
	flagGrab = 0;
    while(!isInterruptOccurred)
	{
		ADCCTL |= 0x80;				//start finding object
		m_turnleft();
		for(beinchod=0;beinchod<delay1;beinchod++)
		{
			if(isInterruptOccurred) break;
		}
		m_stop();	
		for(beinchod=0;beinchod<delay2;beinchod++);
	}
	PAOUT = ~0x00;


	/*isInterruptOccurred = FALSE;
    while(!isInterruptOccurred)
	{
		ADCCTL |= 0x80;				//start finding object
		m_turnright();
		for(beinchod=0;beinchod<600;beinchod++);
		m_stop();	
	}
	PAOUT = ~0x03;*/
}

void grab_can(int delay1,int delay2)
{
	open();
	PAOUT = ~0x02;
	isInterruptOccurred = FALSE;
	flagGrab = 1;
	ADCCTL |= 0x80;				//start finding object
    while((distance >= 25)||(!isInterruptOccurred))
	{
	
		m_forward();
		for(beinchod=0;beinchod<delay1;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<delay2;beinchod++);
		
	}
	m_stop();
	flagGrab = 0;
	PAOUT = ~0x00;
	close();
}
 

void init_adc(void)
{
	DI();
	SET_VECTOR(ADC, isr_adc0);		// Set vector address of adc int to function

	ADCCTL = 0x20;			// 0010 0000b - single shot for ANA0,Vref provided externally

	IRQ0ENH |= 0x01;			// Enable ADC interrupt
	IRQ0ENL	|= 0x01;			// 0x10 = nominal interrupt level

	EI();
}

#pragma interrupt
void isr_adc0(void)
{
	ADCCTL &= 0x7F;			// Disable ADC conversion
	valueH = ADCD_H ;		
	valueH &= 0x0ff;			// Get ADC Data High from memory. 
								
	valueH = valueH << 2;		// Shift left 2 bits of ADC Data High.	 
	valueL = ADCD_L;			// Get ADC Data Low from memory. 

	valueL = valueL >> 6;				
	valueL &= 0x03;			// only last two bytes are  valid.
	adc_valuetemp = valueH | valueL; ;	// ADC Data High, ADC Data Low =10-bit ADC
	distance = adc_valuetemp/10;
	printf ("\n\n Current distance is:\t %d",distance);
	if(!flagGrab)
	{
			
		if (distance > 20)//) && (distance < 60)) 
		{
		m_stop();	
		isInterruptOccurred = TRUE;
		ADCCTL &= 0x7F;			// Disable ADC conversion
		}
		else ADCCTL |= 0x80;
	}
	else
	{
		if ((distance < 25)) 
		{
		m_stop();	
		isInterruptOccurred = TRUE;
		ADCCTL &= 0x7F;		
		}
		else ADCCTL |= 0x80;
	}
}



void init_gpio(void)
{
	/*******************************************************************
	   Configures PB0 for alternate function - ANA0 (for the ADC)
	*******************************************************************/

	PBADDR = 0x02;		// Select Alternate Function SubRegister
	PBCTL = 0x01;		// Enable PB0 alternate function as ANA0
	PBADDR = 0x00;

	return;
}

/**************END OF ADC PROJECT CODE*******************************/

