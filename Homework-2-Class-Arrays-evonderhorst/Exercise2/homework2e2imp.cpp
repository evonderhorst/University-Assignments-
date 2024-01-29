#include "StateData.h"

using namespace std;

// Author: Erich Vonderhorst
// Creation Date: 9/22/2023
// Last Update: 9/22/2023

// Description: constructor for instances of the StateData class
// Parameters: none
// Return: a new instance of the StateData class
// Notes: none
StateData:: StateData() {

    StateName = "";
    data = nullptr;
    size = 0;
}

// Description: destructor for instances of the StateData class
// Parameters: none
// Return: none
// Notes: none
StateData:: ~StateData() {

    delete[] data;
}

// Description: mutator for the StateName string member
// Parameters:
//      string newName: the name of a US state to be stored into the StateName member
// Return: void
// Notes: none
void StateData:: setStateName(string newName) {

    StateName = newName;
}

// Description: accessor for the StateName string member
// Parameters: none
// Return: the string stored in StateName
// Notes: none
string StateData:: getStateName() {

    return StateName;
}

// Description: appends the data dynamic double array member with a new value
// Parameters:
//      double addData: the double value to be added to a new index in the array
// Return: void
// Notes: none
void StateData:: add(double addData) {

    double* tempArr = new double[size + 1]; //temporary array with an extra allocated element for storing the value of addData

    // Copy the old array over
    for (int i = 0; i < size; i++)
        *(tempArr + i) = *(data + i);

    // Append the array with the passed value
    *(tempArr + size) = addData;

    // Deallocate old array and update members
    delete[] data;
    data = tempArr;
    size++;
}

// Description: accessor for the value of any element in the data array
// Parameters:
//      int index: the index of the data array where the value is to be retrieved from
// Return: the value of the data in the passed index of the data array
// Notes: validates passed index
double StateData:: get(int index) {

    // Check to see if the data array of the current instance has any elements
    if (size == 0)
        return 0;

    // Validate input
    if (index < 0)
        index = 0;

    if (index >= size)
        index = size - 1;

    // Return the value of the data in the passed index
    return *(data + index);
}
