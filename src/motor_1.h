/* 
 * Motor Driver: This module sends corresponding output
 * to motor
 * Authors:
 *			Jignesh Patel <jkp34c@umkc.edu>
 *			Phaneesh Gujraj <pgxzd@umkc.edu>
 *
 * Date Created:	11/12/2005
 * Date Modified:	11/12/2005
 *
 */
/*	
	 Right    Left
	PF7	PF6	PF5	PF4		HEX		Comments
	 0   0  0   0		0F		Dynamic brake L & R
	 1	 1  1   1		FF		Dynamic brake L & R
	 0   0  1   1		3F		Dynamic brake L & R
	 1	 1  0   0		CF		Dynamic brake L & R

	 0   1   0   1		5F		Reverse	
	 1	 0   1   0 		AF		Forward
	 0   1   1   0      6F		Right Turn
	 1   0   0   1		9F		Left Turn
	 
	 1	 1	 0   1		DF		Right Motor Off, Left motor Reverse
	 0	 1	 1	 1      7F		Left Motor Off, Right motor Reverse	
	 1	 1	 1	 0		EF		Right Motor Off, Left motor Forward
	 1	 0	 1	 1      BF		Left Motor Off, Right motor Forward

	 0	 0	 0   1		1F		Right Motor Off, Left motor Reverse
	 0	 1	 0	 0      4F		Left Motor Off, Right motor Reverse	
	 0	 0	 1	 0		2F		Right Motor Off, Left motor Forward
	 1	 0	 0	 0      8F		Left Motor Off, Right motor Forward
*/

 void m_init()
 {
	PFADDR = 0x01;				// PF Data Dir = output: Gives output to H bridge on High Byte 
	PFCTL &= 0x00;		 		// PF output Ctrl = Pin 0
								// PF7,PF6 - Right Motor Control 
 	PGADDR = 0x01;	    		// PF5,PF4 - Left Motor Control
	PGCTL &= 0x00;

	PGOUT = 0xFF ;
 }
	

////////////////// MOTOR FUNCTIONS //////////////////////////////

 void m_forward()
 {
	PGOUT = 0xFF;
 	PFOUT = 0xAF; 				
 }

 void m_reverse()
 {
 	PGOUT = 0xFF ;
 	PFOUT = 0x5F;	
 }

 void m_turnleft()
 {
 	PGOUT = 0xFF ;
 	PFOUT = 0x9F;
 }

 void m_turnright()
 {
 	PGOUT = 0xFF ;
 	PFOUT = 0x6F;
 }

 void m_stop()
 {
 int timepass;
 	PGOUT = 0x00;
 	PFOUT = 0xFF;
	for(timepass=0;timepass<1000;timepass++);  
 }

 //////////////////////////////////////////////////////////////////////
