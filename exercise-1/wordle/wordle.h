#ifndef WORDLE_H
#define WORDLE_H
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <random>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <cmath>
#include "main_screen.h"
using namespace std;
// WORDLE LOGIC
string randomWordle() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(0,2315); // possible words to become the
    // wordle, in the words.txt file
    int number = distr(gen);
    string answer_lower;
    ifstream file("words.txt"); // opens the words.txt file
    for (int i=0; i< number; i++) getline(file, answer_lower);
        file.close();   
        return answer_lower;
    
}

vector<string> guessColors(string guess_upper, string answer_upper) {
    vector<string> color = {BLACK, BLACK, BLACK, BLACK, BLACK};

    //will loop through the guesses twice.
    //first iteration will check if it is an exact match and sort them. If it isn't it will check
    //if it is a match just in a different place    
    for (int i = 0; i < 10; i++) {
        size_t index = answer_upper.find(guess_upper[(i % 5)]); //mod by 5 to separate the two iterations

        // First five iterations
    // make another vector that helps sort called tempcolor  
    // if the letter is exactly the same as the answer
    // if the word is eagle
    // guess is sleek
    //npos can tell u the index it was found at
        if (floor((float)i/float(5)) == 0) {

            // Letter is an exact match
            if (index != string::npos && index == (i % 5)) {
                color[index] = GREEN;
                answer_upper[index] = ' ';
            }
        
        // Last five iterations
        } else {
            if (index != string::npos) {

                // Letter is an indirect match
                color[i % 5] = YELLOW;
                answer_upper[index] = ' ';
            }
        }
    }
    return color;
}
  

void updateKeyboard(vector<vector<string>> colors, string guess_upper) {
    string black_keys;
    string yellow_keys;
    string green_keys;

    ifstream keyboard_file_in("keyboard.txt");

    // Keep track of previous keyboard colors
    if (keyboard_file_in.is_open()) {
        string line;
        getline(keyboard_file_in, line);
        black_keys = line + string(5, ' ');
        getline(keyboard_file_in, line);
        yellow_keys = line + string(5, ' ');
        getline(keyboard_file_in, line);
        green_keys = line + string(5, ' ');
    } else cerr << "Error: File could not be opened" << endl;
    keyboard_file_in.close();

    ofstream keyboard_file_out("keyboard.txt", ios::trunc);
    if (keyboard_file_out.is_open()) {

        // Add new colors to keyboard color rows
        for (int i = 0; i < 5; i++) {
            if (colors.back()[i] == BLACK) {
                black_keys[black_keys.size()-5+i] = guess_upper[i];
            } else if (colors.back()[i] == YELLOW) {
                yellow_keys[yellow_keys.size()-5+i] = guess_upper[i];
            } else if (colors.back()[i] == GREEN) {
                green_keys[green_keys.size()-5+i] = guess_upper[i];
            }
        }
        keyboard_file_out << black_keys << '\n' << yellow_keys << '\n' << green_keys;
    } else cerr << "Error: File could not be opened" << endl;
    keyboard_file_out.close();
}

void startGame(Stats & stats){
    vector <string> guesses;
    vector <vector<string>> colors;
    string gameState = "active";
    bool valid_guess = false;
    string answer = randomWordle();
    transform(answer.begin(), answer.end(), answer.begin(), ::toupper);

    while (gameState == "active"){
        bool valid_guess = false;
        string guess;
        string line;

        while (!valid_guess){ // not a valid guess 
            ifstream allowed_words_file("allowed.txt"); //opens the file (to read)
            ifstream answer_words_file("words.txt");
            cout << "Enter guess: ";
            cin >> guess;
            while (getline(allowed_words_file, line) || getline(answer_words_file, line)) {
                if (line.find(guess) != string::npos && guess.size() == 5) {
                    valid_guess = true;
                    break;
                } // checks if the word is within the file of allowed words, or allowed guesses
            }
            allowed_words_file.close();
            answer_words_file.close();
        }
        
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);
            guesses.push_back(guess);
            colors.push_back(guessColors(guess, answer)); // pushes back into our 2d vector, some 2d vectors
            //in the format of guess, answer.
            updateKeyboard(colors, guess);

            if (guess == answer) gameState = 'win';
            else if (guesses.size() == 6) gameState = 'lose';
            printScreen(guesses, answer, gameState, colors);
        }
        stats.Words.push_back(answer);
        stats.Attempts.push_back(guesses.size());
        stats.Wins.push_back((gameState == "win" ? "Yes" : "No")); // proposes boolean, and answers it
        cin.ignore();
        while (!gameState.empty()) getline(cin, gameState); // does not, game state is not empty.
    }
        #endif
    
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
// int Wordlength = 5;
// string wordguess;
// string correctword;
// String tempword = correctword;
// for (int i = 0; i<5; i++){ // this code is for each guess
//     // String tempword = correctword; <-- make sure the code has this reset on every
//     // new guess, not in the same guess.
//     if (wordguess[i] != string::npos){
//         if (wordguess[i] == correctword[i]){
//             wordguess[i] = green; // change this later, this just means correct;
//             tempword[i] = ' ';
//         }
//         wordguess[i] = yellow;
//         tempword[i] = ' '; 
//         // change this later, this means the letter is in the word, 
//         //but not in that position
//     }
//     else{
//         wordguess[i] = grey; 
//         // change this later, this means that the letter isnt in the
//         // word at all
//     }
// }
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
// }MAKE IT INTO SEPARATE FUNCTIONS
// the reason is because in each row, you cant go back to print, otherwise, 
// each new row would not work, print row by row in the picture

// TOP HEADER 
// MAKE A VARIABLE CALLED COLOR VECTOR that stores all the colors of each letter





// Keyboard Viewer

//String COLOR = WHITE;
//TOP HEADER
// for (int i = 0; i<5; i++){
//     string COLOR = colorvec[i];
//     cout << COLOR << " --- " << RESET;
// }
// // MIDDLE HEADER
// for (int i = 0; i<5; i++){
//     string COLOR = colorvec[i];
//     cout << COLOR << "| " << wordguess[i] << " |" << RESET;
// }

// //BOTTOM HEADER
// for (int i = 0; i<5; i++){
//     string COLOR = colorvec[i];
//     cout << COLOR << " --- " << RESET;
// }
