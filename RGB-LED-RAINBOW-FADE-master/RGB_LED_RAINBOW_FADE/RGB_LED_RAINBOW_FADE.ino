/**
  RGB LED RAINBOW FADE FOR ARDUINO
  2018.8.15
  Author: Trey Gilliland
  Version: 1.0
  Components:
    (1x Arduino Uno or similar compatible board)
    (4x Male-Male Jumper Wire)
    (1x RGB LED)
    (3x 220 ohm resistors)

    Pins defined below, be sure to plug jumpers into correct pin slots on UNO
    Colors based on RGB rainbow chart
**/

// Define Pins
#define BLUE 3 //Blue Wire in 3~ slot
#define GREEN 5 //Green Wire in 5~ slot
#define RED 6 //Red Wire in 6~ slot

void setup()
{
  //setup LEDs for output
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  //Turn red on, low voltage for blue and green
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

// define color RBG value variables and time between color changes (ms)
int redValue;
int greenValue;
int blueValue;
int delayTime;

// main loop
void loop()
{
  delayTime = 20; // fading time between colors

  redValue = 255; //Starting color values
  greenValue = 0;
  blueValue = 0;

  analogWrite(RED, redValue);
  analogWrite(BLUE, blueValue);
  analogWrite(GREEN, greenValue);

  for (int i = 0; i < 127; i += 1) // Fade to orange (255,127,0)
  {
    greenValue += 1;
    analogWrite(GREEN, greenValue);
    delay(delayTime);
  }

  redValue = 255;
  greenValue = 127;
  blueValue = 0;
  delayTime = 20;

  for (int i = 0; i < 127; i += 1) // Fade to yellow (255,255,0)
  {
    greenValue += 1;
    analogWrite(GREEN, greenValue);
    delay(delayTime);
  }

  redValue = 255;
  greenValue = 255;
  blueValue = 0;
  delayTime = 10;

  for (int i = 0; i < 255; i += 1) // Fade to green (0,255,0)
  {
    redValue -= 1;
    analogWrite(RED, redValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for (int i = 0; i < 255; i += 1) // Fade to blue (0,0,255)
  {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 0;
  blueValue = 255;
  delayTime = 16;

  for (int i = 0; i < 155; i += 1) // Fade to indigo (75,0,150)
  {
    if (i % 2 == 0 && redValue < 75) {
      redValue += 1;
      analogWrite(RED, redValue);
    }
    blueValue -= 1;
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

  redValue = 75;
  greenValue = 0;
  blueValue = 150;
  delayTime = 24;

  for (int i = 0; i < 105; i += 1) // Fade to violet (150,0,255)
  {
    if (redValue < 150) {
      redValue += 1;
      analogWrite(RED, redValue);
    }
    blueValue += 1;
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

  redValue = 150;
  greenValue = 0;
  blueValue = 255;
  delayTime = 10;

  for (int i = 0; i < 255; i += 1) // Fade to red (255,0,0)
  {
    if (i % 2 == 0 && redValue < 255) {
      redValue += 1;
      analogWrite(RED, redValue);
    }
    blueValue -= 1;
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }

}

