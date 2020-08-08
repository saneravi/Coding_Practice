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

void print_array(forward_list <int> C)
{
   for(forward_list <int>::iterator j=C.begin(); j!= C.end(); ++j)
      cout<<*j<<"\t";
   cout << endl;
}

/* This function takes last element as pivot, 
places the pivot element at its correct position in sorted array, 
and places all smaller (smaller than pivot) to left of pivot and 
all greater elements to right of pivot */
forward_list <int>::iterator partition(forward_list <int> &A, forward_list <int>::iterator low, forward_list <int>::iterator high)
{
   int pivot = *(high-1);                // pivot
   forward_list <int>::iterator i = low-1;                      // Index of smaller element  

   for(forward_list <int>::iterator j=low; j!= high; ++j)
      if(*j < pivot)                 // If current element is smaller than the pivot  
      {
         i++;                          // increment index of smaller element  
         swap(*j, *i);
      }
   high--;
   i++;
   swap(*i, *high);
   return i;
}

/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quicksort(forward_list <int> &A, forward_list <int>::iterator low, forward_list <int>::iterator high)
{
   if(low!=high)
   {
      forward_list <int>::iterator pi = partition(A, low, high); /* pi is partitioning index, arr[pi] is now  
                                          at right place */
      quicksort(A, low, pi);            // Separately sort elements before
      pi++;
      quicksort(A, pi, high);           // partition and after partition
   }
}

void solve() 
{
   forward_list <int> A;
   int n;
   
   // create a vector of size n
   cin >> n;   
   cout << "Input Array: \n";
   for(int i=0; i<n; ++i){
      A.push_front(rand()%100);
   }


   print_array(A);
   cout << endl;

   //sort(A.begin(), A.end());
   /********QUICK SORT ALGO*********/  
   quicksort(A, A.begin(), A.end());                  // function call
   cout << "Sorted Array:\n";
   print_array(A);

}  

/////////////////// NOT WORKING ??????????
