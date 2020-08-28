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
    int tot_marks;
    
    int calc_tot(void)
    {   
        tot_marks = 0;
        for(int i = 0; i < 5; ++i)
            tot_marks += marks[i];
        return tot_marks;
    } 
};

// generate data
void generate_data(Student *s, int size)
{
// to generate random numbers        
    time_t t;
    int t_value = time(&t);
    srand(t_value);
    
    for(int j = 0; j < size; ++j)
    {
        s[j].rollno = rand()%10000;         // generate random roll no    
        
        for(int i = 0; i < 9; ++i)
            s[j].name[i] = (char)(rand()%26 + 97);     // generate random name
        s[j].name[9] = '\0';
        
        for(int i = 0; i < 5; ++i)
            s[j].marks[i] = rand()%100;     // generate random marks
        
        int temp = s[j].calc_tot();         // just to calc total marks, but never shown
    }
}

// function to bubble sort based on total marks
void bubble_sort(Student *s, int size)
{
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size - 1 - i; ++j)
            if(s[j].calc_tot() > s[j+1].calc_tot())
                swap(s[j], s[j+1]);
}

// display data function    
void print_data(Student *s, int size)
{
    cout << endl << endl;
    for(int j = 0; j < size; ++j)
    {
        cout << "Roll No:\t " << s[j].rollno << endl;
        cout << "Name:\t\t "; cout.write(s[j].name, 10); cout << endl;
        cout << "Marks:\t\t ";
        for(int i = 0; i < 5; ++i)
            cout << s[j].marks[i] << "\t";
        cout << "\nTotal Marks:\t " << s[j].tot_marks << endl << endl;
    }
}


int main()
{
//  create size number of students
    cout << "\nEnter size: ";
    int size;   cin >> size;
    Student *A = new Student[size];    
    
    generate_data(A, size);    
    print_data(A, size);

//  sort and display students data
    cout << "After Sorting" << endl << endl;
    
    bubble_sort(A, size);
    print_data(A, size);
    
    delete A;
    cout << endl << endl;      
    return 0;
    
}
