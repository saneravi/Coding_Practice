#include <iostream>
using namespace std;

class date
{
    int dd, mm, yy;
    
    public:
        date(int a, int b, int c)
        {
            cout << "\nCtor called\n";
            dd = a;
            mm = b;
            yy = c;
        }
        
        date()
        {
            cout << "\nCtor called\n";
            dd = 1; mm = 1; yy = 1900;
        }
        
        void display(void);
        
        ~date()
        {
            cout << "\nDtor called\n";
        }
};

void date::display(void)
{
    cout << endl;
    cout << dd << "/" << mm << "/" << yy <<endl;
} 
        
void fun(date t) // call by value function no ctor created
{   
    cout << "In Function" << endl;
    t.display();
}

int main()
{
    date d1(8, 1, 1999), d2;
        
    fun(d1);
    cout << "out of function" << endl;    
    
    fun(d2);    
    cout << "In Main" << endl;        
        
    return 0;
    
}
