#include <iostream>
using namespace std;
#define MAX_N 1000001
#define DIV 1000000007
typedef long long ll;
ll tree[MAX_N * 4];
ll update_tree(int now, int target, int start, int end, int value)
{
   if (target > end || target < start)
      return tree[now];
   if (start == end)
      return tree[now] = value;
   int mid = (start + end) / 2;
   return tree[now] = (update_tree(now * 2, target, start, mid, value) * update_tree(now * 2 + 1, target, mid + 1, end, value)) % DIV;
}
ll query(int now, int left, int right, int start, int end)
{
   if (left > end || right < start)
      return 1;
   if (left <= start && end <= right)
      return tree[now];
   int mid = (start + end) / 2;
   return (query(now * 2, left, right, start, mid) * query(now * 2 + 1, left, right, mid + 1, end)) % DIV;
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int N, M, K;
   cin >> N >> M >> K;
   for (int i = 0; i < N; i++)
   {
      int data;
      cin >> data;
      update_tree(1, i, 0, N - 1, data);
   }
   for (int i = 0; i < M + K; i++)
   {
      int a, b, c;
      cin >> a >> b >> c;
      if (a == 1)
      {
         update_tree(1, b - 1, 0, N - 1, c);
      }
      else
      {
         cout << query(1, b - 1, c - 1, 0, N - 1) << "\n";
      }
   }
}
