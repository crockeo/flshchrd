#include "deck.hpp"

//////////////
// Includes //
#include <cstdlib>
#include <fstream>
#include <sstream>

//////////
// Code //

// Reading in a line!
std::string readLine(std::istream& in) {
    std::ostringstream str;

    while (in.peek() != '\r' && in.peek() != '\n')
        str << (char)in.get();
    if (in.peek() == '\r' || in.peek() == '\n')
        in.get();

    return str.str();
}

// Creating a new deck from an existent set of questions.
Deck::Deck(std::map<std::string, std::string> questions) :
        questions(questions) { }

// Creating a new deck from an input stream.
Deck::Deck(std::istream&& in) throw(std::runtime_error) {
    if (!in.good())
        throw std::runtime_error("Input stream is not good.");

    std::string question, answer;
    while (!in.eof() && in.peek() != -1) {
        question = readLine(in);
        answer   = readLine(in);

        this->questions[question] = answer;
    }
}

// Creating a new deck from a location on disk.
Deck::Deck(std::string str) throw(std::runtime_error)
        : Deck(std::ifstream(str)) { }

// Creating a new, empty deck.
Deck::Deck() { }

// Getting the size of the deck.
int Deck::size() const { return this->questions.size(); }

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
    return std::get<0>(*it);
}

// Generating a set of 'answers' for a question. Only one of the returned
// strings will be the correct answer.
std::vector<std::string> Deck::generateAnswers(std::string question, int extras) const throw(std::logic_error) {
    if (extras > this->questions.size() - 1)
        throw std::logic_error("The number of extra answers exceeds the number of extra questions.");

    std::vector<std::string> answers;

    answers.push_back(this->questions.at(question));
    std::string q;

    for (int i = 0; i < extras; i++) {
        q = this->getQuestion(rand() % this->questions.size());

        if (q.compare(question) == 0) {
            i--;
            continue;
        }

        answers.push_back(this->questions.at(q));
    }

    return answers;
}

// Getting a copy of the question map.
std::map<std::string, std::string> Deck::getMap() const {
    return this->questions;
}

// Checking if the deck is empty.
bool Deck::isEmpty() const {
    return this->questions.size() == 0;
}
