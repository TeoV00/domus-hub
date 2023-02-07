#include "BluetoothTask.h"
#include "Communication/Bluetooth/BTController.h"
#include "HomeState.h"
#include "PinSetup.h"

BluetoothTask::BluetoothTask(HomeState* homeState) {
    this->homeState = homeState;
    this->btCtrl = new BtController(homeState,BT_TX_PIN, BT_RX_PIN, BT_STATE_PIN);
}

void BluetoothTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}
void BluetoothTask::tick() {
    bool btState = this->btCtrl->isConnected();
    this->homeState->btConnected = btState;
    
    if (btState) {
        this->btCtrl->receiveData();
        //this->btCtrl->sendData();
    }
}
