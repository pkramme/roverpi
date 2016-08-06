/*
The MIT License (MIT)

Copyright (c) 2016 Paul Kramme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include"test.h"

/************************************************
Function:	pin_test

Type:		void

Return:		Nothing (void)

Description:	Contains a timer which waits a given time.
		After that, it activated a given pin for a given time.
		The pin has to match a predefined pin in BCM2835 lib.
		The specified name will be written to standart output.
************************************************/

void pin_test(char mesg_name[256], uint8_t pin, int time, unsigned int delay)
{
	int internalcounter = 0;
	while(internalcounter <= time)
	{
		printf("Activating %s in %d\n", mesg_name, time);
		bcm2835_delay(1000);
		--time;
	}
	printf("Activating %d\n", pin);
	bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_write(pin, 0x1);
	bcm2835_delay(delay);
	bcm2835_gpio_write(pin, 0x0);
	printf("Deactivating %d\n", pin);
}

/************************************************
Function:	test

Type:		int

Return:		0

Description:	Either tests pins via pin_test,
		or by using the pin definitions from move.h header.
*************************************************/
		
int test()
{
	init(1);
	/*
	Add your pins below...
	*/
	pin_test("onepintorulethemall", RPI_GPIO_P1_12, 3, 2000);
	forward_set(1);
	forward_status();
	forward_set(0);
	forward_status();

	init(0);
	return 0;  
}

/*************************************************
Function:	test_init

Type:		void

Return:		Nothing

Description:	Checks if user really want to execute test mode.
		After that, it executes test function.
**************************************************/

void test_init()
{
	puts("==================TEST MODE==================");
	puts("Do you want to continue? (y/n)");
	switch(getch())
	{
		case 'y':
		{
			test();
			break;
		}
		default:
		{
			puts("Abort");
			break;
		}
	}
}

