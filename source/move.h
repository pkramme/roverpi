#ifndef _MOVE_H_
#define _MOVE_H_

#define forward RPI_GPIO_P1_11
#define backward RPI_GPIO_P1_12
#define left RPI_GPIO_P1_13
#define right RPI_GPIO_P1_14

#define debug 1

char[] status_online = "online";
char[] status_offline = "offline";
char[] status_status = "status";
char[] status_init = "init";

void forward(char status[])
{
	bool state = false;
	bool init = false;
	if(strcmp(status, status_online) == 0)
	{
		//SET ONLINE
		state = true;
		bcm2835_gpio_write(forward, 0x1);
	}
	else if(strcmp(status, status_offline) == 0)
	{
		//SET OFFLINE
		state = false;
		bcm2835_gpio_write(forward, 0x0);
	}
	else if(strcmp(status, status_status) == 0)
	{
		if(state == true)
		{
			if(strcmp((argv)[1], arg_test) == 0)
			{
				printf("FORWARD STATE: TRUE");
			}
			else if(strcmp((argv)[1], arg_test_short) == 0)
			{
				printf("FORWARD STATE: TRUE");
			}
			else if(strcmp((argv)[1], arg_direct) == 0)
			{
				printw("FORWARD STATE: TRUE");
			}
			else if(strcmp((argv)[1], arg_direct_short) == 0)
			{
				printw("FORWARD STATE: TRUE");
			}
			else if(strcmp((argv)[1], arg_headless) == 0)
			{
				//DO NOTHING.
			}
			else if(strcmp((argv)[1], arg_headless_short) == 0)
			{
				//DO NOTHING.
			}
			else if(strcmp((argv)[1], arg_remote) == 0)
			{
				printw("FORWARD STATE: TRUE");
			}
			else if(strcmp((argv)[1], arg_remote_short) == 0)
			{
				printw("FORWARD STATE: TRUE");
			}
			else
			{
				printf("EXCEPTION OCCURED: FORWARD ELSE ARG CALLED");
			}
		}
		else if(state == false)
		{
			printf("FORWARD STATE: FALSE");
		}
	}
	else if(strcmp(status, status_init) == 0)
	{
		if(bcm2835_init() == 0)
		{
			bcm2835_init();
			if(bcm2835_init() == 0)
			{
				printf("EXCEPTION OCCURED: ERROR INITIALIZING BCM2835");
		}
		bcm2835_gpio_fsel(forward, BCM2835_GPIO_FSEL_OUTP);
		init = true;
	}
	else
	{
		printf("EXCEPTION OCCURED: FORWARD ELSE CALLED");
	}
}

void backward(char[] status)
{
	//args
}

#endif
