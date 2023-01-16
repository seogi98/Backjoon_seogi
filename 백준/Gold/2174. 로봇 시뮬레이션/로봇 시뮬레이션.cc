#include <bits/stdc++.h>

using namespace std;

pair<int, int> dirM[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // 오른쪽, 아래 , 왼쪽 , 위

struct robot
{
   int x;
   int y;
   int dir;
};
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   pair<int, bool> isEx[101][101];
   robot R[101];
   int A, B;
   cin >> A >> B;
   int N, M;
   cin >> N >> M;
   memset(isEx, false, sizeof(isEx));
   for (int i = 1; i <= N; i++)
   {
      robot tmpR;
      char tmpdir;
      cin >> tmpR.x >> tmpR.y >> tmpdir;
      if (tmpdir == 'E')
         tmpR.dir = 2;
      if (tmpdir == 'S')
         tmpR.dir = 3;
      if (tmpdir == 'W')
         tmpR.dir = 0;
      if (tmpdir == 'N')
         tmpR.dir = 1;
      isEx[tmpR.y][tmpR.x].second = true;
      isEx[tmpR.y][tmpR.x].first = i;
      R[i] = tmpR;
   }
   for (int i = 0; i < M; i++)
   {
      //로봇, 명령 종류, 반복 횟수
      int rb, rc;
      char ct;
      cin >> rb >> ct >> rc;
      int nextx, nexty, prex, prey;
      for (int j = 0; j < rc; j++)
      {

         if (ct == 'L')
         {
            R[rb].dir = R[rb].dir - 1 < 0 ? 3 : R[rb].dir - 1;
         }
         if (ct == 'R')
         {
            R[rb].dir = (R[rb].dir + 1) % 4;
         }
         if (ct == 'F')
         {

            prex = R[rb].x;
            prey = R[rb].y;
            nextx = prex + dirM[R[rb].dir].second;
            nexty = prey + dirM[R[rb].dir].first;
            // for (int i = 1; i <= B; i++)
            // {
            //    for (int j = 1; j <= A; j++)
            //    {
            //       cout << isEx[i][j].first << " ";
            //    }
            //    cout << "\n";
            // }
            // cout << "\n";
            if (nextx > 0 && nextx <= A && nexty > 0 && nexty <= B)
            {
               if (!isEx[nexty][nextx].second)
               {
                  isEx[prey][prex].second = false;
                  isEx[prey][prex].first = 0;
                  isEx[nexty][nextx].second = true;
                  isEx[nexty][nextx].first = rb;
                  R[rb].y = nexty;
                  R[rb].x = nextx;
               }
               else
               {
                  cout << "Robot " << rb << " crashes into robot " << isEx[nexty][nextx].first;
                  return 0;
               }
            }
            else
            {
               cout << "Robot " << rb << " crashes into the wall";
               return 0;
            }
         }
      }
   }
   cout << "OK";
}
