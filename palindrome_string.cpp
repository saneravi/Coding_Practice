#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ch[50];
    cout << "Enter a string : ";
    cin.getline(ch, 50);
    int l = strlen(ch);
    int flag = 1;
    for(int i = 0; i <= l/2; ++i)
    {
        if(ch[i] != ch[l-i-1])
        {
            cout << "Not a Palindrome" << endl << endl;
            flag = 0;
            break;            
        }
    }
    if (flag)
        cout << "It is a Palindrome" << endl << endl;
    return 0;
}


              
