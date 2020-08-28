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
There are n applicants and m free apartments. Your task is to distribute 
the apartments so that as many applicants as possible will get an apartment.
Each applicant has a desired apartment size, and they will accept any 
apartment whose size is close enough to the desired size.
Input
The first input line has three integers n, m, and k: the number of applicants, 
the number of apartments, and the maximum allowed difference.
The next line contains n integers a1,a2,…,an: the desired apartment size of 
each applicant. If the desired size of an applicant is x, he or she will 
accept any apartment whose size is between x−k and x+k.
The last line contains m integers b1,b2,…,bm: the size of each apartment.

Output
Print one integer: the number of applicants who will get an apartment.
*/
void solve() 
{   
   int n,m,k,i,j;
   cin>>n>>m>>k;
   long long int A[n],B[m];
   for(i=0; i<n; ++i)   
      cin>>A[i];         
   for(j=0; j<m; ++j)
      cin>>B[j];      
   
   sort(A, A+n);
   sort(B, B+m);
   int count = 0;
   i=0; j=0;
   while(i<n && j<m)
   {
      if(A[i]-B[j]>k)
         j++;
      else if(B[j]-A[i]>k)
         i++;
      else
      {
         count++;
         i++;
         j++;
      } 
   }   
   cout<<count;
}


