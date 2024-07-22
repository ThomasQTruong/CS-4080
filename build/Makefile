# By Thomas Truong
# Quickly compiles and links every .cpp file in the
# src folder, and places them into the bin folder.

# Directory paths.
SRC = ../src/
BIN = ../bin/

# Function names to run.
all: stack_matrix_calculator pointer_matrix_calculator class_matrix_calculator Matrix

# Functions.
stack_matrix_calculator: $(BIN)stack_matrix_calculator.o
	g++ -o $(BIN)$(basename $^) $^

pointer_matrix_calculator: $(BIN)pointer_matrix_calculator.o
	g++ -o $(BIN)$(basename $^) $^

class_matrix_calculator: $(BIN)class_matrix_calculator.o
	g++ -o $(BIN)$(basename $^) $^

Matrix:
	javac -d $(BIN) $(SRC)Matrix.java

# Compile .cpp files to .o files.
$(BIN)%.o: $(SRC)%.cc
	g++ -c -o $@ $<

# Make and run stack_matrix_calculator.
run1:
	make clean
	make stack_matrix_calculator
	$(BIN)stack_matrix_calculator

# Make and run pointer_matrix_calculator.
run2:
	make clean
	make pointer_matrix_calculator
	$(BIN)pointer_matrix_calculator

# Make and run class_matrix_calculator.
run3:
	make clean
	make class_matrix_calculator
	$(BIN)class_matrix_calculator

# Make and run Matrix.java.
run4:
	make clean
	make Matrix
	java -cp $(BIN) Matrix

# make clean.
clean:
	rm -f $(BIN)*
	rm -rf $(BIN)*.class
