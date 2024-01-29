// Author: Erich Vonderhorst
// Creation Date: 10/15/2023
// Last Update: 10/16/2023
// Description: represents a complex value a + bi with data members representing both the real portion, a, and the imaginary portion,
//              b. Member functions include several overloads for addition, subtraction, multiplication, and division as well as
//              other operators such as the bitwise XOR being used for exponents of complex values.
#include <cmath>
#include <iostream>
using namespace std;

#ifndef Complex_h_
#define Complex_h_

class Complex {

private:
    double real; // the real portion, a, of the complex value a + bi
    double imaginary; // // the imaginary portion, b, of the complex value a + bi

public:
    Complex();
    Complex(double, double);
    Complex(double);
    ~Complex();
    double getReal();
    double getImag();
    void setReal(double);
    void setImag(double);
    void set(double, double);
    Complex operator+(Complex);
    Complex operator+(double);
    Complex operator-(Complex);
    Complex operator-(double);
    Complex operator*(Complex);
    Complex operator*(double);
    Complex operator/(Complex);
    Complex operator/(double);
    friend Complex operator+(double, Complex);
    friend Complex operator-(double, Complex);
    friend Complex operator*(double, Complex);
    friend Complex operator/(double, Complex);
    void operator+=(Complex);
    void operator-=(Complex);
    Complex operator^(int);
    bool operator==(Complex);
    bool operator!=(Complex);
    Complex operator=(Complex);
    friend ostream& operator<<(ostream&, Complex);
    friend istream& operator>>(istream&, Complex&);
    double mod();
};

#endif
