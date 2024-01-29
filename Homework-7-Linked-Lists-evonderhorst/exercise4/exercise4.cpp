// Author: Erich Vonderhorst
// Creation Date: 10/27/2023
// Last Update: 10/27/2023
// Description: tests the templated LinkedList class using the Shape class and its derived types by storing
//              nodes of said class types and drawing them.
// User Interface:
//      "Input the number of objects: ": the number of shape objects to be randomly be chosen and added to the
//                                       linked list structure.
#include <iostream>
#include "LinkedList.h"
#include "Shape.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"

using namespace std;

int main() {

    int items; // the number of items to be stored in the list
    int randNum; // a random number representing which derived class of Shape the next node added should be

    // Seed random number generator with current timestamp
    srand(time(0));

    // Ask for the number of objects
    cout << "Input the number of objects: ";
    cin >> items;

    LinkedList<Shape*> shapes; // linked list that holds the created instances of shape

    // Generate shapes
    for (int i = 0; i < items; i++) {

        randNum = rand() % 3; // get a random value to decide which derived class to use

        if (!randNum)
            shapes.push_back(new Triangle((rand() % 11) + 5, (rand() % 11) + 5, (rand() % 11) + 5));
        else if (randNum == 1)
            shapes.push_back(new Rectangle((rand() % 11) + 5, (rand() % 11) + 5));
        else
            shapes.push_back(new Square ((rand() % 11) + 5));
    }

    // Draw each shape in the linked list
    for (int j = 0; j < items; j++) {
        shapes[j]->draw();
    }

    // Deallocate all of the created shapes
    for (int k = 0; k < items; k++) {
        delete shapes[k];
    }

    return 0;
}
