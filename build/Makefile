# By Thomas Truong
# Quickly compiles and links every .cpp file in the
# src folder, and places them into the bin folder.

# Directory paths.
SRC = ../src/
BIN = ../bin/

# Every object file needed for linking.
OBJECTS = stack_matrix_calculator.o
# The path of every object file.
PATHS = $(foreach path, $(OBJECTS), $(BIN)$(path))

# Function names to run.
all: main

# Functions.
main: $(PATHS)
	g++ -o $(BIN)$(basename $^) $^

# Compile .cpp files to .o files.
$(BIN)%.o: $(SRC)%.cc
	g++ -c -o $@ $<

# make run.
run1:
	make clean
	make
	$(BIN)stack_matrix_calculator

# make clean.
clean:
	rm -f $(BIN)*
