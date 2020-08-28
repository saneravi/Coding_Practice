#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// generate data (random numbers b/w 0 and 99)
void generate_data(int *arr, int size)
{     
    time_t t;
    int t_value = time(&t);
    srand(t_value);

    for(int i = 0; i < size; ++i)
        arr[i] = rand()%100;
}

// sort array in asc order
void bubble_sort(int *arr, int size)
{
    for(int i = 0; i < size; ++i)
        for (int j = 0; j < size-i-1; ++j)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// recursive binary search function
int recursive_binary_search(int *arr, int value, int low, int high)
{
    if (low > high)
        return -1;
    
    int mid = (low + high)/2;
    
    if (arr[mid] == value)
        return mid;
    
    if (arr[mid] > value)
        return recursive_binary_search(arr, value, low, mid-1);
    
    else
        return recursive_binary_search(arr, value, mid+1, high);    
}
       
int main()
{

// generating numbers
    cout << "\nEnter size: ";
    int size;   cin >> size;
    int *A = new int[size];   
    
    generate_data(A, size);
    
    bubble_sort(A, size);

// display sorted array    
    cout << "\nSorted array: \n";
    for(int i = 0; i < size; ++i)
        cout << A[i] << " ";
    
    cout << endl;
    cout << "Enter the value v: ";
    int value = 0;
    cin >> value;    

// display index        
    cout << "\nIndex of value v: " << recursive_binary_search(A, value, 0, size-1) << endl << endl;
    
    delete A;
    cout << endl << endl;      
    return 0;
    
}
