#include<bits/stdc++.h> 
using namespace std; 
void solve(); 
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
      cout<<"\n\n\n"; 
   } 
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
} 

/*

*/

void solve() 
{   
   int n,i,x;
   cin>>n;
   vector <int> A,t;
   vector <vector <int> > B;
   for(i=0; i<n; ++i)
   {
      cin>>x;
      A.push_back(x);
   }
   
   t.push_back(A[0]);
   B.push_back(t);

   for(i=1; i<n; ++i)
   {  
      int flag = 1; 
      vector <int> v;
      for(int j=0; j<B.size(); j++)
         if(A[i] < B[j].back())
         {
            B[j].push_back(x);
            flag = 0;
            break;
         }

      if(flag)
      {
         v.push_back(x);
         B.push_back(v);
      }   
   }
   
   cout<<B.size();
 
   for(i=0; i<B.size(); ++i)
      for(int j=0; j<B[i].size(); ++j)
         cout << B[i][j]<<" ";


}


