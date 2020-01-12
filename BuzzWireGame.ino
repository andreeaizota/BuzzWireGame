/*

*/

const uint8_t pinSpeaker = 11u;
const uint8_t pinCircuit = 9u;
const uint8_t pinSegA = 10u;
const uint8_t pinButton = 12u;
uint8_t count;
uint32_t lastMilis = millis();
uint32_t currentMilis = millis();

void setup() {
    pinMode(pinSpeaker, OUTPUT);
    pinMode(pinCircuit, INPUT);
    pinMode(pinSegA, OUTPUT);
    pinMode(pinButton, INPUT);
    digitalWrite(pinButton, HIGH);
    DDRD = 0b11111111;
    count = 0u;
    Serial.begin(9600);
}

void displayMistakes(uint8_t count)
{
  switch (count)
    {
      case 0:
        PORTD = 0b01111100;
        digitalWrite(pinSegA, 1);
        break;
      case 1:
        PORTD = 0b00001100;
        digitalWrite(pinSegA, 0);
        break;
      case 2:
        PORTD = 0b010110100;
        digitalWrite(pinSegA, 1);
        break;
      case 3:
        PORTD = 0b010011100;
        digitalWrite(pinSegA, 1);
        break;      
      case 4:
        PORTD = 0b011001100;
        digitalWrite(pinSegA, 0);
        break;
      case 5:
        PORTD = 0b011011000;
        digitalWrite(pinSegA, 1);
        break;
      case 6:
        PORTD = 0b011111000;
        digitalWrite(pinSegA, 1);
        break;
      case 7:
        PORTD = 0b00001100;
        digitalWrite(pinSegA, 1);
        break;
      case 8:
        PORTD = 0b11111100;
        digitalWrite(pinSegA, 1);
        break;
      case 9:
        PORTD = 0b11011100;
        digitalWrite(pinSegA, 1);
        break;
      case 10:
        PORTD = 0b11101100;
        digitalWrite(pinSegA, 1);
        break;
      case 11:
        PORTD = 0b11111000;
        digitalWrite(pinSegA, 0);
        break;      
      case 12:
        PORTD = 0b01110000;
        digitalWrite(pinSegA, 1);
        break;
      case 13:
        PORTD = 0b10111100;
        digitalWrite(pinSegA, 0);
        break;
      case 14:
        PORTD = 0b11110000;
        digitalWrite(pinSegA, 1);
        break;
      case 15:
        PORTD = 0b11100000;
        digitalWrite(pinSegA, 1);
        break;
    }
}

void loop() {
    if (HIGH == digitalRead(pinButton))
    {
      count = 0u;
    }
    if (HIGH == digitalRead(pinCircuit))
    { 
      currentMilis = millis();
      if (currentMilis - lastMilis > 200)
      {
        lastMilis = currentMilis;
        count++;
      }
      tone(pinSpeaker, 880, 100);
    }
    if (15u < count)
    {
      count = 0u;
    }
    displayMistakes(count);
}
