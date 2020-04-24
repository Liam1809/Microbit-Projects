/*
The MIT License (MIT)

Copyright (c) 2016 British Broadcasting Corporation.
This software is provided by Lancaster University by arrangement with the BBC.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
*/

#include "MicroBit.h"
#include <stdlib.h>
#include <time.h>
#include "MicroBitImage.h"
#include "ManagedString.h"

MicroBit uBit;

int main()
{
    srand(time(NULL));
    // Initialise the micro:bit runtime.
    uBit.init();
    // Insert your code here!
    // declare variables
    int num1 = 0, num2 = 0, answer = 0;
    /* check = -1 initialized
       check = 0 to start the game
       check = 1 used for the correct answer
       check = 2 used for the wrong answer
       check = -2 to stop the game
    */
    int check = -1;
    int operation = 0;
    int score = 0;
    int counter = 0;
    int ran_answer = 0;
    int ran_choice = 0;
    // kicking off displaying string and image of arrow 
    uBit.display.scroll("MINI MATH GAME, PRESS A&B TO START", 120);
    MicroBitImage arrow("0,0,0,0,0\n0,255,0,255,0\n255,255,255,255,255\n0,255,0,255,0\n0,0,0,0,0\n");
    uBit.display.print(arrow);
    // creating string using ManagedString , library included from the head
    ManagedString equal("=");
    ManagedString space(" ");
    ManagedString plus("+");
    ManagedString sub("-");
    ManagedString multi("*"); 
    ManagedString division("/"); 
    //While loop
    while(true) {
//----------------------------------------------------------------------------
      if (check == -1){
      // check if whether button AB is pressed
         if (uBit.buttonAB.isPressed()) {
                  uBit.display.scroll("READY IN",120);
                  uBit.sleep(400);
                  // counting down from 3 to start the game using while loop
                  int count = 3;
                  while(count > 0) {
                         uBit.display.print(count);
                         uBit.sleep(400);
                         count--;
                         }
                   check = 0; // assign check to 0 to start the game 
                 }
         }
//-----------------------------------------------------------------------------
      if(check == 0){
           // random choice from 1 to 4 then assign to operation
           operation = rand() % 4 + 1;
//------------------------------------------------------------------------------
           // operation equals to 1, the game will do the addition
           if (operation == 1){
                   ran_answer = rand() % 9 + 1; // random from 1 - 9 to decide the output answer tricky or not
                   num1 = rand() % 7 + 1; // num1 randomly from 1 - 7
                   num2 = rand() % (9 - num1) + 1; // num2 randomly from 9 - num1 + 1
                   answer = num1 + num2;
                   uBit.sleep(400);

                  if (ran_answer % 2 == 0) // this will show correct output answer
                         check = 1;
       
                  else { // this will not show correct output answer
                         check = 2;
                         // the answer is made to be wrong to test  player
                         answer -= rand() % answer -1 ; 
                         }
            // create strings and display strings and answer
                  ManagedString number1(num1);
                  ManagedString number2(num2);  
                  ManagedString s = number1 + space + plus + space + number2 + space + equal + space;
                  uBit.display.scroll(s);
                  uBit.sleep(100);
                  uBit.display.print(answer);
                  uBit.sleep(100);
                 }
 //------------------------------------------------------------------------------                
           // operation equals to 2, the game will do the subtraction
           if (operation == 2) {
                  ran_answer = rand() % 9 + 1;// random from 1 - 9 to decide the output answer tricky or not
                  num1 = rand() % 6 + 2; // num1 randomly from 2 - 7
                  num2 = rand() % (num1 - 1); // num2 randomly from  num1 - 1
                  answer = num1 - num2;
                  uBit.sleep(400);

                  if(ran_answer %2 == 0) // this will show correct output answer
                         check = 1;
                  else {// this will not show correct output answer
                         check = 2;
                         // the answer is made to be wrong to test  player 
                         answer += rand() % answer - 1;
                         }
                  // create strings and display strings and answer
                   ManagedString number1(num1);
                   ManagedString number2(num2);  
                   ManagedString s = number1 + space + sub + space + number2 + space + equal + space;
                   uBit.display.scroll(s);
                   uBit.sleep(100);
                   uBit.display.print(answer);
                   uBit.sleep(100);
                 }
  //----------------------------------------------------------------------------    
           // operation equals to 3, the game will do the multiplication
           if (operation == 3) {
                   // random from 1 - 9 corresponding to case 1 to case 9
                  ran_choice = rand() % 9 + 1;
                  // using switch case 
                  switch(ran_choice) {
                          case 1 :
                                 num1 = 2;
                                 num2 = 3;
                                 answer = 6;
                                 break;
                          case 2 :
                                 num1 = 1;
                                 num2 = 9;
                                 answer = 9;
                                 break;
                          case 3 :
                                 num1 = 2;
                                 num2 = 2;
                                 answer = 4;
                                 break;
                          case 4 :
                                 num1 = 3;
                                 num2 = 3;
                                 answer = 9;
                                 break;
                          case 5 :
                                 num1 = 4;
                                 num2 = 2;
                                 answer = 8;
                                 break;
                          case 6 :
                                 num1 = 3;
                                 num2 = 2;
                                 answer = 6;
                                 break;
                          case 7 :
                                 num1 = 2;
                                 num2 = 1;
                                 answer = 2;
                                 break;
                          case 8 :
                                 num1 = 6;
                                 num2 = 1;
                                 answer = 6;
                                 break;
                          case 9 :
                                 num1 = 8;
                                 num2 = 1;
                                 answer = 8;
                                 break;
                          default:
                                 uBit.display.scroll("No operation");
                                 break;
                         }
                  ran_answer = rand() % 9 + 1;// random from 1 - 9 to decide the output answer tricky or not

                  if(ran_answer %2 == 0) // this will show correct output answer
                         check = 1;
                  else {// this will not show correct output answer
                         check = 2;
                         // the answer is made to be wrong to test player 
                         answer -= rand()% answer;
                         }
                  // create strings and display strings and answer
                  ManagedString number1(num1);
                  ManagedString number2(num2);
                  ManagedString s = number1 + space + multi + space + number2 + space + equal + space;
                  uBit.display.scroll(s); 
                  uBit.sleep(100);
                  uBit.display.print(answer);   
                  uBit.sleep(100);                         
                 }
//------------------------------------------------------------------------
           // operation equals to 4, the game will do the division
           if (operation == 4) {
                   // random from 1 - 9 corresponding to case 1 to case 9
                   ran_choice = rand() % 9 + 1;
                   // using switch case 
                   switch(ran_choice) {
                           case 1 :
                                 num1 = 6;
                                 num2 = 3;
                                 answer = 2;
                                 break;
                           case 2 :
                                 num1 = 9;
                                 num2 = 1;
                                 answer = 9;
                                 break;
                           case 3 :
                                 num1 = 7;
                                 num2 = 1;
                                 answer = 7;
                                 break;
                           case 4 :
                                 num1 = 3;
                                 num2 = 1;
                                 answer = 3;
                                 break;
                           case 5 :
                                 num1 = 4;
                                 num2 = 2;
                                 answer = 2;
                                 break;
                           case 6 :
                                 num1 = 6;
                                 num2 = 2;
                                 answer = 3;
                                 break;
                           case 7 :
                                 num1 = 2;
                                 num2 = 1;
                                 answer = 2;
                                 break;
                           case 8 :
                                 num1 = 6;
                                 num2 = 1;
                                 answer = 6;
                                 break;
                           case 9 :
                                 num1 = 8;
                                 num2 = 4;
                                 answer = 2;
                                 break;
                           default:
                                 uBit.display.scroll("No operation");
                                 break;
                         }
                  ran_answer = rand() % 9 + 1;// random from 1 - 10 to decide the output answer tricky or not
 
                if (ran_answer %2 == 0) // this will show correct output answer
                          check = 1;
                  else { // this will not show correct output answer
                         check = 2;
                         // the answer is made to be wrong to test player
                         answer -=rand() % answer;
                         }
                  // create strings and display strings and answer
                  ManagedString number1(num1);
                  ManagedString number2(num2);  
                  ManagedString s = number1 + space + division + space + number2 + space + equal + space; 
                  uBit.display.scroll(s);
                  uBit.sleep(100);
                  uBit.display.print(answer); 
                  uBit.sleep(100);       
                 }
         }
//----------------------------------------------------------------------------
         // if check > 0
         if (check > 0) {
              // if button A is pressed then
              if (uBit.buttonA.isPressed()) {
                  counter ++; // counter count up by 1
                  // if check = 1 and button A is pressed that means player answer it correct
                  if (check == 1) {
                          score ++; // score count up by 1
                          // display tick image
                          MicroBitImage tick("0,0,0,0,0\n0,0,0,0,255\n0,0,0,255,0\n255,0,255,0,0\n0,255,0,0,0\n");
                          uBit.display.print(tick);
                         }
                  // if not that means player answer it wrong
                  else {
                          //display cross image
                         MicroBitImage cross("255,0,0,0,255\n0,255,0,255,0\n0,0,255,0,0\n0,255,0,255,0\n255,0,0,0,255\n");
                         uBit.display.print(cross); 
                         uBit.sleep(800);             
                         }
                  check = 0;
                 }
              // if button B is pressed then
              if (uBit.buttonB.isPressed()) {
                  counter ++; //counter count up by 1 
                  // if check = 1 and button B is pressed that means player answer it wrong
                  if (check == 1) {                       
                          //display cross image
                          MicroBitImage cross("255,0,0,0,255\n0,255,0,255,0\n0,0,255,0,0\n0,255,0,255,0\n255,0,0,0,255\n");
                          uBit.display.print(cross); 
                         }
                  // if not that means player answer it correct
                  else {
                         score ++; // score count up by 1
                         //display tick image
                         MicroBitImage tick("0,0,0,0,0\n0,0,0,0,255\n0,0,0,255,0\n255,0,255,0,0\n0,255,0,0,0\n");
                         uBit.display.print(tick); 
                         uBit.sleep(800);     
                         }
                  check = 0;
                 }
         }
//------------------------------------------------------------------------------
         // check if the game repeats 10 times
         if (counter == 10) {
                  check = -2; // to stop the game when it reaches 10 times operation
                  uBit.sleep(1000);
                  // score is greater or equal to 5, player won
                  if (score >= 5) {
                   uBit.display.scroll("YOU WON",120);
                   uBit.display.scroll(score);
                   uBit.display.scroll("/10",70);
                   uBit.sleep(800);
                    // display smile face
                    MicroBitImage smiley("0,0,0,0,0\n0,255,0,255,0\n0,0,0,0,0\n255,0,0,0,255\n0,255,255,255,0\n");
                    uBit.display.print(smiley);
                 }
                  // if not, player lose
                 else {
                   uBit.display.scroll("YOU LOSE",100);
                   uBit.display.scroll(score);
                   uBit.display.scroll("/10",70);
                   uBit.sleep(800);
                   // display sad face
                   MicroBitImage sadley("0,0,0,0,0\n0,255,0,255,0\n0,0,0,0,0\n0,255,255,255,0\n255,0,0,0,255\n");
                   uBit.display.print(sadley);  
                 }
                 // reset counter and score
                 counter = 0;
                 score = 0;      
         }
    
    }
    // If main exits, there may still be other fibers running or registered event handlers etc.
    // Simply release this fiber, which will mean we enter the scheduler. Worse case, we then
    // sit in the idle task forever, in a power efficient sleep.
    release_fiber();


}