#include <iostream>
#include <cmath>
    
 using namespace std;
    
#define until(a) while(!(a))
    
const float g = 9.8;
    
int main() {
    float distanceFallen = 0;
    int time = 0;
    int timeOfFall;
    cout << "Please Input the time of fall in seconds:" << endl;
    cin >> timeOfFall;
    int height;
    cout << "Please Input the height of the bridge in meters:" << endl; 
    cin >> height;
    cout << endl;
    cout << "Time Falling (seconds) Distance Fallen (meters)" << endl;
    cout << "*******************************************" << endl;
    until (time > timeOfFall) {
        cout << time << "                      ";
        cout << distanceFallen;
        cout << endl;
        time += 1;
        distanceFallen = g*time*time*0.5;
    }
    if (distanceFallen > height) {
        cout << endl;
        cout << "Warning-Bad Data: The distance fallen exceeds the height of the bridge" << endl;
    }
    cout << endl;
    return 0;
}