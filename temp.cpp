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

void print_array(vector <float> C)
{
   for(int i=0; i<C.size(); ++i)
      cout<<C[i]<<"\t";
   cout << endl;
}

void bucketsort(vector <float> &A, int n)
{
   // create n buckets
   vector <float> bucket[n];

   // store in correct buckets
   for(int i=0; i<n; ++i)
   {
      int b_idx = n* A[i];
      bucket[b_idx].push_back(A[i]);
   }

   // sort each buckets
   for(int i=0; i<n; ++i)
      sort(bucket[i].begin(), bucket[i].end());

   // concatenate buckets
   int index = 0;
   for(int i=0; i<n; ++i)
      for(int j=0; j<bucket[i].size(); ++j)
         A[index++] = bucket[i][j];

}


void solve() 
{
   vector <float> A;
   int n,x;
   
   // create a vector of size n
   cin >> n;   
   cout << "Input Array: \n";
   for(int i=0; i<n; ++i){
      // cin >> x;
      A.push_back(((float)(rand()%100))/100);
   }

   print_array(A);
   cout << endl;

   //sort(A.begin(), A.end());
   
   bucketsort(A, n);
   
   print_array(A);
   

}  





