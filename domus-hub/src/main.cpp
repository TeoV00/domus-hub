#include <Arduino.h>
#include "./boundary/display/Lcd.h"
#include "./boundary/display/Display.h"

Lcd lcd;
volatile long int oldTime;
volatile long int prevTime;
int temp = 20;

void setup() {
  lcd.initLcd(0x27);
  lcd.updateAlarmState(PowerState::ON);
  lcd.updateHeatState(PowerState::OFF);
  lcd.updateHeatTemp(20);
  oldTime = millis();
}

void loop() {
  prevTime = millis();
  if (prevTime-oldTime >2000) {
    temp++;
    lcd.updateHeatTemp(temp);
    oldTime = prevTime;
  }
  
}