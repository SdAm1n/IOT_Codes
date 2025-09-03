int soilPin = A0;
int greenLED = D8;
int redLED = D7;


void setup(){
  pinMode(soilPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);


  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);


  Serial.begin(9600);
}

void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(soilPin);
  Serial.print(sensorValue);

  if(sensorValue > 800){
    Serial.println(" - Time to water your plant");
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  else {
    Serial.println(" - Doesn't need watering");
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
  }

  delay(500);
}