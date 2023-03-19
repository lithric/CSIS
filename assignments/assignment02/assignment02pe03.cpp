/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment02pe03: Water Bill                                       */
/*                                                                            */
/* Approximate completion time: 25 minutes                                     */
/******************************************************************************/

/*
   This program calculates and gives a response on the average water bill of the user based upon the water bill for each quarter inputed by the user. */

#include <iostream>
#include <iomanip>
    
using namespace std;

int main() {
    float bill, average;
    
    cout << fixed << setprecision(2) << showpoint;
    for (int yearQuarter = 1; yearQuarter <= 4; yearQuarter++) {
        cout << "Input your water bill for quarter " << yearQuarter << ": ";
        cin >> bill;
        average += bill / 12;
    }
    cout << "Your average monthly bill is $" << average << endl;
    if (average < 25) {
        cout << "Thank you for conserving water!" << endl;
    }
    else if (average > 75) {
        cout << "You are using too much water!" << endl;
    }
    else {
        cout << "You are using a typical amount of water!" << endl;
    }
    
    return 0;
}