/**
 * class_matrix_calculator.cc
 * Basic calculator for matrices which uses a class.
 * Possible operations are addition, subtraction, and multiplication.
 *
 * Copyright (c) 2024, Thomas Truong.
 */

#include <iostream>


const int MIN_SIZE = 1;
const int MAX_SIZE = 100;


void printMenu();


class Matrix {
 public:
  /**
   * Constructor.
   *
   * @param id - the ID number of the matrix.
   * @param width - the width of the matrix.
   * @param height - the height of the matrix.
   * @throws std::invalid_argument - invalid width/height error.
   */
  Matrix(int id, int width, int height) {
    // Invalid width/height.
    if (width < MIN_SIZE || width > MAX_SIZE) {
      throw std::invalid_argument("Width out of range: " + std::to_string(MIN_SIZE)
                                  + " >= width <= " + std::to_string(MAX_SIZE));
    }
    if (height < MIN_SIZE || height > MAX_SIZE) {
      throw std::invalid_argument("Height out of range: " + std::to_string(MIN_SIZE)
                                  + " >= height <= " + std::to_string(MAX_SIZE));
    }

    // Valid width/height.
    _id = id;
    _width = width;
    _height = height;

    createMatrix();
  }

  /**
   * Constructor.
   * 
   * @param id - the ID number of the matrix.
   */
  explicit Matrix(int id) {
    _id = id;

    getDimensions();
  }


  /**
   * Destructor.
   */
  ~Matrix() {
    // Data doesn't exist.
    if (_data == nullptr) {
      return;
    }

    // Data exists; for each row, delete array.
    for (int i = 0; i < _height; ++i) {
      delete[] _data[i];
    }
    delete[] _data;
  }


  /**
   * Retrieves the matrix's ID number.
   * 
   * @return int - the matrix's ID number.
   */
  int getID() {
    return _id;
  }


  /**
   * Asks user to input the dimensions of the matrices.
   * 
   * @param matrixNumber - the ID number of the matrix.
   * @param dimensions - the array that will contain the user's inputs.
   */
  void getDimensions() {
    std::cout << "Enter the dimensions for matrix " << _id << " (width x height)." << std::endl;
    bool valid = false;

    // Get input and repeat if invalid (invalid = MIN_SIZE < x > MAX_SIZE).
    do {
      std::cout << "Dimensions <x y>: ";
      std::cin >> _width;
      std::cin >> _height;

      // Validate input.
      if (_width < MIN_SIZE || _height < MIN_SIZE) {
        std::cout << "Invalid size, min is " << MIN_SIZE << std::endl;
      } else if (_width > MAX_SIZE || _height > MAX_SIZE) {
        std::cout << "Invalid size, max is " << MAX_SIZE << std::endl;
      } else {
        valid = true;
      }
    } while (!valid);

    createMatrix();
  }


  /**
   * Asks user to input values for the matrix.
   */
  void getMatrixValues() {
    std::cout << "===== Matrix " << _id << " =====" << std::endl;
    std::cout << "Enter " << _width * _height << " value(s) individually or seperated by space."
              << std::endl;

    // Take user input for each valid slot.
    for (int i = 0; i < _height; ++i) {
      for (int j = 0; j < _width; ++j) {
        std::cin >> _data[i][j];
      }
    }
  }


  /**
   * Operator overload for addition.
   * 
   * @param matrix - the rhs matrix to be added.
   * @param Matrix - the sum matrix.
   * @throws std::string - invalid dimensions.
   */
  Matrix operator+(const Matrix &matrix) {
    // Check for same size.
    if (_width != matrix._width || _height != matrix._height) {
      throw(std::string("[Sum] ERROR: dimensions are not matching."));
    }

    // Add each position from both matrices with each other.
    Matrix sum = Matrix(3, _width, _height);
    for (int i = 0; i < _height; ++i) {
      for (int j = 0; j < _width; ++j) {
        sum._data[i][j] = _data[i][j] + matrix._data[i][j];
      }
    }

    return sum;
  }


  /**
   * Operator overload for subtraction.
   * 
   * @param matrix - the rhs matrix to be subtracted.
   * @param Matrix - the difference matrix.
   * @throws std::string - invalid dimensions.
   */
  Matrix operator-(const Matrix &matrix) {
    // Check for same size.
    if (_width != matrix._width || _height != matrix._height) {
      throw(std::string("[Difference] ERROR: dimensions are not matching."));
    }

    // Subtract each position from both matrices with each other.
    Matrix difference = Matrix(4, _width, _height);
    for (int i = 0; i < _height; ++i) {
      for (int j = 0; j < _width; ++j) {
        difference._data[i][j] = _data[i][j] - matrix._data[i][j];
      }
    }

    return difference;
  }


  /**
   * Operator overload for multiplication.
   * 
   * @param matrix - the rhs matrix to be multiplied.
   * @param Matrix - the product matrix.
   * @throws std::string - invalid dimensions.
   */
  Matrix operator*(const Matrix &matrix) {
    // Check for same size.
    if (_width != matrix._height) {
      throw(std::string("[Product] ERROR: matrix 1's width does not match matrix 2's height."));
    }

    // Matrix 1's height & matrix 2's width = new matrix's dimensions.
    Matrix product = Matrix(5, _height, matrix._width);

    // For each row for matrix 1.
    for (int i = 0; i < _height; ++i) {
      // For each column for matrix 2.
      for (int k = 0; k < matrix._width; ++k) {
        int sum = 0;
        // For each column in row for matrix 1.
        for (int j = 0; j < _width; ++j) {
          sum += _data[i][j] * matrix._data[j][k];
        }
        product._data[i][k] = sum;
      }
    }

    return product;
  }


 private:
  int _id;
  int _width;
  int _height;
  int** _data;


  /**
   * Allocates the matrix.
   */
  void createMatrix() {
    _data = new int*[_height];
    // Create array inside of array.
    for (int i = 0; i < _height; ++i) {
      _data[i] = new int[_width];
    }
  }


  /**
   * Operator overloading for prints.
   * 
   * @param os - the output stream.
   * @param matrix - the matrix to print.
   */
  friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    std::string output = "";
    // For every row.
    for (int i = 0; i < matrix._height; ++i) {
      // For every column.
      for (int j = 0; j < matrix._width; ++j) {
        output += std::to_string(matrix._data[i][j]) + " ";
      }
      output += "\n";
    }
    return os << output;
  }
};


int main(void) {
  std::cout << "[ Class Matrix Calculator ]" << std::endl;

  // Get dimensions and create matrix.
  Matrix matrix1 = Matrix(1);
  Matrix matrix2 = Matrix(2);

  // Get values for matrix 1.
  std::cout << std::endl;
  matrix1.getMatrixValues();
  std::cout << matrix1;

  // Get values for matrix 2.
  std::cout << std::endl;
  matrix2.getMatrixValues();
  std::cout << matrix2;

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
      case 1: {  // Calculate and print sum.
        try {
          Matrix sum = matrix1 + matrix2;
          std::cout << "[[[ Sum ]]]" << std::endl;
          std::cout << sum;
        } catch (std::string errorMessage) {
          std::cout << errorMessage << std::endl;
        }
        break;
      }
      case 2: {  // Calculate and print difference.
        try {
          Matrix difference = matrix1 - matrix2;
          std::cout << "[[[ Difference ]]]" << std::endl;
          std::cout << difference;
        } catch (std::string errorMessage) {
          std::cout << errorMessage << std::endl;
        }
        break;
      }
      case 3: {  // Calculate and print product.
        try {
          Matrix product = matrix1 * matrix2;
          std::cout << "[[[ Product ]]]" << std::endl;
          std::cout << product;
        } catch (std::string errorMessage) {
          std::cout << errorMessage << std::endl;
        }
        break;
      }
      case 4: {  // Print matrix 1.
        std::cout << "----- Matrix " << std::to_string(matrix1.getID()) << " -----\n";
        std::cout << matrix1;
        break;
      }
      case 5: {  // Print matrix 2.
        std::cout << "----- Matrix " << std::to_string(matrix2.getID()) << " -----\n";
        std::cout << matrix2;
        break;
      }
      case 6: {  // Re-input matrix 1.
        matrix1.getDimensions();
        matrix1.getMatrixValues();
        std::cout << matrix1;
        break;
      }
      case 7: {  // Re-input matrix 2.
        matrix2.getDimensions();
        matrix2.getMatrixValues();
        std::cout << matrix2;
        break;
      }
      case 8: {  // Exit program.
        exit = true;
        break;
      }
    }
  } while (!exit);

  // User exited; unallocate matrices.
  std::cout << "Goodbye!" << std::endl;

  return 0;
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
