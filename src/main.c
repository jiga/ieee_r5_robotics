/* Main.c - robot main program 
 *		Authors:
 * 			Dhaval Ghody <dagf98@umkc.edu>
 *			Jignesh Patel <jkp34c@umkc.edu>
 *	         
 *
 * Date Created:	11/05/2005
 * Date Modified:	Thursday 03/02/2006
 */

#include <ez8.h>
#include <defines.h>
#include <stdio.h>                          //Standard IO library
#include <sio.h>                            //Non standard library
#include <string.h>                        //Library for string functions (strcpy())
#include "encoder.h"
#include "motor.h"
#include "interrupts.h"
#include "util.h"
#include "linesensor.h"
#include "navigator.h"
#include "Roomfunctions.h"
#include "camera.h"
#include "armpit.h"
#include "distancesensor.h"
#include "pathfinder.h" 		// contains shortest path functions...
#include "timer.h"

void init_components(void);
void testRoutines(void);

void main()
{
	init_uart(_UART0, 18432000, 115200);	// WARNING: DO NOT REMOVE THIS STATEMENT
	init_components();						// WARNING: DO NOT REMOVE THIS STATEMENT
	
	//jigSort();

	testRoutines();
}


void init_components(void)
{
	DI();					// Disable ALL Interrupts
	PAADDR = 0x01; 			// FOR TEST LEDs Port A Address reg accessed // 0x01 => Data Direction sub-register 
	PACTL &= 0x00; 			// FOR TEST LEDs Port A Control reg sets all the bits as output

	PDADDR 	= 0x01;     	// PD Data Dir = input
  	PDCTL 	= 0xFF;     	// PD input Ctrl All pins

	PCADDR 	= 0x01;     	// PD Data Dir = input
  	PCCTL 	= 0xFF;     	// PD input Ctrl All pins
	
	ls_init();				// Initialize line Sensors
	
	PGADDR 	= 0x01;     	// PG Data Dir = output
  	PGCTL 	= 0x00;     	// PG output Ctrl All pins

	PHADDR 	= 0x01;     	// PG Data Dir = output
  	PHCTL 	= 0xFF;     	// PG input Ctrl All pins

	m_init();				// Initialize line Motors

	init_gpio();
    init_adc();

	PAOUT = 0x00;

	i=0;					//for Encoders
	count=0;				//for Encoders

	count_LS_L=0;			//For the Line Sensor Interrupts
 	count_LS_R=0; 
	count_upper_LS_R=0; 
	count_upper_LS_L=0;
	new_count_LS_L=2; 
	new_count_LS_R=2; 
	new_count_upper_LS_L=2;
 	new_count_upper_LS_R=2;		//

   	upper_outer=0;
	upper_outer_L=0;
	upper_outer_R=0;
	
	outer=0;
	outer_R=0;
	outer_L=0;
	
	init_servo();
	open();
//	init_camera();

	EI();

	
}


void testRoutines(void)
{
/*	followline_to_room(5000,5000);
	find_can(300,50);
	grab_can(300,600);
	//Delay(30);
	endRoom = color_detect()+1; //fake_color_detect();
		//Delay(30);
	while(1);
*/
//	color_detect();
//	while(1);
/*	ADCCTL |= 0x80;				//start finding object
	while(1);
*/
	/*while(1)
	{
	open();
	delay(30);
		close();
	delay(30);
	}
	
	*/		
	
	/*		Room_A_to_1();
	
			drop_can();
			
			find_can(300,50);
			delay(15);
			grab_can(300,600);
			delay(15);
	
			snapleftfine_slowly_All(5000,5000);
			init_upper_outer_LS_L(2);							
			snapleft_slowly(5000,5000);
			snapleftfine_slowly(5000,5000);
	
			Room_A_to_4();
	
			open();
	*/
		
	
	//Room_B_to_2();
	
	
				
	
	
	/*	PAOUT=~fake_color_detect();
		Delay(30);
		PAOUT=~fake_color_detect();
		Delay(30);
		PAOUT=~fake_color_detect();
		Delay(30);
		PAOUT=~fake_color_detect();
	*/
	
	//straight_across_room();
	//moveoutof_outerroom_turnright_sp();
	//moveoutof_outerroom_turnleft_sp();
	//moveoutof_outerroom_turnright();
	//moveoutof_outerroom_turnleft();
	
	moveoutof_innerroom_turnright_sp();
	//moveoutof_innerroom_turnleft_sp();
	//moveoutof_innerroom_turnleft();
	//moveoutof_innerroom_turnright();
	
	//moveinto_outerroom_turnleft();
	
	//moveinto_outerroom_turnright();
	
	
	//moveinto_innerroom_turnright();
	//moveinto_innerroom_turnleft();           //   TEST FUNCTIONS
	

}
