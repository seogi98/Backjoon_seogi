#include <bits/stdc++.h>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int N, L, R;
int mp[51][51];
int vst[51][51]; // case 0 : 방문 x  case 1 : 인구  case 2 : 방문후 인구기록
bool isMove = false;
int pop = 0;
int cnt = 0;
void dfs(pair<int, int> P)
{
    int cx = P.second;
    int cy = P.first;
    //방문 햇을경우 return
    if (vst[cy][cx] == 1 || vst[cy][cx] == 2)
        return;
    vst[cy][cx] = 1;
    pop += mp[cy][cx];
    cnt++;
    for (int i = 0; i < 4; i++)
    {
        int nx = P.second + dx[i];
        int ny = P.first + dy[i];
        if (ny >= N || ny < 0 || nx < 0 || nx >= N)
            continue;
        if (vst[ny][nx] == 1 || vst[ny][nx] == 2)
            continue;
        int diff = abs(mp[ny][nx] - mp[cy][cx]);
        if (diff < L || diff > R)
            continue;
        isMove = true;
        dfs({ny, nx});
    }
}
void popW(pair<int, int> P)
{
    int cx = P.second;
    int cy = P.first;
    // 인구기록이 되었거나 방문을 안했을경우 return
    if (vst[cy][cx] == 2 || vst[cy][cx] == 0)
        return;
    mp[cy][cx] = pop / cnt;
    vst[cy][cx] = 2;
    for (int i = 0; i < 4; i++)
    {
        int nx = P.second + dx[i];
        int ny = P.first + dy[i];
        if (ny >= N || ny < 0 || nx < 0 || nx >= N)
            continue;
        if (vst[ny][nx] == 2 || vst[ny][nx] == 0)
            continue;
        popW({ny, nx});
    }
}
void seeA(int mp[51][51])
{
    for (int i = 0; i < N; i++)
    {
        cout << "\n";
        for (int j = 0; j < N; j++)
        {
            cout << mp[i][j] << " ";
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> mp[i][j];
        }
    }
    int result=0;
    while (1)
    {
        isMove =false;
        memset(vst, 0, sizeof(vst));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                pop = 0;
                cnt = 0;
                dfs({i, j});
                popW({i, j});
            }
        }
        if(!isMove) break;
        
        result++;
    }
    cout << result;
}
