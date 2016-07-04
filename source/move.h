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
