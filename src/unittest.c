#include<stdio.h> //unnecessary but included

#include"unittest_move.h"

int main(void)
{
	if(unittest_move_forward())
	{
		puts("utest_move_f fail.");
		return 1;
	}
	else
	{
		puts("utest_move_f success.");
	}
	if(unittest_move_right())
	{
		puts("utest_move_r fail.");
		return 1;
	}
	else
	{
		puts("utest_move_r success.");
	}
	if(unittest_move_left())
	{
		puts("utest_move_l fail.");
		return 1;
	}
	else
	{
		puts("utest_move_l success.");
	}
	if(unittest_move_backward())
	{
		puts("utest_move_b fail.");
		return 1;
	}
	else
	{
		puts("utest_move_b success");
	}
	return 0;
}

