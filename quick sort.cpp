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

/* This function takes last element as pivot, 
places the pivot element at its correct position in sorted array, 
and places all smaller (smaller than pivot) to left of pivot and 
all greater elements to right of pivot */
int partition(vector <int> &A, int low, int high)
{
   int pivot = A[high];                // pivot
   int i = low-1;                      // Index of smaller element  

   for(int j=low; j< high; ++j)
      if(A[j] < pivot)                 // If current element is smaller than the pivot  
      {
         i++;                          // increment index of smaller element  
         swap(A[j], A[i]);
      }
   swap(A[i+1], A[high]);
   return (i+1);
}

/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quicksort(vector <int> &A, int low, int high)
{
   if(low<high)
   {
      int pi = partition(A, low, high); /* pi is partitioning index, arr[pi] is now  
                                          at right place */
      quicksort(A, low, pi-1);            // Separately sort elements before
      quicksort(A, pi+1, high);           // partition and after partition
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
   /********QUICK SORT ALGO*********/  
   quicksort(A, 0, n-1);                  // function call
   cout << "Sorted Array:\n";
   print_array(A);

}  



