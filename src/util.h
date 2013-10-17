/* 
 * util.h - some utility functions e.g. for debugging
 * Authors:
 *			Jignesh Patel <jkp34c@umkc.edu>
 *			Phaneesh Gujraj <pgxzd@umkc.edu>
 *
 * Date Created:	11/12/2005
 * Date Modified:	11/12/2005
 *
 */

 void printled(char);

 void printled(char data)
 {
 	PAOUT = data;
 }
