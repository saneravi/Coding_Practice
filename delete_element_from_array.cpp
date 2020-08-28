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
void bubble_sort(int *arr, int size)
{
    for(int i = 0; i < size; ++i)
        for (int j = 0; j < size-i-1; ++j)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

// find the postion of value v in array
// iterative binary search
int iterative_binary_search(int *arr, int value, int size)
{
    int low = 0, high = size - 1, mid, itr = 1;
    
    while(low <= high)
    {
       
        mid = (int)((low + high)/2);
        
        if (arr[mid] == value)
            return mid;
        
        if (arr[mid] > value)
            high = mid-1;
        else
            low = mid+1;
    }
    return -1;
}


       
int main()
{

// generating numbers
    cout << "\nEnter size: ";
    int size, temp_size;   cin >> size;
    int *A = new int[size];
    
    temp_size = size;
    
    generate_data(A, size);
    
    bubble_sort(A, size);

// display sorted array    
    cout << "\nSorted array: \n";
    for(int i = 0; i < size; ++i)
        cout << A[i] << " ";
    
    cout << endl;
    
    do
    {
    cout << "\n\nDo you want to delete any number?: ";
    char ch; cin >> ch;
    if(ch != 'y' and ch != 'Y')
        break;

// get value        
    cout << "\nEnter the value v to be deleted: ";
    int value;    cin >> value;

// get position    
    int pos = iterative_binary_search(A, value, size);

// error
    if (pos == -1)
    {
        cout << "\nNumber not found!!!\n";
        continue;
    }
        
    size--;

// delete element from the array
    for(int j = pos; j < size; ++j)
        A[j] = A[j+1];            

// display sorted array
    cout << "\nSorted array: \n";
    for(int j = 0; j < size; ++j)
        cout << A[j] << " ";                
    
    if (size == 0)
    {
        cout << "\nList is empty!!!";
        break;
    }
    
    }while(1);

    delete A;
    cout << endl << endl;      
    return 0;
    
}
