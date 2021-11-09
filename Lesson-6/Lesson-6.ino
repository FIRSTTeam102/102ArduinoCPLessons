/*
    Name: Lesson-6

    Description:    Using the light sensor to make a beep from the speaker.   

    Author: Brian Stouchko
    
    Date: 9/22/17

    Notes:  'tone()' generates a square wave of the specified frequency (and 50% duty cycle) on a pin. 
            A duration can be specified, otherwise the wave continues until a call to noTone(). 
            The pin can be connected to a piezo buzzer or other speaker to play tones.
            
  
*/

// Include seperate libraries.  This is a bunch of functions someone else already did so we don't
// have to reinvent the wheel.
#include "Adafruit_CPlay_Speaker.h"

#define LIGHTSENSOR_PIN A5
#define BUZZER_PIN 5
 
Adafruit_CPlay_Speaker speaker;

float lightLevel =100;

/**
 *  The setup function runs first, one time only.
 *  This is where you put your initialization code.
 *  
 *  
 */
void setup() {
    pinMode(BUZZER_PIN, OUTPUT);

}


/**
 * The loop routine runs the main body of code.
 * It runs over and over forever.
 * 
 * Put any code you want to repeat here.
 * 
 */
void loop() {
    lightLevel =analogRead(LIGHTSENSOR_PIN);

    // The max value from the analogRead is 1023.
    if( lightLevel < 10 ){  // only a little bit of light.
        tone(BUZZER_PIN, 400);
    }
    else{
        noTone(BUZZER_PIN);
    }


}



