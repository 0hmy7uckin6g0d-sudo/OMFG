// u2f.cpp
#include "u2f.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
void u2f_run(cyd_state_t* state) {
    cyd_draw_attack("U2F");
    cyd_draw_log("Sending U2F signal...");
    radio_send_code(125000, 1, 0x123456); // Example code
    cyd_draw_green_light("U2F signal sent.");
}
