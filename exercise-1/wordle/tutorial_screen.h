#ifndef TUTORIAL_SCREEN_H
#define TUTORIAL_SCREEN_H

def print_Tutorial_screen(){
    // HOW TO PLAY, MAIN MENU
std::cout << "=============================================" << std::endl;
std::cout << "                 HOW TO PLAY                 " << std::endl;
std::cout << "=============================================" << std::endl;
std::cout << "Guess the Wordle in 6 tries." << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << "HOW TO PLAY:"
std::cout << "- Each guess must be a valid 5 letter word."
std::cout << "- The color of the titles will change to show" << std::endl;
std::cout << "you how close your guess was to the word." << std::endl;
std::cout << std::endl; 
std::cout << std::endl;
std::cout << GREEN << " --- " << RESET << "  ---  ---  ---  ---";
std::cout << GREEN << "| W |" << RESET << " | E || A || R || Y |";
std::cout << GREEN << " --- " << RESET << "  ---  ---  ---  ---";
std::cout << "W is in the word and in the correct spot." << std::endl;
std::cout << std::endl;
std::cout << " --- " << YELLOW << " --- " << RESET << " ---  ---  --- " << std::endl;
std::cout << "| P |" << YELLOW << "| I |" << RESET << "| L || L || S |" << std::endl;
std::cout << " --- " << YELLOW << " --- " << RESET << " ---  ---  --- " << std::endl;
std::cout << "I is in the word but in the wrong spot." << std::endl;
std::cout << std::endl;
std::cout << " ---  ---  --- " << BLACK << " --- " << RESET << " --- " << std::endl;
std::cout << "| V || A || G |" << BLACK << "| U |" << RESET << "| E |" << std::endl;
std::cout << " ---  ---  --- " << BLACK << " --- " << RESET << " --- " << std::endl;
std::cout << "U is not in the word in any spot.";
std::cout << std::endl;
std::cout << std::endl;
std::cout << "Press [enter] to continue";

}