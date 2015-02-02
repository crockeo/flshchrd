#include "prompt.hpp"

//////////////
// Includes //
#include <iostream>

//////////
// Code //

// Starting the prompt.
void startPrompt(const Deck& deck) {
    const int extraAnswers = deck.size() < 4 ? deck.size() - 1 : 3;

    std::string question, input;
    std::vector<std::string> answers;

    for (int i = 0; i < deck.size(); i++) {
        question = deck.getQuestion(i);
        answers = deck.generateAnswers(question, extraAnswers);

        std::cout << "Q: " << question << std::endl;

        for (int j = 0; j < answers.size(); j++)
            std::cout << " " << (j + 1) << ". " << answers.at(j) << std::endl;

        std::string input;
        std::cin >> input;

        if (input.compare("q") == 0 || input.compare("quit") == 0)
            return;

        int n;
        try {
            n = stoi(input);
        } catch (const std::invalid_argument& err) {
            std::cout << "You did not enter a number!" << std::endl << std::endl;

            i--;
            continue;
        }

        if (deck.validateAnswer(question, answers.at(n - 1)))
            std::cout << "You were right!";
        else
            std::cout << "You were wrong!";
        std::cout << std::endl << std::endl;
    }

    std::cout << "Done!" << std::endl;
}
