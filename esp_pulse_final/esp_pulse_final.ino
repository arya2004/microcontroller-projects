#include <Arduino.h>
#include <WiFi.h>

hw_timer_t * sampleTimer = NULL;
portMUX_TYPE sampleTimerMux = portMUX_INITIALIZER_UNLOCKED;
#define USE_ARDUINO_INTERRUPTS true
//#define NO_PULSE_SENSOR_SERIAL true
#include <PulseSensorPlayground.h>
PulseSensorPlayground pulseSensor;



const int PULSE_INPUT = 36;
const int PULSE_BLINK = 2;    
const int THRESHOLD = 685; 

void IRAM_ATTR onSampleTime() {
  portENTER_CRITICAL_ISR(&sampleTimerMux);
    PulseSensorPlayground::OurThis->onSampleTime();
  portEXIT_CRITICAL_ISR(&sampleTimerMux);
}



void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  analogReadResolution(10);
  
/*  Configure the PulseSensor manager  */
  pulseSensor.analogInput(PULSE_INPUT);
  pulseSensor.blinkOnPulse(PULSE_BLINK);
  pulseSensor.setSerial(Serial);
  pulseSensor.setThreshold(THRESHOLD);

    sampleTimer = timerBegin(0, 80, true);                
  timerAttachInterrupt(sampleTimer, &onSampleTime, true);  
  timerAlarmWrite(sampleTimer, 2000, true);      
  timerAlarmEnable(sampleTimer);


}

void loop() {
  delay(500);
  // put your main code here, to run repeatedly:
Serial.print(pulseSensor.getBeatsPerMinute());
      Serial.println(" bpm");
}
