/*
    Name: Lesson-3

    Description:    Turns on/off the led when the user taps the board.   

    Author: Brian Stouchko
    
    Date: 9/22/17

    Notes:  Accelerometers are the sensors in your WiiMote, phone, and other electronic devices that can sense tilt, gravity, motion and 'tap' effects.

  
*/

#include "Adafruit_CPlay_LIS3DH.h"
#include <Wire.h>
#include <SPI.h>

#define LED_PIN             13
#define ACCEL_PIN_SELECT    8  // The accelerometer chip uses two pins to control it.
#define ACCEL_PIN           7


// Adjust this number for the sensitivity of the 'click' force
// this strongly depend on the range! for 16G, try 5-10
// for 8G, try 10-20. for 4G try 20-40. for 2G try 40-80
#define CLICKTHRESHHOLD 40

// This is a special library for the accelerometer.
Adafruit_CPlay_LIS3DH lis = Adafruit_CPlay_LIS3DH(ACCEL_PIN_SELECT);

// bool means boolean.  it is either true or false.
volatile bool tapDetected =false;   // New keyword volatile.  It's a very advanced keyword.  They are used when using interrupts.  Read on.
bool toggleState =false;

// ISR = Interrupt Service Routine: the code is stopped and this is called when a special
//        'interrupt' occurs.  It can be from a timer, or a pin going high, or a pin going low, or when something else
//        happens.  
//        THE SECRET WITH ISRS IS THAT THEY MUST !!!!! BE SHORT.
//        Typically, nothing else can interrupt an interrupt.  So everything will wait until we are done.
void tapISR(void) {
    tapDetected =true;  // we defined this as volatile.  The compiler can do some pretty tricky things.  Sometimes it can break how this is used
}                       // if we also read or write the variable in our regular code.  Sometimes the compiler makes two copies of it.  That's not
                        // good.  If we defined it as volatile, it tells the compiler that this is special and may be inside an ISR.

/**
 *  The setup function runs first, one time only.
 *  This is where you put your initialization code.
 *  
 *  
 */
void setup() {

    pinMode(LED_PIN, OUTPUT);
    lis.begin(0x18);  // This does internal setup with the sensor.  0x18 is a magic value that is used to specify how the sensor is to be used.
    
    lis.setRange(LIS3DH_RANGE_2_G);   // 2, 4, 8 or 16 G!  G is G-Force.

    // 0 = turn off click detection & interrupt
    // 1 = single click only interrupt output
    // 2 = double click only interrupt output, detect single click
    // Adjust threshhold, higher numbers are less sensitive
    lis.setClick(2, CLICKTHRESHHOLD);  // A magic function from the library that sets up how sensitive we want the sensor.

    // the actual sensor will send us a signal when it is tapped.  We 'interrupt' what we are doing and perform
    // some task (tapISR).
    attachInterrupt(digitalPinToInterrupt(ACCEL_PIN), tapISR, FALLING);
}


/**
 * The loop routine runs the main body of code.
 * It runs over and over forever.
 * 
 * Put any code you want to repeat here.
 * 
 */
void loop() {
    if(tapDetected){
        noInterrupts();     // We can shut off interrupts so we don't get interrupted.  We do this so tapDetected doesn't get changed while we are
        tapDetected =false; // changing it.  This is a big problem using interrupts.  Very powerful, but also very tricky to manage.
        interrupts(); // turn them back on.  We don't want to miss anything.

        // Here's another trick...
        toggleState =!toggleState;  // It looks odd.  But it means if its true, make it false.  If its false, make it true.
        
        if(toggleState == true){
            digitalWrite(LED_PIN, HIGH);
        }
        else{
            digitalWrite(LED_PIN, LOW);
        }
     }
}





