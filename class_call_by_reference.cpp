#include <iostream>

using namespace std;
class Distance
    {
        int feet, inches;
        
        public:
        
        void print() // function to display output GETTER
        {
            cout << feet << " feet " << inches << " inches " << endl;
        }
        
        void getdata() // function to get data SETTER
        {
            cout << "Enter feet and inches: ";
            cin >> feet >> inches;
        }
        
        Distance &sum(Distance &); // function takes call by ref mode object as input parameters and return output 
    };                                 // also call by reference             

Distance &Distance::sum(Distance &d2)   // function definition here d2 is an alias to n2
    {
        d2.feet = feet + d2.feet + ((inches + d2.inches)/12);    // sum feet
        d2.inches = ((inches + d2.inches)%12);                   // sum inches
        return d2;                              // return object d2
    }
    

int main()
{
    Distance n1, n2, n3; // define 3 obj
    n1.getdata();
    n2.getdata();
    n3 = n1.sum(n2); // output will have n3 = n2 = (n2 + n1)
    
    cout << endl;
    n1.print();
    n2.print();
    n3.print();
    
    cout << endl << endl;
    
    return 0;
}



              
