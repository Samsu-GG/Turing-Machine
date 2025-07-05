# Makefile in root directory

CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC_DIR = src
SRC = $(SRC_DIR)/main.cpp $(SRC_DIR)/TuringMachine.cpp $(SRC_DIR)/Loader.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = TuringSimulator

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

