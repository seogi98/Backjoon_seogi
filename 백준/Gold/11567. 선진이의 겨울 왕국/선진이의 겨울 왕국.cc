#include <bits/stdc++.h>
using namespace std;
#define MAX 501
#define INF 0xfffffffe
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
char mapp[MAX][MAX];
bool vst[MAX][MAX];
int N, M;
pair<int, int> st, ed;
bool isEsc=false;
bool isEnd=false;
void dfs(pair<int, int> cur)
{
   int x = cur.second;
   int y = cur.first;
   vst[y][x] = true;
   if(isEsc && isEnd)
   {
      return;
   }
   if (x == ed.second && y == ed.first)
   {
      int ex = ed.second;
      int ey = ed.first;
      if (mapp[ey][ex] == '.')
      {
         for (int i = 0; i < 4; i++)
         {
            int edx = ex + dx[i];
            int edy = ey + dy[i];
            if (edx > 0 && edx <= M && edy > 0 && edy <= N && !vst[edy][edx] && mapp[edy][edx] == '.')
            {
               isEnd =true;
               isEsc = true;
               return;
            }
         }
      }
      else
      {
         isEnd =true;
         isEsc = true;
      }
      return;
   }
   for (int i = 0; i < 4; i++)
   {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (tx > 0 && tx <= M && ty > 0 && ty <= N)
      {
         if (mapp[ty][tx] == '.' && !vst[ty][tx])
         {
            vst[ty][tx] = true;
            dfs({ty,tx});
            vst[ty][tx] = false;
         }
         if (mapp[ty][tx] == 'X' && ty == ed.first && tx == ed.second)
         {
            dfs({ty, tx});
         }
      }
   }
}
int main(void)
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   cin >> N >> M;

   memset(vst, false, sizeof(vst));
   for (int i = 1; i <= N; i++)
   {
      for (int j = 1; j <= M; j++)
      {
         cin >> mapp[i][j];
      }
   }
   cin >> st.first >> st.second;
   cin >> ed.first >> ed.second;
   if (st.first == ed.first && st.second == ed.second)
   {
      mapp[st.first][st.second] = '.';
   }
   dfs({st.first,st.second});
   isEsc?cout << "YES" :cout << "NO";
}