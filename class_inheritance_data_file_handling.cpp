#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/* This is a class to store name and location of school */
class school
{
    char s_name[30];
    char location[30];
    
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
        cout << "\nEnter the name of school(Press . for default): ";        
        cin.getline(s_name, 30);
        //char ch;
        //cin.get(ch);
        cout << "\nEnter the location of school(Press . for default): ";
        cin.getline(location, 30);
        //cin.get(ch);
        
        if(s_name[0] == '.')
            strcpy(s_name,"K V EME No 2");
        if(location[0] == '.')
            strcpy(location,"Vadodara");
    }
void school::display(void)
    {
        cout << "\nSchool Name: ";
        cout.write(s_name, strlen(s_name));
        cout << "\nLocation: ";
        cout.write(location, strlen(location));
    }
/////////////////////////////////////////////////////////////////////////////////    
    
/* This is the class to store the name, roll no and class of student. */    
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

//////////////////////////////////////////////////////////////////
///////////////////////// Main Fn ////////////////////////////////
//////////////////////////////////////////////////////////////////    

int main()
    {
    student obj1;
    fstream fio, fio2;
    fio.open("Database.dat", ios::app);

// loop to accept new student entries    
    do
    {
        cout << "Do you want enter data of new student?: ";
        char ch[4];
        cin.getline(ch,4);
        if(ch[0] == 'Y' or ch[0] == 'y')
        {                    
            obj1.input();
            obj1.school::input();
        }
        else
            break;
            
        fio.write((char *) &obj1, sizeof(obj1));
    }while(1);
        
    fio.close();
    
    student obj2;
    
    cout << "\n\nDatabase: \n";
    fio2.open("Database.dat", ios::in);

// loop to print the database    
    while(fio2)
    {
        cout << "Address in Database: " << fio2.tellg();    
        fio2.read((char *) &obj2, sizeof(obj2));
        obj2.school::display();
        obj2.display();
    }
    
    fio2.close();
    return 0;
    }        
    
