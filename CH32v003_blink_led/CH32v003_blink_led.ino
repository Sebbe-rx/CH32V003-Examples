// Fade an LED on pin PC1
int ledPin = PD2;         // PWM-capable pin
int brightness = 0;       // Current brightness
int fadeAmount = 30;       // Step size for fading

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Set the brightness of the LED
  analogWrite(ledPin, brightness);

  // Change the brightness for the next iteration
  brightness = brightness + fadeAmount;

  // Reverse the direction of the fading at the ends
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  // Wait for 30 milliseconds to see the dimming effect
  delay(30);
}