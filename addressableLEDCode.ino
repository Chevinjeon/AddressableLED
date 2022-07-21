
#include <FastLED.h>
#define LED_PIN 2
#define NUM_LEDS 60

CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
    FastLED.clear();
    FastLED.show();
    //Serial.begin(9600);
}

/*
void flashing_changing_color() {
  for (int i=0; i<NUM_LEDS; i++){
    // Teal color
    leds[i] = CRGB(0, 200, 255);
  }
    
  //FastLED.setBrightness(i);
  //delay(1);
  //FastLED.show();
  
  
   //delay(4000);
  //for (int i=128; i>0; i--) {
  //  FastLED.setBrightness(i);
  //delay(1);
 // FastLED.show();
 // }
  // delay(4000);
//FastLED.clear();
}
*/

void loop() {
//    flashing_changing_color();    

  // Turn lights from green to blue from left to right R G B
  for (int i=0; i<NUM_LEDS; i++) {
    leds[i] = CRGB(0,255-4*i, 4*i);
    //for (int i=0; i<NUM_LEDS; i++){
    // Real color
    //leds[i] = CRGB(0, 200, 255);
    FastLED.setBrightness(2*i);
    //FastLED.setBrightness(i);
 
    FastLED.show();
    delay(50);
  }
  
  // Turn lights from blue to magenta from right to left
  for (int i=NUM_LEDS; i>0; i--){
    //for (int i=128; i>0; i--) {
    leds[i] =  CRGB(4*i,0,255-4*i);
    FastLED.setBrightness(100-i);
    FastLED.show();
    delay(50);
  }

  
}
