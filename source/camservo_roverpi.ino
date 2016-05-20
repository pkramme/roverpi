#include <Servo.h>

Servo MS1;
Servo MS2;
int counter1;
int counter2;
//10° - 170° Drehbereich

int del = 100;
int schritte = 1;

//Defines here

void setup()
{
	Serial.begin(9600);
	MS1.attach(4);
	MS2.attach(3);
	counter1 = 90;
	counter2 = 90;
	pinMode(7,INPUT);
	pinMode(6,INPUT);

	pinMode(9,INPUT);
	pinMode(8,INPUT);
	MS1.write(15);
	MS2.write(15);
	delay(300);
	MS1.write(160);
	MS2.write(160);
	delay(500);
}

void loop()
{
	Serial.print(counter1);
	Serial.print("\t");
	Serial.println(counter2);
	MS1.write(counter1);
	MS2.write(counter2);

	if(digitalRead(7)==HIGH)
	{
		counter1 = counter1 + schritte;
		delay(del);
	}

	if(digitalRead(6)==HIGH)
	{
		counter1 = counter1 - schritte;
		delay(del);
	}

	if(digitalRead(9)==HIGH)
	{
		counter2 = counter2 + schritte;
		delay(del);
	}

	if(digitalRead(8)==HIGH)
	{
		counter2 = counter2 - schritte;
		delay(del);
	}

	if(counter1>170)
	{
		counter1 = 170;
	}

	if(counter1<10)
	{
		counter1 = 10;
	}

	if(counter2>170)
	{
		counter2 = 170;
	}

	if(counter2<10)
	{
		counter2 = 10;
	}
}
