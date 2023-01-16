#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <string.h>
using namespace std;
long long dp[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int N, M;
int K;
bool map[101][101];
bool vst[101][101];
int mx = 0;
int num=1;
void dfs(int x, int y)
{
   //cout << y << "," << x << "\n";
   vst[y][x] = true;
   int tx, ty;
   for (int i = 0; i < 4; i++)
   {
      tx = x + dx[i];
      ty = y + dy[i];
      if (tx >= 1 && tx <= M && ty >= 1 && ty <= N)
      {
         if (!vst[ty][tx] && map[ty][tx])
         {
            num++;
            dfs(tx, ty);
         }
      }
   }
}
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   vector<pair<int, int>> V; // (y,x)
   memset(map, false, sizeof(map));
   memset(vst, false, sizeof(vst));
   cin >> N >> M >> K;
   for (int i = 0; i < K; i++)
   {
      int x, y;
      cin >> y >> x;
      map[y][x] = true;
   }

   for (int i = 1; i <= N; i++)
   {
      for (int j = 1; j <= M; j++)
      {
         if (!vst[i][j] && map[i][j])
         {
            dfs(j, i);
            mx =max(mx,num);
            num=1;
         }
      }
   }
   cout << mx;
}