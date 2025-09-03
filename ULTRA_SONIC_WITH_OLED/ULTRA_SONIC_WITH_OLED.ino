#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h> //optional for font use

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int trigPin = D6;
const int echoPin = D5;

#define SOUND_VELOCITY 0.034 // 20 degree -> 340 m/s
#define CM_TO_INCH 0.393701  // to convert cm to inch
#define MIN_DISTANCE_CM 2    // reliable minimum distance
#define MAX_DISTANCE_CM 400  // HC-SR04 maximum range

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(500);

  display.setFont(&FreeSerif9pt7b);  //optional
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
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

  display.clearDisplay();   // always clear screen before writing
  display.setCursor(0, 25); // y-position for centered text

  if (duration == 0) {
    Serial.println("No echo detected (object too close or out of range).");
    display.print("No Echo");
  }
  else {
    float distanceCm = (duration * SOUND_VELOCITY) / 2;

    if (distanceCm < MIN_DISTANCE_CM) {
      Serial.println("Object too close!");
      display.print("Too Close!");
    } 
    else if (distanceCm > MAX_DISTANCE_CM) {
      Serial.println("Object out of range!");
      display.print("Out of Range!");
    }
    else {
      // Valid distance
      float distanceInch = distanceCm * CM_TO_INCH;
      Serial.print("Distance (cm): ");
      Serial.println(distanceCm);
      Serial.print("Distance (inch): ");
      Serial.println(distanceInch);

      // Show both cm and inch on OLED
      display.setCursor(0, 15);
      display.print(distanceCm); // 1 decimal place
      display.print(" cm");

      display.setCursor(0, 30);
      display.print(distanceInch);
      display.print(" in");
    }
  }

  display.display(); 
  delay(500);
}
