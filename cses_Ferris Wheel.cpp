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
There are n children who want to go to a Ferris wheel, 
and your task is to find a gondola for each child.
Each gondola may have one or two children in it, and 
in addition, the total weight in a gondola may not exceed x. 
You know the weight of every child.
What is the minimum number of gondolas needed for the children?

Input
The first input line contains two integers n and x: 
the number of children and the maximum allowed weight.
The next line contains n integers p1,p2,…,pn: the weight of each child.

Output
Print one integer: the minimum number of gondolas.
*/
void solve() 
{   
   int n,x,i,j;
   cin>>n>>x;
   long long int A[n];
   for(i=0; i<n; ++i)   
      cin>>A[i];          
   
   sort(A, A+n);
   int count = 0;
   i=0; j=n-1;
   while(i<=j)
   {
      if(A[i]+A[j]>x)
      {
         j--;
         count++;
      }
      else if(A[i]+A[j]<=x)
      {
         i++;
         j--;
         count++;
      }
      else if(i==j)
         count++;

   }   
   cout<<count;
}


