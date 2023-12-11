#include "utils.h"

void setup()
{
    Serial.begin(115200);
    setup_wifi();
    setup_mqtt();
}

void loop()
{
    Serial.println(serial_reader().c_str());
    Serial.println(serial_reader("Bruh: ").c_str());
}