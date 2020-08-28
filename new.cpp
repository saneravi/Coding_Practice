#include <bits/stdc++.h>
using namespace std;

void seed_random(void)
{
    time_t t;
    int t_val = time(&t);
    srand(t_val);    
}

void solve() 
{ 

   vector < vector <int> > A;
   for(int i=0,k=0;i<5; i++){
      vector <int> v;
      for(int j=0;j<5; j++,k++)
         v.push_back(k);
      A.push_back(v);
   }

   int m=A.size();
   int n=A[0].size();

   vector <int> B;

   int cmax=n, cmin=0, rmax=m, rmin=1, i=0, j=0;
   while(cmax>cmin && rmax>rmin)
   {
      while(j++ < cmax)
         B.push_back(A[i][j]);
      cmax--;j--;
      while(i++ < rmax)
         B.push_back(A[i][j]);
      rmax--;i--;
      while(j-- >= cmin)
         B.push_back(A[i][j]);
      cmin++;j++;
      while(i-- >= rmin)
         B.push_back(A[i][j]);
      rmin++;i++;
   }

   for(int j=0;j<m*n; j++)
      cout << B[j] << " , ";

} 
int main()
{      
    seed_random();    
    auto begin = chrono::high_resolution_clock::now();    
    // code starts here   
    
    
    solve();       
    
    // code ends here   
    auto end = chrono::high_resolution_clock::now();
    cout <<endl<<"Runtime: " << (float)(chrono::duration_cast <chrono::nanoseconds> (end-begin).count())/1000 << "us" << endl;
    
    return 0;
    }
   
