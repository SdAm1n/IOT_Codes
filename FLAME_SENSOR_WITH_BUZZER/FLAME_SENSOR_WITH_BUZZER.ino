int BUZZER = D7; // use led or buzzer
int FLAME_SENSOR = D1;

/*
If you are using a buzzer, you need to find out if the buzzer is passive or active.

Power test (easy method):

Connect the buzzer directly to 5V (or 3.3V):

Active buzzer: makes a steady “beep” as soon as you power it.

Passive buzzer: stays silent (it needs a frequency signal, not DC).
*/


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(BUZZER, OUTPUT);
  pinMode(FLAME_SENSOR, INPUT); // use INPUT_PULLUP for 3.3v

}

void loop() {
  // put your main code here, to run repeatedly:
  int flame_detected = digitalRead(FLAME_SENSOR);

  if (flame_detected == LOW) {
    Serial.println("Flame Detected.....");
    // digitalWrite(BUZZER, HIGH);    // use this line for LED or Active Buzzer
    tone(BUZZER, 1000);               // for passive buzzer
    delay(500);
    noTone(BUZZER);
  }
  else {
    Serial.println("No Flame.....");
    // digitalWrite(BUZZER, LOW);     // use this line for LED or Active Buzzer
    noTone(BUZZER);                   // for passive buzzer
    delay(500);
  }

}
