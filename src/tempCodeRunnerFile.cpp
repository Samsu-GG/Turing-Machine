#include <iostream>
#include <string>
#include "TuringMachine.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::exception;

TuringMachine loadMachineFromFile(const string& filename);

int main()
{
    cout << "Select a Turing Machine to run:\n";
    cout << "1. 1's Complement\n";
    cout << "2. 0^n 1^n 2^n (n>=1)\n";
    cout << "3. 2's Complement\n";
    cout << "4. Unary Addition\n";
    cout << "5. Unary Subtraction\n";
    cout << "6. Unary Multiplication\n";
    cout << "7. Unary Division\n";
    cout << "8. Palindrome\n";
    cout << "9. W2W where W->{1,2}*\n";
    cout << "Enter your choice (1-9): ";

    int choice;
    cin >> choice;
    string filepath;

    switch (choice) 
    {
        case 1: filepath = "machines/ones_complement.tm"; break;
        case 2: filepath = "machines/0n1n2n.tm"; break;
        case 3: filepath = "machines/twos_complement.tm"; break;
        case 4: filepath = "machines/unary_add.tm"; break;
        case 5: filepath = "machines/unary_subtract.tm"; break;
        case 6: filepath = "machines/unary_multiply.tm"; break;
        case 7: filepath = "machines/unary_divide.tm"; break;
        case 8: filepath = "machines/palindrome.tm"; break;
        case 9: filepath = "machines/W2W.tm"; break; // the logic 1st half and 2nd half will be same and 1st half and 2nd half will be separate by 2...
        default: cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "Enter input string for the Turing Machine: ";
    string input;
    cin >> input;

    try
    {
        TuringMachine tm=loadMachineFromFile(filepath);
        tm.setTape(input);
        cout << "Running Turing Machine from: "<< filepath << endl;
        cout << "Initial tape: ";
        tm.printTape();
        tm.run();
    }
    catch(const exception& e)
    {
        cout << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}