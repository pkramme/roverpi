#ifndef _DIRECTMODE_H_
#define _DIRECTMODE_H_

#include<bcm2835.h>
#include<ncurses.h>

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
		switch(input)
		{
			case 'w':
			{
				printw("FORWARD");
				refresh();
				break;
			}
			case 'a':
			{
				printw("LEFT");
				refresh();
				break;
			}

			case 'q':
			{
				printw("QUIT");
				refresh();
				endwin();
				return 0;
				//terminator();
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
/*
void terminator()
{
	endwin();
}
*/
#endif
