// Author: Erich Vonderhorst
// Creation Date: 11/8/2023
// Last Update: 11/10/2023
// Description: a queue data structure that works similarly to the STL queue. Contains member functions for
//              enqueueing, dequeueing, displaying, clearing and copying the Queue and functions to determine
//              the Queue's size and see if it is empty.
// Notes: uses the LinkedList class as an underlying data structure

#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class Queue {
private:
    LinkedList<T> queue; // underlying storage structure that the Queue will add and remove elements from

public:
    Queue();
    ~Queue();
    void displayQueue(bool nl = false) const;

    Queue (const Queue &obj);
    const Queue<T> operator=(const Queue &rhs);

    void clear();
    int size();
    void enqueue(T);
    T dequeue();
    bool isEmpty();
};


// Description: default constructor for Queues
template <class T> Queue<T>::Queue() {}

// Description: destructor for Queues
template <class T> Queue<T>::~Queue() {}

// Description: displays all of the elements in the Queue
// Parameters:
//      nl: will have the function print each element on its own line if set to true
template <class T> void Queue<T>::displayQueue(bool nl) const {queue.displayList(nl);}

// Description: copy constructor for Queues
// Parameters:
//      obj: Stack instance to have its element values copied to the current instance
template <class T> Queue<T>::Queue(const Queue<T> &obj) {queue = obj.queue;}

// Description: overloaded assignment operator for Queues
// Parameters:
//      rhs: Queue insance to have its element values assigned to those of the current instance
// Return:
//      a reference to the current instance
template <class T> const Queue<T> Queue<T>::operator=(const Queue &rhs) {queue = rhs.queue; return *this;}

// Description: removes all elements from a Queue
template <class T> void Queue<T>::clear() {queue.clear();}

// Description: returns the number of elements in a Queue
// Return: what do you think?
template <class T> int Queue<T>::size() {return queue.length();}

// Description: places the passed value at the back of the Queue
// Parameters:
//      val: value to be placed on the back
template <class T> void Queue<T>::enqueue(T val) {queue.push_back(val);}

// Description: returns and deletes the element at the front of the Queue
// Note: throws an exception in the pop_front() function of the LinkedList class if the Queue is empty
template <class T> T Queue<T>::dequeue() {return queue.pop_front();}

// Description: determines if the Queue is empty or not
// Return: true or false depending on if the Queue is empty or not
template <class T> bool Queue<T>::isEmpty() {return !queue.length();}

#endif
