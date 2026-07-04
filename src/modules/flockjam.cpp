// flockjam.cpp
#include "flockjam.h"
#include "../hardware/hw_radio.h"
#include "../hardware/hw_ir.h"
#include "../ui/ui_draw.h"
#include "../hardware/hw_input.h"

void flockjam_run(cyd_state_t* state) {
    cyd_draw_attack("Flock Cam/CCTV Jam");
    cyd_draw_log("OK: RF Jam, RIGHT: IR Flood");
    cyd_button_t btn = cyd_read_button();
    if(btn == CYD_BTN_OK) {
        for(int i=0; i<4; ++i) {
            uint32_t cam_freqs[] = {2400000000, 5800000000, 915000000, 433920000};
            radio_jam(cam_freqs[i], 3);
            cyd_draw_log("Jamming RF...");
            delay(800);
        }
    }
    if(btn == CYD_BTN_RIGHT) {
        cyd_draw_log("IR Flood ON");
        ir_flood_on();
        delay(3500);
        ir_flood_off();
        cyd_draw_log("IR Flood complete");
        delay(1200);
    }
}
