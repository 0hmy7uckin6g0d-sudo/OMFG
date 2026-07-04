// hw_radio.cpp
#include "hw_radio.h"
void radio_init() {}
void radio_jam(uint32_t freq, uint8_t power) { delay(100); }
bool radio_signal_captured() { return random(1,20)==1; }
uint32_t radio_get_captured() { return random(0,0xFFFF); }
void radio_send_code(uint32_t freq, uint8_t proto, uint32_t code) { delay(50); }
void radio_stop() {}
