// Author: Erich Vonderhorst
// Creation Date: 10/11/2023
// Last Update: 10/13/2023

#include "PersonData.h"
#include "CustomerData.h"

using namespace std;

// Description: default constructor for instances of CustomerData
// Return: a new instance of CustomerData
CustomerData:: CustomerData(): PersonData() {
        
    customerNumber = 0;
    mailingList = true;
}

// Description: copy constructor for instances of CustomerData with the base class PersonData
// Parameters:
//      PersonData* copy: instance of the base class to have its member values copied over
// Return: a new instance of CustomerData
CustomerData:: CustomerData(PersonData* copy): PersonData() {

    firstName = copy->getFirstName();
    lastName = copy->getLastName();
    address = copy->getAddress();
    city = copy->getCity();
    state = copy->getState();
    zip = copy->getZip();
    phone = copy->getPhone();
}

// Description: destructor for instances of CustomerData
// Notes: overwritten for this derived class and its own derived class
CustomerData:: ~CustomerData() {}

// Description: standard accessor for the customerNumber data member
// Return: the value of the customerNumber data member
int CustomerData:: getCustomerNumber() {
        
    return customerNumber;
}

// Description: standard accessor for the mailingList data member
// Return: the value of the mailingList data member
bool CustomerData:: getMailingList() {
        
    return mailingList;
}

// Description: standard mutator for the customerNumber data member
// Parameters:
//      int newNum: value for customerNumber to be set to
void CustomerData:: setCustomerNumber(int newNum) {
    
    customerNumber = newNum;
}

// Description: standard mutator for the mailingList data member
// Parameters:
//      int newBool: value for mailingList to be set to
void CustomerData:: setMailingList(bool newBool) {
    
    mailingList = newBool;
}

// Description: function for displaying the data stored in the current object in a multiple line, more descriptive format
// Notes: overwritten for this derived class and its own derived class
void CustomerData:: printRecord() {

    PersonData:: printRecord();
    cout << "Customer Number: " << customerNumber << endl;
    cout << "On the Mailing List: ";
    if (mailingList == true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

// Description: creates a single line string containing the data stored in the current instance
// Return: the string containing all the data of the current instance
// Notes: overwritten for this derived class and its own derived class
string CustomerData:: getRecord() {

    // Initialize the string to the value returned by this function but for the base class so it can contain inherited members
    string record = PersonData::getRecord();

    // Append the string with the remaining data
    record += " / C#: " + to_string(customerNumber) + " / ML: ";

    // Translate the boolean value to yes or no
    if (mailingList == true)
        record += "Yes";
    else
        record += "No";

    // Return the string
    return record;
}
