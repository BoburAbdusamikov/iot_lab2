


#include "Arduino.h"
#define LIGHT_PIN    33
#define PERIOD_MS    1000
#define NUM_SAMPLES  10

unsigned long lastSampleMs = 0;


/****************************************************/
void setup(void) 
{
 Serial.begin(115200);
    analogReadResolution(12);           
    Serial.println("Ex2: Sensor statistics");
}


/****************************************************/
void loop(void) 
{
     unsigned long now = millis();
    if (now - lastSampleMs < PERIOD_MS) return;
    lastSampleMs = now;

    int  minVal = 4095;
    int  maxVal = 0;
    long sum    = 0;

    for (int i = 0; i < NUM_SAMPLES; i++) {     
        int v = analogRead(LIGHT_PIN);
        if (v < minVal) minVal = v;
        if (v > maxVal) maxVal = v;
        sum += v;
    }

    int avg = (int)((sum + NUM_SAMPLES / 2) / NUM_SAMPLES);   

    Serial.printf("min=%d max=%d avg=%d\n", minVal, maxVal, avg);
    
}
