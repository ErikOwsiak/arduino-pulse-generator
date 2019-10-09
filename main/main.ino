#include "global.h"
#include "core.h"


void setup() {
   Serial.begin(38400);
   pinMode(LED_BUILTIN, OUTPUT);
   Serial.println("\n=== setup ===");
   for(uint8_t i = 0; i < PINCOUNT; i++)
      pins[i].Print();
   Serial.println("\n=== end setup ===\n");
   for(uint8_t i = 0; i < PINCOUNT; i++)
      pins[i].SetOn();
}

/* main loop */
void loop() {
   //pinSet();
   //allOn();
   //delay(1000);
   //serialPrint();
   //flashLed();
   digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
   delay(1000);
}
