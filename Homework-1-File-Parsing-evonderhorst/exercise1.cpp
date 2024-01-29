
#include <iostream>

using namespace std;

int main() {
    int size = 0;
    cout << "Input array size: ";
    cin >> size;
    int *A = getRandomNumbers(size);
    display(A, size);
    sort(A, size);
    display(A, size);
    if (sorted(A, size))
        cout << "Array is sorted." << endl;
    else
        cout << "Array is not sorted." << endl;
    div();
    delete[] A;
    A = new int[10];
    size = 10;
    for (int i = 0; i < size; i++)
        A[i] = i + 1;
    int *copyA = duplicateArray(A, size);
    display(A, size);
    shuffle(A, size);
    display(A, size);
    cout << sorted(A, size) << endl;
    sort(A, size);
    display(A, size);
    cout << sorted(A, size) << endl;
    div();
    int *B = new int[5];
    int sizeB = 5;
    for (int i = 0; i < sizeB; i++)
        B[i] = rand() % 100;
    display(B, sizeB);
    display(A, size);
    concat(A, size, B, sizeB);
    display(B, sizeB);
    display(A, size);
    div();
    // Reset A to original data.
    delete[] A;
    size = 10;
    A = duplicateArray(copyA, size);
    display(A, size);
    remove(A, size, 3, 7);
    display(A, size);
    div();
    // Reset A to original data.
    delete[] A;size = 10;
    A = duplicateArray(copyA, size);
    display(A, size);
    sub(A, size, 3, 7);
    display(A, size);
    div();
    // Reset A to original data.
    delete[] A;
    size = 10;
    A = duplicateArray(copyA, size);
    display(A, size);
    display(B, sizeB);
    insert(A, size, B, sizeB, 2);
    display(A, size);
    div();
    // Reset A to original data.
    delete[] A;
    size = 10;
    A = duplicateArray(copyA, size);
    display(A, size);
    resize(A, size, 20);
    display(A, size);
    div();
    // Reset A to original data.
    delete[] A;
    size = 10;
    A = duplicateArray(copyA, size);
    display(A, size);
    resize(A, size, 5);
    display(A, size);
    delete[] A;
    A = nullptr;
    delete[] copyA;
    copyA = nullptr;
    delete[] B;
    B = nullptr;
    return 0;
}


