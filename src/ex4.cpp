


#include "Arduino.h"
#define RED_LED_PIN    26
#define GREEN_LED_PIN  27
#define YELLOW_LED_PIN 12
#define BLUE_LED_PIN   14
#define BUTTON_PIN     25         
#define DEBOUNCE_MS    50
#define MAX_COUNT      4

const int ledPins[4] = { RED_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN, BLUE_LED_PIN };

int counter = 0;
int lastReading = LOW;             
unsigned long lastChangeMs = 0;

void showCounter(int n)
{
    for (int i = 0; i < 4; i++) {
        digitalWrite(ledPins[i], (i < n) ? HIGH : LOW);
    }
}

/****************************************************/
void setup(void) 
{
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT);
    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
    showCounter(counter);
    Serial.println("Ex4: Button press counter");

}


/****************************************************/
void loop(void) 
{
     int reading = digitalRead(BUTTON_PIN);
    if (reading != lastReading) {
        unsigned long now = millis();
        if (reading == HIGH && (now - lastChangeMs) > DEBOUNCE_MS) {
            counter++;
            if (counter > MAX_COUNT) counter = 0;   
            showCounter(counter);
            Serial.printf("count=%d\n", counter);
        }
        lastChangeMs = now;
        lastReading = reading;
    }
}
