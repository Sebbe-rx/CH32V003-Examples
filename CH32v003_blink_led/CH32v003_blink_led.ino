void setup() {
  pinMode(PC1, OUTPUT);
}

void loop() {
  digitalWrite(PC1, HIGH);
  delay(500);
  digitalWrite(PC1, LOW);
  delay(500);

}
