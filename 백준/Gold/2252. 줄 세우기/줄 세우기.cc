#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string.h>

#define MAX 100001

using namespace std;

vector<int> V[MAX];
queue<int> q;
vector<int> ans;
int indegree[MAX];
int N, M;
void find_zero()
{
   for (int i = 1; i <= N; i++)
   {
      if (indegree[i] == 0)
      {
         q.push(i);
      }
   }
}
int main(void)
{
   cin >> N >> M;
   memset(indegree, 0, sizeof(indegree));
   for (int i = 0; i < M; i++)
   {
      int node1, node2;
      cin >> node1 >> node2;
      V[node1].push_back(node2);
      indegree[node2]++;
   }
   find_zero();
   while (!q.empty())
   {
      int popNode = q.front();
      for (int i = 0; i < V[popNode].size(); i++)
      {
         indegree[V[popNode][i]]--;
         if(indegree[V[popNode][i]]==0)
         {
            q.push(V[popNode][i]);
         }
      }
      ans.push_back(popNode);
      q.pop();
   }
   for(int i=0;i<ans.size();i++)
   {
      cout << ans[i] << " ";
   }
}