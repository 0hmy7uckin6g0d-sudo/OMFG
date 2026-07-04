// hw_radio.h
#ifndef HW_RADIO_H
#define HW_RADIO_H
#include <stdint.h>
void radio_init();
void radio_jam(uint32_t freq, uint8_t power);
bool radio_signal_captured();
uint32_t radio_get_captured();
void radio_send_code(uint32_t freq, uint8_t proto, uint32_t code);
void radio_stop();
#endif
