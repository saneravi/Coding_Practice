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
Given an array of n integers, your task is to 
find the maximum sum of values in a contiguous, nonempty subarray.

Input
The first input line has an integer n: the size of the array.
The second line has n integers x1,x2,…,xn: the array values.

Output
Print one integer: the maximum subarray sum
*/

void solve() 
{   
   int n,i,x;
   cin>>n;
   vector <long long int> A;
   for(i=0; i<n; ++i)
   {
      cin>>x;
      A.push_back(x);
   }
      
   long long int max_so_far = A[0]; 
   long long int curr_max = A[0]; 
  
   for (i=1; i < n; i++) 
   { 
        curr_max = max(A[i], curr_max + A[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 

   cout<<max_so_far;
 
}


