// Author: Erich Vonderhorst
// Creation Date: 11/2/2023
// Last Update: 11/3/2023
// Description: stores the personal data (full name, height, weight, date of birth) of any person. Includes
//              standard accessors but no mutators, and a function to return all of the data as a single string.
// Notes: base type for NBAPlayer and NFLPlayer types
#include <iostream>
#include "Date.h" // for date of birth member
#include "FeetInches.h" // for height member

using namespace std;

#ifndef Person_h_
#define Person_h_

class Person {
protected:
    // Data Members
    string firstName; // first name of a person
    string lastName; // last name of a person
    FeetInches height; // height of a person in feet and inches
    double weight; // weight of a person in lbs.
    Date dob; // the day a person was born (M/D/Y)

public:
    // Constructors
    Person();
    Person(const string&,const string&,const FeetInches&,const double&,const Date&);

    // Destructor
    virtual ~Person();

    // Accessors
    string getFormalName() const;
    string getInformalName() const;
    FeetInches getHeight() const;
    double getWeight() const;
    Date getDOB() const;

    // Convert to String
    virtual string toString() const;
};

#endif
