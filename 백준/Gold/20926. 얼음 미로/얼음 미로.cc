#include <bits/stdc++.h>
using namespace std;
#define MAX 600
#define INF 10000000
struct tara
{
    int Y;
    int X;
    // 이동거리
    int dst;
    bool fall = false;
    bool escape = false;
};
struct cmp
{
    bool operator()(tara p1, tara p2)
    {
        return p1.dst > p2.dst;
    }
};
char mp[MAX][MAX];
int vst[MAX][MAX];
int W, H;

tara moveT(tara T, int dir)
{
    int dst = 0;
    // 오른쪽
    if (dir == 0)
    {
        char cur = mp[T.Y][T.X];
        while (1)
        {
            int nx = T.X + 1;
            int ny = T.Y;
            // 범위 밖이면
            if (nx < 0 || nx >= W || ny < 0 || ny >= H)
            {
                T.fall = true;
                return T;
            }
            // 숫자가 아니면
            if (mp[ny][nx] == 'R')
                return T;
            T.X = nx;
            T.Y = ny;
            if (mp[ny][nx] == 'E')
            {
                T.escape = true;
                return T;
            }
            if (mp[ny][nx] == 'H')
            {
                T.fall = true;
                return T;
            }
            T.dst += mp[ny][nx] - '0';
        }
    }
    if (dir == 1)
    {
        char cur = mp[T.Y][T.X];
        while (1)
        {
            int nx = T.X;
            int ny = T.Y + 1;
            // 범위 밖이면
            if (nx < 0 || nx >= W || ny < 0 || ny >= H)
            {
                T.fall = true;
                return T;
            }
            // 숫자가 아니면
            if (mp[ny][nx] == 'R')
                return T;
            T.X = nx;
            T.Y = ny;
            if (mp[ny][nx] == 'E')
            {
                T.escape = true;
                return T;
            }
            if (mp[ny][nx] == 'H')
            {
                T.fall = true;
                return T;
            }
            T.dst += mp[ny][nx] - '0';
        }
    }
    if (dir == 2)
    {
        char cur = mp[T.Y][T.X];
        while (1)
        {
            int nx = T.X - 1;
            int ny = T.Y;
            // 범위 밖이면
            if (nx < 0 || nx >= W || ny < 0 || ny >= H)
            {
                T.fall = true;
                return T;
            }
            // 숫자가 아니면
            if (mp[ny][nx] == 'R')
                return T;
            T.X = nx;
            T.Y = ny;
            if (mp[ny][nx] == 'E')
            {
                T.escape = true;
                return T;
            }
            if (mp[ny][nx] == 'H')
            {
                T.fall = true;
                return T;
            }
            T.dst += mp[ny][nx] - '0';
        }
    }
    if (dir == 3)
    {
        char cur = mp[T.Y][T.X];
        while (1)
        {
            int nx = T.X;
            int ny = T.Y - 1;
            // 범위 밖이면
            if (nx < 0 || nx >= W || ny < 0 || ny >= H)
            {
                T.fall = true;
                return T;
            }
            // 숫자가 아니면
            if (mp[ny][nx] == 'R')
                return T;
            T.X = nx;
            T.Y = ny;
            if (mp[ny][nx] == 'E')
            {
                T.escape = true;
                return T;
            }
            if (mp[ny][nx] == 'H')
            {
                T.fall = true;
                return T;
            }
            T.dst += mp[ny][nx] - '0';
        }
    }
    return T;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> W >> H;
    tara start;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            vst[i][j] = INF;
            cin >> mp[i][j];
            if (mp[i][j] == 'T')
            {
                start = {i, j, 0, false, false};
                vst[i][j] = 0;
                mp[i][j] = '0';
            }
        }
    }
    priority_queue<tara, vector<tara>, cmp> pq;
    pq.push(start);
    int ans = -1;
    while (!pq.empty())
    {
        tara cur = pq.top();
        pq.pop();
        if (cur.fall)
            continue;
        if (cur.escape)
        {
            ans = cur.dst;
            break;
        }
        // if(vst[cur.Y][cur.X] < cur.dst) continue;
        for (int i = 0; i < 4; i++)
        {
            tara nx = moveT(cur, i);
            int nxDist = nx.dst;
            // 만약에 거리가 더 길 경우
            if (vst[nx.Y][nx.X] <= nxDist)
                continue;
            if (nx.fall)
                continue;
            vst[nx.Y][nx.X] = nxDist;
            pq.push(nx);
        }
    }
    cout << ans;
}