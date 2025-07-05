// Loader.cpp
#include "TuringMachine.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using std::ifstream;
using std::string;
using std::getline;
using std::istringstream;
using std::runtime_error;

TuringMachine loadMachineFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Cannot open file: " + filename);
    }

    string line, start_state, accept_state, reject_state;

    // Parse config lines
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        if (line.rfind("start:", 0) == 0) {
            start_state = line.substr(6);
            start_state.erase(0, start_state.find_first_not_of(" "));
        } else if (line.rfind("accept:", 0) == 0) {
            accept_state = line.substr(7);
            accept_state.erase(0, accept_state.find_first_not_of(" "));
        } else if (line.rfind("reject:", 0) == 0) {
            reject_state = line.substr(7);
            reject_state.erase(0, reject_state.find_first_not_of(" "));
        } else {
            break; // Transition lines start now
        }
    }

    if (start_state.empty() || accept_state.empty() || reject_state.empty()) {
        throw runtime_error("Missing start, accept, or reject state in .tm file");
    }

    TuringMachine tm(start_state, accept_state, reject_state);

    do {
        if (line.empty() || line[0] == '#') continue;

        // Example: q0 1 -> q1 0 R
        string current, next, arrow;
        char read, write, dir;

        istringstream iss(line);
        iss >> current >> read >> arrow >> next >> write >> dir;

        if (arrow != "->") {
            throw runtime_error("Invalid transition syntax in line: " + line);
        }

        tm.addTransition(current, read, next, write, dir);

    } while (getline(file, line));

    return tm;
}