#include "my_fingerPrint.h"

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&Serial2); // use RX2 and TX2

void startFingerPrint()
{
    while (!Serial);  // For Yun/Leo/Micro/Zero/...
        delay(100);
    Serial.println("\n\nAdafruit finger detect test");

    // set the data rate for the sensor serial port
    finger.begin(57600);

    if (finger.verifyPassword())
    {
        Serial.println("Found fingerprint sensor!");
    }
    else
     {
        Serial.println("Did not find fingerprint sensor :(");
        while (1) { delay(1); }
    }

    finger.getTemplateCount();
    Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
    Serial.println("Waiting for valid finger...");
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintID()
{
    uint8_t p = finger.getImage();
    if (p != FINGERPRINT_OK)  return -1;

    p = finger.image2Tz();
    if (p != FINGERPRINT_OK)  return -1;

    p = finger.fingerFastSearch();
    if (p != FINGERPRINT_OK)  return -1;

    // found a match!
    Serial.print("Found ID #"); Serial.print(finger.fingerID); 
    Serial.print(" with confidence of "); Serial.println(finger.confidence);
    return finger.fingerID; 
}
