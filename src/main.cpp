#include "config.h"
#include "cyd_state.h"
#include "hardware/hw_display.h"
#include "hardware/hw_input.h"
#include "modules/rolljam.h"
#include "modules/flockfucker.h"
#include "modules/flockjam.h"
#include "modules/amazonlocker.h"
#include "modules/saflok.h"
#include "modules/policejam.h"
#include "modules/cctvblock.h"
#include "modules/garageopener.h"
#include "modules/magspoof.h"
#include "modules/u2f.h"
#include "modules/alarmjam.h"
#include "modules/protopirate.h"
#include "modules/pandwarf.h"
#include "modules/kaiju.h"
#include "ui/ui_draw.h"

void setup() {
    cyd_reset_state();
    cyd_display_init();
    cyd_input_init();
    rolljam_init();
    // ...init rest as needed
}

void vehicle_attacks_dispatch(int sel) {
    switch(sel) {
        case 0: rolljam_run(&cyd_state); break;
        case 1: flockfucker_run(&cyd_state); break;
        default: break;
    }
}
void loop() {
    // Pre-menu selection
    int pre_sel = cyd_premenu_select();
    if(pre_sel==0) {
        // Vehicle - show module menu
        int msel = 0, last_sel=-1;
        while(1) {
            cyd_button_t btn = cyd_read_button();
            if(btn==CYD_BTN_DOWN && msel<2) ++msel;
            if(btn==CYD_BTN_UP && msel>0) --msel;
            if(last_sel!=msel) { cyd_draw_menu(msel); last_sel=msel; }
            if(btn==CYD_BTN_OK) { vehicle_attacks_dispatch(msel); break; }
            delay(60);
        }
    }
    else if(pre_sel==1) { flockfucker_run(&cyd_state);}
    else if(pre_sel==2) { saflok_run(&cyd_state);}
    else if(pre_sel==3) { amazonlocker_run(&cyd_state);}
    else if(pre_sel==4) { flockjam_run(&cyd_state);}
    else if(pre_sel==5) { cctvblock_run(&cyd_state);}
    else if(pre_sel==6) { policejam_run(&cyd_state);}
    else if(pre_sel==7) { magspoof_run(&cyd_state);}
    else if(pre_sel==8) { u2f_run(&cyd_state);}
    else if(pre_sel==9) { alarmjam_run(&cyd_state);}
    else if(pre_sel==10) { protopirate_run(&cyd_state);}
    else if(pre_sel==11) { pandwarf_run(&cyd_state);}
    else if(pre_sel==12) { kaiju_run(&cyd_state);}
    else if(pre_sel==13) { garageopener_run(&cyd_state);}
    // ... add more pre-menu -> module matches as needed
}
