#ifndef WORDLE_H
#define WORDLE_H
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <random>
using namespace std;

struct Stats {

}
/* First step 
    to check if the word is in the list of allowed text            !=string::npos
    second step
    to check letter by letter to see if its in the word (make a separate variable, remove the letter from this temp variable
    if it is in the word. dont do anything if it isnt)
    if it is, check if that index has the index of the word. for instance, if u guessed frink and the word was flirt,
    the f will be checked against index 0 of the real word. if it is correct, it lights green. if not, make it yellow (because
    we only reach this check if the letter is in the word anyway.)

    unit tests: 
    Testing word that isnt in allowed.txt
    Invalid INputs: Testing 4 Letter word / Symbols that aren't letters 
    Testing Word with multiple letters, for instance Speed (if they guess 3 Es, only the first two should be colored)

*/
// IN ORDER to check if the word is in the file, 
// looop through the text file with getline, and use a comparison to figure out if any of 
// them are a valid word, if yes, then continue.
int Wordlength = 5;
string wordguess;
string correctword;
String tempword = correctword;
for (int i = 0; i<5; i++){ // this code is for each guess
    // String tempword = correctword; <-- make sure the code has this reset on every
    // new guess, not in the same guess.
    if (wordguess[i] != string::npos){
        if (wordguess[i] == correctword[i]){
            wordguess[i] = green; // change this later, this just means correct;
            tempword[i] = ' ';
        }
        wordguess[i] = yellow;
        tempword[i] = ' '; 
        // change this later, this means the letter is in the word, 
        //but not in that position
    }
    else{
        wordguess[i] = grey; 
        // change this later, this means that the letter isnt in the
        // word at all
    }
}
// THIS PROGRAM CHECKS IF THE WORD IS CORRECT/WORDLE LOGIC, ASSUMING THAT IT IS IN THE FILE
//ALREADY.
//WORDLE GAME^^






// IDK WHAT PART THIS IS BUT 
// printing the picture of the word, given the word.
// for (int i = 0; i<6; i++){
// for (int j = 0; j < 5; j++){
// cout << COLOR << " --- " << RESET;
// cout << COLOR << "| " << wordguess[i] << " |" << RESET;
// cout << COLOR << " --- " << RESET;
// }
// } HAJIN SAID TO MAKE IT INTO SEPARATE FUNCTIONS
// the reason is because in each row, you cant go back to print, otherwise, 
// each new row would not work, print row by row in the picture

// TOP HEADER 
// MAKE A VARIABLE CALLED COLOR VECTOR that stores all the colors of each letter





// Keyboard Viewer

String COLOR = WHITE;
//TOP HEADER
for (int i = 0; i<5; i++){
    string COLOR = colorvec[i];
    cout << COLOR << " --- " << RESET;
}
// MIDDLE HEADER
for (int i = 0; i<5; i++){
    string COLOR = colorvec[i];
    cout << COLOR << "| " << wordguess[i] << " |" << RESET;
}

//BOTTOM HEADER
for (int i = 0; i<5; i++){
    string COLOR = colorvec[i];
    cout << COLOR << " --- " << RESET;
}