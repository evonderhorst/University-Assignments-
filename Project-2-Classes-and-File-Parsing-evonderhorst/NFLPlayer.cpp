// Author: Erich Vonderhorst
// Creation Date: 11/2/2023
// Last Update: 11/3/2023
#include "Person.h"
#include "NFLPlayer.h"

using namespace std;

// Description: default constructor for instances of NFLPlayer
NFLPlayer::NFLPlayer(): Person() {
    number = -1;
    position = "";
    team = "";
}

// Description: overloaded constructor for instances of NFLPlayer
// Notes: only way to assign values as this class and its base class do not have mutators
NFLPlayer::NFLPlayer(const string& f, const string& l, const FeetInches& h, const double& w, const Date& d, const int& n, const string& p, const string& t): Person() {
    firstName = f;
    lastName = l;
    height = h;
    weight = w;
    dob = d;
    number = n;
    position = p;
    team = t;
}

// Description: destructor for instances of NFLPlayer
// Notes: virtualized for inheritance
NFLPlayer::~NFLPlayer() {}

// Description: accessor for the position code of an NFLPlayer
// Return: the value of a code representing the current NFLPlayer's position such as 'K' for kicker or 'QB' for
//         quarterback
string NFLPlayer::getPosition() const {
    return position;
}

// Description: accessor for the number of an NFLPlayer
// Return: the value of the current NFLPlayer's number
int NFLPlayer::getNumber() const {
    return number;
}

// Description: accessor for the team code of an NFLPlayer
// Return: the value of a code representing the current NFLPlayer's team such as 'BAL' for the Baltimore Ravens
string NFLPlayer::getTeam() const {
    return team;
}

// Description: concatenates the values of all of a NFLPlayer's data members seperated by slashes into a string
// Return: a string containing the values of the current NFLPlayer's data members (includes inherited)
string NFLPlayer::toString() const {
    return Person::toString() + " / " + position + " / " + to_string(number) + " / " + team + " / NFL";
}
