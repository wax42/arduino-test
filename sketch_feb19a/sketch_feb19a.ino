//We always have to include the library
#include "LedControlMS.h"
/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
#define NBR_MTX 2 
LedControl lc= LedControl(50,51,52, NBR_MTX);

String digits= "1234567890";


int digitCounter=0;
/* we always wait a bit between updates of the display */
unsigned long delaytime=300;

void display_message(char *message) {
  lc.writeString(0, message);   // sending characters to display
}

void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
  Serial.begin (9600);
  Serial.println("Setup");
  digitCounter=0;
  for (int i=0; i< NBR_MTX; i++){
    lc.shutdown(i,false);
  /* Set the brightness to a medium values */
    lc.setIntensity(i,8);
  /* and clear the display */
    lc.clearDisplay(i);x
  }

}


void loop() { 
  //clear all

}
