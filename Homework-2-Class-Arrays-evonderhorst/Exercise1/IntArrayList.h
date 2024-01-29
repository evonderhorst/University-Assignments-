#include <iostream>
#include <algorithm>

// Author: Erich Vonderhorst
// Creation Date: 9/20/2023
// Last Update: 9/22/2023
// Description: header file for the InArrayList class. The class has 2 data members: list and size. The members functions allow
//              for the manipulation of both members in various ways outlined in the implementation file.
// Notes: none

#ifndef IntArrayList_h
#define IntArraylist_h

class IntArrayList {

private:
    int *list; //generic dynamic integer array
    int size; //number of elements in the array member

public:

    IntArrayList();
    ~IntArrayList();

    void duplicate(IntArrayList&);
    void display(bool vert = false);
    void displayAddress();
    void sort();
    bool sorted();
    void add(int);
    void concat(const IntArrayList&);
    void remove(int, int);
    void shuffle();
    void sub(int, int);
    void insert(const IntArrayList&, int);
    void insert(int, int);
    int get(int);
    void set(int, int);
    void resize(int);
    int length();
};

#endif
