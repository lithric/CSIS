// This program prints the proverb
// "Now is the time for all good men to come to the aid of their party"
// in a function (procedure) called writeProverb that is called by the main function

// Elion Oliver

#include <iostream>
#include <iomanip>
using namespace std;

float getSpeed(float,float);	// This is the prototype for the writeProverb function 

int main()
{
    float miles;
    float hours;
    
	cout << setprecision(2) << fixed << showpoint;
    cout << "Please input the miles traveled" << endl;
    cin >> miles;
    cout << "Please input the hours traveled" << endl;
    cin >> hours;
    cout << "Your speed is " << getSpeed(miles,hours) << " miles per hour" << endl;
	return 0;
}

//*********************************************************************
//	writeProverb
//
//	task:	  This function prints a proverb
//	data in:  none
//	data out: no actual parameter altered
//
//********************************************************************

// Fill in the function heading and the body of the function that will print
// to the screen the proverb listed in the comments at the beginning of the
// program
float getSpeed(float miles, float hours) {
    return miles/hours;
}