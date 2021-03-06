# Takiuino - the arduino compatible board for ME!

Just a WIP atm, look in the eagle directory and you can see the boards and their OSHPark links, though v2.0 has now
been tested against both arduino v1.0.x and arduino v1.5.7 and v1.6.0.

The main site for the takiuino is here: http://pjr.cc/tu/ (which is comming soon)

## Thanks go to....

Maniacbug - for his work on the 1284 originally, from [here](https://maniacbug.wordpress.com/2011/11/27/arduino-on-atmega1284p-4/).

The Optiboot folk - for making the awesome optiboot code! Available [here](https://code.google.com/p/optiboot/).

## What is it?

A fork of Maniacbug's mighty1284 code base, also includes the 644p code.

I've removed everything except the optiboot options (for now)

## What do you need?

First you need the board, which is on oshpark [here](https://oshpark.com/shared_projects/BunCIt50) for V3.1 or
[here](https://oshpark.com/shared_projects/wfCfnxof) for V3.2. The only difference between them is how the ICSP and reset swtiches are layed out.

# V3.1
![Top](http://pjr.cc/tu/op_top.png)
![Bottom](http://pjr.cc/tu/op_bottom.png)

# V3.2
![Top](http://pjr.cc/tu/t32_top.png)
![Bottom](http://pjr.cc/tu/t32_bottom.png)
Then you need to make the board (its pretty simple)

1. decide what you need, if your powering from a stable 5v source, you dont need the 5v REG (though keeping the 5v cap, C1, isnt a bad idea)
If you dont need a 3.3v line, you can drop the 3.3v REG as well (and its capacitor, C2).

2. the polarized components (2 caps, 2 leds) have their positive lines marked

3. Conquer the world. They'll be a better written tutorial coming soon, as well as an annotated
image of the actual board and components that go on it. But for the impatient the components are as follows:

- C1, C2: 10uf Tant CAP (16v rated)
- RES: SMD resontator (16mhz), Murata CSTCE16M0V53-R0 is appropriate
- C4: 0.1uf (100nf) 0603 sized ceramic cap
- R1: 330 ohm 0603 sized resister
- R2: 220 ohm 0603 sized resister (can also be 330 ohm if you wish)
- S1: SMD push button switch
- L2, L3: 0603 sized SMD led (note polarity)
- 1117-5v: AMS/LM1117 5v regulator
- 1117-3.3v: AMS/LM1117 3.3v regulator
- ATmega: ATmega1284p-au or ATmega644p-au (which ever suits you) should be a little circle on the chip, which 
goes with the printed circle on the board

Personally i find the resonator the hardest bit to solder, but doesnt take too much to long to get the hang
of it. After that, hook up an ASP and go program it directly with code, or use a bootloader and program via
the serial pinouts (note you'll need a USB to uart thingo).

If it all works, L3 should come on when power to the board is applied and you can control L2 via pummelling
pin 23 (which is what L2 is connected to). The following code should work:

```
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
  } else {
    tLat = tLat/1.2;
  }

  Serial.print("tlat now: ");
  Serial.println(tLat);

}

```
This should cause the L2 led to start as a slow on/off then ramp up and eventually stay on, then reset and start again.


## Installation

copy the contents of the arduino-ide folder into you arduino ide's hardware directory


## Why?

Originally started as a project to create something very specific, hence why the original V1 board has a
MOSFET on the board.

Second reason was cause I could, always wanted to design my own board for a microctronoller and this worked
out well.

Third was that I wanted a board with more useful pinout info, not many of the smaller boards have any markings
to tell you which channel is a pwm line, etc. The code also allow you to call pins via the names on
either side of the board (hence whey they're both there).

Lastly, I needed something small (round the pro mini/micro size) with two serial ports, the ability to run
an OLED screen (which requires quite some memory) along with some other memory sapping parts

## TODO

- I think I may regret the position of the reset switch as its sitting very close to the resonator (i'll know once
the v3 prints arrive from OSH Park)
- Write a test harness and some programs to check that the pins all work

