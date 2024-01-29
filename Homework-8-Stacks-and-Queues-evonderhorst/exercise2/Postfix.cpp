// Author: Erich Vonderhorst a.k.a. Big E
// Creation Date: 11/8/2023
// Last Update: 11/10/2023
// Description: reads in a postfix expression from the user, calculates and prints its result.
// User Interface:
//      Enter a postfix expression: type and enter any valid postfix expression such as 3 5 -
// Notes: catches thrown errors for insufficient operands from input or unrecognized characters,
//        Uses "homemade" stack and queue structures

#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {

    string input; // for storing and tokenizing input expression

    // Get the expression from the user
    cout << "Enter a postfix expression: ";
    getline(cin, input);

    Queue<string> tokens; // for storing each character in the expression as a token
    stringstream inputstream(input); // for seperating the expression into tokens
    string token; // stores individual tokens as they are enqueued and dequeued
    double result; // stores the resulting value of each operation in the expression and the whole expression
    Stack<double> operands; // stores the operands of the expression, which are popped on as the tokens are dequeued

    // Using a space as a delimiter, keep reading in "lines" from the stringstream and enqueue them until empty
    while (getline(inputstream, token, ' '))
        tokens.enqueue(token);

    try {
        // For all tokens...
        while (!tokens.isEmpty()) {
            // Dequeue a token
            token = tokens.dequeue();

            // If the token is an operator character...
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop one of the operands off of the stack (by this point, the user's expression should have had at
                // least two operands before an operator if entered correctly)
                result = operands.pop();
                // Perform the operation corresponding to the token with a second popped operand and push the
                // result back on the operands stack
                if (token == "+")
                    operands.push(result + operands.pop());
                else if (token == "-")
                    operands.push(operands.pop() - result);
                else if (token == "*")
                    operands.push(result * operands.pop());
                else
                    operands.push(operands.pop() / result);
            }
            // If the token isn't an operator, convert it to a double and push it on the operands stack
            else
                operands.push(stod(token));
        }
        // Pop and print the value of the operands stack as it should be the overall result of the expression
        cout << "Value = " << operands.pop() << endl;

    } catch (exception& e) {
            cout << "Invalid Postfix Expression Error." << endl;
    } catch (string & e) {
            cout << "Invalid Postfix Expression Error." << endl;
    }

    return 0;
}
