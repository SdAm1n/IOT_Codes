#include <Servo.h>

Servo servo;
unsigned long MOVING_TIME = 3000; // moving time is 3 seconds
unsigned long move_start_ms;
int angle_start = 30; // 30°
int angle_stop = 90; // 90°

void setup() {
  servo.attach(D7);
  move_start_ms = millis(); // start moving

  // TODO: other code
}

void loop() {
  unsigned long progress = millis() - move_start_ms;

  if (progress <= MOVING_TIME) {
    long angle = map(progress, 0, MOVING_TIME, angle_start, angle_stop);
    servo.write(angle);
  }

  // TODO: other code
}
