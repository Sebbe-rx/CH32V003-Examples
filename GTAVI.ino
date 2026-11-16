#include <Adafruit_NeoPixel.h>

#define LED_PIN    PC1
#define NUM_LEDS   49

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(180);   

  for (int i = 0; i < NUM_LEDS; i++) {
    uint16_t t = (uint16_t)((uint32_t)i * 512UL / (NUM_LEDS - 1));

    uint8_t r, g, b;
    if (t < 256) {
      r = 255 - (uint8_t)(((uint16_t)(255 - 150) * t) / 256);
      g = 0;
      b = 160 + (uint8_t)(((uint16_t)(210 - 160) * t) / 256);
    } else {
      uint16_t u = t - 256;
      r = 150 + (uint8_t)(((uint16_t)(255 - 150) * u) / 256);
      g = 0   + (uint8_t)(((uint16_t)(110 - 0)   * u) / 256);
      uint32_t b32 = (uint32_t)210 * (256 - u) * (256 - u) / (256UL * 256UL);
      b = (uint8_t)b32;
    }

    strip.setPixelColor(i, strip.Color(r, g, b));
  }

  strip.show();
}

void loop() {
}
