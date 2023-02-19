package it.unibo.esiot;

import it.unibo.esiot.service.agents.SerialRecvListener;
import it.unibo.esiot.service.commchannel.CommChannel;
import it.unibo.esiot.service.commchannel.SerialCommChannel;
import it.unibo.esiot.service.model.HomeStateImpl;
import org.json.JSONException;

public class Main {

    public static void main(String[] args) throws Exception {
        CommChannel channel = new SerialCommChannel("/dev/tty.usbmodem21401",9600);
        HomeStateImpl homeState = new HomeStateImpl();

        SerialRecvListener serialAgent = new SerialRecvListener(channel, homeState);
        serialAgent.start();
    }
}
