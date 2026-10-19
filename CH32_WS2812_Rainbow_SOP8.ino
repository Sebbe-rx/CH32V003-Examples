#include <Adafruit_NeoPixel.h>

#define LED_PIN    PC1
#define NUM_LEDS   9

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int pos = 0;      // comet position (0 .. NUM_LEDS-1)
int dir = 1;      // +1 = moving right, -1 = moving left
int hue = 0;      // rainbow base hue (0..255), shifts over time

// Classic Adafruit hue wheel: 0..255 -> full rainbow
uint32_t Wheel(byte pos) {
  pos = 255 - pos;
  if (pos < 85)  return strip.Color(255 - pos * 3, 0, pos * 3);
  if (pos < 170) { pos -= 85;  return strip.Color(0, pos * 3, 255 - pos * 3); }
  pos -= 170;
  return strip.Color(pos * 3, 255 - pos * 3, 0);
}

void setup() {
  strip.begin();
  strip.show();               // all off
  // strip.setBrightness(80); // uncomment if it's too bright
}

void loop() {
  strip.clear();

  // Draw the comet head + 2 trailing pixels behind the direction of travel
  for (int t = 0; t < 3; t++) {
    int p = pos - dir * t;                 // trail sits BEHIND the head
    if (p < 0 || p >= NUM_LEDS) continue;  // skip if it fell off the strip

    uint32_t c = Wheel((hue + p * 20) & 255);  // rainbow hue per LED

    // Fade the trail: t=0 = head full brightness, t=1 dimmer, t=2 dimmest
    uint8_t scale = 255 - t * 70;          // 255, 185, 115
    uint8_t r = ((c >> 16) & 0xFF) * scale / 255;
    uint8_t g = ((c >>  8) & 0xFF) * scale / 255;
    uint8_t b = ( c        & 0xFF) * scale / 255;

    strip.setPixelColor(p, strip.Color(r, g, b));
  }

  strip.show();

  // Advance position and bounce off the ends
  pos += dir;
  if (pos >= NUM_LEDS) { pos = NUM_LEDS - 2; dir = -1; }
  if (pos <  0)        { pos = 1;            dir =  1; }

  hue = (hue + 3) & 255;   // slowly rotate the rainbow
  delay(60);
}