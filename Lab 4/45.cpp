// This program illustrates the use of the switch statement.

// PLACE YOUR NAME HERE

#include <iostream>
using namespace std;

const int IN_STATE_TUITION = 3000;
const int OUT_OF_STATE_TUITION = 4500;
const int ROOM_AND_BOARD_IN_STATE_COST = 2500;
const int ROOM_AND_BOARD_OUT_OF_STATE_COST = 3500;

int main()
{
	char grade;
    char userState;
    bool inState;
    char userReq;
    bool roomReq;
    int tuition = 0;

	cout << "Please input \"I\" if you are in-state or \"O\" if you are out-of-state:" << endl;
    cin >> userState;
    if (userState == 'I') {
        inState = true;
    }
    else if (userState == 'O') {
        inState = false;
    }
    else {
        cout << "invalid input" << endl;
        return 0;
    }
    cout << "Please input \"Y\" if you require room and board and \"N\" if you do not:" << endl;
    cin >> userReq;
    if (userReq == 'Y') {
        roomReq = true;
    }
    else if (userReq == 'N') {
        roomReq = false;
    }
    else {
        cout << "invalid input" << endl;
        return 0;
    }
    
    if (inState) {
        tuition += IN_STATE_TUITION;
        if (roomReq) {
            tuition += ROOM_AND_BOARD_IN_STATE_COST;
        }
    }
    else {
        tuition += OUT_OF_STATE_TUITION;
        if (roomReq) {
            tuition += ROOM_AND_BOARD_OUT_OF_STATE_COST;
        }
    }
    
    cout << "Your total bill for this semester is $" << tuition << endl;

	return 0;
}