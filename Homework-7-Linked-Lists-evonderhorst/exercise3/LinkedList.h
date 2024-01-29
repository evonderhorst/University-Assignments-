// Author: Erich Vonderhorst
// Creation Date: 10/27/2023
// Last Update: 10/27/2023
// Description: A class template for holding a linked list with the list's nodes also being class templates
//              themselves.

#include <iostream>

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

//*********************************************
// The ListNode class creates a type used to  *
// store a node of the linked list.           *
//*********************************************
template<class T>
class ListNode {
public:
	T value;           // Node value
	ListNode<T> *next; // Pointer to the next node

	// Constructor
	ListNode(T nodeValue) {
		value = nodeValue;
		next = nullptr;
	}
};

//*********************************************
// LinkedList class                           *
//*********************************************
template<class T>
class LinkedList {
private:
	ListNode<T> *head;   // List head pointer
	ListNode<T> *tail;   // List tail pointer

public:
	// Constructor
	LinkedList();

	// Copy constructor
	LinkedList(const LinkedList&);

	// Destructor
	~LinkedList();

	// Linked list operations
	void push_back(T);
	void push_front(T);
	T pop_front();
	T peakHead();
	T peakTail();
	void clear();
	int length();
	T get(int);
	void set(int, T);
	void insertNode(T);
	void deleteNode(T);
	void displayList() const;
	LinkedList<T>& operator=(const LinkedList<T>&);
	T& operator[](int);
};

// Description: default constructor for LinkedList
// Return: a new instance of LinkedList
template<class T>
LinkedList<T>::LinkedList() {
	// Set both pointer members to nullptr
	head = nullptr;
	tail = nullptr;
}

// Description: copy constructor for two instances of LinkedList
// Parameters:
//		list: the instance to have its values copied over to the one being created
// Return: a new instance of LinkedList with the same values as the one passed
template<class T>
LinkedList<T>::LinkedList(const LinkedList& list) {

	head = nullptr;
	tail = nullptr;
	ListNode<T>* copy = list.head;
	if(copy) {
		while(!copy) {
			push_back(copy->value);
			copy = copy->next;
		}
	}
}

// Description: for adding new ListNodes onto the back of the LinkedList
// Parameters:
//		newValue: the value that the new ListNode will hold
template<class T>
void LinkedList<T>::push_back(T newValue) {
	ListNode<T> *newNode;  // To point to a new node

	// Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list
	// make newNode the first node.
	if (!head) {
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		// Assign newNode to tail of list.
		tail->next = newNode;
		tail = newNode;
	}
}

// Description: displays the value of each ListNode
template<class T>
void LinkedList<T>::displayList() const {
	ListNode<T> *nodePtr;  // To move through the list

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr) {
		// Display the value in this node.
		cout << nodePtr->value << " ";

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

// Description: creates a new ListNode with the passed value and places it in ascending order with the
//              rest of the ListNode's values
// Parameters:
//		newValue: the value of the ListNote to be insterted into the LinkedList
// Notes: templated type must have overloaded '<' operator
template<class T>
void LinkedList<T>::insertNode(T newValue) {
	ListNode<T> *newNode;				// A new node
	ListNode<T> *nodePtr;				// To traverse the list
	ListNode<T> *previousNode = nullptr; // The previous node

	// Allocate a new node and store newValue there.
	newNode = new ListNode<T>(newValue);

	// If there are no nodes in the list
	// make newNode the first node
	if (!head) {
		head = newNode;
		tail = newNode;
		newNode->next = nullptr;
	} else  // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than newValue.
		while (nodePtr != nullptr && nodePtr->value < newValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list,
		// insert it before all other nodes.
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		} else  // Otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}

		// If the new node was placed last in the list,
		// set tail to newNode.
		if (!nodePtr)
			tail = newNode;
	}
}

// Description: searches for a ListNode with the passed value and deletes it if found
// Parameters:
//		searchValue: value that the ListNode to be deleted will have
template<class T>
void LinkedList<T>::deleteNode(T searchValue) {
	ListNode<T> *nodePtr;       // To traverse the list
	ListNode<T> *previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == searchValue) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	} else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != searchValue) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list:
		if (nodePtr) {
			// If nodeptr is the last node in the list,
			// delete nodePtr, set the node after previous
			// node to nullptr, and set tail to previous
			// node.
			if (!(nodePtr->next)) {
				delete nodePtr;
				previousNode->next = nullptr;
				tail = previousNode;
			}
			// Else, link the previous node to the node
			// after nodePtr, then delete nodePtr.
			else {
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}
	}
}

// Description: destructor for instances of LinkedList
template<class T>
LinkedList<T>::~LinkedList() {
	ListNode<T> *nodePtr;   // To traverse the list
	ListNode<T> *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

// Description: adds a new ListNode with the passed value to the front of the LinkedList
// Parameters:
//		num: the value that the new ListNode will have
template<class T>
void LinkedList<T>:: push_front(T num) {
	ListNode<T>* newNode = new ListNode<T>(num); // To track the first node while moving it around

	// If the list is empty, create the first node
	if (!head) {
		head = newNode;
		tail = newNode;
		newNode->next = nullptr;
	}

	// Otherwise, point to the first node, have the head point to the new node, and point the new node to
	// the first node
	else {
		ListNode<T>* nextNode = head;
		head = newNode;
		head->next = nextNode;
	}
}

// Description: deletes the first ListNode in the LinkedList and returns its value
// Return: the value of the deleted ListNode
// Notes: throws an exception if the list is empty
template<class T>
T LinkedList<T>:: pop_front() {
	// Throw an exception if the LinkedList is empty
	string error;
	if (!head) {
		error = "Empty List Exception";
		throw error;
	}

	// Save the node's value, delete the node, then return the value
	T nodeVal; // To store the value of the node to be deleted
	nodeVal = head->value;
	deleteNode(nodeVal);
	return nodeVal;
}

// Description: returns the value of the first ListNode in the LinkedList
// Return: the value of the first ListNode
// Notes: throws an exception if the LinkedList is empty
template<class T>
T LinkedList<T>:: peakHead() {

	// Throw an exception if the list is empty
	string error;
	if (!head) {
		error = "Null Pointer Exception";
		throw error;
	}

	// Return the first node's value
	return head->value;
}

// Description: returns the value of the last ListNode in the LinkedList
// Return: the value of the last ListNode
// Notes: throws an exception if the LinkedList is empty
template<class T>
T LinkedList<T>:: peakTail() {

	// Throw an exception if the list is empty
	string error;
	if (!tail) {
		error = "Null Pointer Exception";
		throw error;
	}

	// Return the last node's value
	return tail->value;
}

// Description: deletes all of the ListNodes in the LinkedList
template<class T>
void LinkedList<T>:: clear() {

	ListNode<T> *nodePtr;   // To traverse the list
	ListNode<T> *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}

	// Reset the pointer members to nullptr
	head = nullptr;
	tail = nullptr;
}

// Description: returns the number of ListNodes in the LinkedList
// Return: the number of ListNodes
template<class T>
int LinkedList<T>:: length() {
	int count = 0; // To count the number of nodes

	// Return 0 if the list is empty
	if (!head)
		return count;

	// Otherwise, keep incrementing count until the nullptr at the end is encountered
	else {
		ListNode<T>* nextNode = head; // To traverse down the list
		while (nextNode) {
			count++;
			nextNode = nextNode->next;
		}
		// Return the final value of count
		return count;
	}
}

// Description: accessor for the value of any ListNode in the LinkedList
// Parameters:
//		nodeNum: the number of ListNodes up the LinkedList needed to reach the one with the value to return
// Return: the value of the specified ListNode
// Notes: throws an exception if the LinkedList is empty or if the passed value excedes the number of ListNodes
template<class T>
T LinkedList<T>:: get(int nodeNum) {

	// Throw an exception if the list is empty
	string error;
	if (!head) {
		error = "Empty List Exception";
		throw error;
	}

	// Traverse to the next node a number of times equal to the passed value
	ListNode<T>* nextNode = head; // To traverse the list
	for (int i = 0; i < nodeNum; i++) {
		// Throw an exception if the next node comes up as nullptr
		if (!nextNode) {
			error = "Index Out of Bounds Exception";
			throw error;
		}
		else
			nextNode = nextNode->next;
	}

	// Return the value of the node that the loop stopped on
	return nextNode->value;
}

// Description: mutator for the value of any ListNode in the LinkedList
// Parameters:
//		nodeNum: the number of ListNodes up the LinkedList needed to reach the one with the value to modify
//		num: the value for that of the specified ListNode to be changed to
// Notes: throws an exception if the LinkedList is empty or if the passed value excedes the number of ListNodes
template<class T>
void LinkedList<T>:: set(int nodeNum, T num) {

	// Throw an exception if the list is empty
	string error;
	if (!head) {
		error = "Empty List Exception";
		throw error;
	}

	// Traverse to the next node a number of times equal to the passed value
	ListNode<T>* nextNode = head; // To traverse the list
	for (int i = 0; i < nodeNum; i++) {
		// Throw an exception if the next node comes up nullptr
		if (!nextNode) {
			error = "Index Out of Bounds Exception";
			throw error;
		}
		else
			nextNode = nextNode->next;
	}

	// Assign the passed templated value to that of the node that the loop stopped on
	nextNode->value = num;
}

// Description: overloaded assignment operator for two instances of LinkedList
// Parameters:
// 		rhs: LinkedList to have all its values copied over to the current instance
// Return: a reference to the current instance of LinkedList
// Notes: allows for chain assignment
template<class T>
LinkedList<T>& LinkedList<T>:: operator=(const LinkedList& rhs) {

	ListNode<T>* current = head; // For traversing the current list
	ListNode<T>* copy = rhs.head; // For traversing the passed list

	// If the passed list has any values to copy over..
	if (copy) {
		// Traverse the passed list and copy its values until its end is reached.
		while (!copy) {
			// Push the next value to the back of the current list has less nodes than the passed
			if (!current)
				push_back(copy->value);

			// Otherwise, just copy over the node's value like normal
			else
				current->value = copy->value;

			current = current->next;
			copy = copy->next;
		}
	}

	// If the passed list is empty, clear the current list
	else
		clear();

	// Return a reference to the current list
	return *this;
}

// Description: overloaded subscript operator for instances of LinkedList
// Parameters:
// 		index: the number of ListNodes up the LinkedList needed to reach the one with the value to return
// Return: a reference to the value of the ListNode at the passed index
// Notes: throws exceptions if the LinkedList is empty or if the passed index excedes the number of ListNodes
template<class T>
T& LinkedList<T>:: operator[](int index) {


	// Throw an exception if the list is empty
	string error;
	if (!head) {
		error = "Empty List Exception";
		throw error;
	}

	// Traverse to the next node a number of times equal to the passed value
	ListNode<T>* nextNode = head; // To traverse the list
	for (int i = 0; i < index; i++) {
		// Throw an exception if the next node comes up as nullptr
		if (!nextNode) {
			error = "Index Out of Bounds Exception";
			throw error;
		}
		else
			nextNode = nextNode->next;
	}

	// Return a reference to the value of the node the loop ended on
	return nextNode->value;
}

#endif
