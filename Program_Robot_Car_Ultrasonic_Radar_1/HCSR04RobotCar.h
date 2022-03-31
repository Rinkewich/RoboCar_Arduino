/*
Library for the ultrasonic distance sensor HC-SR04
Developer: Maksim Masalski
E-mail: maxxliferobot@gmail.com
*/

#include <Arduino.h>

class Ultrasonic
{
  public:
    void attach();
    int read();
};
