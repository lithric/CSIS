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
	float totalSales;		// contains the amount of items purchased 
	float stateTax;	// contains the price of each item
	float localTax;	// contains the total bill.

	cout << setprecision(2) << fixed << showpoint;	// formatted output 
    cout << "Please input the total sales" << endl;
    cin >> totalSales;
	cout << "Please input the state tax percentage in decimal form (.02 for 2%)" << endl;
    cin >> stateTax;
    cout << "Please input the local tax percentage in decimal form (.02 for 2%)" << endl;
    cin >> localTax;
    cout << "The total sales for the month is $" << totalSales << endl;
    cout << "The state tax for the month is $" << totalSales * stateTax << endl;
    cout << "The total bill is $" << totalSales * localTax << endl;

	// Fill in the input statement to bring in the quantity.

	// Fill in the prompt to ask for the price.

	// Fill in the input statement to bring in the price of each item.

	// Fill in the assignment statement to determine the total bill.

	// Fill in the output statement to print total bill,
	// with a label to the screen.

	return 0;
}