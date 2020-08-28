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
    cout << "\nIn Function";
    t.display();
}

int main()
{
    date d1(8, 1, 1999), *d2;
    
    d1.display();
    
    d2 = &d1;
    
    fun(d1);
    cout << "\nIn Main" << endl;    
    
    fun(*d2);   
    cout << "\nIn Main" << endl;
    
    cout << "To show use of object pointer";
    d2->display();        
        
    return 0;
    
}
