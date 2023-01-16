#include <bits/stdc++.h>
using namespace std;
// 톨레미의 정리에 따르면 다음과 같이
// 원에 내접한 사각형은 마주 보는 두 쌍의 변의 곱의 합이 두 대각선의 곱과 같다.

string wl[1000];
string st[1000];
bool cmp(string a, string b)
{
   if(a[0] != b[0])
   {
      return a<b;
   }
   else
   {
      if(a.length() == b.length())
      {
         return a<b;
      }
      else
      {
         return a.length()<b.length()?true:false;
      }
      
   }
   
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int T, N;
   cin >> T;
   N = T * 5;
   for (int i = 0; i < N; i++)
   {
      cin >> wl[i];
      st[i] = wl[i];
   }
   sort(st, st + N, cmp);
   stack<string> S;
   int j = 0;                  // st 인덱스
   for (int i = 0; i < N; i++) //wl 인덱스
   {
      string stJ = st[j];
      string wlI = wl[i];
      if (st[j] == wl[i])
      {
         j++;
         continue;
      }
      if (st[j] != wl[i])
      {
         if (!S.empty())
         {
            if (st[j] == S.top())
            {
               S.pop();
               j++;
               i--;
               continue;
            } 
         }
         S.push(wl[i]);
         continue;
      }
   }
   if(!S.empty())
   {
      if(st[j] != S.top())
      {
         cout << "BAD";
         return 0;
      }
      S.pop();
      j++;

   }
   cout << "GOOD";

}