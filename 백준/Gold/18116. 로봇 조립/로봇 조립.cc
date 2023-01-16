#include <bits/stdc++.h>
#include <algorithm>
#define MAXX 1000100
using namespace std;
int P[MAXX];
int union_find(const int &curNode)
{
   if (P[curNode] < 0)
   {
      return curNode;
   }
   return P[curNode] = union_find(P[curNode]);
}
int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int T;
   memset(P, -1, sizeof(P));
   cin >> T;
   int node1P, node2P;
   int ans;
   char op;
   int node1, node2;
   for (int i = 0; i < T; i++)
   {
      cin >> op;
      if (op == 'I')
      {
         cin >> node1 >> node2;
         node1P = union_find(node1);
         node2P = union_find(node2);
         if(node1P == node2P) {continue;}
         P[node1P] += P[node2P];
         P[node2P] = node1;
      }
      if (op == 'Q')
      {
         cin >> ans;
         cout << -P[union_find(ans)] << "\n";
      }
   }
}
