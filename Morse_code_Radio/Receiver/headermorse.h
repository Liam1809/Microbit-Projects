#include "ManagedString.h"
// Sequence Morse characters from [A->Z] and [0->9]
ManagedString MorseCharacter [36] = {".-","-...", "-.-.", "-..", 
                                     ".", "..-.", "--.", "....", 
                                     "..", ".---", "-.-", ".-.-", 
                                     "--", "-.", "---", ".--.", 
                                     "--.-", ".-.", "...", "-", 
                                     "..-", "...-", ".--", "-..-", 
                                     "-.--", "--..", ".----", "..---",
                                     "...--", "....-", ".....", "-....",
                                     "--...", "---..", "----.", "-----" };
// Sequence Alphabet and numeric characters, corresponding to Morse characters
ManagedString Character [36] = {"A", "B", "C", "D",
                                "E", "F", "G", "H",
                                "I", "J", "K", "L", 
                                "M", "N", "O", "P",
                                "Q", "R", "S", "T",
                                "U", "V", "W", "X",
                                "Y", "Z", "1", "2",
                                "3", "4", "5", "6",
                                "7", "8", "9", "0"};
/* Sequence undefined dash and dot,
   How to find: 
   take 4 character Morse codes   
   then add dash/dot at the fifth position
   then compare with 5 character Morse codes
   the rest are found by changing the sequence of dot and dash into dash and dot in order*/
ManagedString Undefined [22] = {"-...-", "-.-..", "-.-.-", "..-..", "..-.-", "--..-", ".-..-", ".--..", ".--.-", "...-.", "-.---", 
                                ".---.", ".-.--", ".-.-.", "--.--", "--.-.", "..--.", "-.--.", "-..--", "-..-.", "---.-", ".-..."};

/*char Encrypted (char c) {
    switch(c){
        case 'L' :   
                     return '1';
                     break; 
        case 'I' :   
                     return '8';
                     break;
        case 'A' :   
                     return '0';
                     break;
        case 'M' :   
                     return '9';
                     break;
        case '1' :   
                     return 'L';
                     break; 
        case '8' :   
                     return 'I';
                     break;
        case '0' :   
                     return 'A';
                     break;
        case '9' :   
                     return 'M';
                     break;
        default:     return c;
                     break;
    }
}*/