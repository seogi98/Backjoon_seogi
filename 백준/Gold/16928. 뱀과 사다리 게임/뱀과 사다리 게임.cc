#include <bits/stdc++.h>
using namespace std;
#define MAX 50001
int vst[MAX];
int ladder[MAX];
int snake[MAX];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= 100; i++)
    {
        ladder[i] = i;
        snake[i] = i;
    }
    for (int i = 0; i < N + M; i++)
    {
        int u, v;
        cin >> u >> v;
        if (i < N)
            ladder[u] = v;
        else
            snake[u] = v;
    }
    queue<pair<int, int>> q;
    q.push({1, 0});
    vst[1] = true;
    while (!q.empty())
    {
        int cur = q.front().first;
        int count = q.front().second;
        q.pop();
        if (cur >= 100)
        {
            if (cur == 100)
            {
                cout << count;
                return 0;
            }
            continue;
        }
        for (int i = 1; i <= 6; i++)
        {
            int nx = cur + i;
            int nx1 = ladder[cur + i];
            int nx2 = snake[cur + i];
            if (nx1 != nx2)
            {
                if (nx1 != nx)
                    nx = nx1;
                else
                    nx = nx2;
            }
            if (vst[nx])
                continue;
            vst[nx] = true;
            q.push({nx, count + 1});
        }
    }
}