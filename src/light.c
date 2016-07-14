#include"light.h"

<<<<<<< HEAD
#define headlight_def /*ADD PIN HERE*/

static unsigned short int headlight_state = 0;

int headlight_set(int arg)
{
	init(1);
	switch(arg)
	{
		case 0:
			bcm2835_gpio_write(/*ADD PIN HERE*/, 0x0);
			headlight_state = 0;
			return 0;
		case 1:
			bcm2835_gpio_write(/*ADD PIN HERE*/, 0x1);
			headlight_state = 1;
			return 0;
		case 2:
			switch(headlight_status())
			{
				case 0:
					headlight_set(1);
				case 1:
					headlight_set(0);
			}
	}
	return 0;
}

int headlight_status(void)
{
	return headlight_state;
}


#define underlight_def /*SOME PIN*/

static unsigned short int underlight_state = 0;

int underlight_set(int arg)
{
	init(1);
	switch(arg)
	{
		case 0:
			bcm2835_gpio_write(/*ADD PIN HERE*/, 0x0);
			underlight_state = 0;
			return 0;
		case 1:
			bcm2835_gpio_write(/*ADD PIN HERE*/, 0x1);
			underlight_state = 1;
			return 0;
		case 2:
			switch(underlight_status())
			{
				case 0:
					underlight_set(1);
				case 1:
					underlight_set(0);
			}
	}
	return 0;
}

int underlight_status(void)
{
	return underlight_state;
}
=======
>>>>>>> master

