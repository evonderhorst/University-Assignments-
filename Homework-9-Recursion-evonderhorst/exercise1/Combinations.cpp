// Author: Erich Vonderhorst
// Creation Date: 11/17/2023
// Last Update: 11/17/2023
// Description: program for testing a function that finds n choose k combinations recursively.

#include <iostream>

using namespace std;

// Prototype for combination function
int combination(int, int);

int main() {
    int n; // n value for n choose k
    int k; // k value for n choose k

    // Get the n and k values from the user
    cout << "Enter n and k (integer) with a space between them: ";
    cin >> n >> k;

    // Calculate the combination for the given values and output the result
    cout << n << " choose " << k << " = " << combination(n, k) << endl;

    return 0;
}

// Description: calculates n choose k recursively
// Parameters:
//      n: n value for n choose k
//      k: k value for n choose k
// Return: the result of the overall combination and each recursive step needed to get to it
int combination(int n, int k) {
    if (n == 0 || k == 0 || n == k)
        return 1;
    if (n < 0 || k < 0 || n < k)
        return 0;
    return combination(n - 1, k) + combination (n - 1, k - 1);
}
