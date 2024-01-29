// Author: Erich Vonderhorst
// Creation Date: 11/17/2023
// Last Update: 11/17/2023
// Description: finds and prints the row positions of all soutions to the eight queens problem through recursion.
//				this version of the program allows the number of rows and columns, n, in an n X n chessboard
//				(the number of queens) is determiend by the user.
// Notes: updated from a program given by the professor
#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
bool safeLocation(int row, int col, const vector<int> &queenList);
void placeQueens(vector<int> &queenList, int col, int& solutions, const int& size);

int main() {
	int size; // the number of rows and columns, n, in an n x n chessboard
	int solutions = 0; // the total number of solutions found

	// Get the size of the board from the user
	cout << "Input the board size n X n. n = ";
	cin >> size;

	vector<int> queenList(size); // holds the row positions of the queens in each solution found

	// Loop through all possible starting positions, find and print the solutions for each
	for (int i = 0; i < size; i++) {
		queenList[0] = i;
		placeQueens(queenList, 1, solutions, size);
	}

	// Output the number of solutions
	cout << "The number of solutions is " << solutions << endl;

	return 0;
}

// Description: determines if a queen at the passed coordinates can be attacked by the other queens on the board
// Parameters:
//		queenList: vector of the row values where the other queens are placed
//		col: column position of the queen being evaluated
//		row: row position of the queen being evaluated
// Return: true or false depending on if the queen in question can be attacked by the other queens or not
bool safeLocation(int row, int col, const vector<int> &queenList) {
	for (int qCol = 0; qCol < col; qCol++) {
		int qRow = queenList[qCol];
		if (qRow == row)
			return false;
		else if (qCol == col)
			return false;
		else if (qCol - qRow == col - row || qCol + qRow == col + row)
			return false;
	}
	return true;
}

// Description: exhaustively determines all possible solutions to the eight queens problem through recursion.
// Parameters:
//		queenList: vector of the row values where the queens are placed in a solution
//		col: the current column being checked for safe positions
//		solutions: number of solutions found
//		size: the number of rows, columns, and maximum number of queens on the chessboard
// Return: true or false depending on if each layer of recursion led to a solution or not
void placeQueens(vector<int> &queenList, int col, int& solutions, const int& size) {
	int row;
	if (col == size) {
		for (unsigned int i = 0; i < queenList.size(); i++)
			cout << queenList[i] << " ";
		cout << endl;
		solutions++;
	}
	else {
		row = 0;

		while (row < size) {
			if (safeLocation(row, col, queenList)) {
				queenList[col] = row;
				placeQueens(queenList, col + 1, solutions, size);
				row++;
			} else
				row++;
		}
	}
}

