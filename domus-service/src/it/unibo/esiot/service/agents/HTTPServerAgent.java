package it.unibo.esiot.smartgarden.service.agents;

import io.vertx.core.AbstractVerticle;
import io.vertx.core.http.HttpMethod;
import io.vertx.core.json.JsonArray;
import io.vertx.core.json.JsonObject;
import io.vertx.ext.web.Router;
import io.vertx.ext.web.RoutingContext;
import io.vertx.ext.web.handler.BodyHandler;
import it.unibo.esiot.smartgarden.service.model.SmartGarden;

/*
 * Data Service as a vertx event-loop 
 */
public class HTTPAgent extends AbstractVerticle {

	private static final String PATH = "/api/data";
	private final int port;
	private final SmartGarden garden;

	public HTTPAgent(final int port, final SmartGarden garden) {
		this.port = port;
		this.garden = garden;
	}

	@Override
	public void start() {		
		Router router = Router.router(vertx);
		router.route().handler(io.vertx.ext.web.handler.CorsHandler.create(".*.")
				.allowedMethod(io.vertx.core.http.HttpMethod.GET)
				.allowedMethod(io.vertx.core.http.HttpMethod.POST)
				.allowedMethod(io.vertx.core.http.HttpMethod.OPTIONS)
				.allowedMethod(HttpMethod.PUT)
				.allowedHeader("Access-Control-Request-Method")
				.allowedHeader("Access-Control-Allow-Origin")
				.allowedHeader("Access-Control-Allow-Headers")
				.allowedHeader("Content-Type"));
		router.route().handler(BodyHandler.create());
		router.get(PATH).handler(this::handleGetData);
		vertx.createHttpServer().requestHandler(router).listen(port);
		log("Service ready.");
	}
	
	private void handleGetData(final RoutingContext routingContext) {
		final JsonObject doc = new JsonObject();
		doc.put("status", this.garden.getState());
		final JsonArray arr = new JsonArray();
		final var dataPoints = this.garden.getDataPoints();
		for (final var point: dataPoints) {
			final JsonObject data = new JsonObject();
			data.put("timestamp", point.getTimeStamp());
			data.put("lightness", point.getLightness());
			data.put("temperature", point.getTemperature());
			arr.add(data);
		}
		doc.put("data", arr);
		routingContext.response()
				.putHeader("content-type", "application/json")
				.end(doc.encodePrettily());
	}

	private void log(final String msg) {
		System.out.println("[DATA SERVICE] " + msg);
	}

}