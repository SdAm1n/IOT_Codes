const int trigPin = D6;
const int echoPin = D5;

#define SOUND_VELOCITY 0.034 // 20 degree -> 340 m/s
#define CM_TO_INCH 0.393701  // to convert it to from cm to inch
#define MIN_DISTANCE_CM 2   // reliable minimum distance
#define MAX_DISTANCE_CM 400 // HC-SR04 maximum range

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear trigger
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send trigger pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo duration
  long duration = pulseIn(echoPin, HIGH, 30000); // timeout after 30ms (~5m)
  
  if (duration == 0) {
    Serial.println("No echo detected (object too close or out of range).");
  } 
  else if (duration < 200) {  // very short pulse = unreliable (< ~2 cm)
    Serial.println("Object too close!");
  }
  else {
    float distanceCm = (duration * SOUND_VELOCITY) / 2;

    if (distanceCm < MIN_DISTANCE_CM) {
      Serial.println("Object too close!");
    } 
    else if (distanceCm > MAX_DISTANCE_CM) {
      Serial.println("Object out of range!");
    }
     else {
      // Valid distance
      float distanceInch = distanceCm * CM_TO_INCH;
      Serial.print("Distance (cm): ");
      Serial.println(distanceCm);
      Serial.print("Distance (inch): ");
      Serial.println(distanceInch);
    }
  }

  delay(1000);
}
