import java.util.Scanner;

/**
 * <p>
 * Matrix.java
 * Basic calculator for matrices which uses a class.
 * Possible operations are addition, subtraction, and multiplication.
 * Java variant of class_matrix_calculator.cc.
 *
 * Copyright (c) 2024, Thomas Truong.
 * </p>
 */
public class Matrix {
  public static final int MIN_SIZE = 1;
  public static final int MAX_SIZE = 100;
  public static Scanner intInput = new Scanner(System.in);
  public static Scanner floatInput = new Scanner(System.in);


  private int _id;
  private int _width;
  private int _height;
  private float[][] _data;


  /**
   * Constructor.
   *
   * @param id - the ID number of the matrix.
   * @param width - the width of the matrix.
   * @param height - the height of the matrix.
   * @throws IllegalArgumentException - invalid width/height error.
   */
  public Matrix(int id, int width, int height) throws IllegalArgumentException {
    // Invalid width/height.
    if (width < MIN_SIZE || width > MAX_SIZE) {
      throw new IllegalArgumentException("Width out of range: "
                                         + MIN_SIZE + " >= width <= " + MAX_SIZE);
    }
    if (height < MIN_SIZE || height > MAX_SIZE) {
      throw new IllegalArgumentException("Height out of range: "
                                         + MIN_SIZE + " >= height <= " + MAX_SIZE);
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
  public Matrix(int id) {
    _id = id;

    getDimensions();
  }


  /**
   * Retrieves the matrix's ID number.
   *
   * @return int - the matrix's ID number.
   */
  public int getID() {
    return _id;
  }


  /**
   * Asks user to input the dimensions of the matrices.
   */
  public void getDimensions() {
    System.out.println("Enter the dimensions for matrix " + _id + " (width x height).");
    boolean valid = false;

    // Get input and repeat if invalid (invalid = MIN_SIZE < x > MAX_SIZE).
    do {
      System.out.print("Dimensions <x y>: ");
      _width = intInput.nextInt();
      _height = intInput.nextInt();

      // Validate input.
      if (_width < MIN_SIZE || _height < MIN_SIZE) {
        System.out.println("Invalid size, min is " + MIN_SIZE);
      } else if (_width > MAX_SIZE || _height > MAX_SIZE) {
        System.out.println("Invalid size, max is " + MAX_SIZE);
      } else {
        valid = true;
      }
    } while (!valid);

    createMatrix();
  }


  /**
   * Asks user to input values for the matrix.
   */
  public void getMatrixValues() {
    System.out.println("===== Matrix " + _id + " =====");
    System.out.println("Enter " + _width * _height
                       + " value(s) individually or seperated by space.");

    // Take user input for each valid slot.
    for (int i = 0; i < _height; ++i) {
      for (int j = 0; j < _width; ++j) {
        _data[i][j] = floatInput.nextFloat();
      }
    }
  }


  /**
   * Adds two matrices together.
   *
   * @param matrix - the rhs matrix.
   * @return Matrix - the sum matrix.
   * @throws Exception - invalid dimensions.
   */
  public Matrix add(Matrix matrix) throws Exception {
    // Check for same size.
    if (_width != matrix._width || _height != matrix._height) {
      throw new Exception("[Sum] ERROR: dimensions are not matching.");
    }

    // Add each position from both matrices with each other.
    Matrix sum = new Matrix(3, _width, _height);
    for (int i = 0; i < _height; ++i) {
      for (int j = 0; j < _width; ++j) {
        sum._data[i][j] = _data[i][j] + matrix._data[i][j];
      }
    }

    return sum;
  }


  /**
   * Subtracts two matrices with each other.
   *
   * @param matrix - the rhs matrix.
   * @return Matrix - the difference matrix.
   * @throws Exception - invalid dimensions.
   */
  public Matrix subtract(Matrix matrix) throws Exception {
    // Check for same size.
    if (_width != matrix._width || _height != matrix._height) {
      throw new Exception("[Difference] ERROR: dimensions are not matching.");
    }

    // Subtract each position from both matrices with each other.
    Matrix difference = new Matrix(4, _width, _height);
    for (int i = 0; i < _height; ++i) {
      for (int j = 0; j < _width; ++j) {
        difference._data[i][j] = _data[i][j] - matrix._data[i][j];
      }
    }

    return difference;
  }


  /**
   * Multiplies two matrices together.
   *
   * @param matrix - the rhs matrix to be multiplied.
   * @return Matrix - the product matrix.
   * @throws Exception - invalid dimensions.
   */
  public Matrix multiply(Matrix matrix) {
    // Check for same size.
    if (_width != matrix._height) {
      throw new IllegalArgumentException(
                          "[Product] ERROR: matrix 1's width does not match matrix 2's height.");
    }

    // Matrix 1's height & matrix 2's width = new matrix's dimensions.
    Matrix product = new Matrix(5, _height, matrix._width);

    // For each row for matrix 1.
    for (int i = 0; i < _height; ++i) {
      // For each column for matrix 2.
      for (int k = 0; k < matrix._width; ++k) {
        float sum = 0;
        // For each column in row for matrix 1.
        for (int j = 0; j < _width; ++j) {
          sum += _data[i][j] * matrix._data[j][k];
        }
        product._data[i][k] = sum;
      }
    }

    return product;
  }


  /**
   * Prints the matrix.
   */
  public void print() {
    for (int i = 0; i < _height; ++i) {
      for (int j = 0; j < _width; ++j) {
        System.out.print(_data[i][j] + " ");
      }
      System.out.println();
    }
  }


  /**
   * Allocates the matrix.
   */
  private void createMatrix() {
    _data = new float[_height][_width];
  }


  /**
   * Prints the menu.
   */
  public static void printMenu() {
    System.out.println("=-=-=- Menu -=-=-=");
    System.out.println("[1] Print Sum");
    System.out.println("[2] Print Difference");
    System.out.println("[3] Print Product");
    System.out.println("[4] Print Matrix 1");
    System.out.println("[5] Print Matrix 2");
    System.out.println("[6] Re-input Matrix 1");
    System.out.println("[7] Re-input Matrix 2");
    System.out.println("[8] Exit");
  }


  public static void main(String[] args) {
    System.out.println("[ Java Class Matrix Calculator ]");

    // Get dimensions and create matrix.
    Matrix matrix1 = new Matrix(1);
    Matrix matrix2 = new Matrix(2);

    // Get values for matrix 1.
    System.out.println();
    matrix1.getMatrixValues();
    System.out.println("----- Matrix " + matrix1.getID() + " -----");
    matrix1.print();

    // Get values for matrix 2.
    System.out.println();
    matrix2.getMatrixValues();
    System.out.println("----- Matrix " + matrix2.getID() + " -----");
    matrix2.print();

    boolean exit = false;
    int choice = 0;
    do {
      // Get user's choice.
      System.out.println();
      printMenu();
      System.out.print("Input: ");
      choice = intInput.nextInt();

      // Process choice.
      System.out.println();
      switch (choice) {
        case 1: {  // Calculate and print sum.
          try {
            Matrix sum = matrix1.add(matrix2);
            System.out.println("[[[ Sum ]]]");
            sum.print();
          } catch (Exception e) {
            System.out.println(e.getMessage());
          }
          break;
        }
        case 2: {  // Calculate and print difference.
          try {
            Matrix difference = matrix1.subtract(matrix2);
            System.out.println("[[[ Difference ]]]");
            difference.print();
          } catch (Exception e) {
            System.out.println(e.getMessage());
          }
          break;
        }
        case 3: {  // Calculate and print product.
          try {
            Matrix product = matrix1.multiply(matrix2);
            System.out.println("[[[ Product ]]]");
            product.print();
          } catch (Exception e) {
            System.out.println(e.getMessage());
          }
          break;
        }
        case 4: {  // Print matrix 1.
          System.out.println("----- Matrix " + matrix1.getID() + " -----");
          matrix1.print();
          break;
        }
        case 5: {  // Print matrix 2.
          System.out.println("----- Matrix " + matrix1.getID() + " -----");
          matrix2.print();
          break;
        }
        case 6: {  // Re-input matrix 1.
          matrix1.getDimensions();
          matrix1.getMatrixValues();
          System.out.println("----- Matrix " + matrix1.getID() + " -----");
          matrix1.print();
          break;
        }
        case 7: {  // Re-input matrix 2.
          matrix2.getDimensions();
          matrix2.getMatrixValues();
          System.out.println("----- Matrix " + matrix2.getID() + " -----");
          matrix2.print();
          break;
        }
        case 8: {  // Exit program.
          exit = true;
          break;
        }
        default: {
          break;
        }
      }
    } while (!exit);
    
    // User exited; close scanners.
    intInput.close();
    floatInput.close();
    System.out.println("Goodbye!");

    return;
  }
}
