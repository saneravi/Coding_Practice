#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

// structure for student details
struct Student
{
    int rollno;
    char name[10];    
    int marks[5];
    
    Student *link;                                      // to point to next link
    
};

// generate data for structure
void generate_data(Student *s)
{        
    time_t t;
    int t_value = time(&t);
    srand(t_value);
    
    s->rollno = rand()%10000;                           // generate random roll no    
    
    for(int i = 0; i < 9; ++i)
        s->name[i] = (char)(rand()%26 + 97);            // generate random name
    s->name[9] = '\0';
    
    for(int i = 0; i < 5; ++i)
        s->marks[i] = rand()%100;                       // generate random marks
        
    s->link = NULL;                                     // set link pointer to NULL  
}

Student *start, *last;                                  // to store start pointer and last pointer

// function to enter node in the beginning
void insert_beg(Student *new_one)
{
    Student *temp;
        
    if(start == NULL)                           // to check if the start pointer is empty
    {
        start = new_one;                        // then new pointer will be start pointer and link will remain NULL
        last = new_one;                         // This init of last is used to make insert_beg() and insert_end() in any order
    }
    else                                        
    {
        cout << "\nbefore start: " << start << "\tbefore start->link: " << start->link << "\tbefore new_one: " << new_one;
        cout << "\tbefore new_one->link: " << new_one->link; 
    
        temp = start;                           // else store the old start pointer value in the link of new pointer
        start = new_one;                        // and new pointer will be start pointer
        new_one->link = temp;
    }
    
    cout << "\nafter start: " << start << "\tafter start->link: " << start->link << "\tafter new_one: " << new_one;
    cout << "\tafter new_one->link: " << new_one->link; 
    
}

// function to enter node in the end
void insert_end(Student *new_one)
{    
    
    if(start == NULL)                           // to check if the start pointer is empty
    {
        start = new_one;                        // then new pointer will be start pointer and last pointer
        last = new_one;
    }
    else                                        
    {
        cout << "\nbefore start: " << start << "\tbefore start->link: " << start->link << "\tbefore last: " << last;
        cout << "\tbefore last->link: " << last->link;
        
        last->link = new_one;                   // old last pointer's link will point to new pointer
        last = new_one;                         // last pointer will be updated to new_pointer
    }
    
    cout << "\nafter start: " << start << "\tafter start->link: " << start->link << "\tafter last: " << last; 
    cout << "\tafter last->link: " << last->link;        
}

void bubble_sort(Student *now)
{
    cout << endl;
    Student *prev = start, *temp, *now2 = start;
    
    if(now == NULL)
        cout << "List is EMPTY!!!";
    
    for(now2 = start; now2!= NULL;)
    {
        for(now = start; now!= NULL;)
        {
            if (now->rollno < prev->rollno)
            {
                temp = now;
                temp->link = now->link;
                now = prev;
                now->link = prev->link;
                prev = temp;
                prev->link = temp->link;
            }
            prev = now;
            now = now->link;
        }
        now2 = now2->link;
    }
    
}
        
        


// display data function    
void print_data(Student *s)
{    
    cout << endl ;
    if(s == NULL)
        cout << "List is EMPTY!!!";
    
    while(s != NULL)                                                    // display data till s pointer is not NULL
    {   
        cout << endl << endl;
        cout << "Roll No:\t " << s->rollno << endl;
        cout << "Name:\t\t "; cout.write(s->name, 10); cout << endl;
        cout << "Marks:\t\t ";
        for(int i = 0; i < 5; ++i)
            cout << s->marks[i] << "\t";
            
        s = s->link;                                                    // update the value of from s to value stored in s->link
    }
}

int main()
{

// state start pointer as NULL
    start = NULL;
    cout << start;
    char ch;
            
    do
    {
        Student *newptr = new Student;                      // create new node
        
        if (newptr == NULL)                                 // check for memory error
        {
            cout << "\n\n\nMemory Full Error!!!\n\n\n";
            break;
        }
        
        generate_data(newptr);                              // generate data    
        cout << "\nNew Node Created.\n";
        
        char choice;
        cout << "\nEnter in the beginning or at end? (enter b or e): ";
        cin >> choice;
        
        if (choice == 'b' or choice == 'B')
        {
            cout << "Inserting new Node in the beginning.\n";
            insert_beg(newptr);                             // insert node in the beginning
        }
        else
        {
            cout << "Inserting new Node in the end.\n";
            insert_end(newptr);                             // insert node in the end
        }                
        
        cout << "\nNow the list is: \n";
        print_data(start);                                  // print data
        
        cout << "\n\nWant to enter new node?: ";
        cin >> ch;
    
    }while (ch == 'y' or ch == 'Y');
    
    bubble_sort(start);
    cout << "\nNow the list is: \n";
    print_data(start);
    
    
    cout << endl << endl;      
    return 0;    
}
