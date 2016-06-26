#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	printf("RoverPi Software v2\n");
	if(argc != 2)
	{
		printf("USAGE: %s mode\n", argv[1]);
		return 1;
	}
	else
	{	
		if(strcmp((argv)[1], "test") == 0)
		{
			printf("TEST MODE\n");
		}
		else if(strcmp((argv)[1], "direct") == 0)
		{
			printf("DIRECT MODE\n");
		}
		else if(strcmp((argv)[1], "headless") == 0)
		{
			printf("HEADLESS MODE\n");
		}
		else
		{
			printf("choose a mode");
		}
	}
	return 0;
}
