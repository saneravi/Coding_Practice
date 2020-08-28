#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// CLASS SCHOOL //////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
class School
    {
    static int count_school; // count number of school objects
    char name[50];           // name of school
    int cls;                 // class of student
    
    public:
    School() : name("K V EME School") // initiate with default parameters using CTOR
        {
        cls = 12;
        count_school++;
        //cout << count_school << " number object of class School is created." << endl;
        }
    
    void update(void)   // change the parameters
        {
        char temp; cin.get(temp);
        cout << "Enter the school name: ";
        cin.getline(name, 50);
        cout << "Enter the class: ";
        cin >> cls;
        cout << "Entry done!" << endl;
        }
        
    void display(void)  // display the parameters
        {
        cout << "School: "; cout.write(name, strlen(name)); cout << endl;
        cout << "Class: " << cls << endl;
        }
        
    char *acc_name(void) // to access and in the end store school name in a file
        {return name;}
        
    int acc_class(void)  // to access and in the end store class in a file
        {return cls;}
        
    ~School()   // DTOR
        {
        //cout << count_school << " number Object of class School is destroyed." << endl;        
        count_school--;        
        }
        
    };
int School::count_school = 0;        // static variable init

/////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// CLASS STUDENT /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

class Student
    {
    static int count_student;   // to count student objects
    int rollno;
    char name[50];
    int marks;
    char grade;
    School s;                   // object to store school n class info
    
    public:
    void enter(void);           // enter new values
    void get_grade(void);       // calculate grades
    void change(void);          // change the school name and class
    void display(void);         // display all info
    
    Student(): name("New_Student")    // CTOR init default values
        {
        rollno = 0;
        marks = 0;
        count_student++;
        //cout << count_student << " number object of class Student is created." << endl;
        get_grade();
        }
    
    char *access(int &r, int &m, char &g, int &c) // to access private parameters in order to store them in a file
        {
        r = rollno;
        m = marks;
        g = grade;
        c = s.acc_class();
        return name;
        }
    
    char *access2(void) // to access name of school
        {
        return s.acc_name();
        }
    
    ~Student()  // DTOR
        {
        //cout << count_student << " number object of class Student is being destroyed." << endl;
        count_student--;        
        }
        
    };
int Student::count_student = 0; // to init the counter to count number of student object created

void Student::enter(void) // enter new values
    {
    cout << endl << "Enter the roll number of student: ";
    cin >> rollno;
    char temp; cin.get(temp);
    cout << "Enter the name of student: ";
    cin.getline(name, 50);
    cout << "Enter the marks of student: ";
    cin >> marks;       
    change();
    get_grade();
    }
       
void Student::change(void) // change the school name and class
    {
    char ch;
    cout << "Do you want to change the default school name or class? Enter y/n: ";
    cin >> ch;
    if (ch == 'Y' or ch == 'y')
        s.update();
    else
        cout << "Entry done!" << endl;
    }

void Student::get_grade(void) // calculate grades
    {
    if (marks > 80)
        grade = 'A';
    else if (marks > 60)
        grade = 'B';
    else if (marks > 50)
        grade = 'C';
    else if (marks > 40)
        grade = 'D';
    else
        grade = 'F';
    }
 
void Student::display(void) // display all info
    {
    s.display();    
    cout << "Roll no: " << rollno << endl;
    cout << "Name: "; cout.write(name, strlen(name)); cout << endl;        
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << grade << endl << endl;            
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////// MAIN FUNCTION /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
int main() 
    {
    
    Student candidate[10];
    int num;
    cout << "\n\nEnter number of students: "; // TOTAL students required max 10 allowed
    cin >> num;
    
    
    for(int i = 0; i < num; i++) // get info of students
        candidate[i].enter();
    
    
    int r, m, c; // temp variables
    char *n, g, *ss;
    
    ofstream fout;
    fout.open("Store_here.txt", ios::app); // to store to a file
    for(int i = 0; i < num; i++)
        {
        n = candidate[i].access(r, m, g, c); // get name, rollno, marks, grade, class
        ss = candidate[i].access2();         // get school name
        
        fout << "School Name: " << ss << '\n' 
             << "Class: " << c <<'\n'
             << "Roll No: " << r << '\n'
             << "Name: " << n << '\n'
             << "Marks: " << m << '\n'
             << "Grade: " << g << '\n' << '\n'; // write in a file
        
        }
    fout.close(); // close the file
    cout << endl << endl;
    for(int i = 0; i < num; i++) // display the details entered
        candidate[i].display();
        
    return 0;
    }   

    
    
        
    
    
              
