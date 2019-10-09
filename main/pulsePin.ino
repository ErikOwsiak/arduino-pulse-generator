
#include "pulsePin.h"

PulsePin::PulsePin(char* pn, uint8_t pin, uint16_t msOnWidth, uint16_t msOffWidth) {
   pinMode(pin, OUTPUT);
   this->pinVal = LOW;
   digitalWrite(pin, this->pinVal);
   this->pinName = pn;
   this->pin = pin;
   this->msPinOnWidth = msOnWidth;
   this->msPinOffWidth = msOffWidth;
   this->pulseOffCounter = 0;
   this->pulseOnCounter = 0;
   this->tickCounter = 0;
}

void PulsePin::Tick() {
   
   this->pinVal = digitalRead(this->pin);
   if((this->pinVal == LOW) && (this->pulseOffCounter <= this->msPinOffWidth)){
      this->pulseOffCounter++;
      return;
   }

   if((this->pinVal == LOW) && (this->pulseOffCounter >= this->msPinOffWidth)){
      digitalWrite(this->pin, HIGH);
      this->pulseOffCounter = 0;
      this->tickCounter++;
      return;
   }

   if((this->pinVal == HIGH) && (this->pulseOnCounter <= this->msPinOnWidth)){
      this->pulseOnCounter++;
      return;
   }
   
   if((this->pinVal == HIGH) && (this->pulseOnCounter >= this->msPinOnWidth)){
      digitalWrite(this->pin, LOW);
      this->pulseOnCounter = 0;
      return;
   }
   /* end */
   return;   
}

char* PulsePin::PinName() {
   return this->pinName;   
}

uint8_t PulsePin::Pin() {
   return this->pin;
}

void PulsePin::SetOn() {
   digitalWrite(this->pin, HIGH);
}

void PulsePin::Print() {
   Serial.print(this->pinName);
   Serial.print(":");
   Serial.print(this->pin);
   Serial.print(":");
   Serial.print(this->tickCounter);
   Serial.print("; ");
}
