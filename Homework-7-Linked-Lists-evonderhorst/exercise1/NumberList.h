// Specification file for the NumberList class
#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList {
private:
	// Declare a structure for the list
	struct ListNode {
		int value;              // The value in this node
		struct ListNode *next;  // To point to the next node
	};

	ListNode *head;            // List head pointer

public:
	// Constructor
	NumberList() {
		head = nullptr;
	}

	// Destructor
	~NumberList();

	// Linked list operations
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void deleteList();
	int length();
	void displayList() const;
};
#endif
