int ledPin = 23;                 // LED connected to digital pin 23
int tLat = 1024;

void setup()
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
}

void loop()
{


  digitalWrite(ledPin, HIGH);   // sets the LED on
  delay(tLat);                  // waits for a bit
  digitalWrite(LED, LOW);       // sets the LED off
  // note that i use "LED" above, which is defined 
  // in the hardware library for this pin
  delay(tLat);                  // waits for a bit


  tLat = tLat/1.2;
  if(tLat < 2) tLat = 1024;
}
