#include <iostream>
#include <cmath>
#include "Point.h"

using namespace std;

// Author: Erich Vonderhorst
// Creation Date: 10/05/2023
// Last Update: 10/05/2023


// Description: default constructor for Point class
// Return: a new instance of the Point class
Point:: Point() {

    x = 0;
    y = 0;
    z = 0;
}

// Description: overloaded constructor for Point class
// Parameters:
//      double cx: value x will be set to
//      double cy: value y will be set to
//      double cz: value z will be set to
// Return: a new instance of the Point class
Point:: Point(double cx, double cy, double cz) {

    x = cx;
    y = cy;
    z = cz;
}

// Description: copy constructor for Point class
// Parameters:
//      const Point& rhs: passed instance from which the created instance will copy its values
// Return: a new instance of the Point class

Point:: Point(const Point& rhs) {

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
}

// Description: accessor for the member x
// Return: the value of member x
double Point:: getX() {

    return x;
}

// Description: accessor for the member y
// Return: the value of member y
double Point:: getY() {

    return y;
}

// Description: accessor for member z
// Return: the value of member z
double Point:: getZ() {

    return z;
}

// Description: mutator for member x
// Parameters:
//      const double& newX: value that x will be set to
// Return: void
void Point:: setX(const double& newX) {

    x = newX;
}

// Description: mutator for member y
// Parameters:
//      const double& newY: value that y will be set to
// Return: void
void Point:: setY(const double& newY) {

    y = newY;
}

// Description: mutator for member z
// Parameters:
//      const double& newZ: value that z will be set to
// Return: void
void Point:: setZ(const double& newZ) {

    z = newZ;
}

// Description: mutator for all three members
// Parameters:
//      const double& newX: value that x will be set to
//      const double& newY: value that y will be set to
//      const double& newZ: value that z will be set to
// Return: void
void Point:: setXYZ(const double& newX, const double& newY, const double& newZ) {

    x = newX;
    y = newY;
    z = newZ;
}

// Description: overloaded assignment operator for Point class
// Parameters:
//      const Point& rhs: instance from which the current instance will copy its values
// Return: the current instance of Point
Point& Point:: operator=(const Point& rhs) {

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

// Description: overloaded addition operator for Point class
// Parameters:
//      const Point& rhs: instance that will have its member values added to those of the current instance
// Return: dynamic instance of Point containing the modified values
// Notes: neither the current or passed instance are altered by this function
Point& Point:: operator+(const Point& rhs) const {

    return *(new Point(x + rhs.x, y + rhs.y, z + rhs.z));
}

// Description: overloaded subtraction operator for Point class
// Parameters:
//      const Point& rhs: instance that will have its member values subtracted from those of the current instance
// Return: dynamic instance of Point containing the modified values
// Notes: neither the current or passed instance are altered by this function
Point& Point:: operator-(const Point& rhs) const {

    return *(new Point(x - rhs.x, y - rhs.y, z - rhs.z));
}

// Description: overloaded multiplication operator for Point class (scalar multiplication)
// Parameters:
//      const double& rhs: value that the current instance's member values will be multiplied by
// Return: dynamic instance of Point containing the modified values
// Notes: the current instance is not altered by this function
Point& Point:: operator*(const double& rhs) const {

    return *(new Point(x * rhs, y * rhs, z * rhs));
}

// Description: overloaded division operator for Point class
// Parameters:
//      const double& rhs: value that the current instance's member values will be divided by
// Return: dynamic instance of Point containing the modified values
// Notes: the current instance is not altered by this function
Point& Point:: operator/(const double& rhs) const {

    return *(new Point(x / rhs, y / rhs, z / rhs));
}

// Description: overloaded multiplication operator for Point class (scalar product)
// Parameters:
//      const Point& rhs: instance that will have its member values multiplied by those of the current instance
// Return: dynamic instance of Point containing the modified values
// Notes: neither the current or passed instance are altered by this function
double Point:: operator*(const Point& rhs) const{

    return ((x * rhs.x) + (y * rhs.y) + (z * rhs.z));
}

// Description: overloaded comparison operator for Point class
// Parameters:
//      const Point& rhs: instance that will have its member values compared to those of the current instance
// Return: true or false depending on whether the member values of both instances are the same
bool Point:: operator==(const Point& rhs) {

    if (x == rhs.x && y == rhs.y && z == rhs.z)
        return true;

    return false;
}

// Description: calculates and returns the distance of the point from the origin
// Return: the distance of the point from the origin
double Point:: length() {

    return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}

// Description: overloaded multiplication operator for scalar multiplication between a value and a Point
// Parameters:
//      const double& lhs: value the members of the passed instance will be multiplied by
//      const Point& rhs: instance that will have its member values multiplied by the passed value
// Return: dynamic instance of Point containing the modified values
// Notes: the passed instance is not altered by this function
Point& operator*(const double& lhs, const Point& rhs) {

    return *(new Point(rhs.x * lhs, rhs.y * lhs, rhs.z * lhs));
}

// Description: overloaded insertion operator for printing the data of a Point in a readable format
// Parameters:
//      ostream& display: output stream being used to print the information
//      const Point& rhs: instance that will have its member values printed
// Return: the output stream currently being used
ostream& operator<<(ostream& display, const Point& rhs) {

    display << "(" << rhs.x << ", " << rhs.y << ", " << rhs.z << ") ";
    return display;
}
