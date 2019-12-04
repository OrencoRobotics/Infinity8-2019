#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 80

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 7

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.setBrightness(84);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(25); } }

void loop () {
  static uint8_t hue = 0;
  for(CRGB*led=leds; led < leds + NUM_LEDS;led+=5) {
  //
   *(led++) = CHSV(64, 255, 255);
    *(led++) = CRGB::Green;
    //Green is red, Red is green
    *(led++) = CHSV(64, 255, 255);
    led += 5;
    *(led++) = CHSV(64, 255, 255);
    *(led++) = CHSV(64, 255, 255);
    *(led++) = CHSV(64, 255, 255);
    //
    FastLED.show();
    fadeall();
    delay(700);
}
}
