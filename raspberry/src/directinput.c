#include"directinput.h"

/*	Function: 	input
 *
 *	Params: 	None (void)
 *
 *	Return: 	0 for exit
 *
 *	Information: 	Function executes an infinitive loop, waits for input
 *			and launches the specified functions.
 */

int input(void)
{
	puts("==================|DIRECT MODE|==================");
	init(1);
	for(;;)
	{
#ifdef DEBUG
		switch(getche())
#endif
#ifndef DEBUG
		switch(getch())
#endif
		{
#ifdef DEBUG
			printf("\n");
#endif
			case 'w':
				if(PROTECT && !forward_status())
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
						puts("Forward OFF");
						break;
					case 1:
						puts("Forward ON");
						break;
				}
				break;
			case 'a':
				if(PROTECT && !left_status())
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
						puts("Left OFF");
						break;
					case 1:
						puts("Left ON");
						break;
				}
				break;
			case 's':
				if(PROTECT && !backward_status())
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
						puts("Backward OFF");
						break;
					case 1:
						puts("Backward ON");
						break;
				}
				break;
			case 'd':
				if(PROTECT && !right_status())
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
						puts("Right OFF");
						break;
					case 1:
						puts("Right ON");
						break;
				}
				break;
			case 'r':
				headlight_set(2);
				switch(headlight_status())
				{
					case 0:
						puts("Headlight OFF");
						break;
					case 1:
						puts("Headlight ON");
						break;
				}
				break;
			case 't':
				underlight_set(2);
				switch(underlight_status())
				{
					case 0:
						puts("Underlight OFF");
						break;
					case 1:
						puts("Underlight ON");
						break;
				}
				break;
			case 'e':
				puts("Kill All");
				forward_set(0);
				backward_set(0);
				left_set(0);
				right_set(0);
				break;
			case 'q':
				puts("QUIT");
				underlight_set(0);
				headlight_set(0);
				forward_set(0);
				backward_set(0);
				left_set(0);
				right_set(0);
				init(0);
				return 0;
			default:
				puts("Key not defined.");
				break;
		}
	}
}
