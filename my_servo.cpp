#include "my_servo.h"
#include <Servo.h>

Servo Zone1_Servo, Zone2_Servo, Zone3_Servo ;

void openServo(uint8_t servoNum)
{
    Serial.println("ouverture servo");
    Servo * servo ; // pointer to servo

    switch(servoNum)
    {
        case 1 :
          servo = &Zone1_Servo; 
        case 2 :
          servo = &Zone2_Servo;
        case 3 :
          servo = &Zone3_Servo;
    }

    servo->write(0); 
    delay(3000) ; 
    servo->write(90); 
    delay(3000) ;
}

void openAllServo()
{
    Zone1_Servo.write(90);
    Zone2_Servo.write(90);
    Zone3_Servo.write(90);
}

void closeAllServo()
{
    Zone1_Servo.write(0);
    Zone2_Servo.write(0);
    Zone3_Servo.write(0);
}

void startservos()
{
    Zone1_Servo.attach(SERVO1_PIN);
    Zone2_Servo.attach(SERVO2_PIN);
    Zone3_Servo.attach(SERVO3_PIN);
}

