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

// merging function as per cpp book
void merge(int *L, int n1, int *R, int n2, int *arr)
{
    cout << endl << endl;
    
    int i = 0, j = 0, k = 0;
    while (i < n1 and j < n2)   // exit when anyone of array is over for comparison
    {
        if (L[i] <= R[j])       // if left element is small, shift it to array
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        else                    // if right element is small, shift it to array
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    if (i >= n1)                // if left array is all copied, shift remaining right elements to array
    {
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    
    if (j >= n2)                // if right array is all copied, shift remaining left elements to array
    {
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
    }        
}

/* make it compact in look
// merging function as per cpp book
void merge(int *L, int n1, int *R, int n2, int *arr)
{
    cout << endl << endl;
    
    for (int i = 0, j = 0, k = 0; i < n1 and j < n2; k++)   // exit when anyone of array is over for comparison
    {
        if (L[i] <= R[j])       // if left element is small, shift it to array
            arr[k] = L[i++];
        
        else                    // if right element is small, shift it to array
            arr[k] = R[j++];
    }
    
    if (i >= n1)                // if left array is all copied, shift remaining right elements to array
    {
        while (j < n2)
            arr[k++] = R[j++];
    }
    
    if (j >= n2)                // if right array is all copied, shift remaining left elements to array
    {
        while (i < n1)
            arr[k++] = L[i++];
    }        
}

*/

       
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
    merge(L, size_1, R, size_2, A);  
    
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
