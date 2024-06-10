/*************************************************************
  ButtonRead.ino
  Description: Reads the state of five digital input pins and prints their values to Serial Monitor.

  Author: arya2004

  This example code is in the public domain.
*************************************************************/

void setup() {
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
  Serial.println("NEW"); // Print a label indicating new data
  int thre = digitalRead(3); // Read digital pin 3
  Serial.print("3 : ");
  Serial.println(thre); // Print the value read from pin 3

  int fo = digitalRead(4); // Read digital pin 4
  Serial.print("4 : ");
  Serial.println(fo); // Print the value read from pin 4

  int fi = digitalRead(5); // Read digital pin 5
  Serial.print("5 : ");
  Serial.println(fi); // Print the value read from pin 5

  int si = digitalRead(6); // Read digital pin 6
  Serial.print("6 : ");
  Serial.println(si); // Print the value read from pin 6

  int se = digitalRead(7); // Read digital pin 7
  Serial.print("7 : ");
  Serial.println(se); // Print the value read from pin 7

  delay(1000); // Wait for 1000 milliseconds before reading again
}
