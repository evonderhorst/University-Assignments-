#ifndef CANVAS_H_INCLUDED
#define CANVAS_H_INCLUDED

//--------------------------------------------------------------------------------------------------------------------------------------------
// LIBRARIES
//--------------------------------------------------------------------------------------------------------------------------------------------

#include <iostream> //For using cout and cin
#include <windows.h> //For using handles and system()
#include <conio.h> //For using getch()

using namespace std;

const int OVERALL_ROWS = 62; //Maximum number of rows a Canvas can have
const int OVERALL_COLS = 237; //Maximum number of columns a Canvas can have

//ASCII color escape codes for colored text:
const string RED = "\e[0;31m";
const string GREEN = "\e[0;32m";
const string YELLOW = "\e[0;33m";
const string BLUE = "\e[0;34m";
const string PURPLE = "\e[0;35m";
const string CYAN = "\e[0;36m";
const string WHITE = "\e[0;37m";
const string BROWN = "\e[38;5;137m";
const string ORANGE = "\e[38;5;214m";
const string PINK = "\e[38;5;211m";
const string GRAY = "\e[38;5;247m";
const string TURQUOISE = "\e[38;5;73m";
const string CRESET = "\e[0m"; //Resets the text color

//--------------------------------------------------------------------------------------------------------------------------------------------
// SPACES CLASS
//--------------------------------------------------------------------------------------------------------------------------------------------
class Spaces {

    char symbol; //Character that appears in this space whenever it is printed
    string color; //ASCII color code that determines the color that the symbol is printed in

public:

    //Constructor: assigns default values to both data members
    Spaces();

    //Setter function for symbol
    void setSymbol(char sym);

    //Getter function for symbol
    char getSymbol();

    //Setter function for color
    void setColor(string newColor);

    //Getter function for color
    string getColor();
};

//--------------------------------------------------------------------------------------------------------------------------------------------
// CANVAS CLASS
//--------------------------------------------------------------------------------------------------------------------------------------------

class Canvas {

    Spaces** cptr; //Dynamic Spaces array for keeping the color and symbol present in each cell
    int canvasRows; //The number of rows the Canvas object's dynamic array has
    int canvasCols; //The number of columns the Canvas object's dynamic array has
    int startRow; //The row number where the cursor appears when the Canvas is printed
    int startCol; //The column number where the cursor appears when the Canvas is printed
    int currentRow; //The row number of the cursor's position at any given time, used for movement
    int currentCol; //The column number of the cursor's position at any given time, used for movement
    int brushLabelRow; //The row number for where the label indicating the brush's current color is located on screen
    int brushLabelCol; //The column number for where the label indicating the brush's current color is located on screen
    char activeSymbol; //The character that appears when a cell is filled in by the user
    char passiveSymbol; //The character that appears in each cell when they have not been filled in
    char cursorSymbol; //The character that appears at the location of the cursor
    char borderSymbol; //The character that makes up the Canvas' border
    char cursorOnActiveSymbol; //The character that appears at the location of the cursor when it shared the location of a cell that has
                               //already been filled in
    string borderColor; //The ASCII color escape code that indicates the color the border should be printed in
    string activeColor; //The ASCII color escape code that indicates the color that the next cell filled in by the user should be
    string defaultColor; //The ASCII color reset escape code that indicates the color of the background

public:

    //Constructor: assigns default and passed values to all data members
    Canvas(int row = OVERALL_ROWS, int col = OVERALL_COLS);

    //Destructor: deallocates cptr and its pointees
    ~Canvas();

    //Extraction operator overload for printing the Canvas
    friend ostream& operator<< (ostream& out, const Canvas& rhs);

    //Function for assigning color codes and symbols to each Square in cptr's pointees
    void buildCanvas();

    //Function that registers movement and color changes based onto the key pressed by user which is passed as an argument
    void updateCanvas(const char& direction);

    //Function for printing in specific areas so that the entirety of cptr does not have to reprint (doing that was very slow),
    //Reprints the symbol and color of the Space at the passed coordinates
    void localPrint(int x, int y);

    //Function similar to above but has an extra parameter for printing a symbol other than the one stored in the Space in the
    //passed coordinates
    void localPrint(int r, int c, char symbol);

    //Function similar to above but for reprinting the cursor as it moves so that it doesn't interfere with the stored colors of
    //each Space it passes over
    void printCursor(int r, int c);

    //Function that allows the console window to be opened as maximized immediately and the console's flickering cursor to be made
    //invisible
    void startupConditions();
    };

#endif // CANVAS_H_INCLUDED
