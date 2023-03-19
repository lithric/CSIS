// This program prints "You Pass" if a student's average is
// 60 or higher and prints "You Fail" otherwise

// Elion Oliver

#include <iostream>
using namespace std;

void say(string s) {
    cout << s << endl;
}

int main()
{
	float average;	// holds the grade average

	say("Input your average:");
	cin >> average;
    
    if (average > 100) say("invalid data");
    else if (average == 100) say("Perfect Grade! Here's An A+!");
    else if (average >= 90) say("Great Job! You Get An A!");
    else if (average >= 80) say("Not Bad, But You Can \"B\" Better!");
    else if (average >= 60) say("You Pass");
    else if (average >= 0) say("You Fail");
    else say("invalid data");

	return 0;
}