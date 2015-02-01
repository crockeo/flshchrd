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

        std::cout << "isEmpty():" << std::endl;
        std::cout << "  " << d.isEmpty() << std::endl;

        std::cout << "getMap():" << std::endl;
        auto map = d.getMap();
        for (auto it = map.begin(); it != map.end(); it++)
            std::cout << "  " << std::get<0>(*it) << " | " << std::get<1>(*it) << std::endl;

        std::cout << "generateAnswers():" << std::endl;
        auto vec = d.generateAnswers(d.getQuestion(0), 1);
        for (auto& a: vec)
            std::cout << "  " << a << std::endl;

        return 0;
    }
}
