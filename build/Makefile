# By Thomas Truong
# Quickly compiles and links every .cpp file in the
# src folder, and places them into the bin folder.

# Directory paths.
SRC = ../src/
BIN = ../bin/

# Function names to run.
all: stack_matrix_calculator pointer_matrix_calculator class_matrix_calculator

# Functions.
stack_matrix_calculator: $(BIN)stack_matrix_calculator.o
	g++ -o $(BIN)$(basename $^) $^

pointer_matrix_calculator: $(BIN)pointer_matrix_calculator.o
	g++ -o $(BIN)$(basename $^) $^

class_matrix_calculator: $(BIN)class_matrix_calculator.o
	g++ -o $(BIN)$(basename $^) $^

# Compile .cpp files to .o files.
$(BIN)%.o: $(SRC)%.cc
	g++ -c -o $@ $<

# make run.
run1:
	make clean
	make stack_matrix_calculator
	$(BIN)stack_matrix_calculator

# make run.
run2:
	make clean
	make pointer_matrix_calculator
	$(BIN)pointer_matrix_calculator

# make run.
run3:
	make clean
	make class_matrix_calculator
	$(BIN)class_matrix_calculator

# make clean.
clean:
	rm -f $(BIN)*
