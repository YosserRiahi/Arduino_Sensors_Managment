#include "my_rfid.h"

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

void startRFID()
{
    SPI.begin();        // Init SPI bus
    mfrc522.PCD_Init(); // Init MFRC522 card
}

String TestRFID()
{

    if ( ! mfrc522.PICC_IsNewCardPresent()) 
    {
        return "";
    } 

    // Select one of the cards
    if ( ! mfrc522.PICC_ReadCardSerial()) 
    {
        return "";
    }

    byte card_ID[4];
    String code = "" ;

    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        card_ID[i]=mfrc522.uid.uidByte[i];
        String card_ID_hex = String(card_ID[i], HEX); //byte to hex exemple 255 --> ff
        card_ID_hex.toUpperCase();// exemple ff--> FF
        code += card_ID_hex;  
    }
    Serial.println(code);
    return code;
}

