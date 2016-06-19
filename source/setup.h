#ifndef __SETUP_H_INCLUDED__
#define __SETUP_H_INCLUDED__

void setup()
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
	pinMode(quitpin_gpio, OUTPUT);
}

#endif
