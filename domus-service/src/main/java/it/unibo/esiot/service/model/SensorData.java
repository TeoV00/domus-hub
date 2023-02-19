package it.unibo.esiot.service.model;

public interface SensorData {
    void updateLight(final int newExtLight);
    void updateTemp(final int newExtTemp);
    int getExtLight();
    int getExtTemp();
}
