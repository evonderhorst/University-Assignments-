// Author: Erich Vonderhorst
// Creation Date: 10/11/2023
// Last Update: 10/13/2023

#include "PersonData.h"

using namespace std;

// Description: default constructor for instances of PersonData
// Return: a new instance of PersonData
PersonData:: PersonData() {
 
    firstName = "";
    lastName = "";
    address = "";
    city = "";
    state = "";
    zip = "";
    phone = "";
}

// Description: destructor for instances of PersonData
// Notes: overwritten for both of this abstract base class' derived classes
PersonData:: ~PersonData() {}

// Description: standard accessor for the firstName data member
// Return: the value of the firstName data member
string PersonData:: getFirstName() {
    
    return firstName;
}

// Description: standard accessor for the lastName data member
// Return: the value of the lastName data member
string PersonData:: getLastName() {
        
    return lastName;
}

// Description: standard accessor for both the firstName and lastName data members
// Return: a string containing the values of the firstName and lastName data members
string PersonData:: getName() {
        
    return firstName + " " + lastName;
}

// Description: standard accessor for the address data member
// Return: the value of the address data member
string PersonData:: getAddress() {
        
    return address;
}

// Description: standard accessor for the city data member
// Return: the value of the city data member
string PersonData:: getCity() {
        
    return city;
}

// Description: standard accessor for the state data member
// Return: the value of the state data member
string PersonData:: getState() {
        
    return state;
}

// Description: standard accessor for zip data member
// Return: the value of the zip data member
string PersonData:: getZip() {
 
    return zip;
}

// Description: standard accessor for the phone data member
// Return: the value of the phone data member
string PersonData:: getPhone() {
 
    return phone;
}

// Description: standard mutator for the firstName data member
// Parameters:
//      string newName: value for firstName to be set to
void PersonData:: setFirstName(string newName) {

    firstName = newName;
}

// Description: standard mutator for the lastName data member
// Parameters:
//      string newName: value for lastName to be set to
void PersonData:: setLastName(string newName) {
        
    lastName = newName;
}

// Description: standard mutator for the firstName and lastName data members
// Parameters:
//      string newFirst: value for firstName to be set to
//      string newLast: value for lastName to be set to
void PersonData:: setName(string newFirst, string newLast) {
 
    firstName = newFirst;
    lastName = newLast;
}

// Description: standard mutator for the address, city, state, and zip data members
// Parameters:
//      string newAdd: value for address to be set to
//      string newCity: value for city to be set to
//      string newState: value for state to be set to
//      string newZip: value for zip to be set to
void PersonData:: setAddress(string newAdd, string newCity, string newState, string newZip) {
        
    address = newAdd;
    city = newCity;
    state = newState;
    zip = newZip;
}

// Description: standard mutator for the address data member
// Parameters:
//      string newStreet: value for address to be set to
void PersonData:: setStreet(string newStreet) {

    address = newStreet;
}

// Description: standard mutator for the city data member
// Parameters:
//      string newCity: value for city to be set to
void PersonData:: setCity(string newCity) {
        
    city = newCity;
}

// Description: standard mutator for the state data member
// Parameters:
//      string newState: value for state to be set to
void PersonData:: setState(string newState) {
        
    state = newState;
}

// Description: standard mutator for the zip data member
// Parameters:
//      string newZip: value for zip to be set to
void PersonData:: setZip(string newZip) {
 
    zip = newZip;
}

// Description: standard mutator for the phone data member
// Parameters:
//      string newPhoneWhoDis: value for phone to be set to
void PersonData:: setPhone(string newPhoneWhoDis) {
 
    phone = newPhoneWhoDis;
    
}

// Description: function for displaying the data stored in the current object in a multiple line, more descriptive format
// Notes: overwritten for both of this abstract base class' derived classes
void PersonData:: printRecord() {
        
    cout << lastName << ", " << firstName << endl;
    cout << address << endl;
    cout << city << ", " << state << " " << zip << endl;
    cout << phone << endl;
}

// Description: creates a single line string containing the data stored in the current instance
// Return: the string containing all the data of the current instance
// Notes: overwritten for both of this abstract base class' derived classes
string PersonData:: getRecord() {
    
    return firstName + " " + lastName + " / " + address + " / " + city + ", " + state + " " + zip + " / " + phone;
}
