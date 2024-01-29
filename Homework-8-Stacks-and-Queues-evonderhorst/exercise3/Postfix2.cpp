// Author: Erich Vonderhorst a.k.a. Big E
// Creation Date: 11/8/2023
// Last Update: 11/10/2023
// Description: reads in a postfix expression from the user, calculates and prints its result.
// User Interface:
//      Enter a postfix expression: type and enter any valid postfix expression such as 3 5 -
// Notes: catches thrown errors for insufficient operands from input or unrecognized characters,
//        Uses STL stack and queue structures

#include <queue>
#include <stack>
#include <iostream>
#include <sstream>

using namespace std;

int main() {

    string input; // for storing and tokenizing input expression

    // Get the expression from the user
    cout << "Enter a postfix expression: ";
    getline(cin, input);

    queue<string> tokens; // for storing each character in the expression as a token
    stringstream inputstream(input); // for seperating the expression into tokens
    string token; // stores individual tokens as they are enqueued and dequeued
    double result; // stores the resulting value of each operation in the expression and the whole expression
    stack<double> operands; // stores the operands of the expression, which are popped on as the tokens are dequeued

    // Using a space as a delimiter, keep reading in "lines" from the stringstream and enqueue them until empty
    while (getline(inputstream, token, ' '))
        tokens.push(token);

    try {
        // For all tokens...
        while (!tokens.empty()) {
             // Dequeue a token
            token = tokens.front();

            // If the token is an operator character...
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Store the operand at the top of the stack and pop it (by this point, the user's expression should
                // have had at least two operands before an operator if entered correctly)
                result = operands.top();
                operands.pop();

                // Perform the operation corresponding to the token with a second stored and popped operand and
                // push the result back on the operands stack (I've said the word 'token' so many times, it makes me
                // think of Chuck E. Cheese. That place was a lot of fun as a kid. Damn, growing up fucking sucks.)
                if (token == "+") {
                    result += operands.top();
                    operands.pop();
                    operands.push(result);
                }
                else if (token == "-") {
                    result = operands.top() - result;
                    operands.pop();
                    operands.push(result);
                }
                else if (token == "*") {
                    result *= operands.top();
                    operands.pop();
                    operands.push(result);
                }
                else {
                    result = operands.top() / result;
                    operands.pop();
                    operands.push(result);
                }
            }
            // If the token isn't an operator, convert it to a double and push it on the operands stack
            else
                operands.push(stod(token));
            tokens.pop();
        }
        // Print the value at the top of the operands stack as it should be the overall result of the expression
        cout << "Value = " << operands.top() << endl;
    } catch (exception& e) {
            cout << "Invalid Postfix Expression Error." << endl;
    }

    return 0;
}
