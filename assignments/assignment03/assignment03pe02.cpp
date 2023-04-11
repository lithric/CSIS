/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment03pe02: Call by Reference                                */
/*                                                                            */
/* Approximate completion time: 2 minutes                                     */
/******************************************************************************/

/*
   This program swaps two user inputted values and prints them to the screen
*/

#include <iostream>

using namespace std;

void swap(int &, int &);

int main() {
    int x;
    int y;
    cout << "Please enter the first value, x: ";
    cin >> x;
    cout << endl;
    cout << "Please enter the second value, y: ";
    cin >> y;
    cout << endl;
    cout << "After the swap, x is equal to " << x << " and y is equal to " << y << endl;
    return 0;
}

/******************************************************************************/
/* Function: swap                                                             */
/*                                                                            */
/* Description: swaps the values of two integer variables passed by reference */
/*                                                                            */
/* Data in: two integers passed by reference                                  */
/*                                                                            */
/* Data out: none                                                             */
/******************************************************************************/
void swap(int &x,int &y) {
    int temp = x;
    x = y;
    y = temp;
}