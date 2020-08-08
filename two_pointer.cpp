//queue of vectors
#include<bits/stdc++.h> 
using namespace std; 
void solve(); 
void seed_rand(void)
{
   time_t t;
   int t_val = time(&t);
   srand(t_val);
}
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
   vector <int> A, B;
   int n, m, x;
   cin >> n;
   for(int i=0; i<n; ++i)
   {
      cin>>x;
      A.push_back(x);
   }

   cin>>m;
   for(int i=0; i<m; ++i)
   {
      cin>>x;
      B.push_back(x);
   }

   sort(A.begin(), A.end());
   sort(B.begin(), B.end());


   cin>>x;
   int ans1, ans2, diff=INT_MAX, l=0, r=m-1;
   while(l<n && r>=0)
   {
      if(abs(A[l]+B[r]-x) < diff)
         {
            ans1 = A[l];
            ans2 = B[r];
            diff  = abs(A[l]+B[r]-x);
         } 
      else if(A[l]+B[r]<x)
         l++;
      else
         r--;

   }



/*
   for(int i=0; i<n; ++i)
   {
      for(int j=0; j<m; ++j)
      {
         if(abs(A[i]+B[j]-x) < diff)
         {
            ans1 = A[i];
            ans2 = B[j];
            diff  = abs(A[i]+B[j]-x);
         } 
      }
   }
*/
   cout << ans1 <<"\t"<<ans2;

}


