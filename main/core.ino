
#include <Arduino.h>
#include "core.h"

void flashLed(void) {
   if(led_counter++ == MS500){
      digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
      led_counter = 0;
   }
}

void serialPrint(void) {
   if(loop_counter++ == SEC){
      Serial.print("diff: ");
      Serial.println(millis() - ms_top);
      loop_counter = 0;
      /* do dump */
      if(SEC_COUNTER++ == 120){
         Serial.println("\n== 2min dump ===");
         for(uint8_t i = 0; i < PINCOUNT; i++)
            pins[i].Print();
         Serial.println("\n== end 2min dump ===\n");
         SEC_COUNTER = 0;
      }
   }
}

void pinSet(void) {
   /* - - */
   if(loop_counter == 0)
      ms_top = millis();
   /* time of the pins loop + TICKOFFSET
      let the loop run at 1kHz */
   for(uint8_t i = 0; i < PINCOUNT; i++)
      pins[i].Tick();
   /* run at 1kHz */
   delayMicroseconds(TICKOFFSET);
}

void allOn() {
   for(uint8_t i = 0; i < PINCOUNT; i++)
      pins[i].SetOn();
}
