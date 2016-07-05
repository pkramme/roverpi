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
#include"input.h"

int input(int verbose)
{
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
				if(verbose)
				{
					if(forward_status() == 1)
					{
						printf("FORWARD ACTIVATED\n");
					}
					else if(forward_status() == 0)
					{
						printf("FORWARD DEACTIVATED\n");
					}
					else
					{
						printf("EXCEPTION OCCURED: FORWARD STATUS ELSE\n");
					}
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
				if(verbose)
				{
					if(left_status() == 1)
					{
						printf("LEFT ACTIVATED\n");
                	                }
                	                else if(left_status() == 0)
                	                {
                	                        printf("LEFT DEACTIVATED\n");
                	                }
                	                else
					{
						printf("EXCEPTION OCCURED: LEFT STATUS ELSE\n");
					}
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
				if(verbose)
				{
					if(backward_status() == 1)
                        	        {
                        	                printf("BACKWARD ACTIVATED\n");
                        	        }
                        	        else if(backward_status() == 0)
                        	        {
                                	        printf("BACKWARD DEACTIVATED\n");
                        	        }
					else
					{
					printf("EXCEPTION OCCURED: BACKWARD STATUS ELSE\n");
					}
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
				if(verbose)
				{
					if(right_status() == 1)
					{
						printf("RIGHT ACTIVATED\n");
					}
                               		else if(right_status() == 0)
                           		{
                                        	printf("RIGHT DEACTIVATED\n");
                               		}
                                	else
                                	{
                                        	printf("EXCEPTION OCCURED: RIGHT STATUS ELSE\n");
                                	}
				}
				break;
			}
			case 'q':
			{
				printf("QUIT\n");
				forward_set(0);
				backward_set(0);
				left_set(0);
				right_set(0);
				bcm2835_close();
				return 0;
			}
			default:
			{
				printf("KEY ERROR\n");
			}
		}
	}
}
