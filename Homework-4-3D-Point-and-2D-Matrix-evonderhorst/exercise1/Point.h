#include <iostream>

using namespace std;

// Author: Erich Vonderhorst
// Creation Date: 10/05/2023
// Last Update: 10/05/2023
// Description: represents a three dimensional point in space. Contains members for the x, y, and z coordinates of the point
//              and several member and friend functions overloading several operators.

#ifndef Point_h_
#define Point_h_

class Point {

private:
    double x; // x dimension of point
    double y; // y dimension of point
    double z; // z dimension of point

public:
    Point();
    Point(double, double, double);
    Point(const Point&);
    double getX();
    double getY();
    double getZ();
    void setX(const double&);
    void setY(const double&);
    void setZ(const double&);
    void setXYZ(const double&, const double&, const double&);
    Point& operator=(const Point&);
    Point& operator+(const Point&) const;
    Point& operator-(const Point&) const;
    Point& operator*(const double&) const;
    friend Point& operator*(const double&, const Point&);
    Point& operator/(const double&) const;
    double operator*(const Point&) const;
    friend ostream& operator<<(ostream&, const Point&);
    bool operator==(const Point&);
    double length();

};

#endif
