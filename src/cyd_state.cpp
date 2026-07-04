// cyd_state.cpp
#include "cyd_state.h"
cyd_state_t cyd_state;
void cyd_reset_state() {
    cyd_state.premenu_selected = 0;
    cyd_state.menu_selected = 0;
    cyd_state.active_attacks = 0;
    cyd_state.phase = 0;
    cyd_state.stealth_mode = false;
    for (int i=0; i<4; i++) cyd_state.code_buf[i] = 0;
}
