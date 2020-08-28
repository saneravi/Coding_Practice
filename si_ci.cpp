#include <iostream>
#include <math.h>
using namespace std;

int main()
{
float p, r, t;
cout<<"\n Enter principal : Rs ";
cin>>p;
cout<<"\n Enter rate in \%: ";
cin>>r;
cout<<"\n Enter time in years : ";
cin>>t;

float si = p*r*t/100;
float ci = p*pow((1 + (r/100)), t) - p;

cout<<"\n"<<si<<"\n"<<ci<<"\n";

return 0;
}


