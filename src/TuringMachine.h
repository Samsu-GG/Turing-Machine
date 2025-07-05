#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

#include <deque>
#include <string>
#include <map>
#include <utility>

using std::deque;
using std::string;
using std::map;
using std::pair;

struct Transition {
    string next_state;
    char write_symbol;
    char direction; 
};

class TuringMachine
{
    deque<char> tape;
    int head;
    string current_state, accept_state, reject_state;
    map<pair<string, char>, Transition> transitions;

    public:

    TuringMachine(string start_state, string accept, string reject);
    void setTape(const string& new_tape);
    void addTransition(string state, char read, string next, char write, char dir);
    void run();
    void printTape();
};

#endif