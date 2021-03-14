#include "my_keypad.h"

enum PinState{
    Empty,
    WrittingId,
    WrittingPin
} pinState;

String codePin = "" ;
String hiddenCode = "" ;
String empID = "";

//----------------------- keypad config --------------------------   
char keys[KEYPAD_ROWS_NUMBER][KEYPAD_COLS_NUMBER] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
};

byte rowPins[KEYPAD_ROWS_NUMBER] = { ROW1_PIN, ROW2_PIN, ROW3_PIN, ROW4_PIN };
byte colPins[KEYPAD_COLS_NUMBER] = { COL1_PIN, COL2_PIN, COL3_PIN };

Keypad kpd = Keypad(makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS_NUMBER, KEYPAD_COLS_NUMBER);
LiquidCrystal_I2C lcd(ADDRESS_I2C_LCD, 20, 4);

String getPIN()
{ 
    char key = kpd.getKey();
    String ret = ""; // returned string
    if (key) 
    {
        // reset
        if (key == '#')
        {
            codePin = hiddenCode = empID =  "";
            lcd.clear();
            Serial.println("reset Keypad\n\n");
        }
        // first keypad press
        else if(pinState == Empty)
        {
            if(key != '*')
            {
                pinState = WrittingId;
                Serial.println("Enter your ID");
                lcd.setCursor(1,0);
                lcd.print("Enter your ID");
                empID +=key;
                Serial.println(empID);
                lcd.setCursor(2,1);
                lcd.print(empID);
            }
        }
        // writting ID
        else if(pinState == WrittingId)
        {
            if(key != '*')
            {
                empID +=key;
                Serial.println(empID);
                lcd.print(key);
            }
            else if (key == '*')
            {
                pinState = WrittingPin;
                Serial.println("Enter your Pin");
                lcd.clear();
                lcd.setCursor(1,0);
                lcd.print("Enter your Pin");
            }
        }
        // writting pin
        else if(pinState == WrittingPin)
        {
            if(key != '*')
            {
                codePin +=key ;
                hiddenCode +='*' ;
                Serial.println(hiddenCode);
                lcd.setCursor(2,1);
                lcd.print(hiddenCode);
            }
            else if (key == '*')
            {
                ret = empID + ";" + codePin;
                pinState = Empty;
                codePin = hiddenCode = empID = "" ;
                lcd.clear();
            }
        }
    }      
    return ret;
}

void startLcd()
{
    lcd.begin();
}

