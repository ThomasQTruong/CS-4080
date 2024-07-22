# CS 4080
- by Thomas Truong

## Instructions
- Implement 4 versions of a matrix program and write a driver to test 3 different operations with matrices.
- The matrix operations that you should include are Addition, Subtraction and Multiplication.
- The driver can be as simple as asking the user to enter two matrices and then presenting a simple menu that allows the user to select the operation they want to test.
  - Have the menu in a loop so that the user can test any other operation unless they choose to exit the menu.
  - Also, provide the user an option to select two new matrices. Make sure that the result of every operation is printed out after the operation is chosen.
- The matrices should hold float values, so please use float data types in all versions.
- Also, make sure that you do the check based on sizes of the matrices if the chosen operation is permissible on the two matrices entered by the user.
- The matrices can be entered by the user by first entering the size of each matrix followed by the element.
  - Alternatively, you can also provide the user the option of reading both matrices from a simple text file, where the first line is the size of the matrix and then followed by the elements of the matrix.
- The four versions are as follows:
  1. C/C++ version that uses a regular stack dynamic 2D array for representing the matrices. Limit the size of array to 100x100. Add appropriate functions to do the operations of addition, subtraction and multiplication of two matrices.
  2. C/C++ version that uses a pointer to a pointer (**p) that is allocated memory using new or malloc to create the 2D matrices. Provide 3 functions, one for addition, subtraction and multiplication respectively, that take in the two matrices and return the result back (as a new matrix which is also declared as a pointer to a pointer)
  3. C/C++ version that uses a pointer to a pointer as a private data in a class called matrix (create this class) and add overloaded operator functions (+ for addition, - for subtraction and * for multiplication) to the class for doing the matrix operations. Add other appropriate member functions, like constructors, destructors and any other helper functions.
  4. Create a Java Class called matrix and uses arrays and add appropriate methods for the matrix operations.