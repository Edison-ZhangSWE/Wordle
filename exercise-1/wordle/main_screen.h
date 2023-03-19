#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"

#include <iostream>
#include <vector>

void printTopScreen(string COLOR) {
    cout << COLOR << " --- " << RESET;
    }
void printMiddleScreen(char a, string COLOR) {
    cout << COLOR << "| " << a << " |" << RESET;
    }
void printBottomScreen(string COLOR) {
    cout << COLOR << " --- " << RESET;
    }
void printScreen(std::vector<std::string> guesses, std::string correctWord, std::string wordleGameState, std::vector<std::vector<std::string>> colors){

for (int i = 0; i<5; i++){ // loops through our guesses
    for (int j = 0; j<5; j++){
        printTopScreen(colors[i][j]); // prints the top of the header with our specified color
}
std::cout << endl;
for (int i = 0; i<5; i++){
    printMiddleScreen(guesses[i][j], colors[i][j]); // prints the middle part, with the array index of our guess
    // array of an array because there are multiple guesses and multiple letters in a guess. same for colors
}
std::cout << endl; 
for (int i = 0; i<5; i++){
    printBottomScreen(colors[i][j]);
}
std::cout << endl;
}
std::cout << endl;
std::cout << endl;
std::cout << endl;
// VICTORY SCREEN
if (wordleGameState == "win"){
cout << endl;
cout << "Splendid!" << endl;
cout << endl;
cout << "Press [enter] to continue";
}
// DEFEAT SCREEN
else if (wordleGameState == "lose"){
cout << endl;
cout << "The word was: " << correctword << endl;
cout << endl;
cout << "Better luck next time!" << endl;
cout << endl;
cout << "Press [enter] to continue";
}
}
#endif