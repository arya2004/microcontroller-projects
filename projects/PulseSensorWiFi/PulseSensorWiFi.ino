/*
  PulseSensorWiFi.ino
  Description: This code uses an ESP32 to measure the heart rate using a pulse sensor and displays the beats per minute (BPM) on the serial monitor. It utilizes hardware timers to sample the pulse sensor data accurately.

  Circuit:
  - Pulse sensor connected to ESP32
    - Signal pin to pin 36 (analog input)
    - VCC to 3.3V
    - GND to GND
  - LED connected to pin 2 to blink on pulse detection

  Dependencies:
  - PulseSensorPlayground library for pulse sensor management
  - WiFi library for WiFi connectivity (if needed)

  Notes:
  - Replace the placeholders for WiFi credentials if needed.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <PulseSensorPlayground.h>

// Timer and interrupt settings
hw_timer_t *sampleTimer = NULL;
portMUX_TYPE sampleTimerMux = portMUX_INITIALIZER_UNLOCKED;

// Pulse sensor settings
#define PULSE_INPUT 36
#define PULSE_BLINK 2    
#define THRESHOLD 685 

PulseSensorPlayground pulseSensor;

// Interrupt service routine for pulse sensor sampling
void IRAM_ATTR onSampleTime() {
  portENTER_CRITICAL_ISR(&sampleTimerMux);
  PulseSensorPlayground::OurThis->onSampleTime();
  portEXIT_CRITICAL_ISR(&sampleTimerMux);
}

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  
  // Set analog read resolution to 10 bits
  analogReadResolution(10);
  
  // Configure the PulseSensor manager
  pulseSensor.analogInput(PULSE_INPUT);
  pulseSensor.blinkOnPulse(PULSE_BLINK);
  pulseSensor.setSerial(Serial);
  pulseSensor.setThreshold(THRESHOLD);

  // Initialize and configure the timer
  sampleTimer = timerBegin(0, 80, true);                // Initialize timer 0 with a prescaler of 80
  timerAttachInterrupt(sampleTimer, &onSampleTime, true);  // Attach interrupt to the timer
  timerAlarmWrite(sampleTimer, 2000, true);             // Set alarm to trigger every 2000 microseconds (500Hz)
  timerAlarmEnable(sampleTimer);                        // Enable the timer alarm
}

void loop() {
  // Delay for readability
  delay(500);

  // Print BPM to serial monitor
  Serial.print(pulseSensor.getBeatsPerMinute());
  Serial.println(" bpm");
}
