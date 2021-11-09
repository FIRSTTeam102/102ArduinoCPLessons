/*
    Name: Lesson-9

    Description:    Left button will change color, right
                    button will start it spinning.   

    Author: Brian Stouchko
    
    Date: 9/22/17

    Notes:  .

  
*/

#include "Adafruit_CPlay_NeoPixel.h"

#define DATA_IN_PIN     17
#define NUMBER_OF_LEDS  10
 
Adafruit_CPlay_NeoPixel strip = Adafruit_CPlay_NeoPixel(NUMBER_OF_LEDS, DATA_IN_PIN, NEO_GRB + NEO_KHZ800);

#define LEFT_BUTTON     4
#define RIGHT_BUTTON    19



bool isSpinning =false;
uint32_t ledColors[8];

int colorIdx =0;

/**
 *  The setup function runs first, one time only.
 *  This is where you put your initialization code.
 *  
 *  
 */
void setup() {

    pinMode(LEFT_BUTTON, INPUT); 
    pinMode(RIGHT_BUTTON, INPUT); 

    ledColors[0]   =0x1639CB;
    ledColors[1]   =0xBDC4DF;
    ledColors[2]   =0xCB46C7;
    ledColors[3]   =0x46CB93;
    ledColors[4]   =0xA61F36;
    ledColors[5]   =0x41E723;
    ledColors[6]   =0xE78523;
    ledColors[7]   =0x232FE7;

    strip.begin();  // Initialize the library.
}


/**
 * The loop routine runs the main body of code.
 * It runs over and over forever.
 * 
 * Put any code you want to repeat here.
 * 
 */
void loop() {
    static int ledNum =0;
    
    if( digitalRead (LEFT_BUTTON)==1 ){
        colorIdx++;
        if(colorIdx>7){
            colorIdx =0;
        }
    }
    
    if(digitalRead (RIGHT_BUTTON)==1 ){
       isSpinning =!isSpinning;            
    }

    if(isSpinning){
        strip.setPixelColor(ledNum, 0);
        ledNum++;
        if(ledNum>NUMBER_OF_LEDS){
            ledNum =0;
        }
        strip.setPixelColor(ledNum, ledColors[colorIdx]);
    }
    else{
        for(ledNum=0; ledNum<NUMBER_OF_LEDS; ledNum++){
            strip.setPixelColor(ledNum, ledColors[colorIdx]);
        }
    }

    strip.show();
    delay(100);
    
}








