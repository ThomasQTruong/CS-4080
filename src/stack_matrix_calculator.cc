/**
 * stack_matrix_calculator.cc
 * Basic calculator for matrices which are regular stack dyanmic 2D arrays.
 * Possible operations are addition, subtraction, and multiplication.
 *
 * Copyright (c) 2024, Thomas Truong.
 */

#include <iostream>

const int MIN_SIZE = 1;
const int MAX_SIZE = 100;


void getDimensions(int matrixNumber, int dimensions[2]);
void getMatrixValues(const int matrixNumber, int matrix[MAX_SIZE][MAX_SIZE],
                     const int dimensions[2]);
void printMatrix(const int matrixNumber, const int matrix[MAX_SIZE][MAX_SIZE],
                 const int dimensions[2]);
void printSum(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE],
              const int dimensions1[2], const int dimensions2[2]);
void printDifference(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE],
                     const int dimensions1[2], const int dimensions2[2]);
void printProduct(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE],
                  const int dimensions1[2], const int dimensions2[2]);
void printMenu();


int main(void) {
  std::cout << "[ Stack Matrix Calculator ]" << std::endl;

  // Get dimensions.
  int dimensions1[2] = {0, 0};
  int dimensions2[2] = {0, 0};
  getDimensions(1, dimensions1);
  getDimensions(2, dimensions2);

  int matrix1[MAX_SIZE][MAX_SIZE];
  int matrix2[MAX_SIZE][MAX_SIZE];

  // Get values for matrix 1.
  std::cout << std::endl;
  getMatrixValues(1, matrix1, dimensions1);
  printMatrix(1, matrix1, dimensions1);

  // Get values for matrix 2.
  std::cout << std::endl;
  getMatrixValues(2, matrix2, dimensions2);
  printMatrix(2, matrix2, dimensions2);

  bool exit = false;
  int choice = 0;
  do {
    // Get user's choice.
    std::cout << std::endl;
    printMenu();
    std::cout << "Input: ";
    std::cin >> choice;

    // Process choice.
    std::cout << std::endl;
    switch (choice) {
      case 1:  // Print sum.
        printSum(matrix1, matrix2, dimensions1, dimensions2);
        break;
      case 2:  // Print difference.
        printDifference(matrix1, matrix2, dimensions1, dimensions2);
        break;
      case 3:  // Print product.
        printProduct(matrix1, matrix2, dimensions1, dimensions2);
        break;
      case 4:  // Print matrix 1.
        printMatrix(1, matrix1, dimensions1);
        break;
      case 5:  // Print matrix 2.
        printMatrix(2, matrix2, dimensions2);
        break;
      case 6:  // Re-input matrix 1.
        getDimensions(1, dimensions1);
        getMatrixValues(1, matrix1, dimensions1);
        printMatrix(1, matrix1, dimensions1);
        break;
      case 7:  // Re-input matrix 2.
        getDimensions(2, dimensions2);
        getMatrixValues(2, matrix2, dimensions2);
        printMatrix(2, matrix2, dimensions2);
        break;
      case 8:  // Exit program.
        exit = true;
        break;
    }
  } while (!exit);

  // User exited.
  std::cout << "Goodbye!" << std::endl;

  return 0;
}


/**
 * Asks user to input the dimensions of the matrices.
 * 
 * @param matrixNumber - the ID number of the matrix.
 * @param dimensions - the array that will contain the user's inputs.
 */
void getDimensions(int matrixNumber, int dimensions[2]) {
  std::cout << "Enter the dimensions for matrix " << matrixNumber
            << " (width x height)." << std::endl;
  bool valid = false;

  // Get input and repeat if invalid (invalid = MIN_SIZE < x > MAX_SIZE).
  do {
    std::cout << "Dimensions <x y>: ";
    std::cin >> dimensions[0];
    std::cin >> dimensions[1];

    // Validate input.
    if (dimensions[0] < MIN_SIZE || dimensions[1] < MIN_SIZE) {
      std::cout << "Invalid size, min is " << MIN_SIZE << std::endl;
    } else if (dimensions[0] > MAX_SIZE || dimensions[1] > MAX_SIZE) {
      std::cout << "Invalid size, max is " << MAX_SIZE << std::endl;
    } else {
      valid = true;
    }
  } while (!valid);
}


/**
 * Asks user to input values for the matrix.
 * 
 * @param matrixNumber - the ID number of the matrix.
 * @param matrix - the matrix to fill out with user input.
 * @param dimensions - the dimensions of the matrix.
 */
void getMatrixValues(const int matrixNumber, int matrix[MAX_SIZE][MAX_SIZE],
                     const int dimensions[2]) {
  std::cout << "===== Matrix " << matrixNumber << " =====" << std::endl;
  std::cout << "Enter " << dimensions[0] * dimensions[1] << " value(s) individually or seperated by space."
            << std::endl;

  // Take user input for each valid slot.
  for (int i = 0; i < dimensions[1]; ++i) {
    for (int j = 0; j < dimensions[0]; ++j) {
      std::cin >> matrix[i][j];
    }
  }
}


/**
 * Prints out the matrix.
 * 
 * @param matrixNumber - the ID number of the matrix.
 * @param matrix - the matrix to print out.
 * @param dimensions - the dimensions of the matrix.
 */
void printMatrix(const int matrixNumber, const int matrix[MAX_SIZE][MAX_SIZE],
                 const int dimensions[2]) {
  std::cout << "----- Matrix " << matrixNumber << " -----" << std::endl;
  // For every row.
  for (int i = 0; i < dimensions[1]; ++i) {
    // For every column.
    for (int j = 0; j < dimensions[0]; ++j) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


/**
 * Prints the menu.
 */
void printMenu() {
  std::cout << "=-=-=- Menu -=-=-=" << std::endl;
  std::cout << "[1] Print Sum" << std::endl;
  std::cout << "[2] Print Difference" << std::endl;
  std::cout << "[3] Print Product" << std::endl;
  std::cout << "[4] Print Matrix 1" << std::endl;
  std::cout << "[5] Print Matrix 2" << std::endl;
  std::cout << "[6] Re-input Matrix 1" << std::endl;
  std::cout << "[7] Re-input Matrix 2" << std::endl;
  std::cout << "[8] Exit" << std::endl;
}


/**
 * Calculates and prints the sum of the two matrices.
 * 
 * @param matrix1 - the first matrix.
 * @param matrix2 - the second matrix.
 * @param dimensions1 - the dimensions of the first matrix.
 * @param dimensions2 - the dimensions of the second matrix.
 */
void printSum(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE],
              const int dimensions1[2], const int dimensions2[2]) {
  // Check for same size.
  if (dimensions1[0] != dimensions2[0] || dimensions1[1] != dimensions2[1]) {
    std::cout << "[Sum] ERROR: dimensions are not matching." << std::endl;
    return;
  }

  // Add each position from both matrices with each other.
  std::cout << "[[[ Sum ]]]" << std::endl;
  for (int i = 0; i < dimensions1[1]; ++i) {
    for (int j = 0; j < dimensions1[0]; ++j) {
      std::cout << matrix1[i][j] + matrix2[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


/**
 * Calculates and prints the difference of the two matrices.
 * 
 * @param matrix1 - the first matrix.
 * @param matrix2 - the second matrix.
 * @param dimensions1 - the dimensions of the first matrix.
 * @param dimensions2 - the dimensions of the second matrix.
 */
void printDifference(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE],
                     const int dimensions1[2], const int dimensions2[2]) {
  // Check for same size.
  if (dimensions1[0] != dimensions2[0] || dimensions1[1] != dimensions2[1]) {
    std::cout << "[Difference] ERROR: dimensions are not matching." << std::endl;
    return;
  }

  // Subtract each position from both matrices with each other.
  std::cout << "[[[ Difference ]]]" << std::endl;
  for (int i = 0; i < dimensions1[1]; ++i) {
    for (int j = 0; j < dimensions1[0]; ++j) {
      std::cout << matrix1[i][j] - matrix2[i][j] << " ";
    }
    std::cout << std::endl;
  }
}


/**
 * Calculates and prints the product of the two matrices.
 * 
 * @param matrix1 - the first matrix.
 * @param matrix2 - the second matrix.
 * @param dimensions1 - the dimensions of the first matrix.
 * @param dimensions2 - the dimensions of the second matrix.
 */
void printProduct(const int matrix1[MAX_SIZE][MAX_SIZE], const int matrix2[MAX_SIZE][MAX_SIZE],
                  const int dimensions1[2], const int dimensions2[2]) {
  // Check if matrix1's width == matrix2's height.
  if (dimensions1[0] != dimensions2[1]) {
    std::cout << "[Product] ERROR: matrix 1's width does not match matrix 2's height." << std::endl;
  }

  std::cout << "[[[ Product ]]]" << std::endl;
  // For each row for matrix 1.
  for (int i = 0; i < dimensions1[1]; ++i) {
    // For each column for matrix 2.
    for (int k = 0; k < dimensions2[0]; ++k) {
      int sum = 0;
      // For each column in row for matrix 1.
      for (int j = 0; j < dimensions1[0]; ++j) {
        sum += matrix1[i][j] * matrix2[j][k];
      }
      std::cout << sum << " ";
    }
    std::cout << std::endl;
  }
}
