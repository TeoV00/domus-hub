#ifndef __PINOUT_H__
#define __PINOUT_H__

//Lights
#define INDOOR_LIGHT_PIN 12//on-off led
#define OUTDOOR_LIGHT_PIN 11 //pwm led
#define ALARM_LIGHT_PIN 13

// Bluetooth module pins
#define BT_TX_PIN 4
#define BT_RX_PIN 5
#define BT_STATE_PIN 7

// Servo motor pins
#define SERVO_PWM 6

//Display I2C address
#define LCD_ADDR 0x27

//Pin connected to PIR sensor
#define PIR_PIN 8

//Buttons pin
#define HEATING_BTN_PIN 9
#define ALARM_BTN_PIN 10

//Potentionemeter to select temperature
#define HEATING_POT_PIN A0

#endif