#ifndef UTILS
#define UTILS
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

void setup_wifi(char const *ssid, char const *password);
void setup_mqtt(char const *mode, PubSubClient &client, char const *mqtt_server, char const *pub_topic, char const *sub_topic);

String serial_reader(char *prompt = "");

#endif