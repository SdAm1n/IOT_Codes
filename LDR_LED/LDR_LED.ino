#define LED_PIN D7   // D4 on NodeMCU (GPIO2) or pin 13 on Arduino Uno

void setup() {
  Serial.begin(9600);       // initialize serial communication
  pinMode(LED_PIN, OUTPUT); // set LED pin as output
}

void loop() {
  int sensorValue = analogRead(A0); // read analog value from LDR
  float voltage = sensorValue * (5.0 / 1023.0); // map to 0–5V

  Serial.print("Voltage: ");
  Serial.println(voltage);

  // Simple threshold check
  if (voltage < 2.5) { // if it is dark (low voltage from LDR)
    digitalWrite(LED_PIN, HIGH); // turn LED ON
  } else {
    digitalWrite(LED_PIN, LOW);  // turn LED OFF
  }

  delay(500);
}
