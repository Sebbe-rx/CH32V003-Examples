#include <Adafruit_NeoPixel.h>

#define LED_PIN    PD2 
#define NUM_LEDS   6

int tid = 25;

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  
for(int x=0;x<6;x++){
  strip.clear();
  strip.setPixelColor(x, strip.Color(0, 0, 255));
  strip.show();
  delay(tid);
}
for(int y=5;y>=0;y--){
  strip.clear();
  strip.setPixelColor(y, strip.Color(0, 0, 255));
  strip.show();
  delay(tid);
}



}
