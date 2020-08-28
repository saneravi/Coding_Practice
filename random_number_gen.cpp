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
    int x[10], l = (sizeof(x)/sizeof(*x));  // l stores the length of the array
    my_random(x, l, 5, 20);                 // function is called to generate random numbers
    for( int i = 0; i < l; ++i)             // loop to print generated random numbers
        cout << x[i] << endl;
    
    return 0;
}

              
