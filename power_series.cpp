#include <iostream>
#include <math.h>
using namespace std;
double sum_series(double, int);
double fact(double);

int main()
{   
    double x; int n;
    cout<< "Enter the value of x: ";
    cin>> x;
    cout<< "Enter the value of n: ";
    cin>> n;
    cout<< endl<< sum_series(x, n);
    return 0;
}

double sum_series(double x, int n)
    {   
        double sum = 0;
        for (int i = 1; i <= n ; ++i)
            sum += pow(x, i)* pow(-1, i+1)/ fact(2*i - 1);
        return sum;
    }        
    
double fact(double f)
    {
        double factorial = 1;
        for(int i = 1; i <= f; i++)
            factorial *= i;
        return factorial;
    }  
