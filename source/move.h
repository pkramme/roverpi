/*
The MIT License (MIT)

Copyright (c) 2016 Paul Kramme

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include<bcm2835.h>
#include"argument.h"

extern int forward_state;
extern int forward_init;
void forward_set(int arg);
int forward_status(void);

extern int backward_state;
extern int backward_init;
void backward_set(int arg);
int backward_status(void);

extern int left_state;
extern int left_init;
void left_set(int arg);
int left_status(void);

extern int right_state;
extern int right_init;
void right_set(int arg);
int right_status(void);

/*
extern int lr_state;
extern int lr_init;
void lr_set(int arg, int value);
*/
#endif
