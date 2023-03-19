// This program will output the circumference and area
// of the circle with a given radius.

// Elion Oliver

#include <iostream>
using namespace std;

const double PI = 3.14;
const double RADIUS = 5.4;

int main()
{
	int area;								// definition of area of circle 
	int circumference;				// definition of circumference 
	circumference = 2 * PI * RADIUS;	// computes circumference
	area = PI * RADIUS * RADIUS;							// computes area

	// Fill in the code for the cout statement that will output (with description)
	// the circumference
    cout << "the circumference: " << circumference << endl;
	// Fill in the code for the cout statement that will output (with description)
	// the area of the circle
    cout << "the area: " << area << endl;
	return 0;
}