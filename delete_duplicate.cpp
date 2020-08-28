#include <iostream>
using namespace std;
#include <string.h>

int main()
{   
    char a[1000];
    
    cout << "Enter main string :" << endl;      // get the string from user
    cin.getline(a, 1000);
    
    cout << endl;
    
    for(int i = 0; a[i] != '\0'; ++i)           // loop to get one letter at a time
    {
        for(int j = (i+1); a[j] != '\0'; ++j)   // loop to check from next letter onwards whether there is repetition
        {
            if(a[i] == a[j])                    // if there is repetition, delete the duplicate letter from the string
            {                                   // by shifting all letters to the left
                for(int k = j; a[k] != '\0'; ++k)
                    a[k] = a[k+1];
             }
         }
     }
     
     cout << endl;
     cout.write(a, strlen(a));                  // print the output for user
     cout << endl << strlen(a);                 // show different characters used in the given main string
                                                // NOTE: uppercase and lowercase are considered as separate chars
    
    
    
    cout << endl << endl; 
    return 0;
}


              
