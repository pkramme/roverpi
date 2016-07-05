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
#ifndef GETCH_H_INCLUDED
#define GETCH_H_INCLUDED

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int getch(void);

int getche(void);

#endif
