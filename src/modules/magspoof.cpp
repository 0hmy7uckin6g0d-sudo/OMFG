// magspoof.cpp
#include "magspoof.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
void magspoof_run(cyd_state_t* state) {
    cyd_draw_attack("MagSpoof");
    cyd_draw_log("Sending magnetic card signal...");
    radio_send_code(125000, 1, 0x123456); // Example code
    cyd_draw_green_light("MagSpoof signal sent.");
}
