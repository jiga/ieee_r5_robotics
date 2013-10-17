/*
 *  PathFinder.h - contains routines to find shortest paths from room to room
 *  Author: Jignesh Patel
 *
 */


#define ROOM_1	1
#define ROOM_2	2
#define ROOM_3	3
#define ROOM_4	4
#define ROOM_A	5
#define ROOM_B	6
#define ROOM_C	7
#define ROOM_D	8

volatile unsigned int currentRoom = ROOM_1; // currentRoom = {ROOM_1,ROOM_2,ROOM_3,ROOM_4,ROOM_A,ROOM_B,ROOM_C,ROOM_D}

volatile unsigned int destinationRoom = ROOM_A;

#define TASK_A 0x07
#define TASK_B 0x03
#define TASK_C 0x05
#define TASK_D 0x06

#define PT_ABCD 0x0F
#define PT_BCD 	0x07
#define PT_BC 	0x06
#define PT_BD	0x05
#define PT_B	0x04
#define PT_CD	0x03
#define PT_C	0x02
#define PT_D	0x01
#define PT_NULL	0x00

int pendingTask = PT_ABCD; // 

int currentTask = TASK_A; // used to mask pending Task 0x07- A, 0x03 - B, 0x05 - C, 0x06 - D
						
int startRoom,endRoom,targetRoom;
void move_room(int , int );
void jigSort(void);
void drop_can(void)
{
	open();
}
/////////////////////////////////////
// 		state machine for next shortest room
// 		getNextTarget[currentRoom][pendingTask]
// 		currentRoom = { 1, 2, 3, 4} i.e. all destination rooms
//		pendingTask = currentTask & taskFinished
// 		taskFinished = {TASK_A, TASK_B, TASK_C, TASK_D}
						// 0, 1 , 2 , 3 , 4 , 5 , 6 , 7 .
int getNextTarget[5][8] ={ 0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 	// room 0 - no such room
						   0,ROOM_D,ROOM_C,ROOM_C,ROOM_B,ROOM_B,ROOM_B,ROOM_B, 	// room 1
						   0,ROOM_D,ROOM_C,ROOM_C,ROOM_B,ROOM_B,ROOM_B,ROOM_B,	// room 2
						   0,ROOM_D,ROOM_C,ROOM_C,ROOM_B,ROOM_B,ROOM_B,ROOM_B,	// room 3
						   0,ROOM_D,ROOM_C,ROOM_D,ROOM_B,ROOM_D,ROOM_C,ROOM_D	// room 4
						 };

int getTask[4] = {TASK_A,TASK_B,TASK_C,TASK_D};

void jigSort()	//the awesomest function ever!!!!!!!!!!
{
	
	// initialize 
	pendingTask = PT_ABCD;
	startRoom = ROOM_1;
	targetRoom = ROOM_A;
	endRoom = ROOM_1; // this can be anything
	currentTask = TASK_A;
	drop_can();

	while(pendingTask)
	{
		int y=0;
		move_room(startRoom,targetRoom);
		
		find_can(300,50);
		grab_can(300,600);
		//Delay(30);
		endRoom = color_detect()+1; //fake_color_detect();
		//Delay(30);

		snapleftfine_slowly_All(5000,5000);
		init_upper_outer_LS_L(2);							
		snapleft_slowly(5000,5000);
		snapleftfine_slowly(5000,5000);

		move_room(targetRoom,endRoom);
		PAOUT = ~endRoom;
		//Delay(30);

		isInterruptOccurred = FALSE;
		y=0;
		while(y<=500)
		{
			m_forward();
			for(beinchod=0;beinchod<600;beinchod++);
			m_stop();
			for(beinchod=0;beinchod<300;beinchod++);
			y++;
		}
		m_stop();

		drop_can();
		//Delay(30);
		while(!ls_status)
			m_reverse();
		
		m_stop();

		snapleftfine_slowly_All(5000,5000);
		init_upper_outer_LS_L(2);							
		snapleft_slowly(5000,5000);
		snapleftfine_slowly(5000,5000);

		// fist task finished ! good work so far
		// now try for another task
		pendingTask &= currentTask;
		targetRoom = getNextTarget[endRoom][pendingTask];
		currentTask = getTask[targetRoom - 5];
		startRoom = endRoom;
	}
}

#define MOVE_1_TO_A	1
#define MOVE_1_TO_B	2
#define MOVE_1_TO_C 3
#define MOVE_1_TO_D 4
#define MOVE_2_TO_A	5
#define MOVE_2_TO_B	6
#define MOVE_2_TO_C	7
#define MOVE_2_TO_D	8
#define MOVE_3_TO_A	9
#define MOVE_3_TO_B	10
#define MOVE_3_TO_C	11
#define MOVE_3_TO_D	12
#define MOVE_4_TO_A	13
#define MOVE_4_TO_B	14
#define MOVE_4_TO_C	15
#define MOVE_4_TO_D	16
#define MOVE_A_TO_1	17
#define MOVE_A_TO_2	18
#define MOVE_A_TO_3	19
#define MOVE_A_TO_4	20
#define MOVE_B_TO_1	21
#define MOVE_B_TO_2	22
#define MOVE_B_TO_3	23
#define MOVE_B_TO_4	24
#define MOVE_C_TO_1	25
#define MOVE_C_TO_2	26
#define MOVE_C_TO_3	27
#define MOVE_C_TO_4	28
#define MOVE_D_TO_1	29
#define MOVE_D_TO_2	30
#define MOVE_D_TO_3	31
#define MOVE_D_TO_4	32

////////////////////////////////////////////////////
//	getNavigation will let you know which sets
//	of functions to call for moving room to room
//	getNavigation[src][dst], 
//		where src = dest = {ROOM_1,ROOM_2,ROOM_3,ROOM_4,ROOM_A,ROOM_B,ROOM_C,ROOM_D}
//							0, 1 , 2 , 3 , 4 , A , B , C , D ,
int getNavigation[9][9] = {	0, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,	// room 0 - no such room
							0, 0 , 0 , 0 , 0 , MOVE_1_TO_A , MOVE_1_TO_B , MOVE_1_TO_C , MOVE_1_TO_D ,	// room 1 - no such room
							0, 0 , 0 , 0 , 0 , MOVE_2_TO_A , MOVE_2_TO_B , MOVE_2_TO_C , MOVE_2_TO_D ,	// room 2 - no such room
							0, 0 , 0 , 0 , 0 , MOVE_3_TO_A , MOVE_3_TO_B , MOVE_3_TO_C , MOVE_3_TO_D ,	// room 3 - no such room
							0, 0 , 0 , 0 , 0 , MOVE_4_TO_A , MOVE_4_TO_B , MOVE_4_TO_C , MOVE_4_TO_D ,	// room 4 - no such room
							0, MOVE_A_TO_1 , MOVE_A_TO_2 , MOVE_A_TO_3 , MOVE_A_TO_4 , 0 , 0 , 0 , 0 ,	// room A - no such room
							0, MOVE_B_TO_1 , MOVE_B_TO_2 , MOVE_B_TO_3 , MOVE_B_TO_4 , 0 , 0 , 0 , 0 ,	// room B - no such room
							0, MOVE_C_TO_1 , MOVE_C_TO_2 , MOVE_C_TO_3 , MOVE_C_TO_4 , 0 , 0 , 0 , 0 ,	// room C - no such room
							0, MOVE_D_TO_1 , MOVE_D_TO_2 , MOVE_D_TO_3 , MOVE_D_TO_4 , 0 , 0 , 0 , 0 	// room D - no such room
						  };

void move_room(int src, int dst)
{
	switch(getNavigation[src][dst])
	{
		case MOVE_1_TO_A:
		case MOVE_D_TO_4:
			Room_1_to_A();
			break;
		case MOVE_1_TO_B:
			Room_1_to_B();
			break;
		case MOVE_1_TO_C:
			Room_1_to_C();
			break;
		case MOVE_1_TO_D:
			Room_1_to_D();
			break;
		case MOVE_2_TO_B:
		case MOVE_3_TO_C:
		case MOVE_B_TO_2:
		case MOVE_C_TO_3:
			Room_2_to_B();
			break;
		case MOVE_2_TO_C:
			Room_2_to_C();
			break;
		case MOVE_2_TO_D:
			Room_2_to_C();
			break;
		case MOVE_3_TO_B:
			Room_3_to_B();
			break;
		case MOVE_3_TO_D:
			Room_3_to_D();
			break;
		case MOVE_4_TO_B:
			Room_4_to_B();
			break;
		case MOVE_4_TO_C:
			Room_4_to_C();
			break;
		case MOVE_A_TO_1:
		case MOVE_4_TO_D:
			Room_A_to_1();
			break;
		case MOVE_A_TO_2:
			Room_A_to_2();
			break;
		case MOVE_A_TO_3:
			Room_A_to_3();
			break;
		case MOVE_A_TO_4:
			Room_A_to_4();
			break;
		case MOVE_B_TO_1:
			Room_B_to_1();
			break;
		case MOVE_B_TO_3:
			Room_B_to_3();
			break;
		case MOVE_B_TO_4:
			Room_B_to_4();
			break;
		case MOVE_C_TO_1:
			Room_C_to_1();
			break;
		case MOVE_C_TO_2:
			Room_C_to_2();
			break;
		case MOVE_C_TO_4:
			Room_C_to_4();
			break;
		case MOVE_D_TO_1:
			Room_D_to_1();
			break;
		case MOVE_D_TO_2:
			Room_D_to_2();
			break;
		case MOVE_D_TO_3:
			Room_D_to_3();
			break;
		default:
			break;
			// you don't have to do anything here ...
	}
}

