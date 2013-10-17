/* 
 * navigator.h - some utility functions e.g. for debugging
 * Authors:
 *			Jignesh Patel <jkp34c@umkc.edu>
 *
 * Date Created:	Wednesday 02/08/2006
 * Date Modified:	Thursday 03/02/2006
 *
 */
//#include "interrupts.h"
void followline(void);
void followline_into_2way_turnleft(void);
void followline_into_2way_turnright(void);
void revolution_left(void);
void revolution_right(void);
void revolution_rightbill(void);
void revolution_leftbill(void);
void revolution_followline(void);
void revolution_followcurve(void);
void revolution_followcurve_late(void);
void revolution_followcurve_latebill_turnleft(void);
void revolution_followcurve_latebill_turnright(void);
void followlineoutofrightcurve(void);
void followlineoutofleftcurve(void);
void snapright(void);
void snapleft(void);
void snaprightfine(void);
void snapleftfine(void);
void moveforward(void);

//03-09-06
void snapright_slowly(int, int);
void snapleft_slowly(int, int);
void snaprightfine_slowly(int, int);
void snapleftfine_slowly(int, int);
void followline_slowly(int, int);
void followline_software_delay(unsigned int);

void followline_into_2way_turnleft_slowly(void);
void followline_3way_slowly(int, int);
void followline_slowly_outof3way(int , int);
void followline_slowly_straight_across_R(int , int);
void followline_slowly_straight_across_L(int , int);
void snapleftfine_slowly_All(int,int);

void followline_to_room(int, int );

int j, beinchod;
volatile unsigned int isInterruptOccurred;


void followline(void)
{
	
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_forward();
						break;
			
				case LS_L: // left led
						m_turnleft();
						break;
			
				case LS_R: // right led
						m_turnright();
						break;
				
				default:
						m_forward();
						break;
						//return;
			}
		}
		m_stop();
}
/*
void followline_to_room(int on_time, int off_time)
{
	
		while((PHIN&0x07) == 0x01)
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_forward();
						for(beinchod=0;beinchod<on_time;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<0ff_time;beinchod++);
						break;
								
				case LS_L: // left led
						m_turnleft();
						for(beinchod=0;beinchod<on_time;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<0ff_time;beinchod++);
						break;
			
				case LS_R: // right led
						m_turnright();
						for(beinchod=0;beinchod<on_time;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<0ff_time;beinchod++);
						break;
				
				default:
						m_forward();
						for(beinchod=0;beinchod<on_time;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<0ff_time;beinchod++);
						break;
						//return;
			}
		}
		m_stop();
		m_reverse();
		for(beinchod=0;beinchod<65000;beinchod++);
		m_stop();
}*/


void followline_to_room(int on_time, int 0ff_time)
{
	while((PHIN&0x07) == 0x01)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
					m_forward();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
		
			case LS_L: // left led
					m_turnleft();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);m_turnleft();
					break;
			
			case LS_R: // right led
					m_turnright();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
				
			default:
					m_forward();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
					//return;
		}
	}
	m_stop();
	m_reverse();
	for(beinchod=0;beinchod<65000;beinchod++);
	m_stop();
	
}

/*	// ******************************** DELETE THIS ********************************

void followline_PDIN(int on_time, int 0ff_time)
{
		isInterruptOccurred = FALSE;
		while((PDIN != 0)||(!isInterruptOccurred))
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_forward();
						for(beinchod=0;beinchod<on_time;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<0ff_time;beinchod++);
						break;
			
				case LS_L: // left led
						m_turnleft();
						for(beinchod=0;beinchod<on_time;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<0ff_time;beinchod++);
						break;
			
				case LS_R: // right led
						m_turnright();
						for(beinchod=0;beinchod<on_time;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<0ff_time;beinchod++);
						break;
				
				default:
						m_forward();
						for(beinchod=0;beinchod<on_time;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<0ff_time;beinchod++);
						break;
						//return;
			}
		}
		m_stop();
}

void followline_3way_slowly(int on_time, int 0ff_time)
{
	while(upper_outer_L != 1 && upper_outer_R != 1)
	//while(!(count_upper_LS_L && count_upper_LS_R) )
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
					m_forward();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
		
			case LS_L: // left led
					m_turnleft();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
			
			case LS_R: // right led
					m_turnright();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
				
			default:
					m_forward();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
					//return;
		}
	}
	m_stop();
	
}

void followline_into_2way_turnleft() //DO NOT ERASE!!
{
		
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_forward();
						break;
			
				case LS_L: // left led
						m_turnleft();
						break;

				case LS_R: // right led
						m_forward();
						break;
				
				case LS_ALL:
						m_forward();
						break;
			
				default:
						m_forward();
						break;
						//return;
			}
		}
	
		m_reverse();
		m_stop();
			
}

void followline_into_2way_turnleft_slowly() //DO NOT ERASE!!
{
		
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			switch(ls_status&LS_MASK)
			{
			
				case LS_L: // left led
						m_turnleft();
						for(beinchod=0;beinchod<5000;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<5000;beinchod++);
						break;

			
				default:
						m_forward();
						for(beinchod=0;beinchod<5000;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<5000;beinchod++);
						break;
						//return;
			}
		}
	
		m_reverse();
		m_stop();
			
}

void followline_into_2way_turnright() //DO NOT ERASE!!
{
		
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_forward();
						break;
			
				case LS_L: // left led
						m_forward();
						break;

				case LS_R: // right led
						m_turnright();
						break;
				
				case LS_ALL:
						m_forward();
						break;
			
				default:
						m_forward();
						break;
						//return;
			}
		}
	
		m_reverse();
		m_stop();
			
}
*/
/*
void followline_software_delay_slowly(int delay)
{
		int y=0;
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_forward();
						for(beinchod=0;beinchod<5000;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<5000;beinchod++);
						break;
			
				case LS_L: // left led
						m_turnleft();
						for(beinchod=0;beinchod<5000;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<5000;beinchod++);
						break;
			
				case LS_R: // right led
						m_turnright();
						for(beinchod=0;beinchod<5000;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<5000;beinchod++);
						break;
				
				default:
						m_forward();
						for(beinchod=0;beinchod<5000;beinchod++);
						m_stop();
						for(beinchod=0;beinchod<5000;beinchod++);
						break;
						//return;
			}
			y++;
			if (y==delay)isInterruptOccurred = TRUE;
		}
		m_stop();
}
*/

void followline_software_delay(unsigned int delay)
{
		int y=0;
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_forward();
						break;
			
				case LS_L: // left led
						m_turnleft();
						break;
			
				case LS_R: // right led
						m_turnright();
						break;
				
				default:
						m_forward();
						break;
						//return;
			}
			y++;
			if (y==delay)isInterruptOccurred = TRUE;
		}
		m_stop();
}

void followline_slowly(int on_time, int 0ff_time)
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
					m_forward();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
		
			case LS_L: // left led
					m_turnleft();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);m_turnleft();
					break;
			
			case LS_R: // right led
					m_turnright();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
				
			default:
					m_forward();
					for(beinchod=0;beinchod<on_time;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<0ff_time;beinchod++);
					break;
					//return;
		}
	}
	m_stop();
	
}

void followline_slowly_outof3way(int on_time, int 0ff_time)
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred || outer_L != 2 || outer_R != 2)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
				m_forward();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);
				break;
		
			case LS_L: // left led
				m_turnleft();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);m_turnleft();
				break;
			
			case LS_R: // right led
				m_turnright();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);
				break;
				
			default:
				m_forward();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);
				break;
				//return;
		}
	}
	m_stop();
}

void followline_slowly_straight_across_R(int on_time, int 0ff_time)
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred || outer_R != 2)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
				m_forward();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);
				break;
		
			case LS_L: // left led
				m_turnleft();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);m_turnleft();
				break;
			
			case LS_R: // right led
				m_turnright();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);
				break;
				
			default:
				m_forward();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);
				break;
				//return;
		}
	}
	m_stop();
}


void followline_slowly_straight_across_L(int on_time, int 0ff_time)
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred || outer_L != 2)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
				m_forward();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);
				break;
		
			case LS_L: // left led
				m_turnleft();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);m_turnleft();
				break;
			
			case LS_R: // right led
				m_turnright();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);
				break;
				
			default:
				m_forward();
				for(beinchod=0;beinchod<on_time;beinchod++);
				m_stop();
				for(beinchod=0;beinchod<0ff_time;beinchod++);
				break;
				//return;
		}
	}
	m_stop();
}

/*
void followlineoutofleftcurve()
{

		int i = 0;
		isInterruptOccurred = FALSE;
		init_outer_LS_L(2);	
		while(!isInterruptOccurred)
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_forward();
						break;
			
				case LS_L: // left led
						m_turnleft();
						break;
			
				case LS_R: // right led
						m_turnright();
						break;
				
				case LS_ALL:
						m_turnright();
						break;
				case LS_LR:
						m_stop();
						return;
				default:
						m_forward();
						break;
						//return;
			}
		i++;
		if(i>50)isInterruptOccurred = TRUE;
		}
		m_stop();
}
*/
/*
void followlineoutofrightcurve()
{
		int i = 0;
		isInterruptOccurred = FALSE;
//		init_outer_LS_R(2);				// *** Changed by DG (3/9/06) - WT do you accept?
		while(!isInterruptOccurred)
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_forward();
						break;
			
				case LS_L: // left led
						m_turnleft();
						break;
			
				case LS_R: // right led
						m_turnright();
						break;
				
				case LS_ALL:
						m_turnright();
						break;
				
				case LS_NONE:			//*** ADDED this case, Changed by DG (3/9/06) - WT do you accept?
						m_turnright();
						break;

				case LS_LR:
						m_stop();
						return;
				default:
						m_forward();
						break;
						//return;
			}
		i++;
		if(i>50)isInterruptOccurred = TRUE;
		}
		m_stop();
}
*/

void moveforward()
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred)
	{
		m_forward();
	}
	m_stop();
}

/*
void revolution_left()
{
	if(ls_status==LS_ALL)
	{
		while(ls_status & LS_MASK != LS_L)
		{
			m_turnleft();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<10000;beinchod++);
		}
		
		m_turnright();
		m_stop();
	}
}
*/
/*
void revolution_right()
{
	if(ls_status==LS_ALL)
	{
		while(ls_status & LS_MASK != LS_R)
		{
			m_turnright();
			for(beinchod=0;beinchod<500;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<10000;beinchod++);
		}
		
		m_turnleft();
		m_stop();
	}
}

*/
/*
void revolution_leftbill()
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred)
	{
		m_turnleft();
		for(beinchod=0;beinchod<15000;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<5000;beinchod++);
	}
		
	m_turnright();
	m_stop();
	
}
*/
/*
void revolution_rightbill()
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred)
	{
		m_turnright();
		for(beinchod=0;beinchod<15000;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<5000;beinchod++);
	}
		
	m_turnleft();
	m_stop();
	
}

*/
/*
void revolution_followcurve()
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<10000;beinchod++);
					break;
		
			case LS_L: // left led
					m_turnleft();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<10000;beinchod++);m_turnleft();
					break;
			
			case LS_R: // right led
					m_turnright();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<10000;beinchod++);
					break;
				
			default:
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<10000;beinchod++);
					break;
					//return;
		}
	}
	m_stop();
	
}
*/
/*
void revolution_followcurve_late()
{
	int i = 0;
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<10000;beinchod++);
					break;
		
			case LS_L: // left led
					m_turnleft();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<10000;beinchod++);
					break;
			
			case LS_R: // right led
					m_turnright();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<10000;beinchod++);
					break;
				
			default:
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<10000;beinchod++);
					break;
					//return;
		}
		i++;
		if(i>50)isInterruptOccurred = TRUE;
	}
	m_stop();
	
}
*/
/*
void revolution_followcurve_latebill_turnleft()//Possibly take out L1
{
	int i = 0;
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
		
			
			case LS_L1:
			case LS_L: // left led
					m_turnleft();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
			
			
			case LS_R: // right led
					m_turnright();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
				
			case LS_NONE:
					m_turnleft();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
					
			default:
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
					
		}
		i++;
		if(i>50)isInterruptOccurred = TRUE;
	}
	m_stop();
	
}
*/
/*
void revolution_followcurve_latebill_turnright()//Possibly take out L1
{
	int i = 0;
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
		
			
			
			case LS_L: // left led
					m_turnleft();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
			
			case LS_R1:
			case LS_R: // right led
					m_turnright();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
				
			case LS_NONE:
					m_turnleft();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
					
			default:
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<7000;beinchod++);
					break;
					
		}
		i++;
		if(i>50)isInterruptOccurred = TRUE;
	}
	m_stop();
	
}
*/
/*
void revolution_followline()
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred)
	{
		switch(ls_status&LS_MASK)
		{
			case LS_C: // center
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<5000;beinchod++);
					break;
		
			case LS_L: // left led
					m_turnleft();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<5000;beinchod++);
					break;
			
			case LS_R: // right led
					m_turnright();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<5000;beinchod++);
					break;
				
			default:
					m_forward();
					for(beinchod=0;beinchod<5000;beinchod++);
					m_stop();
					for(beinchod=0;beinchod<5000;beinchod++);
					break;
					//return;
		}
	}
	m_stop();
	
}
*/

void snapleft()
{
	isInterruptOccurred = FALSE;
	while(!isInterruptOccurred || (ls_status&LS_MASK == LS_L))
		{
			m_turnleft();
		}
	m_turnright();
	m_stop();
}



void snapleft_slowly(int on_time, int 0ff_time)
{
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			m_turnleft();
			for(beinchod=0;beinchod<on_time;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<0ff_time;beinchod++);
		}
		m_stop();
}


void snapleftfine()
{
	if((ls_status&LS_MASK) == (LS_ALL||LS_L||LS_L1))
		while((ls_status&LS_MASK) != (LS_C))
			m_turnleft();
	
	m_reverse();
	m_stop();
}

void snapleftfine_slowly(int on_time, int 0ff_time)
{
	while((ls_status&LS_MASK) != (LS_C))
	{
		m_turnleft();
		for(beinchod=0;beinchod<on_time;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<0ff_time;beinchod++);
	}	
	
	m_stop();
		
}


void snapleftfine_slowly_All(int on_time, int 0ff_time)
{
	while((ls_status&LS_MASK) != (LS_ALL))
	{
		m_turnleft();
		for(beinchod=0;beinchod<on_time;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<0ff_time;beinchod++);
	}	
	
	m_stop();
		
}

void snapleftfine_slowly_NONE(int on_time, int 0ff_time)
{
	while((ls_status&LS_MASK) != (LS_NONE))
	{
		m_turnleft();
		for(beinchod=0;beinchod<on_time;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<0ff_time;beinchod++);
	}	
	
	m_stop();
		
}




void snapright()
{
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			m_turnright();
		}
		m_stop();
}


void snapright_slowly(int on_time, int 0ff_time)
{
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			m_turnright();
			for(beinchod=0;beinchod<on_time;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<0ff_time;beinchod++);
		}
		m_stop();
}


void snaprightfine()
{
	if((ls_status&LS_MASK) == (LS_ALL||LS_R||LS_R1))
		while((ls_status&LS_MASK) != (LS_C))
			m_turnright();
	
	m_reverse();
	m_stop();
		
}

void snaprightfine_slowly(int on_time, int 0ff_time)
{
	while((ls_status&LS_MASK) != (LS_C))	
	{
		m_turnright();
		for(beinchod=0;beinchod<on_time;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<0ff_time;beinchod++);
	}	
	
	m_stop();
		
}

void snaprightfine_slowly_left(int on_time, int 0ff_time)
{
	while((ls_status&LS_MASK) != (LS_L))	// jigFix:: LS_C to LS_L
	{
		m_turnright();
		for(beinchod=0;beinchod<on_time;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<0ff_time;beinchod++);
	}	
	
	m_stop();
		
}

void snaprightfine_slowly_All(int on_time, int 0ff_time)
{
	int flag1=0,flag2=0;
	while((ls_status&LS_MASK) != (LS_ALL))
	{
		m_turnright();
		for(beinchod=0;beinchod<on_time;beinchod++);
	/*	{
			if((ls_status&LS_MASK) == (LS_ALL))
			{
				flag1=1;
				m_stop();
				break;
			}
		}
		if(flag1)break;*/
		m_stop();
		for(beinchod=0;beinchod<0ff_time;beinchod++);
	/*	{
			if((ls_status&LS_MASK) == (LS_ALL))
			{
				flag2=1;
				m_stop();
				break;
			}
		}
		if(flag2)break;*/

	}	
	
	m_stop();
		
}

void snaprightfine_slowly_NONE(int on_time, int 0ff_time)
{
	int flag1=0,flag2=0;
	while((ls_status&LS_MASK) != (LS_NONE))
	{
		m_turnright();
		for(beinchod=0;beinchod<on_time;beinchod++)
		{
			if((ls_status&LS_MASK) == (LS_NONE))
			{
				flag1=1;
				m_stop();
				break;
			}
		}
		if(flag1)break;
		m_stop();
		for(beinchod=0;beinchod<0ff_time;beinchod++)
		{
			if((ls_status&LS_MASK) == (LS_NONE))
			{
				flag2=1;
				m_stop();
				break;
			}
		}
		if(flag2)break;

	}	
	
	m_stop();
		
}

void followline_software_delay_reverse(unsigned int delay)
{
		int y=0;
		isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)
		{
			switch(ls_status&LS_MASK)
			{
				case LS_C: // center
						m_reverse();
						break;
			
				case LS_L: // left led
						m_turnleft();
						break;
			
				case LS_R: // right led
						m_turnright();
						break;
				
				default:
						m_reverse();
						break;
						//return;
			}
			y++;
			if (y==delay)isInterruptOccurred = TRUE;
		}
		m_stop();
}






