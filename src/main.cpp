#include <iostream>
#include <string>
#include <windows.h>
#include "TuringMachine.h"

using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::string;

TuringMachine loadMachineFromFile(const string &filename);

int main()
{
    while (true)
    {
        Sleep(2500);
        cout << "Select a Turing Machine to run:\n";
        cout << "1. 1's Complement\n";
        cout << "2. 2's Complement\n";
        cout << "3. 0^n 1^n 2^n (n>=1)\n";
        cout << "4. Unary Addition\n";
        cout << "5. Unary Subtraction\n";
        cout << "6. Unary Multiplication\n";
        cout << "7. Unary Division\n";
        cout << "8. Palindrome\n";
        cout << "9. W2W where W->{0,1}*\n";
        cout << "10.Exit\n";
        cout << "Enter your choice (1-10): ";

        int choice;
        cin >> choice;
        string filepath;

        switch (choice)
        {
        case 1:
            cout << "\n\nYou selected 1's Complement.\nPlease enter a binary number (only 0s and 1s) with no spaces(e.g.1100)\n " << endl;
            filepath = "machines/ones_complement.tm";
            break;

        case 2:
            cout << "\n\nYou selected 2's Complement.\nPlease enter a binary number (e.g., 1010)\n " << endl;
            filepath = "machines/twos_complement.tm";
            break;
            
        case 3:
                cout << "\n\nYou selected 0^n 1^n 2^n.\nEnter a string with equal numbers of 0s, 1s, and 2s in that order (e.g., 001122)\n " << endl;
                filepath = "machines/0n1n2n.tm";
                break;

        case 4:
            cout << "\n\nYou selected Unary Addition.\nEnter two unary numbers (1s) separated by a plus sign (e.g., 111+11)\n " << endl;
            filepath = "machines/unary_add.tm";
            break;

        case 5:
            cout << "\n\nYou selected Unary Subtraction.\nEnter two unary numbers separated by a minus sign (e.g., 1111-11)\n " << endl;
            filepath = "machines/unary_subtract.tm";
            break;

        case 6:
            cout << "\n\nYou selected Unary Multiplication.\nEnter two unary numbers separated by a '0' and at the end there will be another '0' (e.g., 1110110)\n " << endl;
            filepath = "machines/unary_multiply.tm";
            break;

        case 7:
            cout << "\n\nYou selected Unary Division.\nEnter two unary numbers separated by a '0' and at the end there will be another '0'(e.g., 1110110)\n"
                 << endl;
            filepath = "machines/unary_divide.tm";
            break;

        case 8:
            cout << "\n\nYou selected Palindrome Checker.\nEnter a binary string (0s and 1s) to check if it is a palindrome\n " << endl;
            filepath = "machines/palindrome.tm";
            break;

        case 9:
            cout << "\n\nYou selected W2W.\nEnter a string over {1,0} where the second half repeats the first half, separated by a 2 (e.g., 10210)\n " << endl;
            filepath = "machines/W2W.tm";
            break;
        case 10:
            cout << "\n\nYou selected uanry to Binary.\nEnter a string over {1}  (e.g., 1111)\n " << endl;
            filepath = "machines/W2W.tm";
            break;
        case 11:
            cout << "\n\nThank You!" << endl;
            return 0;
        default:
            cout << "\n\nInvalid choice.\n"
                 << endl;
        }

        cout << "Enter input string for the Turing Machine: ";
        string input;
        cin >> input;

        try
        {
            TuringMachine tm = loadMachineFromFile(filepath);
            tm.setTape(input);
            cout << "Running Turing Machine from: \033[33m" << filepath <<"\033"<< endl;
            cout << "\033[34mInitial tape: \033[0m";
            tm.printTape();
            tm.run();
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
            return 1;
        }
    }
}