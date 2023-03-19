// Elion Oliver

#include <iostream>
using namespace std;

int main()
{
    char letter = '';
    
    do {
        cout << "Please enter a letter (enter the letter 'x' to exit)" << endl;
        cin >> letter;
        
        cout << "The letter you entered is " << letter << endl;
    } while (letter != 'x');
    
	return 0;
}