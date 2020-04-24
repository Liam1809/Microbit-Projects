
/*
 * File : main.cpp
 * Author:Lam Ha
 * Date: 10-04-2020
 * Desc: the program receives radio values signals from Sending microbit 
 * then changes the signals into morse code, then form morse code into Alphabet and numeric characters
 */
#include "MicroBit.h"
#include "headermorse.h"

MicroBit uBit;
// declare copy-assignable, immutable strings
ManagedString buffer;
ManagedString output;
// set up flag
bool pressed = false;

// used to receive and decode morsecode
void onData(MicroBitEvent e) {

// declare s as a placeholder to receive radio value from Sender
ManagedString s = uBit.radio.datagram.recv();
 
         if (s == "3")
                 pressed = true;

         // Radio value "1" for DOT (0ms- 280ms)
         else if (s == "1") {
                 uBit.display.print("."); // display dot
                 uBit.sleep(500);
                 buffer = buffer + "."; // add a '.' character to buffer
                 uBit.display.clear();
               }

         // Radio value "2" for DASH (280- 800ms)
         else if (s == "2"){
                 uBit.display.print("-"); // display dash
                 uBit.sleep(500);
                 buffer = buffer + "-"; // add a '-' character to buffer
                 uBit.display.clear();
               }
        
        // if flag "pressed" equals to true
        if(pressed){
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
               pressed = false;// assign flag back to false
         }                    
}

// used to display the message
void onButtonA(MicroBitEvent e) {
             uBit.display.scroll(output); // display 
             uBit.sleep(500);
             buffer = ""; // reset buffer
             output = ""; // reset output
             uBit.reset(); // reset
         } 

int main() {
    // initializes uBit and calls functions
    uBit.init();
    uBit.radio.enable();
    uBit.display.scroll("RECEIVER",120);
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, onButtonA);
    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);
    
    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();

}
