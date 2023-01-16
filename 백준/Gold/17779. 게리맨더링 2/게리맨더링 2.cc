#include <bits/stdc++.h>
using namespace std;
#define MAX 21
int mp[MAX][MAX];
struct pos
{
    int y;
    int x;
};
void seeM(vector<vector<int>> mp,int N){
    cout << "\n";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << mp[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(void)
{
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mp[i][j];
        }
    }
    int ans = 999999999;
    // int i =4;
    // int j =2;
    // int d1 =2;
    // int d2 =1;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            pos start = {i, j};
            for (int d1 = 1; d1 <= 11; d1++)
            {
                for (int d2 = 1; d2 <= 11; d2++)
                {        
                    vector<int> popul(MAX, 0);
                    // tmp
                    bool outOfBound = false;
                    // 왼 위 오 아래
                    pos P[4] = {start, {start.y - d1, start.x + d1}, {start.y+(d2-d1), start.x + d1+d2}, {start.y + d2, start.x + d2}};
                    for (int k = 0; k < 4; k++)
                    {
                        if (P[k].x < 0 || P[k].x >= N || P[k].y < 0 || P[k].y >= N)
                        {
                            outOfBound = true;
                            break;
                        }
                    }
                    if (outOfBound){
                        continue;
                    }
                    vector<vector<int>> ttmp(N,vector<int>(N,0));
                    int dx[4]= {1,1,-1,-1};
                    int dy[4] = {-1,1,1,-1};
                    // 지역구 5 내부 범위 탐색
                    for(int ii=0;ii<4;ii++){
                        int nx = P[ii].x;
                        int ny = P[ii].y;
                        int nd = d2;
                        if(ii%2 == 0) nd = d1;
                        for(int jj=0;jj<=nd;jj++){
                            ttmp[ny][nx] = 5;
                            nx += dx[ii];
                            ny += dy[ii];
                        }
                    }
                    queue<pos> q;
                    int ddx[4] = {1,0,-1,0};
                    int ddy[4] = {0,1,0,-1};
                    q.push({P[0].y,P[0].x+1});
                    q.push({P[2].y,P[2].x-1});
                    while(!q.empty()){
                        pos cur = q.front();
                        q.pop();
                        if(ttmp[cur.y][cur.x] == 5) continue;
                        ttmp[cur.y][cur.x] = 5;
                        for(int ii=0;ii<4;ii++){
                            int nx = ddx[ii]+cur.x;
                            int ny = ddy[ii]+cur.y;
                            if(nx < 0 || nx >= N || ny < 0 || ny>= N) continue;
                            if(ttmp[ny][nx] == 5) continue;
                            q.push({ny,nx});
                        }
                    }
                    // 구역 나누기
                    for (int y = 1; y < N-1; y++)
                    {
                        for (int x = 1; x < N-1; x++)
                        {
                            if(
                                ttmp[y+ddy[0]][x+ddx[0]] == 5&&
                                ttmp[y+ddy[1]][x+ddx[1]] == 5&&
                                ttmp[y+ddy[2]][x+ddx[2]] == 5&&
                                ttmp[y+ddy[3]][x+ddx[3]] == 5
                            )
                                ttmp[y][x] = 5;
                        }
                    }
                    // 구역 나누기
                    for (int y = 0; y < N; y++)
                    {
                        for (int x = 0; x < N; x++)
                        {
                            if(ttmp[y][x] == 5) {
                                popul[5] +=mp[y][x];
                            }
                            else if (x <= P[1].x && y < P[0].y)
                            {
                                ttmp[y][x] = 1;
                                popul[1] += mp[y][x];
                            }
                            else if (x > P[1].x && y <= P[2].y)
                            {
                                ttmp[y][x] = 2;
                                popul[2] += mp[y][x];
                            }
                            else if (x < P[3].x && y >= P[0].y)
                            {
                                ttmp[y][x] = 3;
                                popul[3] += mp[y][x];
                            }
                            else if (x >= P[3].x && y > P[2].y)
                            {
                                ttmp[y][x] = 4;
                                popul[4] += mp[y][x];
                            }
                        }
                    }
                    // seeM(ttmp,N);
                    // seeM(ttmp,N);
                    int mn = 999999999;
                    int mx = 0;
                    for (int i = 1; i <= 5; i++)
                    {
                        mn = min(mn, popul[i]);
                        mx = max(mx, popul[i]);
                    }
                    ans = min(mx-mn, ans);
                }
            }
        }
    }
    cout << ans;
}