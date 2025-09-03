#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h> // optional font

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

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

  // OLED initialization
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);

  display.setFont(&FreeSerif9pt7b);  // optional
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.clearDisplay();
}

void loop() {
  int sensorValue = analogRead(soilPin);
  Serial.print(sensorValue);

  // Clear previous OLED content
  display.clearDisplay();

  // Display sensor value
  display.setCursor(0, 15);
  display.print("Soil: ");
  display.println(sensorValue);

  // Check soil condition
  if(sensorValue > 800){
    Serial.println(" - Time to water your plant");
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

    // Display on OLED
    display.setCursor(0, 40);
    display.print("Water your plant!");
  }
  else {
    Serial.println(" - Doesn't need watering");
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);

    // Display on OLED
    display.setCursor(0, 40);
    display.print("Soil is fine");
  }

  display.display(); // Refresh OLED
  delay(500);
}
