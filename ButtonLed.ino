/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int prevButtonState = 0;
int blinkState = 1;
unsigned long elapsedTime;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  elapsedTime = millis();
}

void loop() {

  buttonState = digitalRead(buttonPin);
  if (prevButtonState == 1 && buttonState == 0)
  {
    switch (blinkState){
      case 1:
        blinkState = 2;
        break;
      case 2:
        blinkState = 4;
        break;
      case 4:
        blinkState = 8;
        break;
      case 8:
        blinkState = 1;
        break;
      default:
        break;
    }
  }
  prevButtonState = buttonState;

  
  
  switch (blinkState){
    case 1:
      if (millis() - elapsedTime >= 1000)
        {
          digitalWrite(ledPin, HIGH);
          elapsedTime = millis();
        }
      break;
    case 2:
      if (millis() - elapsedTime >= 1000/2)
        {
          digitalWrite(ledPin, HIGH);
          elapsedTime = millis();
        }
      break;
    case 4:
      if (millis() - elapsedTime >= 1000/4)
        {
          digitalWrite(ledPin, HIGH);
          elapsedTime = millis();
        }
      break;
    case 8:
      if (millis() - elapsedTime >= 1000/8)
        {
          digitalWrite(ledPin, HIGH);
          elapsedTime = millis();
        }
      break;
    default:
      break;
  }

  if (digitalRead(ledPin) == HIGH && millis() - elapsedTime >= 50)
    {
      digitalWrite(ledPin, LOW);
    }
  
}
  
