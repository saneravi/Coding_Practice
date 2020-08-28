#include <iostream>
using namespace std;
#include <string.h>

class Player
{
    char f_name[15], l_name[15];
    int runs, sixes, fours;
    float strike_rate;
    
    public:
        Player():f_name("___"), l_name("___")
        {
            cout << "Player created" << endl;
            runs = 0;
            sixes = 0;
            fours = 0;
            strike_rate = 0.0;
        }
        
        ~Player()
        {
            cout << "Player deleted" << endl;
        }
        
        void input()
        {   char ch;
            cin.get(ch);
            cout << "\nEnter First Name: ";
            cin.getline(f_name, 15);
            cout << "\nEnter Second Name: ";            
            cin.getline(l_name, 15);            
            cout << "\nEnter Runs: ";
            cin >> runs;
            cout << "\nEnter Sixes: ";
            cin >> sixes;
            cout << "\nEnter Fours: ";                        
            cin >> fours;
            cout << "\nEnter Strike Rate: ";
            cin >> strike_rate;     
        }
        
        char *getname()
        {   return strcat(strcat(f_name, " ") , l_name); }
        
        int getruns()
        {   return runs; }
        
        int getsixes()
        {   return sixes; }
        
        int getfours()
        {   return fours; }
        
        float getsrate()
        {   return strike_rate; }
        
        void display()
        {
            char *ch = getname();
            cout << "\nName: ";
            cout.write(ch, strlen(ch));
            cout << "\nRuns: " << runs;
            cout << "\nSixes: " << sixes;
            cout << "\nFours: " << fours;                        
            cout << "\nStrike Rate: " << strike_rate;
        }
};    

        
int main()
{
    cout << "Enter size: ";
    int size;
    cin >> size;
    
    Player *obj = new Player[size];
    
    for(Player *ptr = obj; ptr < &obj[size]; ptr++)
        ptr->input();
    
    Player *mom;
    int max_runs = 0;
    for(Player *ptr = obj; ptr < &obj[size]; ptr++)
    {
        if (ptr->getruns() > max_runs)
        {
            mom = ptr;
            max_runs = ptr->getruns();
        }
    }
    
    cout << "\n\nMan of the Match: \n";
    mom->display();
            
    cout << "\n";
    //delete obj;    
    return 0;
    
}
