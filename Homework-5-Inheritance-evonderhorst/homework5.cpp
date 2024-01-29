// Author: Erich Vonderhorst
// Creation Date: 10/11/2023
// Last Update: 10/13/2023
// Description: this program represents a database for the personal information people and customers. Personal data such as full
//              name and home address are recorded for each entry as well as more specific information regarding their status as a
//              customer or preferred customer. The user is prompted to enter each piece of data after selecting what type of object
//              they wish to add to the database. The database can hold up to 10 objects.
// User Interface:
//          "Choice: ": enter one of the integers next to an option on the above menu to add objects, display the database, or quit
//                      the program.
//                      1: creates a PersonData object which contains information about a person such as their full name and home
//                         address.
//                      2: creates a CustomerData object which contains a customer number and records whether or not a customer
//                         wants to be on the mailing list in addition to all information stored in a PersonData object.
//                      3: creates a PreferredCustomer object which contains the total dollar amount a customer has made in
//                         purchases and the percentage discount they receive as a reward for certain milestones of total purchases
//                         in addition to the information stored in PersonData and CustomerData objects.
//                      4: displays the information stored in all database entries with each entry being displayed over multiple,
//                         more descriptive lines.
//                      5: displays the information stored in all database entries with each entry being displayed in a single line.
//                      6: exits the program.
//          "Input x: ": enter a specific value for the current database entry.
// Notes: all given input is validated.

#include "PersonData.h"
#include "CustomerData.h"
#include "PreferredCustomer.h"

using namespace std;

// Function prototypes
void printMenu();
int menuSelect();
void menuProcess(PersonData**, int&, int);
PersonData* addPerson();
CustomerData* addCustomer();
PreferredCustomer* addPreferred();
void printDataLong(PersonData**, int);
void printDataShort(PersonData**, int);

//------------------------------------------------------------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------------------------------------------------------------
int main() {

    PersonData** baseArray = new PersonData*[10]; // stores all database objects
    int databaseSize = 0; // number of objects added to the database
    int choice = 0; // value corresponding to a menu option entered by the user

    // Main program loop
    while (databaseSize < 10 && choice != 6) {

        printMenu();
        choice = menuSelect();
        menuProcess(baseArray, databaseSize, choice);
    }

    // Deallocate dynamic array
    for (int i = 0; i < databaseSize; i++)
        delete baseArray[i];
    delete[] baseArray;

    return 0;
}

//------------------------------------------------------------------------------------------------------------------------------
// Free Functions
//------------------------------------------------------------------------------------------------------------------------------

// Description: a basic function to display the menu options to the user
void printMenu() {

    cout << "1. Add Personal Data Object" << endl;
    cout << "2. Add Customer Data Object" << endl;
    cout << "3. Add Preferred Customer Data Object" << endl;
    cout << "4. View Database Long Form" << endl;
    cout << "5. View Database Short Form" << endl;
    cout << "6. Quit" << endl;
    cout << "Choice: ";
}

// Description: validates the user's input when selecting an option from the menu
// Return: the integer value of the option the user selected
int menuSelect() {

    string choice; // holds user's input

    // Read in the user's input
    getline(cin, choice);

    // Validate the user's input

    try {

        // Check if the value is in range
        if (stoi(choice) >= 1 && stoi(choice) <= 6)
            return stoi(choice);

        else {

            cout << "Invalid selection, try again: ";
            return menuSelect();
        }
    }

    // If the invalid_argument exception is thrown for the stoi function, the user did not enter a valid integer value
    catch(exception& darn) {

        cout << "Invalid selection, try again: ";
        return menuSelect();
    }
}

// Description: calls the appropriate function based on the value of the menu option entered by the user.
// Parameters:
//      PersonData** arr: database array of the base type which stores all added objects.
//      int& elements: the number of objects that have been added to the database.
//      int option: value corresponding to a menu option entered by the user.
// Notes: option must be validated as a precondition
void menuProcess(PersonData** arr, int& elements, int option) {

    // 1. Add Personal Data Object
    if (option == 1) {

        if (elements == 10)
            cout << endl << "The array is full." << endl;

        else
            arr[elements++] = addPerson();

        cout << endl;
    }

    // 2. Add Customer Data Object
    else if (option == 2) {

        if (elements == 10)
            cout << endl << "The array is full." << endl;

        else
            arr[elements++] = addCustomer();

        cout << endl;
    }

    // 3. Add Preferred Customer Data Object
    else if (option == 3) {

        if (elements == 10)
            cout << endl << "The array is full." << endl;

        else
            arr[elements++] = addPreferred();

        cout << endl;
    }

    // 4. View Database Long Form
    else if (option == 4)
        printDataLong(arr, elements);

    // 5. View Database Short Form
    else if (option == 5)
        printDataShort(arr, elements);

    // 6. Quit
    else
        return; // If the user entered 6, it will the condition in the while loop in main
}

// Description: creates a PersonData object containing values entered by the user.
// Return: a pointer to a PersonData object containing the values entered by the user.
PersonData* addPerson() {

    string input; // holds the user's input
    PersonData* temp = new PersonData; // temporary pointer to the object that will contain the user's values

    // Have the user enter each piece of data
    cout << endl << "Input Last Name: ";
    getline(cin, input);
    temp->setLastName(input);

    cout << "Input First Name: ";
    getline(cin, input);
    temp->setFirstName(input);

    cout << "Input Street Address: ";
    getline(cin, input);
    temp->setStreet(input);

    cout << "Input City: ";
    getline(cin, input);
    temp->setCity(input);

    cout << "Input State: ";
    getline(cin, input);
    temp->setState(input);

    cout << "Input Zip Code: ";
    getline(cin, input);
    temp->setZip(input);

    cout << "Input Phone Number: ";
    getline(cin, input);
    temp->setPhone(input);

    // Return the object's memory address
    return temp;
}

// Description: creates a CustomerData object containing values entered by the user.
// Return: a pointer to a CustomerData object containing the values entered by the user.
CustomerData* addCustomer() {

    PersonData* temp1 = addPerson(); // temporary pointer to an object of the base class for having the user input all of its values
    CustomerData* temp2 = new CustomerData(temp1); // copy construct an instance of the derived class from the base class instance
                                                   // just created and point to it with a another temporary pointer
    delete temp1; // deallocate the temporary pointer to the base class

    string input; // holds the user's input
    int input2 = -1; // holds the value of the user's input after it has been casted to an integer

    // Have the user input the rest of the data values and validate their input
    cout << "Input Customer Number: ";

    do {

        try {

            getline(cin, input);
            input2 = stoi(input);

            // Make sure the value is not negative
            if (input2 < 0)
                cout << "Customer Number cannot be negative: ";
        }

        // If the invalid_argument exception was thrown for the stoi function, then the user did not enter a valid integer value
        catch (exception& bad) {

            cout << "Customer Number must be a positive integer value: ";
        }

    } while (input2 < 0);


    temp2->setCustomerNumber(input2);

    cout << "Do they wish to be on the mailing list? (Y/N): ";

    do {

        getline(cin, input);

        // Check if the user entered y or n, not case sensitive
        if (input != "Y" && input != "y" && input != "N" && input != "n")
            cout << "Select either Y or N: ";

    } while (input != "Y" && input != "y" && input != "N" && input != "n");

    // Translate user's response to either true or false
    if (input == "Y" || input == "y")
        temp2->setMailingList(true);

    else
        temp2->setMailingList(false);

    // Return the object's memory address
    return temp2;
}

// Description: creates a PreferredCustomer object containing values entered by the user.
// Return: a pointer to a PreferredCustomer object containing the values entered by the user.
PreferredCustomer* addPreferred() {

    CustomerData* temp1 = addCustomer(); // pointer to a temporary instance of the base class for having the user enter its values
    PreferredCustomer* temp2 = new PreferredCustomer(temp1); // copy construct an instance of the derived class from the base class
                                                             // instance just created and point to it with another temporary pointer
    delete temp1; // deallocate the temporary pointer to the base class

    string input; // holds the user's input
    double input2 = -1; // holds the value of the user's input after it has been casted to a double

    // Have the user enter the last of the data value and validate their input
    cout << "Input Purchases Amount: ";

    do {

        try {
            getline(cin, input);
            input2 = stod(input);

            // Make sure the value is not negative
            if (input2 < 0)
                cout << "Purchases Amount cannot be negative: ";
        }

        // If the invalid_argument exception was thrown for the stod function, then the user did not enter a valid decimal value
        catch(exception& uhoh) {
            cout << "Purchases Amount must be a positive decimal value: ";
        }

    }  while (input2 < 0);

    temp2->setAmount(input2);

    // Determine the discount a customer receives based on how much they've spent in purchases
    if (temp2->getAmount() >= 2000)
        temp2->setDiscount(0.1);

    else if (temp2->getAmount() >= 1500)
        temp2->setDiscount(0.07);

    else if (temp2->getAmount() >= 1000)
        temp2->setDiscount(0.06);

    else if (temp2->getAmount() >= 500)
        temp2->setDiscount(0.05);

    else
        temp2->setDiscount(0.0);

    // Return the object's memory address
    return temp2;
}

// Description: prints the data of each object in the database in a multiple line, more descriptive format
// Parameters:
//      PersonData** array: database array containing all of the objects added by the user
//      int size: number of objects added to the database
void printDataLong(PersonData** array, int size) {

    // Check to see if the database is empty
    if (size == 0)
        cout << endl << "The array is empty." << endl << endl;

    // Print the data for each object
    else {
        for (int i = 0; i < size; i++) {
            cout << endl;
            array[i]->printRecord();
            cout << endl;
        }
    }
}

// Description: prints the data of each object in the database in a single line format
// Parameters:
//      PersonData** array: database array containing all of the objects added by the user
//      int size: number of objects added to the database
void printDataShort(PersonData** array, int size) {

    // Check to see if the database is empty
    if (size == 0)
        cout << endl << "The array is empty." << endl << endl;

    // Print the data for each object
    else
        for (int i = 0; i < size; i++)
            cout << endl << array[i]->getRecord() << endl << endl;

}
