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
int pos_search(int *arr, int v, int size)
{
    if (v < arr[0])
        return 0;    
    
    for(int i = 0; i < size-1; ++i)
        if (arr[i] <= v && v < arr[i+1])
            return i+1;
    return size;
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
    cout << "\n\nDo you want to insert new number?: ";
    char ch; cin >> ch;
    if(ch != 'y' and ch != 'Y')
        break;

// get value        
    cout << "\nEnter the new value v to be inserted: ";
    int value;    cin >> value;

// get position    
    int pos = pos_search(A, value, size);    
    size++;

// insert element by creating new array    
    for(int j = size-1; j > pos; --j)
        A[j] = A[j-1];

// element inserted        
    A[pos] = value;            

// display sorted array
    cout << "\nSorted array: \n";
    for(int j = 0; j < size; ++j)
        cout << A[j] << " ";                
    
    }while(1);

    delete A;
    cout << endl << endl;      
    return 0;
    
}
