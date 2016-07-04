#include"move.h"

#define forward_def RPI_GPIO_P1_16
#define backward_def RPI_GPIO_P1_12
#define left_def RPI_GPIO_P1_13
#define right_def RPI_GPIO_P1_11

int forward_state = 0;
int forward_init = 0;

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

/*
int lr_state = 0;
int lr_init = 0;


void lr_set(int arg, int value)
{
	if(!lr_init && !left_init && !right_init)
	{
		bcm2835_gpio_fsel(right_def, BCM2835_GPIO_FSEL_ALT5);
		bcm2835_gpio_fsel(left_def, BCM2835_GPIO_FSEL_ALT5);
		bcm2835_pwm_set_clock
		lr_init = 1;
	}
	switch(arg)
	{
		case 0:
		{
			
		}
	}
}
*/
