`/* 
 * linesensor.h - line sensor driver
 * Authors:
 *			Jignesh Patel <jkp34c@umkc.edu>
 *			Phaneesh Gujraj <pgxzd@umkc.edu>
 *
 * Date Created:	11/12/2005
 * Date Modified:	Thursday 03/02/2006
 *
 */

 #define LS_MASK 0x07

 #define LS_NONE 0x00
 #define LS_C 0x05
 #define LS_L 0x03
 #define LS_L1 0x01
 #define LS_R 0x06
 #define LS_R1 0x04
 #define LS_ALL 0x07 // all leds on - forward
 #define LS_LR 0x02 // supposedly stop condition

 #define ls_status PEIN
 
 void ls_init(void);
 //volatile char ls_status; // line sensor status bits
 
 void ls_init(void)
 {
 	PEADDR 	= 0x01;     // PE Data Dir = input: Takes LINE SENSOR inputs on PE0,PE1,PE2
  	PECTL 	= 0xFF;     // PE input Ctrl = Pin 0
						//PE0 - Right Detector
 					    //PE1 - Center Detector
						//PE2 - Left Detector
	isInterruptOccurred = FALSE;
 }

