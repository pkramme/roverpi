#ifndef _DIRECTMODE_H_
#define _DIRECTMODE_H_

#include<bcm2835.h>
#include"move.h"
#include"getch.h"

int input()
{
	int input;
	while(1)
	{
		input = getch();
		switch(input)
		{
			case 'w':
			{
				//setvbuf(stdout, NULL, _IOBLF, 0);
				//forward("init");
				forward("switch");
				forward("status");
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
				return 0;
			}
			default:
			{
				printf("KEY ERROR");
			}
		}
	}
}


void direct_init()
{
	//pin_setup();
	input();
}
#endif
