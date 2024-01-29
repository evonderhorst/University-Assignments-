// Authors: Erich Vonderhorst, Dr. Spickler
// Creation Date: 10/15/23
// Last Update: 10/16/23
// Description: main program for testing the member functions of the Complex class.
// Notes: given by the professor
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

#include "Complex.h"

void print(Complex z)
{
    cout << z << endl;
}

int main()
{
    Complex z;
    Complex x(3, 7);
    Complex y(-4);
    Complex w(0, 2);

    cout << x << ", " << y << ", " << z << ", " << w << endl;
    cout << x.getReal() << ", " << x.getImag() << endl;

    z.setReal(-5);
    z.setImag(19);
    cout << z << endl;

    z.set(-12345, 471);
    cout << z << endl;

    cout << endl;
    z.set(5, -8);
    cout << z << endl;
    cout << z + x << endl;
    cout << z + 4 << endl;
    cout << 4 + z << endl;
    cout << endl;
    cout << z - x << endl;
    cout << z - 4 << endl;
    cout << 4 - z << endl;
    cout << endl;
    cout << z * x << endl;
    cout << z * 4 << endl;
    cout << 4 * z << endl;
    cout << endl;
    cout << z / x << endl;
    cout << z / 4 << endl;
    cout << 4 / z << endl;
    cout << endl;

    w = z;
    cout << w << ", " << x << endl;
    w += x;
    print(w);

    cout << endl;

    w = z;
    cout << w << ", " << x << endl;
    w -= x;
    print(w);

    cout << (w ^ 2) << endl;
    cout << (w ^ 3) << endl;
    cout << endl;

    cout << z.mod() << endl;
    cout << endl;

    if (w == z)
        cout << "w == z" << endl;
    else
        cout << "w != z" << endl;

    if (w != z)
        cout << "w != z" << endl;
    else
        cout << "w == z" << endl;

    cout << endl;

    cout << "Input a complex number by simply entering " << endl;
    cout << "the real and imaginary parts with a space " << endl;
    cout << "between them. " << endl;
    cout << "c = ";
    cin >> z;
    cout << "c = " << z << endl;

    return 0;
}
