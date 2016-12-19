#include"move.h"

#define forward_def RPI_GPIO_P1_22
#define backward_def RPI_GPIO_P1_18
#define left_def RPI_GPIO_P1_12
#define right_def RPI_GPIO_P1_13

static uint8_t forward_state = 0;
static uint8_t forward_init = 0;

int forward_set(int arg)
{
	if(arg > 2 || arg < 0)
	{
		return 1;
	}
	if(!forward_init)
	{
		bcm2835_gpio_fsel(forward_def, BCM2835_GPIO_FSEL_OUTP);
		forward_init = 1;
	}
	switch(arg)
	{
		case 2:
			switch(forward_state)
			{
				case 0:
					bcm2835_gpio_write(forward_def, 0x1);
					forward_state = 1;
					return 0;
				case 1:
					bcm2835_gpio_write(forward_def, 0x0);
					forward_state = 0;
					return 0;
				default:
					return 1;
			}
		case 0:
			bcm2835_gpio_write(forward_def, 0x0);
			forward_state = 0;
			return 0;
		case 1:
			bcm2835_gpio_write(forward_def, 0x1);
			forward_state = 1;
			return 0;
		default:
			return 1;
	}
}

int forward_status(void)
{
	return forward_state;
}

static uint8_t backward_state = 0;
static uint8_t backward_init = 0;

int backward_set(int arg)
{
	if(arg > 2 || arg < 0)
        {
                return 1;
        }
	if(!backward_init)
        {
                bcm2835_gpio_fsel(backward_def, BCM2835_GPIO_FSEL_OUTP);
                backward_init = 1;
        }
	switch(arg)
        {
                case 2:
                        switch(backward_state)
                        {
                                case 0:
                                        bcm2835_gpio_write(backward_def, 0x1);
                                        backward_state = 1;
                                        return 0; 
                                case 1:
                                        bcm2835_gpio_write(backward_def, 0x0);
                                        backward_state = 0;
                                        return 0;
				default:
					return 1;
                        }
                case 0:
                        bcm2835_gpio_write(backward_def, 0x0);
                        backward_state = 0;
                        return 0;
                case 1:
                        bcm2835_gpio_write(backward_def, 0x1);
                        backward_state = 1;
                        return 0;
		default:
			return 1;
        }
}
int backward_status(void)
{
	return backward_state;
}


static uint8_t left_state = 0;
static uint8_t left_init = 0;

int left_set(int arg)
{
	if(arg > 2 || arg < 0)
        {
                return 1;
        }
	if(!left_init)
        {
                bcm2835_gpio_fsel(left_def, BCM2835_GPIO_FSEL_OUTP);
                left_init = 1;
        }
	switch(arg)
        {
                case 2:
                        switch(left_state)
                        {
                                case 0:
                                        bcm2835_gpio_write(left_def, 0x1);
                                        left_state = 1;
                                        return 0;
                                case 1:
                                        bcm2835_gpio_write(left_def, 0x0);
                                        left_state = 0;
                                        return 0;
				default:
					return 1;
                        }
                case 0:
                        bcm2835_gpio_write(left_def, 0x0);
                        left_state = 0;
			return 0;
                case 1:
                        bcm2835_gpio_write(left_def, 0x1);
                        left_state = 1;
                        return 0;
		default:
			return 1;
        }
}

int left_status(void)
{
	return left_state; 
}

static uint8_t right_state = 0;
static uint8_t right_init = 0;

int right_set(int arg)
{
	if(arg > 2 || arg < 0)
        {
                return 1;
        }
	if(!right_init)
        {
                bcm2835_gpio_fsel(right_def, BCM2835_GPIO_FSEL_OUTP);
                right_init = 1;
        }
        switch(arg)
        {
                case 2:
                        switch(right_state)
                        {
                                case 0:
                                        bcm2835_gpio_write(right_def, 0x1);
                                        right_state = 1;
                                        return 0;
                                case 1:
                                        bcm2835_gpio_write(right_def, 0x0);
                                        right_state = 0;
                                        return 0;
				default:
					return 1;
                        }
                case 0:
                        bcm2835_gpio_write(right_def, 0x0);
                        right_state = 0;
                        return 0;
                case 1:
                        bcm2835_gpio_write(right_def, 0x1);
                        right_state = 1;
                        return 0;
		default:
			return 1;
        }
}

int right_status(void)
{
        return right_state;
}

