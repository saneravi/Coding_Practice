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
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void min_heapify(vector <int> &A, int k, int i)
{
   int small = i; // Initialize smallst as root 
   int l = 2*i+1; // left = 2*i + 1 
   int r = 2*i+2; // right = 2*i + 2 

   if(l<k && A[l]<A[small]) // If left child is smallr than root 
      small = l;

   if(r<k && A[r]<A[small]) // If right child is smallr than smallst so far
      small = r;

   if(small!=i)             // If smallst is not root
   {
      swap(A[small], A[i]);   
      min_heapify(A, k, small);  // Recursively heapify the affected sub-tree 
   }
}
void max_heapify(vector <int> &A, int k, int i)
{
   int large = i; // Initialize largest as root 
   int l = 2*i+1; // left = 2*i + 1 
   int r = 2*i+2; // right = 2*i + 2 

   if(l<k && A[l]>A[large]) // If left child is larger than root 
      large = l;

   if(r<k && A[r]>A[large]) // If right child is larger than largest so far
      large = r;

   if(large!=i)             // If largest is not root
   {
      swap(A[large], A[i]);   
      max_heapify(A, k, large);  // Recursively heapify the affected sub-tree 
   }
}

void solve() 
{
   vector <int> A;
   int n, k;
   
   // create a vector of size n
   cin >> n;   
   cin >> k;
   cout << "Input Array: \n";
   for(int i=0; i<n; ++i)
   {
      //cin>>x;
      A.push_back(rand()%100);
      cout<<A[i]<<"\t";
   }
   cout << endl<<endl;

   /********HEAP SORT ALGO*********/  // NOTE : ALGO is incomplete
   //for(int i=(n/2)-1; i>=0; --i)
   //   min_heapify(A, k, i);

   
   for(int j=0; j<n; ++j)
   {
      for(int i=(j+k+1)-1; i>j; --i)    // Build heap (rearrange array) 
         max_heapify(A, k, i);


      for(int i=(j+k+1)-1; i>j; --i)   // One by one extract an element from heap
      {                                // *****only change is in the limits of i>0 to i>(n-1-k)
         swap(A[i], A[j]);             // Move current root to end 
         max_heapify(A, i, j);         // call max heapify on the reduced heap 
      }
   }

   cout << endl << "k sorted array: \n";
   for(int i=0; i<n; ++i)
      cout<<A[i]<<"\t";
   cout << endl;

}  //**** time complexity is (n + klog n)


