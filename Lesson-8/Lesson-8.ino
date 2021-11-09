/*
    Name: Lesson-8

    Description:    Capacitive touch sensors !  What are they?   

    Author: Brian Stouchko
    
    Date: 9/22/17

    Notes:  Different metals can respond electrically to touch.  We can use these to act like buttons.
            Our board has metal contacts around the outside that are setup for capacitive touch.

  
*/
#include "CPlay_CapacitiveSensor.h"
#include "Adafruit_CPlay_Speaker.h"



#define CPLAY_CAPSENSE_SHARED 30
#define CAP_THRESHOLD   20
#define DEBOUNCE        250
#define NUM_SAMPLES     5
#define BUZZER_PIN 5


CPlay_CapacitiveSensor cap[8];
Adafruit_CPlay_Speaker speaker;

/**
 *  The setup function runs first, one time only.
 *  This is where you put your initialization code.
 *  
 *  
 */
void setup() {
    pinMode(BUZZER_PIN, OUTPUT);

    pinMode(CPLAY_CAPSENSE_SHARED, OUTPUT);

    cap[0] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 0);
    cap[1] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 1);
    cap[2] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 2);
    cap[3] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 3);
    cap[4] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 6);
    cap[5] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 9);
    cap[6] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 10);
    cap[7] = CPlay_CapacitiveSensor(CPLAY_CAPSENSE_SHARED, 12); 
}


/**
 * The loop routine runs the main body of code.
 * It runs over and over forever.
 * 
 * Put any code you want to repeat here.
 * 
 */
void loop() {

    if(readCapSensor(0)){
        tone(BUZZER_PIN, 100);
    }
    else
    if(readCapSensor(1)){
        tone(BUZZER_PIN, 200);
    }
    else
    if(readCapSensor(2)){
        tone(BUZZER_PIN, 300);
    }
    else
    if(readCapSensor(3)){
        tone(BUZZER_PIN, 400);
    }
    else
    if(readCapSensor(6)){
        tone(BUZZER_PIN, 500);
    }
    else
    if(readCapSensor(9)){
        tone(BUZZER_PIN, 600);
    }
    else
    if(readCapSensor(10)){
        tone(BUZZER_PIN, 700);
    }
    else
    if(readCapSensor(12)){
        tone(BUZZER_PIN, 1000);
    }
    else{
        noTone(BUZZER_PIN);
    }
}

uint16_t readCapSensor(uint8_t pin) {
    
  switch (pin) {
      case 0:
        return (cap[0].capacitiveSensor(NUM_SAMPLES) > CAP_THRESHOLD);
      case 1:
        return (cap[1].capacitiveSensor(NUM_SAMPLES) > CAP_THRESHOLD);
      case 2:
        return (cap[2].capacitiveSensor(NUM_SAMPLES) > CAP_THRESHOLD);
      case 3:
        return (cap[3].capacitiveSensor(NUM_SAMPLES) > CAP_THRESHOLD);
      case 6:
        return (cap[4].capacitiveSensor(NUM_SAMPLES) > CAP_THRESHOLD);
      case 9:
        return (cap[5].capacitiveSensor(NUM_SAMPLES) > CAP_THRESHOLD);
      case 10:
        return (cap[6].capacitiveSensor(NUM_SAMPLES) > CAP_THRESHOLD);
      case 12:
        return (cap[7].capacitiveSensor(NUM_SAMPLES) > CAP_THRESHOLD);
      default:
        return 0;
    }
}






