// Author: Erich Vonderhorst
// Creation Date: 11/2/2023
// Last Update: 11/3/2023

#include "Person.h"
#include "NBAPlayer.h"

using namespace std;

// Description: constructor for instances of NBAPlayer
NBAPlayer::NBAPlayer(): Person() {
    number = -1;
    position = "";
}

// Description: overloaded constructor for instances of NBAPlayer
// Notes: only way to assign values as this class and its base class don't have mutators
NBAPlayer::NBAPlayer(const string& f, const string& l, const FeetInches& h, const double& w, const Date& d, const int& n, const string& p): Person() {
    firstName = f;
    lastName = l;
    height = h;
    weight = w;
    dob = d;
    number = n;
    position = p;
}

// Description: destructor for instances of NBAPlayer
// Notes: virtualized for inheritance
NBAPlayer::~NBAPlayer() {}

// Description: accessor for the position code of an NBAPlayer
// Return: the value of a code for the current NBAPlayer's position such as 'C' for center or 'PF' for power
//         front
string NBAPlayer::getPosition() {
    return position;
}

// Description: accessor for the number of an NBAPlayer
// Return: the value of the number of an NBAPlayer
int NBAPlayer::getNumber() {
    return number;
}

// Description: concatenates the values of all of a NBAPlayer's data members seperated by slashes into a string
// Return: a string containing the values of the current NBAPlayer's data members (includes inherited)
string NBAPlayer::toString() const {
    return Person::toString() + " / " + position + " / " + to_string(number) + " / NBA";
}
