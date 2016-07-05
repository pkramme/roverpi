/*
Copyright (c) 2016 Paul Kramme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.
*/
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

