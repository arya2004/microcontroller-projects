/*************************************************************
  Blink.ino
  Description: Turns an LED on for one second, then off for one second, repeatedly.

  Board Compatibility:
  - Most Arduinos have an on-board LED you can control. On the UNO, MEGA, and ZERO it is attached to digital pin 13, on MKR1000 on pin 6.
  - LED_BUILTIN is set to the correct LED pin independent of which board is used.
  - Check the Technical Specs of your board at https://www.arduino.cc/en/Main/Products to know the on-board LED pin for your Arduino model.

  Modified:
  - 8 May 2014 by Scott Fitzgerald
  - 2 Sep 2016 by Arturo Guadalupi
  - 8 Sep 2016 by Colby Newman

  This example code is in the public domain.
  Source: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*************************************************************/

// The setup function runs once when you press reset or power the board
void setup() {
  // Initialize digital pin LED_BUILTIN as an output
  pinMode(LED_BUILTIN, OUTPUT);
}

// The loop function runs repeatedly forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED on (HIGH is the voltage level)
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // Turn the LED off by making the voltage LOW
  delay(1000);                      // Wait for a second
}
