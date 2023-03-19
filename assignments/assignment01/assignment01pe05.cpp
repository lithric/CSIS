/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment01pe05: Average of Four Integers                         */
/*                                                                            */
/* Approximate completion time: 5 minutes                                     */
/******************************************************************************/

/*
   This program prints the average of 4 user inputed numbers. */

#include <iostream>
#include <iomanip>
    
using namespace std;
    
int main() {
    int c1; // the first number
    int c2; // the second number
    int c3; // the third number
    int c4; // the fourth number
    float average; // the average of the numbers
    
    // prettify floating-point number output
    cout << setprecision(2) << fixed << showpoint;
    // prompt user for four integers separated by a space
    cout << "Input four integers all separated by a single space" << endl;
    // get user input
    cin >> c1 >> c2 >> c3 >> c4;
    // compute average
    average = (float)(c1 + c2 + c3 + c4)/4; // type cast with "(float)"
    // display average
    cout << "The average of these 4 numbers is: " << average << endl;
    
    return 0;
}