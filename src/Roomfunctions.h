//Format created by Dhaval Ghody 

#include "roommovement.h"


void if_robot_stopped(void);
int abc;
extern char previous_count;

//extern int distance;
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
/////////////////Move Out Functions/////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
////////////////// Outer Rooms /////////////////////////
////////////////////////////////////////////////////////
void moveoutof_outerroom_turnright_sp(void)//ORIGINAL FUNCTION
{

///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////
//-------------------------------------
	init_upper_outer_LS_L(2);		
	init_upper_outer_LS_R(2);
		
	followline();
//-------------------------------------	
	disable_upper_outer_LS_L();		
	disable_upper_outer_LS_R();
	
	init_outer_LS_L(2);			//Init sensors for turn right 	
								//L=1 R=0
	snapright_slowly(5000,10000);

	snaprightfine_slowly(5000,10000);

//-------------------------------------	
	disable_outer_LS_L();
	init_outer_LS_L(2);			//Init sensors navigate right curve

	followline_slowly(5000,4000);	// ????? can possibly use followline slow

//-------------------------------------
	disable_outer_LS_L();		//ALL LS Innterrupts Disabled	
	snaprightfine_slowly(5000,10000);

//-------------------------------------	

/*	disable_ALL_LS();	//ALL LS Innterrupts Disabled		
	init_outer_LS_L(1);
	init_outer_LS_R(1);
	init_upper_outer_LS_R(2);
	init_upper_outer_LS_L(2);

	//followline_PDIN(5000,4000);	
	followline();*/

	disable_ALL_LS();

	followline_software_delay(25000);

	//followline_software_delay(35000); // ******** Change these values to increase the speed if the patch can be detected 
//-------------------------------------
	
	disable_ALL_LS();
						// enable new LS interrupts only if robot stopped
	//init_upper_outer_LS_L(2);	//Include when stand-alone testing		
	//init_upper_outer_LS_R(2);	//Include when stand-alone testing

	//followline(); //Include when stand-alone testing

}

void moveoutof_outerroom_turnleft_sp(void)//REDEFINED FROM ORIGINAL
{

///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////
//-------------------------------------
	init_upper_outer_LS_L(2);		
	init_upper_outer_LS_R(2);
		
	followline();
//-------------------------------------	
	disable_upper_outer_LS_L();		
	disable_upper_outer_LS_R();
	
	init_outer_LS_R(2);			//Init sensors for turn right 	
								//L=1 R=0
	snapleft_slowly(5000,10000);

	snapleftfine_slowly(5000,10000);

//-------------------------------------	
	disable_outer_LS_R();
	init_outer_LS_R(2);			//Init sensors navigate right curve

	followline_slowly(5000,4000);	// ????? can possibly use followline slow

//-------------------------------------
	disable_outer_LS_R();		//ALL LS Innterrupts Disabled	
	snapleftfine_slowly(5000,10000);

//-------------------------------------	
	
/*	init_outer_LS_R(1);
	init_outer_LS_L(1);

	followline();*/
	
	disable_ALL_LS();

	followline_software_delay(25000); // ******** Change these values to increase the speed if the patch can be detected 
//-------------------------------------

	disable_ALL_LS();
				
	//init_upper_outer_LS_L(2);	//Include when stand-alone testing		
	//init_upper_outer_LS_R(2);	//Include when stand-alone testing
	//followline(); 			//Include when stand-alone testing
}

void moveoutof_outerroom_turnright(void)//ORIGINAL FUNCTION
{

///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////
//-------------------------------------
	init_upper_outer_LS_L(2);		
	init_upper_outer_LS_R(2);
		
	followline();
//-------------------------------------	
	disable_upper_outer_LS_L();		
	disable_upper_outer_LS_R();
	
	init_outer_LS_L(2);			//Init sensors for turn right 	
								//L=1 R=0
	snapright_slowly(5000,10000);

	snaprightfine_slowly(5000,10000);

//-------------------------------------	
	disable_outer_LS_L();
	init_outer_LS_L(2);			//Init sensors navigate right curve

	followline_slowly(5000,4000);	// ????? can possibly use followline slow

//-------------------------------------
	disable_outer_LS_L();		//ALL LS Innterrupts Disabled	
	snaprightfine_slowly(5000,10000);

//-------------------------------------	

	disable_ALL_LS();	//ALL LS Innterrupts Disabled		
	init_outer_LS_L(1);
	init_outer_LS_R(1);
	init_upper_outer_LS_R(2);
	init_upper_outer_LS_L(2);

	//followline_PDIN(5000,4000);	
	followline();

	disable_ALL_LS();

	followline_software_delay(5000);

	//followline_software_delay(35000); // ******** Change these values to increase the speed if the patch can be detected 
//-------------------------------------
	
	disable_ALL_LS();
						// enable new LS interrupts only if robot stopped
	//init_upper_outer_LS_L(2);	//Include when stand-alone testing		
	//init_upper_outer_LS_R(2);	//Include when stand-alone testing

	//followline(); //Include when stand-alone testing

}

void moveoutof_outerroom_turnleft(void)//REDEFINED FROM ORIGINAL
{

///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////
//-------------------------------------
	init_upper_outer_LS_L(2);		
	init_upper_outer_LS_R(2);
		
	followline();
//-------------------------------------	
	disable_upper_outer_LS_L();		
	disable_upper_outer_LS_R();
	
	init_outer_LS_R(2);			//Init sensors for turn right 	
								//L=1 R=0
	snapleft_slowly(5000,10000);

	snapleftfine_slowly(5000,10000);

//-------------------------------------	
	disable_outer_LS_R();
	init_outer_LS_R(2);			//Init sensors navigate right curve

	followline_slowly(5000,4000);	// ????? can possibly use followline slow

//-------------------------------------
	disable_outer_LS_R();		//ALL LS Innterrupts Disabled	
	snapleftfine_slowly(5000,10000);

//-------------------------------------	
	disable_ALL_LS();	
	init_outer_LS_R(1);
	init_outer_LS_L(1);

	followline();
	
	disable_ALL_LS();

	followline_software_delay(5000); // jigFix ******** Change these values to increase the speed if the patch can be detected 
//-------------------------------------

	disable_ALL_LS();
				
	//init_upper_outer_LS_L(2);	//Include when stand-alone testing		
	//init_upper_outer_LS_R(2);	//Include when stand-alone testing
	//followline(); 			//Include when stand-alone testing
}

////////////////////////////////////////////////////////
////////////////// Inner Rooms /////////////////////////
////////////////////////////////////////////////////////



void moveoutof_innerroom_turnleft_short(void)//ORIGINAL FUNCTION
{


///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	
	followline();
//-------------------------------------

	disable_ALL_LS();
	if (ls_status != LS_ALL)
				if(upper_outer==1) snapleftfine_slowly_All(5000,10000);
//-------------------------------------	
	
	snapleftfine_slowly(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
	init_outer_LS_L(2);	
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}
	//followline_slowly(5000,4000);
//-------------------------------------	
	disable_ALL_LS();
	snapleftfine_slowly(5000,10000);
//-------------------------------------	

	init_outer_LS_L(2);
	init_outer_LS_R(2);

	followline();

	disable_ALL_LS();

	followline_software_delay(5000);
//-------------------------------------
//	init_upper_outer_LS_L(2);		//Include when stand-alone testing
//	init_upper_outer_LS_R(2);		//Include when stand-alone testing
//	followline();		*/			//Include when stand-alone testing
}


void moveoutof_innerroom_turnleft(void)//ORIGINAL FUNCTION
{


///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	followline_software_delay(60000);
	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	
	followline_slowly(5000,10000);
//-------------------------------------

	delay(5);

	if (ls_status != LS_ALL)
		{	
		if(upper_outer_L > 0 && !(upper_outer_R > 0))			//right interrupt occured 
				{
				init_upper_outer_LS_L(2);
				snapleft_slowly(5000,10000);
				disable_ALL_LS();
				snapleftfine_slowly(5000,5000);
				}
		}
	else
    	{
		if (upper_outer_R > 0 && upper_outer_L > 0)
  	    		{
				snapleftfine_slowly(5000,5000);
				}
		else if (upper_outer_R > 0)
				{
				snaprightfine_slowly(5000,10000);	
				}
		else if (upper_outer== 2)			//right interrupt occured 
				{
				init_upper_outer_LS_L(2);
				snapleft_slowly(5000,10000);
				disable_ALL_LS();
				snapleftfine_slowly(5000,5000);
				}
		else snapleftfine_slowly(5000,10000);
		}
//-------------------------------------	
	snapleftfine_slowly_All(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
	init_upper_outer_LS_L(2);	
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}
//	followline_slowly(5000,4000);
//-------------------------------------	
	disable_ALL_LS();
	snapleftfine_slowly(5000,10000);
//-------------------------------------	

	init_outer_LS_L(2);
	init_outer_LS_R(2);

	followline();

	disable_ALL_LS();

	followline_software_delay(5000);
	
//-------------------------------------
//	init_upper_outer_LS_L(2);		//Include when stand-alone testing
//	init_upper_outer_LS_R(2);		//Include when stand-alone testing
//	followline();					//Include when stand-alone testing
}

void moveoutof_innerroom_turnleft_sp(void)//ORIGINAL FUNCTION
{


///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	followline_software_delay(60000);
	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	
	followline_slowly(5000,10000);
//-------------------------------------

	delay(5);

	if (ls_status != LS_ALL)
		{	
		if(upper_outer_L > 0 && !(upper_outer_R > 0))			//right interrupt occured 
				{
				init_upper_outer_LS_L(2);
				snapleft_slowly(5000,10000);
				disable_ALL_LS();
				snapleftfine_slowly(5000,5000);
				}
		}
	else
    	{
		if (upper_outer_R > 0 && upper_outer_L > 0)
  	    		{
				snapleftfine_slowly(5000,5000);
				}
		else if (upper_outer_R > 0)
				{
				snaprightfine_slowly(5000,10000);	
				}
		else if (upper_outer== 2)			//right interrupt occured 
				{
				init_upper_outer_LS_L(2);
				snapleft_slowly(5000,10000);
				disable_ALL_LS();
				snapleftfine_slowly(5000,5000);
				}
		else snapleftfine_slowly(5000,10000);
		}
//-------------------------------------	
	snapleftfine_slowly_All(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
	init_upper_outer_LS_L(2);	
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}
//	followline_slowly(5000,4000);
//-------------------------------------	
	disable_ALL_LS();
	snapleftfine_slowly(5000,10000);
//-------------------------------------	

/*	init_outer_LS_L(2);
	init_outer_LS_R(2);

	followline();

	disable_ALL_LS();
*/
	followline_software_delay(23000);
	
//-------------------------------------
//	init_upper_outer_LS_L(2);		//Include when stand-alone testing
//	init_upper_outer_LS_R(2);		//Include when stand-alone testing
//	followline();					//Include when stand-alone testing
}


void moveoutof_innerroom_turnright(void)//Redefined from Original
{

///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////
	followline_software_delay(60000);
	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	
	followline_slowly(5000,10000);
//-------------------------------------
	delay(5);

	if (ls_status != LS_ALL)
		{	if(upper_outer_R > 0 && !(upper_outer_L > 0) )			//right interrupt occured 
				{
				init_upper_outer_LS_R(2);
				snapright_slowly(5000,10000);
				disable_ALL_LS();
				snaprightfine_slowly(5000,5000);
				}
		}
	else
    	{
		if (upper_outer_L > 0 && upper_outer_R > 0)
  	    		{
				snaprightfine_slowly(5000,5000);
				}
		else if (upper_outer_L > 0)
				{
				snapleftfine_slowly(5000,10000);	
				}
		else if (upper_outer== 2)			//right interrupt occured 
				{
				init_upper_outer_LS_R(2);
				snapright_slowly(5000,10000);
				disable_ALL_LS();
				snaprightfine_slowly(5000,5000);
				}
		else snaprightfine_slowly(5000,10000);
		}
//-------------------------------------	
	snaprightfine_slowly_All(5000,10000);
	delay(3);
//-------------------------------------	
	disable_ALL_LS();
	init_upper_outer_LS_R(2);			//Init sensors navigate right curve
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<8000;beinchod++);
		}

	//followline_slowly(5000,4000);
//-------------------------------------	
	disable_ALL_LS();
	snaprightfine_slowly(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
	init_outer_LS_L(2);
	init_outer_LS_R(2);
	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	followline();

	disable_ALL_LS();

	followline_software_delay(5000);
	
//-------------------------------------
//	init_upper_outer_LS_L(2);		//Include when stand-alone testing
//	init_upper_outer_LS_R(2);		//Include when stand-alone testing
//	followline();					//Include when stand-alone testing
	
}

void moveoutof_innerroom_turnright_sp(void)//Redefined from Original
{

///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////
	followline_software_delay(60000);
	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	
	followline_slowly(5000,10000);
//-------------------------------------
	delay(5);

	if (ls_status != LS_ALL)
		{	if(upper_outer_R > 0)			//right interrupt occured 
				{
				init_upper_outer_LS_R(2);
				snapright_slowly(5000,10000);
				disable_ALL_LS();
				snaprightfine_slowly(5000,5000);
				}
		}
	else
    	{
		if (upper_outer_L > 0 && upper_outer_R > 0)
  	    		{
				snaprightfine_slowly(5000,5000);
				}
		else if (upper_outer_L > 0)
				{
				snapleftfine_slowly(5000,10000);	
				}
		else if (upper_outer== 2)			//right interrupt occured 
				{
				init_upper_outer_LS_R(2);
				snapright_slowly(5000,10000);
				disable_ALL_LS();
				snaprightfine_slowly(5000,5000);
				}
		else snaprightfine_slowly(5000,10000);
		}

//-------------------------------------	
	snaprightfine_slowly_All(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
	init_upper_outer_LS_R(2);			//Init sensors navigate right curve
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<8000;beinchod++);
		}

	//followline_slowly(5000,4000);
//-------------------------------------	
	disable_ALL_LS();
	snaprightfine_slowly(5000,10000);
//-------------------------------------	
/*	disable_ALL_LS();
	init_outer_LS_L(2);
	init_outer_LS_R(2);
	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	followline();

	disable_ALL_LS();*/

	followline_software_delay(23000);
	
//-------------------------------------
//	init_upper_outer_LS_L(2);		//Include when stand-alone testing
//	init_upper_outer_LS_R(2);		//Include when stand-alone testing
//	followline();					//Include when stand-alone testing
	
}

/*void moveoutof_innerroom_turnright_short(void)//Redefined from Original   //possibly can delete
{

///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	
	followline();
//-------------------------------------

	disable_ALL_LS();
	if (ls_status != LS_ALL)
				if(upper_outer==2) snaprightfine_slowly_All(5000,10000);
//-------------------------------------	
	
	snaprightfine_slowly(5000,10000);
//-------------------------------------	
	disable_ALL_LS();

	init_outer_LS_R(2);			//Init sensors navigate right curve
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}
//	followline_slowly(5000,4000);
//-------------------------------------	
	disable_ALL_LS();
	snaprightfine_slowly(5000,10000);
//-------------------------------------	

	init_outer_LS_L(2);
	init_outer_LS_R(2);

	followline();

	disable_ALL_LS();

	followline_software_delay(8000);
	
//-------------------------------------
//	init_upper_outer_LS_L(2);		//Include when stand-alone testing
//	init_upper_outer_LS_R(2);		//Include when stand-alone testing
//	followline();					//Include when stand-alone testing
	
}*/



////////////////////////////////////////////////////////
///////////////End Move Out Functions///////////////////
////////////////////////////////////////////////////////










////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
/////////////////Move Into Functions////////////////////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

////////////////////////////////////////////////////////
////////////////// Outer Rooms /////////////////////////
////////////////////////////////////////////////////////

void moveinto_outerroom_turnleft(void)//ORIGINAL FUNCTION
{
///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);

	followline_slowly(5000,5000);
//-------------------------------------
		delay(1);
	if (ls_status != LS_ALL)
		{	if(upper_outer_L > 0)			//right interrupt occured 
				{
				init_upper_outer_LS_L(1);
					snapleft_slowly(5000,10000);
				disable_ALL_LS();
				snapleftfine_slowly(5000,5000);
				}
		}
	else
    	{
		if (upper_outer_R > 0 && upper_outer_L > 0)
  	    		{
				snapleftfine_slowly(5000,5000);
				}
		else if (upper_outer_R > 0)
				{
				snaprightfine_slowly(5000,10000);	
				}
		else if (upper_outer== 1)			//right interrupt occured 
				{
				init_upper_outer_LS_L(2);
				snapleft_slowly(5000,10000);
				disable_ALL_LS();
				snapleftfine_slowly(5000,5000);
				}
		else snapleftfine_slowly(5000,10000);
		}

//-------------------------------------	
	snapleftfine_slowly_All(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
	init_outer_LS_L(2);

	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}
	
	disable_ALL_LS();
	snapleftfine_slowly(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
	followline_to_room(5000,2000);

//-------------------------------------	


}


void moveinto_outerroom_turnright(void)//Modified from Original
{
///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	followline_slowly(5000,5000);
//-------------------------------------
	delay(1);
	if (ls_status != LS_ALL)
		{	if(upper_outer_R > 0)			//right interrupt occured 
				{
				init_upper_outer_LS_R(1);
					snapright_slowly(5000,10000);
				disable_ALL_LS();
				snaprightfine_slowly(5000,5000);
				}
		}
	else
    	{
		if (upper_outer_L > 0 && upper_outer_R > 0)
  	    		{
				snaprightfine_slowly(5000,5000);
				}
		else if (upper_outer_L > 0)
				{
				snapleftfine_slowly(5000,10000);	
				}
		else if (upper_outer== 2)			//right interrupt occured 
				{
				init_upper_outer_LS_R(2);
				snapright_slowly(5000,10000);
				disable_ALL_LS();
				snaprightfine_slowly(5000,5000);
				}
		else snaprightfine_slowly(5000,10000);
		}

//-------------------------------------	
	snaprightfine_slowly_All(5000,5000);
//-------------------------------------	
	disable_ALL_LS();
	init_outer_LS_R(2);

	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}
	
	disable_ALL_LS();
	snaprightfine_slowly(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
	followline_to_room(5000,2000);
//-------------------------------------	

}


////////////////////////////////////////////////////////
////////////////// Inner Rooms /////////////////////////
////////////////////////////////////////////////////////



void moveinto_innerroom_turnright(void)//ORIGINAL FUNCTION
{

///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	init_outer_LS_L(2);
	init_outer_LS_R(2);
	followline();
	//	followline_slowly(5000,4000);
//-------------------------------------
	if(outer_R>0 && outer_L>0)
		{
		PAOUT = ~0x03;					// ROBOT is Centered
			disable_ALL_LS();
		init_upper_outer_LS_L(2);							
		snapright_slowly(5000,10000);
		snaprightfine_slowly(5000,10000);
		}

	else if (outer_R>0 && outer_L==0)
		{
		PAOUT = ~0x01;	//ROBOT is turned LEFT
		disable_ALL_LS();
		init_upper_outer_LS_L(2);
		snapright_slowly(5000,10000);
		snaprightfine_slowly(5000,10000);
		}
	else 
    	{
		PAOUT = ~0x02;							//ROBOT is turned RIGHT
		snaprightfine_slowly(5000,10000);
		}
/*	if(outer==1) 
		{
		snapleftfine_slowly(5000,10000);
		PAOUT = ~0x01;
		}
	else
		snaprightfine_slowly(5000,10000);
		PAOUT = ~0x02;*/

//-------------------------------------

	snaprightfine_slowly(5000,10000);
	snaprightfine_slowly_All(5000,10000);

//-------------------------------------	
	disable_ALL_LS();
	init_outer_LS_R(2);			//Init sensors navigate right curve
	
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}

//-------------------------------------	
	disable_ALL_LS();
	snaprightfine_slowly(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
//	init_upper_outer_LS_R(1);
/*	init_upper_outer_LS_L(1);
	init_outer_LS_L(1);
	printled(~0x07);
	followline();*/

	followline_to_room(5000,2000);

//-------------------------------------	

}



void moveinto_innerroom_turnleft(void)//Modified from Original
{

///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	init_outer_LS_R(2);
	init_outer_LS_L(2);
	followline();
	//followline_slowly(7000,4000);
//-------------------------------------
	if(outer_L>0 && outer_R>0)
		{
		PAOUT = ~0x03;					// ROBOT is Centered
		disable_ALL_LS();
		init_upper_outer_LS_R(2);							
		snapleft_slowly(5000,10000);
		snapleftfine_slowly(5000,10000);
		}

	else if (outer_L>0 && outer_R==0)
		{
		PAOUT = ~0x01;							//ROBOT is turned RIGHT
		disable_ALL_LS();
		init_upper_outer_LS_R(2);
		snapleft_slowly(5000,10000);
		snapleftfine_slowly(5000,10000);
		}
	else 
    	{
		PAOUT = ~0x02;							//ROBOT is turned LEFT
		snapleftfine_slowly(5000,10000);
		}

/*	if(outer==1)							// left interrupt occured 
		{
		snapleftfine_slowly(5000,10000);
		PAOUT = ~0x01;
		}
	else
		snaprightfine_slowly(5000,10000);
		PAOUT = ~0x02;*/
//-------------------------------------

/*	disable_ALL_LS();
	init_upper_outer_LS_R(2);		*/					
	snapleft_slowly(5000,10000);
	snapleftfine_slowly_All(5000,10000);

//-------------------------------------	
	disable_ALL_LS();
	init_outer_LS_L(2);			//Init sensors navigate right curve
	
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}
	//followline_slowly(5000,4000);	// ????? can possibly use followline slow

//-------------------------------------	
	snapleftfine_slowly(5000,10000);
//-------------------------------------
//	disable_ALL_LS();		//ALL LS Innterrupts Disabled	
//	snapleftfine_slowly();
//-------------------------------------	
	disable_ALL_LS();
//	init_upper_outer_LS_L(1);
/*	init_upper_outer_LS_R(1);
	init_outer_LS_R(1);
	printled(~0x07);
	followline();*/
	followline_to_room(5000,2000);

//-------------------------------------	

}




////////////////////////////////////////////////////////
///////////////End Move Into Functions//////////////////
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
///////////////GO STRAIGHT FUNCTIONS////////////////////
////////////////////////////////////////////////////////

void movestraight_3fork(int abc)//ORIGINAL FUNCTION
{
///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	init_upper_outer_LS_L(1);
	init_upper_outer_LS_R(1);	

	followline();

	disable_ALL_LS();
	init_outer_LS_R(1);
	init_outer_LS_L(1);

	while((outer_L != 1 && outer_R != 1) && PCIN&0x0C != 0x0C   )
	{		
		m_forward();
		for(beinchod=0;beinchod<5000;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<5000;beinchod++);
	}
//-------------------------------------

	printled(~0x00);
	disable_ALL_LS();	
	
	init_upper_outer_LS_L(4);
	init_upper_outer_LS_R(4);	
	init_outer_LS_L(4);
	init_outer_LS_R(4);

	
//-------------------------------------	

	followline_slowly_outof3way(5000,10000);


	disable_ALL_LS();

	init_outer_LS_L(1);
	init_outer_LS_R(1);
	//init_upper_outer_LS_R(1);
	//init_upper_outer_LS_L(1);
	

	followline_slowly(5000,10000);
	//followline_PDIN(5000,10000);//Not working
	
	disable_ALL_LS();

	followline_software_delay(abc);
	printled(~0x07);
	
}



void movestraight_3fork_short(int abc)//ORIGINAL FUNCTION
{
///////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	init_upper_outer_LS_L(1);
	init_upper_outer_LS_R(1);	

	followline();

	disable_ALL_LS();
	init_outer_LS_R(1);
	init_outer_LS_L(1);

	while((outer_L != 1 && outer_R != 1) && PCIN&0x0C != 0x0C   )
	{		
		m_forward();
		for(beinchod=0;beinchod<5000;beinchod++);
		m_stop();
		for(beinchod=0;beinchod<5000;beinchod++);
	}
//-------------------------------------

	printled(~0x00);
	disable_ALL_LS();	
	
	init_upper_outer_LS_L(4);
	init_upper_outer_LS_R(4);	
	init_outer_LS_L(4);
	init_outer_LS_R(4);

	
//-------------------------------------	

	followline_slowly_outof3way(5000,10000);


	disable_ALL_LS();

	//init_outer_LS_L(1);
	//in/it_outer_LS_R(1);
	init_upper_outer_LS_R(1);
	init_upper_outer_LS_L(1);
	

	followline_slowly(5000,10000);
	//followline_PDIN(5000,10000);//Not working
	
	disable_ALL_LS();

	followline_software_delay(abc);
		
}


void movestraight_through_fork (int abc)
{

//////// DISABLE ALL LS INTERRUPTS ////
	disable_ALL_LS();
///////////////////////////////////////

	init_outer_LS_L(2);
	init_outer_LS_R(2);
	followline();
	//	followline_slowly(5000,4000);
//-------------------------------------

	disable_ALL_LS();

	if(outer==1) 
		{
		snapleftfine_slowly(5000,10000);
		PAOUT = ~0x01;
		}
	else
		snaprightfine_slowly(5000,10000);
		PAOUT = ~0x02;
//-------------------------------------
	init_outer_LS_L(2);
	init_outer_LS_R(2);
	followline_slowly(5000,4000);
//-------------------------------------
	delay(5);
	init_upper_outer_LS_L(1);
	init_upper_outer_LS_R(1);
	followline();
//-------------------------------------
followline_software_delay(abc);
}


/*void if_robot_stopped(void)
{
	init_encoder_gpio();  // encoders initialised
	init_encoder_isr();
	previous_count = count-1; 
	while(previous_count!=count)
	{
		previous_count=count;
		for(beinchod=0;beinchod<1000;beinchod++);	
	}
	disable_encoder();

}*/



void straight_across_room(void)//Redefined from Original
{

///////// DISABLE ALL LS INTERRUPTS ////
followline_software_delay(60000);
	disable_ALL_LS();
///////////////////////////////////////

	init_upper_outer_LS_L(2);
	init_upper_outer_LS_R(2);
	
	followline_slowly(5000,10000);
//-------------------------------------
	delay(1);

	if (ls_status != LS_ALL)
		{	if(upper_outer_R > 0)			//right interrupt occured 
				{
				init_upper_outer_LS_R(2);
				snapright_slowly(5000,10000);
				disable_ALL_LS();
				snaprightfine_slowly(5000,5000);
				}
		}
	else
    	{
		if (upper_outer_L > 0 && upper_outer_R > 0)
  	    		{
				snaprightfine_slowly(5000,5000);
				}
		else if (upper_outer_L > 0)
				{
				snapleftfine_slowly(5000,10000);	
				}
		else if (upper_outer== 2)			//right interrupt occured 
				{
				init_upper_outer_LS_R(2);
				snapright_slowly(5000,10000);
				disable_ALL_LS();
				snaprightfine_slowly(5000,5000);
				}
		else snaprightfine_slowly(5000,10000);
		}
//-------------------------------------	
	snaprightfine_slowly_left(5000,10000);
//-------------------------------------	
	disable_ALL_LS();
	init_outer_LS_R(2);			//Init sensors navigate right curve
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}

	//followline_slowly(5000,4000);
//-------------------------------------	
	disable_ALL_LS();
	init_upper_outer_LS_L(2);
	snapleft_slowly(5000,10000);
	snapleftfine_slowly(5000,10000);
//-------------------------------------	
	disable_ALL_LS();	// jigFix
	init_outer_LS_R(2);
	isInterruptOccurred = FALSE;
		while(!isInterruptOccurred)	
		{
			m_forward();
			for(beinchod=0;beinchod<5000;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<5000;beinchod++);
		}
//-------------------------------------	
	disable_ALL_LS();
	snaprightfine_slowly(5000,10000);
//-------------------------------------
	disable_ALL_LS();

	followline_to_room(5000,2000);
}

////////////////////////////////////////////////////////
////////////END GO STRAIGHT FUNCTIONS///////////////////
////////////////////////////////////////////////////////


