#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define MAX 2010
#define INF 0xffffff
//A --> C  == A -> G -> H -> C or A -> H -> G -> C랑 같으면 참

bool cmp(int p1,int p2)
{
   return p1 < p2;
}
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int T;
   cin >> T;
   while (T--)
   {
      int N, M, T;
      int S, G, H;
      cin >> N >> M >> T; // 도로,교차로,목적지 후보 갯수
      cin >> S >> G >> H; // 출발지 , G H 사이 교차로 지남
      vector<pair<int, int>> E[MAX];
      int dist[MAX][3];                  //출발지에서 중간 S G H
      vector<int> candi;
      for (int i = 1; i < MAX; i++)
      {
         for (int j = 0; j < 3; j++)
         {
            dist[i][j] = INF;
         }
      }
      for (int i = 1; i <= M; i++)
      {
         int node1, node2, weight;
         cin >> node1 >> node2 >> weight;
         E[node1].push_back({node2, weight});
         E[node2].push_back({node1, weight});
      }
      for (int i = 0; i < T; i++)
      {
         int tmp;
         cin >> tmp;
         candi.push_back(tmp);
      }
      sort(candi.begin(),candi.end(),cmp);
      for (int j = 0; j < 3; j++)
      {
         priority_queue<pair<int, int>> pq; //거리 , 현재노드
         int start=0;
         if(j==0)start=S;
         else if(j==1)start=G;
         else if(j==2)start=H;
         pq.push({0, start});
         dist[start][j] = 0;
         while (!pq.empty())
         {
            int curNode = pq.top().second;
            int weight = -pq.top().first;
            pq.pop();
            for (int i = 0; i < E[curNode].size(); i++)
            {
               int nextNode = E[curNode][i].first;
               int nextWeight = E[curNode][i].second + weight;
               if (dist[nextNode][j] > nextWeight)
               {
                  dist[nextNode][j] = nextWeight;
                  pq.push({-nextWeight, nextNode});
               }
            }
         }
      }
      for(int i=0;i<T;i++)
      {
         int dest = candi[i]; // 목적지
         int stToDest = dist[dest][0];
         int stToMid = min(dist[G][0] + dist[H][1]+dist[dest][2],dist[H][0] + dist[G][2]+dist[dest][1]);
         if(stToDest == stToMid)
         {
            cout << dest << " ";
         }
      }
      cout << "\n";
   }
}