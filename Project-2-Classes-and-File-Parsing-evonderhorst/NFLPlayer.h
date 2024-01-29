// Author: Erich Vonderhorst
// Creation Date: 11/2/2023
// Last Update: 11/3/2023
// Description: stores the personal data described in the Person class as well as the number, position code, and
//              team code of an NFL player. Includes the same functionalities as the base class with accessors
//              for the new members and an overwritten verstion of the toString function.
// Notes: type derived from the Person class
#include "Person.h"

using namespace std;

#ifndef NFLPlayer_h_
#define NFLPlayer_h_
class NFLPlayer: public Person {
protected:
    // Data Members
    int number; // the number on an NFL player's jersey
    string position; // a code for the position of an NFL player such as 'QB' for quarterback
    string team; // the team an NFL player plays for
public:
    // Constructors
    NFLPlayer();
    NFLPlayer(const string&,const string&,const FeetInches&,const double&,const Date&,const int&,const string&,const string&);

    // Destructor
    virtual ~NFLPlayer();

    // Accessors
    string getPosition() const;
    int getNumber() const;
    string getTeam() const;

    // Convert to String
    virtual string toString() const;
};

#endif
