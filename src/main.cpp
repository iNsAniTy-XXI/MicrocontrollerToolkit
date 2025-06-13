#include <Arduino.h>
#include "LED.h"
#include "LCD.h"
#include "UltrasonicSensor.h"

// LED
#define LED_PIN 31

// LCD
#define LCD_RS_PIN 26
#define LCD_EN_PIN 27
#define LCD_D4_PIN 25
#define LCD_D5_PIN 24
#define LCD_D6_PIN 23 
#define LCD_D7_PIN 22

// Ultrasonic Sensor
#define USS_TRIG_PIN 34
#define USS_ECHO_PIN 35

LED* led;
LCD* lcd;
UltrasonicSensor* ultrasonicSensor;

void log(long duration);

void setup() {
  led = new LED(LED_PIN);
  lcd = new LCD(LCD_RS_PIN, LCD_EN_PIN, LCD_D4_PIN, LCD_D5_PIN, LCD_D6_PIN, LCD_D7_PIN);
  ultrasonicSensor = new UltrasonicSensor(USS_TRIG_PIN, USS_ECHO_PIN, MeasurementUnit::Inches);
}

void loop() {
  long distance = ultrasonicSensor -> readDistance();
  log(distance);

  if (distance < 6) {
    led -> turnOn();
  }
  else {
    led -> turnOff();
  }

  delay(1000);
}

void log(long distance) {  
  lcd -> clear();
  lcd -> displayMessage("Distance is: ");
  lcd -> setCursor(lcd -> getRowIndex() + 1, lcd -> getColumnIndex());
  lcd -> displayMessage(ultrasonicSensor -> stringify(distance));
}