#include <iostream>
#include <math.h>
using namespace std;
int main()
{   
    int num;
    cin >> num;
    int flag = 1;
    for(int i = sqrt(num); i>= 2; --i)
        if (num%i == 0)
            {
            cout << "Not a prime";
            flag = 0;
            break;
            }
    if(flag)
    {
    cout<< "Prime number";
    }
                        
    return 0;
}    
    
