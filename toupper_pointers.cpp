#include <iostream>
using namespace std;
#include <ctype.h>
#include <string.h>


int main()
{
    char s[100];
    
    cout << "Enter string: ";
    
    cin.getline(s, 100);
    
    for(char *ptr = s; ptr < &s[strlen(s)]; ptr++)
        cout << (char)(toupper(*ptr));
        
    return 0;
    
}
