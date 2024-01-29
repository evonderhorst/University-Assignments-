// Author: Erich Vonderhorst
// Creation Date: 10/27/2023
// Last Update: 10/27/2023
// Description: times the processes of pushing values to the front and back of a vector, linked list and STL list
// User Interface:
//      "Input ther number of values to store:": enter the number of values to run the test with
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <list>
#include "LinkedList.h"

using namespace std;
using namespace std::chrono;

int main() {

    int items; // the number of items to run the tests with

    // Seed the random number generator with the current timestamp
    srand(time(0));

    // Read in the number of values
    cout << "Input the number of values to store: ";
    cin >> items;

    // Create the three data structures being tested
    vector<int> vect(items);
    list<int> list1;
    LinkedList<int> list2;

    // Format the output stream to better show results
    cout << fixed << showpoint;

    // Time each process:
    // Pushing to the front with a linked list
    auto start1 = high_resolution_clock::now(); // when the process begins
    for (int j = 0; j < items; j++)
        list2.push_front(rand());
    auto stop1 = high_resolution_clock::now(); // when the process ends
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Time to push to the front with linked list: " << duration1.count() / 1000000.0 << " seconds" << endl;

    // Pushing to the front with a vector
    auto start2 = high_resolution_clock::now();
    for (int k = 0; k < items; k++)
        vect.insert(vect.begin(), rand());
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time to push to the front with vector: " << duration2.count() / 1000000.0 << " seconds" << endl;

    // Pushing to the front with an STL list
    auto start3 = high_resolution_clock::now();
    for (int l = 0; l < items; l++)
        list1.push_front(rand());
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Time to push to front with STL list: " << duration3.count() / 1000000.0 << " seconds" << endl;

    // Pushing to the back with a linked list
    auto start4 = high_resolution_clock::now();
    for (int m = 0; m < items; m++)
        list2.push_back(rand());
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "Time to push to the back with linked list: " << duration4.count() / 1000000.0 << " seconds" << endl;

    // Pushing to the back with a vector
    auto start5 = high_resolution_clock::now();
    for (int m = 0; m < items; m++)
        vect.push_back(rand());
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(stop5 - start5);
    cout << "Time to push to the back with vector: " << duration5.count() / 1000000.0 << " seconds" << endl;

    // Pushing to the vack with an STL list
    auto start6 = high_resolution_clock::now();
    for (int m = 0; m < items; m++)
        list1.push_back(rand());
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<microseconds>(stop6 - start6);
    cout << "Time to push to the back with STL list: " << duration6.count() / 1000000.0 << " seconds" << endl;

    return 0;
}
