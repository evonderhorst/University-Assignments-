// Author: Erich Vonderhorst
// Creation Date: 10/11/2023
// Last Update: 10/13/2023

#include "PreferredCustomer.h"

using namespace std;

// Description: default constructor for instances of PreferredCustomer
// Return: a new instance of PreferredCustomer
PreferredCustomer:: PreferredCustomer() {

    purchasesAmount = 0.0;
    discountLevel = 0.0;
}

// Description: copy constructor for instances of PreferredCustomer with the base class CustomerData
// Parameters:
//      CustomerData* copy: instance of the base class to have its member values copied over
// Return: a new instance of PreferredCustomer
PreferredCustomer:: PreferredCustomer(CustomerData* copy) : CustomerData() {

    firstName = copy->getFirstName();
    lastName = copy->getLastName();
    address = copy->getAddress();
    city = copy->getCity();
    state = copy->getState();
    zip = copy->getZip();
    phone = copy->getPhone();
    customerNumber = copy->getCustomerNumber();
    mailingList = copy->getMailingList();
}

// Description: destructor for instances of PreferredCustomer
// Notes: overwritten for this derived class
PreferredCustomer:: ~PreferredCustomer() {}

// Description: standard accessor for the purchasesAmount data member
// Return: the value of the purchasesAmount data member
double PreferredCustomer:: getAmount() {

    return purchasesAmount;
}

// Description: standard mutator for the purchasesAmount data member
// Parameters:
//      double newAmount: value for the member to be set to
void PreferredCustomer:: setAmount(double newAmount) {

    purchasesAmount = newAmount;
}

// Description: standard accessor for the discountLevel data member
// Return: the value of the discountLevel data member
double PreferredCustomer:: getDiscount() {

    return discountLevel;
}

// Description: standard mutator for the discountLevel data member
// Parameters:
//      double newDiscount: value for the member to be set to
void PreferredCustomer:: setDiscount(double newDiscount) {

    discountLevel = newDiscount;
}

// Description: prints the data stored in the current instance in a multiple line, more descriptive format
// Notes: overwritten for this derived class
void PreferredCustomer:: printRecord() {

    // Call this function but for the base class to display inherited members
    CustomerData:: printRecord();

    // Print the remaining data
    cout << "Purchases Amount: " << purchasesAmount << endl;
    cout << "Discount Level: " << (discountLevel * 100) << "%" << endl;
}

// Description: creates a single line string containing the data stored in the current instance
// Return: the string containing all the data of the current instance
// Notes: overwritten for this derived class
string PreferredCustomer:: getRecord() {

    // Initialize the string to the value returned by this function but for the base class so it can contain inherited members
    string record = CustomerData::getRecord();

    // Append the string with the remaining data
    record += " / Account: $" + to_string(purchasesAmount) + " / Discount: " + to_string(discountLevel * 100) + "%";

    // Return the string
    return record;
}
