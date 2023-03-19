// This program has the user input a number n and then finds the
// mean of the first n positive integers

// PLACE YOUR NAME HERE

#include <iostream>
using namespace std;

int main()
{
	int value1;		// value is some positive number n
    int value2;
	int total = 0;	// total holds the sum of the first n positive numbers 
	int number;		// the amount of numbers
	float mean;		// the average of the first n positive numbers

	cout << "Please enter two positive integers separated by a space" << endl;
    cout << "The first number must be smaller than the second number" << endl;
	cin >> value1 >> value2;

	if (value1 >= 0 && value2 >= 0) {
		for (number = value1; number <= value2; number++) {
			total = total + number;
		}	// curly braces are optional since there is only one statement

		mean = static_cast<float>(total) / (value2 - value1 + 1);	// note the use of the typecast
													// operator here 
		cout << "The mean average of the postive integers from " << value1 << " to " << value2 << " is " << mean << endl;
	}

	else
		cout << "Invalid input - integer must be positive" << endl;

	return 0;
}