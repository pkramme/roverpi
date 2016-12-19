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
		
int test(void)
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
	puts("==================|TEST MODE|==================");
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

