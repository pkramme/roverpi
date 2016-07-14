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
#include"directinput.h"

int input(void)
{
	printf("---DIRECT MODE---\n");
	bcm2835_set_debug(BCM2835_DEBUG_MODE_SWITCH);
	init(1);
	int input;
	while(1)
	{
		input = getch();
		switch(input)
		{
			case 'w':
			{
				if(PROTECT && forward_status() == 0)
				{
					backward_set(0);
					left_set(0);
					right_set(0);
					forward_set(2);
				}
				else
				{
					forward_set(2);
				}
				switch(forward_status())
				{
					case 0:
						printf("forward low\n");
						break;
					case 1:
						printf("forward high\n");
						break;
				}
				break;
			}
			case 'a':
			{
				if(PROTECT && left_status() == 0)
				{
					backward_set(0);
					forward_set(0);
					right_set(0);
					left_set(2);
				}
				else
				{
					left_set(2);
				}
				switch(left_status())
				{
					case 0:
						printf("left low\n");
						break;
					case 1:
						printf("left high\n");
						break;
				}
				break;
			}
			case 's':
			{
				if(PROTECT && backward_status() == 0)
				{
					forward_set(0);
					left_set(0);
					right_set(0);
					backward_set(2);
				}
				else
				{
					backward_set(2);
				}
				switch(backward_status())
				{
					case 0:
						printf("backward low\n");
						break;
					case 1:
						printf("backward high\n");
						break;
				}
				break;
			}
			case 'd':
			{
				if(PROTECT && right_status() == 0)
				{
					forward_set(0);
					backward_set(0);
					left_set(0);
					right_set(2);
				}
				else
				{
					right_set(2);
				}
				switch(right_status())
				{
					case 0:
						printf("right low\n");
						break;
					case 1:
						printf("right high\n");
						break;
				}
				break;
			}
			case 'r':
				headlight_set(2);
				switch(headlight_status())
				{
					case 0:
						printf("Headlight OFF\n");
						break;
					case 1:
						printf("Headlight ON\n");
						break;
				}
				break;
			case 't':
				underlight_set(2);
				switch(underlight_status())
				{
					case 0:
						printf("Underlight OFF\n");
						break;
					case 1:
						printf("Underlight ON\n");
						break;
				}
				break;
			/*ADD ABOVE*/
			case 'q':
			{
				printf("QUIT\n");
				forward_set(0);
				backward_set(0);
				left_set(0);
				right_set(0);
				init(0);
				return 0;
			}
			default:
			{
				printf("KEY ERROR\n");
				break;
			}
		}
	}
}
