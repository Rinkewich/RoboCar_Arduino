/*
Library for the servo
Developer: Maksim Masalski
E-mail: maxxliferobot@gmail.com
*/

#include <Arduino.h>
#include "ServoRobotCar.h"
#include "Servo.h"

Servo inServo;

int ServoMotor::attach()
{
    inServo.attach(pinServo);
    inServo.write(90);
}

void ServoMotor::write(int servoValue)
{
    int angle=inServo.read();
    if(angle<servoValue)
    {
        for(angle; angle<servoValue; angle++)
        {
            inServo.write(angle);
            //Delay is necessary to make rotation of the servo smooth and do not burn it
            //Without that delay servo will burn due to high load
            delay(20);
        }
    }
    if(angle>servoValue)
    {
        for(angle; angle>servoValue; angle--)
        {
            inServo.write(angle);
            delay(20);
        }
    }

    if(angle==servoValue)
        inServo.write(angle);
}
int ServoMotor::read()
{
    //Measure signal which was written to the servo before
    //Result can be type int in range 0 to 180
    double value=inServo.read();


    return value;
}

