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
You are given an array of n integers, and your task is to 
find two values (at distinct positions) whose sum is x.

Input
The first input line has two integers n and x: the array size 
and the target sum.
The second line has n integers a1,a2,…,an: the array values.

Output
Print two integers: the positions of the values. If there are 
several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
*/

void solve() 
{   
   int n,i,j,x,y;
   cin>>n>>x;
   vector < pair <int,int> > A;
   for(i=0; i<n; ++i)
   {
      cin>>y;
      pair <int, int> p;
      p.first = y;
      p.second = i;

      A.push_back(p);
   }
      
   sort(A.begin(), A.end());

   i=0; j=n-1;
   int flag=1;
   while(i<j)
   {
      if(A[i].first + A[j].first <x)
         i++;
      else if(A[i].first + A[j].first >x)
         j--;
      else if(A[i].first + A[j].first ==x)
      {
         cout << A[i].second <<" "<<A[j].second;
         flag = 0;
         break;
      }
   }

   if(flag)
      cout<<"IMPOSSIBLE";
 
}


