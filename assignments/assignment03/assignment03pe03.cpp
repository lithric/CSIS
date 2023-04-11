/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment03pe03: Reverse                                          */
/*                                                                            */
/* Approximate completion time: 2 minutes                                     */
/******************************************************************************/

/*
   This program reads in 10 numbers and prints them in reverse order
*/

#include <iostream>

using namespace std;

int main() {
    int numbers[10];

    cout << "Input ten integers, and I will print them out in reverse order" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }
    cout << endl;
    cout << "In reverse order, the numbers you entered are: ";
    for (int i = 9; i >= 0; i--) {
        cout << numbers[i] << " ";
    }

    return 0;
}