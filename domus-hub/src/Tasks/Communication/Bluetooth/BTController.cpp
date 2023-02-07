
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
        } else if (key == "outLight") {
            this->homeState->outLight = value.toInt() ;
        } else if (key == "gar") {
            int intVal = value.toInt();
            switch (intVal)
            {
            case GarageState::REQ_OPEN:
                this->homeState->garageState = REQ_OPEN; break;
            case GarageState::REQ_CLOSE:
                this->homeState->garageState = REQ_CLOSE; break;
            case GarageState::REQ_PAUSE:
                this->homeState->garageState = REQ_PAUSE; break;
            default: break;
            }
        } else if (key == "heatP") {
            this->homeState->heatSysPwr = value.toInt() == CUSTOM_STATE ? PowerState::CUSTOM_STATE : PowerState::OFF;
        } else if (key == "resetA") {
            this->homeState->alarmState = AlarmState::A_RESET;
        } else if (key == "reqData") {
            this->sendData();
        }
    }
}

void BtController::sendData() {
    StaticJsonDocument<192> doc;
    doc["iL"] = this->homeState->inLight;
    doc["oL"] = this->homeState->outLight;
    doc["alarm"] = this->homeState->alarmState;
    doc["hP"] = this->homeState->heatSysPwr;
    doc["hT"] = this->homeState->heatTemp;
    doc["gar"] = this->homeState->garageState;
    doc["bt"] = this->homeState->btConnected;
    serializeJson(doc, *this->bt);
};

bool BtController::isConnected() {
    return digitalRead(this->statePin) == HIGH;
}