// cyd_state.h
#ifndef CYD_STATE_H
#define CYD_STATE_H
#include <stdint.h>
struct cyd_state_t {
    uint8_t premenu_selected;
    uint8_t menu_selected;
    uint32_t active_attacks;
    int phase;
    uint32_t code_buf[4];
    bool stealth_mode;
};
extern cyd_state_t cyd_state;
void cyd_reset_state();
#endif
