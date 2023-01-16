#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001
#define MMAX 987654321
int N, M;
vector<pair<int, int>> E[MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool vst[MAX][MAX]; //
char map[101][101];
int bk;
int y,x;
int ty,tx;
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   cin >> M >> N;

   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         cin >> map[i][j];
      }
   }
   memset(vst, false, sizeof(vst));
   priority_queue<pair<short, pair<short, short>>> pq; // 부순 벽의 숫자 , (y,x)
   pq.push({0, {0, 0}});
   while (!pq.empty())
   {
      bk = -pq.top().first;
      y = pq.top().second.first;
      x = pq.top().second.second;
      vst[y][x] = true;
      pq.pop();
      if (y == N - 1 && x == M - 1)
      {
         cout << bk;
         return 0;
      }
      for (int i = 0; i < 4; i++)
      {
         tx = x + dx[i];
         ty = y + dy[i];
         if (tx >= 0 && tx < M && ty >= 0 && ty < N)
         {
            if (!vst[ty][tx])
            {

               if (map[ty][tx] == '0')
               {
                  vst[ty][tx] = true;
                  pq.push({-bk, {ty, tx}});
               }
               if (map[ty][tx] == '1')
               {
                  vst[ty][tx] = true;
                  pq.push({-bk - 1, {ty, tx}});
               }
            }
         }
      }
   }
}