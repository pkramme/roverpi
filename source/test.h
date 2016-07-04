#ifndef _TEST_H_
#define _TEST_H_

#include<bcm2835.h>
#include<stdio.h>
#include<string.h>
#include"move.h"
#include"getch.h"

void pin_test(char mesg_name[256], char pin, int time, int delay)
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
	bcm2835_init();
	if(bcm2835_init() == 0)
	{
		printf("BCM2835 INITIALIZATION FAILED.\n");
		printf("ABORTING.\n");
		return 1;
	}
	else if(bcm2835_init() == 1)
	{
		printf("BCM2835 INITIALIZATION SUCCESSFUL.\n");
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
		bcm2835_close();
		if(bcm2835_close() == 0)
		{
			printf("BCM2835 CLOSING FAILED.\n");
		}
		else if(bcm2835_close() == 1)
		{
			printf("BCM2835 CLOSING SUCCESSFUL.\n");
		}
		else
		{
			printf("UNKNOWN EXCEPTION AT CLOSING.\n");
		}
	}
	else
	{
		printf("UNKNOWN EXCEPTION AT INIT.\n");
	}
	return 0;  
}
	
void testinit()
{
	printf("TEST MODE INITIALISING\n");
	printf("This test uses the Broadcom pin numberings.\nDo you want to continue? (y/n)\n");
	char answer;
	//char positiv = 'y';
	answer = getche();
	printf("\n");
	switch(answer)
	{
		case 'y':
		{
			test();
			break;
		}
		case 'j':
		{
			test();
			break;
		}
		default:
		{
			printf("ABORT.\n");
			break;
		}
	}
}

#endif
