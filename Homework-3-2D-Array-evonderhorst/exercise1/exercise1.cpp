
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Array2D.h"

using namespace std;

// Author: Erich Vonderhorst, Dr. Spickler
// Creation Date: 9/21/2023
// Last Update: 9/21/2023
// Description: tests the member functions of the Array2D class
// Notes: given by professor

int main() {

    srand(time(0));

    Array2D A(3, 5, -1);

    A.display();
    cout << endl;

    for (int i = 0; i < A.getRows(); i++)
        for (int j = 0; j < A.getCols(); j++)
            A.set(i, j, rand() % 100);

    A.display();
    cout << endl;

    A.resize(5, 3);

    A.display();
    cout << endl;

    A.resize(5, 5);

    A.display();
    cout << endl;

    A.resize(7, 2);

    A.display();
    cout << endl;

    A.resize(6, 5, 17);

    A.display();
    cout << endl;

    A.display(4);
    cout << endl;

    return 0;
}
