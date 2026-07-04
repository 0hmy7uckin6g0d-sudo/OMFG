// policejam.cpp
#include "policejam.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
void policejam_run(cyd_state_t* state) {
    cyd_draw_attack("Police/Alarm Jam");
    cyd_draw_log("Jamming police frequencies...");
    uint32_t police_freqs[] = {150000000, 174000000};
    for(int i=0; i<2; ++i) {
        radio_jam(police_freqs[i], 3);
        cyd_draw_log("Jamming...");
        delay(1000);
    }
    radio_stop();
    cyd_draw_green_light("Jamming complete.");
}
