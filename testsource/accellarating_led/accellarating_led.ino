int ledPin = 23;                 // LED connected to digital pin 23
float tLat = 1024;
bool dirUp = true;

void setup()
{
  Serial.begin(115200); 
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


  if(tLat > 1024) {
    Serial.println("Switch direction, down");
    dirUp = false;
    
  }
  
  if(tLat < 2) {
    Serial.println("Switch direction, up");
    dirUp = true;
  }
  
  if(dirUp) {
    tLat = tLat*1.2;
//    if(tLat == 1) tLat = 2;
  } else {
    tLat = tLat/1.2;
  }
  Serial.print("tlat now: ");
  Serial.println(tLat);
//  tLat = tLat/1.1;
//  if(tLat < 2) tLat = 1024;
  
}
