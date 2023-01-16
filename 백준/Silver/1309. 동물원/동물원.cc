#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define MAX_LOG_K 20 // 2^20 1000000
#define MAX_N 500001 // MAX N
#define MAX 200001
using namespace std;
long long dp[MAX][3]; // [세로][왼,오,없]
int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   cin >> N;
   dp[1][0] = 1;
   dp[1][1] = 1;
   dp[1][2] = 1;
   for (int i = 2; i <= N; i++)
   {
      //왼쪽에 있을경우
      dp[i][0] = (dp[i-1][1] +dp[i-1][2])%9901;
      //오른쪽에 있을경우
      dp[i][1] = (dp[i-1][0] + dp[i-1][2])%9901;
      //둘다 없을경우
      dp[i][2] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2])%9901;
   }
   cout << (dp[N][0]+dp[N][1]+dp[N][2])%9901;
}