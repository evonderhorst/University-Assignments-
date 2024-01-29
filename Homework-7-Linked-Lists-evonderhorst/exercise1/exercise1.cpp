// Author: Erich Vonderhorst
// Creation Date: 10/27/2023
// Last Update: 10/27/2023
// Description: main program for testing the speed of different sorting algorithms
// User Interface:
//      "Input the number of values to store:": enter the number of values to run the test with
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "NumberList.h"

using namespace std;
using namespace std::chrono;

// Prototypes
template <class T>
void bubbleSort(T array[], int size);
template <class T>
void selectionSort(T array[], int size);
template <class T>
void insertionSort(T array[], int size);

int main() {

    int items;
    srand(time(0));

    cout << "Input the number of values to store: ";
    cin >> items;

    int* dynArr = new int[items];
    vector<int> vect(items);
    NumberList list;

    for (int i = 0; i < items; i++)
        vect.push_back(rand());

    cout << fixed << showpoint;

    auto start1 = high_resolution_clock::now(); // when the process begins
    for (int j = 0; j < items; j++)
        list.insertNode(vect[j]);
    auto stop1 = high_resolution_clock::now(); // when the process ends
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Time to sort with linked list: " << duration1.count() / 1000000.0 << " seconds" << endl;

    auto start2 = high_resolution_clock::now();
    for (int k = 0; k < items; k++)
        dynArr[k] = (vect[k]);
    bubbleSort(dynArr, items);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time to sort array with bubble sort: " << duration2.count() / 1000000.0 << " seconds" << endl;

    auto start3 = high_resolution_clock::now();
    for (int l = 0; l < items; l++)
        dynArr[l] = (vect[l]);
    insertionSort(dynArr, items);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Time to sort array with insertion sort: " << duration3.count() / 1000000.0 << " seconds" << endl;

    auto start4 = high_resolution_clock::now();
    for (int m = 0; m < items; m++)
        dynArr[m] = (vect[m]);
    selectionSort(dynArr, items);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "Time to sort array with selection sort: " << duration4.count() / 1000000.0 << " seconds" << endl;


    return 0;
}

// Sorting Algorithms
template <class T>
void bubbleSort(T array[], int size) {

    int maxElement;
    int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--)
        for (index = 0; index < maxElement; index++)
            if (array[index] > array[index + 1])
                swap(array[index], array[index + 1]);
}

template <class T>
void selectionSort(T array[], int size) {

    int minIndex;
    T minValue;

    for (int start = 0; start < (size - 1); start++) {
        minIndex = start;
        minValue = array[start];
        for (int index = start + 1; index < size; index++) {
            if (array[index] < minValue) {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

template <class T>
void insertionSort(T array[], int size) {

    for (int itemsSorted = 1; itemsSorted < size; itemsSorted++) {
        T temp = array[itemsSorted];
        int loc = itemsSorted - 1;

        while (loc >= 0 && array[loc] > temp) {
            array[loc + 1] = array[loc];
            loc = loc - 1;
        }
        array[loc + 1] = temp;
    }
}
