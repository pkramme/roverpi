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

void pin_test(char mesg_name[256], uint8_t pin, int time, unsigned int delay)
{
	bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
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

int test()
{
	bcm2835_set_debug(BCM2835_DEBUG_MODE_SWITCH);
	switch(bcm2835_init())
	{
		case 0:
			printf("BCM2835 INITIALIZATION FAILED.\n");
			printf("ABORTING.\n");
			return 1;
		case 1:
			break;
	}
	/*
	YOUR PINS FROM HERE...
	*/
	pin_test("onepintorulethemall", RPI_GPIO_P1_12, 3, 2000);
	forward_set(1);
	forward_status();
	forward_set(0);
	forward_status();

	/*
	...TO HERE.
	*/
	switch(bcm2835_close())
	{
		case 0:
			printf("ERROR CLOSING BCM2835.");
			return 1;
		case 1:
			break;
	}
	return 0;  
}
	
void test_init()
{
	printf("---TEST MODE---\n");
	printf("This test uses the Broadcom pin numberings.\nDo you want to continue? (y/n)\n");
	int answer;
	answer = getche();
	printf("\n");
	switch(answer)
	{
		case 'y':
		{
			test();
			break;
		}
		default:
		{
			printf("Abort\n");
			break;
		}
	}
}

