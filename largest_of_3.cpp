#include <iostream>
using namespace std;

int main()
{
int n1, n2, n3;
cout<<"\nEnter 3 numbers: ";
cin>>n1>>n2>>n3;

int max = n1>n2?(n1>n3?n1:n3):(n2>n3?n2:n3);
cout<<"\nMax = "<<max<<"\n\n";

return 0;
}
