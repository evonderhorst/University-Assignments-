#include <iostream>
#include <iomanip>

using namespace std;

#ifndef Array2D_h_
#define Array2D_h_

// Author: Erich Vonderhorst
// Creation Date: 10/17/2023
// Last Update: 10/19/2023
// Description: a templated 2D array class with various members functions and operator overloads for accessing and manipulating the
//              the data structure.

template <class arrType>
class Array2D {

    private:
        arrType** A; // dynamic 2D array of templated type arrType
        int rows; // number of rows in the 2D array
        int cols; // number of columns in the 2D array
        arrType defVal; // default value for each element of the templated data type, arrType, in the 2D array

    public:
        Array2D(const Array2D<arrType> &);
        Array2D(int r = 3, int c = 3, arrType defval = 0);
        ~Array2D();
        void display();
        void display(int);
        int getRows();
        int getCols();
        void set(int, int, arrType);
        arrType get(int, int);
        void resize(int, int);
        arrType* operator[](int);
        Array2D<arrType>& operator=(const Array2D<arrType> &);
        bool operator==(const Array2D<arrType> &);
        bool operator!=(const Array2D<arrType> &);

        template <class U>
        friend ostream& operator<<(ostream&, const Array2D<U> &);
};

// Description: copy constructor for instances of Array2D that allocates the dynamic 2 dimensional
//              array for the instance called and sets the members to the values of the passed instance
// Parameters:
//      const Array2D& rhs: instance of Array2D that will have its values copied over to the new instance
// Return: a new instance of Array2D
template<class arrType>
Array2D<arrType>:: Array2D(const Array2D<arrType> &rhs) {

    // Copy size members
    rows = rhs.rows;
    cols = rhs.cols;

    // Allocate memory for 2D array
    A = new arrType*[rows];
    for (int i = 0; i < rows; i++)
        A[i] = new arrType[cols];

    // Copy over values from passed instance
    for (int j = 0; j < rows; j++)
        for (int k = 0; k < cols; k++)
            A[j][k] = rhs.A[j][k];
}

// Description: constructor with parameters for instances of the Array2D
// Parameters:
//      int r: the number of rows to be allocated
//      int c: the number of columns to be allocated
//      int defVal: the value that will be stored in every index to start
// Return: a new instance of the Array2D
// Notes: checks the validity of passed row and column values
template<class arrType>
Array2D<arrType>:: Array2D(int r, int c, arrType def) {

    //Validate passed row value
    if (r < 1)
        r = 1;

    //Validate passed column value
    if (c < 1)
        c = 1;

    //Allocate memory for 2D array
    A = new arrType* [r];
    for (int i = 0; i < r; i++)
        A[i] = new arrType[c];

    //Fill 2D array with passed default value
    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++)
            A[j][k] = def;
    }

    //Set members to passed values
    rows = r;
    cols = c;
    defVal = def;
}

// Description: destructor for instances of Array2D
template <class arrType>
Array2D<arrType>:: ~Array2D() {


    //Deallocate memory in each index of A
    for (int i = 0; i < rows; i++)
        delete[] A[i];

     //Deallocate A and set it to nullptr
    delete[] A;
    A = nullptr;
}

// Description: displays each element in the Array2D instance in its respective row and column
template <class arrType>
void Array2D<arrType>:: display() {

    //Loop through each row
    for (int i = 0; i < rows; i++) {

        //For each row, loop through and display each element in the column
        for (int j = 0; j < cols; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

// Description: displays the elements in the Array2D instance in its respective row and column with each column
//              being right justified in a field with a width set to the passed value
template <class arrType>
void Array2D<arrType>:: display(int width) {

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

// Description: standard accessor for the number of rows in the current Array2D instance
// Return: the number of rows in the Array2D instance
template <class arrType>
int Array2D<arrType>:: getRows() {

    return rows;
}

// Description: accessor for the number of columns in the current Array2D instance
// Return: the number of columns in the Array2D instance
template <class arrType>
int Array2D<arrType>:: getCols() {

    return cols;
}

// Description: mutator for any element contained in the current Array2D instance
// Parameters:
//      int rIndex: row index of the element to be altered
//      int cIndex: column index of the element to be altered
//      int addVal: value that will placed in the element with the passed indices
template <class arrType>
void Array2D<arrType>:: set(int rIndex, int cIndex, arrType addVal) {

    //Validate passed indices
    if (rIndex >= rows || rIndex < 0 || cIndex >= cols || cIndex < 0) {

        //Error message
        cout << "Index out of bounds, no change to the array." << endl;
        return;
    }

    //Set element to passed value once indices are validated
    A[rIndex][cIndex] = addVal;
}

// Description: accessor for any element contained in the current Array2D instance
// Parameters:
//      int rIndex: row index of the element to be returned
//      int cIndex: column index of the element to be returned
// Return: the value of the element in the array with the passed indices
template <class arrType>
arrType Array2D<arrType>:: get(int rIndex, int cIndex) {

    //Validate passed indices
    if (rIndex >= rows || rIndex < 0 || cIndex >= cols || cIndex < 0) {

        //Error message
        cout << "Index out of bounds, returning default value." << endl;
        return defVal;
    }

    //Return value of element with passed indices once validated
    return A[rIndex][cIndex];
}

// Description: increases or decreases the number of rows and columns in an instanceo of Array2D
// Parameters:
//      int newRows: number of rows for the array to be resized with
//      int newCols: number of columns for the array to be resized with
// Notes: indices beyond those of the original array have their elements assigned to the default value member
template <class arrType>
void Array2D<arrType>::resize(int newRows, int newCols) {

    // Check if the array already has the same number of rows and columns as the passed values
    if (rows == newRows && cols == newCols)
        return;

    // Create a temporary 2D array of the same type as the current instance's, allocate each row and fill in the elements with
    // copied values or defVal
    arrType** temp = new arrType*[newRows];

    for (int i = 0; i < newRows; i++) {

        temp[i] = new arrType[newCols];

        for (int j = 0; j < newCols; j++) {

            if (j >= cols || i >= rows)
                temp[i][j] = defVal;

            else
                temp[i][j] = A[i][j];
        }
    }

    // Deallocate the old array
    for (int k = 0; k < rows; k++)
        delete[] A[k];
    delete[] A;

    // Have the current instance's array variable point to the temporary array just made
    A = temp;
    for (int l = 0; l < newRows; l++)
        A[l] = temp[l];

    // Update the row and column members
    rows = newRows;
    cols = newCols;
}

// Description: overloaded array access operator that returns a pointer to the row in the passed index of the current instance of
//              Array2D
// Parameters:
//      int index: row index to be returned
// Return: a pointer to the row in the passed index
template <class arrType>
arrType* Array2D<arrType>:: operator[](int index) {

    // Check if the passed index is out of bounds
    if (index >= 0 && index < rows)
        return A[index];

    else
        return nullptr;

}

// Description: overloaded assignment operator for multiple instances of Array2D
// Parameters:
//      const Array2D& rhs: instance with the array to be assigned to that of the current instance
// Return: the current instance of Array2D
// Notes: allows for chain assignment
template <class arrType>
Array2D<arrType>& Array2D<arrType>:: operator=(const Array2D<arrType> &rhs) {

    // Create a temp array and copy over values from the passed instance
    arrType** temp = new arrType*[rhs.rows];

    for (int i = 0; i < rhs.rows; i++) {

        temp[i] = new arrType[rhs.cols];

        for (int j = 0; j < rhs.cols; j++) {

            temp[i][j] = rhs.A[i][j];
        }
    }

    // Deallocate current instance's array
    for (int k = 0; k < rows; k++)
        delete[] A[k];
    delete[] A;

    // Transfer over temp array
    A = temp;
    for (int l = 0; l < rhs.rows; l++)
        A[l] = temp[l];

    // Update row and column members
    rows = rhs.rows;
    cols = rhs.cols;

    return *this;
}

// Description: overloaded equality operator for two instances of Array2D
// Parameters:
//      const Array2D& rhs: instance with the array to be compared to that of the current instance
// Return: a true or false value depending on if the instances are the same or not
template <class arrType>
bool Array2D<arrType>:: operator==(const Array2D<arrType> &rhs) {

    // Return false if the numbers of rows and/or columns of the current and passed instances' arrays are unequal
    if (rows != rhs.rows || cols != rhs.cols)
        return false;

    // Loop through the 2D array and check for any differences, return false if found
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (A[i][j] != rhs.A[i][j])
                return false;

    // Return true if no differences were found
    return true;
}

// Description: overloaded inequality operator for two instances of Array2D
// Parameters:
//      const Array2D& rhs: instance with the array to be compared to that of the current instance
// Return: a true or false value depending on if the instances are different or not
template <class arrType>
bool Array2D<arrType>:: operator!=(const Array2D<arrType> &rhs) {

    return !(*this == rhs);
}

// Description: overloaded insertion operator for printing the elements of the passed instance in a bracketed,
//              single-line format
// Parameters:
//      ostream& out: output stream currently being used
//      const Array2D& rhs: instance that will have its values printed
// Return: the ostream that was used
template <class arrType>
ostream& operator<<(ostream& out, const Array2D<arrType> &rhs) {

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
