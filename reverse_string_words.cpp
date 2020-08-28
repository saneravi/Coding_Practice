#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char ch[100], word[100];
    cout << "Enter a string : ";
    cin.getline(ch, 100);
    strcat(ch, " ");
    int l = strlen(ch), k = 0;
    for(int i = 0; i < l; ++i)
    {
        if(ch[i] != ' ')
        {
            word[k] = ch[i];
            k++;
        }
        else
        {
            while(k > 0)
            {
                k--;
                cout.put(word[k]);

            }
            cout.put(ch[i]);
        }
    }
       
        
        
    return 0;
}


              
