// ui_draw.cpp
#include "ui_draw.h"
#include "../hardware/hw_display.h"
#include "../cyd_state.h"
const char* pre_menu_items[] = {
    "Vehicle Unlock",
    "Garage Opener",
    "Building/Apartment",
    "Amazon Locker",
    "Flock Camera Jam",
    "CCTV/IoT Jam",
    "Police/Alarm Jam",
    "MagSpoof",
    "U2F",
    "Stealth Mode"
};
const int pre_menu_len = 10;

void cyd_draw_premenu(int selected) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_MAGENTA, TFT_BLACK);
    tft.setTextSize(3);
    tft.setCursor(60,18);
    tft.println("0MFG-FW");
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(32,52);
    tft.println("Pick Your Dirty Work");
    tft.setTextSize(2);
    for(int i=0;i<pre_menu_len;i++) {
        int y = 84 + 24*i;
        tft.setTextColor(i==selected?TFT_RED:TFT_WHITE, TFT_BLACK);
        tft.setCursor(42,y); tft.println(pre_menu_items[i]);
    }
}
int cyd_premenu_select() {
    int sel=0, last=0xFF;
    while(1) {
        cyd_button_t btn = cyd_read_button();
        if (btn == CYD_BTN_DOWN && sel < pre_menu_len-1) sel++;
        if (btn == CYD_BTN_UP && sel > 0) sel--;
        if (last != sel) { cyd_draw_premenu(sel); last = sel; }
        if (btn == CYD_BTN_OK) return sel;
        delay(60);
    }
}
const char* vehicle_menu[] = { "RollJam", "FlockFucker", "Back" };
const int vehicle_menu_len = 3;
void cyd_draw_menu(int selected) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(80,16); tft.println("Vehicle Attacks:");
    tft.setTextSize(2);
    for(int i=0;i<vehicle_menu_len;i++) {
        int y = 54 + 30*i;
        tft.setTextColor(i==selected?TFT_RED:TFT_WHITE, TFT_BLACK);
        tft.setCursor(72,y); tft.println(vehicle_menu[i]);
    }
}
void cyd_draw_attack(const char* name) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(40,32);
    tft.println(name);
}
void cyd_draw_log(const char* msg) {
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setCursor(10, 102);
    tft.println(msg);
}
void cyd_draw_red_light(const char* msg){
    tft.fillScreen(TFT_RED);
    tft.setTextColor(TFT_BLACK, TFT_RED);
    tft.setTextSize(5); tft.setCursor(90, 60); tft.println("STOP");
    tft.setTextSize(2); tft.setCursor(20, 160); tft.println(msg);
    delay(1200);
}
void cyd_draw_green_light(const char* msg) {
    tft.fillScreen(TFT_GREEN);
    tft.setTextColor(TFT_BLACK, TFT_GREEN);
    tft.setTextSize(5); tft.setCursor(70, 60); tft.println("GO");
    tft.setTextSize(2); tft.setCursor(20, 160); tft.println(msg);
    delay(1200);
}
void cyd_draw_stealth_mode() {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(40, 32);
    tft.println("Stealth Mode");
    tft.setCursor(20, 64);
    tft.println("LEDs & Display OFF");
    tft.setCursor(20, 96);
    tft.println("Radio ON");
    tft.setCursor(20, 128);
    tft.println("Press OK to toggle");
}
void cyd_draw_animation_working() {
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(40, 32);
    tft.println("Working...");
    tft.setCursor(20, 64);
    tft.println("Please wait");
    tft.setCursor(20, 96);
    tft.println("This may take a moment");
}
void cyd_draw_animation_success() {
    tft.fillScreen(TFT_GREEN);
    tft.setTextColor(TFT_BLACK, TFT_GREEN);
    tft.setTextSize(5); tft.setCursor(90, 60); tft.println("SUCCESS");
    tft.setTextSize(2); tft.setCursor(20, 160); tft.println("Attack succeeded!");
    delay(1200);
}
void cyd_draw_animation_failure() {
    tft.fillScreen(TFT_RED);
    tft.setTextColor(TFT_BLACK, TFT_RED);
    tft.setTextSize(5); tft.setCursor(90, 60); tft.println("FAILURE");
    tft.setTextSize(2); tft.setCursor(20, 160); tft.println("Attack failed!");
    delay(1200);
}
