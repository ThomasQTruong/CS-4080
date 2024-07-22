/**
 * pointer_matrix_calculator.cc
 * Basic calculator for matrices which use pointers and malloc for declaration.
 * Possible operations are addition, subtraction, and multiplication.
 *
 * Copyright (c) 2024, Thomas Truong.
 */

#include <iostream>


const int MIN_SIZE = 1;
const int MAX_SIZE = 100;


void getDimensions(int matrixNumber, int dimensions[2]);
float** createMatrix(const int dimensions[2]);
void deleteMatrix(float** matrix, int height);
void getMatrixValues(const int matrixNumber, float** matrix, const int dimensions[2]);
void printMatrix(const int matrixNumber, float** matrix, const int dimensions[2]);
void printMatrix(float** matrix, const int dimensions[2]);
void printMenu();
float** getSum(float** matrix1, float** matrix2, const int dimensions1[2], const int dimensions2[2]);
float** getDifference(float** matrix1, float** matrix2, const int dimensions1[2],
                    const int dimensions2[2]);
float** getProduct(float** matrix1, float** matrix2, const int dimensions1[2], const int dimensions2[2]);


int main(void) {
  std::cout << "[ Pointer Matrix Calculator ]" << std::endl;

  // Get dimensions and allocate matrix.
  int dimensions1[2] = {0, 0};
  int dimensions2[2] = {0, 0};
  getDimensions(1, dimensions1);
  getDimensions(2, dimensions2);
  float** matrix1 = createMatrix(dimensions1);
  float** matrix2 = createMatrix(dimensions2);

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
      case 1: {  // Print sum.
        float** sum = getSum(matrix1, matrix2, dimensions1, dimensions2);

        if (sum != nullptr) {
          std::cout << "[[[ Sum ]]]" << std::endl;
          printMatrix(sum, dimensions1);
        } else {  // Invalid dimensions.
          std::cout << "[Sum] ERROR: dimensions are not matching." << std::endl;
        }
        break;
      }
      case 2: {  // Print difference.
        float** difference = getDifference(matrix1, matrix2, dimensions1, dimensions2);

        if (difference != nullptr) {
          std::cout << "[[[ Difference ]]]" << std::endl;
          printMatrix(difference, dimensions1);
        } else {  // Invalid dimensions.
          std::cout << "[Difference] ERROR: dimensions are not matching." << std::endl;
        }
        break;
      }
      case 3: {  // Print product.
        float** product = getProduct(matrix1, matrix2, dimensions1, dimensions2);

        if (product != nullptr) {
          std::cout << "[[[ Product ]]]" << std::endl;
          int dimensions[2] = {dimensions1[1], dimensions2[0]};
          printMatrix(product, dimensions);
        } else {  // Invalid dimensions.
          std::cout << "[Product] ERROR: matrix 1's width does not match matrix 2's height."
                    << std::endl;
        }
        break;
      }
      case 4: {  // Print matrix 1.
        printMatrix(1, matrix1, dimensions1);
        break;
      }
      case 5: {  // Print matrix 2.
        printMatrix(2, matrix2, dimensions2);
        break;
      }
      case 6: {  // Re-input matrix 1.
        getDimensions(1, dimensions1);
        getMatrixValues(1, matrix1, dimensions1);
        printMatrix(1, matrix1, dimensions1);
        break;
      }
      case 7: {  // Re-input matrix 2.
        getDimensions(2, dimensions2);
        getMatrixValues(2, matrix2, dimensions2);
        printMatrix(2, matrix2, dimensions2);
        break;
      }
      case 8: {  // Exit program.
        exit = true;
        break;
      }
    }
  } while (!exit);

  // User exited; unallocate matrices.
  deleteMatrix(matrix1, dimensions1[1]);
  deleteMatrix(matrix2, dimensions2[1]);
  std::cout << "Goodbye!" << std::endl;

  return 0;
}


/**
 * Frees the allocated memory for the matrix.
 * 
 * @param matrix - the matrix to unallocate memory for.
 * @param height - the height of the matrix.
 */
void deleteMatrix(float** matrix, int height) {
  // For each row, delete array.
  for (int i = 0; i < height; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
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
 * Allocates the matrix.
 * 
 * @param dimensions - the matrix's dimensions.
 */
float** createMatrix(const int dimensions[2]) {
  float** matrix = new float*[dimensions[1]];
  // Create array inside of array.
  for (int i = 0; i < dimensions[1]; ++i) {
    matrix[i] = new float[dimensions[0]];
  }

  return matrix;
}


/**
 * Asks user to input values for the matrix.
 * 
 * @param matrixNumber - the ID number of the matrix.
 * @param matrix - the matrix to fill out with user input.
 * @param dimensions - the dimensions of the matrix.
 */
void getMatrixValues(const int matrixNumber, float** matrix, const int dimensions[2]) {
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
 * Prints out the matrix with the name displayed.
 * 
 * @param matrixNumber - the ID number of the matrix.
 * @param matrix - the matrix to print out.
 * @param dimensions - the dimensions of the matrix.
 */
void printMatrix(const int matrixNumber, float** matrix, const int dimensions[2]) {
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
 * Prints out the matrix with no name display.
 * 
 * @param matrix - the matrix to print out.
 * @param dimensions - the dimensions of the matrix.
 */
void printMatrix(float** matrix, const int dimensions[2]) {
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
float** getSum(float** matrix1, float** matrix2, const int dimensions1[2], const int dimensions2[2]) {
  // Check for same size.
  if (dimensions1[0] != dimensions2[0] || dimensions1[1] != dimensions2[1]) {
    return nullptr;
  }

  // Add each position from both matrices with each other.
  float** sum = createMatrix(dimensions1);
  for (int i = 0; i < dimensions1[1]; ++i) {
    for (int j = 0; j < dimensions1[0]; ++j) {
      sum[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }

  return sum;
}


/**
 * Calculates and prints the difference of the two matrices.
 * 
 * @param matrix1 - the first matrix.
 * @param matrix2 - the second matrix.
 * @param dimensions1 - the dimensions of the first matrix.
 * @param dimensions2 - the dimensions of the second matrix.
 */
float** getDifference(float** matrix1, float** matrix2, const int dimensions1[2],
                    const int dimensions2[2]) {
  // Check for same size.
  if (dimensions1[0] != dimensions2[0] || dimensions1[1] != dimensions2[1]) {
    return nullptr;
  }

  // Subtract each position from both matrices with each other.
  float** difference = createMatrix(dimensions1);
  for (int i = 0; i < dimensions1[1]; ++i) {
    for (int j = 0; j < dimensions1[0]; ++j) {
      difference[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }

  return difference;
}


/**
 * Calculates and prints the product of the two matrices.
 * 
 * @param matrix1 - the first matrix.
 * @param matrix2 - the second matrix.
 * @param dimensions1 - the dimensions of the first matrix.
 * @param dimensions2 - the dimensions of the second matrix.
 */
float** getProduct(float** matrix1, float** matrix2, const int dimensions1[2], const int dimensions2[2]) {
  // Check if matrix1's width == matrix2's height.
  if (dimensions1[0] != dimensions2[1]) {
    return nullptr;
  }

  // Matrix 1's height & matrix 2's width = new matrix's dimensions.
  int dimensions[2] = {dimensions1[1], dimensions2[0]};
  float** product = createMatrix(dimensions);

  // For each row for matrix 1.
  for (int i = 0; i < dimensions1[1]; ++i) {
    // For each column for matrix 2.
    for (int k = 0; k < dimensions2[0]; ++k) {
      float sum = 0;
      // For each column in row for matrix 1.
      for (int j = 0; j < dimensions1[0]; ++j) {
        sum += matrix1[i][j] * matrix2[j][k];
      }
      product[i][k] = sum;
    }
  }

  return product;
}
