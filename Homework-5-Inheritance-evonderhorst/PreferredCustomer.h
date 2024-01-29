// Author: Erich Vonderhorst
// Creation Date: 10/11/2023
// Last Update: 10/13/2023
// Description: derived type representing an entry in database for a customer that is a regular or is pert of a loyalty program
//              at a store. Has members that represent how much the customer has spent and how much of a discount they receive as
//              a reward. Member functions include standard accessors and mutators as well as a copy constructor and two virtual
//              functions for displaying the data in the instance.
// Notes: is derived from and inherits all members from CustomerData which is derived and inherits all members from PersonData.

#include "CustomerData.h"

using namespace std;

#ifndef PreferredCustomer_h_
#define PreferredCustomer_h_

class PreferredCustomer: public CustomerData {

protected:
    double purchasesAmount; // the total amount of dollars a customer has spent in purchases
    double discountLevel; // the percentage discount a customer receives for certain milestones of their total purchases

public:
    PreferredCustomer();
    PreferredCustomer(CustomerData*);
    virtual ~PreferredCustomer();
    double getAmount();
    void setAmount(double);
    double getDiscount();
    void setDiscount(double);
    virtual void printRecord();
    virtual string getRecord();
};

#endif
