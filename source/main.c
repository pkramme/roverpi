#include<stdio.h>
#include<string.h>
#include"argument.h"
#include"test.h"
#include"directmode.h"

int main(int argc, char *argv[])
{
	printf("RoverPi Software v2\n");
	if(argc != 2)
	{
		printf("USAGE: %s mode\n", argv[0]);
		return 1;
	}
	else
	{
		strcpy(arg1, argv[1]);
		/*
		TEST MODE ARG LINK
		*/
		if(strcmp(arg1, arg_test) == 0)
		{
			printf("MODE: TEST MODE\n");
			testinit();
		}
		else if(strcmp((argv)[1], arg_test_short) == 0)
		{
			printf("MODE: TEST MODE\n");
			testinit();
		}

		/*
		DIRECT MODE ARG LINK
		*/
		else if(strcmp((argv)[1], arg_direct) == 0)
		{
			printf("MODE: DIRECT MODE\n");
			direct_init();
		}
		else if(strcmp((argv)[1], arg_direct_short) == 0)
		{
			printf("MODE: DIRECT MODE\n");
			direct_init();
		}
		
		/*
		HEADLESS MODE ARG LINK
		*/
		else if(strcmp((argv)[1], arg_headless) == 0)
		{
			printf("MODE: HEADLESS MODE\n");
		}
		else if(strcmp((argv)[1], arg_headless_short) == 0)
		{
			printf("MODE: HEADLESS MODE\n");
		}

		/*
		REMOTE MODE ARG LINK
		*/
		else if(strcmp((argv)[1], arg_remote) == 0)
		{
			printf("MODE: REMOTE MODE\n");
		}
		else if(strcmp((argv)[1], arg_remote_short) == 0)
		{
			printf("MODE: REMOTE MODE\n");
		}

		/*
		HELP MESSAGE
		*/
		else if(strcmp((argv)[1], "--help") == 0)
		{
			printf("USAGE: %s mode\n\nDirect mode: Same as in v1\nHeadless mode: REPLACE\nRemote mode: REPLACE\nTest mode: REPLACE\n", argv[0]);
		}
		else
		{
			printf("Choose between 'direct', 'headless', 'remote' and 'test'\n");
		}
	}
	return 0;
}
