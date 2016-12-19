#include"headlessinput.h"

int headlessinput(int key)
{
	init(1);
	switch(key)
	{
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
			break;
		case 'r':
			headlight_set(2);
			break;
		case 't':
			underlight_set(2);
			break;
		case 'e':
			forward_set(0);
			backward_set(0);
			left_set(0);
			right_set(0);
                        break;
		case 'q':
			forward_set(0);
			backward_set(0);
			left_set(0);
			right_set(0);
			init(0);
			return 0;
		default:
			break;
	}
	return 0;
}
