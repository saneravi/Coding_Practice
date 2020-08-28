#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// generate data (random numbers b/w 0 and 99)
void generate_data(int *arr, int size)
{
// to generate random numbers        
    time_t t;
    int t_value = time(&t);
    srand(t_value);

    for(int i = 0; i < size; ++i)
        arr[i] = rand()%100;
}

// sort array in asc order
void insertion_sort(int *arr, int size)
{
    for(int j = 1; j < size; ++j)
    {
        int key = arr[j];
        int i = j - 1;
        
        while(i >= 0 and arr[i] > key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        
        arr[i+1] = key;
                
    }
}

// merging function as per CLRS book
void merge(int *A, int p, int q, int r)
{
    cout << endl << endl;
    int n1 = q - p + 1;                     // get size of left and right arrays
    int n2 = r - q;                         // as left[p...q] and right[(q+1)...r]
    
    int left[n1 + 1], right[n2 + 1];
    
    for(int i = 0; i < n1; i++)             // extract values
        left[i] = A[i];
    
    for(int i = 0; i < n2; i++)
        right[i] = A[n1 + i];

    left[n1 + 1] = 10000;                   // use sentinels as maximum possible number, say 10000 so that
    right[n2 + 1] = 10000;                  // whenever a card with 10000 is exposed, it cannot be the smaller card unless both piles
                                            // have their sentinel cards exposed. But once that happens, all the nonsentinel cards
                                            // have already been placed onto the output pile

    for(int i = 0, j = 0, k = 0; k < n1 + n2; ++k)
        if (left[i] <= right[j])
            A[k] = left[i++];
        else
            A[k] = right[j++];    
}


       
int main()
{

// create sorted arrays L
    cout << "\nEnter size: ";
    int size_1;   cin >> size_1;
    int *L = new int[size_1];    
    
    generate_data(L, size_1);    
    insertion_sort(L, size_1);

// display sorted array L    
    cout << "\nSorted array L: \n";
    for(int i = 0; i < size_1; ++i)
        cout << L[i] << " ";  


// create sorted arrays R
    cout << "\n\nEnter size: ";
    int size_2;   cin >> size_2;
    int *R = new int[size_2];    
    
    generate_data(R, size_2);    
    insertion_sort(R, size_2);

// display sorted array R    
    cout << "\nSorted array R: \n";
    for(int i = 0; i < size_2; ++i)
        cout << R[i] << " ";    


    int *A = new int[size_1 + size_2];
    for(int i = 0; i < size_1; ++i)
        A[i] = L[i];
        
    for(int i = 0; i < size_2; ++i)
        A[i + size_1] = R[i];
            
    merge(A, 0, size_1-1, size_1 + size_2-1);  
    
// display sorted and merged array    
    cout << "\n\nSorted array L+R => A: \n";
    for(int i = 0; i < (size_1 + size_2); ++i)
        cout << A[i] << " ";      

    delete L;
    delete R;    
    delete A;
    cout << endl << endl;      
    return 0;
    
}
