#include <bits/stdc++.h>
using namespace std;

void seed_random(void)
{
    time_t t;
    int t_val = time(&t);
    srand(t_val);    
}

int main()
{      
    seed_random();    
    auto begin = chrono::high_resolution_clock::now();    
    // code starts here   
    
    vector <pair <int, char> > v;    
    
    for(int i=0;i<100;++i)
    {
        pair <int, char> p;
        p.first = rand()%100; p.second = (char)(rand()%26 + 65);
        v.push_back(p);
    }
    
    for(auto j=v.begin(); j!=v.end(); ++j)
        cout<<j->first<<"\t"<<j->second<<"\n";
           
    
    // code ends here   
    auto end = chrono::high_resolution_clock::now();
    cout <<endl<<"Runtime: " << (float)(chrono::duration_cast <chrono::nanoseconds> (end-begin).count())/1000 << "us" << endl;
    
    return 0;
    }
   