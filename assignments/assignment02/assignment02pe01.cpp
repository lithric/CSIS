/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment02pe01: Unfilled Box                                     */
/*                                                                            */
/* Approximate completion time: 60 minutes                                    */
/******************************************************************************/

/*
   This program prints a box of ascii asterisks with a user specified size of up to 20 characters and down to 1 character in both length and width */

#include <iostream>
    
using namespace std;

#define until(expr) while(!(expr))

bool isValidInput(int,int);
void drawBox(int,int);
void drawBoxLid(int,int);
void drawMiddleBox(int,int);

const int MIN_SIZE = 1;
const int MAX_SIZE = 20;
    
int main() {
    int l, h;
    
    do {
        cout << "Enter in a length (must be less than " << MAX_SIZE+1 << "): ";
        cin >> l;
        cout << "Enter in a height (must be less than " << MAX_SIZE+1 << "): ";
        cin >> h;
        if (!isValidInput(l,h)) {
            cout << "Invalid input. Your values should be positive less than " << MAX_SIZE+1 << ".\nTry again!\n";
        }
    } until(isValidInput(l,h));
    drawBox(l,h);
    
    return 0;
}

bool isValidInput(int l, int h) {
    return l >= MIN_SIZE && l <= MAX_SIZE && h >= MIN_SIZE && h <= MAX_SIZE;
}

void drawBox(int l,int h) {
    drawBoxLid(l,h);
    h--;
    while(h > 1) {
        drawMiddleBox(l,h);
        h--;
    }
    drawBoxLid(l,h);
}

void drawBoxLid(int l, int h) {
    if (l <= 0) return;
    if (h <= 0) return;
    for (int step = 0; step < l - 1; step++) {
        cout << "*";
    }
    cout << "*\n";
}

void drawMiddleBox(int l, int h) {
    if (l <= 0) return;
    if (h <= 0) return;
    for (int step = 0; step < l - 1; step++) {
        cout << (step == 0 ? "*" : " ");
    }
    cout << "*\n";
}