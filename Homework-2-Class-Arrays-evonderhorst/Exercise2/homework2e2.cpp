#include "StateData.h"

using namespace std;

// Author: Erich Vonderhorst
// Creation Date: 9/22/2023
// Last Update: 9/22/2023
// Description: this program reads a csv file with a name input by the use, counts the number of states and years in the file,
//              and stores them into an array of the StateData type and integers respectively. The data for each state
//              corresponding to each year is then read in from the file and stored in the member array of each StateData
//              element in the array. The data is then displayed.
// User Interface:
//      "Input the filename:": the user will enter the name of the file to be read. If a file with said name does not exist,
//                             an error message is printed and the program is terminated.
//      "Select a State:": enter a number corresponding to a State on the list displayed following this prompt. If the number
//                         entered does not match that of a State, an error message is printed and the program prompts the
//                         user to input a new value.
//      "Select a Year:": enter a Year on the list displayed following this prompt. If the number entered does not match that of
//                        a Year, an error message is printed and the program prompts the user to input a new value.
// Notes: none

int main() {

    string transfer; //stores each line read in from the file for transfering into name and data
    int* years; //dynamic array for every year listed in the file
    StateData* states; //dynamic array for the objects corresponding to each state listed in the file
    string fileName; //the name of the file to be opened and read

    // Retrieve the name of the file to be opened and read
    cout << "Input the filename: ";
    cin >> fileName;

    ifstream readFile = ifstream(fileName);

    // If a file with the name doesn't exist...
    if (!readFile) {

        // Error message and terminate program
        cout << "File not found, exiting program" << endl;
        return 0;
    }

    int startPos = 0; //the position of the character in the string to start the find function at
    int nextCommaPos; //the position where the character being searched by the find function was found

    // Reading in the header line of the csv file
    getline(readFile, transfer);

    // Reading past the first word on the line and setting the start position past it for reading the rest of the line
    nextCommaPos = transfer.find(',', startPos);
    startPos = nextCommaPos + 1;

    // Counting how many years are listed in the file by looking for the commas separating the values
    int numYears; //number of years listed in the file

    while (transfer.find(',', startPos) != string:: npos) {

        nextCommaPos = transfer.find(',', startPos);
        startPos = nextCommaPos + 1;
        numYears++;
    }

    numYears++; //increment the number of years because the code above doesn't count properly

    // Counting how many states are listed in the file by counting the number of lines in the file past the first
    int numStates; //number of states listed in the file
    getline(readFile, transfer);

    while(!readFile.eof()) {

        getline(readFile, transfer);
        numStates++;
    }

    // Clearing the eof flag and starting the ifstream back at the start of the file in order to read in and store its values
    readFile.clear();
    readFile.seekg(0, ios:: beg);

    // Reading the year values
    startPos = 0;
    string subString; //stores the substring derived from between each set of commas
    getline(readFile, transfer);
    nextCommaPos = transfer.find(',', startPos);
    startPos = nextCommaPos + 1;

    years = new int[numYears]; //allocating years array

    for (int i = 0; i < numYears; i++) {

        nextCommaPos = transfer.find(',', startPos);
        subString = transfer.substr(startPos, nextCommaPos - startPos);
        years[i] = stoi(subString);
        startPos = nextCommaPos + 1;
    }

    // Reading in the state name values and data values
    startPos = 0;
    states = new StateData[numStates]; //allocating states array

    for (int i = 0; i < numStates; i++) {

        getline(readFile, transfer);

        // Reading the state name
        nextCommaPos = transfer.find(',', startPos);
        subString = transfer.substr(startPos, nextCommaPos - startPos);
        states[i].setStateName(subString);
        startPos = nextCommaPos + 1;

        for (int j = 0; j < numYears; j++) {

            // Reading in the data corresponding to each year
            nextCommaPos = transfer.find(',', startPos);
            subString = transfer.substr(startPos, (nextCommaPos - startPos));
            states[i].add(stod (subString));
            startPos = nextCommaPos + 1;
        }

        startPos = 0;
    }

    readFile.close(); //closing file as all data has been extracted at this point

    int selectState; //the number corresponding to a state from the file input by the user
    int selectYear; //a year from the file input by the user

    // Prompting the user to select a state to display data for
    cout << "Select a State:" << endl;
    for (int i = 0; i < numStates; i++)
        cout << i + 1 << ". " << states[i].getStateName() << endl;

    selectState = 0;

    // Loop the prompt in case invalid input is given
    while (selectState <= 0 || selectState > numStates) {

        cout << "Selection: ";
        cin >> selectState;
        cout << endl;

        if (selectState <= 0 || selectState > numStates)
            cout << "Please enter a valid number for a State" << endl;
    }

    // Prompting the user to select a year to display data for in relation to the state selected
    cout << "Select a Year:" << endl;
    for (int i = 0; i < numYears; i++)
        cout << years[i] << endl;

    selectYear = 0;

    // Loop the prompt in case invalid input is given
    while (selectYear < years[0] || selectYear > years[numYears - 1]) {

        cout << "Selection: ";
        cin >> selectYear;
        cout << endl;

        if (selectYear < years[0] || selectYear > years[numYears - 1])
            cout << "Please enter a valid Year" << endl;
    }

    int yearIndex; //the index in the years array of the value entered by the user

    // Converting user's year input into its corresponding index value for proper data retrieval
    for (int i = 0; i < numYears; i++) {

        if (years[i] == selectYear) {

            yearIndex = i;
            break;
        }
    }

    // Displaying data for the selected state for the selected year
    cout << "The energy-related carbon dioxide emissions for " << states[selectState - 1].getStateName() << " in millions of metric tons in the year " << selectYear << " was " << states[selectState - 1].get(yearIndex) << "." << endl;

    return 0;
}

