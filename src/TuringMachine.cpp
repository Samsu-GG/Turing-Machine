#include <iostream>
#include "TuringMachine.h"

using std::cout;
using std::endl;
using std::make_pair;

TuringMachine::TuringMachine(string start_state, string accept, string reject)
{
    current_state=start_state;
    accept_state=accept;
    reject_state=reject;
    head=0;
}

void TuringMachine::setTape(const string& new_tape)
{
    tape.clear();
    for(char ch: new_tape)
    {
        tape.push_back(ch);
    }
    head=0;
}

void TuringMachine::addTransition(string state, char read, string next, char write, char dir)
{
    transitions[{state, read}] = {next, write, dir};
}

void TuringMachine::run() 
{
    while (true) 
    {
        if (current_state == accept_state) {
            cout << "\n\033[32mAccepted\033[0m\nFinal tape: ";
            printTape();
            cout << "\n\n\n";
            return;
        } else if (current_state == reject_state) {
            cout << "\n\033[31mRejected\033[0m\n";
            //printTape();
            cout << "\n\n\n";
            return;
        }

        char current_symbol = tape[head];
        auto key = make_pair(current_state, current_symbol);
        if (transitions.find(key) == transitions.end()) {
            cout << current_state <<" "<<current_symbol<<" -> Not found"<<endl;
            current_state = reject_state;
            continue;
        }

        Transition t = transitions[key];
        tape[head] = t.write_symbol;
        current_state = t.next_state;
        head += (t.direction == 'R') ? 1 : -1;
        cout << key.first <<" "<<key.second<<" -> "<< t.next_state<<" "<<t.write_symbol<<" "<<t.direction<<endl;
        if (head < 0) {
            tape.push_front('_');
            head = 0;
        } else if (head >= static_cast<int>(tape.size())) {
            tape.push_back('_');
        }
    }
}

void TuringMachine::printTape() 
{
    for (char c : tape) cout << c;
    cout << endl;
}