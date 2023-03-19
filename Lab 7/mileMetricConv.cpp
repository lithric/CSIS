#include <iostream>
    
using namespace std;
    
// Elion Oliver
    
#define until(a) while(!(a))
    
const float MILE_RATE = 0.621;
const float KILOMETER_RATE = 1.61;
    
void convertMilesToKilometersBranch();
void convertKilometersToMilesBranch();
float convertMilesToKilometers(float);
float convertKilometersToMiles(float);

int main() {
    int user_choice;
    
    do {
        cout << "Please Input" << endl;
        cout << "1 Convert miles to kilometers" << endl;
        cout << "2 Convert kilometers to miles" << endl;
        cout << "3 Quit" << endl;
        cin >> user_choice;
        cout << endl;
        if (user_choice == 1) {
            convertMilesToKilometersBranch();
        }
        else if (user_choice == 2) {
            convertKilometersToMilesBranch();
        }
    } until(user_choice == 3);
    
    return 0;
}

void convertMilesToKilometersBranch() {
    float miles;
    float kilometers;
    cout << "Please input the miles to be converted" << endl;
    cin >> miles;
    kilometers = convertMilesToKilometers(miles);
    cout << miles << " miles = " << kilometers << " kilometers";
    cout << endl << endl;
}

void convertKilometersToMilesBranch() {
    float miles;
    float kilometers;
    cout << "Please input the kilometers to be converted" << endl;
    cin >> kilometers;
    miles = convertKilometersToMiles(kilometers);
    cout << kilometers << " kilometers = " << miles << " miles";
    cout << endl << endl;
}

float convertMilesToKilometers(float miles) {
    return miles * KILOMETER_RATE;
}

float convertKilometersToMiles(float kilometers) {
    return kilometers * MILE_RATE;
}