/*
  HelloWorldLCD.ino
  Description: This code demonstrates the use of a 16x2 LCD display with the LiquidCrystal library.
  It initializes the LCD, prints "qwerty" on the first line, and then continuously prints "hello"
  on the second line. The LiquidCrystal library is compatible with all LCD displays that use the
  Hitachi HD44780 driver.

  The circuit:
  * LCD RS pin to digital pin 12
  * LCD Enable pin to digital pin 11
  * LCD D4 pin to digital pin 5
  * LCD D5 pin to digital pin 4
  * LCD D6 pin to digital pin 3
  * LCD D7 pin to digital pin 2
  * LCD R/W pin to ground
  * LCD VSS pin to ground
  * LCD VCC pin to 5V
  * 10K resistor:
    * ends to +5V and ground
    * wiper to LCD VO pin (pin 3)

  Original library contributions by David A. Mellis, Limor Fried, Tom Igoe.
  This example code is in the public domain.

  For more information: http://www.arduino.cc/en/Tutorial/LiquidCrystal
*/

#include <LiquidCrystal.h>

// Initialize an instance of the LiquidCrystal class with the interface pins
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

// Global variable to keep track of the seconds
int seconds = 0;

void setup() {
  // Initialize the LCD with 16 columns and 2 rows
  lcd_1.begin(16, 2);

  // Print "qwerty" to the first line of the LCD
  lcd_1.print("qwerty");
}

void loop() {
  // Set the cursor to column 2, line 1 (second row)
  lcd_1.setCursor(2, 1);

  // Print "hello" on the second line of the LCD
  lcd_1.print("hello");

  // Wait for 1 second (1000 milliseconds)
  delay(1000);

  // Increment the seconds variable
  seconds += 1;
}
