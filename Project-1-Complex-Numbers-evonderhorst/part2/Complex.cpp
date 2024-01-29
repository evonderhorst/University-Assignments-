// Author: Erich Vonderhorst
// Creation Date: 10/15/2023
// Last Update: 10/16/2023
#include "Complex.h"

// Description: default constructor for instances of Complex
// Return: a new instance of Complex with the real and imaginary components set to 0
Complex:: Complex() {

    real = 0;
    imaginary = 0;
}

// Description: overloaded constructor with 2 parameters for instances of Complex
// Parameters:
//      double r: real component of the Complex instance to be created
//      double i: imaginary component of the Complex instance to be created
// Return: a new instance of Complex with the real and imaginary components set to r and i respectively
Complex:: Complex(double r, double i) {

    real = r;
    imaginary = i;
}

// Description: overloaded constructor with 1 parameter for instances of Complex
// Parameters:
//      double r: the real component of the Complex instance to be created
// Return: a new instance of Complex with the real component set to r and the imaginary component set to 0
Complex:: Complex(double r) {

    real = r;
    imaginary = 0;
}

// Description: destructor for instances of Complex
Complex:: ~Complex() {}

// Description: standard accessor for the real component of a Complex value
// Return: the real component, a, of the Complex value a + bi
double Complex:: getReal() {

    return real;
}

// Description: standard accessor for the imaginary component of a Complex value
// Return: the imaginary component, b, of the Complex value a + bi
double Complex:: getImag() {

    return imaginary;
}

// Description: standard mutator for the real component of a Complex value
// Parameters:
//      double r: the real component, a, for the Complex value, a + bi, to be set with
void Complex:: setReal(double r) {

    real = r;
}

// Description: standard mutator for the imaginary component of a Complex value
// Parameters:
//      double i: the imaginary component, b, for the Complex value, a + bi, to be set with
void Complex:: setImag(double i) {

    imaginary = i;
}

// Description: mutator for both the real and imaginary component of a Complex value
// Parameters:
//      double r: the real component, a, for the Complex value, a + bi, to be set with
//      double i: the imaginary component, b, for the Complex value, a + bi, to be set with
void Complex:: set(double r, double i) {

    real = r;
    imaginary = i;
}

// Description: overloaded addition operator for two instances of Complex
// Parameters:
//      Complex rhs: the Complex value to be added to that of the current instance
// Return: the Complex value containing the sum of the passed value and the current instance's value
Complex Complex:: operator+(Complex rhs) {

    Complex temp;
    temp.real = real + rhs.real;
    temp.imaginary = imaginary + rhs.imaginary;

    return temp;
}

// Description: overloaded addition operator for an instance of Complex and a double
// Parameters:
//      double rhs: value to be added to the Complex value of the current instance
// Return: the Complex value containing the sum of the current instance's value and the passed double
Complex Complex:: operator+(double rhs) {

    Complex temp;
    temp.real = real + rhs;
    temp.imaginary = imaginary;

    return temp;
}

// Description: overloaded subtraction operator for two instances of Complex
// Parameters:
//      Complex rhs: the value to be subtracted from that of the current instance
// Return: the Complex value containing the difference of the current instance's value and the passed value
Complex Complex:: operator-(Complex rhs) {

    Complex temp;
    temp.real = real - rhs.real;
    temp.imaginary = imaginary - rhs.imaginary;

    return temp;
}

// Description: overloaded subtraction operator for an instance of Complex and a double
// Parameters:
//      double rhs: the value to be subtracted from the current instance's Complex value
// Return: the Complex value containing the difference between the current instance's value and the passed double
Complex Complex:: operator-(double rhs) {

    Complex temp;
    temp.real = real - rhs;
    temp.imaginary = imaginary;

    return temp;
}

// Description: overloaded multiplication operator for two instances of Complex
// Parameters:
//      Complex rhs: the Complex value for that of the current instance to be multiplied by
// Return: the Complex value containing the product of the current instance's and passed instance's values
Complex Complex:: operator*(Complex rhs) {

    Complex temp;
    temp.real = (real * rhs.real) - (imaginary * rhs.imaginary);
    temp.imaginary = (imaginary * rhs.real) + (real * rhs.imaginary);

    return temp;
}

// Description: overloaded multiplication operator for an instance of Complex and a double
// Parameters:
//      double rhs: the value for the Complex value of the current instance to be multiplied by
// Return: the Complex value contining the product of the current instance's value and the passed double
Complex Complex:: operator*(double rhs) {

    Complex temp;
    temp.real = real * rhs;
    temp.imaginary = imaginary * rhs;

    return temp;
}

// Description: overloaded division operator for two instances of Complex
// Parameters:
//      Complex rhs: Complex value for the current instance's value to be divided by
// Return: the Complex value containing the quotient of the current instance's and passed instance's values
// Notes: checks for divide by 0 errors
Complex Complex:: operator/(Complex rhs) {

    if (rhs.real == 0 || rhs.imaginary == 0) {

        cout << "Error: cannot divide by 0." << endl;
        return *this;
    }

    Complex temp;
    temp.real = ((real * rhs.real) + (imaginary * rhs.imaginary)) / (pow(rhs.real, 2) + pow(rhs.imaginary, 2));
    temp.imaginary = ((imaginary * rhs.real) - (real * rhs.imaginary)) / (pow(rhs.real, 2) + pow(rhs.imaginary, 2));

    return temp;
}

// Description: overloaded division operator for an instance of Complex and a double
// Parameters:
//      double rhs: the value that the current instance's Complex value will be divided by
// Return: the Complex value containing the quotient of the current instance's value and the passed double
// Notes: checks for divide by 0 errors
Complex Complex:: operator/(double rhs) {

    if (rhs == 0) {

        cout << "Error: cannot divide by 0." << endl;
        return *this;
    }

    Complex temp;
    temp.real = real / rhs;
    temp.imaginary = imaginary / rhs;

    return temp;
}

// Description: overloaded addition assignment operator for two instances of Complex
// Parameters:
//      Complex rhs: the Complx value to be added with the current instance's value and have their sum be assigned to the current
//                   instance's value
void Complex:: operator+=(Complex rhs) {

    real += rhs.real;
    imaginary += rhs.imaginary;
}

// Description: <One paragraph describing what the function does>
// Parameters:
//      Complex rhs: the Complex value to be subtracted from the current instance's value and have their sum be assigned to the
//                   current instance's value
void Complex:: operator-=(Complex rhs) {

    real -= rhs.real;
    imaginary -= rhs.imaginary;
}

// Description: overloaded bitwise XOR operator that functions as a way to calculate integer exponents of Complex values
// Parameters:
//      int exp: the power to which the Complex value of the current instance will be raised to
// Return: the Complex value containing the calculated exponent of the current instance's value
// Notes: put statements in parenthese as the operator is low in the order of precedence
Complex Complex:: operator^(int exp) {

    Complex temp;
    temp.real = real;
    temp.imaginary = imaginary;
    double realNum;
    double imagNum;

    // Raising to the 0th power
    if (exp == 0) {

        temp.real = 1;
        temp.imaginary = 0;
    }

    // Raising to the -1st power
    else if (exp == -1) {

        temp.real = real / (pow(real, 2) + pow(imaginary, 2));
        temp.imaginary = imaginary / (pow(real, 2) + pow(imaginary, 2));
    }

    // All other exponents
    else {
        for (int i = 0; i < abs(exp) - 1; i++) {

            realNum = (temp.real * real) - (temp.imaginary * imaginary);
            imagNum = (temp.imaginary * real) + (temp.real * imaginary);

            temp.real = realNum;
            temp.imaginary = imagNum;
        }

        // If the exponent is negative
        if (exp < -1) {

            realNum = temp.real / (pow(temp.real, 2) + pow(temp.imaginary, 2));
            imagNum = temp.imaginary / (pow(temp.real, 2) + pow(temp.imaginary, 2));

            temp.real = realNum;
            temp.imaginary = imagNum;
        }
    }


    return temp;
}

// Description: overloaded equality operator for two instances of Complex
// Parameters:
//      Complex rhs: the Complex value that will be compared with that of the current instance
// Return: a true or false value depending on if the Complex values of the current and passed instances are equal or not
bool Complex:: operator==(Complex rhs) {

    if (real == rhs.real && imaginary == rhs.imaginary)
        return true;

    else
        return false;
}

// Description: overloaded inequality operator for two instances of Complex
// Parameters:
//      Complex rhs: the Complex value that will be compared with that of the current instance
// Return: a true or false value depending on if the Complex values of the current and passed instances are unequal or not
bool Complex:: operator!=(Complex rhs) {

    if (real != rhs.real || imaginary != rhs.imaginary)
        return true;

    else
        return false;
}

// Description: overloaded assignment operator for instances of Complex
// Parameters:
//      Complex rhs: the Complex value for that of the current instance to be assigned to
// Return: the Complex value of the current instance
// Notes: allows for chain assignment
Complex Complex:: operator=(Complex rhs) {

    real = rhs.real;
    imaginary = rhs.imaginary;

    return *this;
}

// Description: calculates and returns the modulus of the current instance's Complex value
// Return: the modulus of the current instance's Complex value
double Complex:: mod() {

    return sqrt(pow(real, 2) + pow(imaginary, 2));
}

// Description: overloaded extraction operator for printing out Complex values (a + bi) in a nice format
// Parameters:
//      ostream& out: the output stream currently being used
//      Complex rhs: the Complex value being displayed
// Return: the output stream currently being used
// Notes: will change '+' to '-' if b is negative or print only one value if the other is 0
ostream& operator<<(ostream& out, Complex rhs) {

    if (rhs.real == 0 && rhs.imaginary != 0)
        out << rhs.imaginary << "i";

    else if (rhs.imaginary == 0 && rhs.real != 0)
        out << rhs.real;

    else if (rhs.real == 0 && rhs.imaginary == 0)
        out << 0;

    else if (rhs.imaginary > 0)
        out << rhs.real << " + " << rhs.imaginary << "i";

    else
        out << rhs.real << " - " << abs(rhs.imaginary) << "i";

    return out;
}

// Description: overloaded extraction operator for reading in the real and imaginary components for a Complex value
// Parameters:
//      istream& in: the input stream currently being used
//      Complex& rhs: the Complex value to have its real and imaginary components be input by the user
// Return: the input stream currently being used
// Notes: reads both values separated by a space
istream& operator>>(istream& in, Complex& rhs) {

    in >> rhs.real >> rhs.imaginary;
    return in;
}

// Description: overloaded addition operator for a double and an instance of Complex
// Parameters:
//      double lhs: the value for the passed Complex value to be added to
//      Complex rhs: the Complex value to be added to the passed double
// Return: the Complex value containing the sum of the passed Complex value and double
Complex operator+(double lhs, Complex rhs) {

    Complex temp;
    temp.real = rhs.real + lhs;
    temp.imaginary = rhs.imaginary;

    return temp;
}

// Description: overloaded subtraction operator for a double and an instance of Complex
// Parameters:
//      double lhs: the value for the passed Complex value to be subtracted from
//      Complex rhs: the Complex value to be subtracted from the passed double
// Return: the Complex value containg the difference of the passed double and the passed Complex value
Complex operator-(double lhs, Complex rhs) {

    Complex temp;
    temp.real = lhs - rhs.real;

    if (rhs.imaginary < 0)
        temp.imaginary = abs(rhs.imaginary);

    else
        temp.imaginary = rhs.imaginary;

    return temp;
}

// Description: overloaded multiplication operator for a double and an instance of Complex
// Parameters:
//      double lhs: the value for the passed Complex value to be multiplied by
//      Complex rhs: the Complex value to be multiplied by the passed double
// Return: the Complex value containing the product of the passed double and the passed Complex value
Complex operator*(double lhs, Complex rhs) {

    Complex temp;
    temp.real = rhs.real * lhs;
    temp.imaginary = rhs.imaginary * lhs;

    return temp;
}

// Description: overloaded division operator for a double and an instance of Complex
// Parameters:
//      double lhs: the value to be divided by the passed Complex value
//      Complex rhs: the Complex value for the passed double to be divided by
// Return: the Complex value containing the quotient of the passed double and Complex value
// Notes: checks for divide by 0 errors
Complex operator/(double lhs, Complex rhs) {

    if (rhs.real == 0 || rhs.imaginary == 0) {

        cout << "Error: cannot divide by 0." << endl;
        return rhs;
    }

    Complex temp;
    temp.real = (lhs * rhs.real) / (pow(rhs.real, 2) + pow(rhs.imaginary, 2));
    temp.imaginary = (lhs * rhs.imaginary) / (pow(rhs.real, 2) + pow(rhs.imaginary, 2));

    return temp;
}
