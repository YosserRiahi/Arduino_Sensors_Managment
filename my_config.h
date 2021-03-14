#ifndef H_MY_CONFIG
#define H_MY_CONFIG
#include <LiquidCrystal_I2C.h>

#define ADDRESS_I2C_LCD 0x3F 
 

#include "Arduino.h" //include arduino function (delay, ....etc)


//--------- input/output -------------
#define BUUZZER_PIN 59
#define OPEN_ZONES_BUTTON_PIN 60
#define GAZ_SENSOR_PIN 61
//--------keypad -------------
#define ROW1_PIN 62
#define ROW2_PIN 63
#define ROW3_PIN 64
#define ROW4_PIN 65

#define COL1_PIN 66
#define COL2_PIN 67
#define COL3_PIN 68

#define KEYPAD_ROWS_NUMBER 4
#define KEYPAD_COLS_NUMBER 3

//-------- servo ------------
#define SERVO1_PIN 11
#define SERVO2_PIN 12
#define SERVO3_PIN 13
//-------- RFID -------------
#define RST_PIN 8
#define SS_PIN 9
//------------------------




#endif //H_MY_CONFIG
