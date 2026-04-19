# Compiler
CXX = g++

# Flags
CXXFLAGS = -std=c++17 -Wall -Iinclude

# Source files
SRC = $(wildcard src/*.cpp)

# Object files go into bin/obj/
OBJ = $(patsubst src/%.cpp, bin/obj/%.o, $(SRC))

# Output binary
TARGET = bin/snake

all: $(TARGET)

# Link
$(TARGET): $(OBJ)
	mkdir -p bin
	$(CXX) $(OBJ) -o $(TARGET) -lsfml-graphics -lsfml-window -lsfml-system

# Compile (src → bin/obj)
bin/obj/%.o: src/%.cpp
	mkdir -p bin/obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf bin