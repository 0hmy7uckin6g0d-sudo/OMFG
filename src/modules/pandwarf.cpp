// pandwarf.cpp
#include "pandwarf.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
void pandwarf_run(cyd_state_t* state) {
    cyd_draw_attack("Pandwarf");
    cyd_draw_log("Scanning and jamming...");
    uint32_t pandwarf_freqs[] = {433920000, 868000000};
    for(int i=0; i<2; ++i) {
        radio_jam(pandwarf_freqs[i], 3);
        cyd_draw_log("Jamming...");
        delay(1000);
    }
    radio_stop();
    cyd_draw_green_light("Pandwarf attack complete.");
}
