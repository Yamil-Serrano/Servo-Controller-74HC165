#include <Arduino.h>
#include <Servo.h>

// Pins for the 74HC165
const int clockPin = 13;
const int shiftLoadPin = 12;
const int QHPin = 11;

// Pins for the servos
const int Servo_0_Pin = 10;
const int Servo_1_Pin = 9;

Servo servo0;
Servo servo1;

byte lastData = 0;

void setup() {
  // Configure 74HC165 pins
  pinMode(clockPin, OUTPUT);
  pinMode(shiftLoadPin, OUTPUT);
  pinMode(QHPin, INPUT);

  digitalWrite(clockPin, LOW);

  // Attach servos
  servo0.attach(Servo_0_Pin);
  servo1.attach(Servo_1_Pin);

  // Initial position
  servo0.write(90); // Center
  servo1.write(90); // Center
}

byte Input_74HC165() {
  digitalWrite(shiftLoadPin, LOW);
  delayMicroseconds(5);
  digitalWrite(shiftLoadPin, HIGH); 

  byte data = 0;
  for (int i = 7; i >= 0; i--) {
    int bit = digitalRead(QHPin);
    data |= (bit << i);
    digitalWrite(clockPin, HIGH);
    delayMicroseconds(2);
    digitalWrite(clockPin, LOW);
  }
  return data;
}

void loop() {
  byte currentData = Input_74HC165();

  if (currentData != lastData) {
    lastData = currentData;

    // Detect button combinations and move servos
    switch (currentData) {
      case 0b10000000: // D7 pressed
        servo0.write(60); // Left
        break;
      case 0b01000000: // D6 pressed 
        servo0.write(120); // Right
        break;
      case 0b00100000: // D5 pressed 
        servo1.write(60); // Left
        break;
      case 0b00010000: // D4 pressed 
        servo1.write(120); // Right
        break;
      default:
        // No button pressed, return to center
        servo0.write(90);
        servo1.write(90);
        break;
    }
  }

  delay(10);
}
