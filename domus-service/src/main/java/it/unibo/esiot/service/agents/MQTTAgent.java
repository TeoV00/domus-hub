package it.unibo.esiot.smartgarden.service.agents;

import io.vertx.core.AbstractVerticle;
import io.vertx.core.json.JsonObject;
import io.vertx.mqtt.MqttClient;
import io.vertx.mqtt.messages.MqttPublishMessage;
import it.unibo.esiot.smartgarden.service.commchannel.CommChannel;
import it.unibo.esiot.smartgarden.service.model.DataPointImpl;
import it.unibo.esiot.smartgarden.service.model.SmartGarden;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

/*
 * MQTT Agent
 */
public class MQTTAgent extends AbstractVerticle {

	private static final String TOPIC = "esiot-smart-garden";
	private final CommChannel channel;
	private final SmartGarden garden;
	
	public MQTTAgent(final CommChannel channel, final SmartGarden garden) {
		this.channel = channel;
		this.garden = garden;
	}

	@Override
	public void start() {		
		MqttClient client = MqttClient.create(vertx);
		client.connect(1883, "broker.mqtt-dashboard.com", c -> {
			log("connected");
			log("subscribing...");
			client.publishHandler(this::responseHandler).subscribe(TOPIC, 2);
		});
	}

	private void responseHandler(final MqttPublishMessage msg) {
		final String receivedMsg = msg.payload().toString();
		log("New message in [" + msg.topicName() + "]: " + receivedMsg);
		storeDataPoint(msg);
		log("Sending to Arduino the data");
		channel.sendMsg(receivedMsg);
	}

	private void storeDataPoint(final MqttPublishMessage msg) {
		final var now = LocalDateTime.now();
		final var dateTimeFormatter = DateTimeFormatter.ofPattern("yy-MM-dd HH:mm:ss");
		final String timestamp = now.format(dateTimeFormatter);
		final JsonObject res = msg.payload().toJsonObject();
		final int temperature = res.getInteger("temperature");
		final int lightness = res.getInteger("lightness");
		this.garden.addNewDataPoint(new DataPointImpl(temperature, lightness, timestamp));
	}

	private void log(final String msg) {
		System.out.println("[MQTT AGENT] "+msg);
	}

}