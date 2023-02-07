
#include "PinSetup.h"
#include "HomeState.h"
#include "BTController.h"
#include "Arduino.h"
#include "ArduinoJson.h"

BtController::BtController(HomeState* homeState, int btRXpin, int btTXpin, int btStatePin) {
    this->bt = new SoftwareSerial(btRXpin, btTXpin);
    this->homeState = homeState;

    pinMode(btRXpin, INPUT);
    pinMode(btTXpin, OUTPUT);
    pinMode(btStatePin, INPUT);
    this->statePin = btStatePin;
    this->bt->begin(9600);
};

void BtController::receiveData() {

    if (bt->available() > 0) {
        String recvData = bt->readString();
        String value = recvData.substring(recvData.indexOf(":")+1, recvData.length());
        String key = recvData.substring(0,recvData.indexOf(":"));

        if (key == "inLight") {
            this->homeState->inLight = value == "1" ? PowerState::ON : PowerState::OFF;
        }
    }
};
  
void BtController::sendData() {
    StaticJsonDocument<192> doc;
    doc["inLight"] = this->homeState->inLight;
    doc["outLight"] = this->homeState->outLight;
    doc["alarmState"] = this->homeState->alarmState;
    doc["heatSysPwr"] = this->homeState->heatSysPwr;
    doc["heatTemp"] = this->homeState->heatTemp;
    doc["garageState"] = this->homeState->garageState;
    doc["btConnected"] = this->homeState->btConnected;
    serializeJson(doc, *this->bt);
};

void BtController::checkConnection() {
    /*if (digitalRead(this->statePin) == LOW) {
        this->homeState->btConnected = true;
    }*/
}
