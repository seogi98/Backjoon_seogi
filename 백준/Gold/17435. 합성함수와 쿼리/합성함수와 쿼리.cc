#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
#define MAX_LOG_K 20 // 2^20 1000000
#define MAX_N 500001 // MAX N
#define MAX 200001
using namespace std;
int nxt[MAX];
int table[MAX_LOG_K + 1][MAX_N + 1]; //  table[k][v] v에서 2^k번 진행했을때 도달하는 지점
int main(void)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int N;
   cin >> N;
   for (int i = 1; i <= N; i++)
   {
      cin >> nxt[i];
   }
   //한칸씩 전진하는 경우 체우기
   for (int i = 1; i <= N; i++)
   {
      table[0][i] = nxt[i];
   }
   //K를 1씩 키워나가기
   for (int i = 1; i <= MAX_LOG_K; i++)
   {
      for (int j = 1; j <= N; j++)
      {
         int tmp = table[i - 1][j];       // 중간에 참조하는 노드
         table[i][j] = table[i - 1][tmp]; // 중간 노드에서 2^(i-1)만큼 이동한다.
      }
   }
   int M;
   cin >> M;
   for (int i = 0; i <M; i++)
   {
      int n, x;
      cin >> n >> x;
      for (int j = 0; j <= MAX_LOG_K; j++)
      {
         if (n & (1 << j))
         {
            x = table[j][x]; //만약에 같으면 이동
         }
      }
      cout << x << "\n";
   }
}