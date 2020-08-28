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

void merge(vector <int> &A, int l, int m, int r, int &counter)
{                                                // counter is passed as ref       
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
         {
            A[k] = R[j++];            
            counter += (n1-i);         // ONLY TRICK***** CHANGE IN THE CODE 
         }
   }

}

void MergeSort(vector <int> &A, int l, int r, int &counter)
{                                              // counter is passed as ref

   if(l<r)
   {
      int m = l + (r-l)/2;

      MergeSort(A, l, m, counter);
      MergeSort(A, m+1, r, counter);
      merge(A, l, m, r, counter);
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
      cin >> x;
      A.push_back(x);//rand()%100);
   }

   print_array(A);
   cout << endl;

   //sort(A.begin(), A.end());
   /********COUNT INVERSION ALGO*********/  
   int count = 0;
   MergeSort(A, 0, n-1, count);                  // function call
   cout << "Sorted Array:\n";
   print_array(A);

   cout << "\nInversion Count: " << count << endl;

}  
// Time Complexity: O(n log n)
/*
    The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
    Create a function merge that counts the number of inversions when two halves of the array are merged, create two indices i and j, i is the index for first half and j is an index of the second half. if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
    Create a recursive function to divide the array into halves and find the answer by summing the number of inversions is the first half, number of inversion in the second half and the number of inversions by merging the two.
    The base case of recursion is when there is only one element in the given half.
    Print the answer
*/ 




