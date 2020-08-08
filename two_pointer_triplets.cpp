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
   int n, x;
   cin >> n;
   for(int i=0; i<n; ++i)
   {
      //cin>>x;
      A.push_back(rand()%20-10);
      cout<<A[i]<<"\t";
   }
   cout << endl<<endl;

   sort(A.begin(), A.end());
   int flag=0;
   for(int i =0; i<n-1; ++i)
   {
      int l=i+1, r=n-1;
      while(l<r)
      {
         if(A[i]+A[l]+A[r]==0)
         {
            cout << A[i] << "\t"<< A[l]<<"\t"<< A[r]<<"\n";
            l++;
            r--;
            flag = 1;
         }
         else if(A[i]+A[l]+A[r]<0)
            l++;
         else
            r--;
      }
   }
   if(!flag)
      cout<<"No triplet";

}


