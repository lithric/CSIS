// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.

// Elion Oliver

#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
	int	quantity;		// contains the amount of items purchased 
	float itemPrice;	// contains the price of each item
	float totalBill;	// contains the total bill.
    string name;

	cout << setprecision(2) << fixed << showpoint;	// formatted output 
    cout << "Please input the name of the item" << endl;
    getline(cin,name);
    cout << endl;
	cout << "Please input the number of items bought" << endl;
    cin >> quantity;
    cout << endl;
    cout << "Please input the price of each item" << endl;
    cin >> itemPrice;
    totalBill = quantity * itemPrice;
    cout << endl;
    cout << "The item that you bought is " << name << endl;
    cout << "The total bill is $" << totalBill << endl;

	// Fill in the input statement to bring in the quantity.

	// Fill in the prompt to ask for the price.

	// Fill in the input statement to bring in the price of each item.

	// Fill in the assignment statement to determine the total bill.

	// Fill in the output statement to print total bill,
	// with a label to the screen.

	return 0;
}