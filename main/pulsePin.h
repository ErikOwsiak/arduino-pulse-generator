
#include <Arduino.h>
#ifndef PulsePin_h
#define PulsePin_h

/* pin, MS pin is on 'width', 
   MS pin is off 'width', tick counter */ 

class PulsePin {

   public:
      /* pname, pin, onwith, offwith */
      PulsePin(char*, uint8_t, uint16_t, uint16_t);
      void Tick();
      char* PinName();
      uint8_t Pin();
      void Print();
      void SetOn();
      
   private:
      char* pinName;
      uint8_t pin;
      uint8_t pinVal;
      uint16_t msPinOnWidth;
      uint16_t msPinOffWidth;
      uint16_t pulseOffCounter;
      uint16_t pulseOnCounter;
      uint32_t tickCounter;
};

#endif
