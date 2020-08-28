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
   cout << endl<<endl;
}
// Function to sort arr[] of size n
void shellsort(vector <int> &A, int n)
{
   for(int gap = n/2; gap >0; gap /=2)
   {
      for(int i=gap; i<n; i++)
      {
         int key=A[i];
         int j=i;
         while(j>=gap && A[j-gap]>key)
         {
            A[j] = A[j-gap];
            j -=gap;
         }
         A[j] = key;

      }
      
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
   
   shellsort(A, n);
   
   cout << "Output Array: \n";
   print_array(A);
   

}  





