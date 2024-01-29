// Author: Erich Vonderhorst
// Creation Date: 11/2/2023
// Last Update: 11/3/2023
#include "Date.h"

using namespace std;

// Description: default constructor for instances of Date
Date::Date() {
    day = 0;
    month = 0;
    year = 0;
}

// Description: overloaded constructor for instances of Date
Date::Date(int d,int m, int y) {
    day = d;
    month = m;
    year = y;
}

// Description: mutator for all three members of a Date
void Date::setDate(int d,int m, int y) {
    day = d;
    month = m;
    year = y;
}

// Description: parses a string with a date in M/D/Y format into values for a month, day, and year and assigns
//              them to the members of a Date
// Parameters:
//              dateStr: the string to be parsed into a Date
void Date::setMDY(string dateStr) {
    int divider = dateStr.find("/"); // index of the string containing the slash that divides the day, month, and year
    try {
        month = stoi(dateStr.substr(0, divider));
    } catch (exception& e) {
        month = 0;
    }

    // Erase what has already been parsed to simplify the rest of the process
    dateStr.erase(0, divider + 1);
    divider = dateStr.find("/");
    try {
        day = stoi(dateStr.substr(0, divider));
    } catch (exception& e) {
        day = 0;
    }

    try {
        year = stoi(dateStr.substr(divider + 1));
    } catch (exception& e) {
        year = 0;
    }
}

// Description: converts a Date into a string with the Date shown in a M/D/Y format
// Return: the string containing the current Date
string Date::toString() const {
    return to_string(month) + "/" + to_string(day) + "/" + to_string(year);
}

// Description: overloaded equality operator for two Dates
// Parameters:
//              rhs: the Date to be compared with the current one
// Return: true or false depending on if the two dates are equal
bool Date::operator==(const Date& rhs) {
    if (month == rhs.month && day == rhs.day && year == rhs.year)
        return true;

    else
        return false;
}// Description: overloaded 'greater than' operator for two Dates
// Parameters:
//              rhs: the Date to be compared with the current one
// Return: true or false depending on if the current Date comes chronologically after the other

// Description: overloaded inequality operator for two Dates
// Parameters:
//              rhs: the Date to be compared with the current one
// Return: true or false depending on if the two Dates are unequal
bool Date::operator!=(const Date& rhs) {
    return !(*this == rhs);
}

// Description: overloaded 'greater than' operator for two Dates
// Parameters:
//              rhs: the Date to be compared with the current one
// Return: true or false depending on if the current Date comes chronologically after the other
bool Date::operator>(const Date& rhs) {
   if (year > rhs.year)
        return true;
    else if (year == rhs.year && month > rhs.month)
        return true;
    else if (year == rhs.year && month == rhs.month && day > rhs.day)
        return true;
    else
        return false;
}

// Description: overloaded 'less than' operator for two Dates
// Parameters:
//              rhs: the Date to be compared with the current one
// Return: true or false depending on if the current Date comes chronologically before the other
bool Date::operator<(const Date& rhs) {
    if (rhs.year > year)
        return true;
    else if (year == rhs.year && rhs.month > month)
        return true;
    else if (year == rhs.year && month == rhs.month && rhs.day > day)
        return true;
    else
        return false;
}

// Description: overloaded 'greater than or equal to' operator for two Dates// Description: overloaded 'greater than' operator for two Dates
// Parameters:
//              rhs: the Date to be compared with the current one
// Return: true or false depending on if the current Date comes chronologically after the other
// Parameters:
//              rhs: the Date to be compared with the current one
// Return: true or false depending on if the current Date comes chronologically after or is the same as the
//         other
bool Date::operator>=(const Date& rhs) {
    if (year > rhs.year)
        return true;
    else if (year == rhs.year && month > rhs.month)
        return true;
    else if (year == rhs.year && month == rhs.month && day >= rhs.day)
        return true;// Description: overloaded 'greater than' operator for two Dates
// Parameters:
//              rhs: the Date to be compared with the current one
// Return: true or false depending on if the current Date comes chronologically after the other
    else
        return false;
}

// Description: overloaded 'less than or equal to' operator for two Dates
// Parameters:
//              rhs: the Date to be compared with the current one
// Return: true or false depending on if the current Date comes chronologically before or is the same as the
//         other
bool Date::operator<=(const Date& rhs) {
    if (rhs.year > year)
        return true;
    else if (year == rhs.year && rhs.month > month)
        return true;
    else if (year == rhs.year && month == rhs.month && rhs.day >= day)
        return true;
    else
        return false;
}

// Description: overloaded out stream operator for a Date that prints out its string conversion
// Parameters:
//              out: the out stream being used
//              rhs: the Date to be printed
// Return: the out stream that was used
ostream& operator<<(ostream& out, const Date& rhs) {
    out << rhs.toString();
    return out;
}
