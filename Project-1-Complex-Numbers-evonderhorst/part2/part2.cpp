// Author: Erich Vonderhorst
// Creation Date: 10/15/2023
// Last Update: 10/16/2023
// Description: reads in different parameter values from user input and then applies them to the creation of a bitmap image.
// User Interface:
//      "Input the image size (in pixels): ": enter the resolution of the generated bitmap image, entering n pixels ill result in
//                                            an image with n x n resolution.
//      "Input maximum iteration, boarder ratio, etc.: ": enter different parameters for the creation of the bitmap that I am
//                                                        unfamiliar with how they work.
//      "Input the output file name (no spaces or extension): ": enter the name of the bitmap image file the program will generate
// Notes: no clue what any of this does

#include "Complex.h"
#include "bitmap_image.hpp"

using namespace std;

int main() {

    // Variables
    unsigned int size, maxiter; // the size of the image in pixels and the value for the maximum iteration when generating the image
    double cr, ci; // the real and imaginary portions of the Complex value object c
    double boarderRatio, colorExponent, bailout; // values for the boarder ratio, color exponent, and bailout radius
    string filename; // the name of the file that the program will generate

    // Read in all values
    cout << "Input the image size (in pixels): ";
    cin >> size;

    cout << "Input the real value of c: ";
    cin >> cr;

    cout << "Input the imaginary value of c: ";
    cin >> ci;

    cout << "Input the maximum iteration (100-1,000): ";
    cin >> maxiter;

    cout << "Input the border ratio (0-1): ";
    cin >> boarderRatio;

    cout << "Input the color exponent (0-1): ";
    cin >> colorExponent;

    cout << "Input the bailout radius (>= 4): ";
    cin >> bailout;

    cout << "Input the output file name (no spaces or extension): ";
    cin >> filename;

    // Create an image of size x size and clear it
    bitmap_image pic(size, size);
    pic.clear();

    // Create two Complex values, c and z, with c using the values cr and ci
    Complex c(cr, ci);
    Complex z;

    // Loop through each pixel in the image
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {

           // Initialize the real and imaginary portions for z to be set to
           double zr = (4.0 * x) / size - 2; // real portion, a, of the Complex value, z (a + bi)
           double zi = (4.0 * y) / size - 2; // imaginary portion, b, of the Complex value, z (a + bi)
           z.set(zr, zi);
           int col; // color value
           unsigned int n = 0; // iteration value for the while loop below

           // Determine what color the current pixel should be
           while (n < maxiter) {

                z = (z ^ 2) + c;

                if (z.mod() > bailout) {

                    // Assign a color value to col
                    col = 0;

                    if (n > (maxiter * boarderRatio))
                        col = 255;

                    else if (static_cast<double> (n) != maxiter)
                        col = pow((static_cast<double> (n) / maxiter), colorExponent) * 255;

                    // Set the pixel at the current position to a grayscale value using col as the R, G, and B values
                    pic.set_pixel(x, y, col, col, col);
                    n = maxiter;
               }
               // Increment n
               n++;
           }
        }
    }
    // Save the generated image as the input name with the .bmp extension
    pic.save_image(filename + ".bmp");
}
