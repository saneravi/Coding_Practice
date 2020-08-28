#include <iostream>
#include <math.h>
#include <ctype.h>
using namespace std;
int main()
{   
    char ch;
    int lower = 0;
    
    //program to count number of lower characters entered
    
    cin.get(ch);
    
    while(ch != '\n')
    {
        if(islower(ch))
            lower++;
        cin.get(ch);
    }
    
    cout<<lower;                    
    return 0;
}    
    
