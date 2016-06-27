#ifndef _TEST_H_
#define _TEST_H_

#include<bcm2835.h>
#include<stdio.h>
#include"defines.h"
#include<string.h>

void pin_test(char pin, int time, int delay)
{
	int internalcounter = 0;
	while(internalcounter <= time)
	{
		printf("Activating %c in %d ", pin, time);
		--time;
		bcm2835_delay(1000);
	}
	printf("Activating %d", pin);
	bcm2835_gpio_write(pin, HIGH);
	bcm2835_delay(delay);
	bcm2835_gpio_write(pin, HIGH);
	printf("Deactivated %d", pin);
}

int test()
{
	if(!bcm2835_init())
	{
		printf("BCM2835 INITIALIZATION FAILED.\n");
		return 1;
	}
	else
	{
		pin_test(PIN1, 3, 2000);
		//add more
		return 0;
	}
}
	
void testinit()
{
	printf("TEST MODE INITIALISING\n");
	printf("This test uses the Broadcom pin numberings.\nDo you want to continue?\n");
	char answer;
	scanf(" %c", &answer);
	if(answer == 'y')
	{
		printf("EXECUTE TEST.\n");
		setup();
		test();
	}
	else
	{
		printf("TEST ABORTED\n");
	}
}

#endif
