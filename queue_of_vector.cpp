//queue of vectors
#include<bits/stdc++.h> 
using namespace std; 
void solve(); 
void seed_rand();
int main() 
{ 
   ios_base::sync_with_stdio(false);cin.tie(NULL); 
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin); 
   freopen("error.txt", "w", stderr); 
   freopen("output.txt", "w", stdout); 
   #endif 
   
   int t=1; 
   cin>>t; 
   while(t--) 
   { 
      solve(); 
      cout<<"\n"; 
   } 
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
} 

void solve() 
{ 
	queue <vector <char> > a;
   for(int i=10; i<25; ++i)
   {
      vector <char> v;
      for(int j=0; j<(rand()%10)+1; ++j)
         v.push_back((char)(rand()%26+65));
      a.push(v);
   }

   while(!a.empty())
   {  
      vector <char> v = a.front();    
      for(auto j=v.begin(); j!=v.end(); ++j)
         cout << *j <<"\t";
      a.pop();
      cout << endl;
   }
} 

void seed_rand(void)
{
   time_t t;
   int t_val = time(&t);
   srand(t_val);
}
