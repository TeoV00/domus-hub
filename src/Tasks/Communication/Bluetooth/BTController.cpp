
#include "PinSetup.h"
#include "HomeState.h"
#include "BTController.h"
#include "ArduinoJson.h"
#include "BtKeyRequest.h"

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

        if (key == INDOOR_LIGHT_KEY) {
            this->homeState->inLight = value.toInt() ? PowerState::ON : PowerState::OFF;
        } else if (key == OUTDOOR_LIGHT_KEY) {
            this->homeState->outLight = value.toInt() ;
        } else if (key == GARAGE_KEY) {
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
        } else if (key == HEATING_KEY) {
            this->homeState->heatSysPwr = value.toInt() == CUSTOM_STATE ? PowerState::CUSTOM_STATE : PowerState::OFF;
        } else if (key == ALARM_KEY) {
            this->homeState->alarmState = value.toInt() == A_SWITCH_OFF ? AlarmState::A_SWITCH_OFF : AlarmState::A_SWITCH_ON;
        } else if (key == RESET_ALARM_KEY) {
            this->homeState->alarmState = AlarmState::A_RESET;
        } else if (key == REQUEST_DATA_KEY) {
            this->sendData();
        }
    }
}

void BtController::sendData() {
    StaticJsonDocument<96> doc;
    doc["iL"] = this->homeState->inLight;
    doc["oL"] = this->homeState->outLight;
    doc["alarm"] = this->homeState->alarmState;
    doc["hP"] = this->homeState->heatSysPwr;
    doc["hT"] = this->homeState->heatTemp;
    doc["gar"] = this->homeState->garageState;
    doc["bt"] = this->homeState->btConnected;
    serializeJson(doc, *this->bt);
    this->bt->println();
};

bool BtController::isConnected() {
    return digitalRead(this->statePin) == HIGH;
}
