// Author: Erich Vonderhorst
// Creation Date: 11/17/2023
// Last Update: 11/17/2023
// Description:
#include <iostream>
#include <vector>

using namespace std;

// Permutation function prototype
void permute(vector<int> permList, int index);

int main() {

    int size;

    // Get the size of the list from the user
    cout << "Enter the size of the permutation list: ";
    cin >> size;
    cout << endl;

    // Create a vector of the specified size and populate it with values 1 through the size value
    vector<int> list;
    for (int i = 0; i < size; i++)
        list.push_back(i + 1);

    // Determine and show permutations
    permute(list, 0);

    return 0;
}

// Description: prints out all of the possible perutations of the passed list
// Parameters:
//      permList: the list to have its permutations printed
//      index: the index to start recursing from
void permute(vector<int> permList, int index) {
    if (index == permList.size()) {
        for (unsigned int i = 0; i < permList.size(); i++)
            cout << permList[i] << " ";
        cout << endl;
    }
    else {
        permute(permList,index + 1);
        for (unsigned int i = 0; i < permList.size() - index - 1; i++) {
            int temp = permList[index + i + 1];
            permList[index + i + 1] = permList[index];
            permList[index] = temp;
            permute(permList,index + 1);
        }
    }
}
