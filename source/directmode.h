#ifndef _DIRECTMODE_H_
#define _DIRECTMODE_H_

#include<bcm2835.h>
#include"move.h"
#include"getch.h"

int input()
{
	int input;
	//bcm2835_init();
	//bcm2835_set_debug(BCM2835_DEBUG_MODE_SWITCH);
	while(1)
	{
		input = getch();
		switch(input)
		{
			case 'w':
			{
				forward_set(2);
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
				break;
			}
			case 'a':
			{
				left_set(2);
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
				break;
			}
			case 's':
			{
				backward_set(2);
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

				break;
			}
			case 'd':
			{
				right_set(2);
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


void direct_init()
{
	bcm2835_set_debug(BCM2835_DEBUG_MODE_SWITCH);
	if(!bcm2835_init())
	{
		printf("INITIALIZATION FAILED.\n");
	}
	else
	{
		//pin_setup();
		input();
	}
}

#endif
