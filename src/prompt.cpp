#include "prompt.hpp"

//////////
// Code //

// Prompting a single question - if the return value is true, it indicates that
// the program should quit.
bool promptQuestion(int question) {
    return false;
}

// Starting the prompt.
void startPrompt(const Deck& deck) {
    for (int i = 0; i < deck.size(); i++)
        promptQuestion(i);
}
