#include "my_input_output.h"

void alarm(bool state) 
{
	if(state)
		digitalWrite(BUUZZER_PIN, HIGH); // buzzer on
	else
		digitalWrite(BUUZZER_PIN, LOW);  //  // buzzer off
}

bool getSensorsGazState()
{
	if(!digitalRead(GAZ_SENSOR_PIN)) 
		return true;
	else
		return false;
}

bool getButtonOpenZoneState()
{
	if(!digitalRead(OPEN_ZONES_BUTTON_PIN)) //attention pullup
		return true;
	else
		return false;
}


