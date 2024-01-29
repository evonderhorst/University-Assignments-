#include <iostream>

using namespace std;

#ifndef Matrix_h_
#define Matrix_h_

// Author: Erich Vonderhorst
// Creation Date: 10/05/2023
// Last Update: 10/06/2023
// Description: a class with member functions to display, access, and mutate a dynamic 2 dimensional array data member
//              and the members corresponding to its numbers of rows and columns. Several operators have been overloaded
//              for this class including insertion, array access, and several overloads of the multiplication operator.

class Matrix {

    private:
        double** A = nullptr; // dynamic 2D double array
        int rows; // number of rows in the 2D array
        int cols; // number of columns in the 2D array

    public:
        Matrix(const Matrix&);
        Matrix(int r = 3, int c = 3, double defval = 0);
        ~Matrix();
        void display();
        void display(int);
        int getRows();
        int getCols();
        void set(int, int, double);
        double get(int, int);
        Matrix operator+(const Matrix&);
        Matrix operator-(const Matrix&);
        Matrix operator*(const Matrix&);
        Matrix operator*(const double&);
        double* operator[](int);
        Matrix operator=(const Matrix&);
        friend Matrix operator*(const double&, const Matrix&);
        friend ostream& operator<<(ostream&, const Matrix&);
        Matrix transpose();
};

#endif
