#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64  // adjust according to your OLED

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 failed");
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
/*
If the line at y=31 is visible → physical height = 32 px

If the line at y=63 is visible → physical height = 64 px
*/

  display.drawLine(0, 31, 127, 31, WHITE); // bottom row for 32px panel
display.drawLine(0, 63, 127, 63, WHITE); // bottom row for 64px panel
  display.display();
}

void loop() {}
