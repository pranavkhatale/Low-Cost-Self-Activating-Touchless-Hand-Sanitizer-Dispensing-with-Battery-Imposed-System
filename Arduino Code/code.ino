/*
 Project Name : Low Cost Self-Activating Touchless Hand Sanitizer Dispensing with Battery Imposed System
 Written by: Pranav Khatale, Shivani K., Shubham Kajale
 February 2021

 For complete details of project visit: https://github.com/pranavkhatale/Low-Cost-Self-Activating-Touchless-Hand-Sanitizer-Dispensing-with-Battery-Imposed-System
 */
 
#include<Servo.h>
#define pinServo 2
Servo S1;
int degree = 0;
long cm = 0;
long readUltrasonicDistance (int triggerPin, int echoPin)
{
 pinMode (triggerPin, OUTPUT);
 digitalWrite (triggerPin, LOW); //sets the trigger pin off
 delayMicroseconds (2);
 digitalWrite (triggerPin, HIGH);
 delayMicroseconds (10);
 digitalWrite (triggerPin, LOW);
 pinMode (echoPin, INPUT);//sets the echo pin as input
 return (pulseIn(echoPin, HIGH)*0.01723);
}
void setup ()
{
 S1.attach(pinServo);
 Serial.begin (9600); //initialize serial communication
 S1.write (0); //set servo to 0 degree
 delay (2000);
 pinMode (2, OUTPUT);
}

void loop ()
{
 cm = readUltrasonicDistance ( 5, 4);
 Serial.print(cm);
 Serial.println ("cm");
 if (cm > 40) {
 digitalWrite (2, LOW);
 S1.write(0);
 }
 if (cm <= 40)
 {
 digitalWrite (2, HIGH);
 S1.write(60);
 delay (500);
 S1.write(0);
 delay (3000);
 }
 delay (100);
}
