#include<stdio.h>
#include"api/move.h"
#include"api/init.h"

int unittest_move_forward(void)
{
	init(1);
	if(forward_set(1))
	{
		puts("forward_set(1) failed.");
		return 1;
	}
	if(forward_set(0))
	{
		puts("forward_set(0) failed.");
		return 1;
	}
	if(!forward_set(83)) /*MUST FAIL!*/
	{
		return 1;
	}
	init(0);
	return 0;
}

int unittest_move_left(void)
{
	init(1);
	if(left_set(1))
	{
		return 1;
	}
	if(left_set(1))
	{
		return 1;
	}
	if(!left_set(84)) /*Must fail*/
	{
		return 1;
	}
	init(0);
	return 0;
}

int unittest_move_right(void)
{
	init(1);
	if(right_set(1))
	{
		return 1;
	}
	if(right_set(0))
	{
		return 1;
	}
	if(!right_set(298))
	{
		return 1;
	}
	init(0);
}

int unittest_move_backward(void)
{
	init(1);
	if(backward_set(1))
	{
		return 1;
	}
	if(backward_set(0))
	{
		return 1;
	}
	if(!backward_set(9839))
	{
		return 1;
	}
	init(0);
}
