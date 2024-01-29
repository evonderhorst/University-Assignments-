// Author: Erich Vonderhorst
// Creation Date: 11/17/2023
// Last Update: 11/17/2023
// Description: program for testing a function that determines if a string is a palindrome or not through recursion
#include <iostream>

using namespace std;

// Palindrome function prototype
bool isPal(const string&, int, int);

int main() {
    string str; // string that will be checked to see if it is a palindrome
    bool palStatus; // flag for if the above string is a palindrome or not

    // Get the string from the user
    cout << "Enter a string, no spaces and all lower case: ";
    cin >> str;

    // Set palstatus to the value returned by the isPal function with the string passed to it
    palStatus = isPal(str,0,str.length() - 1);

    // Output the result
    if (palStatus == true)
        cout << str << " is a palindrome." << endl;
    else
        cout << str << " is not a palindrome." << endl;

    return 0;
}

// Description: determines if the passed string is a palindrome by splitting it down the middle and seeing if
//              both halves are symmetrical.
// Parameters:
//      str: the string being checked
//      startIndex: the letter on the first half being compared to the letter in endIndex
//      endIndex: the letter on the second half being compared to the letter in startIndex
// Return: true or false depending on if the string was a palindrome or not
bool isPal(const string& str, int startIndex, int endIndex) {
    if (startIndex >= endIndex)
        return true;
    if (str[startIndex] == str[endIndex])
        return isPal(str,startIndex+1,endIndex-1);
    else
        return false;
}
