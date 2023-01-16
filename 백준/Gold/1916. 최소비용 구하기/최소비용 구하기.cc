#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <vector>
using namespace std;
#define MAX 1001
#define MMAX  987654321
int N,M;
vector<pair<int,int>> E[MAX];
int dist[MAX];
int main(void)
{
   cin >> N >> M;
   for(int i=1;i<=N;i++)
   {
      dist[i] = MMAX;
   }
   for(int i=0;i<M;i++)
   {
      int node1,node2,weight;
      cin >> node1 >> node2 >> weight;
      E[node1].push_back({node2,weight});
   }
   int start,end;
   cin >> start >> end;
   dist[start] =0;
   priority_queue<pair<int,int>> pq; // cost , curNode
   pq.push({0,start});
   while(!pq.empty())
   {
      int cost = -pq.top().first;
      int curNode = pq.top().second;
      pq.pop();
      if(dist[curNode] < cost)
      {
         continue;
      }
      for(int i=0;i<E[curNode].size();i++)
      {
         int nextNode = E[curNode][i].first;
         int nextCost = E[curNode][i].second+cost;
         if(dist[nextNode] > nextCost)
         {
            dist[nextNode] = nextCost;
            pq.push({-nextCost,nextNode});
         }

      }
   }
   // for(int i=1;i<=N;i++)
   // {
   //    cout << dist[i] << "\n";
   // }
   cout << dist[end];

   
}