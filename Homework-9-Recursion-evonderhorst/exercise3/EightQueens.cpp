// Author: Erich Vonderhorst
// Creation Date: 11/17/2023
// Last Update: 11/17/2023
// Description: finds and prints the row positions of all soutions to the eight queens problem through a recursion.
// Notes: updated from a program given by the professor
#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
bool safeLocation(int row, int col, const vector<int> &queenList);
void placeQueens(vector<int> &queenList, int col, int& solutions);

int main() {
	int solutions = 0; // the total number of solutions found
	vector<int> queenList(8); // holds the row positions of the queens in each solution found

	// Loop through all 8 starting positions, find and print the solutions for each
	for (int i = 0; i < 8; i++) {
		queenList[0] = i;
		placeQueens(queenList, 1, solutions);
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
// Return: true or false depending on if each layer of recursion led to a solution or not
void placeQueens(vector<int> &queenList, int col, int& solutions) {
	int row;
	if (col == 8) {
		for (unsigned int i = 0; i < queenList.size(); i++)
			cout << queenList[i] << " ";
		cout << endl;
		solutions++;
	}
	else {
		row = 0;

		while (row < 8) {
			if (safeLocation(row, col, queenList)) {
				queenList[col] = row;
				placeQueens(queenList, col + 1, solutions);
				row++;
			} else
				row++;
		}
	}
}

