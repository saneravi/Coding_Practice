#include <bits/stdc++.h>
using namespace std;

int main()
{   
    queue <int> a, b;
    clock_t t1, t2;    
    t1 = clock();
    
    for(int i = 1; i < 15; ++i)
        a.push(i);
    
    int num, flag;
    cout << "Enter a number to be inserted: ";
    cin >> num;
    cout << endl;
    
    while(!a.empty())
    {   
        if(num > a.front()){
            b.push(a.front());     
            a.pop();
            }
        else{
            b.push(num);
            flag = 1;
            break;
            }        
    }
    
    if(!flag)
        b.push(num);
    else
    {
        while(!a.empty())
        {
        b.push(a.front());     
        a.pop();
        }
    }
    while(!b.empty())
    {
        cout << b.front() << " ";
        b.pop();
    }
    
    t2 = clock();    
    
    cout << (float)((float)t2 - (float)t1)/CLOCKS_PER_SEC;
    return 0;
    }
   
