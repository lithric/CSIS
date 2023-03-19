/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment02pe04: Reading from a File                              */
/*                                                                            */
/* Approximate completion time: 15 minutes                                     */
/******************************************************************************/

/*
   This program opens the file named testdata4, reads the
single value stored in it and prints the value back onto the screen. */

#include <iostream>
#include <fstream>
    
using namespace std;

int main() {
    int fileInt;
    ifstream file;
    
    file.open("testdata4");
    if (!file) {
        cout << "unable to open file testdata4" << endl;
        file.close();
    }
    else {
        file >> fileInt;
        cout << "The integer read is: " << fileInt << endl;
        file.close();
    }
    
    return 0;
}