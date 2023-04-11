/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment03pe04: Passing a Two-Dimensional Array                  */
/*                                                                            */
/* Approximate completion time: 5 minutes                                     */
/******************************************************************************/

/*
   This program prints the sum of a two dimensional array filled in by the user
*/

#include <iostream>

using namespace std;

int sum(int[3][4]);

int main() {
    int numbers[3][4];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "Enter a number to be stored in array[" << i << "][" << j << "]: ";
            cin >> numbers[i][j];
            cout << endl;
        }
    }
    cout << "The sum is: " << sum(numbers) << endl;

    return 0;
}

/******************************************************************************/
/* Function: sum                                                              */
/*                                                                            */
/* Description: sums up all the integers in a two-dimensional array           */
/*                                                                            */
/* Data in: two-dimensional array of integers                                 */
/*                                                                            */
/* Data out: the sum of all the integers in the array                         */
/******************************************************************************/
int sum(int arr[3][4]) {
    int total = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            total += arr[i][j];  
        }
    }
    return total;
}