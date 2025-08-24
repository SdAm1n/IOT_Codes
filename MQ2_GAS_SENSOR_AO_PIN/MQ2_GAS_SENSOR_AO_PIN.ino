/*
You must warm up the MQ2 Sensor before using it for 5-10 mins by connecting 5V and GND
*/

#define AO_PIN A0


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int gasValue = analogRead(AO_PIN);

  Serial.print("MQ2 sensor AO Value: ");
  Serial.println(gasValue);
  delay(500);
}
