#include"directmode.h"
#include"define.h"

void direct_init()
{
	bcm2835_set_debug(BCM2835_DEBUG_MODE_SWITCH);
	if(!bcm2835_init())
	{
		printf("INITIALIZATION FAILED.\n");
	}
	else
	{
		input(1);
	}
}

