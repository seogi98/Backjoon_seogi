#include <bits/stdc++.h>
using namespace std;
#define MAX 3001

char mapp[MAX][MAX];
bool vst[MAX][MAX];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int N, M;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> N >> M;
   pair<int, int> startPoint;
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         cin >> mapp[i][j];
         vst[i][j] = false;
         if (mapp[i][j] == '2')
         {
            startPoint.first = i;
            startPoint.second = j;
         }
      }
   }
   queue<pair<int,pair<int,int>>> q; //weight ,y,x
   q.push({0,{startPoint.first,startPoint.second}});
   int mn=99999;
   while(!q.empty())
   {
      int weight = q.front().first;
      int y = q.front().second.first;
      int x = q.front().second.second;
      q.pop();
      if(mapp[y][x]>='3')
      {
         mn = min(mn,weight);
         continue;
      }
      for(int i=0;i<4;i++)
      {
         int ty = y+dy[i];
         int tx = x+dx[i];
         if(ty>=0&&ty<N&&tx>=0&&tx<M)
         {
            if(!vst[ty][tx]&&mapp[ty][tx]!='1')
            {
               vst[ty][tx] = true;
               q.push({weight+1,{ty,tx}});
            }
         }
      }
   }
   if(mn!=99999)
   {
      cout << "TAK"<<"\n";
      cout << mn;
   }
   else
   {
      cout << "NIE";
   }
}