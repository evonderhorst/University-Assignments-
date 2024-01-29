// Author: Erich Vonderhorst
// Creation Date: 11/27/2023
// Last Update: 12/1/2023
// Description: simulates a cpu running processes when faced with a load of a certain size. The user enters  several
// values that determine how the simulation is run.
#include "PriorityQueue.h"
#include "Process.cpp"

using namespace std;

int main () {
    int cores; // the number of cores the CPU has in the simulation
    int minCycles; // the minimum number of random cycles a new process can be given
    int maxCycles; // the maximum number of random cycles a new process can be given
    int pLevels; // the number of levels in the priority queue that determine the order which processes are loaded
    double newProcesses; // the number of new processes that are added each cycle of the simulation
    unsigned long long simLength; // the number of cycles the simulation is to be ran with
    int* cpu; // int array representing the CPU

    // Get input from the user for all the above values
    cout << "Input the Number of CPU Cores: ";
    cin >> cores;

    cout << "Input the Minimum number of Execution Cycles per Process: ";
    cin >> minCycles;

    cout << "Input the Maximum number of Execution Cycles per Process: ";
    cin >> maxCycles;

    cout << "Input the Number of Priority Levels: ";
    cin >> pLevels;

    cout << "Input the Number of New Processes per Cycle: ";
    cin >> newProcesses;

    cout << "Input the Length of the Simulation in Cycles: ";
    cin >> simLength;

    cout << endl;

    // Set the CPU array size to the number of cores and initialize each to 0
    cpu = new int[cores];
    for (int i = 0; i < cores; i++)
        cpu[i] = 0;

    int idleTime = 0; // total amount of cycles each cpu core spent while not having a process loaded
    unsigned long long completed = 0; // number of processes loaded onto the core
    unsigned long long totalWaitTime = 0; // amount of cycles all loaded processes took to be completed
    double newProcessAmount = 0.0; // tracks the total value of new processes added per cycle since the value can be a decimal
    PriorityQueue<Process> processes; // priority queue containing all the processes to be loaded

    srand(time(0)); // seed the random number generater with the current timestamp

    // Preload the queue for the simulation with a process for each core to start with
    for (int i = 0; i < cores; i++) {
        Process temp(rand() % (maxCycles - minCycles + 1) + minCycles, 0);
        processes.enqueue(temp, (rand() % pLevels) + 1);
    }

    // Perform the simulation
    for (unsigned long long t = 0; t < simLength; t++) {
        // Check each core in the cpu..
        for (int c = 0; c < cores; c++) {
            // Attempt to load a process onto the core if the core is empty
            if (!cpu[c]) {
                // Add to the idle time if there are no processes queued
                if (processes.isEmpty())
                    idleTime++;
                // Load the process onto the core and add to necessary values
                else {
                    Process temp = processes.dequeue();
                    cpu[c] = temp.getExeTime();
                    completed++;
                    totalWaitTime += t - temp.getTimeStamp();
                }
            }
            // Complete one cycle of the process' execution time by decrementing the cpu's value if it has a process loaded
            if (cpu[c])
                cpu[c]--;
        }

        // Add new processes to the queue
        newProcessAmount += newProcesses;
        while (newProcessAmount >= 1) {
            Process temp(rand() % (maxCycles - minCycles + 1) + minCycles, t);
            processes.enqueue(temp, (rand() % pLevels) + 1);
            newProcessAmount -= 1;
        }
    }

    // Complete running any remaining processes and gather certain data
    unsigned long remaining = processes.size(); // number of processes remaining
    unsigned long long totalExecTimeRemaining = 0; // the amount of cycles all the remaining processes need to finish executing
    unsigned long long totalWaitTimeRemaining = 0; // the amount of cycles the simulation would take to complete the rest of
                                                   // processes without adding to the queue
    unsigned long long maxWaitTimeRemaining; // the longest a process can stay unloaded and unprocessed for
    if (remaining) {
        unsigned long long cycle = 0; // tracks the current cycle
        while(!processes.isEmpty()) {
            for (int c = 0; c < cores; c++) {
                if (!cpu[c] && !processes.isEmpty()) {
                    Process temp = processes.dequeue();
                    cpu[c] = temp.getExeTime();
                    totalExecTimeRemaining += temp.getExeTime();
                    totalWaitTimeRemaining += (simLength - temp.getTimeStamp());
                }
                if (cpu[c])
                    cpu[c]--;
            }
            cycle++;
        }
        if (cycle <= simLength)
            maxWaitTimeRemaining = cycle;
        else
            maxWaitTimeRemaining = simLength;
    }

    // Output the results of the simulation
    cout << "==================== Simulation Results ====================" << endl;
    cout << "Idle Time = " << idleTime << endl;
    cout << "Processes Completed = " << completed << endl;
    cout << "Total Wait Time of Completed Processes = " << totalWaitTime << endl;
    cout << "Number of Processes Remaining in Queue = " << remaining << endl;
    // Output the following if all the processes were not completed in the initial simulation
    if (remaining) {
        cout << "Total Execution Time Needed for Unprocessed Processes = " << totalExecTimeRemaining << endl;
        cout << "Total Wait Time for Unprocessed Processes = " << totalWaitTimeRemaining << endl;
        cout << "Maximum Wait Time for Unprocessed Processes = " << maxWaitTimeRemaining << endl;
    }

    return 0;
}
