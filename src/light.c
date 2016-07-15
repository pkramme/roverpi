/*
The MIT License (MIT)
Copyright (c) 2016 Paul Kramme

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include"light.h"

#define headlight_def RPI_GPIO_P1_15

static unsigned short int headlight_state = 0;

int headlight_set(int arg)
{
	init(1);
	switch(arg)
	{
		case 0:
			bcm2835_gpio_write(headlight_def, 0x0);
			headlight_state = 0;
			return 0;
		case 1:
			bcm2835_gpio_write(headlight_def, 0x1);
			headlight_state = 1;
			return 0;
		case 2:
			switch(headlight_status())
			{
				case 0:
					bcm2835_gpio_write(headlight_def, 0x1);
					headlight_state = 1;
					return 0;
				case 1:
					bcm2835_gpio_write(headlight_def, 0x0);
					headlight_state = 0;
					return 0;
			}
	}
	return 1;
}

int headlight_status(void)
{
	return headlight_state;
}


#define underlight_def RPI_GPIO_P1_18

static unsigned short int underlight_state = 0;

int underlight_set(int arg)
{
	init(1);
	switch(arg)
	{
		case 0:
			bcm2835_gpio_write(underlight_def, 0x0);
			underlight_state = 0;
			return 0;
		case 1:
			bcm2835_gpio_write(underlight_def, 0x1);
			underlight_state = 1;
			return 0;
		case 2:
			switch(underlight_status())
			{
				case 0:
					bcm2835_gpio_write(underlight_def, 0x1);
					underlight_state = 1;
					return 0;
				case 1:
					bcm2835_gpio_write(underlight_def, 0x0);
					underlight_state = 0;
					return 0;
			}
	}
	return 1;
}

int underlight_status(void)
{
	return underlight_state;
}

