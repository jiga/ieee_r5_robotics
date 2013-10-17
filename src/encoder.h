#define RESOLUTION 10

//function prototypes//

void init_encoder_isr(void);
void isr_Encoder(void);
void init_encoder_gpio(void);
void disable_encoder(void);

///-----------------///
int x,i;
int count;
char temp;

void init_encoder_gpio(void)
{
  SET_VECTOR(P4AD, isr_Encoder); 
	
  PDADDR 	= 0x02;  // PD Alternate function
  PDCTL 	= 0x00;

  PDADDR 	= 0x01;     // PD Data Dir = input: updated
  PDCTL 	= 0xFF;     // PD input Ctrl  D4-->Yellow G1-->Green
 
 	IRQ1ENH |= 0x10;	// Set Interrupt Priority High
	IRQ1ENL |= 0x10;	// Set Interrupt Priority High

  //PGADDR 	= 0x01;		// PG Data Dir = input: updated
  //PGCTL		= 0xFF;	 	// PG input Ctrl D4-->Yellow G1-->Blue

  IRQES = 0xFF; 		//rising edge
  IRQPS = 0xFF;			//port D selected over port A
}

//////////////////////////////////////////////////////////
//Interrupt routine

#pragma interrupt
void isr_Encoder(void) 
{
	DI();
	temp =PGIN;
	x++;
	if ((x%RESOLUTION)==0)
	{
		if ((temp & 0x02)== 0x02) count++ ;
		else count-- ;
	
	}
	EI();
}
	

//////////////////////////////////////////////////////////
//Intialize Encoder Interrupt ISR
void init_encoder_isr(void)
{
	SET_VECTOR(P4AD, isr_Encoder); 
	IRQPS = 0xFF;
	IRQES = 0x00;
	IRQ1ENH |= 0x10;	// Set Interrupt Priority High
	IRQ1ENL |= 0x00;	// Set Interrupt Priority High
}

void disable_encoder(void)
{
 	IRQ1ENH |= 0x00;	// Set Interrupt OFF
	IRQ1ENL |= 0x00;	// Set Interrupt OFF}
}
