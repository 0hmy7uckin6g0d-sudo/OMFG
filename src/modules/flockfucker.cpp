// flockfucker.cpp
#include "flockfucker.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
void flockfucker_run(cyd_state_t* state) {
    cyd_draw_attack("Flock Fucker");
    cyd_draw_log("RF Jammer Engaged!");
    radio_jam(433920000, 3);
    delay(7500);
    radio_stop();
    cyd_draw_log("Jammer stopped.");
}
