#include <iostream>
#include <string.h>
using namespace std;

class abc
{   
    private:
    int roll;
    char name[15];
    int marks;
    
    public:
    void p(void)
        {display();}
    
    void update(void)
    {
        cout << "Enter the roll no: " << endl;
        cin >> roll;
        char ch;
        cin.get(ch);
        cout << "Enter the name: " << endl;
        cin.getline(name, 15);
        cout << "Enter marks: " << endl;
        cin >> marks;
        cout << endl;
    }
    private:
    void display(void)
    {
        cout << endl << "Roll No: " << roll << endl << "Name: ";
        cout.write(name, strlen(name));
        cout << endl << "Marks: " << marks << endl;
    }
};


int main()
{   

    cout << endl << endl; 
    
    int size = 2;
    abc s[size];
    
    for( int i = 0; i < size; ++i)
        s[i].update();

    cout << endl << endl;     
    
    for( int i = 0; i < size; ++i)
        s[i].p();
        //cout<< s[i].inner.fry << endl;
            
    cout << endl << endl; 
    return 0;
}



              
