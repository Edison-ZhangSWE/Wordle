#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#include <iostream>
#include <fstream>
#include "keyboardprint.h"

using namespace std;

int main(int argc, char* argv[]) {
    int game_state = 0;
    int previous_gamestate;
    string line;
    std::vector<string> colorOptions = {BLACK, YELLOW, GREEN, RESET};
    std::vector<std::vector<string>> colors;
    std::vector<std::vector<string>> previous_colors = {{RESET}};
    std::vector<std::vector<char>> keyboard = {{'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'}, {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'}, {'Z', 'X', 'C', 'V', 'B', 'N', 'M'}};

    while(true) {
        ifstream file("../wordle/stats.txt");
            if(file.is_open()){
                file >> game_state;
            }
        if (game_state = 0){ //wordle is not running
            if (previous_gamestate != game_state){
                system("clear");
                cout << "Please launch the wordle game." << endl;
                ofstream file2("../wordle/keyboard.txt", ios::trunc);
                file2.close();
                previous_gamestate = game_state;
                previous_colors = {{RESET}};
            }
        }
        else if (game_state = 1){ // Wordle is running, but not in game
            if (previous_gamestate != game_state){
                system("clear");
                cout << "Waiting for Wordle game round to start." << endl;
                ofstream file2("../wordle/keyboard.txt", ios::trunc);
                //truncrefreshes the keyboard, before every game
                //reading the keyboard.txt file in wordle
                file2.close();
                previous_gamestate = game_state;
                previous_colors = {{RESET}};

            }
        }
        else if (game_state = 2){ // wordle is currently in game
            previous_gamestate = game_state;
            colors.clear();
            for (std::vector<char> row : keyboard){
                colors.push_back({});
                for (char c : row){
                    ifstream file2("../wordle/keyboard.txt");
                    colors.back().push_back(colorOptions[3]); //colorsoption?
                    if (file.is_open()){ // 3 different color options
                        for (int i = 0; i<3; i++){ // displaying the keyboard
                        // of the current game
                            getline(file2, line);
                            if (line.find(c) != string::npos) {
                                colors.back().back() = colorOptions[i];
                            }
                        }
                    }
                    else cerr<< "Error: file could not be opened." << endl;
                }
            }
            if (previous_colors != colors) {
                system("clear");
                printKeyboard(keyboard, colors);
                previous_colors = colors;
        }
        }
        else cerr<< "Error: file could not be opened." << endl;
        file.close();
    }
    return 0;
    }

