#include "utils.h"

const char *ssid = "Sukamentri";
const char *password = "gggh5555";
const char *mqtt_server = "broker.mqtt-dashboard.com";

WiFiClient espClient;
PubSubClient client(espClient);

String our_username = "";
String their_username = "";
String pub_topic = "";
String sub_topic = "";
String send_msg = "";

void setup()
{
    Serial.begin(115200);
    setup_wifi(ssid, password);
    our_username = serial_reader("Enter your desired username: ");
    their_username = serial_reader("Enter your destination's username: ");
    sub_topic = (their_username + "/to/" + our_username);
    pub_topic = (our_username + "/to/" + their_username);
    setup_mqtt("normal", client, mqtt_server, pub_topic.c_str(), sub_topic.c_str());
}

void loop()
{
    if (Serial.available() > 0)
    {
        send_msg = serial_reader();
        if (!client.connected())
        {
            setup_mqtt("silent", client, mqtt_server, pub_topic.c_str(), sub_topic.c_str());
        }
        if (client.publish(pub_topic.c_str(), send_msg.c_str()))
        {
            Serial.println("<" + our_username + "> " + send_msg);
        }
    }

    client.loop();
}