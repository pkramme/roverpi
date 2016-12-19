#include<stdio.h>
#include<string.h>
#include"argument.h"
#include"test.h"
#include"headless.h"
#include"directinput.h"

/*	Function:	main
 *	Type:		int
 *	Return:		0 = success
 *			1 = failure
 *	Parameters:	argc(int), argv(array char)
 *	Description:	Executes different modes based on parameter flags
 */

int main(int argc, char *argv[])
{
	char helpmessage[] = "Following modes are available:\n--direct / -d for direct control over SSH\n--headless / -h for use with client\n--test / -t for testing";

	puts("RoverPi Software");
	puts("Checkout project at https://github.com/paulkramme/roverpi");
	puts("(C) 2016 Paul Kramme\nDistributed under MIT License");
#ifdef DEBUG
	puts(" ______   _______  _______  __   __  _______  __   __  _______  ______   _______ ");
	puts("|      | |       ||  _    ||  | |  ||       ||  |_|  ||       ||      | |       |");
	puts("|  _    ||    ___|| |_|   ||  | |  ||    ___||       ||   _   ||  _    ||    ___|");
	puts("| | |   ||   |___ |       ||  |_|  ||   | __ |       ||  | |  || | |   ||   |___ ");
	puts("| |_|   ||    ___||  _   | |       ||   ||  ||       ||  |_|  || |_|   ||    ___|");
	puts("|       ||   |___ | |_|   ||       ||   |_| || ||_|| ||       ||       ||   |___ ");
	puts("|______| |_______||_______||_______||_______||_|   |_||_______||______| |_______|");
#endif
	if(argc < 2 || argc > 3)
	{
		puts("Insufficient arguments.");
		printf("USAGE: %s mode\n", argv[0]);
		puts(helpmessage);
		return 1;
	}
	else
	{
		/*global usability as arg1*/
		strcpy(arg1, argv[1]);

		/*
		TEST MODE ARG LINK
		*/
		if(strcmp(arg1, arg_test) == 0)
		{
			test_init();
		}
		else if(strcmp(arg1, arg_test_short) == 0)
		{
			test_init();
		}

		/*
		DIRECT MODE ARG LINK
		*/
		else if(strcmp(arg1, arg_direct) == 0)
		{
			input();
		}
		else if(strcmp(arg1, arg_direct_short) == 0)
		{
			input();
		}
		
		/*
		HEADLESS MODE ARG LINK
		*/
		else if(strcmp(arg1, arg_headless) == 0)
		{
			puts("This mode is not fully supported.");
			server();
		}
		else if(strcmp(arg1, arg_headless_short) == 0)
		{
			server();
		}

		else
		{
			puts(helpmessage);
		}
	}
	return 0;
}

