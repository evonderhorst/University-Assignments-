// Author: Erich Vonderhorst
// Creation Date: 11/9/2023
// Last Update: 11/10/2023
// Description: checks an expression entered by the user to see if their use of delimiters is balanced (all
//              open brackets, braces, and parentheses are closed)
// User Interface:
//      Enter expression: put in any mathematical or coding expression, preferably one with delimiters

#include <stack>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

    string input; // for holding the expression entered by the user

    // Get the expression from the user
    cout << "Enter expression: ";
    getline(cin, input);

    stack<char> delims; // stores delimiter characters that are pushed and popped as they are opened and closed
    stringstream inputstream(input); // for seperating the expression into tokens
    char token; // holds tokens as they are taken from the stringstream

    // For all characters in the expression...
    while (!inputstream.eof()) {

        // Take and store a character from the stringstream
        token = inputstream.get();

        // Push the character on the delimiter stack if its an opening delimiting character
        if (token == '{' || token == '[' || token == '(')
            delims.push(token);

        // If the character is a closing delimiting character but the delimiter stack is empty, push it onto the
        // stack to comply with the success/ failure conditions on lines 58 - 61 and break out of the while loop
        if ((token == '}' || token == ']' || token == ')') && delims.empty()) {
            delims.push(token);
            break;
        }

        // If the character is a closing delimiting character that corresponds to the one on top of the stack,
        // pop the top of the stack
        if (token == '}' && delims.top() == '{')
            delims.pop();

        if (token == ']' && delims.top() == '[')
            delims.pop();

        if (token == ')' && delims.top() == '(')
            delims.pop();
    }

    // If the stack is empty, then that should mean that the delimiters in the expression were balanced
    // Output the result
    if (delims.empty())
        cout << "Delimiters are balanced" << endl;
    else
        cout << "Delimiters are not balanced" << endl;

    return 0;
}
