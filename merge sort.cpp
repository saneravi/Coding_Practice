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

void merge(vector <int> &A, int l, int m, int r)
{
   int n1 = m-l+1;
   int n2 = r-m;

   int L[n1+1], R[n2+1];

   int i, j, k;
   for(i=0; i<n1; ++i)
      L[i] = A[l+i];
   
   for(i=0; i<n2; ++i)
      R[i] = A[m+1 +i];

   L[n1] = INT_MAX; R[n2] = INT_MAX; i=0; j=0;

   for(k=l; k<=r; ++k)
   {
      if(L[i]<=R[j])
         A[k] = L[i++];

      else
         A[k] = R[j++];
   }

}

void MergeSort(vector <int> &A, int l, int r)
{
   if(l<r)
   {
      int m = l + (r-l)/2;

      MergeSort(A, l, m);
      MergeSort(A, m+1, r);
      merge(A, l, m, r);
   }
}


void solve() 
{
   vector <int> A;
   int n;
   
   // create a vector of size n
   cin >> n;   
   cout << "Input Array: \n";
   for(int i=0; i<n; ++i){
      A.push_back(rand()%100);
   }

   print_array(A);
   cout << endl;

   //sort(A.begin(), A.end());
   /********MERGE SORT ALGO*********/  
   MergeSort(A, 0, n-1);                  // function call
   cout << "Sorted Array:\n";
   print_array(A);

}  



