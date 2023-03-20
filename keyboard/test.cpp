#include <igloo/igloo.h>

using namespace igloo;

Context(WordleKeyboard){
    void testKeyboard() {
    Keyboard keyboard;
    string expectedOutput;

    // Test 1: Test that the keyboard returns the correct key for a given character
    expectedOutput = "a";
    assert(keyboard.getKey('A') == expectedOutput);

    // Test 2: Test that the keyboard returns an empty string for an invalid character
    expectedOutput = "";
    assert(keyboard.getKey('$') == expectedOutput);

    // Test 3: Test that the keyboard returns the correct case of the key for a given character
    expectedOutput = "B";
    assert(keyboard.getKey('b', true) == expectedOutput);

    // Test 4: Test that the keyboard returns the correct key for a given character in caps lock mode
    expectedOutput = "D";
    keyboard.setCapsLock(true);
    assert(keyboard.getKey('d') == expectedOutput);

    // Reset caps lock to its original state
    keyboard.setCapsLock(false);
}
int main(int argc, const char* argv[]){
    return TestRunner::RunAllTests(argc, argv);
}
}