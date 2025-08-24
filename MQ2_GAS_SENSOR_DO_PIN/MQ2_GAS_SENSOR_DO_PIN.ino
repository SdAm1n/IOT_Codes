/*
You must warm up the MQ2 Sensor before using it for 5-10 mins by connecting 5V and GND
*/

#define DO_PIN D1
#define BUZZER D7     // if you want to use buzzer


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(DO_PIN, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int gasState = digitalRead(DO_PIN);

  if (gasState == HIGH) {
    Serial.println("The Gas is not Present");

    
    noTone(BUZZER);
    delay(500);
  }
  else {
    Serial.println("The Gas is Present");
    
    // for passive buzzer
    tone(BUZZER, 2000);
    delay(500);
    noTone(BUZZER);
  }
}
