/*
    Name: Lesson-4

    Description:    Interface with the neopixel rgb leds.   

    Author: Brian Stouchko
    
    Date: 9/22/17

    Notes:  
  
*/

// Include a seperate library.  This is a bunch of functions someone else already did so we don't
// have to reinvent the wheel.
#include "Adafruit_CPlay_NeoPixel.h"

#define DATA_IN_PIN     17
#define NUMBER_OF_LEDS  10
#define RIGHT_BUTTON    19
 
Adafruit_CPlay_NeoPixel strip = Adafruit_CPlay_NeoPixel(NUMBER_OF_LEDS, DATA_IN_PIN, NEO_GRB + NEO_KHZ800);



/**
 *  The setup function runs first, one time only.
 *  This is where you put your initialization code.
 *  
 *  
 */
void setup() {

    strip.begin();  // Initialize the library.
    pinMode(RIGHT_BUTTON, INPUT);
    
}


/**
 * The loop routine runs the main body of code.
 * It runs over and over forever.
 * 
 * Put any code you want to repeat here.
 * 
 */
void loop() {

  if (digitalRead(RIGHT_BUTTON)== 1 ) {
     chase(strip.Color(10, 0, 0)); // Red
     chase(strip.Color(0, 10, 0)); // Green
    chase(strip.Color(0, 0, 10)); // Blue
  }
}

/*
 *   Walk through this and see if you can understand what it does.
 *   Play around with changing some of the values once you think
 *   you know what they do.
 */
static void chase(uint32_t c) {
    for(uint16_t i=0; i<strip.numPixels()+4; i++) {
        strip.setPixelColor(i  , c); // Draw new pixel
        strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
        strip.show();
        delay(35);
    }
}
   
