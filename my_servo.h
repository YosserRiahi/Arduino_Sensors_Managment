#ifndef H_MY_SERVO
#define H_MY_SERVO

#include <Servo.h>

#include "my_config.h"




void openServo(uint8_t servoNum);
void openAllServo();
void closeAllServo();
void startservos();

#endif // H_MY_SERVO
