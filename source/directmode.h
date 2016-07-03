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
				//setvbuf(stdout, NULL, _IOBLF, 0);
				//forward("init");
				//forward("switch");
				//forward("status");
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
				printf("LEFT\n");
				break;
			}

			case 'q':
			{
				printf("QUIT\n");
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
