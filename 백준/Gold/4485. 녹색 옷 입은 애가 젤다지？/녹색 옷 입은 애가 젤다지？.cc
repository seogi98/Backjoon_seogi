#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define MAX 200
#define INF 987654321
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int P = 1;
// cost y x
int main(void)
{
   while (1)
   {
       cin.tie(NULL);
       ios::sync_with_stdio(false);
      int map[200][200];
      bool vst[200][200];
     int dist[MAX][MAX];
      priority_queue<pair<int, pair<int, int>>> pq;
      memset(map, 0, sizeof(map));
      memset(vst, false, sizeof(vst));
      int N;
      cin >> N;
      if (N == 0)
      {
         break;
      }
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
         {
            dist[i][j] = INF;
         }
      }
      for (int i = 0; i < N; i++)
      {
         for (int j = 0; j < N; j++)
         {
            cin >> map[i][j];
         }
      }
      pq.push({-map[0][0], {0, 0}});
      vst[0][0] = true;
      while (!pq.empty())
      {
         int total = -pq.top().first;
         int y = pq.top().second.first;
         int x = pq.top().second.second;
         pq.pop();
         for (int i = 0; i < 4; i++)
         {
            int tx = x + dx[i];
            int ty = y + dy[i];
            int nextWeight = total + map[ty][tx];
            if (tx >= 0 && tx < N && ty >= 0 && ty < N)
            {
                  if (dist[ty][tx] > nextWeight)
                  {
                     dist[ty][tx] = nextWeight;
                     vst[ty][tx] = true;
                     pq.push({-(map[ty][tx] + total), {ty, tx}});
                  }
            }
         }
      }
      cout << "Problem " << P << ": " << dist[N - 1][N - 1] << "\n";
      P++;
   }
}