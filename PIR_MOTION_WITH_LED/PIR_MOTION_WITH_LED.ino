
int LED = D6;  // Digital pin D0
int pir_sensor = D7;  // Digital pin D6
void setup() {
  Serial.begin(9600);
  pinMode(pir_sensor, INPUT);   // declare sensor as input
  pinMode(LED, OUTPUT);  // declare LED as output
}
void loop() {
  long state = digitalRead(pir_sensor);
    if(state == HIGH) {
      digitalWrite (LED, HIGH);
      Serial.println("Motion detected!");
      delay(1000);
    }
    else {
      digitalWrite (LED, LOW);
      Serial.println("Motion not detected!");
      delay(1000);
      }
}