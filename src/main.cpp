#include <Arduino.h>


#include "LedControlMS.h"

/*
Configuring the LEDMatrix:
Digital 2 is conneted to DIN (Data IN)
Digital 3 is connected to CLK (CLocK)
Digital 4 is connected to CS (LOAD)
5V is connected to VCC
GND is connected to GND
There is only one MAX7219 display module.
*/


// create Snake instance
// parameters: ledControl (required), digitsCount = 4, delay = 400 ms



// initalizes and sets up the initial values. 

#define NBR_MTX 64
LedControl lc=LedControl(12,10,11, NBR_MTX);
//LedControl lc=LedControl(10,11,12, NBR_MTX);


String sentence= "WEED ";
int letterCounter=0;
/* wait time between updates of the display */
unsigned long delaytime=300;
// fonction to debug the arduino
void bink_test() {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);                       // wait for a second
}


// function to test the led ofe MAX7219 display module.
void test_led() {
    //switch on the led in the 3'rd row 8'th column of the device at addr=0 
//     lc.setLed(0,0,1,true);
//     lc.setLed(0,1,1,true);
//        
//   lc.setLed(0,2,7,true); 
//
//  
//        lc.setLed(0,2,4,true); 
  
//      lc.setLed(0,2,1,true); 
    for (int x=0; x< NBR_MTX; x++){
       for (int y=0; y< NBR_MTX; y++){
        lc.setLed(0, x,y,true);
//        delay(500);
       }
    } 
//    //now the Led at row 0, second from the left side
//    lc.setLed(0,0,1,true); 
//    delay(500); 
//    //switch the first Led off (second one stays on) 
//    lc.setLed(0,2,7,false); 
}

void printCharbyChar() { // =  lc.writeString(0, "WEED");
   char ch= sentence[letterCounter]; //define character ch
  letterCounter++;
  if (letterCounter>14) letterCounter=0; //sets up loop
  lc.displayChar(0, lc.getCharArrayPosition(ch)); //display each character on the screen
//  delay(200000);
//  lc.clearAll();
}
 
void setup() { // Declaring function setup
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);


  
  /* The display module is in power-saving mode on startup.
  Do a wakeup call */
  Serial.begin(9600); // setting data rate as 9600 bits per second for serial data communication to computer
  Serial.println("Setup"); //prints data to serial port as human-readable text
 
  letterCounter=0;
  for (int i=0; i< NBR_MTX; i++){
    lc.shutdown(i,false); //keep the screen on
    lc.setIntensity(i,8); // set brightness to medium values
    lc.clearDisplay(i); //clear the display after each letter
  }

;

}

void loop() { //declaring function loop
//
//  test_led();
//  lc.writeString(0, "WEED");
  printCharbyChar();
  delay(500);

//  test_led();
//  lc.clearAll();
      // move sna

}
