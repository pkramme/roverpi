#include<iostream>
#include<ncurses.h>
#include<wiringPi.h>
#include<cstdlib>

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

//GPIO pins
#define forward_gpio 26
#define backward_gpio 23
#define right_gpio 2
#define left_gpio 3
#define light_front 4
#define light_ground 5
#define camera_x_down_gpio 6
#define camera_x_up_gpio 27 //7 is lighted
#define camera_y_left_gpio 8
#define camera_y_right_gpio 9

int y_pwmswitch = 0;

#define std_d 10//standart delay in ms

void mv_killall()
{
	pwmWrite(forward_gpio, 0);
	forwardswitch = false;
	pwmWrite(backward_gpio, 0);
	backwardswitch = false;
	y_pwmswitch = 0;

	if(leftswitch == true)
	{
		leftswitch = false;
		digitalWrite(left_gpio, 0);
		delay(std_d);
	}

	if(rightswitch == true)
	{
		rightswitch = false;
		digitalWrite(right_gpio, 0);
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
	y_pwmswitch += 100;
	if(y_pwmswitch >= 1000)
	{
		y_pwmswitch = 1000;
	}
}

void backward()
{
	y_pwmswitch -= 100;
	if(y_pwmswitch <= -1000)
	{
		y_pwmswitch = -1000;
	}
}

void x_move()
{
	if(y_pwmswitch > 0)
	{
		if(rightswitch == false && leftswitch == false)
		{
			pwmWrite(forward_gpio, y_pwmswitch);
			pwmWrite(backward_gpio, 0);
			forwardswitch = true;
		}
		else
		{
			if(rightswitch == true)
			{
				rightswitch = false;
				digitalWrite(right_gpio, 0);
				delay(std_d);
			}

			if(leftswitch == true)
			{
				leftswitch = false;
				digitalWrite(left_gpio, 0);
				delay(std_d);
			}
		}
	}
	else if(y_pwmswitch < 0)
	{
		if(rightswitch == false && leftswitch == false)
		{
			pwmWrite(backward_gpio, y_pwmswitch*(-1));//unsigned int in wiringPi class needs inverted negative int input...
			pwmWrite(forward_gpio, 0);
			backwardswitch = true;
		}
		else
		{
			if(rightswitch == true)
			{
				rightswitch = false;
				digitalWrite(right_gpio, 0);
				delay(std_d);
			}

			if(leftswitch == true)
			{
				leftswitch = false;
				digitalWrite(left_gpio, 0);
				delay(std_d);
			}
		}
	}
	else if(y_pwmswitch == 0)
	{
		pwmWrite(forward_gpio, 0);
		pwmWrite(backward_gpio, 0);
	}
}

void left()
{
	if(leftswitch == false)
	{
		if(forwardswitch == true)
		{
			forwardswitch = false;
			pwmWrite(forward_gpio, 0);
			y_pwmswitch = 0;
			delay(std_d);
		}

		if(backwardswitch == true)
		{
			backwardswitch = false;
			digitalWrite(backward_gpio, 0);
			y_pwmswitch = 0;
			delay(std_d);
		}

		if(rightswitch == true)
		{
			rightswitch = false;
			digitalWrite(right_gpio, 0);
			delay(std_d);
		}

		leftswitch = true;
		digitalWrite(left_gpio, 1);
		delay(std_d);

		printw("LEFT");
	}
	else
	{
		mv_killall();
	}
}

void right()
{
	if(rightswitch == false)
	{
		if(forwardswitch == true)
		{
			forwardswitch = false;
			pwmWrite(forward_gpio, 0);
			y_pwmswitch = 0;
			delay(std_d);
		}

		if(backwardswitch == true)
		{
			backwardswitch = false;
			digitalWrite(backward_gpio, 0);
			y_pwmswitch = 0;
			delay(std_d);
		}

		if(leftswitch == true)
		{
			leftswitch = false;
			digitalWrite(left_gpio, 0);
			delay(std_d);
		}

		rightswitch = true;
		digitalWrite(right_gpio, 1);
		delay(std_d);

		printw("RIGHT");
	}
	else
	{
		mv_killall();
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
		printw("CAMERA UP ROTATION ENGAGED");
	}
	else
	{
		cameraupswitch = false;
		digitalWrite(camera_x_up_gpio, 0);
		printw("CAMERA UP ROTATION DISENGAGED");
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
		printw("CAMERA DOWN ROTATION ENGAGED");
	}
	else
	{
		cameradownswitch = false;
		digitalWrite(camera_x_down_gpio, 0);
		printw("CAMERA DOWN ROTATION DISENGAGED");
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
		printw("CAMERA LEFT ROTATION ENGAGED");
	}
	else
	{
		cameraleftswitch = false;
		digitalWrite(camera_y_left_gpio, 0);
		printw("CAMERA LEFT ROTATION DISENGAGED");
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
		printw("CAMERA RIGHT ROTATION ENGAGED");
	}
	else
	{
		camerarightswitch = false;
		digitalWrite(camera_y_right_gpio, 0);
		printw("CAMERA RIGHT ROTATION DISENGAGED");
	}
}

void input()
{
	wiringPiSetup();
	pinMode(forward_gpio, PWM_OUTPUT);
	pinMode(backward_gpio, PWM_OUTPUT);
	pinMode(right_gpio, OUTPUT);
	pinMode(left_gpio, OUTPUT);
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
				forward();
				break;
			case 's':
				backward();
				break;
			case 'a':
				left();
				refresh();
				break;
			case 'd':
				right();
				break;
			case 'e':
				front_light();
				break;
			case 'r':
				ground_light();
				break;
			case 'u':
				camera_up();
				break;
			case 'j':
				camera_down();
				break;
			case 'h':
				camera_left();
				break;
			case 'k':
				camera_right();
				break;
			case 'i':
				printw("HELPMSG\nw : forward\ns : backward\na : left\nd : right\n\ne : frontlight\nr : groundlight\n\nu : camera up\nj : camera down\nh : camera left\nl : camera right\nq : quit\n");
			case 'q':
				killall();
				endwin();
				std::exit(EXIT_SUCCESS);
		}
		refresh();
		x_move();
	}
}
