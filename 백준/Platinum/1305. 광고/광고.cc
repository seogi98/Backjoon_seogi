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
   int N;
   cin >> N;
   string S;
   cin >> S;
   vector<int> V;
   V = getPi(S);
   int lenS = S.length();
   int lenV = V.size();
   if(V[lenV-1] == 0 )
   {
      cout << N;
      return 0;
   }
   cout << lenS - V[lenV-1];
   return 0; 

}
