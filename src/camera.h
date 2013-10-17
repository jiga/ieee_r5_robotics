
/*
----------------------------------------------------------------------------------------------------
Directed Reading Project 03/15/06

*/
				//	  {A,B,C,D}
int fakePosition[4] = {2,1,3,4};

void Delay(int time);
char GetData(void);
int color_detect(void);	


unsigned char buf[100];
unsigned char Data[44];
unsigned int counter,color[250];

unsigned int avg(unsigned int sum1, unsigned int max)
{
	unsigned int ret=0;
	unsigned int diff;
	diff = sum1;
	while(diff >= ret)
	{
		ret++;
		diff -=max;
	}

	if(diff > (max>>1))
	{
		ret++;	
	}
	
	return ret = sum1/max;
}

void init_camera(void)
{
/* Things I have found out about this program
	1)The AVRCAM requires a "\r" at the end of each message
	2)When using strcmp(), if it returns 0, the strings are equal
	3)Sometimes when a command is sent, it isn't picked up by the camera.
	  That is why I have while loops that keep sending the command until the
	  camera picks it up.
	4)When color tracking is enabled on the camera, the data is sent in HEX and
	  there are no spaces between the bytes.  So, a strcmp() can't be used because
	  the string will think the hex numbers stand for ascii values...I think.
*/
	do
	{
		printf("DT\r");
		scanf("%s",Data);
 	}while(strcmp("ACK",Data)!=0);		//wait for the ACK


	do
	{	
		printf("PG\r");
		scanf("%s",Data);
 	}while(strcmp("ACK",Data)!=0);		//wait for the ACK
/*
 	for (i=0;i<3;i++)
	    {
	    PAOUT = ~0x01;		//FLASHES on 1st LED only
        Delay();
		PAOUT = 0xFF;
		Delay();
		}	*/
	do
	{
		// practice room color map 
		printf("SM 0 32 32 16 16 16 80 192 192 128 128 128 0 0 0 0 0 128 128 144 48 48 96 64 64 0 0 0 0 0 0 0 0 192 224 176 16 16 0 0 0 0 0 0 0 0 0 0\r");
		// other color maps
		//printf("SM 0 0 0 0 0 32 32 176 144 208 64 64 0 0 0 0 0 128 0 0 0 0 16 16 80 64 64 32 32 32 0 0 0 192 64 0 32 32 32 16 16 16 0 0 0 0 0 0\r");
		//printf("SM 0 0 0 0 48 48 48 0 0 128 128 128 0 64 64 68 0 128 0 0 16 16 16 0 0 32 32 32 0 64 64 68 0 192 192 32 48 48 16 0 0 0 0 0 0 0 0 4\r");
		//printf("SM 0 0 0 0 48 48 48 0 0 128 128 128 0 64 64 68 0 128 0 0 16 16 16 0 0 32 32 32 0 64 64 68 0 192 192 32 48 48 16 0 0 0 0 0 0 0 0 4\r");
		//printf("SM 0 0 0 0 32 32 224 208 208 208 144 144 144 144 144 144 0 128 128 0 0 0 96 112 112 112 48 48 48 48 48 48 0 144 160 32 32 0 64 64 64 64 64 64 64 0 0 0\r");
		//printf("SM 0 0 0 0 32 32 224 208 208 208 208 144 144 144 144 144 0 128 128 0 0 0 96 112 112 112 112 48 48 48 48 48 0 144 176 32 32 0 64 64 64 64 64 64 64 0 0 0\r");
	    //  printf("SM 0 0 0 0 32 32 224 208 208 208 208 144 144 144 144 144 0 128 128 0 0 0 96 112 112 112 112 48 48 48 48 48 0 144 176 32 32 0 64 64 64 64 64 64 64 0 0 0\r");
		//printf("PG\r");
		scanf("%s",buf);
	}while(strcmp("ACK",buf)!=0);		//wait for the ACK


 /*	for (i=0;i<3;i++)
	    {
	    PAOUT = ~0x02;		//FLASHES on 1st LED only
        Delay();
		PAOUT = 0xFF;
		Delay();
		}	
*/
	
	
	do
	{
		printf("ET\r");
		scanf("%s",Data);
 	}while(strcmp("ACK",Data)!=0);		//wait for the ACK
 
}
//start
int color_detect(void)
{
	int ret = -1;
	int time=0;
	int Byte=0;
	int i,j;


	unsigned int sum1=0,avg1=0;
	unsigned int no_of_blobs=0;
	unsigned int max_blobs=0;

	time=5;
//	init_uart(_UART0, 18432000, 115200);      //Init the RS-232 with a 18.432 Mhz crystal for 115.2 K  
	PAADDR = 0x01;
	PACTL = 0x00;
  


  PAOUT = 0x00;

 /*	for (i=0;i<3;i++)
	    {
	    PAOUT = ~0x04;		//FLASHES on 1st LED only
        Delay();
				PAOUT = 0xFF;
		Delay();
		}	
*/

	max_blobs=no_of_blobs = 0;

	//float favg1=0.0;
	//Get 30 samples from the camera
	for (counter=0;counter<30;counter++)
	{

		i=1;
		while(getch()!=0x0A)	//wait for the beginning of a packet
			;

		Data[1] = getch(); 		// read no. of blobs
		no_of_blobs = Data[1];
		max_blobs +=no_of_blobs;
		do
		{//This routine assum1es no bytes are dropped/missed
			i++;
			Data[i]=getch();
		}while (Data[i]!=0xFF);		//Wait for end of packet
		for(j = 0 ; j < no_of_blobs; j++)
		{
			color[j+counter] = Data[2+j*5];	
			sum1 +=color[j+counter];
		}

/*		if (Data[2]==0x00)     // See's Green
			color[counter]=0;
		else if (Data[2]==0x01)  //See's Blue
			color[counter]=1;
		else if (Data[2]==0x02)  //See's Red
			color[counter]=2;
		else					//See's Yellow 
			color[counter]=3;
*/
	}

	//routine to find the average color seen during the thirty samples taken
	
	//avg1=0;


	// blue 3, yellow 2, 


/*	for (counter=0;counter<30;counter++)
	{
		
		sum1+=color[counter];

	}
*/
//	PAOUT = ~0x06;
//	Delay();
	//favg1 = (float)(sum1* 1.0) / max_blobs;
	avg1=sum1/max_blobs;//avg(sum1,max_blobs); ****************  changed on April 1

	ret = avg1;
	PAOUT = ~avg1;
	
	// reset 
	avg1 = sum1 = 0;

	/*
	if (sum1>=15 && sum1 <45)			//I changed these numbers (Jared)
		PAOUT = ~0x01;
	else if (sum1>=45 && sum1 <75)
		PAOUT = ~0x02;
	else if (sum1>=75 && sum1 < 105)
		PAOUT = ~0x04;
	else
		PAOUT = ~0x03;
	*/
/*	Delay();
	Delay();
	Delay();*/

	do
	{
		printf("DT\r");
		scanf("%s",Data);
 	}while(strcmp("ACK",Data)!=0);		//wait for the ACK

   	return ret;
}

void Delay(int time)
{
	int i,j;
	for (i =0;i<60000;i++)
	{
		for(j=0;j<time;j++)
		;
	}
 }


int fake_color_detect(void)
{
	static int fakeevent=0;
	PAOUT = 0x00;
//	Delay(10);
	return fakePosition[fakeevent++];
}

