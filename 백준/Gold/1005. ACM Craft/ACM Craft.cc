#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#include <string.h>
#define MAX 1010
#define MMAX 100010
using namespace std;
int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int T;
   cin >> T;
   while (T--)
   {
      int N, K;
      cin >> N >> K;
      int D[MMAX]; //
      vector<int> V[MMAX];
      int inD[MAX];
      queue<int> q;
      int result[MAX]; // 해당 건물을 짓기 시작하는 데 걸리는 최소 시간
      int W;
      memset(inD, 0, sizeof(inD));
      memset(result,0,sizeof(result));
      memset(D,0,sizeof(D));
      for (int i = 1; i <= N; i++)
      {
         cin >> D[i]; // time
      }
      for(int i=0;i<K;i++)
      {
         V[i].clear();
      }
      for (int i = 1; i <= K; i++)
      {
         int node1, node2;
         cin >> node1 >> node2;
         V[node1].push_back(node2);
         inD[node2]++;
      }
      cin >> W;
      // 들어오는 간선의 갯수가 0 인
      //노드를 찾은후에 그중에 최대값을 전체 시간에 더한다.
      for (int i = 1; i <= N; i++)
      {
         int mx = 0;
         if (inD[i] == 0)
         {
            mx = max(mx, inD[i]); // 최대값
            q.push(i);      // queue에 i값 대입
         }
      }
      //이전노드에 현제노드 최대값
      while (!q.empty())
      {
         int popNode = q.front();
         q.pop();
         int mx=0;
         for(int i=0;i<V[popNode].size();i++)
         {
            int curNode = popNode;
            int nextNode= V[popNode][i];
            result[nextNode] = max(result[nextNode],result[curNode]+D[curNode]);
            inD[V[popNode][i]] --;
            if(inD[nextNode]==0)//들어오는 노드가 0인경우 
            {
               q.push(nextNode);//push
            }
         }
      }
      cout << result[W]+D[W] << "\n";
   }
}