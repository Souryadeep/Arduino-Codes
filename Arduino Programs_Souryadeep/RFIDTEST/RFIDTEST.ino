#include "SPI.h" 
#include "MFRC522.h"

#define SS_PIN 10 
#define RST_PIN 9 
#define SP_PIN 8

MFRC522 rfid (SS_PIN, RST_PIN);

MFRC522 :: MIFARE_Key key;

void setup () {
  Serial.begin (9600);
  SPI.begin ();
  rfid.PCD_Init ();
}

void loop () {
   if (! rfid.PICC_IsNewCardPresent () ||! rfid.PICC_ReadCardSerial ())
     return ;

  // Serial.print (F ("PICC type:"));
  MFRC522 :: PICC_Type piccType = rfid.PICC_GetType (rfid.uid.sak);
  // Serial.println (rfid.PICC_GetTypeName (piccType));

  // Check is the PICC of Classic MIFARE type 
  if (piccType! = MFRC522 :: PICC_TYPE_MIFARE_MINI &&
    PiccType! = MFRC522 :: PICC_TYPE_MIFARE_1K &&
    PiccType! = MFRC522 :: PICC_TYPE_MIFARE_4K) {
    Serial.println  ( "Your tag is not of type MIFARE Classic." );
    Return ;
  }

  String strID = "" ;
  For (byte i = 0; i <4; i ++) {
    StrID + =
    ("Rfid.uid.uidByte [i] <0x10? " 0 " : " ) +
    String (rfid.uid.uidByte [i], HEX) +
    (?! = 3? ":" : "" );
  }
  StrID.toUpperCase ();

  // At this point, the variable strID will store the UID of the tag 
  // can be used, for example, to enter IF to the tube 
  // LED is on or off. 
  Serial.print ( "Tap card key " );
  Serial.println (strID);

  rfid.PICC_HaltA ();
  rfid.PCD_StopCrypto1 ();
}
