#include<Servo.h>

Servo MSx;
Servo MSy;

int counterx;
int countery;

const int axismaxx = 170;
const int axisminx = 10;
const int axismaxy = 170;
const int axisminy = 10;
//10° - 170° pivoting range

const int up = 9;
const int down = 8;
const int left = 7;
const int right = 6;

const int servox = 4;
const int servoy = 3;

const int reset = 10;

const int del = 25;
const int steps = 1;




void setup()
{
	//Serial.begin(9600); //For Serial communication
	MSx.attach(servox);
	MSy.attach(servoy);
	counterx = 90;
	countery = 90;

	pinMode(up, INPUT);
	pinMode(down, INPUT);
	pinMode(left, INPUT);
	pinMode(right, INPUT);
	pinMode(reset, INPUT);
}

void loop()
{
	MSx.write(counterx);
	MSy.write(countery);

	if(digitalRead(up) == HIGH)
	{
		counterx += steps;
	}

	if(digitalRead(down) == HIGH)
	{
		counterx -= steps;
  	}

	if(digitalRead(left) == HIGH)
	{
		countery += steps;
	}

	if(digitalRead(right) == HIGH)
	{
		countery -= steps;
	}

	if(counterx > axismaxx)
	{
		counterx = axismaxx;
	}

	if(counterx < axisminx)
	{
		counterx = axisminx;
	}

	if(countery > axismaxy)
	{
		countery = axismaxy;
	}

	if(countery < axisminy)
	{
		countery = axisminy;
	}

	ifreset();
	delay(del);
	ifreset();
}

void ifreset()
{
	if(digitalRead(reset) == HIGH)
	{
		while((counterx != 90) || (countery != 90))
		{
			if(counterx < 90)
			{
				counterx++;
			}

			if(counterx > 90)
			{
				counterx--;
			}

			if(countery < 90)
			{
				countery++;
			}

			if(countery > 90)
			{
				countery--;
			}

			MSx.write(counterx);
			MSy.write(countery);
			delay(del);
		}
	}
}

