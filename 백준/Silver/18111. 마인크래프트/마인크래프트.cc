#include <bits/stdc++.h>
#include <algorithm>
#define MAXX 700
#define MAX 99999999999
using namespace std;
long long mp[MAXX][MAXX];
long long N, M, B;
long long calc(long long key)
{
   long long result = 0;
   long long pos = B;
   for (long long i = 0; i < N; i++)
   {
      for (long long j = 0; j < M; j++)
      {
         //땅을 파는경우
         long long diff = key - mp[i][j];
         if (diff < 0)
         {
            result -= (2 * diff);
            pos -= diff;
         }
      }
   }
   for (long long i = 0; i < N; i++)
   {
      for (long long j = 0; j < M; j++)
      {
         long long diff = key - mp[i][j];
         if (diff > 0)
         {
            //블록을 놓는경우
            result += diff;
            pos -= diff;
            if (pos < 0)
               return -1;
         }
      }
   }

   return result;
}
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   cin >> N >> M >> B;

   long long mn = MAX;
   long long mx = 0;
   for (long long i = 0; i < N; i++)
   {
      for (long long j = 0; j < M; j++)
      {
         cin >> mp[i][j]; /* code */
         mx = max(mp[i][j], mx);
         mn = min(mp[i][j], mn);
      }
   }
   long long mnn = MAX;
   long long h = 0;
   for (long long i = mn; i <= mx; i++)
   {
      if (calc(i) < 0)
      {
         continue;
      }
      if (mnn >= calc(i))
      {
         mnn = calc(i);
         h = i;
      }
   }
   cout << mnn << " " << h;
}
