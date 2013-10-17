
void moveoutof_outerroom_turnright(void);
void moveoutof_outerroom_turnleft(void);
void moveoutof_innerroom_turnright(void);
void moveoutof_innerroom_turnright_short(void);
void moveoutof_innerroom_turnright_sp(void);
void moveoutof_innerroom_turnleft(void);
void moveoutof_innerroom_turnleft_short(void);
void moveinto_outerroom_turnright(void);
void moveinto_outerroom_turnleft(void);
void moveinto_innerroom_turnright(void);
void moveinto_innerroom_turnleft(void);
void movestraight_3fork(int);
void movestraight_3fork_short(int);
void moveoutof_outerroom_turnright_sp(void);
void moveoutof_outerroom_turnleft_sp(void);
void straight_across_room(void);

void movestraight_through_fork(int);

void Room_A_to_1(void);
void Room_A_to_2(void);
void Room_A_to_3(void);
void Room_A_to_4(void);
void Room_B_to_1(void);
void Room_B_to_2(void);
void Room_B_to_3(void);
void Room_B_to_4(void);
void Room_C_to_1(void);
void Room_C_to_2(void);

void Room_C_to_3(void);
void Room_C_to_4(void);
void Room_D_to_1(void);
void Room_D_to_2(void);
void Room_D_to_3(void);
void Room_D_to_4(void);

void delay (int);

void Room_1_to_A() // Same as D to 4
{
	disable_ALL_LS();
	init_outer_LS_R(2);
	init_outer_LS_L(2);	
	followline();
	
	if (outer_R>0)
	{
	disable_ALL_LS();
	init_upper_outer_LS_L(2);
	snapright_slowly(5000,10000);
	}

	disable_ALL_LS();
	init_upper_outer_LS_L(2);
	followline_slowly(5000,5000);

	disable_ALL_LS();
	followline_to_room(5000,5000);

}


void Room_A_to_1() // Same as 4 to D
{
	disable_ALL_LS();
	init_outer_LS_R(2);
	init_outer_LS_L(2);	
	followline();
	
	if (outer_L>0)
	{
	disable_ALL_LS();
	init_upper_outer_LS_R(2);
	snapleft_slowly(5000,10000);
	}

	disable_ALL_LS();
	init_upper_outer_LS_R(2);
	followline_slowly(5000,5000);

	disable_ALL_LS();
	followline_to_room(5000,5000);
}

void Room_A_to_2() 
{
	moveoutof_outerroom_turnright_sp();
	printled(~0x07);
	delay(3);
	moveinto_innerroom_turnleft();

}

void Room_2_to_A() 
{
	moveoutof_innerroom_turnright();
	printled(~0x07);
	delay(3);
	moveinto_outerroom_turnleft();

}

void Room_A_to_3()
{
	moveoutof_outerroom_turnright_sp();
	delay(3);
	movestraight_3fork(10000);
	delay(3);
	moveinto_innerroom_turnleft();

}

void Room_A_to_4()
{
	moveoutof_outerroom_turnright_sp();
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	moveinto_outerroom_turnleft();
}

void Room_4_to_A()
{
	moveoutof_outerroom_turnright();
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	moveinto_outerroom_turnleft();
}


void Room_B_to_1()
{
	moveoutof_innerroom_turnleft();
	delay(3);
	moveinto_outerroom_turnright();
}

void Room_1_to_B()
{
	moveoutof_outerroom_turnleft_sp();
	delay(3);
	moveinto_innerroom_turnright();
}

void Room_B_to_2()
{
straight_across_room();
}


void Room_2_to_B()
{
straight_across_room();
}

void Room_B_to_3()
{
	moveoutof_innerroom_turnright();
	delay(3);
	moveinto_innerroom_turnleft();
}

void Room_3_to_B()
{
	moveoutof_innerroom_turnright();
	delay(3);
	moveinto_innerroom_turnleft();
}

void Room_B_to_4()
{
	moveoutof_innerroom_turnright();
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	moveinto_outerroom_turnleft();
}

void Room_4_to_B()
{
	moveoutof_outerroom_turnright();
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	moveinto_innerroom_turnleft();
}



void Room_C_to_1()
{
	moveoutof_innerroom_turnleft();
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	moveinto_outerroom_turnright();
}

void Room_1_to_C()
{
	moveoutof_outerroom_turnleft_sp();
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	moveinto_innerroom_turnright();
}

void Room_C_to_2()
{
	moveoutof_innerroom_turnleft();
	delay(3);
	moveinto_innerroom_turnright();
}

void Room_2_to_C()
{
	moveoutof_innerroom_turnleft();
	delay(3);
	moveinto_innerroom_turnright();
}

void Room_C_to_3()
{
straight_across_room();
}

void Room_3_to_C()
{
straight_across_room();
}

void Room_C_to_4()
{
	moveoutof_innerroom_turnright();
	delay(3);
	moveinto_outerroom_turnleft();
}

void Room_4_to_C()
{
	moveoutof_outerroom_turnright();
	delay(3);
	moveinto_innerroom_turnleft();
}


void Room_D_to_1()
{
	moveoutof_outerroom_turnleft();
	delay(3);
	movestraight_3fork_short(9000);
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	
	moveinto_outerroom_turnright();
}

void Room_1_to_D()
{
	moveoutof_outerroom_turnleft_sp();
	delay(3);
	movestraight_3fork_short(9000);
	delay(3);
	movestraight_3fork(14000);
	delay(3);
	moveinto_outerroom_turnright();
}

void Room_D_to_2()//Same as 1 to C
{
	moveoutof_outerroom_turnleft();
	delay(3);
	movestraight_3fork_short(9000);
	delay(3);
	moveinto_innerroom_turnright();
}

void Room_2_to_D()//Same as 1 to C
{
	moveoutof_innerroom_turnleft();
	delay(3);
	movestraight_3fork_short(9000);
	delay(3);
	moveinto_outerroom_turnright();
}


void Room_D_to_3()//Same as 1 to B
{
	moveoutof_outerroom_turnleft();
	delay(3);
	moveinto_innerroom_turnright();
}

void Room_3_to_D()//Same as 1 to B
{
	moveoutof_innerroom_turnleft();
	delay(3);
	moveinto_outerroom_turnright();
}


void Room_D_to_4()//Same as 1 to A
{
	int u = 40000;
	
	disable_ALL_LS();

	init_upper_outer_LS_L(1);
	init_upper_outer_LS_R(1);	

	followline();

	disable_ALL_LS();
	init_outer_LS_R(1);
	init_outer_LS_L(1);

	while(outer_L != 1 && PCIN&0x0C != 0x0C)
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

	followline_slowly_straight_across_L(5000,10000);

	disable_ALL_LS();

	followline_software_delay(60000);
	followline_software_delay(60000);

	init_upper_outer_LS_R(1);
	init_upper_outer_LS_L(1);

	followline_slowly(5000,5000);
	
	disable_ALL_LS();

}



void delay (int xyz)
{
for(beinchod=0;beinchod<10000;beinchod++)
		for (xyz=0;xyz<20;xyz++);
}
