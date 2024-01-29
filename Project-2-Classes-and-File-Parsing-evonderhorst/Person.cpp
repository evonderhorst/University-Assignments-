// Author: Erich Vonderhorst
// Creation Date: 11/2/2023
// Last Update: 11/3/2023
#include "Person.h"

using namespace std;

// Description: default constructor for instances of Person
Person::Person() {
    firstName = "";
    lastName = "";
    height = FeetInches();
    weight = 0.0;
    dob = Date();
}

// Description: overloaded constructor for instances of Person
// Notes: only way to assign values to data members as this class has no mutators
Person::Person(const string& f, const string& l, const FeetInches& h, const double& w, const Date& d) {
    firstName = f;
    lastName = l;
    height = h;
    weight = w;
    dob = d;
}

// Description: destructor for instances of Person
// Notes: virtualized for inheritance
Person::~Person() {}

// Description: accessor for the full name of a Person in a formal format
// Return: the first and last name of the current Person in a last, first format
string Person::getFormalName() const {
    return lastName + ", " + firstName;
}

// Description: accessor for the full name of a Person in an informal format
// Return: the first and last name of the current Person in a first last format
string Person::getInformalName() const {
    return firstName + " " + lastName;
}

// Description: accessor for the height of a Person
// Return: the value of the current Person's height
FeetInches Person::getHeight() const {
    return height;
}

// Description: accessor for the weight of a person
// Return: the value of the current Person's weight
double Person::getWeight() const {
    return weight;
}

// Description: accessor for a Person's date of birth
// Return: the value of the current Person's data of birth
Date Person::getDOB() const {
    return dob;
}

// Description: concatenates the values of all of a Person's data members seperated by slashes into a string
// Return: a string containing the values of the current Person's data members
string Person::toString() const {
    return getFormalName() + " / " + height.toString() + " / " + to_string(weight) + " / " + dob.toString();
}
