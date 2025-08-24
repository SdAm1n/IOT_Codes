
#define MOTION_SENSOR_PIN  D7  // The ESP8266 pin D7 connected to the OUTPUT pin of motion sensor

int motion_state   = LOW; // current state of pin
int prev_motion_state  = LOW; // previous state of pin

void setup() {
  Serial.begin(9600);            // Initialize the Serial to communicate with the Serial Monitor.
  pinMode(MOTION_SENSOR_PIN, INPUT); // set arduino pin to input mode to read value from OUTPUT pin of sensor
}

void loop() {
  prev_motion_state = motion_state; // store old state
  motion_state = digitalRead(MOTION_SENSOR_PIN);   // read new state

  if (prev_motion_state == LOW && motion_state == HIGH) {   // pin state change: LOW -> HIGH
    Serial.println("Motion detected!");
    // TODO: turn on alarm, light or activate a device ... here
  }
  else
  if (prev_motion_state == HIGH && motion_state == LOW) {   // pin state change: HIGH -> LOW
    Serial.println("Motion stopped!");
    // TODO: turn off alarm, light or deactivate a device ... here
  }
}
