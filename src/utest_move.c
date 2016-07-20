#include<stdio.h>
#include"move.h"
#include"init.h"

int main(void)
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
	if(!forward_set(83)) //MUST FAIL!
	{
		puts("forward_set(83) worked!");
		return 1;
	}
	init(0);
	puts("Unit test successfully finished.");
	return 0;
}
