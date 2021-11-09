/*
    Name: Lesson-1

    Description:    First in a series of lessons to help understand embedded programming.
                    This example will simply blink the onboard pin13 led.   

    Author: Brian Stouchko
    
    Date: 9/22/17

    Notes:  
  
*/

/* Look! I'm a comment.  The program simply ignores me! */
/* I am defined by using the slash and asteriks to start and then asteriks and slash to end */
// Another way to show comments is the double slash.  This was adopted for use in another language, C++.
//  It has been supported in c.  Both are acceptable. 

// A good practice is to provide comments whenever your code would be difficult to understand by another
// developer.  Comments are good.

// Below is a 'define'.  It is used to substitute the name for the value.  So everywhere in code where 'LED_PIN'
// is typed, the compiler will replace the text with its value, 13.  This is very good form.  It is not good to
// use 'magic numbers'.  Magic numbers are when programmers simply use numbers for things with no explanation.
// i.e.  Bad: someFunction(1,2); Better: someFunction( myAltitude, mySpeed );

// This define simply means that pin 13 of the arduino is connected to the LED.  It has been soldered there already.
#define LED_PIN 13

/**
 *  The setup function runs first, one time only.
 *  This is where you put your initialization code.
 *  
 *  
 */

void setup() {
   pinMode(LED_PIN, OUTPUT);
   // What should go here?  Only one line.  We need to tell the chip what pin is an output.
    
}

/**
 * The loop routine runs the main body of code.
 * It runs over and over forever.
 * 
 * Put any code you want to repeat here.
 * 
 */
void loop() {


digitalWrite(LED_PIN, HIGH);
delay(1000);
digitalWrite(LED_PIN, LOW);
delay(1000);
// What should we do here?

    // Set the pin HIGH.  It will light up the led.
    // Delay for a second.
    // Set the pin LOW. It will turn off.
    // Delay for a second.

    // Once we do the line above, we don't need to do anything else.
    // The loop function knows to back to the beginning of loop and do it all again.
    // So what we need to remember is that all the lines here will repeat over and over until we disconnect power.
}


// Once you are done with your coding, save your work, and press the button above that looks like an arrow to the right.
// That will load your code into the chip.  Once it's done loading (you can watch the progress in the box below), the 
// arduino board will begin to run your code.  If you did it right, you should see the red light next to the usb port
// blinking on and off once a second.























// Here's the functions you need.  They are not in order of any kind.  You will need them all.
/*

delay(1000);
digitalWrite(LED_PIN, HIGH); 
pinMode(LED_PIN, OUTPUT);
digitalWrite(LED_PIN, LOW); 



*/
