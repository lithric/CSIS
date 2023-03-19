/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment01pe07: Take a Guess!                                    */
/*                                                                            */
/* Approximate completion time: 6 minutes                                     */
/******************************************************************************/

/*
   This program asks the user to think of a number between 1 and 6
   and then displays a random number between 1 and 6 when the user
   presses <Enter>. */

#include <iostream>
#include <ctime>
    
using namespace std;
    
int main() {
    int randomNumber; // the randomly generated number
    
    // reseed the random number generator using the current time as the seed
    srand(time(0));
    // prompt user to THINK of a number between 1 and 6
    cout << "Think of a number between 1 and 6 and then press <Enter>" << endl;
    // wait for user to press return and ignore input
    cin.ignore();
    // compute random number
    randomNumber = (rand() % 6) + 1;
    // display random number
    cout << randomNumber << endl;
    
    return 0;
}