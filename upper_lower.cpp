#include <iostream>
using namespace std;

int main()
{
char ch;
cout<<"\nEnter a charater: ";
cin>>ch;
int i = ch;
if (i<= 122 and i>= 97)
	cout<<"\nThe upper case character of "<<ch<<" is "<<(char)(ch-32)<<"\n";
else if (i<= 90 and i>= 65)
	cout<<"\nThe lower case character of "<<ch<<" is "<<(char)(ch+32)<<"\n";
else
	cout<<"\n"<<ch<<" is not a letter\n\n";
return 0;
}
