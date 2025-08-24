#define IRSensor D0  // IR sensor output pin
#define LED D7       // LED or Buzzer pin


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.println("Serial Working");   // check if serial monitor is working

  // Set PinMode
  pinMode(IRSensor, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorStatus = digitalRead(IRSensor);

  /*
  IR sensor output is often inverted

  Many IR obstacle avoidance sensors give:

  LOW (0) when obstacle is detected

  HIGH (1) when no obstacle is detected  
  */

  if (sensorStatus == LOW) { // change this to high if it shows no obstacle
    digitalWrite(LED, HIGH);
    Serial.println("Obstacle Detected");
  }
  else {
    digitalWrite(LED, LOW);
    Serial.println("NO Obstacle Detected");
  }
  delay(200);
}
