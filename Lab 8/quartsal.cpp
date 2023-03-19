// This program will read in the quarterly sales transactions for a given number
// of years. It will print the year and transactions in a table format.
// It will calculate year and quarter total transactions.

// PLACE YOUR NAME HERE

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXYEAR = 10;
const int MAXCOL = 5;

typedef int SalesType[MAXYEAR][MAXCOL];	// creates a new 2D integer data type 

void getSales(SalesType, int&);		// places sales figures into the array
void printSales(SalesType, int);	// prints data as a table
void printTableHeading();			// prints table heading

int main()
{
	int yearsUsed;		// holds the number of years used
	SalesType sales;	// 2D array holding the sales transactions 

	getSales(sales, yearsUsed);		// calls getSales to put data in array
	printTableHeading();			// calls procedure to print the heading 
	printSales(sales, yearsUsed);	// calls printSales to display table

	return 0;
}

//*****************************************************************************
//	printTableHeading
//
//	task:	  This procedure prints the table heading
//	data in:  none
//	data out: none
//
//*****************************************************************************

void printTableHeading()
{
	cout << setw(30) << "YEARLY QUARTERLY SALES" << endl << endl << endl;

	cout << setw(10) << "YEAR" << setw(10) << "Quarter 1"
		 << setw(10) << "Quarter 2" << setw(10) << "Quarter 3"
		 << setw(10) << "Quarter 4" << endl;
}

//*****************************************************************************
//	getSales
//
//	task:	  This procedure asks the user to input the number of years.
//	          For each of those years it asks the user to input the year
//	          (e.g. 2004), followed by the sales figures for each of the
//	          4 quarters of that year. That data is placed in a 2D array
//	data in:  a 2D array of integers
//	data out: the total number of years
//
//*****************************************************************************

void getSales(SalesType	table, int&	numOfYears)
{
	cout << "Please input the number of years (1-" << MAXYEAR << ")" << endl;
	cin >> numOfYears;

	// Fill in the code to read and store the next value
    for (int yearCount = 0; yearCount < numOfYears; yearCount++ ) {
        cout << "What is the year: ";
        cin >> table[yearCount][0];
        for (int yearQuarter = 1; yearQuarter <= 4; yearQuarter++) {
            cout << "what were the sales for quarter " << yearQuarter << ": ";
            cin >> table[yearCount][yearQuarter];
        }
        cout << endl;
    }
}

//*****************************************************************************
//	printSales
//
//	task:	  This procedure prints out the information in the array
//	data in:  an array containing sales information
//	data out: none
//
//*****************************************************************************

void printSales(SalesType table, int numOfYears)
{
	// Fill in the code to print the table
    for (int yearCount = 0; yearCount < numOfYears; yearCount++) {
        cout << setw(10) << table[yearCount][0];
        for (int yearQuarter = 1; yearQuarter <= 4; yearQuarter++) {
            cout << setw(10) << table[yearCount][yearQuarter];
        }
        cout << endl;
    }
}