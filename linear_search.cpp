#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int linear_search(int *arr, int v, int size)
{

    for(int i = 0; i < size; ++i)
        if (arr[i] == v)
            return i;
 
    return -1;
}
       
int main()
{
// to generate random numbers        
    time_t t;
    int t_value = time(&t);
    srand(t_value);

// generating numbers
    cout << "Enter size: ";
    int size; cin >> size;
    int *A = new int[size];
    
    for(int i = 0; i < size; ++i)
    {
        A[i] = rand()%100;
        cout << A[i] << " ";
    }
    
    cout << endl;
    cout << "Enter the value v: ";
    int value = 0;
    cin >> value;    
        
    cout << "\nIndex of value v: " << linear_search(A, value, size) << endl << endl;
    
    delete A;        
    return 0;
    
}
