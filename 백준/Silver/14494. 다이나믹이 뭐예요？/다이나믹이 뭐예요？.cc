#include <iostream>
#include <vector>
#include <queue>
using namespace std;
long long dp[1001][1001];
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int N, M;
   cin >> N >> M;
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         if (i == 0 && j == 0)
         {
            dp[i][j] = 1;
            continue;
         }
         if (i == 0)
         {
            dp[i][j] = dp[i][j - 1];
            continue;
         }
         if (j == 0)
         {
            dp[i][j] = dp[i - 1][j];
            continue;
         }
         dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] + dp[i - 1][j - 1])%1000000007;
      }
   }
   cout << dp[N - 1][M - 1]%1000000007;
}