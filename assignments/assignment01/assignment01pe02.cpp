/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment01pe02: Hourglass Pattern                                */
/*                                                                            */
/* Approximate completion time: 3 minutes                                     */
/******************************************************************************/

/*
   This program prints an hourglass to the screen */

#include <iostream>
    
using namespace std;
    
int main() {
    // print the hourglass using multiple cout statements
    cout << "**********" << endl;
    cout << " ******** " << endl;
    cout << "  ******  " << endl;
    cout << "   ****   " << endl;
    cout << "    **    " << endl;
    cout << "   ****   " << endl;
    cout << "  ******  " << endl;
    cout << " ******** " << endl;
    cout << "**********" << endl;
    // print the houglass using a single cout statement (commented out)
    /*
    cout << "**********" << endl
         << " ******** " << endl
         << "  ******  " << endl
         << "   ****   " << endl
         << "    **    " << endl
         << "   ****   " << endl
         << "  ******  " << endl
         << " ******** " << endl
         << "**********" << endl;
    */
    
    return 0;
}