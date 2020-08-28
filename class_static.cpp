#include <iostream>

using namespace std;
class Distance
    {   
        
        int feet, inches;
        
        public:
        static int count;
        void print() // function to display output GETTER
        {   
            count++; // to count the no of objects created        
            cout << feet << " feet " << inches << " inches " << endl;
            cout << "No of classes created = " << count << endl;
        }
        
        void getdata() // function to get data SETTER
        {
            cout << "Enter feet and inches: ";
            cin >> feet >> inches;
        }
        
        Distance sum(Distance); // function takes call by value mode object as input parameters and return output 
    };                                 // also call by value             
int Distance::count = 0;

Distance Distance::sum(Distance d2)   // function definition here d2 is an alias to n2
    {   
        Distance d3;
        d3.feet = feet + d2.feet + ((inches + d2.inches)/12);    // sum feet
        d3.inches = ((inches + d2.inches)%12);                   // sum inches
        return d3;                              // return object d2
    }
    

int main()
{
    // define 3 obj
    cout << "No of classes created = " << Distance::count << endl << endl; // init with 1
    Distance n1;
    n1.getdata();
    n1.print();    // count becomes 2

    cout << endl;

    Distance n2;
    n2.getdata();
    n2.print();    // count becomes 3

    cout << endl;

    Distance n3;
    n3 = n1.sum(n2); // output will have n3 = (n2 + n1)
    n3.print();    // count becomes 3
    /*
    cout << endl;
    n1.print();
    n2.print();
    n3.print();
    */
    cout << endl;    
    cout << "Total No of classes created = " << Distance::count << endl << endl; // 
    cout << endl << endl;
    
    return 0;
}



              
