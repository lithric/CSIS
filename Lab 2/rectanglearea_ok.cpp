// This program will output the circumference and area
// of the circle with a given radius.

// Elion Oliver

#include <iostream>
using namespace std;

const int LENGTH = 8;
const int WIDTH = 3;

int main()
{
	int area;								// definition of area of circle 
	int perimeter;				// definition of circumference 
	perimeter = 2 * LENGTH + 2 * WIDTH;	// computes circumference
	area = LENGTH * WIDTH;							// computes area

	// Fill in the code for the cout statement that will output (with description)
	// the circumference
    cout << "the perimeter: " << perimeter << endl;
	// Fill in the code for the cout statement that will output (with description)
	// the area of the circle
    cout << "the area: " << area << endl;
	return 0;
}