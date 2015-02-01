#ifndef _DECK_HPP_
#define _DECK_HPP_

//////////////
// Includes //
#include <exception>
#include <istream>
#include <string>
#include <vector>
#include <map>

//////////
// Code //

// A class to represent the deck of flash cards.
class Deck {
private:
    std::map<std::string, std::string> questions;

public:
    // Creating a new deck from an existent set of questions.
    Deck(std::map<std::string, std::string>);

    // Creating a new deck from an input stream.
    Deck(std::istream&&) throw(std::runtime_error);

    // Creating a new deck from a location on disk.
    Deck(std::string) throw(std::runtime_error);

    // Creating a new, empty deck.
    Deck();

    // Getting the answer to a question.
    std::string getAnswer(std::string) const;

    // Validating the answer to a question.
    bool validateAnswer(std::string, std::string) const;

    // Getting a question from an 'index' (the begin iterator + the index).
    std::string getQuestion(int) const;

    // Generating a set of 'answers' for a question. Only one of the returned
    // strings will be the correct answer.
    std::vector<std::string> generateAnswers(std::string, int) const throw(std::logic_error);

    // Getting a copy of the question map.
    std::map<std::string, std::string> getMap() const;

    // Checking if the deck is empty.
    bool isEmpty() const;
};

#endif
