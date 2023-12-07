void setup()
{
    for (int i = 2; i < 11; i++) {
        pinMode(i, OUTPUT); // PINS 2-10 are set as output
    }

    pinMode(A0, OUTPUT); // PIN A0 set as output
    pinMode(A1, OUTPUT); // PIN A1 set as output
    pinMode(A2, OUTPUT); // PIN A2 set as output

    digitalWrite(A0, HIGH); // Pull up the A0 pin
    digitalWrite(A1, HIGH); // Pull up the A1 pin
    digitalWrite(A2, HIGH); // Pull up the A2 pin
}
void loop()
{
    // Pattern 1: Each LED turns on sequentially
    for (int layer = 0; layer < 3; layer++) {
        digitalWrite(A0 + layer, LOW); // Ground the current layer

        for (int i = 2; i < 11; i++) {
            digitalWrite(i, HIGH); // Turn on each LED one after another
            delay(100);
            digitalWrite(i, LOW);
        }

        digitalWrite(A0 + layer, HIGH); // Pull up the current layer
    }

    delay(100); // Delay between patterns

    // Pattern 2: Two LEDs turn on in each row sequentially
    for (int layer = 0; layer < 3; layer++) {
        digitalWrite(A0 + layer, LOW); // Ground the current layer

        for (int i = 2; i < 9; i += 2) {
            digitalWrite(i, HIGH); // Turn on two LEDs in each row
            digitalWrite(i + 1, HIGH);
            delay(100);
            digitalWrite(i, LOW);
            digitalWrite(i + 1, LOW);
        }

        digitalWrite(A0 + layer, HIGH); // Pull up the current layer
    }

    delay(500); // Delay between patterns

    // Pattern 3: All three LEDs turn on in each row simultaneously
    for (int layer = 0; layer < 3; layer++) {
        digitalWrite(A0 + layer, LOW); // Ground the current layer

        for (int i = 2; i < 11; i++) {
            digitalWrite(i, HIGH); // Turn on all three LEDs in each row
        }

        delay(100); // Delay for all LEDs to stay on

        for (int i = 2; i < 11; i++) {
            digitalWrite(i, LOW); // Turn off all three LEDs
        }

        digitalWrite(A0 + layer, HIGH); // Pull up the current layer

        delay(100); // Small delay before moving to the next pattern
    }

    // Pattern 4: Random pattern
    for (int layer = 0; layer < 3; layer++) {
        digitalWrite(A0 + layer, LOW); // Ground the current layer

        for (int i = 2; i < 11; i++) {
            if (rand() % 2 == 0) { // Randomly turn on/off LEDs
                digitalWrite(i, HIGH);
            } else {
                digitalWrite(i, LOW);
            }
        }

        delay(100); // Delay for the random pattern

        for (int i = 2; i < 11; i++) {
            digitalWrite(i, LOW); // Turn off all LEDs
        }

        digitalWrite(A0 + layer, HIGH); // Pull up the current layer

        delay(100); // Small delay before moving to the next pattern
    }

    // Pattern 5: All LEDs turn on simultaneously
    for (int i = 2; i < 11; i++) {
        digitalWrite(i, HIGH); // Turn on all LEDs
    }

    delay(100); // Delay for all LEDs to stay on

    for (int i = 2; i < 11; i++) {
        digitalWrite(i, LOW); // Turn off all LEDs
    }

    delay(100); // Small delay before restarting the patterns
}
