#include <iostream>
#include <string.h>
using namespace std;

class abc
{   
    public:
    int roll;
    char name[15];
    int marks[3];
    
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
        for(int i = 0; i< 3; i++){
        cout << "Enter marks: " << endl;
        cin >> marks[i];}
        cout << endl;
    }
    private:
    void display(void)
    {
        cout << endl << "Roll No: " << roll << endl << "Name: ";
        cout.write(name, strlen(name));
        for(int i = 0; i< 3; i++){
        cout << endl << "Marks: " << marks[i];}
    }
};


int main()
{   

    cout << endl << endl; 

    abc s[3] = {{1, "ravi", {100, 200, 300}}, {2, "ra", {4, 40, 400}}, {3, "avi", {9, 90, 900}}};
//    s.display();
    s[0].p();
    s[1].p();            
    s[2].p();    
    cout << endl << endl; 
    cout << s[1].marks[0];
    return 0;
}



              
