#include "IntArrayList.h"

using namespace std;

// Author: Erich Vonderhorst
// Creation Date: 9/20/2023
// Last Update: 9/22/2023

    // Description: constructor for instances of the IntArrayList class
    // Parameters: none
    // Return: a new instance of the IntArrayList class
    // Notes: none
    IntArrayList:: IntArrayList() {

        list = nullptr;
        size = 0;
    }

    // Description: destructor for instances of the IntArrayList class
    // Parameters: none
    // Return: none
    // Notes: none
    IntArrayList:: ~IntArrayList() {

        delete[] list;
    }

    // Description: turns the the passed instance into a duplication of the current instance
    // Parameters:
    //      IntArrayList& dupe: instance containing to be duplicated
    // Return: void
    // Notes: any data in the passed instance will be lost when the function is called
    void IntArrayList:: duplicate(IntArrayList& dupe) {

        dupe.size = size;
        delete[] dupe.list;
        dupe.list = new int[size];

        for (int i = 0; i < size; i++)
            *(dupe.list + i) = *(list + i);
    }

    // Description: displays the values in the dynamic member array in a format depending on the passed boolean value
    // Parameters:
    //      bool vert: if true, each value will be printed on its own line whereas they will all be on the same line if false
    // Return: void
    // Notes: none
    void IntArrayList:: display(bool vert) {

        for (int i = 0; i < size; i++) {

            if (vert)
                cout << *(list + i) << endl;

            else
                cout << *(list + i) << " ";
        }

        cout << endl;
    }

    // Description: prints the hexadecimal value of the address being pointed to by the dynamic array member
    // Parameters: none
    // Return: void
    // Notes: none
    void IntArrayList:: displayAddress() {

        cout << list << endl;
    }

    // Description: uses selection sort to sort the values of the array member in ascending order
    // Parameters: none
    // Return: void
    // Notes: none
    void IntArrayList:: sort() {

        int targetIndex; //index of the value found to placed next in ascending order
        int swapTemp; //temporary variable used for swapping elements

        // Search for the lowest value in the array and remaining portions of the array on subsequent iterations
        for (int i = 0; i < size - 1; i++) {

            targetIndex = i;

            for (int j = 0; j < size - i - 1; j++) {

                if (*(list + targetIndex) > *(list + j + i + 1))
                    targetIndex = j + i + 1;
            }

            if (targetIndex != i) {

                // Swap the values of the target index and index being searched for if the value isn't already in place
                swapTemp = *(list + i);
                *(list + i) = *(list + targetIndex);
                *(list + targetIndex) = swapTemp;
            }
        }

    }

    // Description: returns true if the array member of the current instance is sorted or false if it is not
    // Parameters: none
    // Return: a boolean value relating to whether the array is sorted or not
    // Notes: none
    bool IntArrayList:: sorted() {

        // Each subsequent value should be greater than the last if sorted
        for (int i = 0; i < size - 1; i++) {

            if (*(list + i) > *(list + i + 1))
                return false;
        }

        return true;
    }

    // Description: appends the current instance's array member with the passed value
    // Parameters:
    //      int newVal: value to be added to the current instance's array
    // Return: void
    // Notes: none
    void IntArrayList:: add(int newVal) {

        int* tempArr = new int[size + 1]; //temporary array with an extra allocated element

        // Copy over the old array
        for (int i = 0; i < size; i++)
            *(tempArr + i) = *(list + i);

        // Place the passed value in the last index
        *(tempArr + size) = newVal;

        // Deallocate the old array and update the members
        delete[] list;
        list = tempArr;
        size++;
    }

    // Description: alters the current instance to combine the array of the passed instance with its own
    // Parameters:
    //      const IntArrayList& addList: the instance whose array is to append that of the current instance
    // Return: void
    // Notes: the passed array is unaffected by calling this function
    void IntArrayList:: concat(const IntArrayList& addList) {

        int* tempArr = new int[size + addList.size]; //temporary array with spaced allocated to fit the elements of both arrays

        // Add the values of the current instance's array
        for (int i = 0; i < size; i++)
            *(tempArr + i) = *(list + i);

        // Add the values of the passed instance's array
        for (int j = 0; j < addList.size; j++)
            *(tempArr + size + j) = *(addList.list + j);

        // Deallocate current instance's array and update its members
        delete[] list;
        list = tempArr;
        size += addList.size;
    }

    // Description: removes elements from the current isntance's array in the range of indexes bewteen the passed values
    // Parameters:
    //      int startIndex: index where the values of the should start being removed
    //      int endIndex: index where the values of the array should be removed up to
    // Return: void
    // Notes: removes values from startIndex up to but not including endIndex
    void IntArrayList:: remove(int startIndex, int endIndex) {

        // Validate passed indices
        if (startIndex < 0)
            startIndex = 0;

        if (endIndex >= size)
            endIndex = size - 1;

        // Deallocate the array and set to nullptr if the range encompasses the whole array
        if ((endIndex - startIndex) >= size) {

            delete[] list;
            list = nullptr;
            size = 0;
        }

        // Remove specified range of elements from the array member
        if (endIndex > startIndex && (endIndex - startIndex) < size) {

            int targetIndex = 0; //stores an offset used for tracking the index of the old array to be stored in the new one
            int* tempArr = new int[size - (endIndex - startIndex)]; //temporary pointer to the new array with a number of
                                                                    //elements allocated equal to how many will remain after
                                                                    //those specified are removed

            // Transfer values not in the removed range to the new array
            for (int i = 0; i < size; i++) {

                if (i < startIndex && i >= endIndex)
                    *(tempArr + targetIndex++) = *(list + i);
            }

            // Deallocate the old array and update members
            delete[] list;
            list = tempArr;
            size -= endIndex -startIndex;
        }
    }


    // Description: shuffles the values in the elements of the current instance's array member
    // Parameters: none
    // Return: void
    // Notes: none
    void IntArrayList:: shuffle() {

        random_shuffle(list, (list + size - 1));
    }

    // Description: turns the member array into a subarray consisting only of the values in the specified range of the old array
    // Parameters:
    //      int startIndex: index of the old array where the subarray should begin
    //      int endIndex: index of the old array where the subarray should end
    // Return: void
    // Notes: subarray includes values from the startIndex up to but not including the endIndex
    void IntArrayList:: sub(int startIndex, int endIndex) {

        // Validating passed values
        if (startIndex < 0)
            startIndex = 0;

        if (endIndex > size)
            endIndex = size - 1;

        // Deallocate the array and set it to nullptr if the both passed indices are the same
        if (endIndex - startIndex == 0) {

            delete[] list;
            list = nullptr;
            size = 0;
        }

        // Copy over the specified range of elements from the old array to the subarray
        if (endIndex > startIndex && endIndex - startIndex != 0) {

            int targetIndex = 0; //stores an offset used for tracking the index of the old array to be stored in the new one
            int* tempArr = new int[endIndex - startIndex]; //temporary pointer to the subarray with a number of elements
                                                           //allocated equal to how many are in the range of the passed indices

            // Copy over the values
            for (int i = 0; i < size; i++) {

                if (i >= startIndex && i < endIndex)
                    *(tempArr + targetIndex++) = *(list + i);
            }

            // Deallocate old array and update members
            delete[] list;
            list = tempArr;
            size = endIndex-startIndex;
        }
    }

    // Description: inserts the values of the passed instance's array into that of the current instance starting at the passed
    //              index
    // Parameters:
    //      const IntArrayList& addList: instance whose array elements will be placed into the that of the current instance
    //      int index: index where the elements of the passed instance's array should start appearing in the current instance's
    // Return: void
    // Notes: none
    void IntArrayList:: insert(const IntArrayList& addList, int index) {

        // Validate passed index
        if (index < 0)
            index = 0;

        if (index > size)
            index = size;

        int* tempArr = new int[size + addList.size]; //temporary pointer to the new array with allocated elements equal to the
                                                     //combined sizes of the current and passed instances' arrays


        // Copy over the elements of the old array up to the passed index
        for (int i = 0; i < index; i++)
            *(tempArr + i) = *(list + i);

        // Copy over the elements ofthe passed instance's array
        for (int j = 0; j < addList.size; j++)
            *(tempArr + index + j) = *(addList.list + j);

        // Copy over the rest of the old array's elements
        for (int k = 0; k < size - index; k++)
            *(tempArr + index + addList.size + k) = *(list + index + k);

        // Deallocate the old array and update the members
        delete[] list;
        list = tempArr;
        size += addList.size;
    }

    // Description: inserts the passed value into the current instance's array at the passed index
    // Parameters:
    //      int addVal: value of the element to be added
    //      int index: index where the passed value should appear in the array
    // Return: void
    // Notes: shifts all elements following the passed index up one index to accommodate the passed value
    void IntArrayList:: insert(int addVal, int index) {

        int step = 0; //stores an offset used for tracking the index of the old array to be stored in the new one
        int* tempArr = new int[size + 1]; //temporary pointer to the new array allocated with an extra element

        // Copy over all the old values
        for (int i = 0; i < size + 1; i++) {

            if (i != index)
                *(tempArr + i) = *(list + i - step);

            else {

                // Offset the indices of subsequent element copies by -1 to compensate for the iterator being incremented
                step = 1;
                *(tempArr + i) = addVal; //insert passed value
            }
        }

        // Deallocate old array and update members
        delete[] list;
        list = tempArr;
        size++;
    }

    // Description: accessor for any element in the member array
    // Parameters:
    //      int index: index of the element being accessed
    // Return: the value of the element in the passed index
    // Notes: shifts all elements following the passed index up one index to accommodate the passed value
    int IntArrayList:: get(int index) {

        // Return 0 if the array is empty
        if (size == 0)
            return 0;

        // Return the first element if passed index is below 0
        if (index < 0)
            return *(list);

        // Return the last element if the passed index is beyond the array's size
        if (index >= size)
            return *(list + size - 1);

        // Return the value in the passed index
        return *(list + index);
    }

    // Description: mutator for any value in the member array
    // Parameters:
    //      int addVal: the value that the element in the passed index will be changed to
    //      int index: index of the element being changed
    // Return: void
    // Notes: none
    void IntArrayList:: set(int addVal, int index) {

        // Validate the passed index
        if (index < 0 || index >= size)
            return;

        *(list + index) = addVal;
    }

    // Description: increases or decreases the number of elements in the array member
    // Parameters:
    //      int newSize: new size for member array to be allocated
    // Return: void
    // Notes: elements of arrays resized to be larger are all set to zero passed those copied over from the old array
    void IntArrayList:: resize(int newSize) {

        // Deallocate the array member, set it to nullptr, and set the size to 0 if the passed size is 0
        if (newSize == 0) {

            delete[] list;
            list = nullptr;
            size = 0;
            return;
        }

        // Exit the function if the passed size is the same as the current size
        if (newSize == size)
            return;

        int* tempArr = new int[newSize]; //temporary pointer to the new array allocated with the new number of elements

        // Copy over as many elements from the old array as possible
        for (int i = 0; i < newSize; i++) {

            // Set any extra elements to 0
            if (i >= size)
                *(tempArr + i) = 0;

            else
                *(tempArr + i) = *(list + i);
        }

        // Deallocate the old array and update members
        delete[] list;
        list = tempArr;
        size = newSize;
    }

    // Description: accessor for the size data member
    // Parameters: none
    // Return: the value stored in the size data member
    // Notes: none
    int IntArrayList:: length() {

        return size;
    }
