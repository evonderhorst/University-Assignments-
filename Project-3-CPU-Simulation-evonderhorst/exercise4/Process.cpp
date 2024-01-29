// Author: Erich Vonderhorst
// Creation Date: 11/27/2023
// Last Update: 12/1/2023
#include "Process.h"

using namespace std;

// Description: constructor for a Process
// Parameters:
//      time: the execution time a Process needs to be completed
//      stamp: cycle value for the timestamp to be set to
// Note: execution time can be no less than 1
Process::Process(int time, int stamp) {
    if (time < 1)
        exeTime = 1;
    else
        exeTime = time;
    timeStamp = stamp;
}

// Description: copy constructor for a Process
// Parameters:
//      obj: Process to have its member values copied over
Process::Process(const Process& obj) {exeTime = obj.exeTime; timeStamp = obj.timeStamp;}

// Description: destructor for a Process
Process::~Process() {}

// Description: mutator for the execution time of a Process
// Parameters:
//      time: the execution time a Process needs to be completed
void Process::setExeTime(int time) {exeTime = time;}

// Description: accessor for the execution time of a Process
// Return: the execution time of the current Process
int Process::getExeTime() {return exeTime;}

// Description: mutator for the timestamp of when a Process is loaded onto a cpu
// Parameters:
//      stamp: cycle value for the timestamp to be set to
void Process::setTimeStamp(int stamp) {timeStamp = stamp;}

// Description: accessor for the timestamp of when a Process was loaded onto a cpu
// Return: the timestamp of when the current Process was loaded
int Process::getTimeStamp() {return timeStamp;}

// Description: overloaded assignment operator for Processes
// Paramters:
//      rhs: Process to have its member values copied over
// Return: a reference to the current Process
const Process Process::operator=(const Process& rhs) {exeTime = rhs.exeTime; timeStamp = rhs.timeStamp; return *this;}

// Description: overloaded stream out operator for Processes
// Parameters:
//      out: output stream object being used
//      obj: Process to have its member values displayed in a neat format
// Return: a reference to the output stream that was used
ostream& operator<<(ostream& out, const Process& obj) {out << "[" << obj.exeTime << ", " << obj.timeStamp << "]"; return out;}
