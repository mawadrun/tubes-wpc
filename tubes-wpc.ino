String serial_reader()
{
    char incomingByte = 0;
    String msg = "";
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

void setup()
{
    Serial.begin(115200);
    setup_wifi();
    setup_mqtt();
}

void loop()
{
    Serial.println(serial_reader().c_str());
}