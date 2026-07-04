
// hw_input.cpp
#include "hw_input.h"
#include "../config.h"
void cyd_input_init() {
    pinMode(CYD_BTN_UP, INPUT_PULLUP);
    pinMode(CYD_BTN_DOWN, INPUT_PULLUP);
    pinMode(CYD_BTN_LEFT, INPUT_PULLUP);
    pinMode(CYD_BTN_RIGHT, INPUT_PULLUP);
    pinMode(CYD_BTN_OK, INPUT_PULLUP);
}
cyd_button_t cyd_read_button() {
    if (!digitalRead(CYD_BTN_UP)) return CYD_BTN_UP;
    if (!digitalRead(CYD_BTN_DOWN)) return CYD_BTN_DOWN;
    if (!digitalRead(CYD_BTN_LEFT)) return CYD_BTN_LEFT;
    if (!digitalRead(CYD_BTN_RIGHT)) return CYD_BTN_RIGHT;
    if (!digitalRead(CYD_BTN_OK)) return CYD_BTN_OK;
    return CYD_BTN_NONE;
}
