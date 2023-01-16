#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define MAX 501
#define INF 987654321
using namespace std;

int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int N;
   cin >> N;
   int weight[MAX];
   vector<int> E[MAX];
   int inputLink[MAX];
   int dist[MAX];
   queue<pair<int, int>> q; // 걸리는 시간 , nextNode
   memset(inputLink, 0, sizeof(inputLink));
   for (int i = 1; i <= N; i++)
   {
      int T;
      cin >> T;
      weight[i] = T;
      while (1)
      {
         int pre;
         cin >> pre;
         if (pre == -1)
         {
            break;
         }
         E[pre].push_back(i);
         inputLink[i]++;
      }
   }
   for (int i = 1; i <= N; i++)
   {
      dist[i] = INF;
   }
   for (int i = 1; i <= N; i++)
   {
      if (inputLink[i] == 0)
      {
         q.push({weight[i], i});
         dist[i] = weight[i];
      }
   }
   int mx[MAX]; // 노드로 들어오는 간선의 크기중 최대값
   memset(mx,0,sizeof(mx));
   while (!q.empty())
   {
      int curWeight = q.front().first;
      int curNode = q.front().second;
      q.pop();
      for (int i = 0; i < E[curNode].size(); i++)
      {
         int nextNode = E[curNode][i];
         int nextweight = curWeight + weight[nextNode];
         mx[nextNode] = max(nextweight,mx[nextNode]);
         inputLink[nextNode]--;
         if (inputLink[nextNode] == 0)
         {
            dist[nextNode] = mx[nextNode];
            q.push({mx[nextNode], nextNode});
         }
      }
   }
   
   for (int i = 1; i <= N; i++)
   {
      cout << dist[i] << "\n";
   }
}