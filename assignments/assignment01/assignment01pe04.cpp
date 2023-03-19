/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment01pe04: Sum of Two Values                                */
/*                                                                            */
/* Approximate completion time: 3 minutes                                     */
/******************************************************************************/

/*
   This program prints the sum of two user inputed numbers. */

#include <iostream>
    
using namespace std;
    
int main() {
    int c1; // the first number
    int c2; // the second number
    int sum; // the sum of the two numbers
    
    // prompt the user for two integers separated by a space
    cout << "Input two integers separated by a single space" << endl;
    // get user input
    cin >> c1 >> c2;
    // add the numbers the user submitted together
    sum = c1 + c2;
    // display the sum
    cout << "The sum of these two numbers is: " << sum << endl;
    
    return 0;
}