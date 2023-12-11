char incomingByte = 0;
String msg = "";

void setup()
{
    Serial.begin(115200);
    setup_wifi();
    setup_mqtt();
}

void loop()
{
    if (Serial.available() > 0)
    {
        incomingByte = Serial.read();
        msg += incomingByte;
        if (Serial.available() == 0)
        {
            Serial.println(msg.c_str());
            msg = "";
        }
    }
}