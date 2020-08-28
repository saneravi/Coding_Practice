#include <iostream>
using namespace std;

int main()
{   
    char m_str[1000], substr[20];
    
    cout << "Enter main string :" << endl;//get main string
    cin.getline(m_str, 1000);
    
    cout << endl;
  
    cout << "Enter sub-string :" << endl;//get sub string
    cin.getline(substr, 20);
    
    int flag, k;  
    for(int i = 0; m_str[i] != '\0'; ++i) 
        if(m_str[i] == substr[0])           //find the first matching char
        {   
            flag = 1;
            k = 0;
            while(substr[k] != '\0')        // find rest of the matching char
            {
                if(m_str[i+k] != substr[k]) //break if unmatched
                {   flag = 0;    
                    break;
                }
                k++;
            }
            if(flag)        //flag = 1 when matched
            {   
                cout << "Position = " << i << endl;     // print the position of match
                break;
            }
        }
    
    if(!flag)                           // print this when sub string is absent
        cout << endl << "Not Found";
    
    
    cout << endl << endl; 
    return 0;
}


              
