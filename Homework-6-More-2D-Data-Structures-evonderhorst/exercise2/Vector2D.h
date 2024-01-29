#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#ifndef Vector2D_h_
#define Vector2D_h_

// Author: Erich Vonderhorst
// Creation Date: 10/17/2023
// Last Update: 10/20/2023
// Description: a templated 2D vector class with various members functions and operator overloads for accessing and manipulating the
//              the data structure.

template <class vecType>
class Vector2D {

    private:
        vector<vector<vecType> > A; // 2D vector of templated type arrType
        int rows; // number of rows in the 2D vector
        int cols; // number of columns in the 2D vector
        vecType defVal; // default value for each element of the templated data type, arrType, in the 2D vector

    public:
        Vector2D(const Vector2D<vecType> &);
        Vector2D(int r = 3, int c = 3, vecType defval = 0);
        ~Vector2D();
        void display();
        void display(int);
        int getRows();
        int getCols();
        void set(int, int, vecType);
        vecType get(int, int);
        void resize(int, int);
        vector<vecType>& operator[](int);
        Vector2D<vecType>& operator=(const Vector2D<vecType> &);
        bool operator==(const Vector2D<vecType> &);
        bool operator!=(const Vector2D<vecType> &);

        template <class U>
        friend ostream& operator<<(ostream&, const Vector2D<U> &);
};

// Description: copy constructor for instances of Vector2D
// Parameters:
//      const Vector2D& rhs: instance of Vector2D that will have its values copied over to the new instance
// Return: a new instance of Vector2D
template<class vecType>
Vector2D<vecType>:: Vector2D(const Vector2D<vecType> &rhs) {

    // Copy size members
    rows = rhs.rows;
    cols = rhs.cols;

    // Copy over values from passed instance
    A.resize(rows);
    for (int j = 0; j < rows; j++) {
        for (int k = 0; k < cols; k++)
            A[j].push_back(rhs.A[j][k]);
    }
}

// Description: constructor with parameters for instances of the Vector2D
// Parameters:
//      int r: the number of rows in the 2D vector
//      int c: the number of columns in the 2D vector
//      int defVal: the value that will be stored in every index to start
// Return: a new instance of the Vector2D
// Notes: checks the validity of passed row and column values
template<class vecType>
Vector2D<vecType>:: Vector2D(int r, int c, vecType def) {

    //Validate passed row value
    if (r < 1)
        r = 1;

    //Validate passed column value
    if (c < 1)
        c = 1;

    //Fill 2D vector with passed default value
    A.resize(r);
    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++)
            A[j].push_back(def);
    }

    //Set members to passed values
    rows = r;
    cols = c;
    defVal = def;
}

// Description: destructor for instances of Vector2D
template <class vecType>
Vector2D<vecType>:: ~Vector2D() {}

// Description: displays each element in the Vector2D instance in its respective row and column
template <class vecType>
void Vector2D<vecType>:: display() {

    //Loop through each row
    for (int i = 0; i < rows; i++) {

        //For each row, loop through and display each element in the column
        for (int j = 0; j < cols; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

// Description: displays the elements in the Vector2D instance in its respective row and column with each column
//              being right justified in a field with a width set to the passed value
template <class vecType>
void Vector2D<vecType>:: display(int width) {

    // Printing with only a space between
    if (width <= 0)
        display();

    else {
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
}

// Description: standard accessor for the number of rows in the current Vector2D instance
// Return: the number of rows in the Vector2D instance
template <class vecType>
int Vector2D<vecType>:: getRows() {

    return rows;
}

// Description: accessor for the number of columns in the current Vector2D instance
// Return: the number of columns in the Vector2D instance
template <class vecType>
int Vector2D<vecType>:: getCols() {

    return cols;
}

// Description: mutator for any element contained in the current Vector2D instance
// Parameters:
//      int rIndex: row index of the element to be altered
//      int cIndex: column index of the element to be altered
//      int addVal: value that will placed in the element with the passed indices
template <class vecType>
void Vector2D<vecType>:: set(int rIndex, int cIndex, vecType addVal) {

    //Validate passed indices
    if (rIndex >= rows || rIndex < 0 || cIndex >= cols || cIndex < 0) {

        //Error message
        cout << "Index out of bounds, no change to the array." << endl;
        return;
    }

    //Set element to passed value once indices are validated
    A[rIndex][cIndex] = addVal;
}

// Description: accessor for any element contained in the current Vector2D instance
// Parameters:
//      int rIndex: row index of the element to be returned
//      int cIndex: column index of the element to be returned
// Return: the value of the element in the array with the passed indices
template <class vecType>
vecType Vector2D<vecType>:: get(int rIndex, int cIndex) {

    //Validate passed indices
    if (rIndex >= rows || rIndex < 0 || cIndex >= cols || cIndex < 0) {

        //Error message
        cout << "Index out of bounds, returning default value." << endl;
        return defVal;
    }

    //Return value of element with passed indices once validated
    return A[rIndex][cIndex];
}

// Description: increases or decreases the number of rows and columns in an instance of Vector2D
// Parameters:
//      int newRows: number of rows for the vector to be resized with
//      int newCols: number of columns for the vector to be resized with
// Notes: indices beyond those of the original vector have their elements assigned to the default value member
template <class vecType>
void Vector2D<vecType>::resize(int newRows, int newCols) {

    // Check if the vector already has the same number of rows and columns as the passed values
    if (rows == newRows && cols == newCols)
        return;

    A.resize(newRows);

    for (int i = 0; i < newRows; i++) {

        A[i].resize(newCols);

        for (int j = 0; j < newCols; j++)
            if (j >= cols || i >= rows)
                A[i][j] = defVal;
    }

    // Update the row and column members
    rows = newRows;
    cols = newCols;
}

// Description: overloaded access operator that returns the row in the passed index of the current instance of Vector2D
// Parameters:
//      int index: row index to be returned
// Return: the row in the passed index
template <class vecType>
vector<vecType>& Vector2D<vecType>:: operator[](int index) {
    return A[index];
}

// Description: overloaded assignment operator for multiple instances of Vector2D
// Parameters:
//      const Vector2D& rhs: instance with the vector to be assigned to that of the current instance
// Return: the current instance of Vector2D
// Notes: allows for chain assignment
template <class vecType>
Vector2D<vecType>& Vector2D<vecType>:: operator=(const Vector2D<vecType> &rhs) {

    A = rhs.A;
    for (int i = 0; i < rhs.rows; i++)
        A[i] = rhs.A[i];

    // Update row and column members
    rows = rhs.rows;
    cols = rhs.cols;

    return *this;
}

// Description: overloaded equality operator for two instances of Vector2D
// Parameters:
//      const Vector2D& rhs: instance with the vector to be compared to that of the current instance
// Return: a true or false value depending on if the instances are the same or not
template <class vecType>
bool Vector2D<vecType>:: operator==(const Vector2D<vecType> &rhs) {

    // Return false if the numbers of rows and/or columns of the current and passed instances' vectors are unequal
    if (rows != rhs.rows || cols != rhs.cols)
        return false;

    // Loop through the 2D vector and check for any differences, return false if found
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (A[i][j] != rhs.A[i][j])
                return false;

    // Return true if no differences were found
    return true;
}

// Description: overloaded inequality operator for two instances of Vector2D
// Parameters:
//      const Vector2D& rhs: instance with the vector to be compared to that of the current instance
// Return: a true or false value depending on if the instances are different or not
template <class vecType>
bool Vector2D<vecType>:: operator!=(const Vector2D<vecType> &rhs) {

    return !(*this == rhs);
}

// Description: overloaded insertion operator for printing the elements of the passed instance in a bracketed,
//              single-line format
// Parameters:
//      ostream& out: output stream currently being used
//      const Vector2D& rhs: instance that will have its values printed
// Return: the ostream that was used
template <class vecType>
ostream& operator<<(ostream& out, const Vector2D<vecType> &rhs) {

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
#endif
