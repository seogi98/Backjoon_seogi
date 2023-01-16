#include <string>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string.h>
#include <vector>

#define div 1000000003;
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int N, M;
int map[10][10];
int tmp[10][10];
int tmpNum = 0;
vector<pair<int, int>> V; //(y,x)
vector<pair<int, int>> Z; //(y,x)
int mx = 0;
int findSafe()
{
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmp[i][j] == 0)
            {
                result++;
            }
        }
    }
    return result;
}
void bfs()
{
    for (int i = 0; i < V.size(); i++)
    {
        queue<pair<int, int>> q;
        q.push(V[i]);
        while (!q.empty())
        {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                int tx = x + dx[j];
                int ty = y + dy[j];
                if (tx >= 0 && tx < M && ty >= 0 && ty < N)
                {
                    if (tmp[ty][tx] == 0)
                    {
                        tmp[ty][tx] = 2;
                        q.push({ty, tx});
                    }
                }
            }
        }
    }
}
// temp1

int seeV(vector<pair<int, int>> tv)
{
    for (int i = 0; i < tv.size(); i++)
    {
        cout << "( " << tv[i].first << ", " << tv[i].second << " )";
    }
    cout << endl;
}
void seemap()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << tmp[i][j] << " ";
        }
        cout << endl;
    }
}

void brute(int idx, int n, vector<pair<int, int>> v)
{
    int Zlen = Z.size();
    if (idx > Zlen)
    {
        return;
    }
    if (n == 3)
    {
        //tmpNum++;
        //cout << tmpNum << endl;
        //seeV(v);
        memcpy(tmp, map, sizeof(map));
        //seeV(v);
        for (int i = 0; i < v.size(); i++)
        {
            tmp[v[i].first][v[i].second] = 1;
        }
        bfs();
        mx = max(mx,findSafe());
        //seemap();
        return;
    }
    brute(idx + 1, n, v);
    v.push_back({Z[idx].first, Z[idx].second});
    brute(idx + 1, n + 1, v);
}
int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
            {
                Z.push_back({i, j});
            }
            if (map[i][j] == 2)
            {
                V.push_back({i, j});
            }
        }
    }
    vector<pair<int, int>> P;
    brute(0, 0, P);
    cout << mx;
}