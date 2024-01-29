// Author: Erich Vonderhorst
// Creation Date: 11/2/2023
// Last Update: 11/3/2023
// Description: stores the personal data described in the Person class as well as the number and position code
//              of an NBA player. Includes the same functionalities as the base class with accessors for the
//              the new members and an overwritten verstion of the toString function.
// Notes: type derived from the Person class

#include "Person.h"

using namespace std;

#ifndef NBAPlayer_h_
#define NBAPlayer_h_

class NBAPlayer: public Person {
protected:
    // Data Members
    int number; // the number on an NBA player's jersey
    string position;    // a code for the position an NBA player plays on defense such as 'C' for center

public:
    // Constructors
    NBAPlayer();
    NBAPlayer(const string&,const string&,const FeetInches&,const double&,const Date&,const int&,const string&);

    // Destructor
    virtual ~NBAPlayer();

    // Accessors
    string getPosition();
    int getNumber();

    // Convert to String
    virtual string toString() const;

};

#endif
