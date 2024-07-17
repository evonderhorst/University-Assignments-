#include "Canvas.h"

using namespace std;

void startupMenu(int&, int&);
void startupConditions();

//--------------------------------------------------------------------------------------------------------------------------------------------
// MAIN
//--------------------------------------------------------------------------------------------------------------------------------------------

int main() {

    int canvasXDim; //Stores the number of columns in the user's Canvas as entered by them
    int canvasYDim; //Stores the number of rows in the user's Canvas as entered by them
    Canvas* gridptr; //Pointer for dynamically creating a pointer object

    system("Color 0"); //This statement sets the background to black, which shouldnt be needed because its black to begin with, but removing
                       //it results in the program not working properly for some unknown reason, so its just living here rent-free

    startupConditions(); //Calling the function to make the console's cursor invisible and for the window to start out maximized

    startupMenu(canvasXDim, canvasYDim); //Calling the main menu function

    //Checking to see if the values entered by the user are within possible boundaries
    if (canvasXDim <= OVERALL_COLS && canvasXDim >= 10 && canvasYDim <= OVERALL_ROWS && canvasYDim >= 10) {

        gridptr = new Canvas(canvasYDim, canvasXDim);
        (*gridptr).buildCanvas();
    }

    //If they are not, output an error message for 3 seconds and create a Canvas of the largest possible size
    else {

        gridptr = new Canvas;
        (*gridptr).buildCanvas();

        cout << "Invalid dimensions entered, defaulting to largest possible dimensions..." << endl;
        Sleep(3000); //Sleep for 3 seconds (3000 milliseconds) before executing the next line
        system("cls");
    }

    char keyPressed = ' '; //Variable for storing the user's key presses

    cout << *gridptr; //Printing the Canvas

    keyPressed = getch(); //Reading in the next key pressed

    //Main game loop
    //Exit condition: player presses q
    while (keyPressed != 'q') {

        (*gridptr).updateCanvas(keyPressed);

        keyPressed = getch();
    }

    system("cls"); //Clear screen

    cout << "Thanks for playing!" << endl; //Goodbye message

    return 0;
}

//Function for outputting the main menu and retrieving dimensions for the user's Canvas
void startupMenu(int& inputX, int& inputY) {

    //Title screen
    cout << "\e[0;37m" << "Please Be Patient, I Have..." << endl;
    cout << "\e[0;31m" << "            _____    _______   _____    _____   __  __" << endl;
    cout << "\e[0;31m" << "    /\\     |  __ \\  |__   __| |_   _|  / ____| |  \\/  | " << endl;
    cout << "\e[38;5;214m" << "   /  \\    | |__) |    | |      | |   | (___   | \\  / | " << endl;
    cout << "\e[0;33m" << "  / /\\ \\   |  _  /     | |      | |    \\___ \\  | |\\/| | " << endl;
    cout << "\e[0;32m" << " / ____ \\  | | \\ \\     | |     _| |_   ____) | | |  | | " << endl;
    cout << "\e[0;34m" << "/_/    \\_\\ |_|  \\_\\    |_|    |_____| |_____/  |_|  |_| " << "\e[0m" << endl << endl << endl;

    cout << "Press Any Key to Begin..." << endl;

    getch(); //Read in the key entered

    system("cls"); //Clear screen

    //Prompts for user and reading in entered values
    cout << "Welcome!" << endl;

    cout << "Enter the X dimension of your canvas (Min: 10, Max: 237):" << endl;
    cin >> inputX;

    cout << "Enter the Y dimension of your canvas (Min: 10, Max: 62):" << endl;
    cin >> inputY;

    system("cls"); //Clear screen
}

void startupConditions() {

    //HANDLE object that points to an address the same as a value of type DWORD that references the standard output console (somehow)
    HANDLE console_obj = GetStdHandle(STD_OUTPUT_HANDLE);

    //HWND object that serves as a handle for the console's window so that it can be modified
    HWND window_obj = GetConsoleWindow();

    //CONSOLE_CURSOR_INFO object that stores relevant data member values of a console's cursor so that they can be set and copied back over (don't think I
    //fully understand this one at the moment)
    CONSOLE_CURSOR_INFO cursor_obj;

    //Function call for showing the console window in the maximized state, indicated by the flag in the second argument
    ShowWindow(window_obj,SW_SHOWMAXIMIZED);

    //Calling a getter for the values of the cursor of the console's handle and passing the info object's address
    GetConsoleCursorInfo(console_obj, &cursor_obj);

    //Setting a public data member to false to make the cursor not appear while the program runs
    cursor_obj.bVisible = false;

    //Setting the changes made to the info object to the console's cursor so that it will not appear
    SetConsoleCursorInfo(console_obj, &cursor_obj);
}
