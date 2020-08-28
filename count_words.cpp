#include <iostream>
using namespace std;

int main()
{   
    char ch, temp;
    int word = 0;
    
    //program to count number of words entered by user    
    cin.get(ch);
    
    while(ch != '\n')
    {   
        if(ch == ' ' && temp != ' ') // to avoid considering two or more spaces as separate words
            word++;
        temp = ch;
        cin.get(ch);
        
    }
    
    cout<<word+1;                    // no of words are 1 more than the number of spaces
    return 0;
}    
    
