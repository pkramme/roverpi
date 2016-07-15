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
#include"directinput.h"

int main(int argc, char *argv[])
{
	puts("RoverPi Software");
	puts("Checkout project at https://github.com/paulkramme/roverpi");
	puts("(C) 2016 Paul Kramme\nDistributed under MIT License");
	puts("Read License in LICENSE.md or at");
	puts("https://opensource.org/license/MIT");
	if(BCM2835_DEBUG_MODE_SWITCH)
	{
		puts("\n//////////////////////////////////////////");
		puts("WARNING: RoverPi is running in DEBUG MODE.");
		puts("//////////////////////////////////////////\n");
	}
	if(argc < 2 || argc > 3)
	{
		puts("Insufficient arguments.");
		printf("\n	USAGE: %s mode\n\n", argv[0]);
		puts("Following modes are possible:");
		puts(" --direct / -d for SSH controll");
		puts(" --headless / -h for use with client");
		puts(" --test / -t for testing the pins");
		return 1;
	}
	else
	{
		strcpy(arg1, argv[1]);	/*copy string to arguments.h for global usability*/
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
			server();
		}
		else if(strcmp(arg1, arg_headless_short) == 0)
		{
			server();
		}

		else
		{
			puts("Choose between modes");
			puts("--direct / -d");
			puts("--headless / -h");
			puts("--test / -t");
		}
	}
	return 0;
}

