// hw_ir.cpp
#include "hw_ir.h"
#include "../config.h"
void ir_flood_on()  { pinMode(CYD_IR_PIN, OUTPUT); digitalWrite(CYD_IR_PIN, HIGH); }
void ir_flood_off() { pinMode(CYD_IR_PIN, OUTPUT); digitalWrite(CYD_IR_PIN, LOW); }
