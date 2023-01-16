
#include <bits/stdc++.h>
using namespace std;
#define MAX 60
#define INF 1999999999
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, M;
char mp[MAX][MAX];
int bfs(pair<int, int> start)
{
    queue<pair<int,pair<int,int>>> q;
    q.push({0,start});
    int result =0;
    vector<vector<bool>> vst(MAX,vector<bool>(MAX,false));
    vst[start.first][start.second] = true;
    while(!q.empty())
    {
        int D = q.front().first;
        int Y = q.front().second.first;
        int X = q.front().second.second;
        result = max(result,D);
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = X+dx[i];
            int ny = Y+dy[i];
            if(nx <0 || nx >=M || ny <0 || ny>=N) continue;
            if(mp[ny][nx] == 'W') continue;
            if(vst[ny][nx]) continue;
            vst[ny][nx] = true;
            q.push({D+1,{ny,nx}});
        }
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    int ans=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(mp[i][j] == 'W') continue;
            ans = max(ans,bfs({i,j}));
        }
    }
    cout << ans;
}
