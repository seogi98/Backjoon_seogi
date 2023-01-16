#include<bits/stdc++.h>
using namespace std;
#define MAX 1010
#define INF 9999999999999
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   long long minRoad[401][401]; //A에서 B까지 가는대 걸리는 최소거리
   long long N,M;
   cin >> N >> M;
   vector<pair<long long,long long>> E[MAX]; // 도로
   for(long long i=1;i<=N;i++)
   {
      for(long long j=1;j<=N;j++)
      {
         minRoad[i][j] = INF;
      }
   }
   for(long long i=0;i<M;i++)
   {
      long long node1 , node2, weight;
      cin >> node1 >> node2 >> weight;
      E[node1].push_back({node2,weight});
   }
   for(long long i=1;i<=N;i++)
   {
      long long start = i;
      priority_queue<pair<long long,long long>> pq;
      pq.push({0,i});
      while(!pq.empty())
      {
         long long curNode = pq.top().second;
         long long curDis = -pq.top().first;
         pq.pop();
         for(long long j=0;j<E[curNode].size();j++)
         {
            long long nextNode = E[curNode][j].first;
            long long nextDis = curDis + E[curNode][j].second;
            if(nextDis < minRoad[start][nextNode])
            {
               minRoad[start][nextNode] = nextDis;
               pq.push({-nextDis,nextNode});
            }
         }
      }
   }
   long long mn = INF;
   for(long long i=1;i<=N;i++)
   {
      for(long long j=1;j<=N;j++)
      {
         if(i==j)
         {
            continue;
         }
         mn = min(mn,minRoad[i][j]+minRoad[j][i]);
      }
   }
   if(mn == INF) {
      cout << -1;
      return 0;
   }
   cout << mn;
}