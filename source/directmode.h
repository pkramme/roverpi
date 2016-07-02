#ifndef _DIRECTMODE_H_
#define _DIRECTMODE_H_

#include<bcm2835.h>
#include<ncurses.h>
#include"move.h"

void terminator()
{
	endwin();
}

void screen_setup()
{
	//ncursesinit here!
	printf("NCURSES SETUP INITIATED");
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	printw("NCURSES SETUP COMPLETE");
}

int input()
{
	int input;
	while(1)
	{
		input = getch();
		clear();
		switch(input)
		{
			case 'w':
			{
				printw("FORWARD\n");
				break;
			}
			case 'a':
			{
				printw("LEFT\n");
				break;
			}

			case 'q':
			{
				clear();
				endwin();
				printf("QUIT\n");
				return 0;
			}
			default:
			{
				printw("KEY ERROR");
			}
		}
	}
}


void direct_init()
{
	//pin_setup();
	screen_setup();
	input();
}
#endif
