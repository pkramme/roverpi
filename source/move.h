#ifndef _MOVE_H_
#define _MOVE_H_

#include<bcm2835.h>
#include"argument.h"
//#include<ncurses.h>

#define forward_def RPI_GPIO_P1_16
#define backward_def RPI_GPIO_P1_12
#define left_def RPI_GPIO_P1_13
#define right_def RPI_GPIO_P1_11

#define debug 1

char status_switch[] = "switch";
char status_status[] = "status";
char status_init[] = "init";
char status_online[] = "online";
char status_offline[] = "offline";

int forward_state = 0;
int forward_init = 0;

//OLD CODE
//DO NOT USE!

void forward(char status[])
{
	printf("THE USE OF THIS FUNCTION IS DEPRECIATED. USE forward_set() INSTEAD\n");
	//int state = 0;
	//int init = 0;
	if(strcmp(status, status_switch) == 0)
	{
		if(forward_state == 0)
		{
			forward_state = 1;
			bcm2835_gpio_write(forward_def, 0x1);
		}
		else if(forward_state == 1)
		{
			forward_state = 0;
			bcm2835_gpio_write(forward_def, 0x0);
		}
	}
	else if(strcmp(status, status_online) == 0)
	{
		forward_state = 1;
		bcm2835_gpio_write(forward_def, 0x1);
	}
	else if(strcmp(status, status_offline) == 0)
	{
		forward_state = 0;
		bcm2835_gpio_write(forward_def, 0x0);
	}
	else if(strcmp(status, status_status) == 0)
	{
		if(forward_state == 1)
		{
			if(strcmp(arg1, arg_test) == 0)
			{
				printf("FORWARD STATE: TRUE\n");
			}
			else if(strcmp(arg1, arg_test_short) == 0)
			{
				printf("FORWARD STATE: TRUE\n");
			}
			else if(strcmp(arg1, arg_direct) == 0)
			{
				printf("FORWARD STATE: TRUE\n");
			}
			else if(strcmp(arg1, arg_direct_short) == 0)
			{
				printf("FORWARD STATE: TRUE\n");
			}
			else if(strcmp(arg1, arg_headless) == 0)
			{
				//DO NOTHING.
			}
			else if(strcmp(arg1, arg_headless_short) == 0)
			{
				//DO NOTHING.
			}
			else if(strcmp(arg1, arg_remote) == 0)
			{
				printf("FORWARD STATE: TRUE\n");
			}
			else if(strcmp(arg1, arg_remote_short) == 0)
			{
				printf("FORWARD STATE: TRUE\n");
			}
			else
			{
				printf("EXCEPTION OCCURED: FORWARD ELSE ARG CALLED (POS)\n");
			}
		}
		else if(forward_state == 0)
		{
			if(strcmp(arg1, arg_test) == 0)
                        {
                                printf("FORWARD STATE: FALSE\n");
                        }
                        else if(strcmp(arg1, arg_test_short) == 0)
                        {
                                printf("FORWARD STATE: FALSE\n");
                        }
                        else if(strcmp(arg1, arg_direct) == 0)
                        {
                                printf("FORWARD STATE: FALSE\n");
                        }
                        else if(strcmp(arg1, arg_direct_short) == 0)
                        {
                                printf("FORWARD STATE: FALSE\n");
                        }
                        else if(strcmp(arg1, arg_headless) == 0)
                        {
                                //DO NOTHING.
                        }
                        else if(strcmp(arg1, arg_headless_short) == 0)
                        {
                                //DO NOTHING.
                        }
                        else if(strcmp(arg1, arg_remote) == 0)
                        {
                                printf("FORWARD STATE: FALSE\n");
                        }
                        else if(strcmp(arg1, arg_remote_short) == 0)
                        {
                                printf("FORWARD STATE: FALSE\n");
                        }
                        else
                        {
                                printf("EXCEPTION OCCURED: FORWARD ELSE ARG CALLED (NEG)\n");
                        }

		}
		else
		{
			printf("EXCEPTION OCCURED: FORWARD STATE BOOL LEFT BINARY STATE");
		}
	}
	else if(strcmp(status, status_init) == 0)
	{
		if(forward_init != 1)
		{
			if(bcm2835_init() == 0)
			{
				bcm2835_set_debug(BCM2835_DEBUG_MODE_SWITCH);
				bcm2835_init();
				if(bcm2835_init() == 0)
				{
					printf("EXCEPTION OCCURED: ERROR INITIALIZING BCM2835");
				}
			}
			bcm2835_gpio_fsel(forward_def, BCM2835_GPIO_FSEL_OUTP);
			forward_init = 1;
		}
	}
	else
	{
		printf("EXCEPTION OCCURED: FORWARD ELSE CALLED");
	}
}

void forward_set(int arg)
{
	if(!forward_init)
	{
		bcm2835_gpio_fsel(forward_def, BCM2835_GPIO_FSEL_OUTP);
		forward_init = 1;
	}
	switch(arg)
	{
		case 2:
		{
			//printf("SWITCH MODE\n");
			switch(forward_state)
			{
				case 0:
				{
					//printf("ACTIVATE\n");
					bcm2835_gpio_write(forward_def, 0x1);
					forward_state = 1;
					break;
				}
				case 1:
				{
					//printf("DEACTIVATE\n");
					bcm2835_gpio_write(forward_def, 0x0);
					forward_state = 0;
					break;
				}
			}
			break;
		}
		case 0:
		{
			bcm2835_gpio_write(forward_def, 0x0);
			forward_state = 0;
			break;
		}
		case 1:
		{
			bcm2835_gpio_write(forward_def, 0x1);
			forward_state = 1;
			break;
		}
	}
}

int forward_status(void)
{
	switch(forward_state)
	{
		case 1:
		{
			return 1;
		}
		case 0:
		{
			return 0;
		}
	}
	return 0;
}

int backward_state = 0;
int backward_init = 0;

void backward_set(int arg)
{
	if(!backward_init)
        {
                bcm2835_gpio_fsel(backward_def, BCM2835_GPIO_FSEL_OUTP);
                backward_init = 1;
        }
	switch(arg)
        {
                case 2:
                {
                        //printf("SWITCH MODE\n");
                        switch(backward_state)
                        {
                                case 0:
                                {
                                        //printf("ACTIVATE\n");
                                        bcm2835_gpio_write(backward_def, 0x1);
                                        backward_state = 1;
                                        break;
                                }
                                case 1:
                                {
                                        //printf("DEACTIVATE\n");
                                        bcm2835_gpio_write(backward_def, 0x0);
                                        backward_state = 0;
                                        break;
                                }
                        }
                        break;
                }
                case 0:
                {
                        bcm2835_gpio_write(backward_def, 0x0);
                        backward_state = 0;
                        break;
                }
                case 1:
                {
                        bcm2835_gpio_write(backward_def, 0x1);
                        backward_state = 1;
                        break;
                }
        }
}
int backward_status(void)
{
        switch(backward_state)
        {
                case 1:
                {
                        return 1;
                }
                case 0:
                {
                        return 0;
                }
        }
        return 0;
}


int left_state = 0;
int left_init = 0;

void left_set(int arg)
{
	if(!left_init)
        {
                bcm2835_gpio_fsel(left_def, BCM2835_GPIO_FSEL_OUTP);
                left_init = 1;
        }
	switch(arg)
        {
                case 2:
                {
                        //printf("SWITCH MODE\n");
                        switch(left_state)
                        {
                                case 0:
                                {
                                        //printf("ACTIVATE\n");
                                        bcm2835_gpio_write(left_def, 0x1);
                                        left_state = 1;
                                        break;
                                }
                                case 1:
                                {
                                        //printf("DEACTIVATE\n");
                                        bcm2835_gpio_write(left_def, 0x0);
                                        left_state = 0;
                                        break;
                                }
                        }
                        break;
                }
                case 0:
                {
                        bcm2835_gpio_write(left_def, 0x0);
                        left_state = 0;
                        break;
                }
                case 1:
                {
                        bcm2835_gpio_write(left_def, 0x1);
                        left_state = 1;
                        break;
                }
        }
}

int left_status(void)
{
        switch(left_state)
        {
                case 1:
                {
                        return 1;
                }
                case 0:
                {
                        return 0;
                }
        }
        return 0;
}

int right_state = 0;
int right_init = 0;

void right_set(int arg)
{
	if(!right_init)
        {
                bcm2835_gpio_fsel(right_def, BCM2835_GPIO_FSEL_OUTP);
                right_init = 1;
        }
        switch(arg)
        {
                case 2:
                {
                        //printf("SWITCH MODE\n");
                        switch(right_state)
                        {
                                case 0:
                                {
                                        //printf("ACTIVATE\n");
                                        bcm2835_gpio_write(right_def, 0x1);
                                        right_state = 1;
                                        break;
                                }
                                case 1:
                                {
                                        //printf("DEACTIVATE\n");
                                        bcm2835_gpio_write(right_def, 0x0);
                                        right_state = 0;
                                        break;
                                }
                        }
                        break;
                }
                case 0:
                {
                        bcm2835_gpio_write(right_def, 0x0);
                        right_state = 0;
                        break;
                }
                case 1:
                {
                        bcm2835_gpio_write(right_def, 0x1);
                        right_state = 1;
                        break;
                }
        }
}

int right_status(void)
{
        switch(right_state)
        {
                case 1:
                {
                        return 1;
                }
                case 0:
                {
                        return 0;
                }
        }
        return 0;
}

#endif
