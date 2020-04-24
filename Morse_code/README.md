Lam Ha - 19035157
=====================
Introduction
=================
a small microbit programme that can be used to communicate between two microbits via morsecode 

Files
===================

* morse-code/Receivemorse/source/main.cpp - main code for the recieving microbit

* morse-code/Sendmorse/source/main.cpp   - main code for the sending microbit

* headermorse.h  - contains morsetable and characters

* morse-code/Hex file/Receiver/microbit-samples-combined.hex  - compiled code for the recieving microbit

*  morse-code/Hex file/Sender/microbit-samples-combined.hex- compiled code for the sending microbit

Setting up
=================

Setting for Sending microbit:
--------------------------------
1. plug in sending microbit
2. create a folder for sending microbit in your repository which contains file named "module.json" and a folder named source with source file included
3. Type "yt target bbc-microbit-classic-gcc"
4. Then type "yt build"
5. Copy combined.hex file from build/bbc-microbit-classic-gcc/source/iot-example-combined.hex into Sending MICROBIT
6. Unplug the microbit if you supply power to it with seperate battery packs

Setting for Receiving microbit:
-------------------------------
1. plug in receiving microbit
2. create a folder for receiving microbit in your repository which contains file named "module.json" and a folder named source with source file included
3. Type "yt target bbc-microbit-classic-gcc"
4. Then type "yt build"
5. Copy combined.hex file from build/bbc-microbit-classic-gcc/source/iot-example-combined.hex into Receiving MICROBIT
6. Unplug the microbit if you supply power to it with seperate battery packs

Connecting two microbits with GPIOS:
-------------------------------------
1. Supply power to both microbits using either with USB or with seperate battery packs 
2. Put a crocodile clip on pin 1 of the send and pin 1 of the recieve microbit
3. Put a second crocile clip on the GND pin of the send and the GND pin of the recieve microbit.

How to Use
=====================
Two ways:
---------------
1. Copy the codes from source files from Sendmorse and Receivemorse into your source file repository in order, then yt build
2. copy hex files into your Sending and Receiving microbits 

The protocol
=================
My program is able to create sequences of dots and dashes,decrypt into normal characters added in a string which will then scroll across the LED display.
Button A and button B are both utilised on both microbits

On Sending microbit:
--------------------
Button A is used to create dot/dash, press it shortly for a dot and a bit longer for a dash, if too long "???" is displayed and microbit will reset
Button B is used to make sure no sequence of dots and dashes exceeds five characters ( it will display a tick if button B is pressed)
remember to press button B after you finish a sequence of dots and dashes,otherwise if pressing button A exceeds 5 times, the microbit will reset

On Receiving microbit:
---------------------
Button A is used to receive new morse code characters from sender, decrypt to alphabet and numeric characters and add those as a form of a string
( it will display a tick if button A is pressed)
Button B is used to display a string which contains decrypted characters from morse code, after displaying the microbit will reset auto itself

for example:
-----------
             -Let's say you want to decrypt sequences of morse codes into letters: ".-.-" ".." ".-" "--" = "L" "I" "A" "M"
              By pressing button A on Sending microbit shortly for a dot and a bit longer for a dash, you then press button B 
              to confirm that you finish your sequences of dots and dashes. On the receiving microbit, press button A each time you finish 
              a sequence of morse codes in order to be decrypted and added up in to a string.
              After you finish all the sequences that make up for letters "LIAM", press button B to display the result.
My program can use to decrypt a letter and mutiple letters as well.
Make sure you do not press button A on Sending microbit too fast at one time, otherwise the dot/dash may be missed.
Sometime, the microbits require to be pressed one time at first to initialise.

How to build
================
- Microbit Library "microbit.h" to declare used buttons(MicroBitButton) and Pin(MicroBitPin) to transmit Digitalvalue from one microbit to another
- using time of loop execution for if-else statement to check how long it takes to press button then base on the ranging of time
// Time difference for DOT (0ms- 280ms)
// Time difference for DASH (280- 800ms)
- boolean flags and while loops are widely used to initialise and keep the program running
- If-else statement to check the conditions
- Along with some built-in microbit functions: reset,display, sleep, clear,print

State of Diagram
==================
![alt text](https://gitlab.uwe.ac.uk/lk2-ha/morse-code/blob/master/State_diagram.pdf)
