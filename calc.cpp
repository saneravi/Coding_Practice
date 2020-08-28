#include <iostream>
using namespace std;

int main()
{
float n1, n2, result;
char ch;
do
	{
	again2:
	cout<<"\n\nEnter two numbers:\n";
	cin>>n1>>n2;
	
	again:
	cout<<"\nEnter the operation(+, -, *, /, %) : ";
	cin>>ch;
	
	switch(ch)
	    {
	    case '+' :  result = n1 + n2; break;
	    case '-' :  result = n1 - n2; break;
	    case '*' :  result = n1 * n2; break;
	    case '/' :  if (n2)
	                {
	                    result = n1 / n2; 
	                    break;
	                    }
                    else
                    {
                        cout<<"\nDivide by zero error!!!\n\n";
                        goto again2;
                        ;
                        }
	    case '%' :  if (n2)
	                {
	                    result = (int)n1 % (int)n2; 
	                    break;
	                    }
                    else
                    {
                        cout<<"\nDivide by zero error!!!\n\n";
                        goto again2;
                        ;
                        }
	    default  :  cout<<"\nYou have entered wrong character!!!\n\n";
	                goto again;
	                break;
	    }
    cout<<"\n\n"<<result<<"\n";
    again3:
    cout<<"\nWanna calculate more?(y/n) :";
    char in;
    cin>>in;
    if(in == 'y' or in =='Y')
        continue;
    else if(in == 'n' or in =='N')
        break;
    else
        {
        cout<<"\nWrong character entered!!! \n";
        goto again3;;
        }
    }while(1);

return 0;
}
    
	    
	
