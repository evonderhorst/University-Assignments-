// Author: Erich Vonderhorst
// Creation Date: 11/8/2023
// Last Update: 11/10/2023
// Description: a stack data structure that works similarly to the STL stack. Contains member functions for
//              pushing to, popping from, displaying, clearing and copying the Stack and functions to determine
//              the Stack's size and see if it is empty.
// Notes: uses the LinkedList class as an underlying data structure

#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T> class Stack {
private:
    LinkedList<T> stack; // underlying storage structure that the Stack will add and remove elements from
public:
    Stack();
    ~Stack();
    void displayStack(bool nl = false) const;

    Stack(const Stack &obj);
    const Stack<T> operator=(const Stack &rhs);

    void clear();
    int size();
    void push(T);
    T pop();
    bool isEmpty();
};

// Description: default constructor for Stacks
template <class T> Stack<T>::Stack() {}

// Description: destructor for Stacks
template <class T> Stack<T>::~Stack() {}

// Description: displays all of the elements in the Stack
// Parameters:
//      nl: will have the function print each element on its own line if set to true
template <class T> void Stack<T>::displayStack(bool nl) const {stack.displayList(nl);}

// Description: copy constructor for Stacks
// Parameters:
//      obj: Stack instance to have its element values copied to the current instance
template <class T> Stack<T>:: Stack(const Stack &obj) {stack = obj.stack;}

// Description: overloaded assignment operator for Stacks
// Parameters:
//      rhs: Stack insance to have its element values assigned to those of the current instance
// Return:
//      a reference to the current instance
template <class T> const Stack<T> Stack<T>::operator=(const Stack &rhs) {stack = rhs.stack; return *this;}

// Description: removes all elements from a Stack
template <class T> void Stack<T>::clear() {stack.clear();}

// Description: returns the number of elements in a Stack
// Return: I don't know, actually...
template <class T> int Stack<T>::size() {return stack.length();}

// Description: places the passed value at the top of the Stack
// Parameters:
//      val: value to be placed on the top
template <class T> void Stack<T>::push(T val) {stack.push_front(val);}

// Description: returns and deletes the element at the top of the Stack
// Note: throws an exception in the pop_front() function of the LinkedList class if the Stack is empty
template <class T> T Stack<T>::pop() {return stack.pop_front();}

// Description: determines if the Stack is empty or not
// Return: true or false depending on if the Stack is empty or not
template <class T> bool Stack<T>::isEmpty() {return !stack.length();}

#endif
