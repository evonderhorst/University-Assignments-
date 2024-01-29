// Author: Erich Vonderhorst
// Creation Date: 11/9/2023
// Last Update: 11/10/2023

#ifndef PriorityQueue_h_
#define PriorityQueue_h_

#include <iostream>
#include <vector>

using namespace std;

// Description: data storage node containing a templated data value and an integer coressponding to the priority
//              which the node will be dequeued from the queue structure defined in the class starting on line 48
// Notes: uses an STL vector as the underlying data structure
template<class T>
class PQNode {
public:
    T data;
    int priority;

    PQNode (T);
    PQNode(T, int);
};

// Description: overloaded constructor for PQNodes that takes in the data value as a parameter
// Parameters:
//      Data: data value for the PQNode to be set with
template<class T> PQNode<T>::PQNode (T Data) {
    data = Data;
    priority = 1;
}

// Description: overloaded constructor for PQNodes that takes in both member values as parameters
// Parameters:
//      Data: data value for the PQNode to be set with
//      Priority: priority value for the PQNode to be set with
template<class T> PQNode<T>::PQNode(T Data, int Priority) {
    data = Data;
    if (Priority < 1)
        Priority = 1;

    priority = Priority;
}

// Description: a queue class with each element have a set priority in which they are dequed.
// Notes: uses an STL vector as the underlying data structure and the PQNode class for each element
template<class T>
class PriorityQueue {
private:
    vector<PQNode<T> > queue; // stores all nodes as they are enqueued and dequeued

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue&);
    ~PriorityQueue();

    void enqueue(T, int = 1);
    T dequeue();

    void print();
    bool isEmpty();
    void clear();
    int size();

    T& operator[](int);
};

// Description: default constructor for PriorityQueues
template<class T> PriorityQueue<T>::PriorityQueue() {}

// Description: copy constructor for PriorityQueues
// Parameters:
//      obj: data value for the PQNode to be set with
template<class T> PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &obj) {queue = obj.queue;}

// Description: destructor for PriorityQueues
template<class T> PriorityQueue<T>::~PriorityQueue() {}

// Description: constructs a node and places it at the back of the queue
// Parameters:
//      Data: data value for the node to be set with
//      Priority: priority value for the node to be set with
template<class T> void PriorityQueue<T>::enqueue(T Data, int Priority) {queue.push_back(PQNode<T>(Data, Priority));}

// Description: deletes the node with the highest priority closest to the front of the queue and returns its data value
// Return: the data value of the node with the highest priority closest to the front of the queue
template<class T> T PriorityQueue<T>::dequeue() {
    int highestPriority = 1; // stores the highest priority value, initialized to minimum value
    T val; // holds the data value of the node so it can be popped before the return statement

    // If the queue has elements...
    if (!isEmpty()) {
        // Loop through all elements and find the highest priority value
        for (unsigned long i = 0; i < queue.size(); i++)
            if (queue[i].priority > highestPriority)
                highestPriority = queue[i].priority;

        // Loop through the elements from the front and return the first one with a priority value matching the highest
        for (unsigned long j = 0; j < queue.size(); j++) {
            if (queue[j].priority == highestPriority) {
                val = queue[j].data;
                queue.erase(queue.begin() + j);
                return val;

            }
        }
    }

    // Return the default value of the templated variable if the queue is empty
    return val;
}

// Description: displays the data and priority values of all the elements in the queue
template<class T> void PriorityQueue<T>::print() {
    for (int j = 0; j < queue.size(); j++)
        cout << queue[j].data << " --- " << queue[j].priority << endl;
}

// Description: determines if the queue is empty or not
// Return: true or false depending on if the queue is empty or not
template<class T> bool PriorityQueue<T>::isEmpty() {return queue.empty();}

// Description: deletes all elements from the queue
template<class T> void PriorityQueue<T>::clear() {queue.clear();}

// Description: acessor for the queue's size
// Return: the number of elements in the queue
template<class T> int PriorityQueue<T>::size() {return queue.size();}

// Description: overloaded access operator for accessing a value at a specific index in the PriorityQueue without
//              needing to pop the front.
// Return: the value stored in the passed index of the queue
template<class T> T& PriorityQueue<T>::operator[](int index) {return queue[index].data;}

#endif
