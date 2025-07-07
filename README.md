# Turing Machine Simulator

A simple, modular **Turing Machine** simulator written in C++.  
Load and run different machine definitions (.tm files) on custom input strings.

## 🚀 Features

- Modular: load transitions from `.tm` files  
- Interactive: choose machine and input at runtime  
- Extensible: add your own `.tm` files under `machines/`  
- Optional: colored terminal output using ANSI codes

## 📁 Project Structure

Your project directory should look like this:

Turing-Machine/  
├── Makefile  
├── README.md  
├── src/  
│   ├── main.cpp            ← Entry point  
│   ├── TuringMachine.h     ← Simulator class  
│   ├── TuringMachine.cpp   ← Implementation  
│   └── Loader.cpp          ← Loads `.tm` files  
└── machines/  
  ├── ones_complement.tm  
  ├── twos_complement.tm  
  ├── anbncn.tm  
  ├── unary_add.tm  
  ├── unary_subtract.tm  
  ├── unary_multiply.tm  
  ├── unary_divide.tm  
  ├── palindrome.tm  
  ├── w2w.tm
  └── unary_to_binary.tm


## ⚙️ Prerequisites

Make sure you have a C++17 compiler and `make` installed.  
For MSYS2 users:  
First run `pacman -Syu` to update your system.  
Then run `pacman -S --needed base-devel mingw-w64-ucrt-x86_64-gcc make` to install everything.

## 🛠️ Building

From your project root directory, run `make all` to build the simulator.  
To build and run in one step, run `make run`.  
This creates an executable named `TuringSimulator`.

## ▶️ Running the Program

After building, run the simulator using `./TuringSimulator` or `.\TuringSimulator.exe` (on Windows).  
You will see a menu like:

1. 1's Complement  
2. 2's Complement  
3. 0^n 1^n 2^n (n ≥ 1)  
4. Unary Addition  
5. Unary Subtraction  
6. Unary Multiplication  
7. Unary Division  
8. Palindrome  
9. W2W where W ∈ {0,1}*
10. Unary to Bianry

Enter a number between 1–9 to choose the machine, then type your input tape (e.g., `111101` or `000111222`), and the simulator will print the tape step-by-step, finishing with ACCEPT or REJECT.

## 📄 .tm File Format

Each `.tm` file defines a Turing Machine.  
It must contain the start, accept, and reject states at the top, followed by a list of transitions.  
Each transition follows this format:

`<current_state> <read_symbol> -> <next_state> <write_symbol> <direction>`

- Use `_` to represent a blank symbol  
- Direction is either `L` (left) or `R` (right)

### Example: `machines/ones_complement.tm`

start: q0  
accept: ACCEPT  
reject: REJECT  

q0 0 -> q0 1 R  
q0 1 -> q0 0 R  
q0 _ -> ACCEPT _ R

## ✍️ Adding a New Machine

1. Create a `.tm` file under the `machines/` folder.
2. Add a new case in the menu section of `main.cpp` with its path and name.
3. Recompile using `make all`.

---

Happy simulating!
