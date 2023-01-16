#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <stack>
#include <stdlib.h>
#include<string.h>
#define MAX 510
using namespace std;
//1~N, 1~N dfs로 탐색한다
//만약에 값이 있을경우  return map[i][j];
int N;
int map[MAX][MAX];
int dp[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int dfs(pair<int, int> p)
{
   int x = p.second;
   int y = p.first;
   if(dp[y][x])
   {
      return dp[y][x];
   }
   dp[y][x] =1;
   for (int i = 0; i < 4; i++)
   {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx > 0 && tx <= N && ty > 0 && ty <= N)
      {
         if(map[y][x] < map[ty][tx])
         {
            {
               dp[y][x] = max(dp[y][x],dfs({ty,tx})+1);
            }
         }
      }
   }
   return dp[y][x];
}
int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);

   cin >> N;
   for (int i = 1; i <= N; i++)
   {
      for (int j = 1; j <= N; j++)
      {
         cin >> map[i][j];
      }
   }
   memset(dp, 0, sizeof(dp));
   for(int i=1;i<=N;i++)
   {
      for(int j=1;j<=N;j++)
      {
         dfs({i,j});
      }
   }
   int mx=0;
   for(int i=1;i<=N;i++)
   {
      for(int j=1;j<=N;j++)
      {
         mx = max(dp[i][j],mx);
      }
   }
   cout << mx;
}
