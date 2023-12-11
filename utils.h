#ifndef UTILS
#define UTILS
#include <Arduino.h>

void setup_wifi();
void setup_mqtt();

String serial_reader(char *prompt = "");

#endif