#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;
int main()
{
    queue<pair<pair<int, int>, int>> q; //(세로,가로)

    int N, M; //N은 세로 M은 가로
    int X, Y; //Y는 세로 X는 가로
    int D;
    int nX, nY;
    int map[1000][1000];
    bool vst[1000][1000] = {
        false,
    };
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int max = 0;
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1)
            {
                q.push(make_pair(make_pair(i, j), 0));
                vst[i][j] = true;
            }
        }
    }
    while (!q.empty())
    {
        X = q.front().first.second;
        Y = q.front().first.first;
        D = q.front().second;
        q.pop();
        // cout << X << "," <<Y <<endl;
        if (max < D)
        {
            max = D;
        }
        for (int k = 0; k < 4; k++)
        {
            nX = X + dx[k];
            nY = Y + dy[k];
            if (nX >= 0 && nX < M && nY >= 0 && nY < N)
            {
                if (vst[nY][nX] == false && map[nY][nX] == 0)
                {
                    //cout << nY << "," <<nX <<endl;
                    q.push(make_pair(make_pair(nY, nX), D + 1));
                    vst[nY][nX] = true;
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (vst[i][j] == false && map[i][j] != -1)
            {
                cout << "-1";
                return 0;
            }
        }
    }
    cout << max;
}
