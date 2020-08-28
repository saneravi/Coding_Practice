#include <iostream>
using namespace std;

struct student
{
    int roll_no;
    int cls;
};


int main()
{  
    cout << "Enter size: ";
    int n;
    cin >> n;
    
    student *s = new student[n];
    
    for (student *i = s; i < &s[n]; ++i)
    {
        cout << "rno: ";
        cin >> i->roll_no;
        cout << "cls: ";
        cin >> i->cls;
    }
    
    for (int i = 0; i < n; ++i)
    {   
        cout << s[i].roll_no << "\t" << s[i].cls << endl;
    }
    delete s;
    
    return 0;
    
}
