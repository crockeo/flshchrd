//////////////
// Includes //
#include <iostream>

#include "deck.hpp"

//////////
// Code //

// Entry point!
int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Hello from " << argv[0] << "!" << std::endl;
        return 0;
    } else {
        Deck d(argv[1]);

        std::cout << d.isEmpty() << std::endl;

        auto map = d.getMap();
        for (auto it = map.begin(); it != map.end(); it++)
            std::cout << std::get<0>(*it) << " | " << std::get<1>(*it) << std::endl;

        return 0;
    }
}
