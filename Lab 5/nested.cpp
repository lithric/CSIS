// This program finds the average time spent programming by a student
// each day over a three day period.

// Elion Oliver

#include <iostream>
using namespace std;

#define prompt_int(val,msg) cout << msg; cin >> val; cin.ignore(10000,'\n')

int main()
{
	int numStudents;
    int numDays;
	float numHours, numHoursBiology, numHoursProgramming, total, 
    average, averageBiology, averageProgramming, totalBiology, totalProgramming;
	int student, day = 0;	// these are the counters for the loops

	cout << "This program will find the average number of hours a day"
		 << " that a student spent programming over a long weekend\n\n";
	prompt_int(numStudents,"How many students are there ?\n\n");
    prompt_int(numDays,"How many days are there ?\n\n");

	for (student = 1; student <= numStudents; student++)
	{
		total = 0;

		for (day = 1; day <= numDays; day++)
		{
            prompt_int(numHoursBiology,"Please enter the number of hours worked in biology by student "
				 << student << " on day " << day << "." << endl);
            prompt_int(numHoursProgramming,"Please enter the number of hours worked in programming by studuent" << student << " on day " << day << "." << endl);
            numHours += numHoursBiology + numHoursProgramming;
            totalBiology += numHoursBiology;
            totalProgramming += numHoursProgramming;
			total = total + numHours;
		}

		average = total / numDays;
        averageBiology = totalBiology / numDays;
        averageProgramming = totalProgramming / numDays;

		cout << endl;
        cout << "The average number of hours per day spent in total by "
			 << "student " << student << " is " << average
			 << endl << endl;
        if (averageBiology > averageProgramming) {
            cout << "The student spent the most time in biology on average" << endl;
            cout << "The average number of hours per day spent in biology by "
			 << "student " << student << " is " << averageBiology
			 << endl << endl << endl;
        }
        else {
            cout << "The student spent the most time in programming on average" << endl;
            cout << "The average number of hours per day spent programming by "
			 << "student " << student << " is " << averageProgramming
			 << endl << endl << endl;
        }
	}

	return 0;
}