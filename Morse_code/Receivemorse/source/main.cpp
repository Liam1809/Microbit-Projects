/*
 * File : main.cpp
 * Author:Lam Ha
 * Date: 24-02-2020
 * Desc: the program receives signals from P1 from Sending microbit 
 * then changes the signals into morse code, then form morse code into Alphabet and numeric characters
 */
#include "MicroBit.h"
#include "headermorse.h"

MicroBit uBit;

//button A and button B are utilised on the receiving microbit 
/* button A is used to store the morse codes in a string then decrypt those
   button B is used to display a string that contains all the decrypted characters
*/
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);
MicroBitButton buttonB(MICROBIT_PIN_BUTTON_B, MICROBIT_ID_BUTTON_B);
//Constructor,create a MicroBitPin instance, generally used to represent P1 on the edge connector
MicroBitPin P1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1,PIN_CAPABILITY_ALL);

int main(){
// Initialise the micro:bit runtime.
uBit.init();
// declare copy-assignable, immutable strings
ManagedString buffer;// to store a combination of dots and dashes
ManagedString output;// to store a sequence of decrypted letters

// Set up flag for while loop
bool pressed = false;
bool pressed1 = false;

uBit.display.scroll("RECEIVER",120);
// Infinite While Loop
while(1) {

   // read current number of milliseconds
   uint64_t reading = system_timer_current_time();

   /* Whenever Sender microbit button A is pressed, P1 has a value of 1(HI)
    then transmit signals via P1 wires to Reciver microbit which also has the same P1(1),
     beneath line is the while loop with condition of P1.getDigitalValue() == 1
    */
   while(P1.getDigitalValue() == 1){
         pressed = true;//assign "pressed" to true if microbit receive P1(1)
       }

   // time of loop execution
   uint64_t diff = system_timer_current_time() - reading;

   // if flag "pressed" equals to true
   if (pressed){
         // Time difference for DOT (0ms- 280ms)
         if (diff > 0 && diff < 280) {
                 uBit.display.print("."); // display dot
                 uBit.sleep(500);
                 buffer = buffer + "."; // add a '.' character to buffer
                 uBit.display.clear();
               }
         // Time difference for DASH (280- 800ms)
         else if (diff > 280 && diff < 800){
                 uBit.display.print("-"); // display dash
                 uBit.sleep(500);
                 buffer = buffer + "-"; // add a '-' character to buffer
                 uBit.display.clear();
               }
         pressed = false; // assign flag back to false
       }

   //loop while button A pressed in order to save each character to output one by one
   while(buttonA.isPressed()){
      pressed1= true;// assign "pressed1" to true if button A is pressed
       }

   // if flag "pressed" equals to true
   if(pressed1){
          // display tick image
          MicroBitImage tick("0,0,0,0,0\n0,0,0,0,255\n0,0,0,255,0\n255,0,255,0,0\n0,255,0,0,0\n");
          uBit.display.scroll(tick);
          // initialise for loop from 0 to 35 in order to decrypt morse code
          for (int i = 0 ; i < 36; i ++) {
                 if (buffer == MorseCharacter[i])//if buffer equals to MorseCharacter at index i
                        output = output + Character[i];// then add Character at index i to output
               }
          // initialise for loop from 0 to 22 to replace undefined dotdash characters into "~"
          for (int i = 0 ; i < 22; i ++) {
                 if (buffer == Undefined[i])// if buffer equals to Undefined at index i
                        output = output + "~";// then add "~" to output
               } 

          buffer = ""; // reset buffer
          pressed1 = false;// assign flag back to false
     
        }
     // Press button B to display the decrypted characters
    if(buttonB.isPressed()) {
             uBit.display.scroll(output); // display 
             uBit.sleep(500);
             buffer = ""; // reset buffer
             output = ""; // reset output
             uBit.reset(); // reset
         }
   }
    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();
}
