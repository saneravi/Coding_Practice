#include <iostream>
#include <string.h>
using namespace std;

class school
{
    char s_name[30];
    char location[30];
    int pin;
    
public:
    school():s_name("No Name Defined"), location("India")
    {
        cout << "\nSchool Object created!\n";
    }
    
    void input(void);
    void display(void);
    
    ~school()
    {
        cout << "\nSchool Object destroyed!\n";
    }
};

void school::input(void)
    {
        cout << "\nEnter the name of school: ";
        cin.getline(s_name, 30);
        //char ch;
        //cin.get(ch);
        cout << "\nEnter the location of school: ";
        cin.getline(location, 30);
        //cin.get(ch);
    }
void school::display(void)
    {
        cout << "\nSchool Name: ";
        cout.write(s_name, strlen(s_name));
        cout << "\nLocation: ";
        cout.write(location, strlen(location));
    }
    
    
class student:public school
{
    char stud_name[30];
    int rno, cls;
    
public:
    student():stud_name("No Name Defined")
    {
        cout << "\nStudent Object created!\n";
        rno = -1;
        cls = -1;
    }
    
    void input(void);
    void display(void);
    
    ~student()
    {
        cout << "\nStudent Object destroyed!\n";
    }
};

void student::input(void)
    {
        cout << "\nEnter the name of student: ";
        cin.getline(stud_name, 30);
        char ch;
        //cin.get(ch);
        cout << "\nEnter the class: ";
        cin >> cls;
        cout << "\nEnter the roll no: ";
        cin >> rno;
        cin.get(ch);
    }
void student::display(void)
    {
        cout << "\nStudent Name: ";
        cout.write(stud_name, strlen(stud_name));
        cout << "\nClass: ";
        cout << cls;
        cout << "\nRoll No: ";
        cout << rno;
        cout << endl;
    }
    
int main()
    {
    student obj1, obj2;
    obj1.input();
    obj1.school::input();
    obj1.school::display();
    obj1.display();

// to show the use of ctor for default name 
    obj2.school::display();
    obj2.display();

    return 0;
    }        
    
