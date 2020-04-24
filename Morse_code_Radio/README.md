Lam Ha - 19035157
=====================
Introduction
=================
an upgrade small microbit programme that can be used to communicate between two microbits via morsecode using Radio Frequency

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

Connecting two microbits:
-------------------------------------
1. Both repositories for Sender and Receiver must contain a file named "config.json" in order to use the Radio transmission

How to Use
=====================
Two ways:
---------------
1. Copy the codes from source files from Sendmorse and Receivemorse into your source file repository in order, then yt build
2. copy hex files into your Sending and Receiving microbits 

The protocol
=================
My program is able to create sequences of dots and dashes,decrypt into normal characters added in a string which will then scroll across the LED display.
Button A and button B are both utilised on microbit Sender 
Only Button A is utilised on microbit Receiver

On Sending microbit:
--------------------
1. Button A is used to create dot/dash, press it shortly for a dot and a bit longer for a dash, if too long "???" is displayed and microbit will reset
if we press more than 5 characters, the microbit will reset itself as well
When a dot is initialised, the microbit Sender will enable a radio value "1" to microbit Receiver
When a dash is initialised, the microbit Sender will enable a radio value "2" to microbit Receiver
2. Button B is used to confirm the morsecode pattern ( it will display a tick if button B is pressed) by transmit a radio value "3" to microbit Receiver


On Receiving microbit:
---------------------
Microbit Receiver will receive 3 radio values "1","2","3"
1. If value equals to "1", the program will do the dot part
2. If value equals to "2", the program will do the dash part
3. If value equals to "3", the program will do the decrypt morsecode characters into numberic and English alphabets
4. Button A is used to display the message

for example:
-----------
             -Let's say you want to decrypt sequences of morse codes into letters: ".-.-" ".." ".-" "--" = "L" "I" "A" "M"
              By pressing button A on Sending microbit shortly for a dot and a bit longer for a dash, you then press button B 
              to confirm that you finish your a sequence of dots and dashes. After you finish all the sequences that make up for letters "LIAM",
              press button A to display the words on the receiving microbit.
              
My program can use to decrypt a letter and mutiple letters as well.
Make sure you do not press button A on Sending microbit too fast at one time, otherwise the dot/dash may be missed.
Sometime, the microbits require to be pressed one time at first to initialise.

How to build
================
- Microbit Library "microbit.h" to declare used buttons(MicroBitButton) and (uBit.radio.enable) for Radio transmission from one microbit to another
- using time of loop execution for if-else statement to check how long it takes to press button then base on the ranging of time
// Time difference for DOT (0ms- 280ms)
// Time difference for DASH (280- 800ms)
- boolean flags and while loops are widely used to initialise and keep the program running
- If-else statement to check the conditions
- Along with some built-in microbit functions: reset,display, sleep, clear,print

State of Diagram
==================
![alt text](https://gitlab.uwe.ac.uk/lk2-ha/morsecode-radio-challenge3/-/blob/master/State-diagram.pdf)