#include <iostream>
#include <math.h>
using namespace std;
int main()
{   
    int num;
    cin >> num;
    int temp = num;
    int new_num = 0;
    while(temp)
        {
        new_num = (new_num*10) + (temp % 10);
        temp /= 10;        
        }
    if (new_num == num)
        cout<< "Palindrome";
    else
        cout<< "Sorry";
        
    return 0;
}    
    
