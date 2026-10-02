


#include "Arduino.h"
#define LIGHT_PIN       33
#define PERIOD_MS       300
#define HIGH_THRESHOLD  3000
#define LOW_THRESHOLD   2500

bool alertActive = false;
unsigned long lastReadMs = 0;


/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    analogReadResolution(12);
    Serial.println("Ex3: Threshold alert with hysteresis");
}


/****************************************************/
void loop(void) 
{
    unsigned long now = millis();
    if (now - lastReadMs < PERIOD_MS) return;
    lastReadMs = now;

    int raw = analogRead(LIGHT_PIN);

    if (!alertActive && raw > HIGH_THRESHOLD) {
        alertActive = true;
        Serial.println("ALERT=1");
    } else if (alertActive && raw < LOW_THRESHOLD) {
        alertActive = false;
        Serial.println("ALERT=0");
    }
}
