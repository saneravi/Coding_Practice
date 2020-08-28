#include <iostream>

using namespace std;


int main()
{   
    int a[2][3][4] = {{{10, 20, 30, 35}, {40, 50, 60, 65}, {70, 80, 90, 95}}, {{100, 200, 300, 305}, {400, 500, 600, 605}, {700, 800, 900, 905}}};
    
    //cout << &a << "\t" << &a+1 << "\t" << &a+2 << endl;
    
    
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 3; ++j){
            for(int k = 0; k < 4; ++k){
                cout << a[i][j][k] << "\t" << (&a[i][j][k] - &a[0][0][0]) << "\t\t";}
            cout << endl;}
        cout << endl << endl;}  
    return 0;
    
}
