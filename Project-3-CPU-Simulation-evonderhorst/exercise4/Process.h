// Author: Erich Vonderhorst
// Creation Date: 12/1/2023
// Last Update: 12/1/2023
// Description: represents a process being ran by a CPU.

#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <math.h>

using namespace std;

class Process {
private:
    int exeTime; // execution time of the process in cycles
    int timeStamp; // time stamp of the process creation (cycle number when it was loaded onto a CPU core)

public:
    // Constructors and Destructor
    Process(int time = 1, int stamp = 0);
    Process(const Process&);
    ~Process();

    // Accessors and Mutators
    void setExeTime(int);
    int getExeTime();
    void setTimeStamp(int);
    int getTimeStamp();

    // Overloaded Operator Functions
    const Process operator=(const Process&);
    friend ostream& operator<<(ostream&, const Process&);
};
#endif
