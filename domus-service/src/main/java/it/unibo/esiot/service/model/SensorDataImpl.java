package it.unibo.esiot.service.model;

import org.json.JSONObject;

public class SensorDataImpl implements SensorData{
    private int externalLight;
    private int externalTemp;

    public SensorDataImpl(final int light, final int temp) {
        this.externalTemp = temp;
        this.externalLight = light;
    }

    @Override
    public void updateLight(int newExtLight) {
        this.externalLight = newExtLight;
    }

    @Override
    public void updateTemp(int newExtTemp) {
        this.externalTemp = newExtTemp;
    }

    @Override
    public int getExtLight() {
        return this.externalLight;
    }

    @Override
    public int getExtTemp() {
        return this.externalTemp;
    }

    public String getJson() {
        JSONObject jsonObject = new JSONObject(this);
        String json = jsonObject.toString();
        return json;
    }
}
