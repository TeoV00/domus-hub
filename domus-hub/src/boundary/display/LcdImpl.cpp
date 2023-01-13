
#include "Lcd.h"
#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "PowerState.h"

#define DEGREE_SYMBOL_ASCII 223

Lcd::Lcd() {
}

void Lcd::initLcd(uint8_t addr) {
    this->lcd = new LiquidCrystal_I2C(addr,16, 2);
    this->lcd->init();
    this->lcd->backlight();
}

void Lcd::updateAlarmState(PowerState alarmState) {
    this->lcd->setCursor(0,0);
    this->lcd->print("Alarm:");
    this->lcd->setCursor(7,0);
    this->lcd->print(alarmState == PowerState::ON ? "ON" : "OFF");
}

void Lcd::updateHeatState(PowerState heatState) {
    this->lcd->setCursor(0,1);
    this->lcd->print("Heating:");
    this->lcd->setCursor(8,1);
    this->lcd->print(heatState == PowerState::ON ? "ON" : "OFF");
}

void Lcd::updateHeatTemp(int temp) {
    this->lcd->setCursor(12,1);
    this->lcd->print(temp);
    this->lcd->setCursor(14,1);
    this->lcd->print((char)DEGREE_SYMBOL_ASCII);
}

void Lcd::showAlarmAlertMsg() {
    this->lcd->setCursor(0,0);
    this->lcd->print("!!!ATTENZIONE!!!");
    this->lcd->setCursor(0,1);
    this->lcd->print("RILEVATO INTRUSO");
}

void Lcd::clear() {
    this->lcd->clear();
}
