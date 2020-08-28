#include <iostream>
#include <stdio.h>
using namespace std;

int pos(char a[], char ch)
    {
    int flag = 0;
    for( int i = 0; a[i] != '\0'; ++i)
        if (a[i] == ch)
            {
            cout << i << endl;
            flag = 1;
            }
    return flag;
    }
        
int main()
{   
    char my_array[] = "signal energy in part a; normalized error in part b for p=14 pole analysis using 20 msec frame size for covariance method; normalized error in part c for autocorrelation method using HW; normalized error in part d for autocorrelation method using.";
    char find_this = 'q';    
    int f = pos(my_array, find_this);
    
    if(!f)
        cout << "Sorry Not found";
           
    return 0;
}
