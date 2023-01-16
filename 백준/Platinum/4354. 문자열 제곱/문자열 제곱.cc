#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include<algorithm>
using namespace std;

vector<int> getPi(string p)
{
   int m = (int)p.size();
   int j = 0;
   vector<int> pi(m, 0);
   for (int i = 1; i < m; i++)
   {
      while (j > 0 && p[i] != p[j])
         j = pi[j - 1];
      if (p[i] == p[j])
         pi[i] = ++j;
   }
   return pi;
}
int main()
{
   string S;
   while (1)
   {
      vector<int> V;
      getline(cin,S);
      if(S == ".")
      {
         break;
      }
      V = getPi(S);
      int N = S.length();
      int q = V[N-1];
      int r = N-q;

      if(q==0|| q%r !=0)
      {
         cout <<1<<"\n";
         continue;
      }
      cout <<q / r+1 << "\n";
   }
   return 0;
}
