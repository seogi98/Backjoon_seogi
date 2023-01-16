#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define MAX_LOG_K 20 // 2^20 1000000
#define MAX_N 500001 // MAX N
#define MAX 100001
using namespace std;
//위치 1. 정보 2. 전산 3. 미래 4. 신양 5. 한경직 6. 진리 7. 학생 8. 형남공학
//DP[위치][시간]
long long dp[10][MAX];
int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int D;
   cin >> D;
   dp[2][1] = 1;
   dp[3][1] = 1;
   for(int i=2;i<=D;i++)
   {
      dp[1][i] = (dp[2][i-1]+dp[3][i-1])%1000000007;
      dp[2][i] = (dp[1][i-1]+dp[4][i-1]+dp[3][i-1])%1000000007;
      dp[3][i] = (dp[1][i-1]+dp[4][i-1]+dp[5][i-1]+dp[2][i-1])%1000000007;
      dp[4][i] = (dp[6][i-1]+dp[5][i-1]+dp[3][i-1]+dp[2][i-1])%1000000007;
      dp[5][i] = (dp[3][i-1]+dp[4][i-1]+dp[6][i-1]+dp[8][i-1])%1000000007;
      dp[6][i] = (dp[5][i-1]+dp[4][i-1]+dp[7][i-1])%1000000007;
      dp[7][i] = (dp[6][i-1]+dp[8][i-1])%1000000007;
      dp[8][i] = (dp[7][i-1]+dp[5][i-1])%1000000007;
   }
   cout << dp[1][D];
}