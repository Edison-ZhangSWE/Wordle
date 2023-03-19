#ifndef STATS_SCREEN_H
#define STATS_SCREEN_H

//STATS >>
void print_stats_screen(){
int TimesPlayed;
int AverageAttempts;
int winPercentage;
int currentStreak;
int longestStreak;
std::vector<vector<string>> words;
std::vector<int> Attempts;
cout << "==========================" << endl;
cout << "   STATISTICS SUMMARY     " << endl;
cout << "==========================" << endl;
cout << "Times Played:" << setw(13) << right << TimesPlayed << endl;
cout << "Average Attempts:" << setw(9) << right << AverageAttempts << endl;
cout << "Win Percentage:" << setw(10) << right << winPercentage << "%" << endl;
cout << "Current Streak:" <<setw(11) << right << currentStreak << endl;
cout << "Longest Streak:" << setw(11) << right << longestStreak << endl;
cout << endl;
cout << endl;
cout << "--------------------------" << endl;
cout << "WORD     ATTEMPTS      WIN" << endl;
cout << "--------------------------" << endl;
cout << password << setw(12) << right << attempts << setw(9) << right << wasitawin << endl;
// USE A FOR LOOP TO EXECUTE THIS OVER EACH ITERATION OF TEXT ( IN SEPARATE TEXT FILE HOLDING
// WORD, ATTEMPTS, AND WINS)
cout << endl;
cout << endl;
cout << "Press [enter] to continue";


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
}