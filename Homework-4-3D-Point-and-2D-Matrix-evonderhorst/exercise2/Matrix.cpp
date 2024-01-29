#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;
// Author: Erich Vonderhorst
// Creation Date: 10/05/2023
// Last Update: 10/06/2023

// Description: copy constructor for instances of the Matrix class that allocates the dynamic 2 dimensional
//              array and sets the members to the values of the passed instance
//
// Parameters:
//      const Matrix& rhs: instance of Matrix that will have its values copied over to the new instance
// Return: a new instance of the Matrix class
Matrix:: Matrix(const Matrix& rhs) {

    // Copy size members
    rows = rhs.rows;
    cols = rhs.cols;

    // Allocate memory for 2D array
    A = new double*[rows];
    for (int i = 0; i < rows; i++)
        A[i] = new double[cols];

    // Copy over values from passed instance
    for (int j = 0; j < rows; j++)
        for (int k = 0; k < cols; k++)
            A[j][k] = rhs.A[j][k];
}

// Description: constructor for instances of the Matrix class that allocates the dynamic 2 dimensional
//              array and sets the members for the numbers of rows and columns according to the passed
//              values and fills each index with the same value specified by the third paramter
// Parameters:
//      int r: the number of rows to be allocated for the dynamic 2 dimensional array
//      int c: the number of columns to be allocated for the dynamic 2 dimensional array
//      int defVal: the value that will be stored in every index within the dynamic 2 dimensional array
// Return: a new instance of the Matrix class
// Notes: checks the validity of passed row and column values
Matrix:: Matrix(int r, int c, double defval) {

    //Validate passed row value
    if (r < 1)
        r = 1;

    //Validate passed column value
    if (c < 1)
        c = 1;

    //Allocate memory for 2D array
    A = new double* [r];
    for (int i = 0; i < r; i++)
        A[i] = new double[c];

    //Fill 2D array with passed default value
    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++)
            A[j][k] = defval;
    }

    //Set row and column members to passed values
    rows = r;
    cols = c;
}

// Description: destructor for instances of the Matrix class that frees up all dynamic memory allocated for the
//              dynamic 2 dimensional array data member
// Return: void
Matrix:: ~Matrix() {


    //Deallocate memory in each index of A
    for (int i = 0; i < rows; i++)
        delete[] A[i];

     //Deallocate A and set it to nullptr
    delete[] A;
    A = nullptr;
}

// Description: displays the elements in the dynamic 2 dimensional array by their respective row and column
// Return: void
void Matrix:: display() {

    //Loop through each row
    for (int i = 0; i < rows; i++) {

        //For each row, loop through and display each element in the column
        for (int j = 0; j < cols; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

// Description: displays the elements in the dynamic 2 dimensional array by their respective row and column with each column
//              being right justified in a field with a width set to the passed value
// Return: void
void Matrix:: display(int width) {

    //Loop through each row
    for (int i = 0; i < rows; i++) {

        //For each row, loop through and display each element in the column with the proper format
        for (int j = 0; j < cols; j++) {

            //Format output stream and print element
            cout << setw(width) << right;
            cout << A[i][j] << " ";
        }

        cout << endl;
    }
}

// Description: accessor for the data member containing the number of rows in the dynamic 2 dimensional array
// Return: the number of rows in the dynamic 2 dimensional array
int Matrix:: getRows() {

    return rows;
}

// Description: accessor for the data member containing the number of columns in the dynamic 2 dimensional array
// Return: the number of columns in the dynamic 2 dimensional array
int Matrix:: getCols() {

    return cols;
}

// Description: mutator for any element contained in the dynamic 2 dimensional array
// Parameters:
//      int rIndex: row index of the element to be altered
//      int cIndex: column index of the element to be altered
//      int addVal: value that will placed in the element with the passed indices
// Return: void
void Matrix:: set(int rIndex, int cIndex, double addVal) {

    //Validate passed indices
    if (rIndex >= rows || rIndex < 0 || cIndex >= cols || cIndex < 0) {

        //Error message
        cout << "Index out of bounds." << endl;
        return;
    }

    //Set element to passed value once indices are validated
    A[rIndex][cIndex] = addVal;
}

// Description: accessor for any element contained in the dynamic 2 dimensional array
// Parameters:
//      int rIndex: row index of the element to be returned
//      int cIndex: column index of the element to be returned
// Return: the value of the element in the array with the passed indices
double Matrix:: get(int rIndex, int cIndex) {

    //Validate passed indices
    if (rIndex >= rows || rIndex < 0 || cIndex >= cols || cIndex < 0) {

        //Error message
        cout << "Index out of bounds." << endl;
        return 0;
    }

    //Return value of element with passed indices once validated
    return A[rIndex][cIndex];
}

// Description: overloaded addition operator for instances of the Matrix class
// Parameters:
//      const Matrix& rhs: instance that will have its 2D array values added to those of the current instance
// Return: an instance of the Matrix class with a 2D array containing the sums of the elements of both instances
// Notes: both the passed and current instance must have equal row and column numbers in order to be added.
//        Returns an instance that is 1 x 1 and contains 0 as its only element if they are not.
Matrix Matrix:: operator+(const Matrix& rhs) {

    // Check if the number of rows and columns in both instances is equal
    if (rows == rhs.rows && cols == rhs.cols) {

        // Create a temporary instance and populate it with the sums of the elements of the current and passed instances
        Matrix temp(rows, cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                temp.A[i][j] = A[i][j] + rhs.A[i][j];
        }

        // Return the temporary instance by value
        return temp;
    }

    else
        return Matrix(1,1,0);
}

// Description: overloaded subtraction operator for instances of the Matrix class
// Parameters:
//      const Matrix& rhs: instance that will have its 2D array values subtracted from those of the current instance
// Return: an instance of the Matrix class with a 2D array containing the difference of the elements of both instances
// Notes: both the passed and current instance must have equal row and column numbers in order to be subtracted.
//        Returns an instance that is 1 x 1 and contains 0 as its only element if they are not.
Matrix Matrix:: operator-(const Matrix& rhs) {

     // Check if the number of rows and columns in both instances is equal
    if (rows == rhs.rows && cols == rhs.cols) {

        // Create a temporary instance and populate it with the differences of the elements of the current and passed instances
        Matrix temp(rows, cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                temp.A[i][j] = A[i][j] - rhs.A[i][j];
        }

        // Return the temporary instance by value
        return temp;
    }

    else
        return Matrix(1,1,0);
}

// Description: overloaded multiplication operator for use between two instances of the Matrix class. Creates a
//              2D array that contains the sums of the products of each column value multiplied by every column
//              value in a corresponding row of the passed instance.
// Parameters:
//      const Matrix& rhs: instance that will have each of its row values multiplied by the current instance's
//                         column values
// Return: an instance of the Matrix class with a 2D array containing the results of the specified calculations
// Notes: the number of colums in the current instance and the number of rows in the passed instance must be equal.
//        Returns an instance that is 1 x 1 and contains 0 as its only element if they are not.
Matrix Matrix:: operator*(const Matrix& rhs) {

    // Check if the number of columns in the current instance and the number of rows in the passed instance are equal
    if (cols == rhs.rows) {

        // Create temporary instance and perform calculations
        Matrix temp (rows, cols, 0);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                for (int k = 0; k < rhs.cols; k++)
                    temp.A[i][j] += A[i][j] * rhs.A[j][k];
        }

        // Return temporary instance by value
        return temp;
    }

    else
        return Matrix(1,1,0);
}

// Description: overloaded multiplication operator for use between an instance of the Matrix class and a double.
//              Creates a new instance of Matrix with its 2D array containing the products of each element and
//              the passed double.
// Parameters:
//      const double& rhs: value that each element of the current instance will be multiplied by
// Return: an instance of the Matrix class with a 2D array containing the products of each elment and the double
Matrix Matrix:: operator*(const double& rhs) {

    // Multiply each element of the current instance by the passed value and store it in a temporary instance
    Matrix temp(rows, cols, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            temp.A[i][j] = A[i][j] * rhs;
    }

    // Return the temporary instance by value
    return temp;
}

// Description: overloaded array access operator that returns a pointer to a row index of the 2D array of the curerent instance
// Parameters:
//      int index: index of the row that the returned pointer will point to
// Return: a pointer to the row of the passed index in the current instance's 2D array
double* Matrix:: operator[](int index) {

    // Check if the passed index is out of bounds
    if (index >= 0 && index < rows)
        return A[index];

    else
        return nullptr;

}

// Description: overloaded insertion operator for printing the elements of the passed instance in a bracketed,
//              single-line format
// Parameters:
//      ostream& out: output stream currently being used
//      const Matrix& rhs: Matrix instance that will have its values printed
// Return: the ostream that was used
ostream& operator<<(ostream& out, const Matrix& rhs) {

    out << "[ ";
    for (int i = 0; i < rhs.rows; i++) {

        out << "[ ";

        for (int j = 0; j < rhs.cols; j++)
            out << rhs.A[i][j] << " ";

        out << "] ";
    }

    out << "]" << endl;

    return out;
}

// Description: overloaded assignment operator for use between instances of the Matrix class
// Parameters:
//      const Matrix& rhs: instance that will have its attributes copied over to the current instance
// Return: the current instance
Matrix Matrix:: operator=(const Matrix& rhs) {

    // Create a temporary 2D of the same size as the passed instance that will have its values copied over
    double** temp = new double* [rhs.rows];
    for (int i = 0; i < rhs.rows; i++)
        temp[i] = new double[rhs.cols];

    // Deallocate the old 2D array of the current instance
    for (int i = 0; i < rows; i++)
        delete[] A[i];
    delete[] A;

    // Set A to point to the temporary array just created
    A = temp;
    for (int i = 0; i < rhs.rows; i++)
        A[i] = temp[i];

    // Update row and column members
    rows = rhs.rows;
    cols = rhs.cols;

    // Copy values over
     for (int j = 0; j < rows; j++)
        for (int k = 0; k < cols; k++)
            A[j][k] = rhs.A[j][k];

    // Return the current instance for chain assignment
    return *this;
}

// Description: overloaded multiplication operator for use between a double and an instance of the Matrix class
// Parameters:
//      const double& lhs: value that each element in the Matrix instance's 2D array will be multiplied by
// Return: an instance of the Matrix class
Matrix operator*(const double& lhs, const Matrix& rhs) {

    // Create a temporary instance to store the products of each element and the passed double
    Matrix temp(rhs.rows, rhs.cols, 0);
    for (int i = 0; i < rhs.rows; i++) {
        for (int j = 0; j < rhs.cols; j++)
            temp.A[i][j] = rhs.A[i][j] * lhs;
    }

    // Return the temporary instance by value
    return temp;
}

// Description: reverses the orientation of the row and column elements in the current Matrix instance's 2D array
// Return: an instance of Matrix
Matrix Matrix:: transpose() {

    // Create a temporary instance to store the reoriented 2D array
    Matrix temp (cols, rows, 0);
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            temp.A[i][j] = A[j][i];
    }

    // Return the temporary instance by value
    return temp;
}
