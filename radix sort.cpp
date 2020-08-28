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

void print_array(vector <int> C)
{
   for(int i=0; i<C.size(); ++i)
      cout<<C[i]<<"\t";
   cout << endl;
}
// Function to sort arr[] of size n using radix sort
void radixsort(vector <int> &A, int n)
{
   int maxk = *max_element(A.begin(), A.end());
   vector <int> B = A;
   for(; maxk>0; maxk /=10)
   { 
      for(int i=0; i<n-1; ++i)
         for(int j=0; j<n-1-i; ++j)
            if((B[j]%10)>(B[j+1]%10))
            {  
               swap(B[j], B[j+1]); 
               swap(A[j], A[j+1]);
            }
      // print_array(A);
      // cout<<endl;
      for(int i=0; i<n; ++i)
         B[i] /= 10;

   }


}


void solve() 
{
   vector <int> A;
   int n,x;
   
   // create a vector of size n
   cin >> n;   
   cout << "Input Array: \n";
   for(int i=0; i<n; ++i){
      // cin >> x;
      A.push_back(rand()%1000);
   }

   print_array(A);
   cout << endl;

   //sort(A.begin(), A.end());
   
   radixsort(A, n);
   
   print_array(A);
   

}  





