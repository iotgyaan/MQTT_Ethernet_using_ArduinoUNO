// Basic MQTT example

#include <PubSubClient.h>
#include <EthernetENC.h>

// Update these with values suitable for your network.
uint8_t mac[6] = {0xDE, 0xED, 0xBA, 0xFE, 0xFE, 0xED};
IPAddress ip(192, 168, 10, 143);
//IPAddress server(192, 168, 10, 138);

EthernetClient ethClient;
PubSubClient mqttClient(ethClient);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void reconnect() {
  // Loop until we're reconnected
  while (!mqttClient.connected()) {
    Serial.print("Attempting MQTT connection...");
    delay(1000);
    // Attempt to connect
    if (mqttClient.connect("MQTTClient01")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      mqttClient.publish("UnoOutTopic","hello world from UNO!");
      // ... and resubscribe
      mqttClient.subscribe("UnoInTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqttClient.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);

  Ethernet.begin(mac, ip);
//  Ethernet.begin(mac);

  // Allow the hardware to sort itself out
  delay(1000); 
  
  Serial.print("localIP: ");
  Serial.println(Ethernet.localIP());
  Serial.print("subnetMask: ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("gatewayIP: ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("dnsServerIP: ");
  Serial.println(Ethernet.dnsServerIP());

  // connect to mqtt broker
  mqttClient.setServer("test.mosquitto.org", 1883);
//  mqttClient.setServer(server, 1883);
  mqttClient.setCallback(callback);

  delay(5000);
  
}

void loop()
{
  if (!mqttClient.connected()) {
    reconnect();
  }
  mqttClient.loop();
}
