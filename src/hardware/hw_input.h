// hw_input.h
#ifndef HW_INPUT_H
#define HW_INPUT_H
enum cyd_button_t { CYD_BTN_NONE=0, CYD_BTN_UP, CYD_BTN_DOWN, CYD_BTN_LEFT, CYD_BTN_RIGHT, CYD_BTN_OK };
void cyd_input_init();
cyd_button_t cyd_read_button();
#endif
