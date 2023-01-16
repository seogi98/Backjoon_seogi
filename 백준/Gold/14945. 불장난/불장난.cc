#include <bits/stdc++.h>
using namespace std;
#define MAX 106
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   long long dp[MAX][MAX]; //[타일 수][두 사람의 거리]
   //dp[now][dist] = dp[now-1][dist]*2 +dp[now-1][dist+1]+dp[now-1][dist-1]
   memset(dp,0,sizeof(dp));
   dp[2][1] = 2;
   int N;
   cin >> N;

   for(int i=3;i<=N;i++)
   {
      for(int j=1;j<i;j++)
      {
         if(j==1)
         {
            dp[i][j] = (dp[i-1][j]*2 + dp[i-1][j+1])%10007;
            continue;
         }
         dp[i][j] = (dp[i-1][j]*2 + dp[i-1][j+1] + dp[i-1][j-1])%10007;
      }
   }
   int result=0;
   for(int i=1;i<N;i++)
   {
      result+=dp[N][i];
      result=result%10007;
   }
   cout << result;
}