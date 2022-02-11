#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
//define NeoPixel Pin and Number of LEDs
#define PIN 6
#define NUM_LEDS 59
//create a NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // start the strip and blank it out
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.
  strip.begin();
  strip.show();
  for(int i =0; i<=NUM_LEDS; i++){
  strip.setPixelColor(i, 255,255,255);
strip.show();
strip.setBrightness(255);
  }
}

void loop() {
 
  // set pixel to red, delay(1000)
  //for(int i =0; i<=NUM_LEDS; i++){
  //strip.setPixelColor(i, 255, 255, 0);
//strip.show();
  }
  //strip.show();
  //delay(1000);
  // set pixel to off, delay(1000)
  //  for(int j =0; j<=NUM_LEDS; j++){
  //strip.setPixelColor(j, 0, 0, 0);
  //  }
  //strip.show();
  //delay(1000);
