int PulseSensorPurplePin = 36;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0

int LED21 = 2;   //  The on-board Arduion LED

int Signal;                // holds the incoming raw data. Signal value can range from 0-1024

int Threshold = 2200;            // Determine which Signal to “count as a beat”, and which to ingore.

// The SetUp Function:

void setup() {

pinMode(2,OUTPUT);         // pin that will blink to your heartbeat!

Serial.begin(9600);         // Set’s up Serial Communication at certain speed.

}

// The Main Loop Function

void loop() {

Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor’s value.

// Assign this value to the “Signal” variable.

Serial.println(Signal);                    // Send the Signal value to Serial Plotter.

if(Signal > Threshold){                          // If the signal is above “550”, then “turn-on” Arduino’s on-Board LED.

digitalWrite(2,HIGH);

} else {

digitalWrite(2,LOW);                //  Else, the sigal must be below “550”, so “turn-off” this LED.

}

delay(10);

}