/*
This tests the two serial ports

Completed on 1.0 and 1.5  
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
    tm = millis();
    int tdiff = tm-ltm;
    if(tdiff > 1000) {
        Serial.println("Ping Serial0!");
        Serial1.println("Ping Serial1!");
        ltm = millis();
    }
    if(Serial.available() > 0 ) {
      Serial.print("On Serial0 you typed: ");
      while(Serial.available() > 0) {
        Serial.print((char)Serial.read());
      }
      Serial.println();
    }
    if(Serial1.available() > 0 ) {
      Serial1.print("On Serial1 you typed: ");
      while(Serial1.available() > 0) {
        Serial1.print((char)Serial1.read());
      }
      Serial1.println();
    }
  }
}
