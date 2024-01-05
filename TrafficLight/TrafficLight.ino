#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
  pinMode(0, OUTPUT); // Red LED
  pinMode(1, OUTPUT); // Green LED
  pinMode(2, OUTPUT); // Orange LED
}

void countdownDisplay(int startValue) {
  for (int i = startValue; i > 0; i--) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Countdown: ");
    lcd.setCursor(11, 0);
    lcd.print(i);
    delay(1000);
  }
}

void trafficLight(int redDelay, int greenDelay, int orangeDelay) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");

  // Red Light
  digitalWrite(0, HIGH); // Red LED on
  digitalWrite(1, LOW);  // Green LED off
  digitalWrite(2, LOW);  // Orange LED off
  countdownDisplay(redDelay);

  // Green Light
  digitalWrite(0, LOW);   // Red LED off
  digitalWrite(1, HIGH);  // Green LED on
  digitalWrite(2, LOW);   // Orange LED off
  countdownDisplay(greenDelay);

  // Orange Light
  digitalWrite(0, LOW);   // Red LED off
  digitalWrite(1, LOW);   // Green LED off
  digitalWrite(2, HIGH);  // Orange LED on
  countdownDisplay(orangeDelay);

  // Turn off all LEDs
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(2, LOW);
}

void loop() {
  trafficLight(3, 3, 3); // Adjust the delay values as needed
}