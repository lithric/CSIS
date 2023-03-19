/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment01pe03: The cin Object                                   */
/*                                                                            */
/* Approximate completion time: 2 minutes                                     */
/******************************************************************************/

/*
   This program prints what the user inputs to the screen */

#include <iostream>
#include <string>
    
using namespace std;
    
int main() {
    string text; // text from the user
    
    // get text from the user
    cin >> text;
    // display text
    cout << text << endl;
    
    return 0;
}