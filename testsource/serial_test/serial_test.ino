/*
This tests the two serial ports
*/


void setup()
{
  Serial.begin(115200);
  Serial1.begin(115200);
}

void loop()
{
  int tm = millis();
  int ltm = 0;
  while(true) {
    if((tm - ltm) > 1000) {
        Serial.println("Ping!");
        Serial1.println("Ping!");
        ltm = millis();
    }
    if(Serial.available() > 0 ) {
      while(Serial.available() > 0) {
        Serial.print("you typed: ");
        Serial.println(Serial.read());
      }
    }
    if(Serial1.available() > 0 ) {
      while(Serial1.available() > 0) {
        Serial1.print("you typed: ");
        Serial1.println(Serial.read());
      }
    }
  }
}
