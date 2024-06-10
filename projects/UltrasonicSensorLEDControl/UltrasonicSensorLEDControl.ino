/*
  UltrasonicSensorLEDControl.ino
  Description: This code uses an Arduino to measure distance using an ultrasonic sensor
  and control an LED based on the distance measured. Additionally, it reads an analog
  value from a potentiometer and controls another LED based on the potentiometer value.

  Circuit 1 (Ultrasonic sensor):
  - Trig pin connected to Arduino pin 7
  - Echo pin connected to Arduino pin 8
  - LED connected to Arduino pin 2

  Circuit 2 (Potentiometer):
  - Potentiometer wiper connected to Arduino pin A5
  - LED connected to Arduino pin 4

  Dependencies:
  - None
*/

// Function to measure distance using an ultrasonic sensor
long measureDistance(int trigPin, int echoPin) {
  // Clear the trigger pin
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Set the echo pin to input
  pinMode(echoPin, INPUT);
  
  // Calculate the distance in cm
  return (0.01723 * pulseIn(echoPin, HIGH));
}

// Setup function for the ultrasonic sensor and LED control
void setupUltrasonic() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
}

// Loop function for the ultrasonic sensor and LED control
void loopUltrasonic() {
  long distance = measureDistance(7, 8);
  Serial.println(distance);
  
  if (distance > 30) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
  
  delay(100);
}

// Setup function for the potentiometer and LED control
void setupPotentiometer() {
  Serial.begin(9600);
  pinMode(A5, INPUT);
  pinMode(4, OUTPUT);
}

// Loop function for the potentiometer and LED control
void loopPotentiometer() {
  int value = analogRead(A5);
  Serial.println(value);

  if (value < 200) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
  
  delay(100);
}

void setup() {
  // Uncomment the setup you want to use
  // setupUltrasonic();
  // setupPotentiometer();
}

void loop() {
  // Uncomment the loop you want to use
  // loopUltrasonic();
  // loopPotentiometer();
}
