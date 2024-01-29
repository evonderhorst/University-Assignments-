#include "Array2D.h"
#include "Die.h"

using namespace std;

// Author: Erich Vonderhorst
// Creation Date: 9/25/2023
// Last Update: 9/29/2023
// Description: asks the user for a number of trial and rolls to be made for each trial before performing said rolls and trials
//              and outputting the results of each as well as how many trials had all their rolls result in the same value
// User Interface:
//      "Input the number of trials: " : input any positive integer that will serve as the number of trials performed
//      "Input the number of dice rolls per trial: " : input any positive integer that will determine how many dice rolls are
//                                                     made per trial
// Notes: none


int main() {

    int rolls; //number of rolls to be performed in each trial
    int trials; //number of trials to be performed
    Array2D Simulation; //holds the rolls results for all trials
    Die die1; //used for each dice roll, value is added with the other and saved into the Array2D object
    Die die2;

    // Get the number of trials and rolls from the user
    cout << "Input the number of trials: ";
    cin >> trials;

    cout << "Input the number of dice rolls per trial: ";
    cin >> rolls;

    // Resize the array to the values received from user
    Simulation.resize(trials, rolls, 0);

    // Seed the random number generator
    srand(time(0));

    int sameRolls = 0; //number of trials with all the same dice rolls
    bool same = true; //flag used to determine if all rolls in a trial are equal

    // Populate the Array2D object and count the number of trials with the value across all rolls
    for (int i = 0; i< trials; i++) {

        same = true;
        for (int j = 0; j < rolls; j++) {

            // Roll both dice
            die1.roll();
            die2.roll();

            // Populate array
            Simulation.set(i, j, die1.getValue() + die2.getValue());

            // Check if the roll just made resulted in the same value as the previous one
            if(j > 0 && Simulation.get(i,j) != Simulation.get(i, j - 1))
                same = false;
        }

        // If all rolls were the same, increment sameRolls
        if (same)
            sameRolls++;
    }

    // Output results
    cout << "Number of trials resulting in the same roll value was " << sameRolls << "." << endl << endl;
    Simulation.display();

    return 0;
}
