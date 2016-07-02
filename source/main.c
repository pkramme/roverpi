#include<stdio.h>
#include<string.h>
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
		/*
		TEST MODE ARG LINK
		*/
		if(strcmp((argv)[1], "--test") == 0)
		{
			printf("MODE: TEST MODE\n");
			/*
			if(strcmp((argv)[2], "override") == 0)
			{
				test();
			}
			else
			{
				testinit();
			}
			*/
			testinit(); //REMOVE IF ABOVE BLOCK IS UNCOMMENTED!
		}
		else if(strcmp((argv)[1], "-t") == 0)
		{
			printf("MODE: TEST MODE\n");
			testinit();
		}

		/*
		DIRECT MODE ARG LINK
		*/
		else if(strcmp((argv)[1], "--direct") == 0)
		{
			printf("MODE: DIRECT MODE\n");
		}
		else if(strcmp((argv)[1], "-d") == 0)
		{
			printf("MODE: DIRECT MODE\n");
		}
		
		/*
		HEADLESS MODE ARG LINK
		*/
		else if(strcmp((argv)[1], "--headless") == 0)
		{
			printf("MODE: HEADLESS MODE\n");
		}
		else if(strcmp((argv)[1], "-h") == 0)
		{
			printf("MODE: HEADLESS MODE\n");
		}

		/*
		REMOTE MODE ARG LINK
		*/
		else if(strcmp((argv)[1], "--remote") == 0)
		{
			printf("MODE: REMOTE MODE\n");
		}
		else if(strcmp((argv)[1], "-r") == 0)
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
