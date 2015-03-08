/*

This sketch should cause each pin to be switched on for about 50ms, and walks everypin

*/

int walking[] = {RX1, TX1, PWM1, PWM2, PWM3, PWM4, SCL, SDA, GD1, GD2, GD3, GD4, GD5, GA8, GA7, GA6, GA5, GA4, GA3, GA2, GA1, GD6, GD7, GD8, GD9, SS, MOSI, MISO, SCK};
int tLat = 100;

void setup()
{
  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  for(int i=0; i<28; i++) {
    pinMode(i, OUTPUT);      // sets the digital pin as output
  }
}

void loop()
{
  
  int lpin=0;
  bool ledPin = false;
  
  
  for(int i=0; i<28; i++) {
    Serial.print("punching pin: ");
    Serial.println(walking[i]);
    
    if(ledPin) {
      ledPin = false;
      digitalWrite(LED, HIGH);
    } else {
      ledPin = true;
      digitalWrite(LED, LOW);
    }
    digitalWrite(lpin, LOW);
    digitalWrite(walking[i], HIGH);
    lpin = i;
    delay(tLat);
  }
}

