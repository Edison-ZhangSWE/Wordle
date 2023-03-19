#ifndef STATS_SCREEN_H
#define STATS_SCREEN_H

//STATS >>
void print_stats_screen(){
int TimesPlayed;
int AverageAttempts;
int winPercentage;
int currentStreak;
int longestStreak;
std::vector <vector<string>> words;
std::vector <int> attempts;
std::vector <string> wasitawin; // vector of all games, with a value of win or loss assigned to each (Yes/No)
std::cout << "==========================" << std::endl;
std::cout << "   STATISTICS SUMMARY     " << std::endl;
std::cout << "==========================" << std::endl;
std::cout << "Times Played:" << setw(13) << right << TimesPlayed << std::endl;
std::cout << "Average Attempts:" << setw(9) << right << AverageAttempts << std::endl;
std::cout << "Win Percentage:" << setw(10) << right << winPercentage << "%" << std::endl;
std::cout << "Current Streak:" <<setw(11) << right << currentStreak << std::endl;
std::cout << "Longest Streak:" << setw(11) << right << longestStreak << std::endl;
std::cout << std::endl;
std::cout << std::endl;
std::cout << "--------------------------" << std::endl;
std::cout << "WORD     ATTEMPTS      WIN" << std::endl;
std::cout << "--------------------------" << std::endl;
for (int i =0; i < wasitawin.size(); i++) {// could be attempts.size, or word.size, all same size
std::cout << previouswords[i] << setw(12) << right << attempts[i] << setw(9) << right << wasitawin[i] << std::endl;
}
// USE A FOR LOOP TO EXECUTE THIS OVER EACH ITERATION OF TEXT ( IN SEPARATE TEXT FILE HOLDING
// WORD, ATTEMPTS, AND WINS)
std::cout << std::endl;
std::cout << std::endl;
std::cout << "Press [enter] to continue";
}
#endif

//Calculate the variables for the stats

int TimesPlayed = 0;
vector<int> averageAttemptsVec = {}; // vector of number of attempts
int wins = 0; //(increment after each win)
float winPercentage = 0;
int currentStreak = 0;
int longestStreak = 0;

//after each iteration of the program,
TimesPlayed++;
averageAttempts = (int)reduce(averageAttemptsVec.begin(), averageAttemptsVec.end()) / averageAttemptsVec.length(); // #include <numeric>
winPercentage = (float)wins / (float)TimesPlayed // #include <iomanip>
winPercentage.setprecision(2);
if (win == true){ // MAKE SURE TO USE A BOOLEAN CALLED WIN
    currentStreak++;
    if(currentStreak > longestStreak){
        longestStreak = currentStreak;
    }
}
elif (win == false){
    currentStreak = 0;
}
