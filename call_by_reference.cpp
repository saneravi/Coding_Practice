#include <iostream>
#include <stdio.h>
using namespace std;
void conv(float &);
void conv1(float &);

int main()
{   
    float a;
    
    cout<< "Enter the value: ";
    cin >> a;
    
    lab:
    cout<< "What do you want to do ? press '1' to convert to feet/press '2' to convert to inches: \n";
    char i;
    cin >> i;
    
    if( i == '1')
    {   
        conv(a);
        cout << a << " feet " << endl;
    }
    else if( i == '2')
    {
        conv1(a);
        cout << a << " inches " << endl;
    }
    
    char ch;
    cout<< "press any key to continue : \n";
    cin.get(ch);    
    if(ch != '\n')
    {
    goto lab;
    ;
    }
    
    return 0;
}    
    
void conv(float &x)
{
    x = x/12; // inches to feet
        
}    

void conv1(float &x)
{
    x = x*12; // feet to inches
        
}
       
