/*
���������� Servo �� ���������� ������������� TowePro MG996R � ��������� �1.
������ v1.1

������ � ������ �� ������������� �� ������! mrobot.by
http://www.mrobot.by

����������� ������ �����������
���: maxxlife
E-mail: maxxlife@mrobot.by
*/

#include <Arduino.h>
#include "Servo.h"
class ServoMotor
{
private:
	int pinServo=5;
    public:
  int attach();
  void write(int);
  int read();

};
