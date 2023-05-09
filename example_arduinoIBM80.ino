#include <Servo.h>

// Define servo/solenoid and sensor pins
const int servoPins[80] = { ... };
const int sensorPins[80] = { ... };

Servo servos[80];

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 80; i++) {
    servos[i].attach(servoPins[i]);
    pinMode(sensorPins[i], INPUT);
  }
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();

    switch (command) {
      case 'r': // Read punch card
        String cardData = readCard();
        Serial.println(cardData);
        break;
      case 'w': // Write punch card
        String dataToWrite = Serial.readStringUntil('\n');
        writeCard(dataToWrite);
        break;
    }
  }
}

String readCard() {
  String cardData = "";

  // Read hole pattern and convert to ASCII characters
  // ...

  return cardData;
}

void writeCard(String data) {
  // Convert ASCII characters to hole pattern and punch the card
  // ...
}
