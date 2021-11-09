/*
    Name: Lesson-4

    Description:    Interface with the neopixel rgb leds.  Make them change color depending on the temperature.   

    Author: Brian Stouchko
    
    Date: 9/22/17

    Notes:  

    The fixed resistor is 10K and the variable resistor is called R - the voltage output (Vo) is:
    Vo = R / (R + 10K) * Vcc
    Where Vcc is the power supply voltage (5V)
    ADC value = Vi * 1023 / Varef (Varef is tied to 5v)
    So now we combine the two (Vo = Vi) and get:
    ADC value = R / (R + 10K) * Vcc * 1023 / Varef
    What is nice is that if you notice, if Vcc (logic voltage) is the same as the ARef, analog reference voltage, the values cancel out!
    ADC value = R / (R + 10K) * 1023
    It doesn't matter what voltage you're running under. Handy!
    Finally, what we really want to do is get that R (the unknown resistance). So we do a little math to move the R to one side:
    R = 10K*ADC / (1023 - ADC). 

    To smooth out the signal we will do the above and take a number of samples,
    averaging them when done.

    When we have our thermistor reading we need to convert the value to temperature.
    One formula is the steinhart algorithm:

    1/T = 1/T0 + 1/B ln(R/R0).

    T0 is room temperature or 25Deg C.
    B is the coefficent of the thermistor or 3950.
    R0 is resistance at room temperature or 10,000.
    
    Plug in the thermistor resistance read and we should get T, the temperature
    in Kelvin.  From there we can convert to C, and then F.
    
    (((temp_in_c * 9) / 5) + 32)
    
    Depending on the value
    of the temperature we can light up the leds.    
  
*/

#include "Adafruit_CPlay_NeoPixel.h"

#define DATA_IN_PIN     17
#define NUMBER_OF_LEDS  10
 
Adafruit_CPlay_NeoPixel strip = Adafruit_CPlay_NeoPixel(NUMBER_OF_LEDS, DATA_IN_PIN, NEO_GRB + NEO_KHZ800);

// which analog pin to connect
#define TEMPERATURE_ANALOG_IN_PIN A0         
// resistance at 25 degrees C
#define THERMISTORNOMINAL 10000      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25   
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 5
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3380
// the value of the 'other' resistor
#define FIXED_RESISTOR 10000


/**
 *  The setup function runs first, one time only.
 *  This is where you put your initialization code.
 *  
 *  
 */
void setup() {
    Serial.begin(9600);
    strip.begin();
}


/**
 * The loop routine runs the main body of code.
 * It runs over and over forever.
 * 
 * Put any code you want to repeat here.
 * 
 */
void loop() {
    float sample =0;
  
    sample = analogRead(TEMPERATURE_ANALOG_IN_PIN);
    sample = ((1023.0 * FIXED_RESISTOR) / sample);
    sample -= FIXED_RESISTOR;

    Serial.print("Thermistor resistance: "); 
    Serial.println(sample);
    
    // Convert the resistance value to a temperature.
    float steinhart;
    steinhart = sample / THERMISTORNOMINAL;     // (R/Ro)
    steinhart = log(steinhart);                  // ln(R/Ro)
    steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
    steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
    steinhart = 1.0 / steinhart;                 // Invert
    steinhart -= 273.15;                         // convert to C

    float tempF =steinhart * 1.8 + 32;

    Serial.print("Temperature "); 
    Serial.print(tempF);
    Serial.println(" *F");

    int colorLevel =0;

    // Change the intensity of red...

    // temp range: 60 - 80 deg F.
    colorLevel =map(tempF,60,150,0,255);


    for(uint16_t ledNum=0; ledNum<strip.numPixels(); ledNum++) {
        strip.setPixelColor(ledNum, 0,0,colorLevel); // Draw new pixel (r,g,b)
    }

    strip.show();

    delay(1000);
}



