#include <iostream>

using namespace std;
float P = 3.1416;
void f(int a)
    {
    cout << "Integer: " << a << endl;
    }

void f(float a)
    {
    cout << "Float: " << a << endl;
    }

void f(long a)
    {
    cout << "Long: " << a << endl;
    }

void f(char a)
    {
    cout << "Char: ";cout.put(a); cout << endl;
    }

void f(double a)
    {
    cout << "Double: " << a << endl;
    }


/*
int main()
{

    f(1234);
    f(1234.0f);
    f((long)1234);
    f(1234.00);
    f('a');
    
    cout << endl << endl;
    
    return 0;
}

*/

              
