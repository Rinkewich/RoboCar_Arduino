/*
Library for the motors control using L298N driver
Developer: Maksim Masalski
E-mail: maxxliferobot@gmail.com
*/


#include <Arduino.h>

class Motors
{
private:
    //motor 1
    int enA = 8;
    int in1 = 9;
    int in2 = 10;
    // motor 2
    int enB = 13;
    int in3 = 11;
    int in4 = 12;
public:
    void attach();
    void write(int, int);
};
