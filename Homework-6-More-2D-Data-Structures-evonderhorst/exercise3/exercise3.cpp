// Author: Erich Vonderhorst
// Creation Date: 10/20/2023
// Last Update: 10/20/2023
// Description: program for testing the templated 2D array and 2D vector data structures with die rolls using the Die class
// User Interface:
//      "Input the data structure...: ": enter 1 to run the simulation with an Array2D object or 2 to run with a Vector2D object
//      "Input the number of trials: ": the number of trials to be made in the simulation (number of rows in the data structure)
//      "Input the number of dice...: ": the number of dice to be rolled for each trial (number of columns in the data structure)
//      "Do you want to display...?: ": enter y or n for if you want the trials' results to be displayed or not

#include "Array2D.h"
#include "Vector2D.h"
#include "Die.h"

using namespace std;

int main() {

    int structure; // value for which data structure to use
    int trials; // number of trials to be rolled
    int dice; // number of dice to be rolled for each trial
    int equal = 0; // number of trials with equal values across all dice
    bool isEqual; // flag for whether or not a die roll is equal to the previous
    char selection; // whether to print the data or not

    // Ask the user which data structure they wish to use for the test
    cout << "Input the data structure to be used (1 = 2D Array/ 2 = 2D Vector): ";
    cin >> structure;

    // Validate input
    while (structure != 1 && structure != 2) {

        cout << "Please enter 1 for a 2D Array or 2 for a 2D Vector: ";
        cin >> structure;
    }

    // Read in the number of trials to be rolled
    cout << "Input the number of trials: ";
    cin >> trials;

    // Validate input
    while (trials < 1) {

        cout << "The number of trials cannot be negative or zero. Enter a new number: ";
        cin >> trials;
    }

    // Read in the number of dice to be rolled for each trial
    cout << "Input the number of dice for each trial: ";
    cin >> dice;

    // Validate input
    while (dice < 1) {

        cout << "The number of dice cannot be negative or zero. Enter a new number: ";
        cin >> dice;
    }

    // Ask the user if they wish to display the data
    cout << "Do you want to display the data? (Y/N): ";
    cin >> selection;

    // Validate input
    while (selection != 'Y' && selection != 'y' && selection != 'N' && selection != 'n') {

        cout << "Please enter 'Y' for 'yes' or 'N' for 'no': ";
        cin >> selection;
    }

    // Seed the random number generator with the current timestamp
    srand(time(0));

    // If the user chose to use the 2D array:
    if (structure == 1) {

        Array2D<Die> arr (trials, dice, Die());   // 2D array of Die

        // Loop through the array, roll each die, and count the number of trials with all equal rolls
        for (int i = 0; i < trials; i++) {

            // Assume all rolls will be equal until proven otherwise
            isEqual = true;

            for (int j = 0; j < dice; j++) {

                arr[i][j].roll(); // roll the die

                // Check for inequalities
                if (j > 0 && arr[i][j-1].getValue() != arr[i][j].getValue())
                    isEqual = false;
            }

            // Increment the number of trials with all equal rolls if isEqual is not negated
            if (isEqual == true)
                equal++;
        }

        // Display the data if the user asked to do so
        if (selection == 'Y' || selection == 'y')
            arr.display();
    }

    // If the user chose to use the 2D vector:
    if (structure == 2) {

        Vector2D<Die> vect (trials, dice, Die()); // 2D vector of Die

        // Loop through the vector, roll each die, and count the number of trials with all equal rolls
        for (int i = 0; i < trials; i++) {

            // Assume all rolls will be equal until proven otherwise
            isEqual = true;

            for (int j = 0; j < dice; j++) {

                vect[i][j].roll(); // roll the die

                // Check for inequalities
                if (j > 0 && vect[i][j-1].getValue() != vect[i][j].getValue())
                    isEqual = false;
            }

            // Increment the number of trials with all equal rolls if isEqual is not negated
            if (isEqual == true)
                equal++;
        }

        // Display the data if the user asked to do so
        if (selection == 'Y' || selection == 'y')
            vect.display();
    }

    // Output the number of trials with all equal rolls out of the total number of trials
    cout << "There were " << equal << " matches of equal die in the " << trials << " trials of the simulation." << endl;

    return 0;
}
