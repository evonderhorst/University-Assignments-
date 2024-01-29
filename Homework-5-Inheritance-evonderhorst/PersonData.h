// Author: Erich Vonderhorst
// Creation Date: 10/11/2023
// Last Update: 10/13/2023
// Description: base type representing an entry in a database for people. Has several members containing different pieces of
//              personal data such name and address. Member functions are standard accesors, and mutators as well as two virtual
//              functions for displaying the data stored in the object.
// Notes: abstract base class of two derived classes: CustomerData and PreferredCustomer (extends the former).

#include <string>
#include <iostream>

using namespace std;

#ifndef PersonData_h_
#define PersonData_h_

class PersonData {
    
protected:
    string firstName; // a person's first name
    string lastName; // a person's last name
    string address; // a person's home address
    string city; // the city a person lives in
    string state; // the state a person lives in
    string zip; // the zip code of a person's residence
    string phone; // a person's phone number
    
public:
    PersonData();
    virtual ~PersonData();
    string getFirstName();
    string getLastName();
    string getName();
    string getAddress();
    string getCity();
    string getState();
    string getZip();
    string getPhone();
    void setFirstName(string);
    void setLastName(string);
    void setName(string, string);
    void setAddress(string, string, string, string);
    void setStreet(string);
    void setCity(string);
    void setState(string);
    void setZip(string);
    void setPhone(string);
    virtual void printRecord();
    virtual string getRecord();
};

#endif
