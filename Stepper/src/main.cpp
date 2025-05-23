#include <Arduino.h>

#define STEP_PIN 4
#define DIR_PIN 7
#define EN_PIN 8

String command;
bool motorOn = false;
bool direction = true; // true = rechts, false = links

// Funktion zuerst definieren
void stepOnce() {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(3200); // Wert vergrößert, um die Geschwindigkeit auf ca. 25% zu verringern
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(3200); // Wert vergrößert
}

void setup() {
    Serial.begin(9600);
    pinMode(STEP_PIN, OUTPUT);
    pinMode(DIR_PIN, OUTPUT);
    pinMode(EN_PIN, OUTPUT);

    digitalWrite(EN_PIN, LOW); // Motor aktivieren
    digitalWrite(DIR_PIN, direction ? HIGH : LOW);
    Serial.println("Bereit. Befehle: start, stop, links, rechts, step");
}

void loop() {
    if (Serial.available()) {
        command = Serial.readStringUntil('\n');
        command.trim();

        if (command == "start") {
            motorOn = true;
        } else if (command == "stop") {
            motorOn = false;
        } else if (command == "links") {
            direction = false;
            digitalWrite(DIR_PIN, LOW);
        } else if (command == "rechts") {
            direction = true;
            digitalWrite(DIR_PIN, HIGH);
        } else if (command == "step") {
            stepOnce();
        }

        Serial.println("Befehl empfangen: " + command);
    }

    if (motorOn) {
        stepOnce();
    }
}