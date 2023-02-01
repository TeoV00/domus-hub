
#include "Lcd.h"
#include "Arduino.h"
#include <LiquidCrystal_I2C.h>
#include "PowerState.h"

#define DEGREE_SYMBOL_ASCII 223
#define ON_MSG "ON "  //the whitespace is needed in order to cancel last F of word OFF
#define OFF_MSG "OFF"

Lcd::Lcd(uint8_t addr) {
    this->lcd = new LiquidCrystal_I2C(addr,16, 2);
    this->lcd->init();
    this->lcd->backlight();
}

void Lcd::updateAlarmState(PowerState alarmState) {
    this->lcd->setCursor(0,0);
    this->lcd->print("Alarm: ");
    this->lcd->setCursor(7,0);
    this->lcd->print(alarmState == PowerState::ON ? ON_MSG : OFF_MSG);
}

void Lcd::updateHeatState(PowerState heatState) {
    this->lcd->setCursor(0,1);
    this->lcd->print("Heating:");
    this->lcd->setCursor(8,1);
    this->lcd->print(heatState == PowerState::ON ? ON_MSG : OFF_MSG);
}

void Lcd::updateHeatTemp(unsigned int temp) {
    this->lcd->setCursor(11,1);
    this->lcd->print(" ");
    this->lcd->setCursor(12,1);
    this->lcd->print(temp);
    this->lcd->setCursor(14,1);
    this->lcd->print((char)DEGREE_SYMBOL_ASCII);
}

void Lcd::showAlarmAlertMsg() {
    this->lcd->setCursor(0,0);
    this->lcd->print("!! ATTENZIONE !!");
    this->lcd->setCursor(0,1);
    this->lcd->print("RILEVATO INTRUSO");
}

void Lcd::showInitMessage() {
    this->lcd->clear();
    this->lcd->setCursor(0,0);
    this->lcd->print("Domus Hub");
    this->lcd->setCursor(0,1);
    this->lcd->print("Calibrazione...");
}

void Lcd::clear() {
}
