// cctvblock.cpp
#include "cctvblock.h"
#include "../hardware/hw_radio.h"
#include "../hardware/hw_ir.h"
#include "../ui/ui_draw.h"
#include "../hardware/hw_input.h"

void cctvblock_run(cyd_state_t* state) {
    cyd_draw_attack("CCTV Block");
    cyd_draw_log("OK: RF Jam, RIGHT: IR Flood");
    cyd_button_t btn = cyd_read_button();
    if(btn == CYD_BTN_OK) {
        uint32_t cctv_freqs[] = {2400000000, 5800000000};
        for(int i=0; i<2; ++i) {
            radio_jam(cctv_freqs[i], 3);
            cyd_draw_log("Jamming CCTV...");
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
