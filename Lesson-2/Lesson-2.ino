/*
    Name: Lesson-2

    Description:    Turns on the led when the user clicks the button.  If the user moves the slide switch t0 the '-' 
                    position, it will prevent the button from doing anything.   

    Author: Brian Stouchko
    
    Date: 9/22/17

    Notes:  
  
*/

#define LED_PIN         13
#define LEFT_BUTTON     4
#define RIGHT_BUTTON    19
#define SLIDE_SWITCH    21




/**
 *  The setup function runs first, one time only.
 *  This is where you put your initialization code.
 *  
 *  
 */
void setup() {
    pinMode(LED_PIN, OUTPUT); // We are again setting up pin 13, aka LED_PIN as an output.

    pinMode(LEFT_BUTTON, INPUT); 
    pinMode(RIGHT_BUTTON, INPUT); 
    pinMode(SLIDE_SWITCH, INPUT); 
    
    
}


/**
 * The loop routine runs the main body of code.
 * It runs over and over forever.
 * 
 * Put any code you want to repeat here.
 * 
 */
void loop() {

    if(digitalRead( SLIDE_SWITCH )==1  ){

        if( digitalRead (LEFT_BUTTON)==1 ){
          digitalWrite(LED_PIN,HIGH);
        }
        if(digitalRead (RIGHT_BUTTON)==1 ){
            digitalWrite(LED_PIN,LOW);            
        }
    }
}








/*  Here's the functions you need.  They are not in order of any kind.  You will need them all.

delay(time-in-milliseconds);  hint - 1000 milliseconds is = 1 second.   1 millisecond is .001 seconds.
digitalWrite(what pin?, what level); 
pinMode(what pin, do you want to set it, or read it?);
myReadValue =digitalRead( what pin are we reading? )  hint - the pin we read must be set as INPUT with pinMode.  Do the pinMode in the init only.



*/
