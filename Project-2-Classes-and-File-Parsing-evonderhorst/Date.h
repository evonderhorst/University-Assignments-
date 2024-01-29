// Author: Erich Vonderhorst
// Creation Date: 11/2/2023
// Last Update: 11/3/2023
// Definition: represents a date in the Gregorian Calendar. Dates can be parsed from a string, converted to a
//             string, and compared using relational operators. Displayed in M/D/Y format when using out stream
//             operator.
// Notes: used as a data member by the Person class
#include <iostream>

using namespace std;

#ifndef Date_h_
#define Date_h_

class Date {
private:
    // Data Members
    int day;
    int month;
    int year;

public:

    // Constructors
    Date();
    Date(int,int,int);

    // Mutator
    void setDate(int,int,int);

    // Convert from String
    void setMDY(string);

    // Convert to String
    string toString() const;

    // Overloaded Relational Operators
    bool operator==(const Date&);
    bool operator!=(const Date&);
    bool operator>(const Date&);
    bool operator<(const Date&);
    bool operator>=(const Date&);
    bool operator<=(const Date&);

    // Overloaded Out Stream Operator
    friend ostream& operator<<(ostream&, const Date&);
};

#endif
