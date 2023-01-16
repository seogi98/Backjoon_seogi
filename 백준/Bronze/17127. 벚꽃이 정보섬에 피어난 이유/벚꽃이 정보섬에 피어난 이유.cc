#include <bits/stdc++.h>
using namespace std;
#define MAX 20

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   vector<int> V;
   cin >> N;
   for (int i = 0; i < N; i++)
   {
      int T;
      cin >> T;
      V.push_back(T);
   }
   int mx = 0;
   for (int i = 1; i < N-2; i++)
   {
      for (int j = i + 1; j < N-1; j++)
      {

         for (int k = j + 1; k < N; k++)
         {

               int ans=0;
               int tmp = 1;
               for (int o = 0; o < i; o++)
               {
                  tmp *= V[o];
               }
               ans += tmp;
               tmp = 1;
               for (int o = i; o < j; o++)
               {
                  tmp *= V[o];
               }
               ans += tmp;
               tmp = 1;
               for (int o = j; o < k; o++)
               {
                  tmp *= V[o];
               }
               ans += tmp;
               tmp = 1;
               for (int o = k; o < N; o++)
               {
                  tmp *= V[o];
               }
               ans +=tmp;
               mx = max(mx,ans);
         }
      }
   }
   cout << mx;
}