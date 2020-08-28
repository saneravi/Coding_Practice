#include <iostream>
#include <math.h>
using namespace std;
int main()
{   
    int num, f, s, out;
    f = 0;
    s = 1;
    cin >> num;
    cout<< f <<" "<< s <<" ";
    for(int i = 2; i < num; i++)
    {
        out = f + s;
        f = s;
        s = out;
        cout << out <<" ";        
    }
                        
    return 0;
}    
    
