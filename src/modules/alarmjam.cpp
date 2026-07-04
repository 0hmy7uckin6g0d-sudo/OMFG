// alarmjam.cpp
#include "alarmjam.h"
#include "../hardware/hw_radio.h"
#include "../ui/ui_draw.h"
void alarmjam_run(cyd_state_t* state) {
    cyd_draw_attack("Alarm Jam");
    cyd_draw_log("Jamming alarm frequencies...");
    uint32_t alarm_freqs[] = {433920000, 868000000};
    for(int i=0; i<2; ++i) {
        radio_jam(alarm_freqs[i], 3);
        cyd_draw_log("Jamming...");
        delay(1000);
    }
    radio_stop();
    cyd_draw_green_light("Jamming complete.");
}
