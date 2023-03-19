/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment02pe05: Reading from a File and Writing to another File  */
/*                                                                            */
/* Approximate completion time: 15 minutes                                    */
/******************************************************************************/

/*
   This program reads all the integers from testdata5 using a whileloop, calculates the sum of these integers and saves the sum to an output file with the name specified by the user. */

#include <iostream>
#include <fstream>
#include <string>
    
using namespace std;

#define until(expr) while(!(expr))

int main() {
    int fileNumber;
    int sum = 0;
    string fileOutName;
    ifstream fileIn;
    ofstream fileOut;
    
    cout << endl;
    fileIn.open("testdata5");
    if (!fileIn) {
        cout << "input file (testdata5) unable to open" << endl;
        fileIn.close();
    }
    else {
        cout << "This program reads integers from a file," << endl
             << "calculates their sum, and saves the sum " << endl
             << "in another file." << endl
             << endl
             << "The integers read are:";
        until(fileIn.eof()) {
            fileIn >> fileNumber;
            sum += fileNumber;
            cout << " " << fileNumber;
        }
        cout << endl;
        fileIn.close();
        cout << "Their sum is " << sum << endl
             << endl
             << "Enter a filename to write the sum to: ";
        getline(cin,fileOutName);
        cout << endl;
        fileOut.open(fileOutName);
        if (!fileOut) {
            cout << "output file unable to open" << endl;
            fileOut.close();
        }
        else {
            fileOut << sum << endl;
            cout << "The sum " << sum << " was saved successfuly to file " << fileOutName << "." << endl;
            fileOut.close();
        }
        fileIn.close();
    }
    cout << endl;
    
    return 0;
}