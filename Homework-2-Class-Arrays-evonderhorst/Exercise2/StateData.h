#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Author: Erich Vonderhorst
// Creation Date: 9/22/2023
// Last Update: 9/22/2023
// Description: header file for the StateData class which has 3 members: StateName, data, and size. Statename is a string
//              vairable for the name of a US state, data is a dynamic double array for holding the energy-related carbon dioxide
//              emissions in millions of metric tons for the state for each year in a range corresponding to the arrays size, and
//              size is an integer representing the number of years worth of data
// Notes: hi Dr. Spickler

#ifndef StateData_h_
#define StateData_h_

class StateData {

    private:
        string StateName; //the name of a US state
        double *data; //holds the energy-related carbon dioxide emissions in millions of metric tons for the state for each year
                      //in a range corresponding to the array's size
        int size; //the number of years worth of data

    public:
        StateData();
        ~StateData();

        void setStateName(string);
        string getStateName();
        void add(double);
        double get(int);
};

#endif
