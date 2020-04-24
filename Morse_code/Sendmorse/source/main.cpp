/*
 * File: main.cpp
 * Author: Lam Ha
 * Date: 24-02-2020
 * Desc: Gets input and finds whether it is a dot or a dash and sends the corresponding signal from PIN 1 to receiving MicroBit
 */
#include "MicroBit.h"

MicroBit uBit;

//button A and button B are utilised on the sending microbit 
/*button A is used to create create dot/dash ./-
   button B is used to check that button A can only be pressed no more than 5 times
*/
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);
//Constructor,create a MicroBitPin instance, generally used to represent P1 on the edge connector
MicroBitPin P1(MICROBIT_ID_IO_P1,MICROBIT_PIN_P1, PIN_CAPABILITY_ALL);

int main(){
// Initialise the micro:bit runtime.
uBit.init();
// Set up flag for while loop
bool pressed = false;
// Initialize counter to check how many times dash/dot appear
int count = 0;

uBit.display.scroll("SENDER",120);

// Infinite While Loop
while(1){

  // read current number of milliseconds 
  uint64_t reading = system_timer_current_time();

  // loop while button A pressed, Send signal to another microbit when button A is pressed
  while(buttonA.isPressed()) {
       pressed = true; // assign "pressed" to true if button A is pressed
       P1.setDigitalValue(1);// P1 is now HI 
       }

  // time of loop execution
  uint64_t diff = system_timer_current_time() - reading;

  // if flag "pressed" equals to true
  if(pressed) {

     // Time difference for DOT (0ms- 280ms)
     if(diff > 0 && diff < 280){
            uBit.display.print(".");
            count ++;// count by 1
            P1.setDigitalValue(0);// P1 is now LO
            uBit.sleep(500);
            uBit.display.clear();

            // if count is greater than 5, which means NOT MORSE CODE
            if (count > 5) {
                   count = 0;// assign count back to 0
                   uBit.display.scroll("???",120);
                   uBit.sleep(400);
                   uBit.reset();// reset 
                   }
             }
             
     // Time difference for DASH (280- 800ms)
     else if(diff > 280 && diff < 800) {
            uBit.display.print("-");
           count ++;// count by 1
            P1.setDigitalValue(0);// P1 is now LO
            uBit.sleep(500);
            uBit.display.clear();

            // if count is greater than 5, which means NOT MORSE CODE
            if (count > 5) {
                   count = 0;// assign count back to 0
                   uBit.display.scroll("???",120);
                   uBit.sleep(400);
                   uBit.reset();// reset 
                   }
            }

     // Time difference greater than 900ms, NOISE
     else if (diff > 900) {
            uBit.display.scroll("???",120);
            P1.setDigitalValue(0);// P1 is now LO
            uBit.sleep(500);
            uBit.reset();// reset 
           }
     pressed = false;// assign flag back to false
     uBit.display.clear();
     
     }
     // Button B is pressed to confirm you finish your morse code input
     if(buttonB.isPressed()) {
             count =0;
              // display tick image
              MicroBitImage tick("0,0,0,0,0\n0,0,0,0,255\n0,0,0,255,0\n255,0,255,0,0\n0,255,0,0,0\n");
              uBit.display.scroll(tick);
          }  
          
   }
    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}
