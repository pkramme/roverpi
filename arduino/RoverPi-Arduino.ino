//RoverPi Arduino Software
//not completed yet

#include <Servo.h>


Servo MSx;
Servo MSy;

int counterx;
int countery;

const int servosensitivity = 600;
const int drivesensitivity = 1020;
const int drivespeed = 255;
const int brightness = 255;

const int axismaxx = 170;
const int axisminx = 10;
const int axismaxy = 170;
const int axisminy = 10;
//10° - 170° pivoting range

const int del = 50;
const int steps = 1;

const int servoup = 50;
const int servodown = 48;
const int servoleft = 46;
const int servoright = 44;

const int inforward = 51;
const int inbackward = 49;
const int inleft = 47;
const int inright = 45;

const int reset = 42;

const int inlight = 40;
const int outlight = 13;

const int servox = 38;
const int servoy = 36;

const int outforward = 9;
const int outbackward = 8;
const int outleft = 7;
const int outright = 6;

int forwardstat = 0;
int backwardstat = 0;
int leftstat = 0;
int rightstat = 0;

float lightstat = 0;


void setup()
{
     Serial.begin(19200); //For Serial communication
     servosettings();
     pinsettings();
     drivekill();
}

void loop()
{
     debug();
     servoloop();
     driveloop();
     lightloop();

     ifreset();
     delay(del);
     ifreset();
}

void ifreset()
{
     if(digitalRead(reset) == HIGH)
     {
          servosetup();
     }
}


void servosetup()
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


void servotest()
{
     //Servotest
     MSx.write(15);
     MSy.write(15);
     delay(500);
     MSx.write(160);
     MSy.write(160);
     delay(500);
}


void servoloop()
{
     MSx.write(counterx);
     MSy.write(countery);

     if(digitalRead(servoup) == HIGH)
     {
          counterx += steps;
     }

     if(digitalRead(servodown) == HIGH)
     {
          counterx -= steps;
     }

     if(digitalRead(servoleft) == HIGH)
     {
          countery += steps;
     }

     if(digitalRead(servoright) == HIGH)
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
}


void driveloop()
{
     analogWrite(outforward,forwardstat);
     analogWrite(outbackward,backwardstat);
     analogWrite(outleft,leftstat);
     analogWrite(outright,rightstat);

     if((digitalRead(inforward)+digitalRead(inbackward)+digitalRead(inleft)+digitalRead(inright))>=2)
     {
          drivekill();
          delay(100);
          return 0;
     }

     if(digitalRead(inforward)== HIGH)
     {
          backwardstat = 0;
          leftstat = 0;
          rightstat = 0;
          delay(1);

          forwardstat=drivespeed;

          return 0;
     }
     if(digitalRead(inbackward)== HIGH)
     {
          forwardstat = 0;
          leftstat = 0;
          rightstat = 0;
          delay(1);
          backwardstat=drivespeed;
          return 0;
     }

     if(digitalRead(inleft)== HIGH)
     {
          forwardstat = 0;
          backwardstat = 0;
          rightstat = 0;
          delay(1);

          leftstat=drivespeed;

          return 0;
     }

     if(digitalRead(inright)== HIGH)
     {
          forwardstat = 0;
          backwardstat = 0;
          leftstat = 0;
          delay(1);

          rightstat=drivespeed;

          return 0;
     }
     else{drivekill();}
}

void drivekill(){
    forwardstat = 0;
    backwardstat = 0;
    leftstat = 0;
    rightstat = 0;

    analogWrite(outforward,0);
    analogWrite(outbackward,0);
    analogWrite(outleft,0);
    analogWrite(outright,0);
}

void lightloop(){

  if(digitalRead(inlight)==HIGH){
    lightup();
    }
   else {
    lightfade();
    }

}

void debug(){
  Serial.print("F: ");
  Serial.print(digitalRead(inforward));
  Serial.print("  ");
  //Serial.print(forwardstat);
  Serial.print("\t");

  Serial.print("B: ");
  Serial.print(digitalRead(inbackward));
  Serial.print("  ");
  //Serial.print(backwardstat);
  Serial.print("\t");

  Serial.print("L: ");
  Serial.print(digitalRead(inleft));
  Serial.print("  ");
  //Serial.print(leftstat);
  Serial.print("\t");

  Serial.print("R: ");
  Serial.print(digitalRead(inright));
  Serial.print("  ");
  //Serial.print(rightstat);
  Serial.print("\t");

  Serial.print("GE: ");
  Serial.print((digitalRead(inforward)+digitalRead(inbackward)+digitalRead(inleft)+digitalRead(inright)));
  Serial.print("\t");

  Serial.print("Light: ");
  Serial.print(digitalRead(inlight));
  Serial.print("  ");
  Serial.print(lightstat);
  Serial.print("\t");

  Serial.print("\n");

}

void servosettings(){
  MSx.attach(servox);
  MSy.attach(servoy);
  counterx = 90;
  countery = 90;
  MSx.write(counterx);
  MSy.write(countery);
}

void lightup(){

  if(lightstat<brightness){
    lightstat = lightstat + 5;
    lightstat = lightstat * 1.3;

    if (lightstat>brightness){
      lightstat = brightness;
    }
    analogWrite(outlight,lightstat);
    delay(1);
    }
 }

void lightfade(){
  if(lightstat>=1){
    lightstat = lightstat-100;
    if(lightstat<0){
      lightstat=0;
    }
    analogWrite(outlight,lightstat);
    delay(1);
  }
}

void pinsettings(){
  pinMode(inforward,INPUT);
  pinMode(inbackward,INPUT);
  pinMode(inleft,INPUT);
  pinMode(inright,INPUT);

  pinMode(outforward,OUTPUT);
  pinMode(outbackward,OUTPUT);
  pinMode(outleft,OUTPUT);
  pinMode(outright,OUTPUT);

  pinMode(inlight,INPUT);
  pinMode(outlight,OUTPUT);
}

/* acceleration
void facceleration(){
    if (forwardstat<drivespeed){
      while (forwardstat<drivespeed){
  forwardstat=forwardstat+1;
  if (forwardstat>drivespeed){
    forwardstat = drivespeed;
    }
  delay(1);
  analogWrite(outforward,forwardstat);
      }
   }
}

void bacceleration(){
    if (backwardstat<drivespeed){
      while (backwardstat<drivespeed){
  backwardstat=backwardstat+1;
  if (backwardstat>drivespeed){
    backwardstat = drivespeed;
    }
  delay(1);
  analogWrite(outbackward,backwardstat);
      }
   }
}

void lacceleration(){
    if (leftstat<drivespeed){
      while (leftstat<drivespeed){
  leftstat=leftstat+1;
  if (leftstat>drivespeed){
    leftstat = drivespeed;
    }
  delay(1);
  analogWrite(outleft,leftstat);
      }
   }
}

void racceleration(){
    if (rightstat<drivespeed){
      while (rightstat<drivespeed){
  rightstat=rightstat+1;
  if (rightstat>drivespeed){
    rightstat = drivespeed;
    }
  delay(1);
  analogWrite(outright,rightstat);
      }
   }
}
*/
