/**
 * class_matrix_calculator.cc
 * Basic calculator for matrices (...).
 * Possible operations are addition, subtraction, and multiplication.
 *
 * Copyright (c) 2024, Thomas Truong.
 */

#include <iostream>

const int MIN_SIZE = 1;
const int MAX_SIZE = 100;


/**
 * Asks user to input the dimensions of the matrices.
 * 
 * @param dimensions - the array that will contain the user's inputs.
 */
void getDimensions(int dimensions[2]) {
  std::cout << "Enter the dimensions of the matrices." << std::endl;
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


int main(void) {
  std::cout << "[ Class Matrix Calculator ]" << std::endl;

  int dimensions[2] = {0, 0};
  getDimensions(dimensions);

  return 0;
}
