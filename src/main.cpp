//////////////
// Includes //
#include <iostream>

#include "prompt.hpp"
#include "deck.hpp"

//////////
// Code //

// Entry point!
int main(int argc, char** argv) {
    std::string path;
    Deck d;

    if (argc != 2) {
        std::cout << "Enter deck location: ";
        std::cin >> path;
    } else
        path = std::string(argv[1]);

    try {
        d = Deck(path);
    } catch (std::runtime_error& err) {
        std::cout << "Failed to open file '" << path << "'!" << std::endl;
        return 1;
    }

    startPrompt(d);

    return 0;
}
