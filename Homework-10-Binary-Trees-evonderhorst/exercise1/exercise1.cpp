// Author: Erich Vonderhorst
// Creation Date: 12/8/2023
// Last Update: 12/8/2023
// Description: This program tests the timing of tree sort, quick sort, and merge sort on an array with a number
//              of elements given by the user.
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <chrono>
#include "BinaryTree.h"

using namespace std;
using namespace std::chrono;

// Prototypes
template <class T>
void treeSort(T [], int);
template <class T>
void quickSort(T [], int);
template <class T>
void quickSort(T [], int, int);
template <class T>
void merge(T [], T [], int, int, int);
template <class T>
void mergeSort(T [], int);
template <class T>
void mergeSort(T [], T [], int, int);

int main() {
    int elements;
    srand(time(0));

    // Get the array size from the user
    cout << "Input the number of elements to store: ";
    cin >> elements;

    // Create an array of the given size and fill it with random numbers
    int* A = new int[elements];
    for (int i = 0; i < elements; i++)
        A[i] = rand();

    // Format the output so large decimal values won't show up in scientific notation
    cout << fixed << showpoint;

    // Time Each Sorting Algorithm
    auto start1 = high_resolution_clock::now(); // when the process begins
    treeSort(A, elements);
    auto stop1 = high_resolution_clock::now(); // when the process ends
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    cout << "Time to sort with tree sort: " << duration1.count() / 1000000.0 << " seconds" << endl;

    // Refill the array with random, unsorted values
    for (int i = 0; i < elements; i++)
        A[i] = rand();

    auto start2 = high_resolution_clock::now();
    quickSort(A, elements);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time to sort array with quick sort: " << duration2.count() / 1000000.0 << " seconds" << endl;

    for (int i = 0; i < elements; i++)
        A[i] = rand();

    auto start3 = high_resolution_clock::now();
    mergeSort(A, elements);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Time to sort array with merge sort: " << duration3.count() / 1000000.0 << " seconds" << endl;

    return 0;
}

// Sorting Algorithm Functions
template <class T>
void treeSort(T A[], int size) {
    BinaryTree<T> tree;
    for (int i = 0; i < size; i++)
        tree.insertNode(A[i]);
    tree.loadInOrder(A);
}

template <class T>
void quickSort(T A[], int size) {
    quickSort(A, 0, size - 1);
}

template <class T>
void quickSort(T A[], int left, int right) {
    int i = left;
    int j = right;
    int mid = (left + right) / 2;

    T pivot = A[mid];

    while (i <= j) {
        while (A[i] < pivot)
            i++;
        while (A[j] > pivot)
            j--;
        if (i<= j) {
            T temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(A, left, j);
    if (i < right)
        quickSort(A, i, right);
}

template <class T>
void merge(T A[], T Temp[], int startA, int startB, int end) {
    int aptr = startA;
    int bptr = startB;
    int i = startA;

    while (aptr < startB && bptr <= end) {
        if (A[aptr] < A[bptr])
            Temp[i++] = A[aptr++];
        else
            Temp[i++] = A[bptr++];
    }

    while (aptr < startB)
        Temp[i++] = A[aptr++];

    while (bptr <= end)
        Temp[i++] = A[bptr++];

    for (i = startA; i <= end; i++)
        A[i] = Temp[i];
}

template <class T>
void mergeSort(T A[], int size) {
    T* temp = new T[size];
    mergeSort(A, temp, 0, size - 1);
    delete[] temp;
}

template <class T>
void mergeSort(T A[], T Temp[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(A, Temp, start, mid);
        mergeSort(A, Temp, mid + 1, end);
        merge(A, Temp, start, mid + 1, end);
    }
}
