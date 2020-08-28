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
void selection_sort(int *arr, int size)
{
    int smallest;
    for(int j = 0; j < size-1; ++j)
    {
        smallest = j;
        for (int i = j+1; i < size; ++i)
            if (arr[i] < arr[smallest])
                smallest = i;
                
        swap(arr[j], arr[smallest]);
    }
}


       
int main()
{

// generating numbers
    cout << "\nEnter size: ";
    int size, temp_size;   cin >> size;
    int *A = new int[size];
    
    temp_size = size;
    
    generate_data(A, size);
    
    selection_sort(A, size);

// display sorted array    
    cout << "\nSorted array: \n";
    for(int i = 0; i < size; ++i)
        cout << A[i] << " ";    

    delete A;
    cout << endl << endl;      
    return 0;
    
}
