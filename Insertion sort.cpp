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
      cout<<"\n\n\n"; 
   } 
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl; 
   return 0; 
} 

void solve() 
{
   vector <int> A;
   int n;
   cin >> n;
   for(int i=0; i<n; ++i)
   {
      //cin>>x;
      A.push_back(rand()%20);
      cout<<A[i]<<"\t";
   }
   cout << endl<<endl;

   for(int i=1; i<n; ++i)
   {
      int key = A[i];
      int j = i-1;

      while(j>=0 && A[j]>key)
      {
         A[j+1] = A[j];
         j--;
      }
      A[j+1] = key;
   }



   
   for(int i=0; i<n; ++i)
      cout<<A[i]<<"\t";


}


