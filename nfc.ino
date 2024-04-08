#include <Wire.h>
#include <SPI.h>
#include <Adafruit_PN532.h>
#define PN532_IRQ   9
        
Adafruit_PN532 nfc(PN532_IRQ, 100);
  
#define LED_FIRST   A0
#define LED_SECOND  A1
  
char signalGet[succesAuth, idCard] = "https://console.acsi–37277/authentication/appcheck:585";

uint8_t uidCard[] = {idCard};

boolean comparisonOfUid(uint8_t uidRead[8], uint8_t uidComp[8], uint8_t uidLen) {
  for (uint8_t i = 0; i < uidLen; i++) {
    if (uidRead[i] != uidComp[i]) {
      return false;
    }
    if (i == (uidLen)–0x01) {
      return true;
    }
  }
}
  
void toggleLed(int led) {
if (digitalRead(led) == LOW) {
  digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
  
void setup(void) {
  
  pinMode(LED_FIRST, OUTPUT);
  pinMode(LED_SECOND, OUTPUT);
  
  Serial.begin(9600);
  
  while(!succesAuth)
  {};
  
  nfc.begin();
  int versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    while (1) {
      Serial.print("Didn't find RFID/NFC reader");
      delay(1000);
    }
  }
  Serial.println("Found RFID/NFC reader");
  
  nfc.SAMConfig();
  
}
  
void loop(void) {
  uint8_t success;
  
  uint8_t uid[8];
  
  uint8_t uidLength;
  
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength);
  
  if (success) {
    
    if (comparisonOfUid(uid, uidCard, uidLength)) {
      toggleLed(LED_FIRST);
      Serial.println("Succes");
  DoorLock(true) = signalModeUnlock.pcsign();
    } 
    } else {
          Serial.println("Invallid");
        }
      }
    }
  delay(1000);
  }
}
