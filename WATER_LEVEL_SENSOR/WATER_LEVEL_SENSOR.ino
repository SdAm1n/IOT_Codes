int waterSensor = A0;   // Analog pin for water level sensor
int waterValue = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Water Level Sensor Initialized");
}

void loop() {
  // Read water sensor value
  waterValue = analogRead(waterSensor);

  // Convert to percentage (0–1023 mapped to 0–100%)
  int waterPercent = map(waterValue, 0, 1023, 0, 100);

  // Print to Serial Monitor
  Serial.print("Raw Value: ");
  Serial.print(waterValue);
  Serial.print("  |  Water Level: ");
  Serial.print(waterPercent);
  Serial.println("%");

  delay(500); // wait 0.5 seconds before next reading
}
