#include <Arduino.h>


// ====================
// Function Declarations
// ====================

void InitLedPins();



// ====================
// Global Variables
// ====================

const uint8_t Led_Pins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
const uint8_t Led_Number = sizeof(Led_Pins) / sizeof(Led_Pins[0]);

const uint8_t Potmeter_Pin = A6;



// ====================
// Main Program
// ====================

void setup() {
    // Initialize pins
    InitLedPins();
    pinMode(Potmeter_Pin, OUTPUT);
}

void loop() {
    // Read the potmeter value
    uint16_t potmeterValue = analogRead(Potmeter_Pin);

    // Map the potmeter
    uint8_t ledIndex = map(potmeterValue, 0, 1023, 0, Led_Number);

    // Turn on the led
    for (uint8_t i = 0; i < Led_Number; i++) {
        if (i < ledIndex) {
            digitalWrite(Led_Pins[i], HIGH);
        } else {
            digitalWrite(Led_Pins[i], LOW);
        }
    }

    // Wait
    delay(10);
}



// ====================
// Functions
// ====================

void InitLedPins() {
    for (uint8_t i = 0; i < Led_Number; i++) {
        pinMode(Led_Pins[i], OUTPUT);
    }
}