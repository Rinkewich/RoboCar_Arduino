/* Program for the robot test ultrasonic distance sensors
    All measurements are going to the Serial port speed is 9600
*/

//Include all necessary files to control ultrasonic distance sensor and rotate servo
#include "HCSR04RobotCar.h"
#include "ServoRobotCar.h"
#include "MotorL298NRobotCar.h"
//Create class instance for the ultrasonic distance sensor
Ultrasonic myUltrasonic;
ServoMotor myServo;
Motors myMotors;
//Setup all class instances and attach them to the necessary ports
void setup() {
  //Serial port attach on the speed 9600
  Serial.begin(9600);
  myUltrasonic.attach();
  myServo.attach();
  myMotors.attach();
  myServo.write(90);
  delay(100);
}
void pin(int speed_right, int speed_left, char r)
{
  int i = 0;
  if (r == 'r')
  {
    for (i; i < 100; i++)
    {
      myMotors.write(speed_right, speed_left); // Rotate motors forward and gain speed smoothly using for
      delay(10); // delay to make accleration smoothly
    }
  }
  else
  {
    for (i; i < 20; i++)
    {
      myMotors.write(speed_right, speed_left); // Rotate motors forward and gain speed smoothly using for
      delay(10); // delay to make accleration smoothly
    }
  }
}
void loop() {
  pin(0,0, 'f');
  myServo.write(90); //Set servo in the middle position
  delay(100); //Wait 1 second
  if (myUltrasonic.read() < 20) 
  {
    myServo.write(50); //Turn servo right
    if (myUltrasonic.read() < 20) 
    { 
      delay(200); //Wait 1 second
      myServo.write(130);  //Turn servo left
      if (myUltrasonic.read() < 20) 
      { 
        //Robot is going backward myMotors.write(LEFT MOTOR, RIGHT MOTOR)
        pin(220, 220, 'b'); 
        pin(255, -100, 'r'); //Robot turns to the right
        
       // pin(-220, -220, 'f'); //Robot is running straight forward
      }
      else
      {
        delay(200); //Wait 1 second
        myServo.write(90); //Set servo in the middle position
        pin(255, -100, 'r'); //Robot turns to the right
      }
    }
    else
    {
      myServo.write(90); //Set servo in the middle position
    //  pin(255, -100); //Robot turns to the right
      pin(-100, 255, 'r'); //Robot turns to the left
    }
  } 
  else 
  {
   pin(-220, -220, 'f'); //Robot is running straight forward 
  }
}
