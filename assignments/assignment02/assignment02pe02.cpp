/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment02pe02: Persistence of a Number                          */
/*                                                                            */
/* Approximate completion time: 50 minutes                                    */
/******************************************************************************/

/*
   This program prints the persistence of a given number by the user until a sentinel value is given */

#include <iostream>
    
using namespace std;

#define until(expr) while(!(expr))
    
int calculatePersistence(int);
int getProductOfDigits(int);
int getOnesDigit(int);
int removeOnesDigit(int);

const int SENTINAL_STOP = -1;
    
int main() {
    int inputNumber, persistence;
    
    do {
        cout << "Enter a number to calculate its persistence (" << SENTINAL_STOP << " to stop): ";
        cin >> inputNumber;
        if (inputNumber != SENTINAL_STOP) {
            persistence = calculatePersistence(inputNumber);
            cout << endl
                 << "Persistence(" << inputNumber << ") = " << persistence << endl
                 << endl;
        }
    } until(inputNumber == SENTINAL_STOP);
    
    return 0;
}

int calculatePersistence(int number) {
    int persistence = 0;
    int runningNumber = number;
    until(runningNumber < 10) {
        runningNumber = getProductOfDigits(runningNumber);
        persistence++;
    }
    return persistence;
}

int getProductOfDigits(int number) {
    int runningProduct = 1;
    int runningNumber = number;
    until(runningNumber == 0 || runningProduct == 0) {
        runningProduct *= getOnesDigit(runningNumber);
        runningNumber = removeOnesDigit(runningNumber);
    }
    return runningProduct;
}

int getOnesDigit(int number) {
    return number % 10;
}

int removeOnesDigit(int number) {
    return number / 10;
}