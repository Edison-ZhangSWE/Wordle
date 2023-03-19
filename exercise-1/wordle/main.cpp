#define RESET "\033[0m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {

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
    return 0;
}