#include <iostream>
#include <math.h>
using namespace std;

int main()
{
float a, b, c, delta, root1, root2;
cout<<"Enter the coefficients of ax2 + bx + c = 0 :\n";
cin>>a>>b>>c;
if(!a)
    cout<<"Coefficient a is zero, error!!!\n\n";
else
    {
    delta = b*b - (4*a*c);
    
    if(delta < 0)
        {
        cout<<"\nComplex Roots:\n";
        cout<<(-b/(2*a))<<" + i"<<(sqrt(-delta)/(2*a))<<"\n";
        cout<<(-b/(2*a))<<" - i"<<(sqrt(-delta)/(2*a))<<"\n\n";        
        }
    else
        {
        root1 = (-b + sqrt(delta))/(2*a);
        root2 = (-b - sqrt(delta))/(2*a);        
        cout<<"\nReal Roots:\n"<<root1<<"\n"<<root2<<"\n\n";
        }
    }
return 0;
}
