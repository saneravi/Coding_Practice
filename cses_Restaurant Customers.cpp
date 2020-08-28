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
You are given the arrival and leaving times of n customers in a restaurant.
What was the maximum number of customers?

Input
The first input line has an integer n: the number of customers.
After this, there are n lines that describe the customers. 
Each line has two integers a and b: the arrival and leaving times of a customer.
You may assume that all arrival and leaving times are distinct.

Output
Print one integer: the maximum number of customers.

*/
void solve() 
{   
   int n,i,j;
   cin>>n;
   long long int A[n],B[n];
   for(i=0; i<n; ++i)
   {   
      cin>>A[i];          
      cin>>B[i];          
   }
   
   sort(A, A+n);
   sort(B, B+n);

   i=0;j=0;
   int count = 0, max_c=0;
   while(j<n)
   {      
      if(A[i]<B[j])
      {  
         i++;
         count++;
         if(count>max_c) 
            max_c = count;
      }
      else if(A[i]>B[j])
      {
         j++;
         count--;         
      }
      else
      {
         i++;
         j++;
      }
   }

   cout<<max_c;

}


