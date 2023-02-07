#include "BluetoothTask.h"
#include "Communication/Bluetooth/BTController.h"
#include "HomeState.h"
#include "PinSetup.h"

BluetoothTask::BluetoothTask(HomeState* homeState) {
    this->btCtrl = new BtController(homeState,BT_TX_PIN, BT_RX_PIN, BT_STATE_PIN);
}

void BluetoothTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}
void BluetoothTask::tick() {
    this->btCtrl->checkConnection();
    this->btCtrl->receiveData();
    this->btCtrl->sendData();
}
