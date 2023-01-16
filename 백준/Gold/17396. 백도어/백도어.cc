#include <bits/stdc++.h>
using namespace std;
#define MAX 300100
#define INF 98765432199999

bool isWard[MAX];
vector<pair<long long, long long>> E[MAX];
long long dist[MAX];
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   long long N, M; // 분기점 , 길의수
   cin >> N >> M;
   for (long long i = 0; i < N; i++)
   {
      cin >> isWard[i];
      dist[i] = INF;
   }
   isWard[N - 1] = false;
   for (long long j = 0; j < M; j++)
   {
      long long node1, node2, weight;
      cin >> node1 >> node2 >> weight;
      if(isWard[node1]||isWard[node2])
      {
         continue;
      }
      E[node1].push_back({node2, weight});
      E[node2].push_back({node1, weight});
   }
   dist[0] = 0;
   priority_queue<pair<long long, long long>> pq;
   pq.push({0, 0});
   if(isWard[0])
   {
      cout << "-1";
      return 0;
   }
   while (!pq.empty())
   {
      long long curWeight = -pq.top().first;
      long long curNode = pq.top().second;
      pq.pop();
      if(dist[curNode] < curWeight)
      {
         continue;
      }
      for (long long i = 0; i < E[curNode].size(); i++)
      {
         long long nextNode = E[curNode][i].first;
         long long nextWeight = E[curNode][i].second + curWeight;
         if (dist[nextNode] > nextWeight && dist[curNode]!=INF)
         {

            dist[nextNode] = nextWeight;
            pq.push({-nextWeight,  nextNode});
         }
      }
   }
   if (dist[N - 1] == INF)
   {
      cout << "-1";
      return 0;
   }
   cout << dist[N - 1];
}