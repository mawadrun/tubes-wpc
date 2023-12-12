#ifndef UTILS
#define UTILS
#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

extern String their_username; // Ini agar their_username bisa diakses oleh fungsi callback untuk print UI received message

void setup_wifi(char const *ssid, char const *password);
void setup_mqtt(char const *mode, PubSubClient &client, char const *mqtt_server, char const *pub_topic, char const *sub_topic); // Jangan lupa gunakan reference operator untuk object client
void callback(char *topic, byte *payload, unsigned int length);

String serial_reader(char *prompt = "");

#endif