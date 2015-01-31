#include "deck.hpp"

//////////////
// Includes //
#include <exception>
#include <fstream>

//////////
// Code //

// Creating a new deck from an existent set of questions.
Deck::Deck(std::map<std::string, std::string> questions) :
        questions(questions) { }

// Creating a new deck from an input stream.
Deck::Deck(std::istream&& in) throw(std::runtime_error) {
    if (!in.good())
        throw std::runtime_error("Input stream is not good.");

    std::string question, answer;
    while (!in.eof()) {
        in >> question;
        in >> answer;

        this->questions[question] = answer;
    }
}

// Creating a new deck from a location on disk.
Deck::Deck(std::string str) throw(std::runtime_error)
        : Deck(std::ifstream(str)) { }

// Creating a new, empty deck.
Deck::Deck() { }

// Getting the answer to a question.
std::string Deck::getAnswer(std::string question) const {
    return this->questions.at(question);
}

// Validating the answer to a question.
bool Deck::validateAnswer(std::string question, std::string answer) const {
    return this->questions.at(question).compare(answer) == 0;
}

// Getting a question from an 'index' (the begin iterator + the index).
std::string Deck::getQuestion(int index) const {
    auto it = this->questions.begin();
    for (int i = 0; i < index; i++)
        it++;
    return std::get<1>(*it);
}

// Generating a set of 'answers' for a question. Only one of the returned
// strings will be the correct answer.
std::vector<std::string> Deck::generateAnswers(std::string question) const {
    return std::vector<std::string>();
}

// Getting a copy of the question map.
std::map<std::string, std::string> Deck::getMap() const {
    return this->questions;
}

// Checking if the deck is empty.
bool Deck::isEmpty() const {
    return this->questions.size() == 0;
}