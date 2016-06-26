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
			printf("MODE: TEST MODE\n");
		}
		else if(strcmp((argv)[1], "direct") == 0)
		{
			printf("MODE: DIRECT MODE\n");
		}
		else if(strcmp((argv)[1], "headless") == 0)
		{
			printf("MODE: HEADLESS MODE\n");
		}
		else if(strcmp((argv)[1], "remote") == 0)
		{
			printf("MODE: REMOTE MODE\n");
		}
		else
		{
			printf("Choose between 'direct', 'headless', 'remote' and 'test'");
		}
	}
	return 0;
}
