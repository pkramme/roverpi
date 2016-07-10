/*
The MIT License (MIT)

Copyright (c) 2016 Paul Kramme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include<stdio.h>
#include<string.h>
#include"argument.h"
#include"test.h"
#include"headless.h"
#include"input.h"

int main(int argc, char *argv[])
{
	printf("RoverPi Software\n");
	printf("(C) 2016 Paul Kramme\nDistributed under MIT License\n");
	printf("Read License in LICENSE.md or at\n");
	printf("https://opensource.org/license/MIT\n");
	if(BCM2835_DEBUG_MODE_SWITCH)
	{
		printf("\n//////////////////////////////////////////\n");
		printf("WARNING: RoverPi is running in DEBUG MODE.\n");
		printf("//////////////////////////////////////////\n\n");
	}
	if(argc < 2)
	{
		printf("Not enough arguments given.\n");
		printf("\n	USAGE: %s mode\n\n", argv[0]);
		return 1;
	}
	else if(argc > 3)
	{
		printf("Too much arguments given.\n");
		printf("\n	USAGE: %s mode\n\n", argv[0]);
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
			printf("TEST MODE\n");
			test_init();
		}
		else if(strcmp(arg1, arg_test_short) == 0)
		{
			printf("TEST MODE\n");
			test_init();
		}

		/*
		DIRECT MODE ARG LINK
		*/
		else if(strcmp(arg1, arg_direct) == 0)
		{
			printf("DIRECT MODE\n");
			input(1);
		}
		else if(strcmp(arg1, arg_direct_short) == 0)
		{
			printf("DIRECT MODE\n");
			input(1);
		}
		
		/*
		HEADLESS MODE ARG LINK
		*/
		else if(strcmp(arg1, arg_headless) == 0)
		{
			printf("HEADLESS MODE\n");
			server();
		}
		else if(strcmp(arg1, arg_headless_short) == 0)
		{
			printf("HEADLESS MODE\n");
			server();
		}

		/*
		REMOTE MODE ARG LINK
		*/
		else if(strcmp(arg1, arg_remote) == 0)
		{
			printf("REMOTE MODE has not been implemented yet.\n");
		}
		else if(strcmp(arg1, arg_remote_short) == 0)
		{
			printf("REMOTE MODE has not been implemented yet.\n");
		}


		else
		{
			printf("Choose between 'direct', 'headless', 'remote' and 'test'\n");
		}
	}
	return 0;
}
