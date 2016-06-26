#ifndef _DEFINES_H_
#define _DEFINES_H_

#include<bcm2835.h>
//HERE COMES THE NAME DEFINES
#define PIN1 RPI_GPIO_P1_11

//HERE COMES THE setup() part

void setup()
{
	bcm2835_gpio_fsel(PIN1, BCM2835_GPIO_FSEL_OUTP);
}

#endif
