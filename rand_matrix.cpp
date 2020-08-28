#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>

/* This function is used to generate n number of random integers in range of [low, high), 
function is call by reference type */
void my_random(int *a, int n, int low, int high)
    {
    time_t t;                           // time type: alias of a fundamental arithmetic type capable of represnting time
    srand((int)time (&t));              // seed time as random number generator to get different numbers each time
    for( int i = 0; i < n; ++i)
        a[i] = (rand()%(high - low)) + low; // loop to generate random numbers
    }



int main()
{   
    int size = 6, k = 0;
    int m[size][size];
    
    int temp[size * size];
    my_random(temp, size*size, 5, 20);
    
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j, ++k) 
            m[i][j] = temp[k];
    
    for(int i = 0; i < size; ++i)
        {
        for(int j = 0; j < size; ++j) 
            cout << m[i][j] << "\t";
        cout << endl;
        }
    
    cout << endl << endl;
    
    
     
    return 0;
}


              
