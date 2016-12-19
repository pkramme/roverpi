#include"init.h"

static short unsigned int global_init = 0;

int init(int arg)
{
	switch(arg)
	{
		case 0:
			switch(global_init)
			{
				case 1:
					bcm2835_close();
					global_init = 0;
					return 0;
				case 0:
					return 1;
			}
		case 1:
			switch(global_init)
			{
				case 1:
					return 1;
				case 0:
#ifdef DEBUG
					bcm2835_set_debug(1);
#endif
					if(!bcm2835_init())
                                        {
                                             exit(1);
					}
					global_init = 1;
					return 0;
			}
	}
	return 1;
}

