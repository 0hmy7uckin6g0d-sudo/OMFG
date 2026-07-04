// ui_draw.h
#ifndef UI_DRAW_H
#define UI_DRAW_H
void cyd_draw_premenu(int selected);
int cyd_premenu_select();
void cyd_draw_menu(int selected);
void cyd_draw_attack(const char* name);
void cyd_draw_log(const char* log);
void cyd_draw_red_light(const char* msg);
void cyd_draw_green_light(const char* msg);
void cyd_draw_stealth_mode();
void cyd_draw_animation_working();
void cyd_draw_animation_success();
void cyd_draw_animation_failure();
#endif
