#include "pulsePin.h"

#ifndef GLOBAL_H
#define GLOBAL_H

#define SEC 1000
#define MS500 500
#define MINUTE2 (SEC * 122)

uint32_t ms_top = 0;
uint16_t led_counter = 0;
uint16_t loop_counter = 0;
uint16_t TICKOFFSET = 935;
uint16_t SEC_COUNTER = 0;

/*PulsePin(char* pn, uint8_t pin, uint16_t msOnWidth
   , uint16_t msOffWidth, uint16_t msStateChange)*/
PulsePin p0 = PulsePin("D4", 4, 80, 2000);
PulsePin p1 = PulsePin("D5", 5, 80, 1000);
PulsePin p2 = PulsePin("D6", 6, 100, 8000);
PulsePin p3 = PulsePin("D7", 7, 80, 800);
PulsePin p4 = PulsePin("D8", 8, 100, 2000);
PulsePin p5 = PulsePin("D9", 9, 80, 1000);
PulsePin p6 = PulsePin("D10", 10, 100, 1000);
PulsePin p7 = PulsePin("D11", 11, 120, 1200);
PulsePin p8 = PulsePin("D12", 12, 80, 1000);

/* num of pins */
uint8_t PINCOUNT = 9;

/* holds all pins */
PulsePin pins[] = {p0, p1, p2, p3, p4, p5, p6, p7, p8};

#endif
