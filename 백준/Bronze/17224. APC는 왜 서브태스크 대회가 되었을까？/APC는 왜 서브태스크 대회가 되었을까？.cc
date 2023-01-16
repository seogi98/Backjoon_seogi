#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define MAX 501
#define INF 987654321
using namespace std;

vector<pair<int, int>> V;

int N, L, K;
int length=0;
int mx = 0;
int check=0;
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   cin >> N >> L >> K;
   int ans=0;
   for (int i = 0; i < N; i++)
   {
      int node1, node2;
      cin >> node1 >> node2;
      if(length > K)
      {
         break;
      }
      if(node1 <= L && node2 <= L)
      {
         ans +=140;
         length++;
         continue;
      }
      if(node1 <= L && node2 > L)
      {
         check ++;
         continue;
      }
   }
   for(int i=0;i<K-length;i++)
   {
      if(check <= i)
      {
         break;
      }
      ans+=100;
   }
   cout << ans;
}