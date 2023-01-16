#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#include <string.h>
#define MAX 32010
#define MMAX 100001
using namespace std;
int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int N; // 문제 수
   int M; // 정보 수
   priority_queue<int, vector<int>,greater<int>> pq;
   cin >> N >> M;
   vector<int> V[MAX];
   int inD[MAX];
   memset(inD, 0, sizeof(inD));
   for (int i = 1; i <= M; i++)
   {
      int node1, node2;
      cin >> node1 >> node2;
      V[node1].push_back(node2);
      inD[node2]++;
   }
   for (int i = 1; i <= N; i++)
   {
      if (inD[i] == 0)
      {
         pq.push(i);
      }
   }
   while (!pq.empty())
   {
      int popNode = pq.top();
      cout << pq.top() << " ";
      pq.pop();
      for (int i = 0; i < V[popNode].size(); i++)
      {
         int nextNode = V[popNode][i];
         inD[nextNode]--;
         if (inD[nextNode] == 0)
         {
            pq.push(nextNode);
         }
      }
   }
}