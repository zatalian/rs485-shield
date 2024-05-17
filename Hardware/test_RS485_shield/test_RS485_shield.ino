#include <FastLED.h>


#define test_knop 0     // plaats een 1 om dit deel te testen
#define test_led 0
#define test_potM 0
#define test_rgb 0

#define knop1 8
#define knop2 9
#define knop3 10

#define red 2
#define yellow 3
#define blue 4

#define potMeter A0

CRGB leds[1];



void setup() 
{
  Serial.begin(9600);

  if (test_knop)
  {
    pinMode(knop1, INPUT);
    pinMode(knop2, INPUT);
    pinMode(knop3, INPUT);
  }
  if (test_led)
  {
    pinMode(red, OUTPUT);
    pinMode(yellow, OUTPUT);
    pinMode(blue, OUTPUT);
  }
  if (test_potM)
  {
    pinMode(potMeter, INPUT);
  }
  if (test_rgb)
  {
    FastLED.addLeds<WS2812B, 5, GRB>(leds, 1);
  }
}

void loop() 
{
  if (test_knop)
  {
    int K1 = digitalRead(knop1);
    int K2 = digitalRead(knop2);
    int K3 = digitalRead(knop3);
    Serial.print("K1: ");
    Serial.println(K1);
    Serial.print("K2: ");
    Serial.println(K2);
    Serial.print("K3: ");
    Serial.println(K3);
    delay(500);
  }
  if (test_led)
  {
    digitalWrite(red, 1);
    digitalWrite(yellow, 1);
    digitalWrite(blue, 1);
    delay(500);
    digitalWrite(red, 0);
    digitalWrite(yellow, 0);
    digitalWrite(blue, 0);
    delay(500);
  }
  if (test_potM)
  {
    int potM = analogRead(potMeter);
    Serial.println(potM);
  }
  if (test_rgb)
  {
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(500);
    leds[0] = CRGB::Red;
    FastLED.show();
    delay(500);
  }
}
