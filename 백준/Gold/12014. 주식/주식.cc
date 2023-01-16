#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define MAX 2010
#define INF 0xffffff
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int T;
   cin >> T;
   for (int k = 1; k <= T; k++)
   {
      int N, K;
      cin >> N >> K;
      int stk[10001];
      int dp[10001];
      int mx = 1;
      
      for (int i = 1; i <= N; i++)
      {
         cin >> stk[i];
      }
      for (int i = 1; i <= N; i++)
      {
         dp[i] = 1;
         for (int j = i - 1; j > 0; j--)
         {
            if (stk[i] > stk[j])
            {
               dp[i] = max(dp[i], dp[j] + 1);
               mx = max(mx, dp[i]);
            }
         }
      }
      cout << "Case #" << k << "\n";
      mx >= K ? cout << 1 : cout << 0;
      cout << "\n";
   }
}