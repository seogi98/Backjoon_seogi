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
int length = 0;
int mx = 0;
int check = 0;
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int A, B, N; // 상훈,지수,손님수
   cin >> A >> B >> N;
   // 주문시각,색깔,선물개수
   int t;
   char c;
   int m;
   queue<int> b;
   queue<int> r;
   for (int i = 0; i < N; i++)
   {
      cin >> t >> c >> m;
      if (c == 'R')
      {
         for (int j = 1; j <= m; j++)
         {
            int mx = r.size()+b.size();
            r.push(mx+1);
         }
      }
      else if (c == 'B')
      {
         for (int j = 1; j <= m; j++)
         {
            int mx = r.size()+b.size();
            b.push(mx+1);
         }
      }
   }
   cout << b.size() << "\n";
   while(!b.empty())
   {
      cout << b.front() << " ";
      b.pop();
   }
   cout << "\n";
   cout << r.size() << "\n";
   while(!r.empty())
   {
      cout << r.front() << " ";
      r.pop();
   }

}