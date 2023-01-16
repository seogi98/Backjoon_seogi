#include <bits/stdc++.h>
using namespace std;
#define MAX 10001
bool vst[MAX];
int v, e;
int start;
vector<int> fw[MAX]; // 정방향
vector<int> rv[MAX]; // 역방향
stack<int> st; // 정점 stack
priority_queue<int, vector<int>, greater<int>> pq;
vector<priority_queue<int, vector<int>, greater<int>>> Vpq;
void dfsFw(int cur)
{
   vst[cur] = true;
   for (int i = 0; i < fw[cur].size(); i++)
   {
      int nextNode = fw[cur][i];
      if (!vst[nextNode])
      {
         dfsFw(nextNode);
      }
   }
   st.push(cur);
}
void dfsRv(int cur)
{
   vst[cur] = true;
   pq.push(cur);
   for (int i = 0; i < rv[cur].size(); i++)
   {
      int nextNode = rv[cur][i];
      if (!vst[nextNode])
      {
         dfsRv(nextNode);
      }
   }
}
bool cmp (priority_queue<int, vector<int>, greater<int>> pq1 ,priority_queue<int, vector<int>, greater<int>> pq2)
{
   return pq1.top() < pq2.top();
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   memset(vst, false, sizeof(vst));
   cin >> v >> e;
   for (int i = 0; i < e; i++)
   {
      int node1, node2;
      cin >> node1 >> node2;
      if (i == 0)
      {
         start = node1;
      }
      fw[node1].push_back(node2);
      rv[node2].push_back(node1);
   }
   for (int i = 1; i <= v; i++)
   {
      if (!vst[i])
      {
         dfsFw(i);
      }
   }
   memset(vst, false, sizeof(vst));
   while (!st.empty())
   {
      priority_queue<int, vector<int>, greater<int>> tmpQ;
      pq = tmpQ;
      if (vst[st.top()])
      {
         st.pop();
         continue;
      }
      if (!vst[st.top()])
      {
         dfsRv(st.top());
      }
      Vpq.push_back(pq);
   }
   cout << Vpq.size() << "\n";
   sort(Vpq.begin(),Vpq.end(),cmp);
   for(int i=0;i<Vpq.size();i++)
   {
      while(!Vpq[i].empty())
      {
         cout << Vpq[i].top() << " ";
         Vpq[i].pop();
      }
      cout << "-1\n";
   }
}