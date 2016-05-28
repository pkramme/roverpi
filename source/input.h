//========================================
//INCLUDE GUARD
#ifndef __INPUT_H_INCLUDED__
#define __INPUT_H_INCLUDED__

//========================================
//INCLUDE
#include<iostream>
#include<ncurses.h>
#include<wiringPi.h>
#include<cstdlib>

//========================================
//SWITCH DECLERATIONS
bool forwardswitch = false;
bool backwardswitch = false;
bool leftswitch = false;
bool rightswitch = false;
bool frontlightswitch = false;
bool groundlightswitch = false;
bool cameraupswitch = false;
bool cameradownswitch = false;
bool camerarightswitch = false;
bool cameraleftswitch = false;

//========================================
//GPIO PIN DECLERATIONS
#define forward_gpio 0
#define backward_gpio 1
#define right_gpio 26
#define left_gpio 23
#define light_front 4
#define light_ground 5
#define camera_x_down_gpio 6
#define camera_x_up_gpio 27
#define camera_y_left_gpio 8
#define camera_y_right_gpio 9

int x_pwmswitch = 0;

#define std_d 10//standard delay in ms

void mv_killall()
{
	pwmWrite(left_gpio, 0);
	leftswitch = false;
	pwmWrite(right_gpio, 0);
	rightswitch = false;
	x_pwmswitch = 0;

	if(forwardswitch == true)
	{
		forwardswitch = false;
		digitalWrite(forward_gpio, 0);
		delay(std_d);
	}

	if(backwardswitch == true)
	{
		backwardswitch = false;
		digitalWrite(backward_gpio, 0);
		delay(std_d);
	}

	printw("KILLALL");
}

void killall()
{
	mv_killall();
	digitalWrite(light_front, 0);
	digitalWrite(light_ground, 0);
	digitalWrite(camera_x_up_gpio, 0);
	digitalWrite(camera_x_down_gpio, 0);
	digitalWrite(camera_y_left_gpio, 0);
	digitalWrite(camera_y_right_gpio, 0);
	printw("ALL PINS DESTROYED");
}

void forward()
{
	if(forwardswitch == false)
	{
		if(backwardswitch == true)
		{
			backwardswitch = false;
			digitalWrite(backward_gpio, 0);
			delay(std_d);
		}

		if(leftswitch == true)
		{
			leftswitch = false;
			pwmWrite(left_gpio, 0);
			delay(std_d);
			x_pwmswitch = 0;
		}

		if(rightswitch == true)
		{
			rightswitch = false;
			pwmWrite(right_gpio, 0);
			delay(std_d);
			x_pwmswitch = 0;
		}

		forwardswitch = true;
		digitalWrite(forward_gpio, 1);
		delay(std_d);

		printw("FORWARD");
	}
	else
	{
		mv_killall();
	}
}

void backward()
{
	if(backwardswitch == false)
	{
		if(forwardswitch == true)
		{
			forwardswitch = false;
			digitalWrite(forward_gpio, 0);
			delay(std_d);
		}

		if(leftswitch == true)
		{
			leftswitch = false;
			pwmWrite(left_gpio, 0);
			delay(std_d);
			x_pwmswitch = 0;
		}

		if(rightswitch == true)
		{
			rightswitch = false;
			pwmWrite(right_gpio, 0);
			delay(std_d);
			x_pwmswitch = 0;
		}

		backwardswitch = true;
		digitalWrite(backward_gpio, 1);
		delay(std_d);

		printw("BACKWARD");
	}
	else
	{
		mv_killall();
	}
}


void left()
{
	x_pwmswitch += 100;
	if(x_pwmswitch >= 1000)
	{
		x_pwmswitch = 1000;
	}
}

void right()
{
	x_pwmswitch -= 100;
	if(x_pwmswitch <= -1000)
	{
		x_pwmswitch = -1000;
	}
}

void x_move()
{
	if(x_pwmswitch > 0)
	{
		if(forwardswitch == false && backwardswitch == false)
		{
			pwmWrite(left_gpio, x_pwmswitch);
			pwmWrite(right_gpio, 0);
			leftswitch = true;
			mvprintw(0,0,"LEFT SPEED %d",x_pwmswitch);
		}
		else
		{
			if(forwardswitch == true)
			{
				forwardswitch = false;
				digitalWrite(forward_gpio, 0);
				delay(std_d);
			}

			else if(backwardswitch == true)
			{
				backwardswitch = false;
				digitalWrite(backward_gpio, 0);
				delay(std_d);
			}
			pwmWrite(left_gpio, x_pwmswitch);
			pwmWrite(right_gpio, 0);
			leftswitch = true;
			mvprintw(0,0,"LEFT SPEED %d",x_pwmswitch);
		}
	}
	else if(x_pwmswitch < 0)
	{
		if(forwardswitch == false && backwardswitch == false)
		{
			pwmWrite(right_gpio, x_pwmswitch*(-1));//unsigned int in wiringPi class needs inverted negative int input...
			pwmWrite(left_gpio, 0);
			rightswitch = true;
			mvprintw(0,0,"RIGHT SPEED %d", x_pwmswitch);
		}
		else
		{
			if(forwardswitch == true)
			{
				forwardswitch = false;
				digitalWrite(forward_gpio, 0);
				delay(std_d);
			}

			else if(backwardswitch == true)
			{
				backwardswitch = false;
				digitalWrite(backward_gpio, 0);
				delay(std_d);
			}
			pwmWrite(right_gpio, x_pwmswitch*(-1));
			pwmWrite(left_gpio, 0);
			rightswitch = true;
			mvprintw(0,0,"RIGHT SPEED %d", x_pwmswitch);
		}
	}
	else if(x_pwmswitch == 0)
	{
		pwmWrite(left_gpio, 0);
		leftswitch = false;
		pwmWrite(right_gpio, 0);
		rightswitch = false;
	}
}

void front_light()
{
	if(frontlightswitch == false)
	{
		frontlightswitch = true;
		digitalWrite(light_front, 1);
		printw("FRONT LIGHT [ENGAGED]");
	}
	else
	{
		frontlightswitch = false;
		digitalWrite(light_front, 0);
		printw("FRONT LIGHT [DISENGAGED]");
	}
}

void ground_light()
{
	if(groundlightswitch == false)
	{
		groundlightswitch = true;
		digitalWrite(light_ground, 1);
		printw("GROUND LIGHT [ENGAGED]");
	}
	else
	{
		groundlightswitch = false;
		digitalWrite(light_ground, 0);
		printw("GROUND LIGHT [DISENGAGED]");
	}
}

void camera_up()
{
	if(cameraupswitch == false)
	{
		cameradownswitch = false;
		digitalWrite(camera_x_down_gpio, 0);

		cameraupswitch = true;
		digitalWrite(camera_x_up_gpio, 1);
		printw("CAMERA UP ROTATION [ENGAGED]");
	}
	else
	{
		cameraupswitch = false;
		digitalWrite(camera_x_up_gpio, 0);
		printw("CAMERA UP ROTATION [DISENGAGED]");
	}
}

void camera_down()
{
	if(cameradownswitch == false)
	{
		cameraupswitch = false;
		digitalWrite(camera_x_up_gpio, 0);

		cameradownswitch = true;
		digitalWrite(camera_x_down_gpio, 1);
		printw("CAMERA DOWN ROTATION [ENGAGED]");
	}
	else
	{
		cameradownswitch = false;
		digitalWrite(camera_x_down_gpio, 0);
		printw("CAMERA DOWN ROTATION [DISENGAGED]");
	}
}

void camera_left()
{
	if(cameraleftswitch == false)
	{
		camerarightswitch = false;
		digitalWrite(camera_y_right_gpio, 0);

		cameraleftswitch = true;
		digitalWrite(camera_y_left_gpio, 1);
		printw("CAMERA LEFT ROTATION [ENGAGED]");
	}
	else
	{
		cameraleftswitch = false;
		digitalWrite(camera_y_left_gpio, 0);
		printw("CAMERA LEFT ROTATION [DISENGAGED]");
	}
}

void camera_right()
{
	if(camerarightswitch == false)
	{
		cameraleftswitch = false;
		digitalWrite(camera_y_left_gpio, 0);

		camerarightswitch = true;
		digitalWrite(camera_y_right_gpio, 1);
		printw("CAMERA RIGHT ROTATION [ENGAGED]");
	}
	else
	{
		camerarightswitch = false;
		digitalWrite(camera_y_right_gpio, 0);
		printw("CAMERA RIGHT ROTATION [DISENGAGED]");
	}
}

void helpmessage()
{
	mvprintw(1,0,"---HELPMESSAGE---");
	mvprintw(2,0,"Movekeys");
	mvprintw(3,1,"w - forward");
	mvprintw(4,1,"a - left");
	mvprintw(5,1,"s - backward");
	mvprintw(6,1,"d - right");
	mvprintw(7,1,"e - killall");
	mvprintw(8,0,"Lightkeys");
	mvprintw(9,1,"r - front light");
	mvprintw(10,1,"t - ground light");
	mvprintw(11,0,"Camera Movekeys");
	mvprintw(12,1,"u - cam up");
	mvprintw(13,1,"h - cam left");
	mvprintw(14,1,"j - cam down");
	mvprintw(15,1,"k - cam right");
	refresh();
}

void input()
{
	wiringPiSetup();
	pinMode(forward_gpio, OUTPUT);
	pinMode(backward_gpio, OUTPUT);
	pinMode(right_gpio, PWM_OUTPUT);
	pinMode(left_gpio, PWM_OUTPUT);
	pinMode(light_front, OUTPUT);
	pinMode(light_ground, OUTPUT);
	pinMode(camera_x_up_gpio, OUTPUT);
	pinMode(camera_x_down_gpio, OUTPUT);
	pinMode(camera_y_left_gpio, OUTPUT);
	pinMode(camera_y_right_gpio, OUTPUT);
	initscr();
	raw();
	noecho();
	printw("Input Module [LOADED]");
	refresh();
	int input_handler;
	while(true)
	{
		input_handler = getch();
		erase();
		switch(input_handler)
		{
			case 'w':
			{
				forward();
				break;
			}
			case 's':
			{
				backward();
				break;
			}
			case 'a':
			{
				left();
				break;
			}
			case 'd':
			{
				right();
				break;
			}
			case 'e':
			{
				mv_killall();
				break;
			}
			case 'r':
			{
				front_light();
				break;
			}
			case 't':
			{
				ground_light();
				break;
			}
			case 'u':
			{
				camera_up();
				break;
			}
			case 'j':
			{
				camera_down();
				break;
			}
			case 'h':
			{
				camera_left();
				break;
			}
			case 'k':
			{
				camera_right();
				break;
			}
			case 'i':
			{
				helpmessage();
				break;
			}
			case 'q':
			{
				killall();
				endwin();
				std::exit(EXIT_SUCCESS);
			}
		}
		refresh();
		x_move();
	}
}
#endif
