// Author: Erich Vonderhorst
// Creation Date: 10/11/2023
// Last Update: 10/13/2023
// Description: derived type representing an entry in a database of customers. Has members that represent specific information a store may have
//              about a customer. Member functions are standard accessors and mutators as well as a copy constructor and two virtual functions
//              for displaying the data in the instance.
// Notes: is derived from and inherits all members from base type PersonData.

#include "PersonData.h"

using namespace std;

#ifndef CustomerData_h_
#define CustomerData_h_

class CustomerData: public PersonData {
    
protected:
    int customerNumber; // identification number for a customer
    bool mailingList; // whether or not the customer wants to be on the mailing list
    
public: 
    CustomerData();
    CustomerData(PersonData*);
    virtual ~CustomerData();
    int getCustomerNumber();
    bool getMailingList();
    void setCustomerNumber(int);
    void setMailingList(bool);
    virtual void printRecord();
    virtual string getRecord();
};

#endif
