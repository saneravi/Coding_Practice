#include <iostream>
using namespace std;
#include <string.h>

int main()
{   
    char a[1000];
    
    cout << "Enter main string :" << endl;      // get the string from user
    cin.getline(a, 1000);
    
    retry:
    cout << "Enter the starting position of sub-string: "; //get the starting position of string to be deleted
    int st = 0;
    cin >> st;
    if(st < 0 or st >= strlen(a))                          // to check the start pos in range or not
    {   
        cout << "Please enter correct position!\n";
        goto retry;;
    }
    
    cout << "Enter the length of sub-string: ";             // get length of sub string to be deleted
    int l = 0;
    cin >> l;
    
    if(l > strlen(a) - st - 1)                              // take into consideration when starting position is near end
        l = strlen(a) - st - 1;                             // and still you wanna delete the remaining text 
                                                            // which has length less than the user entered value
    int i, n;
    for(i = st + l, n = st; a[i] != '\0'; ++i, ++n)         // shift the string elements right to delete sub string
        a[n] = a[i];
    a[n-1] = '\0';                                          // to terminate the new string
    
    cout << endl;
    cout.write(a, n);                                       // display the output
    
 
    
    cout << endl << endl; 
    return 0;
}


              
