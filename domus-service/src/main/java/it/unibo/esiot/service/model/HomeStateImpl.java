package it.unibo.esiot.service.model;

import netscape.javascript.JSObject;
import org.json.JSONException;
import org.json.JSONObject;
import org.json.JSONString;
import org.json.JSONStringer;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class HomeStateImpl {

    private PowerState inLight; //indoor lights
    private int outLight; //outdoor light
    private AlarmState alarmState; //alarm system power state
    private PowerState heatSysPwr; //heating system power
    private int heatTemp; // selected heating system temperature
    private GarageState garageState;
    private boolean btConnected;
    private String timestamp;

    public HomeStateImpl() {
        this.inLight = PowerState.OFF;
        this.outLight = 0;
        this.alarmState = AlarmState.OFF;
        this.heatSysPwr = PowerState.OFF;
        this.heatTemp = 0;
        this.garageState = GarageState.CLOSE;
        this.btConnected = false;
        this.timestamp = "";
    }

    public void updateState(final String jsonHomeState) {
        try {
            JSONObject jsonObject = new JSONObject(jsonHomeState);
            this.inLight = PowerState.getFromValue(jsonObject.getInt("inLight"));
            this.outLight = jsonObject.getInt("outLight");
            this.alarmState = AlarmState.getFromValue(jsonObject.getInt("alarmState"));
            this.heatSysPwr = PowerState.getFromValue(jsonObject.getInt("heatSysPwr"));
            this.heatTemp = jsonObject.getInt("heatTemp");
            this.garageState = GarageState.getFromValue(jsonObject.getInt("garageState"));
            this.btConnected = jsonObject.getInt("btConnected") == 0;
            final var now = LocalDateTime.now();
            final var dateTimeFormatter = DateTimeFormatter.ofPattern("yy-MM-dd HH:mm:ss");
            this.timestamp = now.format(dateTimeFormatter);
        } catch (JSONException exception) {
            System.out.println("HOME_STATE: " + exception);
        }

    }

    public String getJson() {
        JSONObject jsonObject = new JSONObject();
        jsonObject.put("inLight",this.inLight.getDescr());
        jsonObject.put("outLight",this.outLight);
        jsonObject.put("alarmState",this.alarmState.getDescr());
        jsonObject.put("heatSysPwr",this.heatSysPwr.getDescr());
        jsonObject.put("heatTemp",this.heatTemp);
        jsonObject.put("garageState",this.garageState.getDescr());
        jsonObject.put("btConnected",this.btConnected);
        jsonObject.put("lastUpdate", this.timestamp);

        String json = jsonObject.toString();
        return json;
    }
}
