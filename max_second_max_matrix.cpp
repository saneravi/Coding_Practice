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

// find max and second_max function
void find(int *arr, int m, int n)
{
    int max = arr[0], sec_max = arr[0], max_r = 0, max_c = 0, smax_r = 0, smax_c = 0;
    
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if (arr[i*n + j] > max)             // check for maximum
            {   
                sec_max = max;                  // update second max value
                max = arr[i*n + j];             // update max value
                
                smax_r = max_r; smax_c = max_c; // update second max position
                max_r = i; max_c = j;           // update max position
            }
    cout << "\n\nMax value : " << max << " at [" << max_r << "][" << max_c << "]\n";
    cout << "\nSecond Max value : " << sec_max << " at [" << smax_r << "][" << smax_c << "]\n";    
}

       
int main()
{

// create sorted arrays L
    cout << "\nEnter size M: ";
    int N, M;   cin >> M;
    cout << "\nEnter size N: ";    
    cin >> N;
    int *A = new int[M*N];    
    
    generate_data(A, M*N);

// show matrix    
    for(int i = 0; i < M ; ++i)
    {
        for(int j = 0; j < N ; ++j)        
            cout << A[i*N + j] << "\t";
        cout << endl;
    }
    
// find max and second_max
    find(A, M, N);
    
    delete A;
    cout << endl << endl;      
    return 0;
    
}
