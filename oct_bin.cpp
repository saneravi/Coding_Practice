#include <iostream>
using namespace std;
void oct_bin(int);

int main()
{   
    int n;
    cout<< "Enter the value of octal number: ";
    cin>> n;
    oct_bin(n);
    return 0;
}

void oct_bin(int x)
    {
        int a[6] = {0};
        int ones = x % 10;
        int tens = x / 10;
        
        for( int i = 2; i >= 0; --i)
        {
            a[i+3] = ones % 2;    // to convert ones to binary
            ones /= 2;
            a[i] = tens % 2;      // to convert tens to binary
            tens /= 2;
        }
        
        for( int i = 0; i < 6; ++i) // combine above two to get octal number
            cout<< a[i];

    }
              
