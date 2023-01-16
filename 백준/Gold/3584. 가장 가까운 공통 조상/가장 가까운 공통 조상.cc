#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#include <string.h>
#define MAX 10001
using namespace std;
int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int T;
   cin >> T;
   while (T--)
   {
      vector<int> tree[MAX];
      int N;
      cin >> N;
      int fn, sn;
      for (int i = 0; i < N - 1; i++)
      {
         int node1, node2;
         cin >> node1 >> node2;
         tree[node2].push_back(node1);
      }
      cin >> fn >> sn;
      bool isEx[MAX];
      memset(isEx, false, sizeof(isEx));
      int curNode = fn;
      while (1)
      {
         if(tree[curNode].empty())
         {
            isEx[curNode] = true;
            break;
         }
         isEx[curNode] = true;
         curNode = tree[curNode][0];
      }
      curNode = sn;
      while (1)
      {
         if(tree[curNode].empty())
         {
            cout << curNode << "\n";
            break;
         }
         isEx[curNode] = true;
         curNode = tree[curNode][0];
         if (isEx[curNode] == true)
         {
            cout << curNode << "\n";
            break;
         }
      }
   }
}