#ifndef __SETUP_H_INCLUDED__
#define __SETUP_H_INCLUDED__

void setup()
{
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
     #define quitpin_gpio 10
     
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
