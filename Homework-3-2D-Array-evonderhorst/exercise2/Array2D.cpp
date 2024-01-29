#include "Array2D.h"

using namespace std;

// Author: Erich Vonderhorst
// Creation Date: 9/25/2023
// Last Update: 9/25/2023
// Description: implementation for the constructor, destructor, and all other member functions of the Array2D class
// Notes: none


// Description: constructor for instances of the Array2D class that allocates the dynamic 2 dimensional
//              array and sets the members for the numbers of rows and columns according to the passed
//              values and fills each index with the same value specified by the third paramter
// Parameters:
//      int r: the number of rows to be allocated for the dynamic 2 dimensional array
//      int c: the number of columns to be allocated for the dynamic 2 dimensional array
//      int defVal: the value that will be stored in every index within the dynamic 2 dimensional array
// Return: a new instance of the Array2D class
// Notes: checks the validity of passed row and column values
Array2D:: Array2D(int r, int c, int defval) {

    //Validate passed row value
    if (r < 1)
        r = 1;

    //Validate passed column value
    if (c < 1)
        c = 1;

    //Allocate memory for 2D array
    A = new int*[r];
    for (int i = 0; i < r; i++)
        A[i] = new int[c];

    //Fill 2D array with passed default value
    for (int j = 0; j < r; j++) {
        for (int k = 0; k < c; k++)
            A[j][k] = defval;
    }

    //Set row and column members to passed values
    rows = r;
    cols = c;
}

// Description: destructor for instances of the Array2D class that frees up all dynamic memory allocated for the
//              dynamic 2 dimensional array data member
// Parameters: none
// Return: void
// Notes: none
Array2D:: ~Array2D() {

    //Deallocate memory in each index of A
    for (int i = 0; i < rows; i++)
        delete[] A[i];

    //Deallocate A and set it to nullptr
    delete[] A;
    A = nullptr;
}

// Description: displays the elements in the dynamic 2 dimensional array by their respective row and column
// Parameters: none
// Return: void
// Notes: none
void Array2D:: display() {

    //Loop through each row
    for (int i = 0; i < rows; i++) {

        //For each row, loop through and display each element in the column
        for (int j = 0; j < cols; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

// Description: overload of the above function which accomplishes the same task with the added ability to control the number
//              of spaces all column elements occupy when printed
// Parameters:
//      int colSpace: number of spaces occupied by each column element when printed
// Return: void
// Notes: the values displayed in each column are right justified
void Array2D:: display(int colSpace) {

    //Loop through each row
    for (int i = 0; i < rows; i++) {

        //For each row, loop through and display each element in the column with a field width equal to the passed value
        for (int j = 0; j < cols; j++)
            cout << setw(colSpace) << right << A[i][j];

        cout << endl;
    }
}

// Description: accessor for the data member containing the number of rows in the dynamic 2 dimensional array
// Parameters: none
// Return: the number of rows in the dynamic 2 dimensional array
// Notes: none
int Array2D:: getRows() {

    return rows;
}

// Description: accessor for the data member containing the number of columns in the dynamic 2 dimensional array
// Parameters: none
// Return: the number of columns in the dynamic 2 dimensional array
// Notes: none
int Array2D:: getCols() {

    return cols;
}

// Description: mutator for any element contained in the dynamic 2 dimensional array
// Parameters:
//      int rIndex: row index of the element to be altered
//      int cIndex: column index of the element to be altered
//      int addVal: value that will placed in the element with the passed indices
// Return: void
// Notes: none
void Array2D:: set(int rIndex, int cIndex, int addVal) {

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
// Notes: none
int Array2D:: get(int rIndex, int cIndex) {

    //Validate passed indices
    if (rIndex >= rows || rIndex < 0 || cIndex >= cols || cIndex < 0) {

        //Error message
        cout << "Index out of bounds." << endl;
        return 0;
    }

    //Return value of element with passed indices once validated
    return A[rIndex][cIndex];
}

// Description: resizes the current instance's array with the number of rows and columns passed and fills any new indices
//              with a passed default value
// Parameters:
//      int numRow: number of rows to be in the resized array
//      int numCol: number of columns to be in the resized array
//      int defval: value that fills any indices beyond the sizes of the original array
// Return: void
// Notes: none
void Array2D:: resize(int numRow, int numCol, int defval) {

    // Allocate temporary array for resing
    int** tempArr = new int*[numRow];

    for (int i = 0; i < numRow; i++)
        tempArr[i] = new int[numCol];

    // Copy values over, place default value in indices greater than the old array
    for (int i = 0; i < numRow; i++) {

        for (int j = 0; j < numCol; j++) {

            if (i >= rows || j >= cols)
                tempArr[i][j] = defval;

            else
                tempArr[i][j] = A[i][j];
        }
    }

    // Deallocate the old array and update members
    delete[] A;
    A = tempArr;
    rows = numRow;
    cols = numCol;
}
