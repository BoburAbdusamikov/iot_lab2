


#include "Arduino.h"

#define RED_LED_PIN    26
#define GREEN_LED_PIN  27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN   14
#define STEP_MS        150

const int allPins[4] = { RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN, BLUE_LED_PIN };

const int   chasePins[6]  = { RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN,
                              BLUE_LED_PIN, YELLOW_LED_PIN, GREEN_LED_PIN };
const char* chaseNames[6] = { "RED", "GREEN", "YELLOW", "BLUE", "YELLOW", "GREEN" };
const int   CHASE_STEPS   = 6;

int stepIndex = 0;  

/****************************************************/
void setup(void) 
{
   Serial.begin(115200);
    for (int i = 0; i < 4; i++) {
        pinMode(allPins[i], OUTPUT);
        digitalWrite(allPins[i], LOW);
    }
    Serial.println("Ex1: LED chase");
}


/****************************************************/
void loop(void) 
{
    for (int i = 0; i < 4; i++) {
        digitalWrite(allPins[i], LOW);
    }
    digitalWrite(chasePins[stepIndex], HIGH);
    Serial.printf("chase=%s\n", chaseNames[stepIndex]);
    stepIndex = (stepIndex + 1) % CHASE_STEPS; 

    delay(STEP_MS); 
}
