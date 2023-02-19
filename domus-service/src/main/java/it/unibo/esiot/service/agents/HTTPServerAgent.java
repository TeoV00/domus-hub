package it.unibo.esiot.service.agents;

import io.vertx.core.AbstractVerticle;
import io.vertx.core.http.HttpMethod;
import io.vertx.core.json.JsonArray;
import io.vertx.core.json.JsonObject;
import io.vertx.ext.web.Router;
import io.vertx.ext.web.RoutingContext;
import io.vertx.ext.web.handler.BodyHandler;
import it.unibo.esiot.service.model.HomeStateImpl;
import org.json.JSONObject;

/*
 * Data Service as a vertx event-loop 
 */
public class HTTPServerAgent extends AbstractVerticle {

	private static final String PATH = "/api/data";
	private final int port;
	private final HomeStateImpl homeState;

	public HTTPServerAgent(final int port, final HomeStateImpl garden) {
		this.port = port;
		this.homeState = garden;
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
		routingContext.response()
				.putHeader("content-type", "application/json")
				.end(this.homeState.getJson());
	}

	private void log(final String msg) {
		System.out.println("HTTP_SEVER_SERVICE: " + msg);
	}

}