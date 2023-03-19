// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.

// Elion Oliver

#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	float g1;		// contains the amount of items purchased 
	float g2;	// contains the price of each item
	float g3;	// contains the total bill.
    float avg;

	cout << setprecision(2) << fixed << showpoint;	// formatted output 
    cout << "Please input the first grade" << endl;
    cin >> g1;
	cout << "Please input the second grade" << endl;
    cin >> g2;
    cout << "Please input the third grade" << endl;
    cin >> g3;
    avg = (g1+g2+g3)/3;
    cout << "The average of the three grades is " << avg << endl;

	// Fill in the input statement to bring in the quantity.

	// Fill in the prompt to ask for the price.

	// Fill in the input statement to bring in the price of each item.

	// Fill in the assignment statement to determine the total bill.

	// Fill in the output statement to print total bill,
	// with a label to the screen.

	return 0;
}