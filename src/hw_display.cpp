// hw_display.cpp
#include "hw_display.h"
TFT_eSPI tft = TFT_eSPI();
void cyd_display_init() {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}
