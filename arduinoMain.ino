#include "my_config.h"
#include "my_keypad.h"
#include "my_rfid.h"
#include "my_servo.h"
#include "my_xbee.h"
#include "my_input_output.h"
#include "my_fingerPrint.h"

bool alarmState = false;

void setup() 
{
    pinMode(BUUZZER_PIN, OUTPUT);
    pinMode(OPEN_ZONES_BUTTON_PIN, INPUT_PULLUP);
    pinMode(GAZ_SENSOR_PIN, INPUT_PULLUP);alarm(false);
    startRFID();
    startFingerPrint();
    startXbee();
    startservos();
    closeAllServo();
    startLcd();
    Serial.begin(9600);
}

void loop() 
{
    //--------------------------------------------------------
    String _pin = getPIN();
    if(_pin.length())
    {
        sendXbee("z1;" + _pin);
    }
    //--------------------------------------------------------
    String _tag = TestRFID();
    if(_tag.length())
    {
        sendXbee("z2;" + _tag);
    }
    //--------------------------------------------------------
    int _fingerID = getFingerprintID();
    if(_fingerID > 0)
    {
        sendXbee("z3;" + String(_fingerID));
    }
    //--------------------------------------------------------
    bool _SensorsGazState = getSensorsGazState();
    if(_SensorsGazState)
    {
        alarm(true);
        delay(5000);
        alarm(false);
    }
    //--------------------------------------------------------
    bool  _ButtonOpenZoneState = getButtonOpenZoneState();
    if(_ButtonOpenZoneState)
    {
        alarmState = (!alarmState);
        if(alarmState){openAllServo();}
        else{ closeAllServo();}
        delay(500);
    }
    //--------------------------------------------------------
    String _receivedData = receiveXbee();
    if(_receivedData.charAt(0) == 's')
    {
        uint8_t _servo = _receivedData.charAt(1) - 48;
        Serial.println(_servo);
        openServo(_servo);
    }
}

