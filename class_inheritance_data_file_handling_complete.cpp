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
    int getrollno(void)
    {   return rno;
    }
    
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

// fn to enter new data
void new_data(void)
    {
    
        student obj1;
        fstream fio;
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
        
    }
    
void print_database(void)
    {
        fstream fio2;
        fio2.open("Database.dat", ios::in);
        student obj2;
        cout << "\n\nDatabase: \n";

    // loop to print the database    
        while(fio2)
        {
            cout << "Address in Database: " << fio2.tellg();    
            fio2.read((char *) &obj2, sizeof(obj2));
            obj2.school::display();
            obj2.display();
        }
        
        fio2.close();
    }

void search(void)
    {
        fstream fio;
        fio.open("Database.dat", ios::in);
        student obj;
        
        int rno, flag = 1;
        cout << "\nEnter the roll no of student: ";
        cin >> rno;
        
        while(fio)
        {
            fio.read((char *) &obj, sizeof(obj));
            if (obj.getrollno() == rno)
            {
                obj.school::display();
                obj.display();
                flag = 0;
                break;
            }
        }
        
        if (flag)
            cout << "\nRecord not found!!!";
    }
    
void insert_sorted(void)
    {   
        char flag = 'n';
        student new_obj, temp;
        fstream fio, f_temp;
        fio.open("Database.dat", ios::app);
        f_temp.open("temp.dat", ios::out);
        
        new_obj.input();
        new_obj.school::input();            
        
        while(fio)
        {
            fio.read((char *) &temp, sizeof(temp));
            if  (temp.getrollno() < new_obj.getrollno())
                f_temp.write((char *) &temp, sizeof(temp));
            else
            {
                f_temp.write((char *) &new_obj, sizeof(new_obj));
                flag = 'y';
                break;
            }
        }
        
        if(flag == 'n')
            f_temp.write((char *) &new_obj, sizeof(new_obj));
        else if(!fio.eof())
        {
            while(fio)
            {
                fio.read((char *) &temp, sizeof(temp));
                f_temp.write((char *) &temp, sizeof(temp));
            }
        }
        
        fio.close();
        f_temp.close();
        
        remove("Database.dat");
        rename("temp.dat", "Database.dat");
    }
        
                

void delete_record(void)
    {   
        char flag = 'n';
        student temp;
        fstream fio, f_temp;
        fio.open("Database.dat", ios::app);
        f_temp.open("temp.dat", ios::out);
        
        int rno;
        cout << "\nEnter the roll no of student: ";
        cin >> rno; 
            
        
        while(fio)
        {
            fio.read((char *) &temp, sizeof(temp));
            if  (temp.getrollno() == rno)
            {
                cout << "\nThis record will be deleted: \n";
                temp.school::display();
                temp.display();
                flag = 'y';
            }
            else                    
                f_temp.write((char *) &temp, sizeof(temp));          
        }
        
        if(flag == 'n')
            cout << "\nSorry, Record not found!!!\n";
        
        fio.close();
        f_temp.close();
        
        remove("Database.dat");
        rename("temp.dat", "Database.dat");
    }


void modify_record(void)
    {   
        char flag = 'n';
        student temp;
        fstream fio;
        fio.open("Database.dat");
        
        int rno, pos;
        cout << "\nEnter the roll no of student: ";
        cin >> rno; 
            
        
        while(fio)
        {   
            pos = fio.tellg();
            fio.read((char *) &temp, sizeof(temp));
            if  (temp.getrollno() == rno)
            {
                cout << "\nThis record will be modified: \n";
                temp.school::display();
                temp.display();
                
                temp.input();
                temp.school::input();
                
                fio.seekg(pos);
                fio.write((char *) &temp, sizeof(temp));                          
                flag = 'y';
                break;
            }            
        }
        
        if(flag == 'n')
            cout << "\nSorry, Record not found!!!\n";
        
        fio.close();

    }        
               
        
        
void menu(void)
    {
        int option;
        cout << "\nMenu:\n";
        cout << "1. Search a Record" << endl;
        cout << "2. Append a Record" << endl;
        cout << "3. Insert a Record in sorted file" << endl;                
        cout << "4. Delete a Record" << endl;        
        cout << "5. MOdify a Record" << endl;    
        cout << "\nEnter the option number: ";
        cin >> option;
        char temp;
        cin.get(temp);
        
        switch(option)
        {
            case 1 :    search();
                        break;
            case 2 :    new_data();
                        break;
            case 3 :    insert_sorted();
                        break;
            case 4 :    delete_record();
                        break;
            case 5 :    modify_record();
                        break;
            default:    print_database();
                        break;
        }
    }

//////////////////////////////////////////////////////////////////
///////////////////////// Main Fn ////////////////////////////////
//////////////////////////////////////////////////////////////////    

int main()
    {
    
    new_data();
    
    menu();
    
    print_database();
    
    return 0;
    }        
    
