#include "utils.h"

void setup_wifi(char const *ssid, char const *password)
{
    Serial.println();
    Serial.print("Connecting to: ");
    Serial.print(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(500);
    }

    Serial.println();
    Serial.print("Successfully connected to ");
    Serial.println(ssid);
    Serial.print("Local IP: ");
    Serial.println(WiFi.localIP());
}

void setup_mqtt(PubSubClient &client, char const *mqtt_server, char const *pub_topic, char const *sub_topic)
{
    Serial.print("Connecting to ");
    Serial.println(mqtt_server);

    client.setServer(mqtt_server, 1883);

    randomSeed(micros());

    while (!client.connected())
    {
        String clientId = "ESPClient-";
        clientId += String(random(0xffff), HEX);

        if (client.connect(clientId.c_str()))
        {
            Serial.println("Connected to MQTT server");
            client.publish(pub_topic, "Device Connected: ");
            client.publish(pub_topic, clientId.c_str());
        }
        else
        {
            Serial.print("Failed, rc=");
            Serial.print(client.state());
            for (int i = 0; i < 5; i++)
            {
                Serial.printf("Retrying in %d seconds\n", i);
                delay(1000);
            }
        }
    }
}

String serial_reader(char *prompt)
{
    char incomingByte = 0;
    String msg = "";

    Serial.print(prompt);
    while (Serial.available() <= 0)
    {
    }
    while (Serial.available() > 0)
    {
        incomingByte = Serial.read();
        msg += incomingByte;
    }
    return msg;
}