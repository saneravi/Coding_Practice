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
void max_heapify(vector <int> &A, int n, int i)
{
   int large = i; // Initialize largest as root 
   int l = 2*i+1; // left = 2*i + 1 
   int r = 2*i+2; // right = 2*i + 2 

   if(l<n && A[l]>A[large]) // If left child is larger than root 
      large = l;

   if(r<n && A[r]>A[large]) // If right child is larger than largest so far
      large = r;

   if(large!=i)             // If largest is not root
   {
      swap(A[large], A[i]);   
      max_heapify(A, n, large);  // Recursively heapify the affected sub-tree 
   }
}


void solve() 
{
   vector <int> A;
   int n;
   
   // create a vector of size n
   cin >> n;   
   cout << "Input Array: \n";
   for(int i=0; i<n; ++i)
   {
      //cin>>x;
      A.push_back(rand()%20);
      cout<<A[i]<<"\t";
   }
   cout << endl<<endl;

   /********HEAP SORT ALGO*********/
   cout<<"After building heap: \n";
   for(int i=(n/2)-1; i>=0; --i)    // Build heap (rearrange array) 
      max_heapify(A, n, i);

   cout << endl;     // not imp
   print_array(A);   // not imp
   int count =1;     // not imp

   for(int i=n-1; i>0; --i)         // One by one extract an element from heap 
   {            
      swap(A[i], A[0]);             // Move current root to end 
      max_heapify(A, i, 0);         // call max heapify on the reduced heap 

      cout << "Step "<<count++<<" : "; // not imp
      print_array(A);                  // not imp
   }

   cout << endl << "Sorted array: \n";
   print_array(A);

}


