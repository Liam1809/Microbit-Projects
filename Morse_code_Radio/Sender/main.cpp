/*
 * File: main.cpp
 * Author: Lam Ha
 * Date: 10-04-2020
 * Desc: Gets input and finds whether it is a dot or a dash and sends those to receiving MicroBit using radio frequency
 */
#include "MicroBit.h"

MicroBit uBit;

//button A and button B are utilised on the sending microbit 
/*button A is used to create create dot/dash ./- and send radio values to receiver
   button B is used to send radio value to confirm and decode Morsecode
*/
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);

int main(){
// Initialise the micro:bit runtime.
uBit.init();
uBit.radio.enable();
// Set up flag for while loop
bool pressed = false;
// Set up a counter
int count = 0;

uBit.display.scroll("SENDER",120);


// Infinite While Loop
while(1){

  // read current number of milliseconds 
  uint64_t reading = system_timer_current_time();

  // loop while button A pressed, Send signal to another microbit when button A is pressed
  while(buttonA.isPressed()) {
       pressed = true; // assign "pressed" to true if button A is pressed
       }

  // time of loop execution
  uint64_t diff = system_timer_current_time() - reading;

  // if flag "pressed" equals to true
  if(pressed) {

     // Time difference for DOT (0ms- 280ms)
     if(diff > 0 && diff < 280){
            uBit.display.print(".");
            count += 1; // count by 1
            uBit.radio.datagram.send("1"); // send "1" to Receiver via radio frequency
            uBit.sleep(500);
            uBit.display.clear();
             }
             
     // Time difference for DASH (280- 800ms)
     else if(diff > 280 && diff < 800) {
            uBit.display.print("-");
            count += 1; // count by 1
            uBit.radio.datagram.send("2"); // send "2" to Receiver via radio frequency
            uBit.sleep(500);
            uBit.display.clear();
            }

     // Time difference greater than 900ms, NOISE
     else if (diff > 900) {
            uBit.display.scroll("???",120);
            uBit.sleep(500);
            uBit.reset();// reset 
           }

     pressed = false;// assign flag back to false
     uBit.display.clear();
     }

     // No Morsecode pattern exceeds 5 characters
     if (count > 5) {
            uBit.display.scroll("???",120);
            uBit.sleep(500);
            uBit.reset();// reset 
     }

     // Button B is pressed to confirm you finish your morse code input
     if(buttonB.isPressed()) {
             count = 0; // reset counter
             uBit.radio.datagram.send("3");// send "3" to Receiver via radio frequency
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

