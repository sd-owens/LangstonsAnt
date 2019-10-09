#/**********************************************************************************
# * Program name: Langston's Ant
# * Author: Steven Owens
# * Date: 10/8/2019
#  * Description:  Langston's ant is a two-dimensional universal Turing machine
#  *               invented by Chris Langston in 1986.  It is a cellular automation
#  *               created on a black and white game board re-created in c++ using
#  *               in the console using the char '#' for black and ' ' for white.
#  *               The game board implementation is a dynamically allocated 2D array
#  *               of characters on the heap. The user is prompted by a console menu
#  *               for 5 integers (rows, columns, steps, ant starting row and ant
#  *               starting column) as inputs to setup the game parameters.  Once
#  *               the user is satisfied with the setup, the simulations continues
#  *               until the number of steps reaches 0.  An additional replay feature
#  *               allows the user to run the simulation again.
#  *********************************************************************************/

# makefile syntax adapted from example provided TA Harlan James <waldroha@oregonstat.edu>

# Project Name
PROJ = LangstonsAnt

# Compiler
CXX = g++

# Compiler C++ Version
CXXVER = -std=c++11

# Compiler Flags
CXXFLAGS = -Wall -g

# Source Files
SRC = main.cpp
SRC += Ant.cpp AntGame.cpp Board.cpp Menu.cpp validInput.cpp 

# Create an object for each source file
OBJ = $(SRC:.cpp=.o)

# Output Binary
BIN = $(PROJ).bin

# Valgrind Options
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

# Names of tags that aren't actually files. Without this, if there were ever a
# file in the directory with these names they would never run.
#
# Why? Because Make is checking to see if these files exist. If they already do
# it skips them!
.PHONY: default debug clean zip

# Default Behavior:
#     1. Remove everything to start from screatch
#     2. Compile the binary
#     3. Run it through valgrind for quicker debugging
#
default: clean $(BIN) #debug

# Order assuming no files exist:
#     1. Each .o file
#     2. Binary
#     3. Valgrind
#
# Special Symbols:
#     @     Suppresses the command from being printed to the terminal)
#     $@    Name of tag
#     $^    Name of dependency
debug: $(BIN)
	@valgrind $(VOPT) ./$(BIN)

$(BIN): $(OBJ)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CXXVER) $(CFLAGS) -c $^

zip:
	zip $(PROJ).zip *.cpp *.hpp makefile

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(BIN)"
	@rm -f *.o $(BIN)