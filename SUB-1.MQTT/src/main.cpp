#include <WiFi.h>
#include <PubSubClient.h>

/* ---------- WiFi ---------- */
const char* ssid = "Wokwi-GUEST";
const char* password = "";

/* ---------- MQTT ---------- */
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "home/lab1/temp";

WiFiClient espClient;
PubSubClient client(espClient);

/* ---------- MQTT Callback ---------- */
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received [");
  Serial.print(topic);
  Serial.print("]: ");

  String message;
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println(message);
}

/* ---------- MQTT Reconnect ---------- */
void reconnect() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    String clientId = "ESP32-Wokwi-" + String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe(mqtt_topic);
      Serial.println("Subscribed to topic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" retrying in 2 sec");
      delay(2000);
    }
  }
}

/* ---------- Setup ---------- */
void setup() {
  Serial.begin(115200);

  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

/* ---------- Loop ---------- */
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
