#include <bits/stdc++.h>
using namespace std;
#define MAX 106
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int N, M;
   char mapp[MAX][MAX];
   pair<char, char> ds[10] =
       {{'.', '.'},
        {'O', 'O'},
        {'-', '|'},
        {'|', '-'},
        {'/', 92},
        {92, '/'},
        {'^', '<'},
        {'<', 'v'},
        {'v', '>'},
        {'>', '^'}};
   cin >> N >> M;

   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         cin >> mapp[i][j];
      }
   }

   for (int i = 0; i < M; i++)
   {
      for (int j = 0; j < N; j++)

      {
         for (int k = 0; k < 10; k++)
         {
            if (ds[k].first == mapp[j][M-1-i])
            {
               cout << ds[k].second;
            }
         }
      }
      cout << "\n";
   }
}