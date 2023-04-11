/******************************************************************************/
/* Programmer: Elion Oliver                                                   */
/*                                                                            */
/* Program assignment03pe05: Inner Product of Two Arrays                      */
/*                                                                            */
/* Approximate completion time: 5 minutes                                     */
/******************************************************************************/

/*
   This program calculates the inner product of two arrays
*/

#include <iostream>

using namespace std;

float inner(float[],float[],int);

int main() {
    float arr_u[4];
    float arr_v[4];

    for (int i = 0; i < 4; i++) {
        cout << "Enter in number " << i << " (u array): ";
        cin >> arr_u[i];
        cout << endl;
    }
    for (int i = 0; i < 4; i++) {
        cout << "Enter in number " << i << " (v array): ";
        cin >> arr_v[i];
        cout << endl;
    }
    cout << "The inner product of arrays u and v is " << inner(arr_u,arr_v,4) << endl;

    return 0;
}
/******************************************************************************/
/* Function: inner                                                            */
/*                                                                            */
/* Description: calculates the inner product of two arrays                    */
/*                                                                            */
/* Data in: two arrays of 4 integers                                          */
/*                                                                            */
/* Data out: the inner product of those arrays                                */
/******************************************************************************/
float inner(float arr_u[],float arr_v[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr_u[i] * arr_v[i];
    }
    return total;
}