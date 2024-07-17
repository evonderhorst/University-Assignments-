#include "Canvas.h"

//--------------------------------------------------------------------------------------------------------------------------------------------
// HANDLES
//--------------------------------------------------------------------------------------------------------------------------------------------

//Note: handles are pointers in the Windows (win32) API with pointees that are objects in a heap separate from that the one where
//memory allocated using the new operator are formed (new operator uses what is called the CRT heap, theres others but I dunno what they are and do)

//HANDLE object that points to an address the same as a value of type DWORD that references the standard output console (somehow), used in making the
//cursor invisible and printing at specific cell coordinates
HANDLE console_obj = GetStdHandle(STD_OUTPUT_HANDLE);

//HWND object that serves as a handle for the console's window so that it can be modified, used in starting the console window in maximized mode
HWND window_obj = GetConsoleWindow();

//COORD object that holds the coordinates of a character cell in the console, used for setting the cursor's position to a specific character cell location
COORD cursorPos;

//--------------------------------------------------------------------------------------------------------------------------------------------
// MEMBER FUNCTIONS IMPLEMENTATION
//--------------------------------------------------------------------------------------------------------------------------------------------

//Canvas constructor
Canvas:: Canvas(int r, int c) {

    //Assigning the passed values
    canvasRows = r;
    canvasCols = c;

    //Allocating cptr part 1
    cptr = new Spaces*[canvasRows];

    //Setting starting cursor position
    startRow = 1;
    currentRow = 1;

    startCol = 1;
    currentCol = 1;

    //Allocating cptr part 2
    for (int row = 0; row < canvasRows; row++) {

        cptr[row] = new Spaces[canvasCols];
    }

    //Assigning values to other data members
    brushLabelRow = canvasRows;
    brushLabelCol = 7;
    passiveSymbol = ' ';
    activeSymbol = char(219); //This ASCII character code fills in an entire character cell as a solid block
    cursorSymbol = 'X';
    borderSymbol = '#';
    cursorOnActiveSymbol = char(178); //Similar to ASCII character code 219 but with ripples inside of it
    borderColor = WHITE;
    activeColor = WHITE;
    defaultColor = WHITE;
}

//Destructor
Canvas:: ~Canvas() {

    //Looping through and deleting cptr and its pointees
    for (int r = 0; r < canvasRows; r++) {

        delete[] cptr[r];
    }

    delete[] cptr;
}

//Extraction operator overload that allows the Canvas' array and the menu to be printed seamlessly
ostream& operator<< (ostream& out, const Canvas& rhs) {

    for (int r = 0; r < rhs.canvasRows; r++) {

        for (int c = 0; c < rhs.canvasCols; c++) {

            out << rhs.cptr[r][c].getColor() << rhs.cptr[r][c].getSymbol() << CRESET;
        }

        out << endl;
    }

    //Brush label
    out << "Brush: " << rhs.activeColor << rhs.activeSymbol << CRESET;

    //Displaying color keys
    out << "\t\tColors:\t1:" << RED << "X" << CRESET;
    out << "\t2:" << GREEN << "X" << CRESET;
    out << "\t3:" << BLUE << "X" << CRESET;
    out << "\t4:" << YELLOW << "X" << CRESET;
    out << "\t5:" << PURPLE << "X" << CRESET;
    out << "\t6:" << ORANGE << "X" << CRESET;
    out << "\t7:" << CYAN << "X" << CRESET;
    out << "\t8:" << PINK << "X" << CRESET;
    out << "\t9:" << BROWN << "X" << CRESET;
    out << "\t0:" << WHITE << "X" << CRESET;
    out << "\t-:" << GRAY << "X" << CRESET;
    out << "\t=:" << TURQUOISE << "X" << CRESET;

    //Displaying how to erase and quit
    out << "\t\tPress r to erase";
    out << "\t\tPress q to quit";

    return out;
}

//Function that registers movement and color changes from keys pressed by the user
void Canvas:: updateCanvas(const char& direction) {

    switch (direction) {

        //This program uses WASD for movement

        //Moving the cursor left
        case 'a':

            if (currentCol != 1) {

                if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol) {

                    cptr[currentRow][currentCol].setSymbol(passiveSymbol);
                    localPrint(currentRow, currentCol);
                }

                else {

                    cptr[currentRow][currentCol].setSymbol(activeSymbol);
                    localPrint(currentRow, currentCol);
                }

                if (cptr[currentRow][currentCol - 1].getSymbol() != activeSymbol) {

                    cptr[currentRow][currentCol - 1].setSymbol(cursorSymbol);
                    printCursor(currentRow, currentCol - 1);
                }

                else {

                    cptr[currentRow][currentCol - 1].setSymbol(cursorOnActiveSymbol);
                    localPrint(currentRow, currentCol - 1);
                }

                currentCol -= 1;
            }

            break;

        //Moving the cursor right
        case 'd':

            if (currentCol != canvasCols - 2) {

                if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol) {

                    cptr[currentRow][currentCol].setSymbol(passiveSymbol);
                    localPrint(currentRow, currentCol);
                }

                else {

                    cptr[currentRow][currentCol].setSymbol(activeSymbol);
                    localPrint(currentRow, currentCol);
                }

                if (cptr[currentRow][currentCol + 1].getSymbol() != activeSymbol) {

                    cptr[currentRow][currentCol + 1].setSymbol(cursorSymbol);
                    printCursor(currentRow, currentCol + 1);
                }

                else {

                    cptr[currentRow][currentCol + 1].setSymbol(cursorOnActiveSymbol);
                    localPrint(currentRow, currentCol + 1);
                }

                currentCol += 1;
            }

            break;

        //Moving the cursor up
        case 'w':

            if (currentRow != 1) {

                if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol) {

                    cptr[currentRow][currentCol].setSymbol(passiveSymbol);
                    localPrint(currentRow, currentCol);
                }

                else {

                    cptr[currentRow][currentCol].setSymbol(activeSymbol);
                    localPrint(currentRow, currentCol);
                }

                if (cptr[currentRow - 1][currentCol].getSymbol() != activeSymbol) {

                    cptr[currentRow - 1][currentCol].setSymbol(cursorSymbol);
                    printCursor(currentRow - 1, currentCol);
                }

                else {

                    cptr[currentRow - 1][currentCol].setSymbol(cursorOnActiveSymbol);
                    localPrint(currentRow - 1, currentCol);
                }

                currentRow -= 1;
            }

            break;

        //Moving the cursor down
        case 's':

            if (currentRow != canvasRows - 2) {

                if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol) {

                    cptr[currentRow][currentCol].setSymbol(passiveSymbol);
                    localPrint(currentRow, currentCol);
                }

                else {

                    cptr[currentRow][currentCol].setSymbol(activeSymbol);
                    localPrint(currentRow, currentCol);
                }

                if (cptr[currentRow + 1][currentCol].getSymbol() != activeSymbol) {

                    cptr[currentRow + 1][currentCol].setSymbol(cursorSymbol);
                    printCursor(currentRow + 1, currentCol);
                }

                else {

                    cptr[currentRow + 1][currentCol].setSymbol(cursorOnActiveSymbol);
                    localPrint(currentRow + 1, currentCol);
                }

                currentRow += 1;
            }

            break;

        //Drawing (filling in a character cell)
        case 'f':

            cptr[currentRow][currentCol].setSymbol(cursorOnActiveSymbol);
            cptr[currentRow][currentCol].setColor(activeColor);
            localPrint(currentRow, currentCol);

            break;

        //Erasing (emptying a character cell)
        case 'r':

            if (cptr[currentRow][currentCol].getSymbol() != ' ') {

                cptr[currentRow][currentCol].setSymbol(cursorSymbol);
                cptr[currentRow][currentCol].setColor(defaultColor);
                printCursor(currentRow, currentCol);
            }

            break;


    //Color changes
        case '1':

            activeColor = RED;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << RED;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '2':

            activeColor = GREEN;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << GREEN;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '3':

            activeColor = BLUE;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << BLUE;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '4':

            activeColor = YELLOW;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << YELLOW;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '5':

            activeColor = PURPLE;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << PURPLE;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '6':

            activeColor = ORANGE;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << ORANGE;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '7':

            activeColor = CYAN;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << CYAN;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '8':

            activeColor = PINK;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << PINK;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '9':

            activeColor = BROWN;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << BROWN;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '0':

            activeColor = WHITE;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << WHITE;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '-':

            activeColor = GRAY;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << GRAY;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;

        case '=':

            activeColor = TURQUOISE;

            if (cptr[currentRow][currentCol].getSymbol() != cursorOnActiveSymbol)
                printCursor(currentRow, currentCol);

            cout << TURQUOISE;
            localPrint(brushLabelRow,brushLabelCol, activeSymbol);
            cout << CRESET;

            break;
    }
}

//Function for setting default values to every Space in cptr
void Canvas:: buildCanvas() {

    //Looping through all Spaces
    for (int r = 0; r < canvasRows; r++) {

        for (int c = 0; c < canvasCols; c++) {

            //Applying border color and symbol to spaces on the border indexes
            if (r == 0 || r == canvasRows - 1 || c == 0 || c == canvasCols - 1) {

                cptr[r][c].setSymbol(borderSymbol);
                cptr[r][r].setColor(borderColor);
            }

            //Applying color and symbol to everything else
            else {

                cptr[r][c].setSymbol(passiveSymbol);
                cptr[r][c].setColor(activeColor);
            }
        }
    }

    //Placing the cursor in the starting position
    cptr[startRow][startCol].setSymbol(cursorSymbol);
}

//Function for starting printing at a specific character cell coordinate
void Canvas:: localPrint(int r, int c) {

    //Setting public data members to passed values
    cursorPos.X = c;
    cursorPos.Y = r;

    //Calling a function to position cursor
    SetConsoleCursorPosition(console_obj, cursorPos);

    //Printing at cursor location
    cout << cptr[r][c].getColor() << cptr[r][c].getSymbol() << CRESET;
}

//Similar to above but for the cursor
void Canvas:: printCursor(int r, int c) {

    //Setting public data members to passed values
    cursorPos.X = c;
    cursorPos.Y = r;

     //Calling a function to position cursor
    SetConsoleCursorPosition(console_obj, cursorPos);

    //Printing at cursor location
    cout << activeColor << cptr[r][c].getSymbol() << CRESET;
}

void Canvas:: localPrint(int r, int c, char symbol) {

    //Setting public data members to passed values
    cursorPos.X = c;
    cursorPos.Y = r;

    //Calling a function to position cursor
    SetConsoleCursorPosition(console_obj, cursorPos);

    //Printing the Space's symbol at the cursor location
    cout << symbol;
}

//Spaces constructor
Spaces:: Spaces() {

    symbol = ' ';
    color = CRESET;
}

//Setter for a Space's symbol member
void Spaces:: setSymbol(char sym) {

    symbol = sym;
}

//Getter for a Space's symbol member
char Spaces:: getSymbol() {

    return symbol;
}

//Setter for a Space's color member
void Spaces:: setColor(string newColor) {

    color = newColor;
}

//Getter for a Space's color member
string Spaces:: getColor() {

    return color;
}
