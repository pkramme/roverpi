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
#include <Servo.h>

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

 /* //Servotest
 MSx.write(15);
 MSy.write(15);
 delay(300);
 MSx.write(160);
 MSy.write(160);
 delay(500);
 */
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
