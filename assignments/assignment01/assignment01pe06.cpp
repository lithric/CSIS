/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment01pe06: Using the sqrt Function                          */
/*                                                                            */
/* Approximate completion time: 5 minutes                                     */
/******************************************************************************/

/*
   This program prints the square root of a user inputed number. */

#include <iostream>
#include <cmath>
#include <iomanip>
    
using namespace std;
    
int main() {
    double c1; // the number
    double sq; // the square root of that number
    
    // prettify floating-point number output
    cout << setprecision(2) << fixed << showpoint;
    // prompt user for a floating point number
    cout << "Enter a floating-point number" << endl;
    // get user input
    cin >> c1;
    // compute square root
    sq = sqrt(c1); // using "sqrt(double)" to compute the square root
    // display square root
    cout << "The square root of that number is: " << sq << endl;
    
    return 0;
}