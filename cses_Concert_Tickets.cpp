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
There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.

Each customer announces the maximum price he or she is willing to pay for a ticket, and after this, they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input

The first input line contains integers n and m: the number of tickets and the number of customers.

The next line contains n integers h1,h2,…,hn: the price of each ticket.

The last line contains m integers t1,t2,…,tm: the maximum price for each customer.

Output

Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.

If a customer cannot get any ticket, print −1.
*/
void solve() 
{   
   int n,m,i,j;
   cin>>n>>m;
   long long int A[n],B[m];
   for(i=0; i<n; ++i)   
      cin>>A[i];          
   for(i=0; i<m; ++i)   
      cin>>B[i];          
   sort(A, A+n);

   j=0;
   while(j<m)
   {
      int flag = -1;
      for(i=n-1; i>=0;--i)
         if(A[i]<=B[j])
         {
            cout<<A[i]<<"\n";
            A[i] = INT_MAX;
            flag = 0;
            break;
         }
      if(flag)
         cout<<flag<<"\n";
      j++;
   }


}


