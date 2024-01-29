#include <iostream>
#include <iomanip>

#ifndef Array2D_h_
#define Array2D_h_

// Author: Erich Vonderhorst
// Creation Date: 9/21/2023
// Last Update: 9/25/2023
// Description: a class with member functions to display, access, mutate and resize a dynamic 2 dimensional array data member
//              and the members corresponding to its numbers of rows and columns
// Notes: none

class Array2D {

    private:
        int** A = nullptr;
        int rows;
        int cols;

    public:
        Array2D(int r = 3, int c = 3, int defval = 0);
        ~Array2D();

        void display();
        void display(int);
        int getRows();
        int getCols();
        void set(int, int, int);
        int get(int, int);
        void resize(int r = 3, int c = 3, int defval = 0);
};

#endif
