// This program will read in the quantity of a particular item and its price.
// It will then print out the total price.
// The input will come from the keyboard and the output will go to
// the screen.

// Elion Oliver

#include<iostream>
#include<iomanip>
using namespace std;

const float ACP = 85.00;
const float MP = 57.50;
const float FCP = 127.75;

int main()
{
	float ac;	
    float act;
	float m;
    float mt;
	float fc;
    float fct;
    float allt;

	cout << setprecision(2) << fixed << showpoint;	// formatted output 
    cout << "Please input the number of American Colonial chairs sold" << endl;
    cin >> ac;
	cout << "Please input the number of Modern chairs sold" << endl;
    cin >> m;
    cout << "Please input the number of French Classical chairs sold" << endl;
    cin >> fc;
    act = ac*ACP;
    mt = m*MP;
    fct = fc*FCP;
    allt = act + mt + fct;
    cout << "The total sales of American Colonial chairs $" << act << endl;
    cout << "The total sales of Modern chairs $" << mt << endl;
    cout << "The total sales of French Classical chairs $" << fct << endl;
    cout << "The total sales of all chairs $" << allt << endl;

	// Fill in the input statement to bring in the quantity.

	// Fill in the prompt to ask for the price.

	// Fill in the input statement to bring in the price of each item.

	// Fill in the assignment statement to determine the total bill.

	// Fill in the output statement to print total bill,
	// with a label to the screen.

	return 0;
}