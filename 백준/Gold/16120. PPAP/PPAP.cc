#include <bits/stdc++.h>
using namespace std;

int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   string P;
   cin >> P;
   vector<char> V;
   if(P == "P")
   {
      cout << "PPAP";
      return 0;
   }
   if (P.size() <= 3)
   {
      cout << "NP";
      return 0;
   }
   for(int i=0;i<3;i++)
   {
      V.push_back(P[i]);
   }
   for (int i = 3; i < P.length(); i++)
   {
      char cur = P[i];
      string cmp;
      V.push_back(cur);
      if (cur == 'A')
      {
         continue;
      }
      for (int j = V.size()-4; j < V.size(); j++)
      {
         char curNum2 = V[j];
         cmp.push_back(V[j]);
         //cout << cmp << "\n";
         if (cmp == "PPAP")
         {
            for (int k = 0; k < 4; k++)
            {
               if (!V.empty())
               {
                  V.pop_back();
               }
            }
            V.push_back('P');
         }
      }
   }
   // int vsiz = V.size();
   // for (int i = 0; i < vsiz; i++)
   // {
   //    cout << V[i];
   // }
   if (V.size() == 1 && V.front() == 'P')
   {
      cout << "PPAP";
      return 0;
   }
   cout << "NP";
}